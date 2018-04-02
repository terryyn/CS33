	.file	"cread_alt.c"
	.text
	.globl	cread
	.type	cread, @function
cread:
.LFB0:
	.cfi_startproc
	movq	$0, -8(%rsp)
	leaq	-8(%rsp), %rax
	testq	%rdi, %rdi
	cmove	%rax, %rdi
	movq	(%rdi), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	cread, .-cread
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
