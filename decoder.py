import string
import math
import smsutil

def decode_me(file):
    with open(file) as f:
        lines = list(f)
    for line in lines:
        print(smsutil.decode(line, encoding ='latin-1'))
