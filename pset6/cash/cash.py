from cs50 import get_float
import math

change = get_float("Change owned: ")

while change < 0:
    change = get_float("Change owned: ")

qtdCoins = math.trunc(change/0.25)
change = round(change-(0.25*(math.trunc(change/0.25))),2)

qtdCoins += math.trunc(change/0.10)
change = round(change-(0.10*(math.trunc(change/0.10))),2)

qtdCoins += math.trunc(change/0.05)
change = round(change-(0.05*(math.trunc(change/0.05))),2)

qtdCoins += math.trunc(change/0.01)
change = round(change-(0.01*(math.trunc(change/0.01))),2)

print(qtdCoins)
