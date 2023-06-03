GCD = lambda a, b: (a if b == 0 else GCD(b, a % b))

# or

def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)
    
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x, y = extended_gcd(b, a % b)
    return gcd, y, x - (a // b) * y

def compute_d(e, n):
    _, d, _ = extended_gcd(e, n)
    if d < 0:
        d += n
    return d

p = int(input("enter a prime number p:"))
q = int(input("enter a prime number q:"))
n = p * q
print("n: " + str(n))
phi = (p-1)*(q-1)

e = 13
#for i in range( 2, phi ):
#	if GCD( i, phi ) == 1:
#		e = i
#		break

print("phi: " + str(phi))
d = compute_d(e,phi)
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
        
        
print()