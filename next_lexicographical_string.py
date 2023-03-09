def next_lexicographic_string(s):
    chars = list(s)
    i = len(chars) - 1
    while i >= 0 and chars[i] == 'z':
        i -= 1
    if i < 0:
        a = "a"
        for i in range(0, len(s)):
            a += 'a'
        return a
    chars[i] = chr(ord(chars[i]) + 1)
    chars[i+1:] = ['a'] * (len(chars) - i - 1)
    return ''.join(chars)

s = "zzy"
k = 15
while k > 0:
    print(s)
    s = next_lexicographic_string(s)
    k = k-1