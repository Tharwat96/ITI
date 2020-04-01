#!/usr/bin/env ruby

puts "Enter 3 numbers to sum if not duplicated:"
# n1 = gets.to_i
# n2 = gets.to_i
# n3 = gets.to_i

# numbers = [n1,n2,n3]
# test = 0
numbers = []
for value in 0..2 do
    test = gets.to_i
    unless numbers.include?test
        numbers.push(test)
    end
end

puts numbers.sum


