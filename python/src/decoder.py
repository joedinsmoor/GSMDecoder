import string
import math
import smsutil
import re


message_header = '02 15 00 00 01 16 01 04 06' #2 proceeding bytes may be size of message
number_header = '7F 80'


def decoder(file):
    with open(file) as f:
        smsutil.decode(f)

def with_regex(file):
    ofile = 'out.csv'
    with open(file, 'rb') as f:
       # lines = list(f)
        for line in f:
            if message_header in line:
                ofile.append(line)
            elif number_header in line:
               ofile.append(line)