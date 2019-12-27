
# 27 December 2019
## DBGUI.java
- Added setEmployee(Employee e): fills Employee object's data from gui t
ext fields
- Fixed getGuiTextFields(Employee e) -> getGuiTextFields(): no need to take Employee reference since we can use this reference
- Update button action added.
        
## DBManager.java
- Fixed openConnection() issue where the actual code for opening connection was in constructor: 
>con=DriverManager.getConnection(*connection_details*)
- Fixed closeConnection()
- Fixed getData(): moved the query statement to the method rather than being in constructor and closed both query statement and connection after filling the vector's data.
- Added updateEmployee(int pos, Employee e1) which takes both the position of the Employee in vector and the Employee reference to update an already existent Employee in DB and then call the getData().

## Employee.java
- Added setters for all fields.
- Added printEmployee() which is helpful in debugging. 

