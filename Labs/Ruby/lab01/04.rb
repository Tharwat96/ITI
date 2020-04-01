#!/usr/bin/env ruby

puts "Enter two numbers to test:"
a = gets.to_i.abs
b = gets.to_i.abs

def test_six(n1, n2)
    if n1 == 6 || n2 == 6 || n1+n2 ==6 || n1-n2 == 6 || n2-n1 == 6
        true
    else
        false
    end
end

puts test_six(a,b)