word = input("Enter a string:")
r=""
for i in word:
    if i not in r :
        r+=i
print(r)
