"""word = input("Enter a string:")
for i in word :
    if i == lower() :
        i = i.upper()
        print(i,end=" ")
    elif i == iupper() :
        i = i.lower()
        print(i,end=" ")"""

n = input("enter a string:")
res= ""
for i in range(len(n)) :
    if n[i].isupper() :
        res +=n[i].lower()
    elif n[i].islower() :
        res +=n[i].upper()
print(res)



