import string
import math
import smsutil
import re


message_header = '02 15 00 00 01 16 01 04 06' #2 proceeding bytes may be size of message
number_header = '7F 80'


def decoder(file):
    with open(file) as f:
        lines = list(f)
    for line in lines:
        print(smsutil.decode(line))

def with_regex(file):
    ofile = 'out.csv'
    with open(file) as f:
        try:
            lines = f.readlines()
        except UnicodeDecodeError:
            print("I'm not working")
            pass
        finally:
            try:
                for line in lines:
                    if line.contains(message_header):
                        ofile.append(line)
                    elif line.contains(number_header):
                        ofile.append(line)
            except UnboundLocalError:
                print("I'm really not working")
                pass