#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next = nullptr;

    Node(int x) : data(x) {}
};

class LinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length = 0;
public:
    void print() {

        for (Node *cur = head; cur; cur = cur->next) {
            cout << cur->data << " ";
        }
        cout << endl;
    }

    void insert_end(int val) {
        Node *node = new Node(val);

        if (head == nullptr) {
            head = node;
            tail = head;
        } else {
            tail->next = node;
            tail = node;
        }
        length++;
    }

    Node *get_nth(int n) {
        int cnt = 1;
        for (Node *cur = head; cur; cur = cur->next) {
            if (cnt == n)
                return cur;
            cnt++;
        }

        return nullptr;
    }

    int search(int item) {

        int idx = 0;
        for (Node *cur = head; cur; cur = cur->next) {
            if (cur->data == item)
                return idx;
            idx++;
        }
        return -1;
    }

    int improve_search(int item){
        Node * prv= nullptr;
        int idx=0;
        for(Node * cur =head ; cur; cur = cur->next , idx++){

            if (cur->data==item){
                if (cur!=head) {
                    swap(cur->data, prv->data);
                }
                return idx;
            }
            prv=cur;
        }
        return -1;
    }





};


/**************** Solution start from here ***********************/

int main() {
 
    LinkedList list;

    for (int i = 0; i < 7; i++) {
        list.insert_end(i + 5 * i);
    }
    list.print();
    cout << list.improve_search(0)<<endl;
    list.print();


}
