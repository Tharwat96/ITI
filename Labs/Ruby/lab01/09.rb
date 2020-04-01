#!/usr/bin/env ruby

puts "Enter a string to check: "
str = gets
if str.size > 2
    puts str[0,2]
else
    puts str
end