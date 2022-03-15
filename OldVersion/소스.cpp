#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


node* bubble_sort_LinkedList_itr(node* head)
{
    int count = 0;
    node* temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }

    node* realHead = head;
    for (int i = 0; i < count; i++) {
        node* prevN = NULL;
        node* curN = realHead;
        node* nextN = realHead->next;

        while (nextN) {
            if (!prevN) {
                if (curN->data > nextN->data) {
                    node* temp = nextN->next;
                    nextN->next = curN;
                    curN->next = temp;

                    realHead = nextN;

                    prevN = nextN;
                    //curN = curN;
                    nextN = temp;
                }
                else {
                    realHead = curN;
                    
                    node* temp = nextN->next;
                    prevN = curN;
                    curN = nextN;
                    nextN = temp;
                }

            }
            else {
                if (curN->data > nextN->data) {
                    node* temp = nextN->next;
                    prevN->next = nextN;
                    nextN->next = curN;
                    curN->next = temp;

                    prevN = nextN;
                    //curN = curN;
                    nextN = temp;
                }
                else {
                    node* temp = nextN->next;
                    prevN = curN;
                    curN = nextN;
                    nextN = temp;
                }
            }
        }
    }

    return realHead;
}

int main() {
    node* head = new node(10);
    head->next = new node(30);
    head->next->next = new node(20);
    head->next->next->next = new node(5);


    node* res = bubble_sort_LinkedList_itr(head);

    int count{ 0 };
    while (res) {
        cout << res->data << endl;
        res = res->next;
        count++;
    }
    cout << count << endl;


}