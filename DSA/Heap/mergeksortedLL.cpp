#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

class compare{
public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data > b->data;
    }
};


Node<int>* mergeKLists(vector<Node<int>*> &v)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> pq;
    int k = v.size();
    for (int i = 0;i < k;i++){
        if (v[i] != NULL)
            pq.push(v[i]);
    }
    Node<int>* head = NULL;
    Node<int>* tail = head;
    while (pq.size()){
        Node<int>* temp = pq.top();
        pq.pop();
        if (head == NULL){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
        if (temp->next != NULL){
            pq.push(temp->next);
        }
    }

    if (tail != NULL)
        tail->next = NULL;
    return head;
}
