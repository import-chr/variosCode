.model small
.stack
.data
    msg db 10,13,7, 'ingrese el primer nombre: ','$'
    msg1 db 10,13,7, 'ingrese el segundo nombre: ','$'
    msg2 db 10,13,7, 'ingrese el tercer nombre: ','$'
    msg3 db 10,13,7, 'son iguales$'
    msg4 db 10,13,7, 'son diferentes$'
    
    cadena db 100 dup(' '), '$'
    cadena1 db 100 dup(' '), '$'
    cadena2 db 100 dup(' '), '$'
    
.code

    main proc
    
        mov ax,@data
        mov ds,ax
        mov es,ax
        
        mov ah,09h
        mov dx,offset[msg]
        int 21h
        
        mov ah,3fh
        mov bx,00h
        mov cx,100
        mov dx,offset[cadena]
        int 21h
        
        mov ah,09h
        mov dx,offset[msg1]
        int 21h
        
        mov ah,3fh
        mov bx,00h
        mov cx,100
        mov dx,offset[cadena1]
        int 21h
        
         mov ah,09h
         mov dx,offset[msg2]
        int 21h
        
        mov ah,3fh
        mov bx,00h
        mov cx,100
        mov dx,offset[cadena2]
        int 21h
        
        lea si,cadena
        lea si,cadena1
        lea si,cadena2
        
        repe cmpsb
        
        je igual
        jne diferente
        
        igual:
        mov ah,09h
        lea dx,msg3
        int 21h
        jmp salida
        
        diferente:
        mov ah,09h
        lea dx,msg4
        int 21h
        jmp salida
        
        salida:
        mov ah,4ch
        int 21h
        
        ret 
        .exit
        main endp
        endp
        end main