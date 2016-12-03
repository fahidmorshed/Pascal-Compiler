section .data

section .bss

x resd 1
y resd 1
f resd 1
c resd 1
temp1 resd 1
buffer resb 1
temp resb 10


section .text

global _start

_start:
mov eax,17986984
mov dword[x],eax
mov eax,18028392
mov dword[y],eax
mov eax,dword[x]
mov ebx,dword[y]
cmp eax,ebx
jge label1

mov ecx,eax
push ebx

label2:

pop ebx
push ebx
mov ecx,dword[x]
cmp ecx,ebx
jge label3

mov eax,dword[x]
mov dword[c],eax
mov eax,dword[x]
add eax,17997336
mov dword[temp1],eax
mov eax,dword[temp1]
mov dword[x],eax
jmp label2

label3:
pop ebx

label1:


mov eax,1
mov ebx,0
int 80h
mov ecx,0

printFunc:

mov dx,0
mov bx,10
div bx
add dl,30h
mov [temp+ecx],dl
inc ecx
cmp ax,0
jne printFunc

print:
dec ecx
mov al,[temp+ecx]
mov byte[buffer],al

pusha
mov eax,4
mov ebx,1
mov ecx,buffer
mov edx,1
int 80h

popa

cmp ecx,0
jne print

mov byte[buffer],10

mov eax,4
mov ebx,1
mov ecx,buffer
mov edx,1
int 80h

ret