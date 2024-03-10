class CifradoCesar:
    def __init__(self) -> None:
      self.alphabet = "abcdefghijklmnopqrstuvwxyz"
      self.alpha = len(self.alphabet)
      
    def getIdM(self, m, i = 0):
        return self.alphabet.find(m[i])
    
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
    
    def cifrar(self, m, k):
        aN = []

        for i in range(len(m)):
           aN.append(self.getIdM(m, i) + (k % self.alpha))

        return aN
    
    def descifrar(self, m, k):
        aN = []

        for i in range(len(m)):
           aN.append(self.getIdM(m, i) - (k % self.alpha))
        
        return aN

# ===================================
# >>------  INSTANCIA  ------<<
# ===================================
cesar = CifradoCesar()

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message = input("ingresa la frase a cifrar: ")
key = int(input("ingresa la llave de cifrado: "))

cesarArr = cesar.cifrar(message.replace(" ", ""), key)
cesarStr = cesar.toStr(cesarArr)
cesarF = cesar.spaceStr(message, cesarStr)

print(f"cesar (cifrado): {cesarF}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
cesarText = input("Ingrese la frase a descifrar: ")
key = int(input("Ingrese la llave de descifrado: "))

messageArr = cesar.descifrar(cesarText.replace(" ", ""), key)
messageStr = cesar.toStr(messageArr)
messageF = cesar.spaceStr(cesarText, messageStr)

print(f"cesar (descifrado): {messageF}")
