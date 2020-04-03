const assert = require('assert');

class Employee {
  constructor(firstName, lastName, salary) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.salary = salary;
  }

  getFullName() {
    return this.firstName + ' ' + this.lastName;
  }

  getEmail() {
    return this.firstName + '.' + this.lastName + '@' + 'company.com';
  }

  raiseSalary() {
    this.salary = this.salary * this.raise;
  }

}

  Employee.prototype.raise = 1.04;

let employee;
beforeEach(() => {
  console.log('Employee created!');
  employee = new Employee('Wesam', 'Mustafa', 5000);
});

describe('Suite tests for `Employee`', () => {
  // Assert that new object created with initial data
  it('Should create new employee', () => {

    console.log(employee.getFullName());
    console.log(employee.getEmail());
    console.log(employee.salary);
    assert.equal(employee.salary, 5000)

    employee.raiseSalary();
    console.log(employee.salary);


    assert.equal(employee.getFullName(), "Wesam Mustafa")
    assert.equal(employee.getEmail(), "Wesam.Mustafa@company.com")
    assert.equal(employee.salary, 5000*1.04)
  })

  // Assert when we change first name and last name getFullName function return correct name with the new name
  it('Should have changed first name and last name', () => {
    employee.firstName = "Tharwat"
    employee.lastName = "Abouhelal"

    console.log(employee.getFullName());

    assert.equal(employee.getFullName(), "Tharwat Abouhelal")



  })
  // Assert when we change first name and last name getEmail function return correct email with the new name

  it('Should have changed first name and last name and the email should have changed accordingly', () => {
    employee.firstName = "Tharwat"
    employee.lastName = "Abouhelal"

    assert.equal(employee.getEmail(), "Tharwat.Abouhelal@company.com")

    console.log(employee.getEmail());

  })

  // Assert when we raise employee salary, the salary will be confirmed  increased for this specific employee
  it('Should have changed employee salary', () => {
    employee.salary = 20000

    assert.equal(employee.salary, 20000)

    console.log(`new setted salary ${employee.salary}`);

    employee.raiseSalary();
    console.log(`new salary after raise ${employee.salary}`);

    assert.equal(employee.salary, 20000*1.04)

  })
});