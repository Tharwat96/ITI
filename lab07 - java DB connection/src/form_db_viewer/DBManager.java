package form_db_viewer;

import java.sql.*;
import java.util.Vector;

public class DBManager {

    private Connection con;
    private ResultSet rs;
    private Vector<Employee> emp;
    int counter;
    String netbeansFix;
    

    public static void main(String[] args) {
        
        DBManager db = new DBManager();
       

    }

    public DBManager()
    {
        netbeansFix = "?useUnicode=true&useJDBCCompliantTimezoneShift=true&useLegacyDatetimeCode=false&serverTimezone=UTC";
        counter = 0;

        emp = new Vector<Employee>();
        try
        {
//            rs = con.getMetaData().getCatalogs();
            openConnection();
            getData();
            con.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }

    public void openConnection()
    {

        try{
            con=DriverManager.getConnection(
                    "jdbc:mysql://127.0.0.1:3306/lab07","root","mysql");
                //here lab07 is database name, root is username
//            rs1 = con.getMetaData().getCatalogs();
//            System.out.println(rs1);

        }catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public void closeConnection()
    {
        try
        {
        //closing statement
        con.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }

    }

    public void getData() throws SQLException
    {
        Statement stmt=con.createStatement();
        rs=stmt.executeQuery("select * from Employees");
        Employee e;
        while(rs.next())
        {
            e = new Employee(rs.getInt(1),rs.getString(2), rs.getString(3), rs.getString(4), rs.getString(5), rs.getInt(6));
            emp.add(e);
            //System.out.println();
            //System.out.println(rs.getInt(1) + "  " + rs.getString(2) + "  " + rs.getString(3));
        }
        stmt.close();       //closing statement
        con.close();
    }
    
    public int getVectorSize()
    {

        return emp.size();
    }
    
    public Employee getNextEmployee()
    {

        if(counter >= 0 && counter < emp.size())
        {
//            if(counter == 0)
//            {
//                Employee temp = emp.get(counter);
//                counter++;
//                return temp;
//            }
            if(counter < emp.size()-1)
                counter++;
            return emp.get(counter);

        }
        else
            return null;
        
    }

    public Employee getPreviousEmployee()
    {
        if(counter >= 0)
        {
            if(counter > 0)
                counter--;
            return emp.get(counter);
        }
        else
            return null;
    }

    public Employee getFirstEmployee()
    {
        counter = 0;
        return emp.get(counter);
    }

    public Employee getLastEmployee()
    {
        counter = emp.size()-1;
        return emp.get(counter);
    }

    public void updateEmployee(int pos, Employee e1) throws SQLException {
        Employee e2;
        e2 = emp.get(pos);
        openConnection();
        PreparedStatement pst = con.prepareStatement
        (
        "UPDATE Employees " +
            "SET FirstName=?, MiddleName=?, LastName=?, Email=?, Phone=? " +
            "WHERE ID=?;"
        );
        pst.setString (1, e1.getFirstName());
        pst.setString (2, e1.getMiddleName());
        pst.setString (3, e1.getLastName());
        pst.setString (4, e1.getEmail());
        pst.setInt (5, e1.getPhone());
        pst.setInt(6, e2.getID());
        pst.executeUpdate() ;
        getData();
        pst.close();
        closeConnection();
    }

    public void deleteEmployee(int id)
    {
        try
        {
            //emp.remove(counter);
            PreparedStatement pre = con.prepareStatement("DELETE FROM Employees WHERE ID = ?");
            pre.setInt( 1 , id);
            pre.executeUpdate();
            getData();
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }

    }

}

