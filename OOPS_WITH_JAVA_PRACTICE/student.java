public class student {
    // Fields — সরাসরি class এর ভেতরে
    String name;
    int roll;

    // Constructor — সরাসরি class এর ভেতরে, main() এর বাইরে
    student(String n, int r) {
        name = n;
        roll = r;
    }

    // Method — সরাসরি class এর ভেতরে
    void showInfo() {
        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + roll);
    }

    // main() আলাদা, class এর ভেতরে কিন্তু বাকি সব থেকে independent
    public static void main(String[] args) {
        student s1 = new student("Kawsar", 101);
        s1.showInfo();
    }
}