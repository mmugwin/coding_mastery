#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class DoublyLinkedListNode{
    public:
        string key;
        int value;
        DoublyLinkedListNode* prev;
        DoublyLinkedListNode* next;

        // constructor
        DoublyLinkedListNode(string key, int value){
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }

        void removeBindings(){
            if(this->prev != nullptr){
                this->prev->next = this->next;
            }

            if(this->next != nullptr) {
                this->next->prev = this->prev;
            }
            this->next = nullptr;
            this->prev = nullptr;
        }

    private:

};

class DoublyLinkedList{
    public:
        DoublyLinkedListNode* head;
        DoublyLinkedListNode* tail;
    
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void setHeadTo(DoublyLinkedListNode* node){
        if(this->head == node){
            return;
        } else if(this->head == nullptr){
            this->head = node;
            this->tail = node;
        } else if(this->head == this->tail){
            this->tail->prev = node;
            this->head = node;
            this->head->next = this->tail;
        } else{
            if(this->tail == node){
                this->removeTail();
            }
            node->removeBindings();
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
    }

    void removeTail(){
        if(this->tail == nullptr){
            return;
        }
        if(this->tail == this->head){
            this->head = nullptr;
            this->tail = nullptr;
        }
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
    }
};

class LRUCache{
    public:
        unordered_map<string, DoublyLinkedListNode *> cache;
        int maxSize;
        int currentSize;
        DoublyLinkedList mostRecent;

        //constructor
        LRUCache(int maxSize){
            this->maxSize = maxSize>1 ? maxSize : 1;
            this ->currentSize = 0;
            this->mostRecent = DoublyLinkedList();
        }

        // O(1) time | O(1) space
        void insertKeyValuePair(string key, int value){
            if(this->cache.find(key) == this->cache.end()){
                if(this->currentSize == this->maxSize) {
                    this->evictLeastRecent();
                } else {
                    this->currentSize++;
                }
                this->cache[key] = new DoublyLinkedListNode(key, value);
            } else {
                this->replaceKey(key, value);
            }
            this->updateMostRecent(this->cache[key]);
        }

        // O(1) time | O(1) space
        int *getValueFromKey(string key){
            if(this->cache.find(key) == this->cache.end()) {
                return nullptr;
            }
            this->updateMostRecent(this->cache[key]);
            return &this->cache[key]->value;
        }

        // O(1) time | O(1) space
        string getMostRecentKey(){
            if(this->mostRecent.head == nullptr){
                return "";
            }
            return this->mostRecent.head->key;
        }

        // O(1) time | O(1) space
        void evictLeastRecent(){
            string keyToRemove = this->mostRecent.tail->key;
            this->mostRecent.removeTail();
            this->cache.erase(keyToRemove);
        }

        void updateMostRecent(DoublyLinkedListNode* node){
            this->mostRecent.setHeadTo(node);
        }
        
        void replaceKey(string key, int value){
            if(this->cache.find(key) == this->cache.end()) {
                return;
            }
            this->cache[key]->value = value;
        }

};

int main(){
    LRUCache L = LRUCache(3);
    L.insertKeyValuePair("b", 2);
    L.insertKeyValuePair("a", 1);
    L.insertKeyValuePair("c", 3);
    
    std::cout << "Most recent: " << L.getMostRecentKey() << "\n";
    std::cout << "Value from key (a): " << *L.getValueFromKey("a") << "\n";
    std::cout << "New most recent: " << L.getMostRecentKey() << "\n";
    std::cout << "Most recent: " << L.getMostRecentKey() << "\n";

    L.insertKeyValuePair("d", 4);
    std::cout << "Value from key (b): " << L.getValueFromKey("b") << "\n";

    L.insertKeyValuePair("a", 5);
    std::cout << "Value from key (new a): " << *L.getValueFromKey("a") << "\n"; 

    return 0;
}