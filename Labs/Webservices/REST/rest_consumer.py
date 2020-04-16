import requests

URL = "http://127.0.0.1:5000/employees"

r = requests.get(url=URL)

print("Get all employees: \n" + str(r.json()))
URL = "http://127.0.0.1:5000/employees"

new_employee = {
    'id': 4,
    'name': "Ayman",
    'salary': 4000
}
r = requests.post(url=URL, data=new_employee)
print("Add new employee: \n" + str(r.json()))

URL = "http://127.0.0.1:5000/employees/4"
rr = requests.get(url=URL)
print("Get an employee: \n" + str(r.json()))

URL = "http://127.0.0.1:5000/employees/4"

employee = {
    'name': "Esraa",
    'salary': 3000
}
r = requests.put(url=URL, data=employee)
print("Edit employee: \n" + str(r.json()))


URL = "http://127.0.0.1:5000/employees/4"
r = requests.delete(url=URL, data=employee)
print("Delete employee: \n" + str(r.json()))
