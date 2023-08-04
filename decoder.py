import string
import math
import smsutil

def decoder(file):
    with open(file) as f:
        lines = list(f)
    for line in lines:
        print(smsutil.decode(line, encoding ='latin-1'))
