/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package form_db_viewer;


public class Employee {
    
    int id;
    String firstName;
    String middleName;
    String lastName;
    String email;
    int phone;
    
    public Employee(){
        
        id = 0;
        firstName = null;
        middleName = null;
        lastName = null;
        email = null;
        phone = 0;
    } 
    
    public Employee(int id, String firstName, String middleName, String lastName, String email, int phone){
        
        this.id = id;
        this.firstName = firstName;
        this.middleName = middleName;
        this.lastName = lastName;
        this.email = email;
        this.phone = phone;
    }
    public void setId(int id)
    {
        this.id = id;
    }

    public int getID()
    {
        return id;
    }

    public void setFirstName(String firstName)
    {
        this.firstName = firstName;
    }

    public String getFirstName()
    {
        return firstName;
    }

    public void setMiddleName(String middleName)
    {
        this.middleName = middleName;
    }

    public String getMiddleName()
    {
        return middleName;
    }

    public void setLastName(String lastName)
    {
        this.lastName = lastName;
    }

    public String getLastName()
    {
        return lastName;
    }

    public void setEmail(String email)
    {
        this.email = email;
    }

    public String getEmail()
    {
        return email;
    }

    public void setPhone(int phone)
    {
        this.phone = phone;
    }

    public int getPhone()
    {
        return phone;
    }

    public void printEmployee()
    {
        System.out.println("ID: " + this.getID());
        System.out.println("First Name: " + this.getFirstName());
        System.out.println("Middle Name: " + this.getMiddleName());
        System.out.println("Last Name: " + this.getLastName());
        System.out.println("E-mail: " + this.getPhone());
        System.out.println("Phone: " + this.getEmail());
    }
    
}
