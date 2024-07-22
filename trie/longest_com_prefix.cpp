string longestCommonPrefix(vector<string> &arr, int n)
{ string ans="";
    for(int i=0;i<arr[0].length();i++)

    {
        char ch=arr[0][i];

        bool match=true;
        for(int j=1;j<n;j++)
        {
            // not match
            if(arr[j].size()<i || ch!=arr[j][i])
            {
                match=false;
                break;
            }

        }
        if(match==false)
        {
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}
/*approach 2

class TrieNode {
public:
    char data;
    TrieNode *children[26];
    int childcount;
    bool isTerminal;
    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie(char ch) { root = new TrieNode(ch); }

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
            root->childcount++;
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }

    //Inserts a word into the trie. 
    void insert(string word) { insertUtil(root, word); }

    void lcp(string str, string &ans) {
        TrieNode *current = root; // add this line
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (current->childcount == 1) { // use current instead of root
                ans.push_back(ch);
                // move to the next node
                int index = ch - 'a'; // corrected from ch = 'a'
                current = current->children[index]; // use current instead of root
            } else {
                break;
            }
            if (current->isTerminal) { // use current instead of root
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *t = new Trie('\0');
    // insert
    for (int i = 0; i < n; i++) {
        t->insert(arr[i]);
    }

    string first = arr[0];

    string ans = "";
    t->lcp(first, ans);
    return ans;
}

*/

