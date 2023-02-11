from account import Account
from car import Car
from uberX import UberX

if __name__ == "__main__":
    print("Hello World")

    uberx = UberX("QWE123", Account("David Lopez", "da489308"), "Chevrolet", "Spark")

    print(vars(uberx))
    print(vars(uberx.driver))