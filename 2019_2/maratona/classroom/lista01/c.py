from string import ascii_uppercase as upper

count = 0

a = input()

for letter in a:
    if letter in upper:
        count += 1

if count > len(a) // 2:
    print(a.upper())
else:
    print(a.lower())    