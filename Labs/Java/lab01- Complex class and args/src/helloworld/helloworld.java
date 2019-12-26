/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;

/**
 *
 * @author Tharwat
 */
public class helloworld {
    public static void main(String[] args) 
    {
        System.out.println("Hello World");
        for(int i = 0; i<args.length; i++)
        {   
            System.out.println("args: " + args[i]);
        }
    }
    
}
