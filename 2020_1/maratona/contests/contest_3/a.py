s, op = input().split()
ns = list(filter( lambda x: x.lower() in "aeiou" ,s))
print(len(ns) if op == 'V' else len(s) - len(ns))
