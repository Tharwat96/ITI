# from datetime import *
import datetime
import os
import json
import ast
from modules import registration, general_functions

# TODO
# 1- Fix current date validation with start date, something conflicts with imports O.o

projects = {}
user_email = registration.signed_in_user_email

if os.path.exists("data/projects.json"):
    try:
        with open('data/projects.json', 'r') as gf:
            projects = json.load(gf)
        # ast.literal_eval(projects)
    except Exception as exception:
        print("Projects data is not loaded correctly,", e)


def create_project():
    pass


def print_create_project_menu():
    if user_email == "":
        print("You must be signed up in order to create a campaign")
        return
    # current_date = datetime.date(datetime.now())
    # current_year, current_month, current_day = map(int, current_date.split('-'))

    print("Enter the following campaign details:\n")
    title = input("Title: ")
    description = input("Description: ")
    total_target = input("Total target: ")
    start_date_input = input('Enter campaign start date in YYYY-MM-DD format')
    try:
        year, month, day = map(int, start_date_input.split('-'))
        start_date = datetime.date(year, month, day)
    except ValueError as e:
        print("Date entered is incorrect,", e)
        return
    # if start_date < current_date:
    #     print("Date must be in the future")
    end_date_input = input('Enter campaign end date in YYYY-MM-DD format')
    try:
        year, month, day = map(int, end_date_input.split('-'))
        end_date = datetime.date(year, month, day)
    except ValueError as e:
        print("Date entered is incorrect,", e)
        return
    if end_date < start_date:
        print("Campaign ending date must be after start date.")
        return
    projects[user_email][title] = {"Description": description,
                                   "Total Target": total_target,
                                   "Start Date": start_date,
                                   "End Date": end_date}
    general_functions.write_dict_to_json('projects', projects)


def show_own_projects():
    print("SHOW OWN PROJECTS")
    try:
        general_functions.print_dict(projects[user_email])
    except KeyError as e:
        print("Have you created any projects yet? ¯\_(ツ)_/¯,")


def list_projects():
    # print(projects)
    general_functions.print_dict(projects)


def edit_project(project_name):
    try:
        old_project_details = projects[user_email][project_name]
        print_create_project_menu()
        delete_project(project_name)
        general_functions.write_dict_to_json('projects', projects)
    except Exception as e:
        print("Something went wrong, is it a valid project name?")


def delete_project(project_name):
    del projects[user_email][project_name]
    general_functions.write_dict_to_json('projects', projects)


def print_edit_project():
    show_own_projects()
    project_name = input("Please enter project name to edit: ")
    edit_project(project_name)


def print_delete_project():
    show_own_projects()
    project_name = input("Please enter project name to delete: ")
    delete_project(project_name)


def search_in_projects(date):
    pass
