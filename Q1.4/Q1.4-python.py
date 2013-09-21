#-*- encoding=utf-8 -*-
__author__ = 'Nobody'

str1 = raw_input("请输入第一个字符串")
str2 = raw_input("请输入第一个字符串")
if(str1 is None or str2 is None):
    print "不是变位词"
if(len(str1) != len(str2)):
    print "不是变位词"

str1 = list(str1)
str2 = list(str2)
str1.sort()
str2.sort()
str1 = "".join(str1)
str2 = "".join(str2)


#网上借鉴的一行搞定法  lambda
#str1 = "".join((lambda x:(x.sort(),x)[1])(list(str1)))
#str2 = "".join((lambda x:(x.sort(),x)[1])(list(str1)))

if(str1 == str2):
    print "是变位词"
else:
    print "不是变位词"

