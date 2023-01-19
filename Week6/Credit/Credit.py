def main():
    cc_number = input("Number: ")
    card_brand = verify_card_brand(cc_number)
    print(card_brand)


def verify_card_brand(cc_number):
    number = len(cc_number)

    brand = ""
    if number in [13, 16] and cc_number.startswith("4"):
        brand = "VISA"

    elif number == 15 and cc_number.startswith(("34", "37")):
        brand = "AMEX"

    elif number == 16 and cc_number.startswith(("51", "52", "53", "54", "55")):
        brand = "MASTERCARD"

    if brand != "" and check_luhn(cc_number):
        return brand
    else:
        return "INVALID"


def check_luhn(cc_number):
    sum = 0

    for i, digit in enumerate(cc_number[::-1]):
        if i % 2 == 1:
            multiplied_digit = int(digit) * 2
            if multiplied_digit >= 10:
                sum += 1 + multiplied_digit % 10

            else:
                sum += multiplied_digit

        else:
            sum += int(digit)

    return sum % 10 == 0


main()



 

    
    
    
