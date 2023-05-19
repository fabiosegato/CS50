import re
import csv
from sys import argv
import sys

def main():

    if len(argv)!= 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    file = open(argv[1], "r")
    data = list(csv.DictReader(file, delimiter=","))
    file.close()

    file2 = open(argv[2], "r")
    text = file2.readline()
    file2.close()

    source = []
    for h in data[0].keys():
        source.append(str(count_contigous_str(text,h)))
    source.pop(0)

    for c in data:
        target=[]
        for h in data[0].keys():
            target.append(c[h])
        target.pop(0)

        if source == target:
            print(c["name"])
            sys.exit(0)

    print("No match")
    sys.exit(0)


def count_contigous_str(pString,pSubString):
    s = pString
    substr = pSubString
    result = re.findall(substr,s)
    while len(result) != 0:
        result = re.findall(substr,s)
        substr += pSubString
        if len(re.findall(substr,s)) == 0:
            return len(re.findall(pSubString,result[0]))
    return 0

main()