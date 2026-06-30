def catalan(n):
    if n == 0 or n == 1:
        return 1
    catalan_number = 1
    for i in range(2, n + 1):
        catalan_number = catalan_number * (4 * i - 2) // (i + 1)
    return catalan_number
num = input()
for i in range(int(num)):
    print(catalan(int(input())))