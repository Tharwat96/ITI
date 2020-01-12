/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cmdcalculator;

/**
 *
 * @author Tharwat
 */
public class CmdCalculator {
    
    static float add(float n1, float n2)
    {
        return n1 + n2;
    }
    
    static float subtract(float n1, float n2)
    {
        return n1 - n2;
    }
    
    static float divide(float n1, float n2)
    {
        return n1 / n2;
    }
    
    static float multiply(float n1, float n2)
    {
        return n1*n2;
    }

    public static void main(String[] args) 
    {
        switch (args[1])
        {
            case "+":
                System.out.println(CmdCalculator.add(Float.parseFloat(args[0]), Float.parseFloat(args[2])));
                break;
            case "-":
                System.out.println(CmdCalculator.subtract(Float.parseFloat(args[0]), Float.parseFloat(args[2])));
                break;
            case "x":
                System.out.println(CmdCalculator.multiply(Float.parseFloat(args[0]), Float.parseFloat(args[2])));
                break;
            case "/":
                System.out.println(CmdCalculator.divide(Float.parseFloat(args[0]), Float.parseFloat(args[2])));
                break;
            default:
                System.out.println("No operator found");
            
                
        }    
    }
    
}
