#include <bits/stdc++.h>
using namespace std;

//------------------------------- Trie Structure -------------------------------
struct Trie{
    char value;
    int end = 0;
    struct Trie* next[26];
};
//------------------------------------------------------------------------------

//----------------------------- Create New Node of Trie ------------------------
struct Trie* CreateTrie(char ch, bool isEnd)
{
    Trie* Node = new Trie;
    Node -> value = ch;
    if(isEnd)
        Node -> end += 1;
    for(int i=0; i<26; i++)
        Node -> next[i] = NULL;
    return Node;
}
//------------------------------------------------------------------------------

//------------------------------ Add String to Trie ----------------------------
void addTrie(struct Trie* root, string str)
{
    Trie* curr = root;
    for(int i=0; i<str.length(); i++)
    {
        int key = str[i] - 'a';
        if(curr -> next[key] == NULL)
            curr -> next[key] = CreateTrie(str[i], false);
        curr = curr -> next[key];
    }
    curr -> end++;
}
//------------------------------------------------------------------------------

//------------------------ Check if the Trie node is a leaf --------------------
bool isLeaf(struct Trie* root)
{
    for(int i=0; i<26; i++) // if all the next paths are empty
    {
        if(root -> next[i])
            return false;
    }
    return true;
}
//------------------------------------------------------------------------------

//---------------- function to generate autocompleted words -------------------
vector<string> ans;
void autocomplete(struct Trie* root, string query, vector<string> ans)
{
    static int max_complete = 3;  // limit autocomplete words
    if(root -> end > 0)            // if the Trie root is the end of the word
    {
        ans.push_back(query);      // pushback the generated query string to ans
        max_complete--;            // decrement limit variable
    }
    if(max_complete == 0 || isLeaf(root)) // if limit is reached or you reach a leaf node
        return;                    // return
    for(int i=0; i<26; i++)        // lexographically look for the next path
    {
        if(root -> next[i])        // go to the first valid path
        {
            query.push_back('a'+ i);  // add the path value to the running string
            autocomplete(root -> next[i], query , ans); // recurse to the next path
            query.pop_back(); // popout the path value you added to add the next path value
        }
    }
}
//------------------------------------------------------------------------------

//------------ Check if the query string matches any prefix --------------------
int checkPrifix(struct Trie* root, string query, vector<string> ans)
{
    Trie* curr = root;
    int n = query.length();
    for(int i=0; i<n; i++)            // check if the query already exists in the trie by iterating through the charecters one by one.
    {
        int key = query[i] - 'a';     // key to the next path based on the charecter
        if(curr -> next[key] == NULL) // if there is no path
            return 0;                 // prefix does not exist
        curr = curr -> next[key];     // take the next Trie Node path
    }
    bool isWord = (curr -> end > 0);   // check if the node you ended up on is end of a word
    bool isEnd = isLeaf(curr);    // check if the node you ended up on is the leaf node
    if(isWord && isEnd)             // if it is a word and the leaf
    {
        ans.push_back(query);         // just push the prefix in ans.
        return 1;                     // and return
    }
    if(!isEnd)                          // if there is a path
    {
       autocomplete(curr, query, ans);   // check for further words in that path
    }
    return 0;
}
//------------------------------------------------------------------------------
void TrieFunction(struct Trie* root)
{
    vector<string> input;
    input.push_back("aba");
    input.push_back("abc");
    input.push_back("ab");
    input.push_back("bab");
    for(int i=0; i<input.size(); i++)
    {
        addTrie(root, input[i]);
    }
    string query;
    query ="bc";
    int response = checkPrifix(root, query, ans);
    if(response == 0)
    {
        ans.push_back("");
    }
    for(string s : ans)
    {
        cout << s << " ";
    }
}
int main()
{
    Trie* root = CreateTrie('$', false);
    TrieFunction(root);
    return 0;
}
