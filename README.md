assembly-language-one-
======================
;**************************************************
   STACK SEGMENT PARA STACK 'STACK'
         DB 64 DUP('STACK...')
     STACK ENDS
;**************************************************
   DSEG SEGMENT PARA 'DATA'
        MESS1 DB 50 DUP(' '),'Now the music is <<Butterfly lovers>> ',13,10,'$'
        MESS2 DB 50 DUP(' '),'Now the music is <<The storys>>',13,10,'$'
        MESS3 DB 50 DUP(' '),'Now the music is <<California Dreaming>>            ',13,10,'$'
    	MENU      DB 5 DUP(13,10)
  DB 5 DUP(' '),'  Desigener :    CaoYukai               ',13,10
  DB 5 DUP(' '),'  Class :        control 12-1           ',13,10
  DB 5 DUP(' '),'  Student ID:    28                     ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'         Music   Demanding              ',13,10
  DB 5 DUP(' '),' ************************************   ',13,10
  DB 5 DUP(' '),' **  1:Butterfly lovers;           **   ',13,10
  DB 5 DUP(' '),' **  2:The storys;                 **   ',13,10
  DB 5 DUP(' '),' **  3:California Dreaming;        **   ',13,10
  DB 5 DUP(' '),' **  4:Exit;                       **   ',13,10
  DB 5 DUP(' '),' **                                **   ',13,10
  DB 5 DUP(' '),' ************************************   ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'                                        ',13,10
  DB 5 DUP(' '),'please chioce the number of music:','$  ',13,10
  change DB 125 DUP(' '),'error!  please change anther NO.: ','$'
  MUS_FREG    dw 262,262,294,262,349,330
                dw 262,262,294,262,392,349
                dw 262,262,523,440,349,330,294
                dw 466,466,440,262,392,349
                dw -1
    MUS_TIME  dw 50,50,100,100,100,200
                dw 50,50,100,100,100,200
                dw 50,50,100,100,100,100,300
                dw 50,50,100,100,100,200
    mus_freg1   dw 330,294,262,294,330,330,330
                dw 294,294,294,330,392,392
                dw 330,294,262,294,330,330,330,330
                dw 294,294,330,294,262
                dw  -1
    mus_time1  dw 6 dup(25),50
               dw 2 dup(25,25,50)
               dw 12 dup(25),100
    mus_freg2  dw 330,392,330,294,330,392,330,294,330
               dw 330,392,330,294,262,294,330,292,294
               dw 262,262,220,196,196,220,262,294,330,262
               dw  -1
    mus_time2  dw 50,50,50,25,25,50,25,25,100
               dw 50,50,50,50,25,25,25,25,100
               dw 50,50,50,25,25,25,25,25,25,25,100
   DSEG ENDS
;**************************************************
   CODE SEGMENT PARA 'DATA'
      assume cs:code,ds:dseg,ss:stack
   music proc far
      mov ax,dseg
  mov ds,ax
  rotate:
call clearscreen
LEA DX,MENU
     mov ah, 9
     int 21h
chg:
     mov ah,1
     int 21h
     cmp al,'1'
     je  one
     cmp al,'2'
     je  two
     cmp al,'3'
     je  three
    cmp al,'4'
    je  endmus
   LEA DX,change
     mov ah, 9
     int 21h
     jmp chg
   ONE: call clearscreen
       lea dx,mess1
       mov ah,09
       int 21h
       LEA SI,MUS_FREG
       LEA BP,DS:MUS_TIME
       JMP SOUND
   TWO:call clearscreen
        lea dx,mess2
        mov ah,09
        int 21h
        LEA SI,MUS_FREG1
        LEA BP,DS:MUS_TIME1
        JMP SOUND
THREE:call clearscreen
        lea dx,mess3
        mov ah,09
        int 21h
        LEA SI,MUS_FREG2
        LEA BP,DS:MUS_TIME2
     SOUND:
      ; call q0
freq:
      mov di,[si]
      cmp di,-1
      je  rotate
      mov bx,ds:[bp]
      call soundf
      add si,2
      add bp,2
      jmp freq
      JMP rotate
ENDMUS:
      mov ax,4c00h
      int 21h
      music endp
;***************************************************
soundf  proc near
        push    ax
        push    bx
        push    cx
        push    dx
        push    di
        mov     al,0b6h
        out     43h,al
        mov     dx,12h
        mov     ax,348ch
        div     di
        out     42h,al
        mov     al,ah
        out     42h,al
        in      al,61h
        mov     ah,al
        or      al,3
        out     61h,al
wait1:
        mov     cx,663
        call    waitf
delay:
        loop    delay
        dec     bx
        jnz     wait1
        mov     al,ah
        out     61h,al
        pop     di
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
soundf  endp

CLEARSCREEN PROC NEAR
       MOV  AH,6
       MOV  AL,0
       MOV  DL,79
       MOV  BH,7
       MOV  CH,0
       MOV  CL,0
       MOV  DH,24
       int  10h
       MOV  DX,0
       MOV  AH,2
       INT  10H
       RET
CLEARSCREEN ENDP
q0 proc near
       mov ah,2
       sub bh,bh
       mov dh,0
       mov dl,0
       int 10h
       ret
q0 endp
waitf  proc near
      push    ax
waitf1: in      al,61h
       and     al, 10h
       cmp    al, ah
       je      waitf1
       mov    ah,al
       loop    waitf1
       pop     ax        
	ret
waitf   endp
;***************************************************
  code ends
  end music

The collage curriculum design
