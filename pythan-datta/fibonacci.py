n = int(input("Enter a number of terms:"))
a , b = 0 , 1
print("Fibonacci series:")
for _ in range(n):
    print(a , end="  ")
    a, b = b, a+b
