if __name__ == "__main__":
    x = 0
    for a in range(100):
        for b in range(100):
            x = max(x, sum(int(i) for i in str(a**b)))
    print(x)