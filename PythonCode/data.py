import random

class Data():
    def __init__(self):
        self.cientist = random.choice(['Einstein', 'Rosen'])
        self.num = random.randint(1, 100)
        self.event = None

    def isPrime(self):
        if self.num == 1:
            return False
        for i in range(2, self.num):
            if self.num % i == 0:
                return False
        return True

    def __str__(self):
        return f'{self.cientist} {self.num}'    