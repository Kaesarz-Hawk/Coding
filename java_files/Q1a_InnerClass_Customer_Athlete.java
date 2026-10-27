// Q1(a) [5 Marks]: Inner Class Fill in the Blanks (Customer & Athlete Versions)

class Customer {
    public String customerName;   // Accessible from any class
    private int customerId;       // Accessible only within Customer

    Customer(String name, int id) {
        this.customerName = name;
        this.customerId = id;
    }

    class Order {
        private int itemCount;

        Order(int count) {
            this.itemCount = count;
        }

        void display() {
            System.out.println(customerName + " " + customerId + " " + itemCount);
        }
    }

    void showCustomer() {
        Order item = new Order(4);
        item.display();
    }
}

class Athlete {
    public String athleteName;    // Accessible from any class
    private int athleteId;        // Accessible only within Athlete

    Athlete(String name, int id) {
        this.athleteName = name;
        this.athleteId = id;
    }

    class Training {
        private int trainingHours;

        Training(int hours) {
            this.trainingHours = hours;
        }

        void display() {
            System.out.println(athleteName + " " + athleteId + " " + trainingHours);
        }
    }

    void showAthlete() {
        Training item = new Training(20);
        item.display();
    }
}

public class Q1a_InnerClass_Customer_Athlete {
    public static void main(String[] args) {
        Customer cObj = new Customer("Arif", 701);
        cObj.showCustomer();

        Athlete aObj = new Athlete("Sakib", 501);
        aObj.showAthlete();
    }
}
