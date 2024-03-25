class CifradoCesar:
    def __init__(self) -> None:
      self.alphabet: str = "abcdefghijklmnopqrstuvwxyz"
      self.alpha: int = len(self.alphabet)
      
    def getIdM(self, m: str, i: int = 0) -> int:
        return self.alphabet.find(m[i])
    
    def toStr(self, arr: list[int]) -> str:
        arrC: list[str] = []

        for i in range(len(arr)):
            arrC.append(self.alphabet[arr[i] % self.alpha])
        
        return "".join(arrC)
    
    def spaceStr(self, original: str, joined: str) -> str:
        joined_spaces: list[str] = []
        joined_i: int = 0

        for char in original:
            if char == " ":
                joined_spaces.append(" ")
            else:
                joined_spaces.append(joined[joined_i])
                joined_i += 1
        
        return "".join(joined_spaces)
    
    def cifrar(self, m: str, k: int) -> list[int]:
        aN: list[int] = []

        for i in range(len(m)):
           aN.append(self.getIdM(m, i) + (k % self.alpha))

        return aN
    
    def descifrar(self, m: str, k: int) -> list[int]:
        aN: list[int] = []

        for i in range(len(m)):
           aN.append(self.getIdM(m, i) - (k % self.alpha))
        
        return aN

# ===================================
# >>------  INSTANCIA  ------<<
# ===================================
cesar: CifradoCesar = CifradoCesar()

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message: str = input("ingresa la frase a cifrar: ")
keyCipher: int = int(input("ingresa la llave de cifrado: "))

cesarArr: list[int] = cesar.cifrar(message.replace(" ", ""), keyCipher)
cesarStr: str = cesar.toStr(cesarArr)
cesarF: str = cesar.spaceStr(message, cesarStr)

print(f"cesar (cifrado): {cesarF}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
cesarText: str = input("Ingrese la frase a descifrar: ")
keyDecipher: int = int(input("Ingrese la llave de descifrado: "))

messageArr: list[int] = cesar.descifrar(cesarText.replace(" ", ""), keyDecipher)
messageStr: str = cesar.toStr(messageArr)
messageF: str = cesar.spaceStr(cesarText, messageStr)

print(f"cesar (descifrado): {messageF}")
