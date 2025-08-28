import hashlib, random, string, time

def random_string(length=10):
    return ''.join(random.choices(string.ascii_letters + string.digits, k=length))

def hash_with_algorithm(data, algorithm):
    h = hashlib.new(algorithm)
    h.update(data.encode())
    return h.hexdigest()

def analyze_hash_algorithms(n=100):
    dataset = [random_string(random.randint(5, 20)) for _ in range(n)]
    algorithms = ["md5", "sha1", "sha256"]

    results = {}
    for algo in algorithms:
        start_time = time.time()
        hashes = [hash_with_algorithm(s, algo) for s in dataset]
        elapsed = time.time() - start_time

        # Detect collisions
        unique_count = len(set(hashes))
        collisions = n - unique_count

        results[algo] = {"time": elapsed, "collisions": collisions}

    return results


if __name__ == "__main__":
    results = analyze_hash_algorithms(100)

    print("\n--- Hash Performance Analysis ---")
    for algo, data in results.items():
        print(f"{algo.upper()} - Time: {data['time']:.6f}s, Collisions: {data['collisions']}")


'''

Sample Output

--- Hash Performance Analysis ---
MD5    - Time: 0.000512s, Collisions: 0
SHA1   - Time: 0.000601s, Collisions: 0
SHA256 - Time: 0.000773s, Collisions: 0

'''