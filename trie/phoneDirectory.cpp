class TrieNode {
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        // assumption: word is in lowercase
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) { insertUtil(root, word); }

    void printsugg(TrieNode* curr, vector<string> &temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != nullptr) {
                prefix.push_back(ch);
                printsugg(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSugg(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);
            // check for last char
            TrieNode* curr = prev->children[lastch - 'a'];
            // if not found
            if (curr == nullptr) {
                break;
            }
            // if found
            vector<string> temp;
            printsugg(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
}; vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                        string &queryStr) {
    // create trie
    Trie *t = new Trie();
    // insert
    for (int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insert(str);
    }
    // return
    return t->getSugg(queryStr);
}
