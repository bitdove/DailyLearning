


```cpp
struct DListNode{
    int key;
    int value;
    DListNode* next;
    DListNode* prev;
    DListNode() : key(0), value(0), next(nullptr), prev(nullptr) {}
    DListNode(int _key, int _value) : key(_key), value(_value), next(nullptr), prev(nullptr) {}
};

class LRUCache{
public:
    LRUCache(int _capacity) : capacity(_capacity), used(0) {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(!cache.count(key)){
            return -1;
        }
        DListNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value){
        if(!cache.count(key)){
            DListNode* node = new DListNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++used;
            if(used > capacity){
                DListNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                removed = nullptr;
                --used;
            }
        }
        else{
            DListNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

private:
    int capacity;
    int used;
    std::unordered_map<int, DListNode*> cache;
    DListNode* head;
    DListNode* tail;

    void addToHead(DListNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DListNode* node){
        removeNode(node);
        addToHead(node);
    }

    DListNode* removeTail(){
        DListNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};
```