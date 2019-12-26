/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pattern_drawer;

/**
 *
 * @author Tharwat
 */
public class PatternDrawer {
    
    static void drawPattern1(int usr)
    {
        for(int i = 0; i<usr; i++)
        {
            for(int j = 0; j<i; j++)
            {
                
                System.out.print("*");
            }
            System.out.println();
        }
    }
    
    static void drawPattern2(int usr)
    {
        for(int i = 0; i<usr; i++)
        {
            for(int m = usr-i; m>0; m--)
            {
                System.out.print(" ");
            }

            for(int j = 0; j<i; j++)
            {
                
                System.out.print("* ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) 
    {  

        PatternDrawer.drawPattern1(10);
        System.out.println("-----------");
        PatternDrawer.drawPattern2(10);
    }
}
