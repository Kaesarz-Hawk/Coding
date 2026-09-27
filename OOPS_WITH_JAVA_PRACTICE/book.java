public class book {
    String title;
    double price;

    book(String title, double price) {
        this.title = title;
        this.price = price;
    }

    book() {
        this("Unknown", 0.0);
    }
   
    
    void displayInfo() {
        System.out.println("Title: " + title);
        System.out.println("Price: $" + price);
    }


    public static void main(String[] args) {
        book b1 = new book("Java Programming", 29.99);
        b1.displayInfo();

        book b2 = new book();
        b2.displayInfo();
    }
}
