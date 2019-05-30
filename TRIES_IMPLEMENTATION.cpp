#include <bits/stdc++.h>
using namespace std;

struct node{
    node* alphabet[26];
    bool isEndOfWord;
};

node* newNode(){
    node* temp=new node;
    for(int i=0;i<26;i++){
        temp->alphabet[i]=NULL;
    }
    temp->isEndOfWord=false;
    return temp;
}
node* root=newNode();
void insert(node* root,string s){
    node* temp=root;
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(temp->alphabet[index]==NULL)
            temp->alphabet[index]=newNode();
        temp=temp->alphabet[index];   
    }
    temp->isEndOfWord=true;
}

bool search(node* root, string s){
    node* temp=root;
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(temp->alphabet[index]==NULL)
            return false;
            
        temp=temp->alphabet[index];    
    }
    if(temp->isEndOfWord==true) return true;
    
    else return false;
}

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    root=newNode();
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        string s1;
	        cin>>s1;
	        insert(root,s1);
	    }
	    string s2;
	    cin>>s2;
	   cout<<search(root,s2)<<endl;
	}
	return 0;
}