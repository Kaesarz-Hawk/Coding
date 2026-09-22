public class Book {
    private String title;
    private String author;
    private double price;

    // 1. Default constructor
    public Book() {
        this.title = "Unknown";
        this.author = "Unknown";
        this.price = 0;
    }

    // 2. Constructor with title and author only
    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.price = 0;
    }

    // 3. Constructor with title, author, and price
    public Book(String title, String author, double price) {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public void displayBook() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
        System.out.println("-----------------------------");
    }

    public static void main(String[] args) {
        Book book1 = new Book();
        Book book2 = new Book("The Alchemist", "Paulo Coelho");
        Book book3 = new Book("Java Basics", "James Gosling", 750.50);

        book1.displayBook();
        book2.displayBook();
        book3.displayBook();
    }
}
