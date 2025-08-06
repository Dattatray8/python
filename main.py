str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")
print(
    "Strings are Anagrams"
    if sorted(str1) == sorted(str2)
    else "Strings are not Anagrams"
)
