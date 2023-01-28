class Main {
    public static void main(String[] args) {
        System.out.println("Hello Wolrd");

        Car car0 = new Car();
        car0.driver = "David";
        car0.license = "QWE123";
        car0.passenger = 2;

        Car car1 = new Car();
        car1.driver = "Luis";
        car1.license = "TRY987";
        car1.passenger = 4;

        car0.printData();
        car1.printData();
    }
}