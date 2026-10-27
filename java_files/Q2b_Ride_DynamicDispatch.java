// Q2(b) [5 Marks]: Abstract Class Ride + 3 Child Classes (BikeRide, CarRide, PremiumUber) + Dynamic Method Dispatch

abstract class Ride {
    double distance;

    Ride(double distance) {
        this.distance = distance;
    }

    abstract double calculateFare();
}

class BikeRide extends Ride {
    BikeRide(double distance) {
        super(distance);
    }

    @Override
    double calculateFare() {
        return distance * 15.0; // 15 Tk per km
    }
}

class CarRide extends Ride {
    CarRide(double distance) {
        super(distance);
    }

    @Override
    double calculateFare() {
        return distance * 40.0; // 40 Tk per km
    }
}

class PremiumUber extends Ride {
    PremiumUber(double distance) {
        super(distance);
    }

    @Override
    double calculateFare() {
        return (distance * 60.0) + 50.0; // 60 Tk per km + 50 Tk luxury charge
    }
}

public class Q2b_Ride_DynamicDispatch {
    public static void main(String[] args) {
        Ride r; // Parent reference variable

        // Holding Child objects in Parent reference (Upcasting & Dynamic Method Dispatch)
        r = new BikeRide(10);
        System.out.println("BikeRide Fare (10 km): " + r.calculateFare() + " Tk");

        r = new CarRide(10);
        System.out.println("CarRide Fare (10 km): " + r.calculateFare() + " Tk");

        r = new PremiumUber(10);
        System.out.println("PremiumUber Fare (10 km): " + r.calculateFare() + " Tk");
    }
}
