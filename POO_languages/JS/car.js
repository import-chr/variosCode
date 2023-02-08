class Car {
    id;
    license;
    driver;
    passenger;

    constructor(license, driver) {
        this.license = license;
        this.driver = driver;
    }

    printDataCar() {
        console.log(this.license);
        console.log(this.driver.name);
        console.log(this.driver.document);
    }
}