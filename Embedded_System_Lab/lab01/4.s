	AREA RESET ,DATA ,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0,#1 ;
	ADD R0,#3 ;
	ADD R0,#5 ;
	ADD R0,#7 ;
	ADD R0,#9 ;
STOP B STOP
	END