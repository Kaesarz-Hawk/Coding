// Q2(a) [5 Marks]: Multilevel Inheritance (Person -> Employee -> BranchManager) + Array of 3 Objects

class Person {
    String name;

    Person(String name) {
        this.name = name;
    }
}

class Employee extends Person {
    int empId;
    double salary;

    Employee(String name, int empId, double salary) {
        super(name);
        this.empId = empId;
        this.salary = salary;
    }
}

class BranchManager extends Employee {
    String branchName;

    BranchManager(String name, int empId, double salary, String branchName) {
        super(name, empId, salary);
        this.branchName = branchName;
    }

    void display() {
        System.out.println("Name: " + name + " | ID: " + empId
                + " | Salary: " + salary + " | Branch: " + branchName);
    }
}

public class Q2a_BranchManager_Array {
    public static void main(String[] args) {
        // Create array of 3 BranchManager objects
        BranchManager[] branch = new BranchManager[3];

        branch[0] = new BranchManager("Kawsar", 101, 65000.0, "Mirpur Branch");
        branch[1] = new BranchManager("Sohan", 102, 60000.0, "Dhanmondi Branch");
        branch[2] = new BranchManager("Resalat", 103, 62000.0, "Uttara Branch");

        // Traverse using for loop
        for (int i = 0; i < branch.length; i++) {
            branch[i].display();
        }
    }
}
