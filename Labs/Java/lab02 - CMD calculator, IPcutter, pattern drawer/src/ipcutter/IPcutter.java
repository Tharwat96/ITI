/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ipcutter;

/**
 *
 * @author Tharwat
 */
public class IPcutter {

    public static String[] cut(String input)
    {
        String[] strArr = input.split("\\.");
        return strArr;
    }

    public static void main(String[] args) 
    {
        String strArr[] = IPcutter.cut(args[0]);
        for(String value:strArr)
        {
            System.out.println(value);
        }



    }

}
