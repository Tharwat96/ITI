#!/usr/bin/env ruby
str1 = ""
str2 = ""
puts "Enter two strings that have more than 2 characters each to chop and chomp :D"
str1 = gets[1..].chomp.chop while str1.size < 4
str2 = gets[1..].chomp.chop while str2.size < 4

puts str1 + str2