#!/usr/bin/env ruby

wordHash = Hash.new()

File.new("words").each do |word|
	word.chomp!
	key = word.split(//).sort.join('')
	wordHash[key] = Array.new unless(wordHash.has_key?(key))
	wordHash[key] << word
end

wordHash.sort.each {|k,v| puts "#{k}\t=>\t#{v.join(', ')}" if(v.size > 3) }
