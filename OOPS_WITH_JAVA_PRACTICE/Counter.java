public class Counter {
    static int count = 0;

    public Counter() {
        count++;
    }

    static void showCount() {
        System.out.println("Count: " + count);
    }

public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();

        showCount(); 
    }

}
