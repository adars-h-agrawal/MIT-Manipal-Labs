from utils_pkse import Paillier

# 2a. Dataset
documents = {
    1: "the cat sat on the mat",
    2: "the dog chased the cat",
    3: "cats and dogs are friends",
    4: "the mat was sat on by the cat",
    5: "the quick brown fox jumps",
    6: "foxes are clever animals",
    7: "dogs bark and cats meow",
    8: "the fox chased the rabbit",
    9: "the rabbit is fast and clever",
    10: "clever animals outsmart others"
}

# 2b. Paillier setup
p, q = 17, 19
paillier = Paillier(p, q)

# 2c. Inverted index (word → docIDs)
index = {}
for doc_id, text in documents.items():
    for word in text.split():
        index.setdefault(word, set()).add(doc_id)

# Encrypt index (doc IDs encrypted)
enc_index = {word: [paillier.encrypt(d) for d in doc_ids] for word, doc_ids in index.items()}

# 2d. Search
def search(query):
    if query in enc_index:
        doc_ids = [paillier.decrypt(d) for d in enc_index[query]]
        return [documents[i] for i in doc_ids]
    else:
        return []

# --- Demo ---
if __name__ == "__main__":
    print("PKSE Search Demo:")
    q = "fox"
    results = search(q)
    print(f"Query: {q}")
    print("Results:", results)


'''

Sample Output

PKSE Search Demo:
Query: fox
Results: ['the fox chased the rabbit', 'the quick brown fox jumps']

'''