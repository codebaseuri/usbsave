
%macro ISR_noerr_cd l
    global isr%l
    isr%l:
    push 0
    push l
    jmp isr_common_Code
%endmacro

%macro ISR_err_cd l
    global isr%l
    isr%l:
    push l
    jmp isr_common_Code
%endmacro


ISR_noerr_cd 0
ISR_noerr_cd 1
ISR_noerr_cd 2
ISR_noerr_cd 3
ISR_noerr_cd 4
ISR_noerr_cd 5
ISR_noerr_cd 6
ISR_noerr_cd 7


ISR_err_cd 8
ISR_err_cd 9
ISR_err_cd 10
ISR_err_cd 11
ISR_err_cd 12
ISR_err_cd 13
ISR_err_cd 14

ISR_noerr_cd 15
ISR_noerr_cd 16
ISR_noerr_cd 17
ISR_noerr_cd 18
ISR_noerr_cd 19
ISR_noerr_cd 20
ISR_noerr_cd 21
ISR_noerr_cd 22
ISR_noerr_cd 23
ISR_noerr_cd 24
ISR_noerr_cd 25
ISR_noerr_cd 26
ISR_noerr_cd 27
ISR_noerr_cd 28
ISR_noerr_cd 29

ISR_noerr_cd 30
ISR_noerr_cd 31


ISR_noerr_cd 128 ; for syscalls
ISR_noerr_cd 177 ;for syscalls 


[extern isr_handler]
isr_common_Code:

pusha

mov eax, ds
push eax 
mov ax , 0x10

mov ds , ax 
mov es, ax 
mov fs, ax 
mov gs,ax 


push esp ; save stack pointer because c functions gonna use it now 
call isr_handler

pop eax
pop eax

mov ds , ax 
mov es, ax 
mov fs, ax 
mov gs,ax 

popa
add esp , 8 

iret 
