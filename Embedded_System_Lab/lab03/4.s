        AREA RESET, DATA, READONLY
        EXPORT __Vectors
__Vectors
        DCD 0x10001000
        DCD Reset_Handler
        ALIGN

        AREA mycode, CODE, READONLY
        ENTRY
        EXPORT Reset_Handler

Reset_Handler
        ; Load numbers into R0 and R1
        LDR R0, =a              ; a = 12
        LDR R0, [R0]
        LDR R1, =b              ; b = 18
        LDR R1, [R1]

        MOV R2, #1              ; i = 1

LOOP
        MUL R3, R0, R2          ; R3 = i * a
        UDIV R4, R3, R1         ; R4 = (i * a) / b
        MLS R5, R4, R1, R3      ; R5 = R3 - R4 * R1 => R5 = remainder

        CMP R5, #0              ; if remainder == 0
        BEQ FOUND_LCM

        ADD R2, R2, #1          ; i++
        B LOOP

FOUND_LCM
        MUL R5, R2, R0          ; R5 = i * a (LCM)
        LDR R6, =LCM
        STR R5, [R6]            ; Store result in memory

STOP
        B STOP

        AREA mydata, DATA, READWRITE
a       DCD 12
b       DCD 18
LCM     DCD 0

        END
