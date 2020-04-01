#!/usr/bin/ruby -w
require_relative 'classes.rb'
require 'getoptlong'


if ARGV.length < 1
  puts "Missing argument (try --help)"
  exit 0
end
name = email = phone = ""

opts = GetoptLong.new(
    ['--help', '-h', GetoptLong::OPTIONAL_ARGUMENT],
    ['--list', '-l', GetoptLong::OPTIONAL_ARGUMENT],
    ['--name', '-n', GetoptLong::REQUIRED_ARGUMENT],
    ['--email', '-e', GetoptLong::REQUIRED_ARGUMENT],
    ['--phone', '-p', GetoptLong::REQUIRED_ARGUMENT]
)


opts.each do |opt, arg|
  case opt
  when '--help'
    puts <<-EOF
     main.rb [OPTIONS]

     -h, --help:
         show help

     --name x, -n x:
         adds x name to the user

     --email x, -e x:
         adds x email to the user

     --phone x, -p x:
         adds 012345 phone to the user
    
     --list [1..], -l [1..]
         lists all users if no arguments given or number of lines matching the argument
    EOF

  when '--name'
    if arg == ''
      error
    else
      name = arg
    end
  when '--email'
    if arg == ''
      error
    else
      email = arg
    end
  when '--phone'
    if arg == ''
      error
    else
      phone = arg

    end
  when '--list'
    if arg == ''
      User.list
    else
      User.list(arg.to_i)

    end
  end
end


def error
  puts "Missing argument (try --help)"
  exit 0
end

if name && email && phone != ""
  user1 = User.new(name, email, phone)
  user1.create
end

#p user1.name
#p user1.create
#p User.list(2)