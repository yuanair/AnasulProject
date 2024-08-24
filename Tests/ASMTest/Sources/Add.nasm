

SECTION .data
    msg   db "Hello World!", 0AH

SECTION .text
global  _add, _sub, _mul, _div

_add:
    lea     eax, [rcx+rdx]
    ret
_sub:
    mov   [rsp+10h], edx
	mov   [rsp+8h], ecx
	push  rdi
	mov   eax, [rsp+10h]
	mov   ecx, [rsp+18h]
	sub   eax, ecx
	pop   rdi
    ret
_mul:
    mov     eax, edx
    imul    eax, ecx
    ret
_div:
    mov   [rsp+10h], edx
	mov   [rsp+8h], ecx
	push  rdi
	mov   eax, [rsp+10h]
	mov   ecx, [rsp+18h]
	xor   edx, edx
	div   ecx
	pop   rdi
    ret

