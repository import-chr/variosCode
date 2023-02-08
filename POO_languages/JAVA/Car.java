public class Car {
    Integer id;
    String license;
    Account driver;
    Integer passenger;

    public Car(String license, Account driver) {
        this.license = license;
        this.driver = driver;
    }

    void printData() {
        System.out.println("License: " + license + " Driver Name: " + driver.name);
    }
}
