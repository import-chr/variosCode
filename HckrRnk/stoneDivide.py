#!/bin/python3

import math
import os
import random
import re
import sys
from functools import cache

#
# Complete the 'stoneDivision' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. LONG_INTEGER n
#  2. LONG_INTEGER_ARRAY s
#

def stoneDivision(n, s):
    @cache
    def val(x):
        divs = [i for i in s if x % i == 0 and i != x]
        return max(1 + val(i) * x // i for i in divs) if divs else 0
    return val(n)
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        s = list(map(int, input().rstrip().split()))

        result = stoneDivision(n, s)

        fptr.write(str(result) + '\n')

    fptr.close()