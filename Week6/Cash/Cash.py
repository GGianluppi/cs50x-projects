from cs50 import get_float


def main():

    dollar = get_dollar()
    cents = calculate_cents(dollar)
    coins = calculate_coins(cents)

    print(coins)


def get_dollar():
    while True:
        dollar = get_float("Change owed: ")
        try:
            if dollar > 0:
                return dollar

        except ValueError:
            continue


def calculate_cents(dollar):
    return round(dollar * 100)


def calculate_coins(cents):
    coins = 0
    if cents >= 25:
        coins += cents // 25
        cents = cents % 25

    if cents >= 10:
        coins += cents // 10
        cents = cents % 10

    if cents >= 5:
        coins += cents // 5
        cents = cents % 5

    coins += cents

    return coins
    

main()

 

    
    
    
