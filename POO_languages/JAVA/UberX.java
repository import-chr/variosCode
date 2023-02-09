public class UberX extends Car{
    String model;
    String brand;
    
    public UberX(String license, Account driver, String model, String brand) {
        super(license, driver);
        this.model = model;
        this.brand = brand;
    }
}