public class Shape {
    int area(int side) {
        return side * side;
    }

    int area(int length, int width) {
        return length * width;
    }

    double area(double radius) {
        return 3.14 * radius * radius;
    }

    public static void main(String[] args) {
        Shape shape = new Shape();
        System.out.println("Area of square: " + shape.area(5));
        System.out.println("Area of rectangle: " + shape.area(4, 6));
        System.out.println("Area of circle: " + shape.area(3.0));
    }
}
