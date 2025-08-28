import numpy as np

def clean_text(text):
    return ''.join(filter(str.isalpha, text.lower()))

def text_to_nums(text):
    return [ord(c) - ord('a') for c in text]

def nums_to_text(nums):
    return ''.join(chr(n + ord('a')) for n in nums)

def hill_encrypt(text, key):
    text = clean_text(text)
    if len(text) % 2 != 0:
        text += 'x'
    nums = text_to_nums(text)
    ciphertext = []
    for i in range(0, len(nums), 2):
        pair = np.array([[nums[i]], [nums[i+1]]])
        enc = np.dot(key, pair) % 26
        ciphertext.extend(enc.flatten())
    return nums_to_text(ciphertext)

# Key matrix
K = np.array([[3, 3], [2, 7]])

# Message
message = "We live in an insecure world"
cipher = hill_encrypt(message, K)
print("Hill Cipher Encrypted:", cipher)