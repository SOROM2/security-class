.global _main
.section .text

_main:

push	%ebp
mov	%esp,%ebp

# array of 2 pointers, [0] = $shell, [1] = NULL
subl $0x08,%esp
movl $shell,%edi
movl %edi,-0x08(%ebp)
movl $0x00,-0x04(%ebp)
movl $11,%eax

# execve("/bin/sh",NULL)
movl $shell,%ebx
leal -0x08(%ebp),%ecx
movl $0x00,%edx
int $0x80

leave
ret

.section .data

shell:
    .string "/bin/sh"


