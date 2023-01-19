def main():

    height = get_height()
    print_pyramid(height)


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if 0 < n < 9:
                return n
        except ValueError:
            continue


def print_pyramid(height):
    for i in range(height):
        blocks = i + 1
        spaces = height - blocks

        print(" " * spaces, end="")
        print("#" * blocks)
        

main()

 

    
    
    
