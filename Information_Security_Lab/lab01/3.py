def build_matrix(key):
    key = ''.join(dict.fromkeys(key.upper().replace('J', 'I')))  # Remove duplicates, J=I
    alpha = 'ABCDEFGHIKLMNOPQRSTUVWXYZ'
    full_key = key + ''.join(c for c in alpha if c not in key)
    return [list(full_key[i:i+5]) for i in range(0, 25, 5)]

def prepare_text(text):
    text = text.upper().replace('J', 'I').replace(' ', '')
    result = ''
    i = 0
    while i < len(text):
        a = text[i]
        b = text[i+1] if i+1 < len(text) else 'X'
        if a == b:
            result += a + 'X'
            i += 1
        else:
            result += a + b
            i += 2
    if len(result) % 2 != 0:
        result += 'X'
    return [result[i:i+2] for i in range(0, len(result), 2)]

def find_position(matrix, ch):
    for r, row in enumerate(matrix):
        if ch in row:
            return r, row.index(ch)

def playfair_encrypt(plaintext, key):
    matrix = build_matrix(key)
    pairs = prepare_text(plaintext)
    cipher = ''
    for a, b in pairs:
        ra, ca = find_position(matrix, a)
        rb, cb = find_position(matrix, b)
        if ra == rb:
            cipher += matrix[ra][(ca+1)%5] + matrix[rb][(cb+1)%5]
        elif ca == cb:
            cipher += matrix[(ra+1)%5][ca] + matrix[(rb+1)%5][cb]
        else:
            cipher += matrix[ra][cb] + matrix[rb][ca] 
    return cipher

# Encrypting the message
message = "The key is hidden under the door pad"
key = "GUIDANCE"
ciphertext = playfair_encrypt(message, key)
print("Playfair Encrypted:", ciphertext)