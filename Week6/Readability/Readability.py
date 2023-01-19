def main():

    text = input("Text: ")
    letters, words, sentences = get_text(text)
    coleman = calculate_coleman(letters, words, sentences)
    print_grade(coleman)


def calculate_coleman(letters, words, sentences):
    L = 100 * (letters / words)
    S = 100 * (sentences / words)
    return round(0.0588 * L - 0.296 * S - 15.8)


def print_grade(coleman):
    if coleman < 1:
        print("Before Grade 1")
    elif coleman >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {coleman}")


def get_text(text):
    letters = 0
    words = 1
    sentences = 0

    for letter in text:
        if letter.isalpha():
            letters += 1
        elif letter == " ":
            words += 1
        elif letter in [".", "!", "?"]:
            sentences += 1

    print(f"{letters} letters")
    print(f"{words} words")
    print(f"{sentences} sentences")

    return letters, words, sentences


main()

 

    
    
    
