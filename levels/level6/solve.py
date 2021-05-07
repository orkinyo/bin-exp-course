#flag = "bec{x0r1ngAlLgg}"

exp_s = "dabbad00caf3bab3"
x0r = [6, 4, 1, 25, 25, 84, 66, 1, 13, 6, 39, 95, 46, 6, 5, 78]

for a,b in zip(exp_s,x0r):
    print(chr(ord(a)^b),end="")
print()