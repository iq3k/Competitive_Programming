struct Node{
    map<char, Node*> childs;
    bool isLast;
};


Node* newNode(){
    Node* p = new Node;
    for(char c='a'; c<='z'; c++){
        p->childs[c] = NULL;
    }
    p->isLast = false;
    return p;
}

struct Node* root = newNode();
void insert(string a){
    Node* cur = root;
    for(int i=0; i<a.size(); i++){
        if(cur->childs[a[i]] == NULL){ // not exist
            cur->childs[a[i]] = newNode();
        }
        cur = cur->childs[a[i]];
    }
    cur->isLast = true;
}

int main(){
    for(int i=1; i<s.size(); i++){
        Node* cur = root;
        // max O(size(a))
        for(int j=i; j>=1; j--){
            if(cur->childs[s[j]] == NULL)
                break;
            
            // if(cur->childs[s[j]]->isLast)
                // do something
            cur = cur->childs[s[j]];
        }
    }
}