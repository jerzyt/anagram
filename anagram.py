from collections import defaultdict

f = open('words')
words = f.readlines()
f.close()

anaDict = defaultdict(list)

for word in words:
	word = word.rstrip()
	l = list(word)
	l.sort()
	key = ''.join(l)
	anaDict[key].append(word)

for key, val in anaDict.items():
    if len(val) > 3:
		   print(key + ' => ' + ', '.join(val))
