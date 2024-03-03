def mcdEuclides(a, b):
    if a == 0:
        return b
    
    if b == 0:
        return a
    
    res = a % b
    a, b = b, res
    return mcdEuclides(a, b)

print(mcdEuclides(270, 192))