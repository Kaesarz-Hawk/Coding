// Q3(a) [5 Marks]: Both Versions -> (1) Balance / DataUsage (recharge, use, refund) & (2) Bank Account (deposit, withdraw)

// ================= VERSION 1: Balance & DataUsage (recharge, use, refund) =================
class Balance {
    String userName;
    double dataBalance; // in MB

    Balance(String userName, double dataBalance) {
        this.userName = userName;
        this.dataBalance = dataBalance;
    }

    // Overloaded recharge() methods
    void recharge(double mb) {
        dataBalance += mb;
        System.out.println("Recharged " + mb + " MB | Current Balance: " + dataBalance + " MB");
    }

    void recharge(double mb, String packName) {
        dataBalance += mb;
        System.out.println("Recharged " + mb + " MB (" + packName + ") | Current Balance: " + dataBalance + " MB");
    }
}

class DataUsage extends Balance {
    DataUsage(String userName, double dataBalance) {
        super(userName, dataBalance);
    }

    // Overloaded use() methods
    void use(double mb) {
        if (mb <= dataBalance) {
            dataBalance -= mb;
            System.out.println("Used " + mb + " MB | Remaining: " + dataBalance + " MB");
        } else {
            System.out.println("Insufficient data balance!");
        }
    }

    void use(double mb, String appName) {
        if (mb <= dataBalance) {
            dataBalance -= mb;
            System.out.println("Used " + mb + " MB on " + appName + " | Remaining: " + dataBalance + " MB");
        } else {
            System.out.println("Insufficient data balance for " + appName + "!");
        }
    }

    // Overloaded refund() methods
    void refund(double mb) {
        dataBalance += mb;
        System.out.println("Refunded " + mb + " MB | Updated Balance: " + dataBalance + " MB");
    }

    void refund(double mb, String reason) {
        dataBalance += mb;
        System.out.println("Refunded " + mb + " MB (" + reason + ") | Updated Balance: " + dataBalance + " MB");
    }

    void display() {
        System.out.println("User: " + userName + " | Final Data Balance: " + dataBalance + " MB");
    }
}

// ================= VERSION 2: Bank Account (deposit, withdraw, refund) =================
class Account {
    int accountNumber;
    String accountHolder;
    double balance;

    Account(int accountNumber, String accountHolder, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolder = accountHolder;
        this.balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: " + amount + " | Balance: " + balance);
    }

    void deposit(double amount, String description) {
        balance += amount;
        System.out.println("Deposited: " + amount + " (" + description + ") | Balance: " + balance);
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("Withdrew: " + amount + " | Balance: " + balance);
        } else {
            System.out.println("Insufficient balance!");
        }
    }

    void withdraw(double amount, String description) {
        if (amount <= balance) {
            balance -= amount;
            System.out.println("Withdrew: " + amount + " (" + description + ") | Balance: " + balance);
        } else {
            System.out.println("Insufficient balance!");
        }
    }
}

public class Q3a_DataUsage_And_Banking {
    public static void main(String[] args) {
        System.out.println("--- VERSION 1: DataUsage (recharge, use, refund) ---");
        DataUsage user1 = new DataUsage("Kawsar", 500.0);
        user1.recharge(1000.0);
        user1.recharge(500.0, "Student Pack");
        user1.use(300.0);
        user1.use(450.0, "YouTube");
        user1.refund(100.0, "Network Drop");
        user1.display();

        System.out.println("
--- VERSION 2: Bank Account (deposit, withdraw) ---");
        Account acc = new Account(1001, "Kawsar", 5000.0);
        acc.deposit(2000.0);
        acc.deposit(1500.0, "Scholarship");
        acc.withdraw(1000.0);
        acc.withdraw(500.0, "Internet Bill");
    }
}
