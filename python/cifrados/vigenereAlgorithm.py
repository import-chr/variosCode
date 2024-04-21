alphabet = "abcdefghijklmnopqrstuvwxyz"
alpha = len(alphabet)

def getIdM(m, i = 0):
    return alphabet.find(m[i])

def fillArray(text):
    arr = []

    for i in range(len(text)):
        arr.append(getIdM(text[i]))
    
    return arr

def toStr(arr, abc, alpha):
    arrStr = []

    for i in range(len(arr)):
        arrStr.append(abc[arr[i] % alpha])
    
    return "".join(arrStr)

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message = input("ingresa la frase a cifrar: ")
key = input("ingresa la llave de cifrado: ")

def cifrar(message, key):
    arrKey = fillArray(key)
    arrMess = fillArray(message)
    arrCipher = []
    j = 0

    for i in range(len(arrMess)):
        arrCipher.append((arrMess[i] + arrKey[j]) % alpha)
        j += 1

        if j >= (len(arrKey)):
            j = 0

    return arrCipher

cipheredArr = cifrar(message, key)
cipheredStr = toStr(cipheredArr, alphabet, alpha)

print(cipheredStr)

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
vigereneText = input("ingresa la frase a descifrar: ")
desKey = input("ingresa la llave de descifrado: ")

def descifrar(message, key):
    arrKey = fillArray(key)
    arrMess = fillArray(message)
    arrDescipher = []
    j = 0

    for i in range(len(arrMess)):
        arrDescipher.append((arrMess[i] - arrKey[j]) % alpha)
        j += 1

        if j >= (len(arrKey)):
            j = 0

    return arrDescipher

descipherArr = descifrar(vigereneText, desKey)
descipherStr = toStr(descipherArr, alphabet, alpha)

print(descipherStr)
