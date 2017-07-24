	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-12(%rbp), %rax
	movl	$0, -4(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -8(%rbp)
	movq	%rax, -24(%rbp)
	movl	-12(%rbp), %edx
	movq	%rax, %rsi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.1(%rip), %rdi
	leaq	-24(%rbp), %rsi
	movq	-24(%rbp), %rdx
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	leaq	_main.var2(%rip), %rdx
	movq	%rdx, %rsi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__const
_main.var2:                             ## @main.var2
	.ascii	"\001\002\003\004\005"

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"id=var1, addr=%p, val=%d\n"

L_.str.1:                               ## @.str.1
	.asciz	"id=c, addr=%p, val=%p\n"

L_.str.2:                               ## @.str.2
	.asciz	"id=var2, addr=%p, val=%p\n, val=%p"


.subsections_via_symbols
