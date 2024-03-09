class CifradoVigenere:
    def __init__(self) -> None:
        self.alphabet = "abcdefghijklmnopqrstuvwxyz"
        self.alpha = len(self.alphabet)
    
    def getIdM(self, m, i = 0):
        return self.alphabet.find(m[i])
    
    def fillArr(self, text):
        arr = []

        for i in range(len(text)):
            arr.append(self.getIdM(text[i]))
        
        return arr
    
    def toStr(self, arr):
        arrC = []

        for i in range(len(arr)):
            arrC.append(self.alphabet[arr[i] % self.alpha])
        
        return "".join(arrC)
    
    def cifrar(self, message, key):
        arrMess = self.fillArr(message)
        arrKey = self.fillArr(key)
        arrCipher = []
        j = 0

        for i in range(len(arrMess)):
            arrCipher.append((arrMess[i] + arrKey[j]) % self.alpha)
            j += 1

            if j >= len(arrKey):
                j = 0
        
        return arrCipher
    
    def descifrar(self, message, key):
        arrMess = self.fillArr(message)
        arrKey = self.fillArr(key)
        arrDescipher = []
        j = 0

        for i in range(len(arrMess)):
            arrDescipher.append((arrMess[i] - arrKey[j]) % self.alpha)
            j += 1

            if j >= len(arrKey):
                j = 0
        
        return arrDescipher

# ===================================
# >>------  INSTANCIA  ------<<
# ===================================
vigenere = CifradoVigenere()

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message = input("ingresa la frase a cifrar: ")
key = input("ingresa la llave de cifrado: ")

cipheredArr = vigenere.cifrar(message, key)
cipheredStr = vigenere.toStr(cipheredArr)

print(f"vigenere (cifrado): {cipheredStr}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
vigereneText = input("ingresa la frase a descifrar: ")
desKey = input("ingresa la llave de descifrado: ")

descipherArr = vigenere.descifrar(vigereneText, desKey)
descipherStr = vigenere.toStr(descipherArr)

print(f"vegenere (descifrado): {descipherStr}")