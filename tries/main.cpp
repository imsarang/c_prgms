/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
#include<string>

class TrieNode{
    public:
    int data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        isTerminal = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
  TrieNode *root;
  public:
  Trie(){
      root=new TrieNode('\0');
  }
  void insertWordHelper(TrieNode *root,string word){
    //   base case
    if(word.size() == 0){
        root->isTerminal = true;
        return;
    }
    
    // small calculation
    int index = word[0]-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode(word[0]);
        root->children[index] = child;
    }
    
    // recursive call
    insertWordHelper(child,word.substr(1));
  }
  
  void insertWord(string word){
      insertWordHelper(root,word);
  }
  
  bool searchWordHelper(TrieNode *root,string word){
      int index = word[0]-'a';
      if(root->children[index]==NULL){
          return false;
      }
      if(word.size()==1){
          return root->children[index]->isTerminal;
      }
      return searchWordHelper(root->children[index],word.substr(1));
  }
  
  bool searchWord(string word){
      return searchWordHelper(root,word);
  }

  void removeWord(TrieNode*root,string word){
    // Base case
    if(word.size()==0){
        root->isTerminal = false;
        return;
    }

    // small calculation
    TrieNode *child;
    int index = word[0] - 'a';
    if(root->children[index]!=NULL){
        child = root->children[index];

    }
    else{
        // word not found
        return;
    }
    removeWord(child,word.substr(1));

    // remove child node if useless
    if(child->isTerminal==false){
        for(int i=0;i<26;i++){
            if(child->children[i]!=NULL)
            return;
        }
        delete child;
        root->children[index] = NULL;
    }
  }
  void romoveWord(string word){
    removeWord(root,word);
  }
};

int main()
{
    

    return 0;
}
