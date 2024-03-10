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
    
    def spaceStr(self, original, joined):
        joined_spaces = []
        joined_i = 0

        for char in original:
            if char == " ":
                joined_spaces.append(" ")
            else:
                joined_spaces.append(joined[joined_i])
                joined_i += 1
        
        return "".join(joined_spaces)
    
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

cipheredArr = vigenere.cifrar(message.replace(" ", ""), key)
cipheredStr = vigenere.toStr(cipheredArr)
ciphered = vigenere.spaceStr(message, cipheredStr)

print(f"vigenere (cifrado): {ciphered}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
vigereneText = input("ingresa la frase a descifrar: ")
desKey = input("ingresa la llave de descifrado: ")

descipherArr = vigenere.descifrar(vigereneText.replace(" ", ""), desKey)
descipherStr = vigenere.toStr(descipherArr)
descipher = vigenere.spaceStr(vigereneText, descipherStr)

print(f"vegenere (descifrado): {descipher}")
