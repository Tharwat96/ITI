#!/usr/bin/env ruby

def test_num(n, outsideMode)
    if outsideMode
        (n <= 1 || n >= 10) ? true : false
    else
        (n.between?(1,10)) ? true : false
    end
end

puts "Enter a number to test:"
a = gets.to_i
outsideMode = false
puts test_num(a, outsideMode)