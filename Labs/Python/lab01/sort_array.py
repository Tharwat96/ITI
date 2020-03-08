print("Please enter 5 numbers to be sorted")
user_input = []
i = 0
while i < 5:
    user_input.append(int(input()))
    i += 1

print("==========")
print(user_input)
print("==========")
user_input.sort()
print("=====Ascending order=====")
print(user_input)
print("=====Descending order=====")
print(user_input[::-1])



