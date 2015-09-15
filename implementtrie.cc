class TrieNode {
private:
    TrieNode* data[27]; 
public:
    // Initialize your data structure here.
    TrieNode() {
        memset((void*)data, 0, sizeof(data));
    }

    void append(int start, const char* word, int N) {
        TrieNode* root = this;
        while (start < N) {
            int c = word[start++]-'a';
            if (!root->data[c]) {
                root->data[c] = new TrieNode();
            }
            root = root->data[c];
        }
        if (!root->data[26]) {
            root->data[26] = new TrieNode();
        }
    }

    bool search(int start, const char* word, int N, bool full) const {
        const TrieNode* root = this;
        while (start < N) {
            int c = word[start++]-'a';
            if (!root->data[c])
                return false;
            root = root->data[c];
        }
        return !full || root->data[26];
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(const string& word) {
        root->append(0, word.c_str(), word.size());
    }

    // Returns if the word is in the trie.
    bool search(const string& word) {
        return root->search(0, word.c_str(), word.size(), true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(const string& prefix) {
        return root->search(0, prefix.c_str(), prefix.size(), false);
    }

private:
    TrieNode* root;
};


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");