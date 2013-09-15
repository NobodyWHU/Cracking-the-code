#-*- encoding:utf-8 -*-
__author__ = 'Nobody'

str = raw_input()
#使用列表魔术方法
str = str[::-1]

#使用列表内置方法
str1 = list(str)
str1.reverse()
origin = "".join(str1)

print str
print origin
