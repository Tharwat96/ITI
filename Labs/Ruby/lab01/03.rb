#!/usr/bin/env ruby

puts "Enter a number to test:"
n = gets.to_i

if n < 21
    p (21-n).abs
else
    p (21-n).abs*2
end