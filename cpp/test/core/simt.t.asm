
simd.t:     file format elf64-x86-64


Disassembly of section .init:

00000000004008d8 <_init>:
  4008d8:	48 83 ec 08          	sub    $0x8,%rsp
  4008dc:	48 8b 05 25 21 20 00 	mov    0x202125(%rip),%rax        # 602a08 <_DYNAMIC+0x250>
  4008e3:	48 85 c0             	test   %rax,%rax
  4008e6:	74 05                	je     4008ed <_init+0x15>
  4008e8:	e8 b3 00 00 00       	callq  4009a0 <__gmon_start__@plt>
  4008ed:	48 83 c4 08          	add    $0x8,%rsp
  4008f1:	c3                   	retq   

Disassembly of section .plt:

0000000000400900 <_Znam@plt-0x10>:
  400900:	ff 35 12 21 20 00    	pushq  0x202112(%rip)        # 602a18 <_GLOBAL_OFFSET_TABLE_+0x8>
  400906:	ff 25 14 21 20 00    	jmpq   *0x202114(%rip)        # 602a20 <_GLOBAL_OFFSET_TABLE_+0x10>
  40090c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400910 <_Znam@plt>:
  400910:	ff 25 12 21 20 00    	jmpq   *0x202112(%rip)        # 602a28 <_GLOBAL_OFFSET_TABLE_+0x18>
  400916:	68 00 00 00 00       	pushq  $0x0
  40091b:	e9 e0 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400920 <_ZNSt6chrono3_V212system_clock3nowEv@plt>:
  400920:	ff 25 0a 21 20 00    	jmpq   *0x20210a(%rip)        # 602a30 <_GLOBAL_OFFSET_TABLE_+0x20>
  400926:	68 01 00 00 00       	pushq  $0x1
  40092b:	e9 d0 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400930 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@plt>:
  400930:	ff 25 02 21 20 00    	jmpq   *0x202102(%rip)        # 602a38 <_GLOBAL_OFFSET_TABLE_+0x28>
  400936:	68 02 00 00 00       	pushq  $0x2
  40093b:	e9 c0 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400940 <__cxa_atexit@plt>:
  400940:	ff 25 fa 20 20 00    	jmpq   *0x2020fa(%rip)        # 602a40 <_GLOBAL_OFFSET_TABLE_+0x30>
  400946:	68 03 00 00 00       	pushq  $0x3
  40094b:	e9 b0 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
  400950:	ff 25 f2 20 20 00    	jmpq   *0x2020f2(%rip)        # 602a48 <_GLOBAL_OFFSET_TABLE_+0x38>
  400956:	68 04 00 00 00       	pushq  $0x4
  40095b:	e9 a0 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400960 <_ZNSolsEPFRSoS_E@plt>:
  400960:	ff 25 ea 20 20 00    	jmpq   *0x2020ea(%rip)        # 602a50 <_GLOBAL_OFFSET_TABLE_+0x40>
  400966:	68 05 00 00 00       	pushq  $0x5
  40096b:	e9 90 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400970 <_ZNSt8ios_base4InitC1Ev@plt>:
  400970:	ff 25 e2 20 20 00    	jmpq   *0x2020e2(%rip)        # 602a58 <_GLOBAL_OFFSET_TABLE_+0x48>
  400976:	68 06 00 00 00       	pushq  $0x6
  40097b:	e9 80 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400980 <_ZNSolsEi@plt>:
  400980:	ff 25 da 20 20 00    	jmpq   *0x2020da(%rip)        # 602a60 <_GLOBAL_OFFSET_TABLE_+0x50>
  400986:	68 07 00 00 00       	pushq  $0x7
  40098b:	e9 70 ff ff ff       	jmpq   400900 <_init+0x28>

0000000000400990 <__libc_start_main@plt>:
  400990:	ff 25 d2 20 20 00    	jmpq   *0x2020d2(%rip)        # 602a68 <_GLOBAL_OFFSET_TABLE_+0x58>
  400996:	68 08 00 00 00       	pushq  $0x8
  40099b:	e9 60 ff ff ff       	jmpq   400900 <_init+0x28>

00000000004009a0 <__gmon_start__@plt>:
  4009a0:	ff 25 ca 20 20 00    	jmpq   *0x2020ca(%rip)        # 602a70 <_GLOBAL_OFFSET_TABLE_+0x60>
  4009a6:	68 09 00 00 00       	pushq  $0x9
  4009ab:	e9 50 ff ff ff       	jmpq   400900 <_init+0x28>

00000000004009b0 <_ZNSolsEd@plt>:
  4009b0:	ff 25 c2 20 20 00    	jmpq   *0x2020c2(%rip)        # 602a78 <_GLOBAL_OFFSET_TABLE_+0x68>
  4009b6:	68 0a 00 00 00       	pushq  $0xa
  4009bb:	e9 40 ff ff ff       	jmpq   400900 <_init+0x28>

00000000004009c0 <_ZNSt8ios_base4InitD1Ev@plt>:
  4009c0:	ff 25 ba 20 20 00    	jmpq   *0x2020ba(%rip)        # 602a80 <_GLOBAL_OFFSET_TABLE_+0x70>
  4009c6:	68 0b 00 00 00       	pushq  $0xb
  4009cb:	e9 30 ff ff ff       	jmpq   400900 <_init+0x28>

Disassembly of section .text:

00000000004009d0 <_start>:
  4009d0:	31 ed                	xor    %ebp,%ebp
  4009d2:	49 89 d1             	mov    %rdx,%r9
  4009d5:	5e                   	pop    %rsi
  4009d6:	48 89 e2             	mov    %rsp,%rdx
  4009d9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4009dd:	50                   	push   %rax
  4009de:	54                   	push   %rsp
  4009df:	49 c7 c0 10 1e 40 00 	mov    $0x401e10,%r8
  4009e6:	48 c7 c1 a0 1d 40 00 	mov    $0x401da0,%rcx
  4009ed:	48 c7 c7 c6 0a 40 00 	mov    $0x400ac6,%rdi
  4009f4:	e8 97 ff ff ff       	callq  400990 <__libc_start_main@plt>
  4009f9:	f4                   	hlt    
  4009fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400a00 <deregister_tm_clones>:
  400a00:	b8 9f 2a 60 00       	mov    $0x602a9f,%eax
  400a05:	55                   	push   %rbp
  400a06:	48 2d 98 2a 60 00    	sub    $0x602a98,%rax
  400a0c:	48 83 f8 0e          	cmp    $0xe,%rax
  400a10:	48 89 e5             	mov    %rsp,%rbp
  400a13:	76 1b                	jbe    400a30 <deregister_tm_clones+0x30>
  400a15:	b8 00 00 00 00       	mov    $0x0,%eax
  400a1a:	48 85 c0             	test   %rax,%rax
  400a1d:	74 11                	je     400a30 <deregister_tm_clones+0x30>
  400a1f:	5d                   	pop    %rbp
  400a20:	bf 98 2a 60 00       	mov    $0x602a98,%edi
  400a25:	ff e0                	jmpq   *%rax
  400a27:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  400a2e:	00 00 
  400a30:	5d                   	pop    %rbp
  400a31:	c3                   	retq   
  400a32:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  400a39:	1f 84 00 00 00 00 00 

0000000000400a40 <register_tm_clones>:
  400a40:	be 98 2a 60 00       	mov    $0x602a98,%esi
  400a45:	55                   	push   %rbp
  400a46:	48 81 ee 98 2a 60 00 	sub    $0x602a98,%rsi
  400a4d:	48 c1 fe 03          	sar    $0x3,%rsi
  400a51:	48 89 e5             	mov    %rsp,%rbp
  400a54:	48 89 f0             	mov    %rsi,%rax
  400a57:	48 c1 e8 3f          	shr    $0x3f,%rax
  400a5b:	48 01 c6             	add    %rax,%rsi
  400a5e:	48 d1 fe             	sar    %rsi
  400a61:	74 15                	je     400a78 <register_tm_clones+0x38>
  400a63:	b8 00 00 00 00       	mov    $0x0,%eax
  400a68:	48 85 c0             	test   %rax,%rax
  400a6b:	74 0b                	je     400a78 <register_tm_clones+0x38>
  400a6d:	5d                   	pop    %rbp
  400a6e:	bf 98 2a 60 00       	mov    $0x602a98,%edi
  400a73:	ff e0                	jmpq   *%rax
  400a75:	0f 1f 00             	nopl   (%rax)
  400a78:	5d                   	pop    %rbp
  400a79:	c3                   	retq   
  400a7a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400a80 <__do_global_dtors_aux>:
  400a80:	80 3d 49 21 20 00 00 	cmpb   $0x0,0x202149(%rip)        # 602bd0 <completed.6661>
  400a87:	75 11                	jne    400a9a <__do_global_dtors_aux+0x1a>
  400a89:	55                   	push   %rbp
  400a8a:	48 89 e5             	mov    %rsp,%rbp
  400a8d:	e8 6e ff ff ff       	callq  400a00 <deregister_tm_clones>
  400a92:	5d                   	pop    %rbp
  400a93:	c6 05 36 21 20 00 01 	movb   $0x1,0x202136(%rip)        # 602bd0 <completed.6661>
  400a9a:	f3 c3                	repz retq 
  400a9c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400aa0 <frame_dummy>:
  400aa0:	bf b0 27 60 00       	mov    $0x6027b0,%edi
  400aa5:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400aa9:	75 05                	jne    400ab0 <frame_dummy+0x10>
  400aab:	eb 93                	jmp    400a40 <register_tm_clones>
  400aad:	0f 1f 00             	nopl   (%rax)
  400ab0:	b8 00 00 00 00       	mov    $0x0,%eax
  400ab5:	48 85 c0             	test   %rax,%rax
  400ab8:	74 f1                	je     400aab <frame_dummy+0xb>
  400aba:	55                   	push   %rbp
  400abb:	48 89 e5             	mov    %rsp,%rbp
  400abe:	ff d0                	callq  *%rax
  400ac0:	5d                   	pop    %rbp
  400ac1:	e9 7a ff ff ff       	jmpq   400a40 <register_tm_clones>

0000000000400ac6 <main>:
  400ac6:	55                   	push   %rbp
  400ac7:	48 89 e5             	mov    %rsp,%rbp
  400aca:	48 83 ec 60          	sub    $0x60,%rsp
  400ace:	89 7d ac             	mov    %edi,-0x54(%rbp)
  400ad1:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  400ad5:	e8 53 0d 00 00       	callq  40182d <_ZN6Engine9Processor6hasSSEEv>
  400ada:	84 c0                	test   %al,%al
  400adc:	74 1c                	je     400afa <main+0x34>
  400ade:	be 2b 1e 40 00       	mov    $0x401e2b,%esi
  400ae3:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400ae8:	e8 63 fe ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400aed:	be 30 09 40 00       	mov    $0x400930,%esi
  400af2:	48 89 c7             	mov    %rax,%rdi
  400af5:	e8 66 fe ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400afa:	e8 70 0d 00 00       	callq  40186f <_ZN6Engine9Processor7hasSSE2Ev>
  400aff:	84 c0                	test   %al,%al
  400b01:	74 1c                	je     400b1f <main+0x59>
  400b03:	be 32 1e 40 00       	mov    $0x401e32,%esi
  400b08:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400b0d:	e8 3e fe ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400b12:	be 30 09 40 00       	mov    $0x400930,%esi
  400b17:	48 89 c7             	mov    %rax,%rdi
  400b1a:	e8 41 fe ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400b1f:	e8 8d 0d 00 00       	callq  4018b1 <_ZN6Engine9Processor7hasSSE3Ev>
  400b24:	84 c0                	test   %al,%al
  400b26:	74 1c                	je     400b44 <main+0x7e>
  400b28:	be 3a 1e 40 00       	mov    $0x401e3a,%esi
  400b2d:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400b32:	e8 19 fe ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400b37:	be 30 09 40 00       	mov    $0x400930,%esi
  400b3c:	48 89 c7             	mov    %rax,%rdi
  400b3f:	e8 1c fe ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400b44:	e8 aa 0d 00 00       	callq  4018f3 <_ZN6Engine9Processor8hasSSE41Ev>
  400b49:	84 c0                	test   %al,%al
  400b4b:	74 1c                	je     400b69 <main+0xa3>
  400b4d:	be 42 1e 40 00       	mov    $0x401e42,%esi
  400b52:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400b57:	e8 f4 fd ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400b5c:	be 30 09 40 00       	mov    $0x400930,%esi
  400b61:	48 89 c7             	mov    %rax,%rdi
  400b64:	e8 f7 fd ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400b69:	e8 c7 0d 00 00       	callq  401935 <_ZN6Engine9Processor8hasSSE42Ev>
  400b6e:	84 c0                	test   %al,%al
  400b70:	74 1c                	je     400b8e <main+0xc8>
  400b72:	be 4b 1e 40 00       	mov    $0x401e4b,%esi
  400b77:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400b7c:	e8 cf fd ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400b81:	be 30 09 40 00       	mov    $0x400930,%esi
  400b86:	48 89 c7             	mov    %rax,%rdi
  400b89:	e8 d2 fd ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400b8e:	e8 e4 0d 00 00       	callq  401977 <_ZN6Engine9Processor8hasSSSE3Ev>
  400b93:	84 c0                	test   %al,%al
  400b95:	74 1c                	je     400bb3 <main+0xed>
  400b97:	be 54 1e 40 00       	mov    $0x401e54,%esi
  400b9c:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400ba1:	e8 aa fd ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400ba6:	be 30 09 40 00       	mov    $0x400930,%esi
  400bab:	48 89 c7             	mov    %rax,%rdi
  400bae:	e8 ad fd ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400bb3:	e8 01 0e 00 00       	callq  4019b9 <_ZN6Engine9Processor6hasAVXEv>
  400bb8:	84 c0                	test   %al,%al
  400bba:	74 1c                	je     400bd8 <main+0x112>
  400bbc:	be 5d 1e 40 00       	mov    $0x401e5d,%esi
  400bc1:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400bc6:	e8 85 fd ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400bcb:	be 30 09 40 00       	mov    $0x400930,%esi
  400bd0:	48 89 c7             	mov    %rax,%rdi
  400bd3:	e8 88 fd ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400bd8:	e8 1e 0e 00 00       	callq  4019fb <_ZN6Engine9Processor7hasAVX2Ev>
  400bdd:	84 c0                	test   %al,%al
  400bdf:	74 1c                	je     400bfd <main+0x137>
  400be1:	be 64 1e 40 00       	mov    $0x401e64,%esi
  400be6:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400beb:	e8 60 fd ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400bf0:	be 30 09 40 00       	mov    $0x400930,%esi
  400bf5:	48 89 c7             	mov    %rax,%rdi
  400bf8:	e8 63 fd ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400bfd:	be 30 09 40 00       	mov    $0x400930,%esi
  400c02:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400c07:	e8 54 fd ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400c0c:	e8 0f fd ff ff       	callq  400920 <_ZNSt6chrono3_V212system_clock3nowEv@plt>
  400c11:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
  400c15:	bf 90 00 00 00       	mov    $0x90,%edi
  400c1a:	e8 f1 fc ff ff       	callq  400910 <_Znam@plt>
  400c1f:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  400c23:	bf 90 00 00 00       	mov    $0x90,%edi
  400c28:	e8 e3 fc ff ff       	callq  400910 <_Znam@plt>
  400c2d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  400c31:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  400c38:	eb 36                	jmp    400c70 <main+0x1aa>
  400c3a:	8b 45 fc             	mov    -0x4(%rbp),%eax
  400c3d:	48 98                	cltq   
  400c3f:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  400c46:	00 
  400c47:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  400c4b:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
  400c4f:	8b 45 fc             	mov    -0x4(%rbp),%eax
  400c52:	48 98                	cltq   
  400c54:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  400c5b:	00 
  400c5c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400c60:	48 01 d0             	add    %rdx,%rax
  400c63:	8b 55 fc             	mov    -0x4(%rbp),%edx
  400c66:	89 10                	mov    %edx,(%rax)
  400c68:	8b 00                	mov    (%rax),%eax
  400c6a:	89 01                	mov    %eax,(%rcx)
  400c6c:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  400c70:	83 7d fc 23          	cmpl   $0x23,-0x4(%rbp)
  400c74:	7e c4                	jle    400c3a <main+0x174>
  400c76:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  400c7a:	48 8b 75 e8          	mov    -0x18(%rbp),%rsi
  400c7e:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  400c82:	b9 24 00 00 00       	mov    $0x24,%ecx
  400c87:	48 89 c7             	mov    %rax,%rdi
  400c8a:	e8 b0 05 00 00       	callq  40123f <_ZN6Engine4SIMD3mulIiEEvPKT_S4_PS2_m>
  400c8f:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  400c96:	eb 33                	jmp    400ccb <main+0x205>
  400c98:	8b 45 f8             	mov    -0x8(%rbp),%eax
  400c9b:	48 98                	cltq   
  400c9d:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  400ca4:	00 
  400ca5:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  400ca9:	48 01 d0             	add    %rdx,%rax
  400cac:	8b 00                	mov    (%rax),%eax
  400cae:	89 c6                	mov    %eax,%esi
  400cb0:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400cb5:	e8 c6 fc ff ff       	callq  400980 <_ZNSolsEi@plt>
  400cba:	be 6c 1e 40 00       	mov    $0x401e6c,%esi
  400cbf:	48 89 c7             	mov    %rax,%rdi
  400cc2:	e8 89 fc ff ff       	callq  400950 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400cc7:	83 45 f8 01          	addl   $0x1,-0x8(%rbp)
  400ccb:	83 7d f8 23          	cmpl   $0x23,-0x8(%rbp)
  400ccf:	7e c7                	jle    400c98 <main+0x1d2>
  400cd1:	e8 4a fc ff ff       	callq  400920 <_ZNSt6chrono3_V212system_clock3nowEv@plt>
  400cd6:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
  400cda:	48 8d 55 d0          	lea    -0x30(%rbp),%rdx
  400cde:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  400ce2:	48 89 d6             	mov    %rdx,%rsi
  400ce5:	48 89 c7             	mov    %rax,%rdi
  400ce8:	e8 18 04 00 00       	callq  401105 <_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE>
  400ced:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  400cf1:	48 8d 55 e0          	lea    -0x20(%rbp),%rdx
  400cf5:	48 8d 45 b0          	lea    -0x50(%rbp),%rax
  400cf9:	48 89 d6             	mov    %rdx,%rsi
  400cfc:	48 89 c7             	mov    %rax,%rdi
  400cff:	e8 fc 04 00 00       	callq  401200 <_ZNSt6chrono8durationIdSt5ratioILl1ELl1EEEC1IlS1_ILl1ELl1000000000EEvEERKNS0_IT_T0_EE>
  400d04:	48 8d 45 b0          	lea    -0x50(%rbp),%rax
  400d08:	48 89 c7             	mov    %rax,%rdi
  400d0b:	e8 d6 04 00 00       	callq  4011e6 <_ZNKSt6chrono8durationIdSt5ratioILl1ELl1EEE5countEv>
  400d10:	bf c0 2a 60 00       	mov    $0x602ac0,%edi
  400d15:	e8 96 fc ff ff       	callq  4009b0 <_ZNSolsEd@plt>
  400d1a:	be 30 09 40 00       	mov    $0x400930,%esi
  400d1f:	48 89 c7             	mov    %rax,%rdi
  400d22:	e8 39 fc ff ff       	callq  400960 <_ZNSolsEPFRSoS_E@plt>
  400d27:	b8 00 00 00 00       	mov    $0x0,%eax
  400d2c:	c9                   	leaveq 
  400d2d:	c3                   	retq   

0000000000400d2e <_Z41__static_initialization_and_destruction_0ii>:
  400d2e:	55                   	push   %rbp
  400d2f:	48 89 e5             	mov    %rsp,%rbp
  400d32:	48 83 ec 10          	sub    $0x10,%rsp
  400d36:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400d39:	89 75 f8             	mov    %esi,-0x8(%rbp)
  400d3c:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  400d40:	75 27                	jne    400d69 <_Z41__static_initialization_and_destruction_0ii+0x3b>
  400d42:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
  400d49:	75 1e                	jne    400d69 <_Z41__static_initialization_and_destruction_0ii+0x3b>
  400d4b:	bf d1 2b 60 00       	mov    $0x602bd1,%edi
  400d50:	e8 1b fc ff ff       	callq  400970 <_ZNSt8ios_base4InitC1Ev@plt>
  400d55:	ba 90 2a 60 00       	mov    $0x602a90,%edx
  400d5a:	be d1 2b 60 00       	mov    $0x602bd1,%esi
  400d5f:	bf c0 09 40 00       	mov    $0x4009c0,%edi
  400d64:	e8 d7 fb ff ff       	callq  400940 <__cxa_atexit@plt>
  400d69:	c9                   	leaveq 
  400d6a:	c3                   	retq   

0000000000400d6b <_GLOBAL__sub_I_main>:
  400d6b:	55                   	push   %rbp
  400d6c:	48 89 e5             	mov    %rsp,%rbp
  400d6f:	be ff ff 00 00       	mov    $0xffff,%esi
  400d74:	bf 01 00 00 00       	mov    $0x1,%edi
  400d79:	e8 b0 ff ff ff       	callq  400d2e <_Z41__static_initialization_and_destruction_0ii>
  400d7e:	5d                   	pop    %rbp
  400d7f:	c3                   	retq   

0000000000400d80 <_ZNSt6chrono8durationIlSt5ratioILl1ELl1000000000EEEC1IlvEERKT_>:
  400d80:	55                   	push   %rbp
  400d81:	48 89 e5             	mov    %rsp,%rbp
  400d84:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  400d88:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  400d8c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  400d90:	48 8b 10             	mov    (%rax),%rdx
  400d93:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400d97:	48 89 10             	mov    %rdx,(%rax)
  400d9a:	5d                   	pop    %rbp
  400d9b:	c3                   	retq   

0000000000400d9c <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv>:
  400d9c:	55                   	push   %rbp
  400d9d:	48 89 e5             	mov    %rsp,%rbp
  400da0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  400da4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400da8:	48 8b 00             	mov    (%rax),%rax
  400dab:	5d                   	pop    %rbp
  400dac:	c3                   	retq   
  400dad:	90                   	nop

0000000000400dae <_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv>:
  400dae:	55                   	push   %rbp
  400daf:	48 89 e5             	mov    %rsp,%rbp
  400db2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  400db6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400dba:	48 8b 00             	mov    (%rax),%rax
  400dbd:	5d                   	pop    %rbp
  400dbe:	c3                   	retq   

0000000000400dbf <_ZN6Engine4SIMD6canMulIiE4testENS0_4SizeE>:
  400dbf:	55                   	push   %rbp
  400dc0:	48 89 e5             	mov    %rsp,%rbp
  400dc3:	48 83 ec 10          	sub    $0x10,%rsp
  400dc7:	89 7d fc             	mov    %edi,-0x4(%rbp)
  400dca:	83 7d fc 20          	cmpl   $0x20,-0x4(%rbp)
  400dce:	75 07                	jne    400dd7 <_ZN6Engine4SIMD6canMulIiE4testENS0_4SizeE+0x18>
  400dd0:	e8 26 0c 00 00       	callq  4019fb <_ZN6Engine9Processor7hasAVX2Ev>
  400dd5:	eb 05                	jmp    400ddc <_ZN6Engine4SIMD6canMulIiE4testENS0_4SizeE+0x1d>
  400dd7:	e8 17 0b 00 00       	callq  4018f3 <_ZN6Engine9Processor8hasSSE41Ev>
  400ddc:	c9                   	leaveq 
  400ddd:	c3                   	retq   

0000000000400dde <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE32EE4loadEPKi>:
  400dde:	4c 8d 54 24 08       	lea    0x8(%rsp),%r10
  400de3:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
  400de7:	41 ff 72 f8          	pushq  -0x8(%r10)
  400deb:	55                   	push   %rbp
  400dec:	48 89 e5             	mov    %rsp,%rbp
  400def:	41 52                	push   %r10
  400df1:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  400df5:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  400df9:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  400dfd:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  400e01:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400e05:	c5 fe 6f 00          	vmovdqu (%rax),%ymm0
  400e09:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400e0d:	c5 fd 7f 00          	vmovdqa %ymm0,(%rax)
  400e11:	41 5a                	pop    %r10
  400e13:	5d                   	pop    %rbp
  400e14:	49 8d 62 f8          	lea    -0x8(%r10),%rsp
  400e18:	c3                   	retq   
  400e19:	90                   	nop

0000000000400e1a <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE32EE5storeEPi>:
  400e1a:	4c 8d 54 24 08       	lea    0x8(%rsp),%r10
  400e1f:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
  400e23:	41 ff 72 f8          	pushq  -0x8(%r10)
  400e27:	55                   	push   %rbp
  400e28:	48 89 e5             	mov    %rsp,%rbp
  400e2b:	41 52                	push   %r10
  400e2d:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  400e31:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
  400e35:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  400e39:	c5 fd 6f 00          	vmovdqa (%rax),%ymm0
  400e3d:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
  400e41:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  400e45:	c5 fd 7f 45 b0       	vmovdqa %ymm0,-0x50(%rbp)
  400e4a:	c5 fd 6f 45 b0       	vmovdqa -0x50(%rbp),%ymm0
  400e4f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400e53:	c5 fe 7f 00          	vmovdqu %ymm0,(%rax)
  400e57:	41 5a                	pop    %r10
  400e59:	5d                   	pop    %rbp
  400e5a:	49 8d 62 f8          	lea    -0x8(%r10),%rsp
  400e5e:	c3                   	retq   
  400e5f:	90                   	nop

0000000000400e60 <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE32EEmlES3_>:
  400e60:	55                   	push   %rbp
  400e61:	48 89 e5             	mov    %rsp,%rbp
  400e64:	48 81 ec d8 00 00 00 	sub    $0xd8,%rsp
  400e6b:	48 89 bd c8 fe ff ff 	mov    %rdi,-0x138(%rbp)
  400e72:	48 89 b5 c0 fe ff ff 	mov    %rsi,-0x140(%rbp)
  400e79:	c5 fd 6f 45 10       	vmovdqa 0x10(%rbp),%ymm0
  400e7e:	c5 fd 70 c0 d8       	vpshufd $0xd8,%ymm0,%ymm0
  400e83:	c5 fd 6f c8          	vmovdqa %ymm0,%ymm1
  400e87:	48 8b 85 c0 fe ff ff 	mov    -0x140(%rbp),%rax
  400e8e:	c5 fd 6f 00          	vmovdqa (%rax),%ymm0
  400e92:	c5 fd 70 c0 d8       	vpshufd $0xd8,%ymm0,%ymm0
  400e97:	c5 fd 7f 45 90       	vmovdqa %ymm0,-0x70(%rbp)
  400e9c:	c5 fd 7f 8d 70 ff ff 	vmovdqa %ymm1,-0x90(%rbp)
  400ea3:	ff 
  400ea4:	c5 fd 6f 8d 70 ff ff 	vmovdqa -0x90(%rbp),%ymm1
  400eab:	ff 
  400eac:	c5 fd 6f 45 90       	vmovdqa -0x70(%rbp),%ymm0
  400eb1:	c4 e2 7d 28 c1       	vpmuldq %ymm1,%ymm0,%ymm0
  400eb6:	c5 fd 7f 45 d0       	vmovdqa %ymm0,-0x30(%rbp)
  400ebb:	c5 fd 6f 45 10       	vmovdqa 0x10(%rbp),%ymm0
  400ec0:	c5 fd 70 c0 72       	vpshufd $0x72,%ymm0,%ymm0
  400ec5:	c5 fd 6f c8          	vmovdqa %ymm0,%ymm1
  400ec9:	48 8b 85 c0 fe ff ff 	mov    -0x140(%rbp),%rax
  400ed0:	c5 fd 6f 00          	vmovdqa (%rax),%ymm0
  400ed4:	c5 fd 70 c0 72       	vpshufd $0x72,%ymm0,%ymm0
  400ed9:	c5 fd 7f 85 50 ff ff 	vmovdqa %ymm0,-0xb0(%rbp)
  400ee0:	ff 
  400ee1:	c5 fd 7f 8d 30 ff ff 	vmovdqa %ymm1,-0xd0(%rbp)
  400ee8:	ff 
  400ee9:	c5 fd 6f 8d 30 ff ff 	vmovdqa -0xd0(%rbp),%ymm1
  400ef0:	ff 
  400ef1:	c5 fd 6f 85 50 ff ff 	vmovdqa -0xb0(%rbp),%ymm0
  400ef8:	ff 
  400ef9:	c4 e2 7d 28 c1       	vpmuldq %ymm1,%ymm0,%ymm0
  400efe:	c5 fd 7f 45 b0       	vmovdqa %ymm0,-0x50(%rbp)
  400f03:	c5 fd 6f 45 b0       	vmovdqa -0x50(%rbp),%ymm0
  400f08:	c5 fd 7f 85 10 ff ff 	vmovdqa %ymm0,-0xf0(%rbp)
  400f0f:	ff 
  400f10:	c5 fc 28 8d 10 ff ff 	vmovaps -0xf0(%rbp),%ymm1
  400f17:	ff 
  400f18:	c5 fd 6f 45 d0       	vmovdqa -0x30(%rbp),%ymm0
  400f1d:	c5 fd 7f 85 f0 fe ff 	vmovdqa %ymm0,-0x110(%rbp)
  400f24:	ff 
  400f25:	c5 fc 28 85 f0 fe ff 	vmovaps -0x110(%rbp),%ymm0
  400f2c:	ff 
  400f2d:	c5 fc c6 c1 88       	vshufps $0x88,%ymm1,%ymm0,%ymm0
  400f32:	c5 fc 29 85 d0 fe ff 	vmovaps %ymm0,-0x130(%rbp)
  400f39:	ff 
  400f3a:	c5 fd 6f 85 d0 fe ff 	vmovdqa -0x130(%rbp),%ymm0
  400f41:	ff 
  400f42:	48 8b 85 c8 fe ff ff 	mov    -0x138(%rbp),%rax
  400f49:	c5 fd 7f 00          	vmovdqa %ymm0,(%rax)
  400f4d:	48 8b 85 c8 fe ff ff 	mov    -0x138(%rbp),%rax
  400f54:	c9                   	leaveq 
  400f55:	c3                   	retq   

0000000000400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>:
  400f56:	55                   	push   %rbp
  400f57:	48 89 e5             	mov    %rsp,%rbp
  400f5a:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  400f5e:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  400f62:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  400f66:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400f6a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400f6e:	c5 fa 6f 00          	vmovdqu (%rax),%xmm0
  400f72:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  400f76:	c5 f8 29 00          	vmovaps %xmm0,(%rax)
  400f7a:	5d                   	pop    %rbp
  400f7b:	c3                   	retq   

0000000000400f7c <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE16EE5storeEPi>:
  400f7c:	55                   	push   %rbp
  400f7d:	48 89 e5             	mov    %rsp,%rbp
  400f80:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  400f84:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  400f88:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400f8c:	c5 f9 6f 00          	vmovdqa (%rax),%xmm0
  400f90:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  400f94:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  400f98:	c5 f8 29 45 e0       	vmovaps %xmm0,-0x20(%rbp)
  400f9d:	c5 f9 6f 45 e0       	vmovdqa -0x20(%rbp),%xmm0
  400fa2:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  400fa6:	c5 f8 11 00          	vmovups %xmm0,(%rax)
  400faa:	5d                   	pop    %rbp
  400fab:	c3                   	retq   

0000000000400fac <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE16EEmlES3_>:
  400fac:	55                   	push   %rbp
  400fad:	48 89 e5             	mov    %rsp,%rbp
  400fb0:	48 83 ec 48          	sub    $0x48,%rsp
  400fb4:	48 89 bd 68 ff ff ff 	mov    %rdi,-0x98(%rbp)
  400fbb:	48 89 f0             	mov    %rsi,%rax
  400fbe:	48 89 d1             	mov    %rdx,%rcx
  400fc1:	48 89 ca             	mov    %rcx,%rdx
  400fc4:	48 89 85 50 ff ff ff 	mov    %rax,-0xb0(%rbp)
  400fcb:	48 89 95 58 ff ff ff 	mov    %rdx,-0xa8(%rbp)
  400fd2:	c5 f9 6f 85 50 ff ff 	vmovdqa -0xb0(%rbp),%xmm0
  400fd9:	ff 
  400fda:	c5 f9 70 c0 d8       	vpshufd $0xd8,%xmm0,%xmm0
  400fdf:	c5 f9 6f c8          	vmovdqa %xmm0,%xmm1
  400fe3:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
  400fea:	c5 f9 6f 00          	vmovdqa (%rax),%xmm0
  400fee:	c5 f9 70 c0 d8       	vpshufd $0xd8,%xmm0,%xmm0
  400ff3:	c5 f8 29 45 d0       	vmovaps %xmm0,-0x30(%rbp)
  400ff8:	c5 f8 29 4d c0       	vmovaps %xmm1,-0x40(%rbp)
  400ffd:	c5 f9 6f 45 c0       	vmovdqa -0x40(%rbp),%xmm0
  401002:	c5 f9 6f 4d d0       	vmovdqa -0x30(%rbp),%xmm1
  401007:	c4 e2 71 28 c0       	vpmuldq %xmm0,%xmm1,%xmm0
  40100c:	c5 f8 29 45 f0       	vmovaps %xmm0,-0x10(%rbp)
  401011:	c5 f9 6f 85 50 ff ff 	vmovdqa -0xb0(%rbp),%xmm0
  401018:	ff 
  401019:	c5 f9 70 c0 72       	vpshufd $0x72,%xmm0,%xmm0
  40101e:	c5 f9 6f c8          	vmovdqa %xmm0,%xmm1
  401022:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
  401029:	c5 f9 6f 00          	vmovdqa (%rax),%xmm0
  40102d:	c5 f9 70 c0 72       	vpshufd $0x72,%xmm0,%xmm0
  401032:	c5 f8 29 45 b0       	vmovaps %xmm0,-0x50(%rbp)
  401037:	c5 f8 29 4d a0       	vmovaps %xmm1,-0x60(%rbp)
  40103c:	c5 f9 6f 45 a0       	vmovdqa -0x60(%rbp),%xmm0
  401041:	c5 f9 6f 4d b0       	vmovdqa -0x50(%rbp),%xmm1
  401046:	c4 e2 71 28 c0       	vpmuldq %xmm0,%xmm1,%xmm0
  40104b:	c5 f8 29 45 e0       	vmovaps %xmm0,-0x20(%rbp)
  401050:	c5 f9 6f 45 e0       	vmovdqa -0x20(%rbp),%xmm0
  401055:	c5 f8 29 45 90       	vmovaps %xmm0,-0x70(%rbp)
  40105a:	c5 f8 28 4d 90       	vmovaps -0x70(%rbp),%xmm1
  40105f:	c5 f9 6f 45 f0       	vmovdqa -0x10(%rbp),%xmm0
  401064:	c5 f8 29 45 80       	vmovaps %xmm0,-0x80(%rbp)
  401069:	c5 f8 28 45 80       	vmovaps -0x80(%rbp),%xmm0
  40106e:	c5 f8 c6 c1 88       	vshufps $0x88,%xmm1,%xmm0,%xmm0
  401073:	c5 f8 29 85 70 ff ff 	vmovaps %xmm0,-0x90(%rbp)
  40107a:	ff 
  40107b:	c5 f9 6f 85 70 ff ff 	vmovdqa -0x90(%rbp),%xmm0
  401082:	ff 
  401083:	c5 f8 29 85 40 ff ff 	vmovaps %xmm0,-0xc0(%rbp)
  40108a:	ff 
  40108b:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
  401092:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
  401099:	c9                   	leaveq 
  40109a:	c3                   	retq   

000000000040109b <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_>:
  40109b:	55                   	push   %rbp
  40109c:	48 89 e5             	mov    %rsp,%rbp
  40109f:	53                   	push   %rbx
  4010a0:	48 83 ec 48          	sub    $0x48,%rsp
  4010a4:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
  4010a8:	48 89 75 b0          	mov    %rsi,-0x50(%rbp)
  4010ac:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  4010b0:	48 8b 00             	mov    (%rax),%rax
  4010b3:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
  4010b7:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
  4010bb:	48 89 c7             	mov    %rax,%rdi
  4010be:	e8 d9 fc ff ff       	callq  400d9c <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv>
  4010c3:	48 89 c3             	mov    %rax,%rbx
  4010c6:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
  4010ca:	48 8b 00             	mov    (%rax),%rax
  4010cd:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  4010d1:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4010d5:	48 89 c7             	mov    %rax,%rdi
  4010d8:	e8 bf fc ff ff       	callq  400d9c <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv>
  4010dd:	48 29 c3             	sub    %rax,%rbx
  4010e0:	48 89 d8             	mov    %rbx,%rax
  4010e3:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
  4010e7:	48 8d 55 c8          	lea    -0x38(%rbp),%rdx
  4010eb:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  4010ef:	48 89 d6             	mov    %rdx,%rsi
  4010f2:	48 89 c7             	mov    %rax,%rdi
  4010f5:	e8 86 fc ff ff       	callq  400d80 <_ZNSt6chrono8durationIlSt5ratioILl1ELl1000000000EEEC1IlvEERKT_>
  4010fa:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  4010fe:	48 83 c4 48          	add    $0x48,%rsp
  401102:	5b                   	pop    %rbx
  401103:	5d                   	pop    %rbp
  401104:	c3                   	retq   

0000000000401105 <_ZNSt6chronomiINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIIT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE>:
  401105:	55                   	push   %rbp
  401106:	48 89 e5             	mov    %rsp,%rbp
  401109:	48 83 ec 30          	sub    $0x30,%rsp
  40110d:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
  401111:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
  401115:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  401119:	48 89 c7             	mov    %rax,%rdi
  40111c:	e8 8d fc ff ff       	callq  400dae <_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv>
  401121:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  401125:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401129:	48 89 c7             	mov    %rax,%rdi
  40112c:	e8 7d fc ff ff       	callq  400dae <_ZNKSt6chrono10time_pointINS_3_V212system_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv>
  401131:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  401135:	48 8d 55 e0          	lea    -0x20(%rbp),%rdx
  401139:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  40113d:	48 89 d6             	mov    %rdx,%rsi
  401140:	48 89 c7             	mov    %rax,%rdi
  401143:	e8 53 ff ff ff       	callq  40109b <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIINS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_>
  401148:	c9                   	leaveq 
  401149:	c3                   	retq   

000000000040114a <_ZNSt6chrono8durationIdSt5ratioILl1ELl1EEEC1IdvEERKT_>:
  40114a:	55                   	push   %rbp
  40114b:	48 89 e5             	mov    %rsp,%rbp
  40114e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401152:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401156:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40115a:	48 8b 00             	mov    (%rax),%rax
  40115d:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  401161:	48 89 02             	mov    %rax,(%rdx)
  401164:	5d                   	pop    %rbp
  401165:	c3                   	retq   

0000000000401166 <_ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILl1ELl1EEEES2_ILl1ELl1000000000EEdLb1ELb0EE6__castIlS5_EES4_RKNS1_IT_T0_EE>:
  401166:	55                   	push   %rbp
  401167:	48 89 e5             	mov    %rsp,%rbp
  40116a:	48 83 ec 20          	sub    $0x20,%rsp
  40116e:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401172:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401176:	48 89 c7             	mov    %rax,%rdi
  401179:	e8 1e fc ff ff       	callq  400d9c <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv>
  40117e:	c5 f9 57 c0          	vxorpd %xmm0,%xmm0,%xmm0
  401182:	c4 e1 fb 2a c0       	vcvtsi2sd %rax,%xmm0,%xmm0
  401187:	c5 fb 10 0d e9 0c 00 	vmovsd 0xce9(%rip),%xmm1        # 401e78 <_ZN9__gnu_cxxL21__default_lock_policyE+0x8>
  40118e:	00 
  40118f:	c5 fb 5e d1          	vdivsd %xmm1,%xmm0,%xmm2
  401193:	c4 e1 f9 7e d0       	vmovq  %xmm2,%rax
  401198:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  40119c:	48 8d 55 f8          	lea    -0x8(%rbp),%rdx
  4011a0:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  4011a4:	48 89 d6             	mov    %rdx,%rsi
  4011a7:	48 89 c7             	mov    %rax,%rdi
  4011aa:	e8 9b ff ff ff       	callq  40114a <_ZNSt6chrono8durationIdSt5ratioILl1ELl1EEEC1IdvEERKT_>
  4011af:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  4011b3:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  4011b7:	c5 fb 10 45 e0       	vmovsd -0x20(%rbp),%xmm0
  4011bc:	c9                   	leaveq 
  4011bd:	c3                   	retq   

00000000004011be <_ZNSt6chrono13duration_castINS_8durationIdSt5ratioILl1ELl1EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE>:
  4011be:	55                   	push   %rbp
  4011bf:	48 89 e5             	mov    %rsp,%rbp
  4011c2:	48 83 ec 10          	sub    $0x10,%rsp
  4011c6:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4011ca:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4011ce:	48 89 c7             	mov    %rax,%rdi
  4011d1:	e8 90 ff ff ff       	callq  401166 <_ZNSt6chrono20__duration_cast_implINS_8durationIdSt5ratioILl1ELl1EEEES2_ILl1ELl1000000000EEdLb1ELb0EE6__castIlS5_EES4_RKNS1_IT_T0_EE>
  4011d6:	c4 e1 f9 7e c0       	vmovq  %xmm0,%rax
  4011db:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  4011df:	c5 fb 10 45 f0       	vmovsd -0x10(%rbp),%xmm0
  4011e4:	c9                   	leaveq 
  4011e5:	c3                   	retq   

00000000004011e6 <_ZNKSt6chrono8durationIdSt5ratioILl1ELl1EEE5countEv>:
  4011e6:	55                   	push   %rbp
  4011e7:	48 89 e5             	mov    %rsp,%rbp
  4011ea:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4011ee:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4011f2:	48 8b 00             	mov    (%rax),%rax
  4011f5:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  4011f9:	c5 fb 10 45 f0       	vmovsd -0x10(%rbp),%xmm0
  4011fe:	5d                   	pop    %rbp
  4011ff:	c3                   	retq   

0000000000401200 <_ZNSt6chrono8durationIdSt5ratioILl1ELl1EEEC1IlS1_ILl1ELl1000000000EEvEERKNS0_IT_T0_EE>:
  401200:	55                   	push   %rbp
  401201:	48 89 e5             	mov    %rsp,%rbp
  401204:	48 83 ec 20          	sub    $0x20,%rsp
  401208:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  40120c:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  401210:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401214:	48 89 c7             	mov    %rax,%rdi
  401217:	e8 a2 ff ff ff       	callq  4011be <_ZNSt6chrono13duration_castINS_8durationIdSt5ratioILl1ELl1EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE>
  40121c:	c4 e1 f9 7e c0       	vmovq  %xmm0,%rax
  401221:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  401225:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  401229:	48 89 c7             	mov    %rax,%rdi
  40122c:	e8 b5 ff ff ff       	callq  4011e6 <_ZNKSt6chrono8durationIdSt5ratioILl1ELl1EEE5countEv>
  401231:	c4 e1 f9 7e c2       	vmovq  %xmm0,%rdx
  401236:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  40123a:	48 89 10             	mov    %rdx,(%rax)
  40123d:	c9                   	leaveq 
  40123e:	c3                   	retq   

000000000040123f <_ZN6Engine4SIMD3mulIiEEvPKT_S4_PS2_m>:
  40123f:	55                   	push   %rbp
  401240:	48 89 e5             	mov    %rsp,%rbp
  401243:	48 83 ec 20          	sub    $0x20,%rsp
  401247:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  40124b:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  40124f:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  401253:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  401257:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  40125b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  40125f:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  401263:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401267:	48 89 c7             	mov    %rax,%rdi
  40126a:	e8 02 00 00 00       	callq  401271 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m>
  40126f:	c9                   	leaveq 
  401270:	c3                   	retq   

0000000000401271 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m>:
  401271:	4c 8d 54 24 08       	lea    0x8(%rsp),%r10
  401276:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
  40127a:	41 ff 72 f8          	pushq  -0x8(%r10)
  40127e:	55                   	push   %rbp
  40127f:	48 89 e5             	mov    %rsp,%rbp
  401282:	41 52                	push   %r10
  401284:	53                   	push   %rbx
  401285:	48 81 ec 00 01 00 00 	sub    $0x100,%rsp
  40128c:	48 89 bd 08 ff ff ff 	mov    %rdi,-0xf8(%rbp)
  401293:	48 89 b5 00 ff ff ff 	mov    %rsi,-0x100(%rbp)
  40129a:	48 89 95 f8 fe ff ff 	mov    %rdx,-0x108(%rbp)
  4012a1:	48 89 8d f0 fe ff ff 	mov    %rcx,-0x110(%rbp)
  4012a8:	bf 20 00 00 00       	mov    $0x20,%edi
  4012ad:	e8 0d fb ff ff       	callq  400dbf <_ZN6Engine4SIMD6canMulIiE4testENS0_4SizeE>
  4012b2:	84 c0                	test   %al,%al
  4012b4:	74 07                	je     4012bd <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x4c>
  4012b6:	b8 20 00 00 00       	mov    $0x20,%eax
  4012bb:	eb 05                	jmp    4012c2 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x51>
  4012bd:	b8 10 00 00 00       	mov    $0x10,%eax
  4012c2:	48 c1 e8 02          	shr    $0x2,%rax
  4012c6:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  4012ca:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  4012d1:	ba 00 00 00 00       	mov    $0x0,%edx
  4012d6:	48 f7 75 e8          	divq   -0x18(%rbp)
  4012da:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
  4012de:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  4012e2:	48 0f af 45 e8       	imul   -0x18(%rbp),%rax
  4012e7:	48 8b 95 f0 fe ff ff 	mov    -0x110(%rbp),%rdx
  4012ee:	48 29 c2             	sub    %rax,%rdx
  4012f1:	48 89 d0             	mov    %rdx,%rax
  4012f4:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  4012f8:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
  4012ff:	bf 20 00 00 00       	mov    $0x20,%edi
  401304:	e8 b6 fa ff ff       	callq  400dbf <_ZN6Engine4SIMD6canMulIiE4testENS0_4SizeE>
  401309:	84 c0                	test   %al,%al
  40130b:	0f 84 0b 01 00 00    	je     40141c <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x1ab>
  401311:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
  401318:	e9 ab 00 00 00       	jmpq   4013c8 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x157>
  40131d:	8b 45 d8             	mov    -0x28(%rbp),%eax
  401320:	48 98                	cltq   
  401322:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401329:	00 
  40132a:	48 8b 85 08 ff ff ff 	mov    -0xf8(%rbp),%rax
  401331:	48 01 c2             	add    %rax,%rdx
  401334:	48 8d 85 10 ff ff ff 	lea    -0xf0(%rbp),%rax
  40133b:	48 89 d6             	mov    %rdx,%rsi
  40133e:	48 89 c7             	mov    %rax,%rdi
  401341:	e8 98 fa ff ff       	callq  400dde <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE32EE4loadEPKi>
  401346:	8b 45 d8             	mov    -0x28(%rbp),%eax
  401349:	48 98                	cltq   
  40134b:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401352:	00 
  401353:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  40135a:	48 01 c2             	add    %rax,%rdx
  40135d:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
  401364:	48 89 d6             	mov    %rdx,%rsi
  401367:	48 89 c7             	mov    %rax,%rdi
  40136a:	e8 6f fa ff ff       	callq  400dde <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE32EE4loadEPKi>
  40136f:	8b 45 d8             	mov    -0x28(%rbp),%eax
  401372:	48 98                	cltq   
  401374:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  40137b:	00 
  40137c:	48 8b 85 f8 fe ff ff 	mov    -0x108(%rbp),%rax
  401383:	48 8d 1c 02          	lea    (%rdx,%rax,1),%rbx
  401387:	48 8d 85 70 ff ff ff 	lea    -0x90(%rbp),%rax
  40138e:	48 8d 8d 30 ff ff ff 	lea    -0xd0(%rbp),%rcx
  401395:	48 8d 95 10 ff ff ff 	lea    -0xf0(%rbp),%rdx
  40139c:	48 8d 75 af          	lea    -0x51(%rbp),%rsi
  4013a0:	48 89 c7             	mov    %rax,%rdi
  4013a3:	e8 f4 01 00 00       	callq  40159c <_ZNKSt10multipliesIN6Engine4SIMD6PacketIiLNS1_4SizeE32EEEEclERKS4_S7_>
  4013a8:	48 8d 85 70 ff ff ff 	lea    -0x90(%rbp),%rax
  4013af:	48 89 de             	mov    %rbx,%rsi
  4013b2:	48 89 c7             	mov    %rax,%rdi
  4013b5:	e8 60 fa ff ff       	callq  400e1a <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE32EE5storeEPi>
  4013ba:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4013be:	89 c2                	mov    %eax,%edx
  4013c0:	8b 45 d8             	mov    -0x28(%rbp),%eax
  4013c3:	01 d0                	add    %edx,%eax
  4013c5:	89 45 d8             	mov    %eax,-0x28(%rbp)
  4013c8:	8b 45 d8             	mov    -0x28(%rbp),%eax
  4013cb:	48 63 d0             	movslq %eax,%rdx
  4013ce:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  4013d5:	48 2b 45 e0          	sub    -0x20(%rbp),%rax
  4013d9:	48 39 c2             	cmp    %rax,%rdx
  4013dc:	0f 82 3b ff ff ff    	jb     40131d <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0xac>
  4013e2:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  4013e9:	89 c2                	mov    %eax,%edx
  4013eb:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  4013ef:	29 c2                	sub    %eax,%edx
  4013f1:	89 d0                	mov    %edx,%eax
  4013f3:	89 45 dc             	mov    %eax,-0x24(%rbp)
  4013f6:	48 c7 45 e8 04 00 00 	movq   $0x4,-0x18(%rbp)
  4013fd:	00 
  4013fe:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401402:	ba 00 00 00 00       	mov    $0x0,%edx
  401407:	48 f7 75 e8          	divq   -0x18(%rbp)
  40140b:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
  40140f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  401413:	48 0f af 45 e8       	imul   -0x18(%rbp),%rax
  401418:	48 29 45 e0          	sub    %rax,-0x20(%rbp)
  40141c:	bf 10 00 00 00       	mov    $0x10,%edi
  401421:	e8 99 f9 ff ff       	callq  400dbf <_ZN6Engine4SIMD6canMulIiE4testENS0_4SizeE>
  401426:	84 c0                	test   %al,%al
  401428:	0f 84 d3 00 00 00    	je     401501 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x290>
  40142e:	8b 45 dc             	mov    -0x24(%rbp),%eax
  401431:	89 45 d4             	mov    %eax,-0x2c(%rbp)
  401434:	e9 ac 00 00 00       	jmpq   4014e5 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x274>
  401439:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  40143c:	48 98                	cltq   
  40143e:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401445:	00 
  401446:	48 8b 85 08 ff ff ff 	mov    -0xf8(%rbp),%rax
  40144d:	48 01 c2             	add    %rax,%rdx
  401450:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  401457:	48 89 d6             	mov    %rdx,%rsi
  40145a:	48 89 c7             	mov    %rax,%rdi
  40145d:	e8 f4 fa ff ff       	callq  400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>
  401462:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  401465:	48 98                	cltq   
  401467:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  40146e:	00 
  40146f:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  401476:	48 01 c2             	add    %rax,%rdx
  401479:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
  401480:	48 89 d6             	mov    %rdx,%rsi
  401483:	48 89 c7             	mov    %rax,%rdi
  401486:	e8 cb fa ff ff       	callq  400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>
  40148b:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  40148e:	48 98                	cltq   
  401490:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401497:	00 
  401498:	48 8b 85 f8 fe ff ff 	mov    -0x108(%rbp),%rax
  40149f:	48 8d 1c 02          	lea    (%rdx,%rax,1),%rbx
  4014a3:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
  4014aa:	48 8d 8d 60 ff ff ff 	lea    -0xa0(%rbp),%rcx
  4014b1:	48 8d 45 c6          	lea    -0x3a(%rbp),%rax
  4014b5:	48 89 ce             	mov    %rcx,%rsi
  4014b8:	48 89 c7             	mov    %rax,%rdi
  4014bb:	e8 38 01 00 00       	callq  4015f8 <_ZNKSt10multipliesIN6Engine4SIMD6PacketIiLNS1_4SizeE16EEEEclERKS4_S7_>
  4014c0:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
  4014c4:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
  4014c8:	48 8d 45 b0          	lea    -0x50(%rbp),%rax
  4014cc:	48 89 de             	mov    %rbx,%rsi
  4014cf:	48 89 c7             	mov    %rax,%rdi
  4014d2:	e8 a5 fa ff ff       	callq  400f7c <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE16EE5storeEPi>
  4014d7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4014db:	89 c2                	mov    %eax,%edx
  4014dd:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4014e0:	01 d0                	add    %edx,%eax
  4014e2:	89 45 d4             	mov    %eax,-0x2c(%rbp)
  4014e5:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4014e8:	48 63 d0             	movslq %eax,%rdx
  4014eb:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  4014f2:	48 2b 45 e0          	sub    -0x20(%rbp),%rax
  4014f6:	48 39 c2             	cmp    %rax,%rdx
  4014f9:	0f 82 3a ff ff ff    	jb     401439 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x1c8>
  4014ff:	eb 0b                	jmp    40150c <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x29b>
  401501:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  401508:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  40150c:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
  401513:	89 c2                	mov    %eax,%edx
  401515:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401519:	29 c2                	sub    %eax,%edx
  40151b:	89 d0                	mov    %edx,%eax
  40151d:	89 45 d0             	mov    %eax,-0x30(%rbp)
  401520:	eb 5b                	jmp    40157d <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x30c>
  401522:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401525:	48 98                	cltq   
  401527:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  40152e:	00 
  40152f:	48 8b 85 f8 fe ff ff 	mov    -0x108(%rbp),%rax
  401536:	48 8d 1c 02          	lea    (%rdx,%rax,1),%rbx
  40153a:	8b 45 d0             	mov    -0x30(%rbp),%eax
  40153d:	48 98                	cltq   
  40153f:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
  401546:	00 
  401547:	48 8b 85 00 ff ff ff 	mov    -0x100(%rbp),%rax
  40154e:	48 01 c2             	add    %rax,%rdx
  401551:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401554:	48 98                	cltq   
  401556:	48 8d 0c 85 00 00 00 	lea    0x0(,%rax,4),%rcx
  40155d:	00 
  40155e:	48 8b 85 08 ff ff ff 	mov    -0xf8(%rbp),%rax
  401565:	48 01 c1             	add    %rax,%rcx
  401568:	48 8d 45 c7          	lea    -0x39(%rbp),%rax
  40156c:	48 89 ce             	mov    %rcx,%rsi
  40156f:	48 89 c7             	mov    %rax,%rdi
  401572:	e8 b1 00 00 00       	callq  401628 <_ZNKSt10multipliesIiEclERKiS2_>
  401577:	89 03                	mov    %eax,(%rbx)
  401579:	83 45 d0 01          	addl   $0x1,-0x30(%rbp)
  40157d:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401580:	48 98                	cltq   
  401582:	48 3b 85 f0 fe ff ff 	cmp    -0x110(%rbp),%rax
  401589:	72 97                	jb     401522 <_ZN6Engine4SIMD9operationIiSt10multipliesNS0_6canMulEEEvPKT_S6_PS4_m+0x2b1>
  40158b:	48 81 c4 00 01 00 00 	add    $0x100,%rsp
  401592:	5b                   	pop    %rbx
  401593:	41 5a                	pop    %r10
  401595:	5d                   	pop    %rbp
  401596:	49 8d 62 f8          	lea    -0x8(%r10),%rsp
  40159a:	c3                   	retq   
  40159b:	90                   	nop

000000000040159c <_ZNKSt10multipliesIN6Engine4SIMD6PacketIiLNS1_4SizeE32EEEEclERKS4_S7_>:
  40159c:	4c 8d 54 24 08       	lea    0x8(%rsp),%r10
  4015a1:	48 83 e4 e0          	and    $0xffffffffffffffe0,%rsp
  4015a5:	41 ff 72 f8          	pushq  -0x8(%r10)
  4015a9:	55                   	push   %rbp
  4015aa:	48 89 e5             	mov    %rsp,%rbp
  4015ad:	41 52                	push   %r10
  4015af:	48 83 ec 28          	sub    $0x28,%rsp
  4015b3:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  4015b7:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  4015bb:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
  4015bf:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
  4015c3:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  4015c7:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
  4015cb:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  4015cf:	ff 70 18             	pushq  0x18(%rax)
  4015d2:	ff 70 10             	pushq  0x10(%rax)
  4015d5:	ff 70 08             	pushq  0x8(%rax)
  4015d8:	ff 30                	pushq  (%rax)
  4015da:	48 89 ce             	mov    %rcx,%rsi
  4015dd:	48 89 d7             	mov    %rdx,%rdi
  4015e0:	e8 7b f8 ff ff       	callq  400e60 <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE32EEmlES3_>
  4015e5:	48 83 c4 20          	add    $0x20,%rsp
  4015e9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  4015ed:	4c 8b 55 f8          	mov    -0x8(%rbp),%r10
  4015f1:	c9                   	leaveq 
  4015f2:	49 8d 62 f8          	lea    -0x8(%r10),%rsp
  4015f6:	c3                   	retq   
  4015f7:	90                   	nop

00000000004015f8 <_ZNKSt10multipliesIN6Engine4SIMD6PacketIiLNS1_4SizeE16EEEEclERKS4_S7_>:
  4015f8:	55                   	push   %rbp
  4015f9:	48 89 e5             	mov    %rsp,%rbp
  4015fc:	48 83 ec 20          	sub    $0x20,%rsp
  401600:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401604:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401608:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  40160c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401610:	48 8b 08             	mov    (%rax),%rcx
  401613:	48 8b 50 08          	mov    0x8(%rax),%rdx
  401617:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40161b:	48 89 ce             	mov    %rcx,%rsi
  40161e:	48 89 c7             	mov    %rax,%rdi
  401621:	e8 86 f9 ff ff       	callq  400fac <_ZNK6Engine4SIMD6PacketIiLNS0_4SizeE16EEmlES3_>
  401626:	c9                   	leaveq 
  401627:	c3                   	retq   

0000000000401628 <_ZNKSt10multipliesIiEclERKiS2_>:
  401628:	55                   	push   %rbp
  401629:	48 89 e5             	mov    %rsp,%rbp
  40162c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401630:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401634:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  401638:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  40163c:	8b 10                	mov    (%rax),%edx
  40163e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401642:	8b 00                	mov    (%rax),%eax
  401644:	0f af c2             	imul   %edx,%eax
  401647:	5d                   	pop    %rbp
  401648:	c3                   	retq   
  401649:	90                   	nop

000000000040164a <_ZL15__get_cpuid_maxjPj>:
  40164a:	55                   	push   %rbp
  40164b:	48 89 e5             	mov    %rsp,%rbp
  40164e:	53                   	push   %rbx
  40164f:	89 7d e4             	mov    %edi,-0x1c(%rbp)
  401652:	48 89 75 d8          	mov    %rsi,-0x28(%rbp)
  401656:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  401659:	0f a2                	cpuid  
  40165b:	89 de                	mov    %ebx,%esi
  40165d:	89 45 f4             	mov    %eax,-0xc(%rbp)
  401660:	89 75 f0             	mov    %esi,-0x10(%rbp)
  401663:	89 4d ec             	mov    %ecx,-0x14(%rbp)
  401666:	89 55 e8             	mov    %edx,-0x18(%rbp)
  401669:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
  40166e:	74 09                	je     401679 <_ZL15__get_cpuid_maxjPj+0x2f>
  401670:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  401674:	8b 55 f0             	mov    -0x10(%rbp),%edx
  401677:	89 10                	mov    %edx,(%rax)
  401679:	8b 45 f4             	mov    -0xc(%rbp),%eax
  40167c:	5b                   	pop    %rbx
  40167d:	5d                   	pop    %rbp
  40167e:	c3                   	retq   

000000000040167f <_ZL11__get_cpuidjPjS_S_S_>:
  40167f:	55                   	push   %rbp
  401680:	48 89 e5             	mov    %rsp,%rbp
  401683:	53                   	push   %rbx
  401684:	48 83 ec 38          	sub    $0x38,%rsp
  401688:	89 7d e4             	mov    %edi,-0x1c(%rbp)
  40168b:	48 89 75 d8          	mov    %rsi,-0x28(%rbp)
  40168f:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
  401693:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
  401697:	4c 89 45 c0          	mov    %r8,-0x40(%rbp)
  40169b:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  40169e:	25 00 00 00 80       	and    $0x80000000,%eax
  4016a3:	89 45 f4             	mov    %eax,-0xc(%rbp)
  4016a6:	8b 45 f4             	mov    -0xc(%rbp),%eax
  4016a9:	be 00 00 00 00       	mov    $0x0,%esi
  4016ae:	89 c7                	mov    %eax,%edi
  4016b0:	e8 95 ff ff ff       	callq  40164a <_ZL15__get_cpuid_maxjPj>
  4016b5:	3b 45 e4             	cmp    -0x1c(%rbp),%eax
  4016b8:	0f 92 c0             	setb   %al
  4016bb:	84 c0                	test   %al,%al
  4016bd:	74 07                	je     4016c6 <_ZL11__get_cpuidjPjS_S_S_+0x47>
  4016bf:	b8 00 00 00 00       	mov    $0x0,%eax
  4016c4:	eb 24                	jmp    4016ea <_ZL11__get_cpuidjPjS_S_S_+0x6b>
  4016c6:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  4016c9:	0f a2                	cpuid  
  4016cb:	89 de                	mov    %ebx,%esi
  4016cd:	48 8b 7d d8          	mov    -0x28(%rbp),%rdi
  4016d1:	89 07                	mov    %eax,(%rdi)
  4016d3:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
  4016d7:	89 30                	mov    %esi,(%rax)
  4016d9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  4016dd:	89 08                	mov    %ecx,(%rax)
  4016df:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  4016e3:	89 10                	mov    %edx,(%rax)
  4016e5:	b8 01 00 00 00       	mov    $0x1,%eax
  4016ea:	48 83 c4 38          	add    $0x38,%rsp
  4016ee:	5b                   	pop    %rbx
  4016ef:	5d                   	pop    %rbp
  4016f0:	c3                   	retq   
  4016f1:	90                   	nop

00000000004016f2 <_ZN12_GLOBAL__N_16CPU_IDC2Ev>:
  4016f2:	55                   	push   %rbp
  4016f3:	48 89 e5             	mov    %rsp,%rbp
  4016f6:	48 83 ec 60          	sub    $0x60,%rsp
  4016fa:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
  4016fe:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401702:	be 00 00 00 00       	mov    $0x0,%esi
  401707:	48 89 c7             	mov    %rax,%rdi
  40170a:	e8 9b 05 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  40170f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401713:	48 83 c0 08          	add    $0x8,%rax
  401717:	be 00 00 00 00       	mov    $0x0,%esi
  40171c:	48 89 c7             	mov    %rax,%rdi
  40171f:	e8 86 05 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  401724:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401728:	48 83 c0 10          	add    $0x10,%rax
  40172c:	be 00 00 00 00       	mov    $0x0,%esi
  401731:	48 89 c7             	mov    %rax,%rdi
  401734:	e8 71 05 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  401739:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  40173d:	48 83 c0 18          	add    $0x18,%rax
  401741:	be 00 00 00 00       	mov    $0x0,%esi
  401746:	48 89 c7             	mov    %rax,%rdi
  401749:	e8 5c 05 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  40174e:	be 00 00 00 00       	mov    $0x0,%esi
  401753:	bf 00 00 00 00       	mov    $0x0,%edi
  401758:	e8 ed fe ff ff       	callq  40164a <_ZL15__get_cpuid_maxjPj>
  40175d:	89 45 fc             	mov    %eax,-0x4(%rbp)
  401760:	83 7d fc 00          	cmpl   $0x0,-0x4(%rbp)
  401764:	74 5f                	je     4017c5 <_ZN12_GLOBAL__N_16CPU_IDC2Ev+0xd3>
  401766:	48 8d 75 b0          	lea    -0x50(%rbp),%rsi
  40176a:	48 8d 4d b4          	lea    -0x4c(%rbp),%rcx
  40176e:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
  401772:	48 8d 45 bc          	lea    -0x44(%rbp),%rax
  401776:	49 89 f0             	mov    %rsi,%r8
  401779:	48 89 c6             	mov    %rax,%rsi
  40177c:	bf 01 00 00 00       	mov    $0x1,%edi
  401781:	e8 f9 fe ff ff       	callq  40167f <_ZL11__get_cpuidjPjS_S_S_>
  401786:	8b 45 b4             	mov    -0x4c(%rbp),%eax
  401789:	89 c2                	mov    %eax,%edx
  40178b:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  40178f:	48 89 d6             	mov    %rdx,%rsi
  401792:	48 89 c7             	mov    %rax,%rdi
  401795:	e8 10 05 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  40179a:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  40179e:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
  4017a2:	48 89 10             	mov    %rdx,(%rax)
  4017a5:	8b 45 b0             	mov    -0x50(%rbp),%eax
  4017a8:	89 c2                	mov    %eax,%edx
  4017aa:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
  4017ae:	48 89 d6             	mov    %rdx,%rsi
  4017b1:	48 89 c7             	mov    %rax,%rdi
  4017b4:	e8 f1 04 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  4017b9:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  4017bd:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
  4017c1:	48 89 50 08          	mov    %rdx,0x8(%rax)
  4017c5:	83 7d fc 06          	cmpl   $0x6,-0x4(%rbp)
  4017c9:	76 60                	jbe    40182b <_ZN12_GLOBAL__N_16CPU_IDC2Ev+0x139>
  4017cb:	48 8d 75 b0          	lea    -0x50(%rbp),%rsi
  4017cf:	48 8d 4d b4          	lea    -0x4c(%rbp),%rcx
  4017d3:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
  4017d7:	48 8d 45 bc          	lea    -0x44(%rbp),%rax
  4017db:	49 89 f0             	mov    %rsi,%r8
  4017de:	48 89 c6             	mov    %rax,%rsi
  4017e1:	bf 07 00 00 00       	mov    $0x7,%edi
  4017e6:	e8 94 fe ff ff       	callq  40167f <_ZL11__get_cpuidjPjS_S_S_>
  4017eb:	8b 45 b8             	mov    -0x48(%rbp),%eax
  4017ee:	89 c2                	mov    %eax,%edx
  4017f0:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4017f4:	48 89 d6             	mov    %rdx,%rsi
  4017f7:	48 89 c7             	mov    %rax,%rdi
  4017fa:	e8 ab 04 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  4017ff:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401803:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  401807:	48 89 50 10          	mov    %rdx,0x10(%rax)
  40180b:	8b 45 b4             	mov    -0x4c(%rbp),%eax
  40180e:	89 c2                	mov    %eax,%edx
  401810:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
  401814:	48 89 d6             	mov    %rdx,%rsi
  401817:	48 89 c7             	mov    %rax,%rdi
  40181a:	e8 8b 04 00 00       	callq  401caa <_ZNSt6bitsetILm32EEC1Ey>
  40181f:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401823:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  401827:	48 89 50 18          	mov    %rdx,0x18(%rax)
  40182b:	c9                   	leaveq 
  40182c:	c3                   	retq   

000000000040182d <_ZN6Engine9Processor6hasSSEEv>:
  40182d:	55                   	push   %rbp
  40182e:	48 89 e5             	mov    %rsp,%rbp
  401831:	53                   	push   %rbx
  401832:	48 83 ec 18          	sub    $0x18,%rsp
  401836:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  40183a:	ba 19 00 00 00       	mov    $0x19,%edx
  40183f:	be 08 2c 60 00       	mov    $0x602c08,%esi
  401844:	48 89 c7             	mov    %rax,%rdi
  401847:	e8 8e 04 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  40184c:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401850:	48 89 c7             	mov    %rax,%rdi
  401853:	e8 be 04 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  401858:	89 c3                	mov    %eax,%ebx
  40185a:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  40185e:	48 89 c7             	mov    %rax,%rdi
  401861:	e8 a6 04 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  401866:	89 d8                	mov    %ebx,%eax
  401868:	48 83 c4 18          	add    $0x18,%rsp
  40186c:	5b                   	pop    %rbx
  40186d:	5d                   	pop    %rbp
  40186e:	c3                   	retq   

000000000040186f <_ZN6Engine9Processor7hasSSE2Ev>:
  40186f:	55                   	push   %rbp
  401870:	48 89 e5             	mov    %rsp,%rbp
  401873:	53                   	push   %rbx
  401874:	48 83 ec 18          	sub    $0x18,%rsp
  401878:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  40187c:	ba 1a 00 00 00       	mov    $0x1a,%edx
  401881:	be 08 2c 60 00       	mov    $0x602c08,%esi
  401886:	48 89 c7             	mov    %rax,%rdi
  401889:	e8 4c 04 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  40188e:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401892:	48 89 c7             	mov    %rax,%rdi
  401895:	e8 7c 04 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  40189a:	89 c3                	mov    %eax,%ebx
  40189c:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4018a0:	48 89 c7             	mov    %rax,%rdi
  4018a3:	e8 64 04 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  4018a8:	89 d8                	mov    %ebx,%eax
  4018aa:	48 83 c4 18          	add    $0x18,%rsp
  4018ae:	5b                   	pop    %rbx
  4018af:	5d                   	pop    %rbp
  4018b0:	c3                   	retq   

00000000004018b1 <_ZN6Engine9Processor7hasSSE3Ev>:
  4018b1:	55                   	push   %rbp
  4018b2:	48 89 e5             	mov    %rsp,%rbp
  4018b5:	53                   	push   %rbx
  4018b6:	48 83 ec 18          	sub    $0x18,%rsp
  4018ba:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4018be:	ba 00 00 00 00       	mov    $0x0,%edx
  4018c3:	be 00 2c 60 00       	mov    $0x602c00,%esi
  4018c8:	48 89 c7             	mov    %rax,%rdi
  4018cb:	e8 0a 04 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  4018d0:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4018d4:	48 89 c7             	mov    %rax,%rdi
  4018d7:	e8 3a 04 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  4018dc:	89 c3                	mov    %eax,%ebx
  4018de:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4018e2:	48 89 c7             	mov    %rax,%rdi
  4018e5:	e8 22 04 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  4018ea:	89 d8                	mov    %ebx,%eax
  4018ec:	48 83 c4 18          	add    $0x18,%rsp
  4018f0:	5b                   	pop    %rbx
  4018f1:	5d                   	pop    %rbp
  4018f2:	c3                   	retq   

00000000004018f3 <_ZN6Engine9Processor8hasSSE41Ev>:
  4018f3:	55                   	push   %rbp
  4018f4:	48 89 e5             	mov    %rsp,%rbp
  4018f7:	53                   	push   %rbx
  4018f8:	48 83 ec 18          	sub    $0x18,%rsp
  4018fc:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401900:	ba 13 00 00 00       	mov    $0x13,%edx
  401905:	be 00 2c 60 00       	mov    $0x602c00,%esi
  40190a:	48 89 c7             	mov    %rax,%rdi
  40190d:	e8 c8 03 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  401912:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401916:	48 89 c7             	mov    %rax,%rdi
  401919:	e8 f8 03 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  40191e:	89 c3                	mov    %eax,%ebx
  401920:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401924:	48 89 c7             	mov    %rax,%rdi
  401927:	e8 e0 03 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  40192c:	89 d8                	mov    %ebx,%eax
  40192e:	48 83 c4 18          	add    $0x18,%rsp
  401932:	5b                   	pop    %rbx
  401933:	5d                   	pop    %rbp
  401934:	c3                   	retq   

0000000000401935 <_ZN6Engine9Processor8hasSSE42Ev>:
  401935:	55                   	push   %rbp
  401936:	48 89 e5             	mov    %rsp,%rbp
  401939:	53                   	push   %rbx
  40193a:	48 83 ec 18          	sub    $0x18,%rsp
  40193e:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401942:	ba 14 00 00 00       	mov    $0x14,%edx
  401947:	be 00 2c 60 00       	mov    $0x602c00,%esi
  40194c:	48 89 c7             	mov    %rax,%rdi
  40194f:	e8 86 03 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  401954:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401958:	48 89 c7             	mov    %rax,%rdi
  40195b:	e8 b6 03 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  401960:	89 c3                	mov    %eax,%ebx
  401962:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401966:	48 89 c7             	mov    %rax,%rdi
  401969:	e8 9e 03 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  40196e:	89 d8                	mov    %ebx,%eax
  401970:	48 83 c4 18          	add    $0x18,%rsp
  401974:	5b                   	pop    %rbx
  401975:	5d                   	pop    %rbp
  401976:	c3                   	retq   

0000000000401977 <_ZN6Engine9Processor8hasSSSE3Ev>:
  401977:	55                   	push   %rbp
  401978:	48 89 e5             	mov    %rsp,%rbp
  40197b:	53                   	push   %rbx
  40197c:	48 83 ec 18          	sub    $0x18,%rsp
  401980:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  401984:	ba 09 00 00 00       	mov    $0x9,%edx
  401989:	be 00 2c 60 00       	mov    $0x602c00,%esi
  40198e:	48 89 c7             	mov    %rax,%rdi
  401991:	e8 44 03 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  401996:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  40199a:	48 89 c7             	mov    %rax,%rdi
  40199d:	e8 74 03 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  4019a2:	89 c3                	mov    %eax,%ebx
  4019a4:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4019a8:	48 89 c7             	mov    %rax,%rdi
  4019ab:	e8 5c 03 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  4019b0:	89 d8                	mov    %ebx,%eax
  4019b2:	48 83 c4 18          	add    $0x18,%rsp
  4019b6:	5b                   	pop    %rbx
  4019b7:	5d                   	pop    %rbp
  4019b8:	c3                   	retq   

00000000004019b9 <_ZN6Engine9Processor6hasAVXEv>:
  4019b9:	55                   	push   %rbp
  4019ba:	48 89 e5             	mov    %rsp,%rbp
  4019bd:	53                   	push   %rbx
  4019be:	48 83 ec 18          	sub    $0x18,%rsp
  4019c2:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4019c6:	ba 1c 00 00 00       	mov    $0x1c,%edx
  4019cb:	be 00 2c 60 00       	mov    $0x602c00,%esi
  4019d0:	48 89 c7             	mov    %rax,%rdi
  4019d3:	e8 02 03 00 00       	callq  401cda <_ZNSt6bitsetILm32EEixEm>
  4019d8:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4019dc:	48 89 c7             	mov    %rax,%rdi
  4019df:	e8 32 03 00 00       	callq  401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>
  4019e4:	89 c3                	mov    %eax,%ebx
  4019e6:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
  4019ea:	48 89 c7             	mov    %rax,%rdi
  4019ed:	e8 1a 03 00 00       	callq  401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>
  4019f2:	89 d8                	mov    %ebx,%eax
  4019f4:	48 83 c4 18          	add    $0x18,%rsp
  4019f8:	5b                   	pop    %rbx
  4019f9:	5d                   	pop    %rbp
  4019fa:	c3                   	retq   

00000000004019fb <_ZN6Engine9Processor7hasAVX2Ev>:
  4019fb:	55                   	push   %rbp
  4019fc:	48 89 e5             	mov    %rsp,%rbp
  4019ff:	b8 00 00 00 00       	mov    $0x0,%eax
  401a04:	5d                   	pop    %rbp
  401a05:	c3                   	retq   

0000000000401a06 <_ZN6Engine4SIMD7strncmpEPcS1_m>:
  401a06:	55                   	push   %rbp
  401a07:	48 89 e5             	mov    %rsp,%rbp
  401a0a:	48 83 ec 60          	sub    $0x60,%rsp
  401a0e:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
  401a12:	48 89 75 b0          	mov    %rsi,-0x50(%rbp)
  401a16:	48 89 55 a8          	mov    %rdx,-0x58(%rbp)
  401a1a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401a1e:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
  401a22:	75 0a                	jne    401a2e <_ZN6Engine4SIMD7strncmpEPcS1_m+0x28>
  401a24:	b8 00 00 00 00       	mov    $0x0,%eax
  401a29:	e9 aa 01 00 00       	jmpq   401bd8 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1d2>
  401a2e:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401a32:	48 c1 e8 04          	shr    $0x4,%rax
  401a36:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
  401a3a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401a3e:	48 c1 e0 04          	shl    $0x4,%rax
  401a42:	48 89 c2             	mov    %rax,%rdx
  401a45:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
  401a49:	48 29 d0             	sub    %rdx,%rax
  401a4c:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
  401a50:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
  401a57:	00 
  401a58:	e9 a4 00 00 00       	jmpq   401b01 <_ZN6Engine4SIMD7strncmpEPcS1_m+0xfb>
  401a5d:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  401a61:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401a65:	48 01 c2             	add    %rax,%rdx
  401a68:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
  401a6c:	48 89 d6             	mov    %rdx,%rsi
  401a6f:	48 89 c7             	mov    %rax,%rdi
  401a72:	e8 df f4 ff ff       	callq  400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>
  401a77:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
  401a7b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401a7f:	48 01 c2             	add    %rax,%rdx
  401a82:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  401a86:	48 89 d6             	mov    %rdx,%rsi
  401a89:	48 89 c7             	mov    %rax,%rdi
  401a8c:	e8 c5 f4 ff ff       	callq  400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>
  401a91:	c5 f9 6f 45 c0       	vmovdqa -0x40(%rbp),%xmm0
  401a96:	c5 f9 6f c8          	vmovdqa %xmm0,%xmm1
  401a9a:	c5 f9 6f 45 d0       	vmovdqa -0x30(%rbp),%xmm0
  401a9f:	c4 e3 79 63 c1 18    	vpcmpistri $0x18,%xmm1,%xmm0
  401aa5:	89 c8                	mov    %ecx,%eax
  401aa7:	c4 e3 79 62 c1 18    	vpcmpistrm $0x18,%xmm1,%xmm0
  401aad:	89 45 ec             	mov    %eax,-0x14(%rbp)
  401ab0:	83 7d ec 0f          	cmpl   $0xf,-0x14(%rbp)
  401ab4:	7f 46                	jg     401afc <_ZN6Engine4SIMD7strncmpEPcS1_m+0xf6>
  401ab6:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401ab9:	48 63 d0             	movslq %eax,%rdx
  401abc:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401ac0:	48 01 c2             	add    %rax,%rdx
  401ac3:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401ac7:	48 01 d0             	add    %rdx,%rax
  401aca:	0f b6 10             	movzbl (%rax),%edx
  401acd:	8b 45 ec             	mov    -0x14(%rbp),%eax
  401ad0:	48 63 c8             	movslq %eax,%rcx
  401ad3:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401ad7:	48 01 c1             	add    %rax,%rcx
  401ada:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
  401ade:	48 01 c8             	add    %rcx,%rax
  401ae1:	0f b6 00             	movzbl (%rax),%eax
  401ae4:	38 c2                	cmp    %al,%dl
  401ae6:	7d 0a                	jge    401af2 <_ZN6Engine4SIMD7strncmpEPcS1_m+0xec>
  401ae8:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401aed:	e9 e6 00 00 00       	jmpq   401bd8 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1d2>
  401af2:	b8 01 00 00 00       	mov    $0x1,%eax
  401af7:	e9 dc 00 00 00       	jmpq   401bd8 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1d2>
  401afc:	48 83 45 f8 10       	addq   $0x10,-0x8(%rbp)
  401b01:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401b05:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
  401b09:	48 29 c2             	sub    %rax,%rdx
  401b0c:	48 89 d0             	mov    %rdx,%rax
  401b0f:	48 3b 45 f8          	cmp    -0x8(%rbp),%rax
  401b13:	0f 87 44 ff ff ff    	ja     401a5d <_ZN6Engine4SIMD7strncmpEPcS1_m+0x57>
  401b19:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401b1d:	48 85 c0             	test   %rax,%rax
  401b20:	0f 84 ad 00 00 00    	je     401bd3 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1cd>
  401b26:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
  401b2a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401b2e:	48 01 c2             	add    %rax,%rdx
  401b31:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
  401b35:	48 89 d6             	mov    %rdx,%rsi
  401b38:	48 89 c7             	mov    %rax,%rdi
  401b3b:	e8 16 f4 ff ff       	callq  400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>
  401b40:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
  401b44:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401b48:	48 01 c2             	add    %rax,%rdx
  401b4b:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
  401b4f:	48 89 d6             	mov    %rdx,%rsi
  401b52:	48 89 c7             	mov    %rax,%rdi
  401b55:	e8 fc f3 ff ff       	callq  400f56 <_ZN6Engine4SIMD6PacketIiLNS0_4SizeE16EE4loadEPKi>
  401b5a:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401b5e:	89 c2                	mov    %eax,%edx
  401b60:	c5 f9 6f 45 c0       	vmovdqa -0x40(%rbp),%xmm0
  401b65:	c5 f9 6f c8          	vmovdqa %xmm0,%xmm1
  401b69:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401b6d:	c5 f9 6f 45 d0       	vmovdqa -0x30(%rbp),%xmm0
  401b72:	c4 e3 79 61 c1 18    	vpcmpestri $0x18,%xmm1,%xmm0
  401b78:	c4 e3 79 60 c1 18    	vpcmpestrm $0x18,%xmm1,%xmm0
  401b7e:	89 4d e8             	mov    %ecx,-0x18(%rbp)
  401b81:	83 7d e8 0f          	cmpl   $0xf,-0x18(%rbp)
  401b85:	7f 4c                	jg     401bd3 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1cd>
  401b87:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401b8b:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
  401b8f:	48 29 c2             	sub    %rax,%rdx
  401b92:	8b 45 e8             	mov    -0x18(%rbp),%eax
  401b95:	48 98                	cltq   
  401b97:	48 01 c2             	add    %rax,%rdx
  401b9a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
  401b9e:	48 01 d0             	add    %rdx,%rax
  401ba1:	0f b6 10             	movzbl (%rax),%edx
  401ba4:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  401ba8:	48 8b 4d a8          	mov    -0x58(%rbp),%rcx
  401bac:	48 29 c1             	sub    %rax,%rcx
  401baf:	8b 45 e8             	mov    -0x18(%rbp),%eax
  401bb2:	48 98                	cltq   
  401bb4:	48 01 c1             	add    %rax,%rcx
  401bb7:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
  401bbb:	48 01 c8             	add    %rcx,%rax
  401bbe:	0f b6 00             	movzbl (%rax),%eax
  401bc1:	38 c2                	cmp    %al,%dl
  401bc3:	7d 07                	jge    401bcc <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1c6>
  401bc5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
  401bca:	eb 0c                	jmp    401bd8 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1d2>
  401bcc:	b8 01 00 00 00       	mov    $0x1,%eax
  401bd1:	eb 05                	jmp    401bd8 <_ZN6Engine4SIMD7strncmpEPcS1_m+0x1d2>
  401bd3:	b8 00 00 00 00       	mov    $0x0,%eax
  401bd8:	c9                   	leaveq 
  401bd9:	c3                   	retq   

0000000000401bda <_Z41__static_initialization_and_destruction_0ii>:
  401bda:	55                   	push   %rbp
  401bdb:	48 89 e5             	mov    %rsp,%rbp
  401bde:	48 83 ec 10          	sub    $0x10,%rsp
  401be2:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401be5:	89 75 f8             	mov    %esi,-0x8(%rbp)
  401be8:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
  401bec:	75 31                	jne    401c1f <_Z41__static_initialization_and_destruction_0ii+0x45>
  401bee:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
  401bf5:	75 28                	jne    401c1f <_Z41__static_initialization_and_destruction_0ii+0x45>
  401bf7:	bf e0 2b 60 00       	mov    $0x602be0,%edi
  401bfc:	e8 6f ed ff ff       	callq  400970 <_ZNSt8ios_base4InitC1Ev@plt>
  401c01:	ba 90 2a 60 00       	mov    $0x602a90,%edx
  401c06:	be e0 2b 60 00       	mov    $0x602be0,%esi
  401c0b:	bf c0 09 40 00       	mov    $0x4009c0,%edi
  401c10:	e8 2b ed ff ff       	callq  400940 <__cxa_atexit@plt>
  401c15:	bf 00 2c 60 00       	mov    $0x602c00,%edi
  401c1a:	e8 d3 fa ff ff       	callq  4016f2 <_ZN12_GLOBAL__N_16CPU_IDC2Ev>
  401c1f:	c9                   	leaveq 
  401c20:	c3                   	retq   

0000000000401c21 <_GLOBAL__sub_I__ZN6Engine9Processor6hasSSEEv>:
  401c21:	55                   	push   %rbp
  401c22:	48 89 e5             	mov    %rsp,%rbp
  401c25:	be ff ff 00 00       	mov    $0xffff,%esi
  401c2a:	bf 01 00 00 00       	mov    $0x1,%edi
  401c2f:	e8 a6 ff ff ff       	callq  401bda <_Z41__static_initialization_and_destruction_0ii>
  401c34:	5d                   	pop    %rbp
  401c35:	c3                   	retq   

0000000000401c36 <_ZNSt12_Base_bitsetILm1EEC1Ey>:
  401c36:	55                   	push   %rbp
  401c37:	48 89 e5             	mov    %rsp,%rbp
  401c3a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401c3e:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401c42:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401c46:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
  401c4a:	48 89 10             	mov    %rdx,(%rax)
  401c4d:	5d                   	pop    %rbp
  401c4e:	c3                   	retq   

0000000000401c4f <_ZNSt12_Base_bitsetILm1EE11_S_whichbitEm>:
  401c4f:	55                   	push   %rbp
  401c50:	48 89 e5             	mov    %rsp,%rbp
  401c53:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401c57:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401c5b:	83 e0 3f             	and    $0x3f,%eax
  401c5e:	5d                   	pop    %rbp
  401c5f:	c3                   	retq   

0000000000401c60 <_ZNSt12_Base_bitsetILm1EE10_S_maskbitEm>:
  401c60:	55                   	push   %rbp
  401c61:	48 89 e5             	mov    %rsp,%rbp
  401c64:	48 83 ec 10          	sub    $0x10,%rsp
  401c68:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401c6c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401c70:	48 89 c7             	mov    %rax,%rdi
  401c73:	e8 d7 ff ff ff       	callq  401c4f <_ZNSt12_Base_bitsetILm1EE11_S_whichbitEm>
  401c78:	ba 01 00 00 00       	mov    $0x1,%edx
  401c7d:	89 c1                	mov    %eax,%ecx
  401c7f:	48 d3 e2             	shl    %cl,%rdx
  401c82:	48 89 d0             	mov    %rdx,%rax
  401c85:	c9                   	leaveq 
  401c86:	c3                   	retq   
  401c87:	90                   	nop

0000000000401c88 <_ZNSt12_Base_bitsetILm1EE10_M_getwordEm>:
  401c88:	55                   	push   %rbp
  401c89:	48 89 e5             	mov    %rsp,%rbp
  401c8c:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401c90:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401c94:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401c98:	5d                   	pop    %rbp
  401c99:	c3                   	retq   

0000000000401c9a <_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy>:
  401c9a:	55                   	push   %rbp
  401c9b:	48 89 e5             	mov    %rsp,%rbp
  401c9e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401ca2:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401ca6:	89 c0                	mov    %eax,%eax
  401ca8:	5d                   	pop    %rbp
  401ca9:	c3                   	retq   

0000000000401caa <_ZNSt6bitsetILm32EEC1Ey>:
  401caa:	55                   	push   %rbp
  401cab:	48 89 e5             	mov    %rsp,%rbp
  401cae:	48 83 ec 10          	sub    $0x10,%rsp
  401cb2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401cb6:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401cba:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401cbe:	48 89 c7             	mov    %rax,%rdi
  401cc1:	e8 d4 ff ff ff       	callq  401c9a <_ZNSt13_Sanitize_valILm32ELb1EE18_S_do_sanitize_valEy>
  401cc6:	48 89 c2             	mov    %rax,%rdx
  401cc9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401ccd:	48 89 d6             	mov    %rdx,%rsi
  401cd0:	48 89 c7             	mov    %rax,%rdi
  401cd3:	e8 5e ff ff ff       	callq  401c36 <_ZNSt12_Base_bitsetILm1EEC1Ey>
  401cd8:	c9                   	leaveq 
  401cd9:	c3                   	retq   

0000000000401cda <_ZNSt6bitsetILm32EEixEm>:
  401cda:	55                   	push   %rbp
  401cdb:	48 89 e5             	mov    %rsp,%rbp
  401cde:	48 83 ec 20          	sub    $0x20,%rsp
  401ce2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401ce6:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401cea:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  401cee:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  401cf2:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  401cf6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401cfa:	48 89 ce             	mov    %rcx,%rsi
  401cfd:	48 89 c7             	mov    %rax,%rdi
  401d00:	e8 49 00 00 00       	callq  401d4e <_ZNSt6bitsetILm32EE9referenceC1ERS0_m>
  401d05:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401d09:	c9                   	leaveq 
  401d0a:	c3                   	retq   
  401d0b:	90                   	nop

0000000000401d0c <_ZNSt6bitsetILm32EE9referenceD1Ev>:
  401d0c:	55                   	push   %rbp
  401d0d:	48 89 e5             	mov    %rsp,%rbp
  401d10:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401d14:	5d                   	pop    %rbp
  401d15:	c3                   	retq   

0000000000401d16 <_ZNKSt6bitsetILm32EE9referencecvbEv>:
  401d16:	55                   	push   %rbp
  401d17:	48 89 e5             	mov    %rsp,%rbp
  401d1a:	53                   	push   %rbx
  401d1b:	48 83 ec 18          	sub    $0x18,%rsp
  401d1f:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
  401d23:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401d27:	48 8b 00             	mov    (%rax),%rax
  401d2a:	48 8b 18             	mov    (%rax),%rbx
  401d2d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401d31:	48 8b 40 08          	mov    0x8(%rax),%rax
  401d35:	48 89 c7             	mov    %rax,%rdi
  401d38:	e8 23 ff ff ff       	callq  401c60 <_ZNSt12_Base_bitsetILm1EE10_S_maskbitEm>
  401d3d:	48 21 d8             	and    %rbx,%rax
  401d40:	48 85 c0             	test   %rax,%rax
  401d43:	0f 95 c0             	setne  %al
  401d46:	48 83 c4 18          	add    $0x18,%rsp
  401d4a:	5b                   	pop    %rbx
  401d4b:	5d                   	pop    %rbp
  401d4c:	c3                   	retq   
  401d4d:	90                   	nop

0000000000401d4e <_ZNSt6bitsetILm32EE9referenceC1ERS0_m>:
  401d4e:	55                   	push   %rbp
  401d4f:	48 89 e5             	mov    %rsp,%rbp
  401d52:	48 83 ec 20          	sub    $0x20,%rsp
  401d56:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401d5a:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401d5e:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  401d62:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
  401d66:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
  401d6a:	48 89 d6             	mov    %rdx,%rsi
  401d6d:	48 89 c7             	mov    %rax,%rdi
  401d70:	e8 13 ff ff ff       	callq  401c88 <_ZNSt12_Base_bitsetILm1EE10_M_getwordEm>
  401d75:	48 89 c2             	mov    %rax,%rdx
  401d78:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401d7c:	48 89 10             	mov    %rdx,(%rax)
  401d7f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
  401d83:	48 89 c7             	mov    %rax,%rdi
  401d86:	e8 c4 fe ff ff       	callq  401c4f <_ZNSt12_Base_bitsetILm1EE11_S_whichbitEm>
  401d8b:	48 89 c2             	mov    %rax,%rdx
  401d8e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  401d92:	48 89 50 08          	mov    %rdx,0x8(%rax)
  401d96:	c9                   	leaveq 
  401d97:	c3                   	retq   
  401d98:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  401d9f:	00 

0000000000401da0 <__libc_csu_init>:
  401da0:	41 57                	push   %r15
  401da2:	41 89 ff             	mov    %edi,%r15d
  401da5:	41 56                	push   %r14
  401da7:	49 89 f6             	mov    %rsi,%r14
  401daa:	41 55                	push   %r13
  401dac:	49 89 d5             	mov    %rdx,%r13
  401daf:	41 54                	push   %r12
  401db1:	4c 8d 25 d8 09 20 00 	lea    0x2009d8(%rip),%r12        # 602790 <__frame_dummy_init_array_entry>
  401db8:	55                   	push   %rbp
  401db9:	48 8d 2d e8 09 20 00 	lea    0x2009e8(%rip),%rbp        # 6027a8 <__init_array_end>
  401dc0:	53                   	push   %rbx
  401dc1:	4c 29 e5             	sub    %r12,%rbp
  401dc4:	31 db                	xor    %ebx,%ebx
  401dc6:	48 c1 fd 03          	sar    $0x3,%rbp
  401dca:	48 83 ec 08          	sub    $0x8,%rsp
  401dce:	e8 05 eb ff ff       	callq  4008d8 <_init>
  401dd3:	48 85 ed             	test   %rbp,%rbp
  401dd6:	74 1e                	je     401df6 <__libc_csu_init+0x56>
  401dd8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  401ddf:	00 
  401de0:	4c 89 ea             	mov    %r13,%rdx
  401de3:	4c 89 f6             	mov    %r14,%rsi
  401de6:	44 89 ff             	mov    %r15d,%edi
  401de9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  401ded:	48 83 c3 01          	add    $0x1,%rbx
  401df1:	48 39 eb             	cmp    %rbp,%rbx
  401df4:	75 ea                	jne    401de0 <__libc_csu_init+0x40>
  401df6:	48 83 c4 08          	add    $0x8,%rsp
  401dfa:	5b                   	pop    %rbx
  401dfb:	5d                   	pop    %rbp
  401dfc:	41 5c                	pop    %r12
  401dfe:	41 5d                	pop    %r13
  401e00:	41 5e                	pop    %r14
  401e02:	41 5f                	pop    %r15
  401e04:	c3                   	retq   
  401e05:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401e0c:	00 00 00 00 

0000000000401e10 <__libc_csu_fini>:
  401e10:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000401e14 <_fini>:
  401e14:	48 83 ec 08          	sub    $0x8,%rsp
  401e18:	48 83 c4 08          	add    $0x8,%rsp
  401e1c:	c3                   	retq   
