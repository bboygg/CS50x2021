import cs50


def main():

    while True:
        height = cs50.get_int("Height:")
        if height > 0 and height < 9:
            break
    for i in range(height):
        for j in range(height - i - 1):  # simple math: - i - 1 == -(j+1)
            print(" ", end=' ')
        for k in range(i + 1):
            print("#", end=' ')
            
        print(" ")
        

if __name__ == "__main__":
    main()
