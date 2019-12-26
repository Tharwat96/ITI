/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package complex;

/**
 *
 * @author Tharwat
 */
public class Complex {
    private float real;
    private float imag;
    public void setReal(float i)
    {
        real = i;
    }
    public void setImag(float i)
    {
        imag = i;
    }
    public float getReal()
    {
        return real;
    }
    public float getImag()
    {
        return imag;
    }
    public void print()
    {
        if(imag<0)
             System.out.println(real + " - " + Math.abs(imag) + "i");
        else
            System.out.println(real + " + " + imag + "i");
    }
    
    public Complex add(Complex c1, Complex c2)
    {
        Complex result = new Complex();
        result.setReal(c1.getReal()+c2.getReal());
        result.setImag(c1.getImag()+c2.getImag());
        return result;
    }

    public Complex subtract(Complex c1, Complex c2)
    {
        Complex result = new Complex();
        result.setReal(c1.getReal()-c2.getReal());
        result.setImag(c1.getImag()-c2.getImag());
        return result;
    }
}
