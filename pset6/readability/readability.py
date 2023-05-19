from cs50 import get_string
import re

text = get_string("Text: ")

totalWords = len(re.findall(" ", text))+1
totalLetters = len(re.sub("[^a-zA-Z0-9]", "", text))
totalSentences = len(re.findall("[\.\?\!]", text))

grade = round((0.0588 *totalLetters*100/totalWords) - (0.296*totalSentences*100/totalWords) - 15.8)

if grade <= 16:
    if grade >= 1:
        print(f"Grade: {grade}")
    else:
        print("Before Grade 1")
else:
    print("Grade 16+")

