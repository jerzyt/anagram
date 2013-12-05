#	1.	Import the dictionary file
startTime <- proc.time()['elapsed']
dic <- read.csv('words', header=FALSE)
endTime <- proc.time()['elapsed']
elapsed <- endTime - startTime 
startTime <- endTime
print(elapsed)

#	2.	Create a column with sorted letters
key <- function(str) {
	paste(sort(unlist(strsplit(str, ''))), collapse='')
}

keys <- apply(dic, 1, key)
endTime <- proc.time()['elapsed']
elapsed <- endTime - startTime 
startTime <- endTime
print(elapsed)

#	3.	Combine dic with keys
dic <- cbind(dic, keys)
names(dic) <- c('word', 'key')
endTime <- proc.time()['elapsed']
elapsed <- endTime - startTime 
startTime <- endTime
print(elapsed)

#	4.	Find keys with > 3 occurences
counts <- as.data.frame(table(dic$key))
anagramKeys <- subset(counts, select=(Var1), subset=(Freq > 3))
endTime <- proc.time()['elapsed']
elapsed <- endTime - startTime 
startTime <- endTime
print(elapsed)

#	5.	Print the anagrams
printAnagrams <- function(aKey) {
	anagrams <- paste(subset(dic, subset=(aKey == key))[,1], collapse=', ')
	print(paste(aKey, ' => ', anagrams))
}

apply(anagramKeys, 1, printAnagrams)
endTime <- proc.time()['elapsed']
elapsed <- endTime - startTime 
startTime <- endTime
print(elapsed)
