import os
import json
import re
from modules import general_functions

signed_in_user_email = ""
if os.path.exists("data/signed_in_user_email"):
    signed_in_user_email = open('data/signed_in_user_email').read()

users = {}
if os.path.exists("data/users.json"):
    try:
        with open('data/users.json', 'r') as gf:
            users = json.load(gf)
    except Exception as exception:
        print("Users data is not loaded correctly:", exception, ":(")


def is_matched_password(password, password_confirmation):
    return True if password == password_confirmation else False


def is_valid_email(email):
    email_regex = re.compile(r"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)")
    return True if email_regex.match(email) else False


def is_email_signed_up(email):
    try:
        return True if users[email] else False
    except KeyError:
        return False


def is_valid_phone_number(phone):
    return True
    # phone_eg_regex = re.compile(r"(01)(0|1|2|5)[0-9]{8}")
    # return True if re.match(phone_eg_regex, phone) else False


def is_signed_up(email):
    if email in users:
        return True
    else:
        return False


def sign_up_menu():
    first_name = input("First name: ")
    last_name = input("Last name: ")
    email = input("Email: ")
    if not is_valid_email(email):
        print("Email is not written in the right form.")
        return
    if is_email_signed_up(email):
        print("Email is already signed up, try signing in.")
        return
    password = input("Password: ")
    confirm_password = input("Confirm Password: ")
    if not is_matched_password(password, confirm_password):
        print("Passwords don't match")
        return
    phone = int(input("Phone number: "))
    if not is_valid_phone_number(phone):
        print("Phone number is not valid")
        return
    users[email] = {"first_name": first_name,
                    "last_name": last_name,
                    "phone": phone,
                    "password": password}
    general_functions.write_dict_to_json("users", users)
    print("Sign up success, welcome to our platform.")


def sign_in(email, password):
    print(users[email]['password'])
    if is_signed_up(email):
        if users[email]['password'] == password:
            f = open("data/signed_in_user_email", "w")
            f.write(email)
            f.close()
            return True
    return False


def sign_in_menu():
    email = input("Email: ")
    password = input("Password: ") if is_valid_email(email) else print("email is not valid")
    status = sign_in(email, password)
    if status:
        global signed_in_user_email
        signed_in_user_email = email
        print("You are now signed in")
    else:
        print("Wrong credentials, please try again.")


def check_login():
    if os.path.exists("data/signed_in_user_email"):
        f1 = open("data/signed_in_user_email", "r")
        global signed_in_user_email
        signed_in_user_email = f1.read()
        f1.close()
        print("You are logged in as: ", signed_in_user_email)
        confirm = input("Confirm logging out? (y/n)")
        if confirm.lower() == 'y':
            os.remove("data/signed_in_user_email")
            signed_in_user_email = ""
        else:
            return
    else:
        print("You are not currently logged in, choose an option from the following:")
        try:
            user_input = int(input("1 - Signin. \n"
                                   "2 - Signup.\n"
                                   "3- Main menu.\n"))
        except TypeError as e:
            print("Please enter a valid option,", e)
        if user_input == 1:
            sign_in_menu()
        elif user_input == 2:
            sign_up_menu()
        elif user_input == 3:
            return
        else:
            print("Invalid choice.")
