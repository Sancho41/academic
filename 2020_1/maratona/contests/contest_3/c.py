def nome(m, f, s):
    if (s == 'F'):
        return f[:3] + m[-3::]
    return m[:3] + f[-3::]

p, m, s = input().split()
f = nome(m, p, s)

p, s2 = input().split()

n = nome(f, p, s2) if s == 'F' else nome(p, f, s2)

p, s3 = input().split()

b = nome(n, p, s3) if s2 == 'F' else nome(p, n, s3)

print(b)