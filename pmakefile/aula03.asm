	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_printVersion
	.p2align	4, 0x90
_printVersion:                          ## @printVersion
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
	subq	$16, %rsp
	leaq	L_.str(%rip), %rax
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movzbl	(%rdi), %esi
	movq	-8(%rbp), %rdi
	movzbl	1(%rdi), %edx
	movq	-8(%rbp), %rdi
	movzwl	2(%rdi), %ecx
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	-8(%rbp), %rdi
	movl	$0, -4(%rbp)
	movl	L_main.v(%rip), %eax
	movl	%eax, -8(%rbp)
	callq	_printVersion
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Version %d.%d.%d\n"

	.section	__TEXT,__literal4,4byte_literals
	.p2align	1               ## @main.v
L_main.v:
	.byte	1                       ## 0x1
	.byte	0                       ## 0x0
	.short	8                       ## 0x8


.subsections_via_symbols
