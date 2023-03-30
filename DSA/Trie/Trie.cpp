#include <iostream>
#include <iomanip>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;        //for search fxn;

    TrieNode(char data) : data (data){
        for (int i = 0;i < 26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode* root = new TrieNode('\0');

    void insertUntil(TrieNode* root,string word){
        //base case;
        if (word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumin all letters in CAPS
        int index = word[0] - 'A';
        TrieNode* child;
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUntil(child,word.substr(1));
    }

    void insert(string word){
        insertUntil(root,word);
    }

    bool searchUntil(TrieNode* root,string word){
        if (word.length() == 0)
            return root->isTerminal;
        
        // cout << "root->isTerminal : " << root->isTerminal << endl;
        int index = word[0] - 'A';
        TrieNode* child;
        if (root->children[index] != NULL){
            child = root->children[index];
        }
        else
            return false;
        
        return searchUntil(child,word.substr(1));
    }

    bool search(string word){
        return searchUntil(root,word);
    }

    void removeUntil1(TrieNode* root,string word){
        //base case;
        if (word.length() == 0){
            root->isTerminal = false;
            return;
        }
        
        TrieNode* child = root->children[word[0] - 'A'];
        removeUntil1(child,word.substr(1));
    }
    //approach 1;
    void remove1(string word){
        removeUntil1(root,word);
    }

    bool hasChildren(TrieNode* temp){
        for (int i = 0;i < 26;i++){
            if (temp->children[i] != NULL){
                return true;
            }
        }
        return false;
    }

    TrieNode* removeUntil2(TrieNode* root,string word){
        if (word.length() == 0){
            root->isTerminal = false;
            return root;

            if (hasChildren(root)){
                return root;
            }
            else {
                delete root;
                return NULL;
            }  
                
        }
        TrieNode* child = root->children[word[0] - 'A'];
        root->children[word[0]-'A'] =  removeUntil2(child,word.substr(1));
        if (hasChildren(root) || root->isTerminal == true)
            return root;
        else{
            delete root->children[word[0] - 'A'];
            return NULL;
        }

    }
    //approach 2;
    void remove2(string word){
        root = removeUntil2(root,word);
    }
};

int main(){
    Trie* root = new Trie();
    root->insert("HELLO");
    root->insert("HELLOEND");
    cout << boolalpha;
    
    root->remove2("HELLO");
    cout << root->search("HELLO") << endl;
    cout << root->search("HELLOEND") << endl;

    return 0;
}

