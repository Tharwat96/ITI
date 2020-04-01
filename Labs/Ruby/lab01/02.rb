#!/usr/bin/env ruby

puts "Enter 2 numbers to add them:"
a = gets.to_i
b = gets.to_i

def sum_or_double(a, b)
    (a != b) ? a+b : a*2*2
end

p sum_or_double(a, b)