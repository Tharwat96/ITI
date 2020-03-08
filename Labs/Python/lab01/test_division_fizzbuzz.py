def test_division(number):
    if user_input % 3 == 0 and user_input % 5 == 0:
        print("FizzBuzz")
    elif user_input % 3 == 0:
        print("Fizz")
    elif user_input % 5 == 0:
        print("buzz")


user_input = int(input("Please enter a number to test if it is divisible by 3: "))
test_division(user_input)
