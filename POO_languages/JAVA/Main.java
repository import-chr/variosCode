class Main {
    public static void main(String[] args) {
        System.out.println("Hello Wolrd");

        Car car0 = new Car("QWE123", new Account("David", "da195465"));
        car0.passenger = 2;

        Car car1 = new Car("TRY987", new Account("Luis", "lu472930"));
        car1.passenger = 4;

        car0.printData();
        car1.printData();
    }
}