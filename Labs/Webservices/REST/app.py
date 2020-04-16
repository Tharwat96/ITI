from flask import Flask, request, jsonify
import sqlite3
from sqlite3 import Error, IntegrityError

app = Flask(__name__)
db_file_path = r'sqlite3.db'

# table sql statements
sql_create_employees_table = """ CREATE TABLE IF NOT EXISTS employees (
                                    id integer PRIMARY KEY,
                                    name text NOT NULL,
                                    salary integer
                                ); """

# create tables
try:
    with sqlite3.connect(str(db_file_path)) as conn:
        # create employees table
        c = conn.cursor()
        c.execute(sql_create_employees_table)
except Error as e:
    print("Error! cannot create the database connection.")
    print(e)


def select_employee(id='%', db_file=db_file_path):
    if id != '%':
        id = f'={id}'
    else:
        id = " LIKE '%'"
    with sqlite3.connect(str(db_file)) as conn:
        sql = f''' SELECT * FROM employees WHERE id{id}; '''
        cur = conn.cursor()
        cur.execute(sql)
        return cur.fetchall()


def insert_employees_row(employee, db_file=db_file_path):
    with sqlite3.connect(str(db_file)) as conn:
        sql = f''' INSERT INTO employees (id, name, salary) VALUES(?,?,?); '''
        print(sql)
        cur = conn.cursor()
        try:
            cur.execute(sql, (employee['id'], employee['name'], employee['salary']))
        except IntegrityError as e:
            return {"error": "ID must be unique, salary must be integers"}


def update_employees_row(employee, db_file=db_file_path):
    with sqlite3.connect(str(db_file)) as conn:
        print(employee)
        sql = f''' UPDATE employees SET name = ? ,salary= ? WHERE id = ?; '''
        print(sql)
        cur = conn.cursor()
        try:
            cur.execute(sql, (employee['name'], employee['salary'], employee['id']))
            conn.commit()
            return jsonify({"success": "update successful"})
        except Exception as err:
            print(err)
            return jsonify({"error": f"update failed"})


def delete_employee(id, db_file=db_file_path):
    with sqlite3.connect(str(db_file)) as conn:
        sql = f''' DELETE FROM employees WHERE id=?; '''
        print(sql)
        try:
            cur = conn.cursor()
            cur.execute(sql, (id,))
            conn.commit()
            return jsonify({"success": "employee deleted successfully"})
        except Exception as e:
            return jsonify({"error": "ID must be an existing integer"})


@app.route('/')
def hello_world():
    return 'Welcome to the employees RESTful api, use /employees and employees/<id> to use it correctly'


@app.route('/employees', methods=['GET', 'POST'])
def get_all_employees():
    employees = [
        {
            'id': '1',
            'name': 'test',
            'salary': '5000',
        },
    ]
    if request.method == 'POST':
        new_employee = dict()
        new_employee['id'] = request.form['id']
        new_employee['name'] = request.form['name']
        new_employee['salary'] = request.form['salary']
        insert_result = insert_employees_row(new_employee)
        if insert_result is not None:
            return insert_result
        employees = select_employee()
        print(employees)
        return jsonify(employees)
    elif request.method == 'GET':
        employees = select_employee()
        return jsonify(employees)


@app.route('/employees/<int:id>', methods=['GET', 'PUT', 'DELETE'])
def specific_employee_operation(id):
    if request.method == 'GET':
        employee = select_employee(id)
        print(employee)
        return jsonify(employee)
    if request.method == 'PUT':
        edited_employee = dict()
        edited_employee['id'] = id
        edited_employee['name'] = request.form['name']
        edited_employee['salary'] = request.form['salary']
        update_result = update_employees_row(edited_employee)
        return update_result
    if request.method == 'DELETE':
        return delete_employee(id)


if __name__ == '__main__':
    app.run(debug=True)
