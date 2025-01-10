word = input("Enter a string:")
v = ['a','i','e','o','u']
vowel=0
cons=0

for i in word:
    if i in v :
        vowel+=1
    else :
        cons+=1
print("vowels:",vowel)
print("consonant:",cons)
