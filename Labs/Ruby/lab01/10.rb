#!/usr/bin/env ruby
str1 = ""
str2 = ""
puts "Enter two strings that have more than 2 characters each to chop and chomp :D"
str1 = gets[1..].chomp while str1.size < 2
str2 = gets[1..].chomp while str2.size < 2

puts str1 + str2