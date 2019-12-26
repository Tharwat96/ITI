/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab1;
import complex.Complex;
/**
 *
 * @author Tharwat
 */
public class Lab1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        
        Complex c1 = new Complex();
        Complex c2 = new Complex();
        Complex c3 = new Complex();
        c1.setImag(-5);
        c1.setReal(10);
        c2.setImag(7);
        c2.setReal(2);
        c3 = c3.add(c1, c2);
        c3.print();

    }
    
}
