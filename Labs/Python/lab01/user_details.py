import re

EMAIL_REGEX = re.compile(r"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)")
username = input("Please enter your name: ")
if username:
    email = input("Please enter your email: ")
    if EMAIL_REGEX.match(email):
        print("Username: {0}, Email: {1}".format(username, email))
    else:
        print("email is not of email form")
