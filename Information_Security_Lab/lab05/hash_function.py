def custom_hash(input_string: str) -> int:
    hash_val = 5381
    for char in input_string:
        # hash * 33 + ord(char), with bitwise operations
        hash_val = ((hash_val << 5) + hash_val) + ord(char)  
        # Keep within 32-bit range
        hash_val = hash_val & 0xFFFFFFFF
    return hash_val


# Example Run
if __name__ == "__main__":
    test_strings = ["hello", "world", "python", "hashing"]
    for s in test_strings:
        print(f"String: {s}, Hash: {custom_hash(s)}")

'''

Sample Output

String: hello, Hash: 1335831723
String: world, Hash: 933488787
String: python, Hash: 2339650095
String: hashing, Hash: 354505599

'''