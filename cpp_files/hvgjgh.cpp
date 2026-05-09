#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

// ==========================================
// MODEL: Transaction Class (Encapsulated)
// ==========================================

class Transaction {
private:
    string type;     // "Income" or "Expense"
    double amount;
    string category;
    string note;
    string date;

public:
    // Default Constructor
    Transaction() : amount(0.0) {}

    // Parameterized Constructor
    Transaction(string t, double a, string c, string n, string d)
        : type(t), amount(a), category(c), note(n), date(d) {}

    // Getters
    string getType() const { return type; }
    double getAmount() const { return amount; }
    string getCategory() const { return category; }
    string getNote() const { return note; }
    string getDate() const { return date; }

    // Setters
    void setType(const string &t) { type = t; }
    void setAmount(double a) { amount = a; }
    void setCategory(const string &c) { category = c; }
    void setNote(const string &n) { note = n; }
    void setDate(const string &d) { date = d; }
};

// ==========================================
// MODEL: Data Manager
// ==========================================

class FinanceManager {
private:
    vector<Transaction> transactions;
    const string filename = "finance_data.txt";

public:
    FinanceManager() {
        loadFromFile();
    }

    // Helper to get current time string
    string getCurrentDate() {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[20];
        strftime(buffer, 20, "%Y-%m-%d %H:%M", ltm);
        return string(buffer);
    }

    void addTransaction(string type, double amount, string category, string note) {
        // Use Constructor
        Transaction t(type, amount, category, note, getCurrentDate());
        transactions.push_back(t);
        saveToFile();
    }

    // New Feature: Edit existing transaction
    void editTransaction(int index, string type, double amount, string category, string note) {
        if (index >= 0 && index < transactions.size()) {
            // We keep the original date, only update other fields
            transactions[index].setType(type);
            transactions[index].setAmount(amount);
            transactions[index].setCategory(category);
            transactions[index].setNote(note);
            saveToFile();
        }
    }

    const vector<Transaction>& getTransactions() const {
        return transactions;
    }

    // Get a specific transaction for editing
    Transaction getTransaction(int index) {
        if (index >= 0 && index < transactions.size()) {
            return transactions[index];
        }
        return Transaction();
    }

    void deleteTransaction(int index) {
        if (index >= 0 && index < transactions.size()) {
            transactions.erase(transactions.begin() + index);
            saveToFile();
        }
    }

    void getBalanceInfo(double &income, double &expense, double &balance) {
        income = 0;
        expense = 0;
        for (const auto &t : transactions) {
            if (t.getType() == "Income") income += t.getAmount();
            else expense += t.getAmount();
        }
        balance = income - expense;
    }

    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto &t : transactions) {
                file << t.getType() << "|"
                     << t.getAmount() << "|"
                     << t.getCategory() << "|"
                     << t.getNote() << "|"
                     << t.getDate() << "\n";
            }
            file.close();
        }
    }

    void loadFromFile() {
        transactions.clear();
        ifstream file(filename);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                string segment;
                vector<string> seglist;
                while (getline(ss, segment, '|')) {
                    seglist.push_back(segment);
                }
                if (seglist.size() == 5) {
                    // Use setters or constructor
                    Transaction t(seglist[0], stod(seglist[1]), seglist[2], seglist[3], seglist[4]);
                    transactions.push_back(t);
                }
            }
            file.close();
        }
    }
};

// ==========================================
// CUSTOM WIDGET: Pie Chart
// ==========================================
class PieChart : public Fl_Widget {
    double income;
    double expense;
public:
    PieChart(int x, int y, int w, int h, const char *l = 0) : Fl_Widget(x, y, w, h, l) {
        income = 0;
        expense = 0;
    }

    void updateValues(double inc, double exp) {
        income = inc;
        expense = exp;
        redraw();
    }

    void draw() override {
        // Draw Background
        fl_color(FL_WHITE);
        fl_rectf(x(), y(), w(), h());
        fl_color(FL_BLACK);
        fl_rect(x(), y(), w(), h());

        if (income == 0 && expense == 0) {
            fl_draw("No Data", x() + w()/2 - 20, y() + h()/2);
            return;
        }

        double total = income + expense;
        double incomeAngle = (income / total) * 360.0;

        int cx = x() + w()/2;
        int cy = y() + h()/2;
        int r = (w() < h() ? w() : h()) / 2 - 10;

        // Draw Income (Green)
        if (income > 0) {
            fl_color(FL_GREEN);
            fl_pie(cx - r, cy - r, 2*r, 2*r, 0, incomeAngle);
        }

        // Draw Expense (Red)
        if (expense > 0) {
            fl_color(FL_RED);
            fl_pie(cx - r, cy - r, 2*r, 2*r, incomeAngle, 360);
        }

        // Legend
        fl_color(FL_BLACK);
        fl_font(FL_HELVETICA, 12);
        char buf[50];
        sprintf(buf, "Inc: %.1f%%", (income/total)*100);
        fl_draw(buf, x() + 5, y() + h() - 20);
        sprintf(buf, "Exp: %.1f%%", (expense/total)*100);
        fl_draw(buf, x() + w() - 70, y() + h() - 20);
    }
};

// ==========================================
// VIEW: Edit Dialog Window
// ==========================================
class EditDialog : public Fl_Window {
public:
    Fl_Choice *inputType;
    Fl_Float_Input *inputAmount;
    Fl_Input *inputCategory;
    Fl_Input *inputNote;
    Fl_Button *btnSave;
    Fl_Button *btnCancel;

    bool saved; // Flag to check if user clicked save

    EditDialog() : Fl_Window(300, 320, "Edit Transaction") {
        this->set_modal(); // Make it block other windows
        saved = false;

        inputType = new Fl_Choice(90, 20, 180, 30, "Type:");
        inputType->add("Income");
        inputType->add("Expense");

        inputAmount = new Fl_Float_Input(90, 60, 180, 30, "Amount:");
        inputCategory = new Fl_Input(90, 100, 180, 30, "Category:");
        inputNote = new Fl_Input(90, 140, 180, 30, "Note:");

        btnSave = new Fl_Button(30, 250, 100, 30, "Save");
        btnSave->color(FL_GREEN);
        btnSave->callback(cb_save, this);

        btnCancel = new Fl_Button(170, 250, 100, 30, "Cancel");
        btnCancel->callback(cb_cancel, this);

        this->end();
    }

    void loadData(Transaction t) {
        inputType->value(t.getType() == "Income" ? 0 : 1);

        char buf[50];
        sprintf(buf, "%.2f", t.getAmount());
        inputAmount->value(buf);

        inputCategory->value(t.getCategory().c_str());
        inputNote->value(t.getNote().c_str());
    }

    static void cb_save(Fl_Widget*, void* v) {
        ((EditDialog*)v)->saved = true;
        ((EditDialog*)v)->hide();
    }

    static void cb_cancel(Fl_Widget*, void* v) {
        ((EditDialog*)v)->saved = false;
        ((EditDialog*)v)->hide();
    }
};

// ==========================================
// VIEW: Main GUI
// ==========================================
class FinanceApp : public Fl_Window {
    FinanceManager manager;

    // Widgets
    Fl_Tabs *tabs;

    // Tab 1: Add
    Fl_Group *grpAdd;
    Fl_Choice *inputType;
    Fl_Float_Input *inputAmount;
    Fl_Input *inputCategory;
    Fl_Input *inputNote;
    Fl_Button *btnAdd;

    // Tab 2: History
    Fl_Group *grpHistory;
    Fl_Hold_Browser *browser;
    Fl_Button *btnDelete;
    Fl_Button *btnEdit; // New Edit Button

    // Tab 3: Dashboard
    Fl_Group *grpStats;
    PieChart *chart;
    Fl_Box *boxIncome;
    Fl_Box *boxExpense;
    Fl_Box *boxBalance;

public:
    FinanceApp() : Fl_Window(500, 400, "Advanced Finance Manager") {
        // --- Styling ---
        this->color(fl_rgb_color(240, 240, 240));

        tabs = new Fl_Tabs(10, 10, 480, 380);

        // ---------------- Tab 1: Add Transaction ----------------
        grpAdd = new Fl_Group(10, 35, 480, 355, "Add New");
        {
            inputType = new Fl_Choice(150, 60, 200, 30, "Type:");
            inputType->add("Income");
            inputType->add("Expense");
            inputType->value(0);

            inputAmount = new Fl_Float_Input(150, 100, 200, 30, "Amount ($):");
            inputCategory = new Fl_Input(150, 140, 200, 30, "Category:");
            inputNote = new Fl_Input(150, 180, 200, 30, "Note:");

            btnAdd = new Fl_Button(150, 230, 200, 40, "Save Transaction");
            btnAdd->color(fl_rgb_color(100, 180, 255));
            btnAdd->callback(cb_add, this);
        }
        grpAdd->end();

        // ---------------- Tab 2: History ----------------
        grpHistory = new Fl_Group(10, 35, 480, 355, "History");
        {
            browser = new Fl_Hold_Browser(20, 50, 440, 280);
            browser->textfont(FL_COURIER); // Monospace for alignment

            btnEdit = new Fl_Button(20, 340, 100, 30, "Edit");
            btnEdit->color(fl_rgb_color(255, 255, 150));
            btnEdit->callback(cb_edit, this);

            btnDelete = new Fl_Button(130, 340, 120, 30, "Delete Selected");
            btnDelete->color(fl_rgb_color(255, 100, 100));
            btnDelete->callback(cb_delete, this);
        }
        grpHistory->end();

        // ---------------- Tab 3: Dashboard ----------------
        grpStats = new Fl_Group(10, 35, 480, 355, "Dashboard");
        {
            chart = new PieChart(150, 50, 180, 180, "Income vs Expense");

            boxIncome = new Fl_Box(20, 250, 140, 30, "Income: 0.0");
            boxIncome->box(FL_FLAT_BOX);
            boxIncome->color(FL_GREEN);

            boxExpense = new Fl_Box(170, 250, 140, 30, "Expense: 0.0");
            boxExpense->box(FL_FLAT_BOX);
            boxExpense->color(FL_RED);

            boxBalance = new Fl_Box(320, 250, 140, 30, "Balance: 0.0");
            boxBalance->box(FL_BORDER_BOX);
        }
        grpStats->end();

        tabs->end();
        this->end();

        // Load initial data
        refreshData();
    }

    // Callbacks
    static void cb_add(Fl_Widget*, void* v) {
        ((FinanceApp*)v)->addTransaction();
    }

    static void cb_delete(Fl_Widget*, void* v) {
        ((FinanceApp*)v)->deleteTransaction();
    }

    static void cb_edit(Fl_Widget*, void* v) {
        ((FinanceApp*)v)->editTransaction();
    }

    // Logic Methods
    void addTransaction() {
        string type = inputType->text(inputType->value());
        string amtStr = inputAmount->value();
        string cat = inputCategory->value();
        string note = inputNote->value();

        if (amtStr.empty() || cat.empty()) {
            fl_alert("Please fill in Amount and Category!");
            return;
        }

        double amount = stod(amtStr);
        manager.addTransaction(type, amount, cat, note);

        // Reset Inputs
        inputAmount->value("");
        inputCategory->value("");
        inputNote->value("");
        inputAmount->take_focus();

        refreshData();
        fl_message("Transaction Added!");
    }

    void editTransaction() {
        int selected = browser->value(); // 1-based index
        if (selected == 0) {
            fl_alert("No transaction selected to edit.");
            return;
        }

        int index = selected - 1; // Convert to 0-based
        Transaction t = manager.getTransaction(index);

        // Create and Show Edit Dialog
        EditDialog dlg;
        dlg.loadData(t);
        dlg.show();

        // Wait loop until dialog closes
        while(dlg.shown()) Fl::wait();

        if(dlg.saved) {
            string newType = dlg.inputType->text(dlg.inputType->value());
            string newAmtStr = dlg.inputAmount->value();
            double newAmt = (newAmtStr.empty()) ? 0.0 : stod(newAmtStr);
            string newCat = dlg.inputCategory->value();
            string newNote = dlg.inputNote->value();

            manager.editTransaction(index, newType, newAmt, newCat, newNote);
            refreshData();
            // Keep selection on the edited item
            browser->select(selected);
        }
    }

    void deleteTransaction() {
        int selected = browser->value(); // 1-based index
        if (selected == 0) {
            fl_alert("No transaction selected.");
            return;
        }

        if (fl_choice("Are you sure you want to delete this?", "No", "Yes", 0) == 1) {
            manager.deleteTransaction(selected - 1); // Convert to 0-based
            refreshData();
        }
    }

    void refreshData() {
        // 1. Refresh Browser
        browser->clear();
        const auto& trans = manager.getTransactions();
        char line[200];

        // Add header
        browser->add("TYPE    | AMOUNT   | CATEGORY   | DATE");

        for (const auto& t : trans) {
            // Format: Income   | 500.00   | Salary     | 2023-10...
            sprintf(line, "%-8s | %-8.2f | %-10s | %s",
                t.getType().c_str(), t.getAmount(), t.getCategory().c_str(), t.getDate().c_str());
            browser->add(line);
        }

        // 2. Refresh Stats
        double inc, exp, bal;
        manager.getBalanceInfo(inc, exp, bal);

        static char lInc[50], lExp[50], lBal[50];
        sprintf(lInc, "Income: $%.2f", inc);
        sprintf(lExp, "Expense: $%.2f", exp);
        sprintf(lBal, "Bal: $%.2f", bal);

        boxIncome->copy_label(lInc);
        boxExpense->copy_label(lExp);
        boxBalance->copy_label(lBal);

        chart->updateValues(inc, exp);
    }
};

int main(int argc, char **argv) {
    FinanceApp win;
    win.show(argc, argv);
    return Fl::run();
}
