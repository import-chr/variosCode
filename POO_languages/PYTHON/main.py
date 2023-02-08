from account import Account
from car import Car

if __name__ == "__main__":
    print("Hello World")

    car0 = Car("QWE123", Account("David Rivera", "da489308"))

    print(vars(car0))
    print(vars(car0.driver))