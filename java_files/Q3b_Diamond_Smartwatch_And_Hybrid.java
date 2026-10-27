// Q3b [5 Marks]: Diamond Interface UML Problem (Both Versions from Friend's Note)
// Version 1: Device -> Health, Fitness -> Smartwatch
// Version 2: Vehicle -> Land, Water -> Hybrid

// ================= VERSION 1: Smartwatch Diamond Interface =================
interface Device {
    void powerOn();
}

interface Health extends Device {
    void checkHeartRate();
}

interface Fitness extends Device {
    void trackSteps();
}

class Smartwatch implements Health, Fitness {
    String brand;

    Smartwatch(String brand) {
        this.brand = brand;
    }

    @Override
    public void powerOn() {
        System.out.println(brand + " Smartwatch is powered ON.");
    }

    @Override
    public void checkHeartRate() {
        System.out.println("Heart Rate: 72 BPM (Normal).");
    }

    @Override
    public void trackSteps() {
        System.out.println("Steps Tracked: 8500 steps today.");
    }
}

// ================= VERSION 2: Hybrid Vehicle Diamond Interface =================
interface Vehicle {
    void start();
}

interface Land extends Vehicle {
    void drive();
}

interface Water extends Vehicle {
    void sail();
}

class Hybrid implements Land, Water {
    String model;

    Hybrid(String model) {
        this.model = model;
    }

    @Override
    public void start() {
        System.out.println(model + " Hybrid Vehicle started.");
    }

    @Override
    public void drive() {
        System.out.println("Driving on land highway.");
    }

    @Override
    public void sail() {
        System.out.println("Sailing across water.");
    }
}

public class Q3b_Diamond_Smartwatch_And_Hybrid {
    public static void main(String[] args) {
        System.out.println("--- VERSION 1: Smartwatch ---");
        Smartwatch sw = new Smartwatch("Apple Watch");
        sw.powerOn();
        sw.checkHeartRate();
        sw.trackSteps();

        System.out.println("
--- VERSION 2: Hybrid Vehicle ---");
        Hybrid hv = new Hybrid("Amphibious Cruiser");
        hv.start();
        hv.drive();
        hv.sail();
    }
}
