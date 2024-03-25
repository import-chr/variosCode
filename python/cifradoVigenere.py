class CifradoVigenere:
    def __init__(self) -> None:
        self.alphabet: str = "abcdefghijklmnopqrstuvwxyz"
        self.alpha: int = len(self.alphabet)
    
    def getIdM(self, m: str, i: int = 0) -> int:
        return self.alphabet.find(m[i])
    
    def fillArr(self, text: str) -> list[int]:
        arr: list[int] = []

        for i in range(len(text)):
            arr.append(self.getIdM(text[i]))
        
        return arr
    
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
    
    def cifrar(self, message: str, key: str) -> list[int]:
        arrMess: list[int] = self.fillArr(message)
        arrKey: list[int] = self.fillArr(key)
        arrCipher: list[int] = []
        j: int = 0

        for i in range(len(arrMess)):
            arrCipher.append((arrMess[i] + arrKey[j]) % self.alpha)
            j += 1

            if j >= len(arrKey):
                j = 0
        
        return arrCipher
    
    def descifrar(self, message: str, key: str) -> list[int]:
        arrMess: list[int] = self.fillArr(message)
        arrKey: list[int] = self.fillArr(key)
        arrDescipher: list[int] = []
        j: int = 0

        for i in range(len(arrMess)):
            arrDescipher.append((arrMess[i] - arrKey[j]) % self.alpha)
            j += 1

            if j >= len(arrKey):
                j = 0
        
        return arrDescipher

# ===================================
# >>------  INSTANCIA  ------<<
# ===================================
vigenere: CifradoVigenere = CifradoVigenere()

# ===================================
# >>------  CIFRADO  ------<<
# ===================================
message: str = input("ingresa la frase a cifrar: ")
key: str = input("ingresa la llave de cifrado: ")

cipheredArr: list[int] = vigenere.cifrar(message.replace(" ", ""), key)
cipheredStr: str = vigenere.toStr(cipheredArr)
ciphered: str = vigenere.spaceStr(message, cipheredStr)

print(f"vigenere (cifrado): {ciphered}")

# ===================================
# >>------  DESCIFRADO  ------<<
# ===================================
vigereneText: str = input("ingresa la frase a descifrar: ")
desKey: str = input("ingresa la llave de descifrado: ")

descipherArr: list[int] = vigenere.descifrar(vigereneText.replace(" ", ""), desKey)
descipherStr: str = vigenere.toStr(descipherArr)
descipher: str = vigenere.spaceStr(vigereneText, descipherStr)

print(f"vegenere (descifrado): {descipher}")
