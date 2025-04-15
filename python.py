
n = int(input("Input please: "))



for i in range(n):
    count = 0
    for j in range(i+1):
        count += 1
        print(count, end="")
    print("")