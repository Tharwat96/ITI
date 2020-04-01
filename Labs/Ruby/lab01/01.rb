#!/usr/bin/env ruby
puts "Enter a number to test:"
a = gets.to_i
def test_bounds(a)
    (a.between?(10,100) or a.eql? 200) ? true : false
end
p test_bounds(a)