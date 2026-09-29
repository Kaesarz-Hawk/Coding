class Vehicle {
    int speed;

    Vehicle(int speed) {
        this.speed = speed;
        System.out.println("Vehicle constructor called");
    }

    void move() {
        System.out.println("Vehicle is moving at speed: " + speed + " km/h");
    }
}

    class Car extends Vehicle {

        String brand;

        Car(int speed, String brand) {
            super(speed);
            this.brand = brand;
            System.out.println("Car constructor called");

        }

    @Override 
    void move() {
        System.out.println("Car " + brand + " is moving at speed: " + speed + " km/h");
    }
    }

        

class Main {
    public static void main(String[] args) {
      Car car = new Car(120, "Toyota");
      car.move();
    }
}