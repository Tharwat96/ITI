def gen_list(length, start):
    new_start = start + 1
    generated_list = list(range(new_start, new_start + length))
    return generated_list


print(gen_list(10, 5))
