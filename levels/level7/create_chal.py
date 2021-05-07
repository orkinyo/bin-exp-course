import struct
import random

flag = bytearray("mYC001Pa33W0rd".encode())

opcodes = {
    "push":0x2,
    "pop":0x4,
    "xor":0x8,
    "cmp":0x10,
    "load":0x20,
    "read":0x40,
    "exit_not_zero":0x80
}

output = []

def push(reg1:bool):
    if reg1:
        output.append(opcodes["push"] | 0x1)
    else:
        output.append(opcodes["push"])
    print(f"push {'reg1' if reg1 else 'reg2'}")
        
def pop(reg1:bool):
    if reg1:
        output.append(opcodes["pop"] | 0x1)
    else:
        output.append(opcodes["pop"])
    print(f"pop {'reg1' if reg1 else 'reg2'}")
    
def xor(reg1:bool):
    if reg1:
        output.append(opcodes["xor"] | 0x1)
    else:
        output.append(opcodes["xor"])
    
    print(f"xor {'reg1' if reg1 else 'reg2'}")

def cmp():
    output.append(opcodes["cmp"])
    print("cmp")
    
def load(reg1:bool, value:int):
    if reg1:
        output.append(opcodes["load"] | 0x1)
    else:
        output.append(opcodes["load"])
    
    bytes_interp = struct.pack("<I",value)
    for b in bytes_interp:
         output.append(b)
   
    print(f"load {'reg1' if reg1 else 'reg2'} {value}")
    
def read(reg1:bool):
    if reg1:
        output.append(opcodes["read"] | 0x1)
    else:
        output.append(opcodes["read"])
    print(f"read {'reg1' if reg1 else 'reg2'}")
def exit_not_zero():
    output.append(opcodes["exit_not_zero"])
    print("exit_not_zero")
        
def push_read_cmp_xor_enz(index:int):
    push(True)
    push(False)
    reg = bool(random.randint(0,1))
    to_xor = random.randint(10,100)
    xor_res = to_xor ^ flag[index]
    read(reg)
    load(not reg, to_xor)  
    xor(reg)
    load(not reg,xor_res)
    cmp()
    exit_not_zero()
    pop(False)
    pop(True)

for i in range(len(flag)):
    push_read_cmp_xor_enz(i)
    
print("{",end="")
for g,i in enumerate(output):
    if(g % 12 == 0):
        print()
    print(hex(i),end=",")
print("}")
