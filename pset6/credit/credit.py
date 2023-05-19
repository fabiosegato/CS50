from cs50 import get_string

flags = {
   "3": "AMEX",
   "5": "MASTERCARD",
   "4": "VISA"
}

cardNum = get_string("Card number: ")
count=0
sumEven=0
sumOdd=0

for digit in cardNum[::-1]:
    count = count+1
    if count%2 == 0:
        sumEven += int((int(digit)*2/10))+int((int(digit)*2%10))
    else:
        sumOdd += int(digit)

if (sumEven+sumOdd)%10==0:
    print(flags[cardNum[0]])
else:
    print("INVALID")