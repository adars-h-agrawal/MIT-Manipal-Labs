from utils_sse import encrypt, decrypt

# 1a. Dataset
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

SECRET = "mysecretkey"

# 1c. Build inverted index (word → docIDs)
index = {}
for doc_id, text in documents.items():
    for word in text.split():
        index.setdefault(word, set()).add(doc_id)

# Encrypt index
enc_index = {encrypt(word, SECRET): [encrypt(str(d), SECRET) for d in doc_ids] 
             for word, doc_ids in index.items()}

# 1d. Search function
def search(query):
    enc_query = encrypt(query, SECRET)
    if enc_query in enc_index:
        doc_ids = [int(decrypt(d, SECRET)) for d in enc_index[enc_query]]
        return [documents[i] for i in doc_ids]
    else:
        return []

# --- Demo ---
if __name__ == "__main__":
    print("SSE Search Demo:")
    q = "cat"
    results = search(q)
    print(f"Query: {q}")
    print("Results:", results)


'''

Sample Output

SSE Search Demo:
Query: cat
Results: ['the cat sat on the mat', 'the dog chased the cat', 'the mat was sat on by the cat']

'''