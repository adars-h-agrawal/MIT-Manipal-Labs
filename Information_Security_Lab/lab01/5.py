def char_to_num(c):
    return ord(c.upper()) - ord('A')

def num_to_char(n):
    return chr((n % 26) + ord('A'))

def find_shift(plaintext, ciphertext):
    # Calculate shift using first character pair
    return (char_to_num(ciphertext[0]) - char_to_num(plaintext[0])) % 26

def decrypt(ciphertext, shift):
    plaintext = ''
    for c in ciphertext:
        if c.isalpha():
            p = (char_to_num(c) - shift) % 26
            plaintext += num_to_char(p)
        else:
            plaintext += c  # Non-alpha chars unchanged
    return plaintext

# Given known plaintext-ciphertext pair
known_plain = "yes"
known_cipher = "CIW"

# Ciphertext to decrypt
cipher_to_decrypt = "XVIEWYWI"

shift_key = find_shift(known_plain, known_cipher)
decrypted_text = decrypt(cipher_to_decrypt, shift_key)

print(f"Detected Shift Key: {shift_key}")
print(f"Decrypted Text: {decrypted_text}")