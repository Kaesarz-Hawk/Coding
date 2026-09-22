public class Employee {
    private String name;
    private int employeeId;
    private double basicSalary;

    // Constructor
    public Employee(String name, int employeeId, double basicSalary) {
        this.name = name;
        this.employeeId = employeeId;
        this.basicSalary = basicSalary;
    }

    // Adds 20% allowance to the basic salary
    public double calculateSalary() {
        double allowance = basicSalary * 0.20;
        return basicSalary + allowance;
    }

    public void displayEmployee() {
        System.out.println("Name: " + name);
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Total Salary: " + calculateSalary());
        System.out.println("-----------------------------");
    }

    public static void main(String[] args) {
        Employee e1 = new Employee("Ayesha Rahman", 101, 30000);
        Employee e2 = new Employee("Rakib Hasan", 102, 45000);

        e1.displayEmployee();
        e2.displayEmployee();
    }
}
