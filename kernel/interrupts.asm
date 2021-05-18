[BITS 32]

 ; ISR and IRQs saving processor state , before context switching 
%macro ISR_NOERR 1 ; Macro TAKING 1 parameter (Interrupt Number) . 
 GLOBAL isr%1 ; Defining All  ISRs That Doesnt have a Default error code . 
 isr%1:
	cli ; Disabling interrupts .
	push byte 0 ; push dummy error code .
	push byte %1 ; push the interrupt number .
	
	; Since the isr stub is common to both interrupts that have and dont have error code 
	; instead of putting the code here we just have to jmp to it from both macros .  
	jmp isr_stub      
%endmacro 


%macro ISR_ERR 1 ; Macro TAKING 1 parameter (Interrupt Number) . 
 GLOBAL isr%1 ; Defining All  ISRs That have a Default error code . 
 isr%1:
        cli ; Disabling interrupts .
        
        push byte %1 ; push the interrupt number .

        ; Since the isr stub is common to both interrupts that have and dont have error code 
        ; instead of putting the code here we just have to jmp to it from both macros .  
        jmp isr_stub      
%endmacro

%macro IRQ 2 
 GLOBAL irq%1
 irq%1:
	cli  ; disable interrupts 
	push byte 0 ; dummy Value 
	push byte %2 ; number of interrupt
	jmp irq_stub
%endmacro

ISR_NOERR 0
ISR_NOERR 1
ISR_NOERR 2
ISR_NOERR 3 
ISR_NOERR 4
ISR_NOERR 5
ISR_NOERR 6
ISR_NOERR 7
ISR_ERR   8
ISR_NOERR 9
ISR_ERR   10
ISR_ERR   11
ISR_ERR   12
ISR_ERR   13
ISR_ERR   14
ISR_NOERR 15
ISR_NOERR 16
ISR_NOERR 17
ISR_NOERR 18
ISR_NOERR 19
ISR_NOERR 20
ISR_NOERR 21
ISR_NOERR 22
ISR_NOERR 23
ISR_NOERR 24
ISR_NOERR 25
ISR_NOERR 26
ISR_NOERR 27
ISR_NOERR 28
ISR_NOERR 29
ISR_NOERR 30
ISR_NOERR 31


[extern isr_handler] 
[GLOBAL isr_stub]
isr_stub: 
; Common Code for Handling the interrupt , Saving the processor state before Jumping To the code that will handle the interrupt
	
	pusha ; pushing edi , esi , ebp , esp , ebx , edx , ecx  , eax  into the stack 
	mov ax , ds ; Save the data segment descripor into the stack 
	push eax 
	
	; Suppose that our processor is executing Some User mode code When the interrupt fires , 
	;First we need to load The kernel data segment descriptor   
	mov ax, 0x10  
	mov ds, ax 
	mov es, ax
   	mov fs, ax
  	mov gs, ax 

	call isr_handler ; Handling the interrupt

	; Restoring all Values and return executing Code before interrupts fires . 
	pop eax ; top of the stack after return contains now old ds Value .
	mov ds, ax 
	mov es, ax
   	mov fs, ax
   	mov gs, ax
	
	popa ; Pops edi , esi , ebp , esp , ebx , edx , ecx , eax From the stack 
	
	; All ISRs will do a JMP Before entering the isr_stub , So we need to reset 
	;the stack to before the call to ISRs  , ( we pushed error code and interrupt Number ) 
	; even if we push just a byte the stack pointer will move by (32 bits ) that s where 8 comes from 
	; 8 bytes   
	add esp , 8
	;sti ; Enabling interrupts again (Setting Interrupt Flag to 1 ) iret will restore the EFLAGS no this is useless !!
	
	iret ; Cool instruction to restore ESP , CS , EIP , EFLAGS , SS before the interrupt trigerred



[extern irq_handler] 
[GLOBAL irq_stub]
irq_stub: 
; Common Code for Handling the interrupt , Saving the processor state before Jumping To the code that will handle the interrupt
	
	pusha ; pushing edi , esi , ebp , esp , ebx , edx , ecx  , eax  into the stack 
	mov ax , ds ; Save the data segment descripor into the stack 
	push eax 
	
	; Suppose that our processor is executing Some User mode code When the interrupt fires , 
	;First we need to load The kernel data segment descriptor   
	mov ax, 0x10  
	mov ds, ax 
	mov es, ax
   	mov fs, ax
  	mov gs, ax 

	call irq_handler ; Handling the interrupt

	; Restoring all Values and return executing Code before interrupts fires . 
	pop eax ; top of the stack after return contains now old ds Value .
	mov ds, ax 
	mov es, ax
   	mov fs, ax
   	mov gs, ax
	
	popa ; Pops edi , esi , ebp , esp , ebx , edx , ecx , eax From the stack 
	
	; All ISRs will do a JMP Before entering the isr_stub , So we need to reset 
	;the stack to before the call to ISRs  , ( we pushed error code and interrupt Number ) 
	; even if we push just a byte the stack pointer will move by (32 bits ) that s where 8 comes from 
	; 8 bytes   
	add esp , 8
	;sti ; Enabling interrupts again (Setting Interrupt Flag to 1 ) iret will restore the EFLAGS no this is useless !!
	
	iret ; Cool instruction to restore ESP , CS , EIP , EFLAGS , SS before the interrupt trigerred


%macro send_command_to_PIC 2 ; First param port , Second  param : value 
	mov dx , %1
	mov al , %2 
	out dx ,al 
%endmacro


[GLOBAL remap_irq]
remap_irq:
	; there is two 8259 PIC chip , Slave and master chips ,the Slave chip is mapped to port 2 on the Master PIC
	; the Master PIC is directly connected to the CPU interrupt pin 
	; remapping should be done for both PIC chips
	; Master chip :
		; Command port : 0x20 
		; data port : 0x21 
	; Slave chip :
		;Command port : 0xA0 
		; data port : 0xA1
   

	
	; Initialisation the 2 chips
	send_command_to_PIC 0x20 ,0x11 
	send_command_to_PIC 0xA0 ,0x11 

	; Sending the New offsets

	send_command_to_PIC 0x21 ,0x20 ; = 32
	send_command_to_PIC 0xA1 ,0x28

	; Notify Master PIC that there is a slave at at IRQ2 
	
	send_command_to_PIC 0x21 ,0x4

	; Tell Slave cascade identity = 2 
	send_command_to_PIC 0xA1 ,0x2

	;  enabling all interrupts by setting the mask to 0x00  , and sending some Default data the chip expects 

	send_command_to_PIC 0x21 ,0x1
	send_command_to_PIC 0xA1 ,0x1
	send_command_to_PIC 0x21 ,0x00
    send_command_to_PIC 0xA1 ,0x00
	
	ret



IRQ 0, 32
IRQ 1, 33  
IRQ 2, 34  
IRQ 3, 35  
IRQ 4, 36  
IRQ 5, 37  
IRQ 6, 38  
IRQ 7, 39 
IRQ 8, 40  
IRQ 9, 41  
IRQ 10, 42  
IRQ 11, 43  
IRQ 12, 44  
IRQ 13, 45  
IRQ 14, 46
IRQ 15, 47


[GLOBAL EOI] 
EOI:       ; End of interrupt 
	mov eax , [esp + 4] ; port 
	send_command_to_PIC 0x20 , al 
	ret 
