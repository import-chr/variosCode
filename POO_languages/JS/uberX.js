class UberX extends Car {
    constructor(license, driver, brand, model) {
        super(license, driver);
        this.brand = brand;
        this.model = model;
    }

    printDataCar() {
        console.log(this.license);
        console.log(this.driver.name);
        console.log(this.driver.document);
        console.log(this.brand);
        console.log(this.model);
    }
}