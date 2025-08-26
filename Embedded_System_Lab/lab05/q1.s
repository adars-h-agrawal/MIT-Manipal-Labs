	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC     ; Base address of input list
    LDR R1, =DST   ; Base address of result list
    MOV R2, #10        ; Total number of elements (increased to 10)
copy_loop
    LDR R3, [R0], #4  
    STR R3, [R1], #4  
    SUBS R2,#1   
    BNE copy_loop
 
    LDR R0, =DST  ; Reset result list base address
    MOV R2, #10       ; Reset total elements count
outer_loop
    SUB R3, R2, #1    
    CMP R3, #0        
    BLE STOP
    MOV R4, R0        
    MOV R5, R0        
    ADD R6, R4, #4    
    MOV R7, R3        
inner_loop
    LDR R8, [R6]      
    LDR R9, [R5]      
    CMP R8, R9        
    BGE skip_min      
    MOV R5, R6        
skip_min
    ADD R6,#4    
    SUBS R7,#1   
    BNE inner_loop    
    LDR R8, [R5]      
    LDR R9, [R4]      
    STR R8, [R4]      
    STR R9, [R5]      
    ADD R0,#4    
    SUBS R2,#1   
    BNE outer_loop
STOP B STOP      
SRC DCD 0x64, 0x32, 0x14, 0x50, 0x23, 0x11, 0x45, 0x78, 0x90, 0x05 
	AREA data_section, DATA, READWRITE
DST DCD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  ; Space for 10 sorted numbers
    END