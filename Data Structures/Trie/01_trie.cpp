/*
  Tree like data structure where each node becomes the extension of a chain of words
  sharing a set of common prefix. Used to implement dictionaries.

  string : ["ashi", "ask", "ma"]
                            Root
                          a      m
                         s        a
                       h  k
                      i
  Time Complexity : O(key_length)
  Space Complexity : O(ALPHABET_SIZE * key_length * N)  ; where N is the number of occurances of key.
*/
#include <bits/stdc++.h>
using namespace std;
//------------------------------- Trie Structure -------------------------------
struct Trie{                  // Trie structure
    char value;               // value of the node
    int end = 0;              // none zero mark to represent end of word
    struct Trie* next[26];    // possible paths the current node can take
};
//------------------------------------------------------------------------------

//--------------------------- Function to create Trie --------------------------
struct Trie* CreateTrie(char ch, bool isEnd)
{
    Trie* Node = new Trie;    // allocate memory
    Node -> value = ch;       // value of node
    if(isEnd)                 // if the node is marked as end node
        Node -> end += 1;     // mark it as end
    for(int i=0; i<26; i++)   // mark all next paths as NULL
        Node -> next[i] = NULL;

    return Node;               // return newly created node
}
//------------------------------------------------------------------------------

//-------------------------- Function to add a node to trie --------------------
void addTrie(struct Trie* root, string str)  // Function to add new Node to Trie
{
    Trie* curr = root;          // take a temp node with address of root
    for(int i=0; i<str.length(); i++) // traverse through the charecters of the string
    {
        int key = str[i] - 'a';   // find corresponding next path
        if(curr -> next[key] == NULL) // if no next path exists
            curr -> next[key] = CreateTrie(str[i], false);  // create a new path
        curr = curr -> next[key]; // go deeper.
    }
    curr -> end++;                // the last node is marked as "last node"
}
//------------------------------------------------------------------------------

//-------------- Function to display all the words in Trie ---------------------
void displayTrie(struct Trie* root, char curr[], int level) // function to view all the words in the trie
{
    if(root -> end > 0)   // if the root is marked as the end
    {
        curr[level] = '\0';  // terminate the string and print result
        cout << curr <<  " ";
    }
    for(int i=0; i<26; i++)   // explore all paths
    {
       if(root->next[i] != NULL)  // if there is a path
        {
            curr[level] = i + 'a';  // add the corresponding value of the path to the running string
            displayTrie(root->next[i], curr, level + 1);  // recurese with the next node and next level
        }
    }
}
//------------------------------------------------------------------------------

//---------------------- Function to search word in Trie -----------------------
bool search(struct Trie* root, string word) // function to search a word in a Trie
{
    Trie* curr = root;
    for(int i=0; i<word.length(); i++)    // traverse each charecter of the word
    {
        int key = word.at(i) - 'a';       // next path to take based on the charecter
        if(curr -> next[key] != NULL)     // if a path exists
            curr = curr -> next[key];     // traverse to that path
        else
            return false;                 // if the expected path is not met the word is not present
    }
    return (curr != NULL && curr -> end > 0); // if the word is exhausted and no terminating node is found return false else return true
}
//------------------------------------------------------------------------------

//------------------------ Trie Helper Function --------------------------------
void TrieFunction(struct Trie* root)
{
    vector<string> input;
    input.push_back("aba");
    input.push_back("abc");
    input.push_back("ab");
    input.push_back("bab");
    for(int i=0; i<input.size(); i++)     // add strings to trie
    {
        addTrie(root, input[i]);
    }
    char curr[20];
    displayTrie(root, curr, 0);           // display all elements of trie

    if(search(root, "abc"))               // find if the word exists or not
    {
        cout << "word hello exists";
    }
    else
        cout << "word hello doesn't exist.";
}
//------------------------------------------------------------------------------
int main()
{
    Trie* root = CreateTrie('$', false);
    TrieFunction(root);
    return 0;
}
