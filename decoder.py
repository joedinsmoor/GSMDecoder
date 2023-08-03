import string
import math
import smsutil

def decode(file):
    file.open()
    wordDict = smsutil.split(file)
    decodeDict = ''
    i = 0
    for word in wordDict:
        smsutil.decode(word)