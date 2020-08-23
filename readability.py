import cs50
import sys

# get string from user
text = cs50.get_string("Text:")

# count letters
lettercount = 0
for i in range(0, len(text)):
    if text[i].isalpha() == True:
        lettercount = lettercount + 1
        
# Count words
words = 1

for j in range(0, len(text)):
    if ord(text[j]) == 32:
        words = words + 1
        
# Count sentences
sentences = 0

for k in range(len(text)):
    if ord(text[k]) == 46 or ord(text[k]) == 33 or ord(text[k]) == 63:
        sentences = sentences + 1

# Prep Average per 100

L = (lettercount / words) * 100
S = (sentences / words) * 100
# Coleman - Liau index

index = round(0.0588 * L - 0.296 * S - 15.8)

# Sort

if index < 1:
    print("Before Grade 1")
elif (index >= 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")
