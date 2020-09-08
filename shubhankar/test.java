def main():
    for _ in range(int(input())):
        n = int(input())
        List = list(map(int, input().split()))
        k = sum(List) % n
        if k == 0:
            print("YES")
        else:
            print("NO")

if _name_ == "_main_":
    main()