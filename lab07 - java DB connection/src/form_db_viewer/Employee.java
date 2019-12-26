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
    
    public int getID()
    {
        return id;
    }
    
    public String getFirstName()
    {
        return firstName;
    }
        
    public String getMiddleName()
    {
        return middleName;
    }
            
    public String getLastName()
    {
        return lastName;
    }
                
    public String getEmail()
    {
        return email;
    }
                    
    public int getPhone()
    {
        return phone;
    }
    
}
