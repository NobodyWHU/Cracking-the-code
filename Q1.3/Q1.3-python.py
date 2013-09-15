#-*- encoding:utf-8 -*-
__author__ = 'Nobody'

str = raw_input()
len = len(str)
str = list(str)
for i in range(0, len):
    j = i+1
    for k in range(j, len):
        if(str[i] == str[k]):
            str[k] = "\0"

print "".join(str)

