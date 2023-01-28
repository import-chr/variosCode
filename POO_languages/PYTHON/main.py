from car import Car

if __name__ == "__main__":
    print("Hello World")

    car0 = Car()
    car0.driver = "David"
    car0.license = "QWE123"
    car0.passenger = 2

    car1 = Car()
    car1.driver = "Luis"
    car1.license = "TRY987"
    car1.passenger = 4

    print(vars(car0))
    print(vars(car1))