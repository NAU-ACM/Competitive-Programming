n = int(input())

for i in range(n):
    a, b = list(map(int, input().strip().split(" ")))
    print(pow(a, b, 1000000007))
