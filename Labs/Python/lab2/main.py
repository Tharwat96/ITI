import os
from modules import registration
from modules import projects


# TODO
# 1- Check if user is already signed in
# 2- assign email of user to variable signed_in_user_email


def clear():
    os.system('clear')


# def check_files():
#     if not (os.path.exists("data/projects")):
#         f = open("data/projects", "w")
#         f.write("")
#         f.close()
#     if not (os.path.exists("data/users")):
#         f1 = open("data/users", "w")
#         f1.write("")
#         f1.close()
#
#
# check_files()


def print_menu():
    print(registration.signed_in_user_email)
    if registration.signed_in_user_email == "":
        print("1- Signin/Signup")
    else:
        print("1- Logout")
    print("2- Create project")
    print("3- Your projects")
    print("4- All projects")
    print("5- Edit your projects")
    print("6- Delete a project")
    # print("7- Search for a project using date")
    print("0- Exit")
    user_input = input("\nPlease choose your desired operation: ")
    selection(int(user_input))


def selection(sel):
    if sel == 1:
        registration.check_login()
    elif sel == 2:
        projects.print_create_project_menu()
    elif sel == 3:
        projects.show_own_projects()
    elif sel == 4:
        projects.list_projects()
    elif sel == 5:
        projects.print_edit_project()
    elif sel == 6:
        projects.print_delete_project()
    # elif sel == 7:
    #     pass
    elif sel == 0:
        global app_flag
        app_flag = False
    else:
        print("Unrecognized entry, please select an option from the menu: ")


print("WELCOME TO CROWDSOURCING PROJECT")
app_flag = True
while app_flag:
    print_menu()

# clear()
