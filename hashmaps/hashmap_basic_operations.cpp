/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
using namespace std;
#include<unordered_map>
#include<string>
template <typename V> 

class MapNode{
    public:
    std::string key;
    V value;
    MapNode *next;
    MapNode(string key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;
    }
};

class ourmap{
    MapNode<V>**buckets;
    int numBuckets;
    int size;
    int getBucketIndex(string key){
        
        // for hashcode
        int hashcode=0;
        int currCoeff = 1;
        for(int i = key.length()-1;i>=0;i--){
            hashcode += key[i]*currCoeff;
            hashcode = hashcode % numBuckets;
            currCoeff*=37;
            currCoeff= currCoeff % numBuckets;
        }
        
        return hashcode%numBuckets;
    }
    
    void rehash(){
        MapNode<V>**temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets*=2;
        size=0;
        for(int i = 0;i<oldBucketCount;i++){
            MapNode<V>*head=temp[i];
            while(head!=NULL){
                string key = head->key;
                V value= head->value;
                insert(key,value);
                head = head->next;
            }
        } 

        for(int i=0;i<oldBucketCount;i++){
            MapNode<V>*head=temp[i];
            delete head;
        }
        delete [] temp;
    }
    public:
    ourmap(){
        size=0;
        numBuckets=5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i = 0;i<numBuckets;i++){
            delete buckets[i];
        }
        delete [] buckets;
    }
    
    int getSize(){
        return size;
    }
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    
    void insert(string key,V value){
        // get bucket index;
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
        }
        head = buckets[bucketIndex];
        MapNode<V> *newnode = new MapNode<V>(key,value);
        newnode->next = head;
        head = newnode;
        size++;

        double loadFactor = (1.0*size)/numBuckets;
        if(loadFactor>0.7){
            rehash();
        } 
    }
    
    V removeValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while(head!=NULL){
            if(head->key == key){
                if(prev==NULL){
                    buckets[bucketIndex] = head->next;
                }else
                prev->next = head->next;
                head->next = NULL;
                V value = head->value;
                delete head;
                size--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};

int main()
{
    
    return 0;
}
