from cs50 import get_int

h=0
while not (h>0 and h<9):
    h = get_int("Height: ")

for i in range(1,h+1):
    print((" " *(h-i))+("#" *i)+"  "+("#" *i))