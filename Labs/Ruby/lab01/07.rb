#!/usr/bin/env ruby

puts "Enter 3 numbers to sum:"

numbers = []
for value in 0..2 do
    test = gets.to_i
    (test != 16) ? numbers<<test : break
end

puts numbers.sum
