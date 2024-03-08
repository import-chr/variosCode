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
# >>------  OBJETO  ------<<
# ===================================
algoritmo = CifradoCesar()

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message = input("ingresa la frase a cifrar: ")
key = int(input("ingresa la llave de cifrado: "))

cesarArr = algoritmo.cifrar(message, key)
cesarStr = algoritmo.toStr(cesarArr)

print(f"cesar (cifrado): {cesarStr}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
cesarText = input("Ingrese la frase a descifrar: ")
key = int(input("Ingrese la llave de descifrado: "))

messageArr = algoritmo.descifrar(cesarText, key)
messageStr = algoritmo.toStr(messageArr)

print(f"cesar (descifrado): {messageStr}")