require "json"

module Talkable
  def contacts(email, phone)
    return "#{email} | #{phone}"
  end
end

class Person
  attr_accessor :name

  def initialize(name)
    (valid_name? name) ? @name = name : puts("Invalid name format, please write alphabetics only")
  end

  def valid_name?(name)
    name.match(/^[[:alpha:][:blank:]]+$/)
  end
end


class User < Person
  extend Talkable
  @filename = "users.txt"
  @email_phone = ""
  attr_accessor :email, :phone

  def initialize(name, email, phone)
    super(name)
    @email = email
    @phone = phone
  end

  def create
    index, users = User.get_json_and_index("users.json")
    users[index] = {
        :name => name,
        :email => email,
        :phone => phone
    }
    User.write_hash_to_pretty_json_file(users, "users.json")
    #File.open('users.txt', mode) do |f2|
    #  f2.puts "#{name} ** #{email} | #{phone}"
    #end
    return self
  end

  def self.list(n = 0)
    i = 0
    _, users = User.get_json_and_index("users.json")
    case n
    when 0
      users.each do
        puts "#{users[i.to_s]['name']} ** " + contacts(users[i.to_s]["email"], users[i.to_s]["phone"])
        i += 1
      end
    when n
      users.each do
        puts "#{users[i.to_s]['name']} ** " + contacts(users[i.to_s]["email"], users[i.to_s]["phone"])
        i += 1
        if i == n
          return
        end
      end
    end
  end

  def self.write_hash_to_pretty_json_file(hash, filename)
    File.open(filename, "w") do |f|
      f.write(JSON.pretty_generate(hash))
    end
  end

  def self.parse_json(filename)
    JSON(File.read(filename))
  end

  def self.get_json_and_index(filename)
    index = 0
    if File.file? filename
      users = parse_json(filename)
      index = users.size
    else
      users = {}
    end
    return index, users
  end

  # no longer used but kept for future reference
  def read_file_old(n)
    l = 0
    f = File.open("users.txt", "r")
    f.each_line do |line|
      puts line.reverse.match("^[^\*]*").to_s.chop.reverse
      l += 1
      break if l == n
    end
    f.close
    return ""
  end
end
