public class UberPool extends Car {
    String model;
    String brand;

    public UberPool(String license, Account driver, String model, String brand) {
        super(license, driver);
        this.model = model;
        this.brand = brand;
    }
}
