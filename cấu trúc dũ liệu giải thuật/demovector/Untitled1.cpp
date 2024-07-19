#include<cstdio>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
class TrieNode{

    private:

        TrieNode *children[128];
        bool isEndOfWord;
    public:

        TrieNode(){
            for(int i = 0; i < 128; i++){

                children[i] = NULL;
            }
            isEndOfWord = false;
        }

        bool checkNull(char temp){
            cout<<"\nIn check "<<temp<<" "<<(temp - 'a')<<" \n";
            if(children[temp - 'a'] == NULL){

                return true;
            }
            else{

                return false;
            }
        }

        void setNode(char temp){
            cout<<"Setting node \n";
            children[temp - 'a'] = new TrieNode();
        }

        TrieNode *getNode(char temp){ // tra ve null

            return children[temp - 'a'];
        }

        void setEndWord(){

            this->isEndOfWord = true;//nho ki tu cuoi
        }

        bool getEndWord(){

            return this->isEndOfWord;
        }

        void insert(TrieNode*, string);
        bool search(TrieNode*, string);

};

void TrieNode::insert(TrieNode *root, string key){

    TrieNode *crawl = root;
    for(int i = 0;i < (int) (key.size()); i++){
        cout<<"TEST null check key is "<<key[i]<<endl;
        if(crawl->checkNull(key[i])){
            cout<<"null check key is "<<key[i]<<endl;
            crawl->setNode(key[i]);
            crawl = crawl->getNode(key[i]);

            if(key[i + 1] == '\0'){
                cout<<"In setting end word\n";
                if(crawl->getEndWord()){

                    cout<<"Word already exists";
                }
                else{

                    crawl->setEndWord();
                    cout<<"End word setted "<<crawl->getEndWord()<<endl;
                }
            }
        }
        else{

            if(key[i + 1] == '\0'){
                cout<<"In setting end word\n";
                if(crawl->getEndWord()){

                    cout<<"Word already exists";
                }
                else{

                    crawl->setEndWord();
                    cout<<"End word setted\n";
                }
            }
            else{

                crawl = crawl->getNode(key[i]); 
            }
        }
    }
}

bool TrieNode::search(TrieNode *root, string key){
    TrieNode *crawl = root;
    for(int i = 0; i < (int) (key.size()); i++){
        if(crawl->checkNull(key[i])){
            return false;
        }
        crawl = crawl->getNode(key[i]);
    }
    return crawl->getEndWord();
}

int main(){
    TrieNode *root = new TrieNode();
    cout<<"starting"<<endl;
    root->insert(root, "hello");
    cout<<"first added"<<endl;
    root->insert(root, "anna");
     root->insert(root, "12");
    root->insert(root, "anni");
     root->insert(root, "1234");
     root->insert(root, "123");

    cout<<"words added"<<endl;
    cout << root->search(root, "hello") << endl;  // 1
    cout << root->search(root, "anny") << endl;
    cout << root->search(root, "12") << endl;

}