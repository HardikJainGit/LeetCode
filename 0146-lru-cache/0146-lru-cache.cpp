class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next; //DLL

            //constructor 
            Node(int key, int val)
            {
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m; //int is the key and Node* is pointer to that node

    LRUCache(int capacity) 
    {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode)
    {
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode)
    {
        Node* prev = delnode -> prev;
        Node* next = delnode -> next;

        prev -> next = next;
        next -> prev = prev;
    }
    
    int get(int key) 
    {
        if(m.find(key) != m.end())
        {
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);

            //Update that the node is used recently ; attach to the head of the DLL
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        if(m.find(key) != m.end()) //the key pre-exists
        {
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap)
        {
            m.erase(tail -> prev -> key); //erase the LRU node
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next; //recent node
    }
};