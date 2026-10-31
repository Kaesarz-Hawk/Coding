class Balance {
    protected double accountBalance;
    protected double dataBalance;

    Balance(double money, double data) {
        this.accountBalance = money;
        this.dataBalance = data;
    }

    void showBalance() {
        System.out.println("Account Balance: $" + accountBalance + " | Data Balance: " + dataBalance + " MB");
    }

}

class Datausage extends Balance {
    Datausage(double money, double data) {
        super(money, data);
    }

    void recharge(double money) {
        accountBalance += money;
        System.out.println("Recharged $" + money + " TK | Current Account Balance: $" + accountBalance);
    }

    void recharge(double money, double data) {
        accountBalance += money;
        dataBalance += data;
        System.out.println("Recharged $" + money + " TK and " + data + " MB | Current Account Balance: $"
                + accountBalance + " | Current Data Balance: " + dataBalance + " MB");
    }
    
    void use(double money) {
        if (money <= accountBalance) {
            accountBalance -= money;
            System.out.println("Used $" + money + " TK | Remaining Account Balance: $" + accountBalance);
        } else {
            System.out.println("Insufficient account balance!");
        }
    }

    void use(double money, double data) {
        if (money <= accountBalance && data <= dataBalance) {
            accountBalance -= money;
            dataBalance -= data;
            System.out.println("Used $" + money + " TK and " + data + " MB | Remaining Account Balance: $"
                    + accountBalance + " | Remaining Data Balance: " + dataBalance + " MB");
        } else {
            System.out.println("Insufficient balance or data!");
        }
    }


    void refund(double money) {
        accountBalance += money;
        System.out.println("Refunded $" + money + " TK | Updated Account Balance: $" + accountBalance);
    }

    void refund(double money, double data) {
        accountBalance += money;
        dataBalance += data;
        System.out.println("Refunded $" + money + " TK and " + data + " MB | Updated Account Balance: $"
                + accountBalance + " | Updated Data Balance: " + dataBalance + " MB");
    }
    
}






public class Main {
    public static void main(String[] args) {
        Datausage u = new Datausage(1000, 500); // Initial account balance: $1000, data balance: 500 MB
        u.showBalance();
        u.recharge(500, 250);
        u.use(200, 100);
        u.refund(100, 50);
        u.showBalance();
        
    }
}
