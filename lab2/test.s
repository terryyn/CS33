	.file	"testovf.c"
	.text
	.p2align 4,,15
	.globl	testovf
	.type	testovf, @function
testovf:
.LFB0:
	.cfi_startproc
	movl	$1, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	testovf, .-testovf
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
