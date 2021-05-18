
[GLOBAL gdt_flush]

gdt_flush:
	
	mov eax , [esp+4] ; GDT pointer passed as arg  
	lgdt [eax] ; Load The GDT pointer Into Special register GDTR
	
	; Data Segment at : offset 0x10 
	mov ax  , 0x10
	; Setting up all the data Segments 
	mov ds , ax 
	mov fs , ax 
	mov es , ax 
	mov gs , ax 
	mov ss , ax 
	
	; Setting up the CS to 0x08 (Kernel Code Segment at offset 0x08) by doing a far JMP 
	jmp 0x08:.flsh 
	
.flsh:
	ret


[GLOBAL idt_flush]
idt_flush :
	
	mov eax , [esp+4] ; IDT poinnter 
	lidt [eax] ; Load IDT pointer Into Special register IDTR
	ret 
