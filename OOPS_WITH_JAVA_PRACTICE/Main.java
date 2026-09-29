class Vehicle {
    int speed;

    Vehicle() {
        speed = 60;
    }

    void move() {
        System.out.println("Vehicle is moving at speed: " + speed + " km/h");
    }
}

class Car extends Vehicle {   
    @Override
    void move() {
        System.out.println("Car is racing at speed: " + speed + " km/h");
    }
}

public class Main {
    public static void main(String[] args) {
        Vehicle v = new Vehicle();
        v.move();

        Car c = new Car();
        c.move();
    }
}