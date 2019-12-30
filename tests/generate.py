#!/usr/bin/env python

import random
import string

MAX_VALUE_LEN = 16

worsd = ["lollollollololol", "kekekekekekekeke", "allmidallmidomgm", "fastpushfastpush", "whatswrongwithyu", "anothertestworld"]

def generate_random_value():
    return "".join( [ random.choice( worsd ) for _ in range( 1, 2 ) ] )

def main():

    for i in range(10):
        figure = generate_random_value()
    count_text = 10000000
    count_pattern = random.randint(1, 5)
    dec7 = 10000000000000000
    for i in range(count_pattern):
        perform = generate_random_value()
        print(perform, end = ' ')
    print(' ')
        
    for i in range(count_text):
        perform = generate_random_value()
        print(perform, end = ' ')
    
if __name__ == "__main__":
    main()
