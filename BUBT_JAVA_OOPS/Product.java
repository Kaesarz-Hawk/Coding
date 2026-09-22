public class Product {
    private String productName;
    private double price;
    private int quantity;

    // Constructor
    public Product(String productName, double price, int quantity) {
        this.productName = productName;
        this.price = price;
        this.quantity = quantity;
    }

    // Returns total price of the product
    public double calculateTotal() {
        return price * quantity;
    }

    // Gives 10% discount if total price > 5000
    public double calculateDiscount() {
        double total = calculateTotal();
        if (total > 5000) {
            return total * 0.10;
        }
        return 0;
    }

    public void displayProduct() {
        double total = calculateTotal();
        double discount = calculateDiscount();
        System.out.println("Product Name: " + productName);
        System.out.println("Price: " + price);
        System.out.println("Quantity: " + quantity);
        System.out.println("Total Price: " + total);
        System.out.println("Discount: " + discount);
        System.out.println("Final Price: " + (total - discount));
        System.out.println("-----------------------------");
    }

    public static void main(String[] args) {
        Product p1 = new Product("Laptop", 60000, 1);
        Product p2 = new Product("Notebook", 50, 10);

        p1.displayProduct();
        p2.displayProduct();
    }
}
