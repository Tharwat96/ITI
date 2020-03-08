vowels = ["a", "e", "i", "o", "u"]
user_input = input("Enter a sentence to count vowels in it: ")
number = 0
for i in user_input.lower():
    if i in vowels:
        number = number + 1
print(number)