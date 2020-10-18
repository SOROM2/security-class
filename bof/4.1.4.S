.global your_asm_fn
.section .text

your_asm_fn:
push	%ebp
mov	%esp,%ebp
push $coolfood
push $closed
push $0xacce55ed
call practice
leave

.section .data

coolfood:
    .string "coolfood\0"
closed:
    .int 0xc105ed
