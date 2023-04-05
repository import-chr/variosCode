.MODEL SMALL,C
.STACK
.DATA
    N1 DB 0                 
    N2 DB 0                 
    N3 DB 0                 
    N4 DB 0
    M1 DB 10,13,' Primer numero  : $'    
    M2 DB 10,13,' Segundo numero : $'    
    M3 DB 10,13,' Suma           : $'   
    M4 DB 10,13,' Resta          : $'    
    M5 DB 10,13,' Multiplicacion : $'    
    M6 DB 10,13,' Division       : $'    
    M7 DB 10,13,' Residuo        : $'     
    S DB 3 DUP('   '),'$'
    B DB 100,10,1
.CODE
.STARTUP

    MOV AX, @DATA           
    MOV DS, AX              
        
    MOV AH, 9               
    LEA DX, M1              
    INT 21H                 
    MOV AH, 1              
    INT 21H                 
    SUB AL, 30H             
    MOV BL, 10
    MUL BL
    MOV N1, AL              
    MOV AH, 1
    INT 21H
    SUB AL, 30H
    ADD N1,AL

    MOV AH, 9               
    LEA DX, M2
    INT 21H
    MOV AH, 1
    INT 21H
    SUB AL, 30H
    MUL BL
    MOV N2, AL
    MOV AH, 1
    INT 21H
    SUB AL, 30H
    ADD N2, AL
    
    ;SUMA
    MOV AL, N1              
    ADD AL, N2              
    MOV N3, AL              

    MOV AH, 9
    LEA DX, M3
    INT 21H

    MOV AX,0
    MOV AL, N3
    DIV B[0]
    MOV S[0], AL
    
    MOV BH, AH
    MOV AX, 0
    MOV AL, BH
    DIV B[1]
    MOV S[1],AL
    
    MOV S[2],AH
    
    ADD S[0],'0'
    ADD S[1],'0'
    ADD S[2],'0'
    
    LEA DX,S
    MOV AH,9
    INT 21H
    
    ;RESTA
    MOV AL, N1
    SUB AL, N2
    MOV N3, AL
    
    MOV AH, 9
    LEA DX, M4
    INT 21H

    MOV AX,0
    MOV AL, N3
    DIV B[0]
    MOV S[0],AL
    
    MOV BH,AH
    MOV AX,0
    MOV AL,BH
    DIV B[1]
    MOV S[1],AL
    
    MOV S[2],AH
    
    ADD S[0],'0'
    ADD S[1],'0'
    ADD S[2],'0'
    
    LEA DX,S
    MOV AH,9
    INT 21H
    
    ;MULTIPLICACION
    MOV AL, N1
    MOV BL, N2
    MUL BL
    ;ADD AL, 48
    MOV N3, AL
    
    MOV AH, 9
    LEA DX, M5
    INT 21H
    
    MOV AX,0
    MOV AL, N3
    DIV B[0]
    MOV S[0],AL
    
    MOV BH,AH
    MOV AX,0
    MOV AL,BH
    DIV B[1]
    MOV S[1],AL
    
    MOV S[2],AH
    
    ADD S[0],'0'
    ADD S[1],'0'
    ADD S[2],'0'
    
    LEA DX,S
    MOV AH,9
    INT 21H
    
    ;DIVISION
    MOV AX, 0000H
    MOV BX, 0000H
    MOV AL, N1
    MOV BL, N2
    DIV BL
    ADD AL, 30H
    MOV N3, AL
    MOV N4, AH
    
    MOV AH, 9
    LEA DX, M6
    INT 21H
    MOV AH, 2               
    MOV DL, N3              
    INT 21H
    
    MOV AH, 9
    LEA DX, M7
    INT 21H
    MOV AH, 2               
    MOV DL, N4              
    ADD DL, 30H
    INT 21H

    MOV AH, 4cH             
    INT 21H
END