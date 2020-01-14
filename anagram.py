# -*- coding: utf-8 -*-
"""
Created on Sun Jan 12 09:11:59 2020

@author: JerzyT
"""

f = open('words')
words = f.readlines()
f.close()

anaDict = {}

for word in words:
    word = word.rstrip()
    l = list(word)
    l.sort()
    key = ''.join(l)
    if key in anaDict.keys():
        anaDict[key].append(word)
    else:
        anaDict[key] = [word]

for key in anaDict.keys():
    val = anaDict[key]
    if(len(val) > 3):
        print(key + ' => ' + ', '.join(val))

