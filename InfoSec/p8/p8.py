p = int(input("enter a prime number p:"))
q = int(input("enter a prime number q:"))
e = 13
n = p * q
print("n: " + str(n))
phi = (p-1)*(q-1)
print("phi: " + str(phi))
d = e - (1 % phi)
print("e:" + str(e))
print("d:" + str(d))
cmd = int(input("enter the command(1: encode, 2: decode):"))

plain = 0
cipher = 0

match cmd:
    case 1:
        plain = int(input("enter the plain:"))
        cipher = (plain ** e) % n
        print("cipher:" + str(cipher))
    case 2:
        cipher = int(input("enter the cipher:"))
        plain = (cipher ** d) % n
        print("plain:" + str(plain))