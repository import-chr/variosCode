alphabet = "abcdefghijklmnopqrstuvwxyz"
alphabet_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
alpha = len(alphabet)

def getIdM(m, i = 0):
    return alphabet.find(m[i])

def toStr(arr, a, alpha):
    arrC = []

    for i in range(len(arr)):
        arrC.append(a[arr[i] % alpha])
    
    cad = "".join(arrC)

    return cad

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message = input("ingresa la frase a cifrar: ")
key = int(input("ingresa la llave de cifrado: "))

def cesar(m, k, a):
    aN = []

    for i in range(len(m)):
        aN.append(getIdM(m, i) + (k % a))

    return aN


cesarArr = cesar(message, key, alpha)
cesarStr = toStr(cesarArr, alphabet, alpha)

print(f"cesar (cifrado): {cesarStr}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
cesarText = input("Ingrese la frase a descifrar: ")
key = int(input("Ingrese la llave de descifrado: "))

def message(m, k, a):
  arrN = []

  for i in range(len(m)):
    arrN.append(getIdM(m, i) - (k % a))
  
  return arrN

messageArr = message(cesarText, key, alpha)
messageStr = toStr(messageArr, alphabet, alpha)

print(f"cesar (descifrado): {messageStr}")