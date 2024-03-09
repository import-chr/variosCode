alphabet = "abcdefghijklmnopqrstuvwxyz"
alpha = len(alphabet)
print(alpha)

def getIdM(m, i = 0):
    return alphabet.find(m[i])

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
    arrKey = []
    arrMess = []
    arrCipher = []
    j = 0

    for i in range(len(key)):
        arrKey.append(getIdM(key[i]))

    for i in range(len(message)):
        arrMess.append(getIdM(message[i]))

    for i in range(len(arrMess)):
        arrSum = arrMess[i] + arrKey[j]

        j += 1

        if j >= (len(arrKey)):
            j = 0

        arrCipher.append(arrSum % alpha)
    print(arrCipher)
    return arrCipher

arreglo = cifrar(message, key)
arregloStr = toStr(arreglo, alphabet, alpha)

print(arregloStr)