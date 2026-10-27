// Q1(b) [5 Marks]: Packages (store & management) + Encapsulation Validation (0-100)
// Note: In the exam paper, write File 1 under 'package store;' and File 2 under 'package management;'

// --- FILE 1: store/Customer.java ---
// package store;
class StoreCustomer {
    private String customerName;
    private int customerId;
    private int loyaltyScore;

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public int getCustomerId() {
        return customerId;
    }

    public void setCustomerId(int customerId) {
        this.customerId = customerId;
    }

    public int getLoyaltyScore() {
        return loyaltyScore;
    }

    public void setLoyaltyScore(int loyaltyScore) {
        if (loyaltyScore >= 0 && loyaltyScore <= 100) {
            this.loyaltyScore = loyaltyScore;
        } else {
            System.out.println("Invalid loyalty score: " + loyaltyScore + " (Allowed: 0-100)");
        }
    }

    public String calculateLoyaltyTier() {
        if (loyaltyScore >= 80)
            return "Platinum";
        else if (loyaltyScore >= 60)
            return "Gold";
        else if (loyaltyScore >= 40)
            return "Silver";
        else
            return "Bronze";
    }
}

// --- FILE 2: management/CustomerManagement.java ---
// package management;
// import store.Customer;
public class Q1b_Packages_Encapsulation_Customer {
    public static void main(String[] args) {
        StoreCustomer c1 = new StoreCustomer();
        c1.setCustomerName("Arif");
        c1.setCustomerId(701);
        c1.setLoyaltyScore(92);

        StoreCustomer c2 = new StoreCustomer();
        c2.setCustomerName("Nabila");
        c2.setCustomerId(702);
        c2.setLoyaltyScore(67);

        StoreCustomer c3 = new StoreCustomer();
        c3.setCustomerName("Rafi");
        c3.setCustomerId(703);
        c3.setLoyaltyScore(150); // Invalid -> rejected
        c3.setLoyaltyScore(35); // Valid

        StoreCustomer[] list = { c1, c2, c3 };
        for (int i = 0; i < list.length; i++) {
            System.out.println("Name: " + list[i].getCustomerName()
                    + ", ID: " + list[i].getCustomerId()
                    + ", Score: " + list[i].getLoyaltyScore()
                    + ", Category: " + list[i].calculateLoyaltyTier());
        }
    }
}
