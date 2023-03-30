#include <iostream>
using std::cout;
using std::endl;

void TowerOfHanoi(int n,char source,char desti,char auxi)   //a source,b destination, c auxiliary tower
{
    if (n == 1)
    {
        cout << "Move disk from tower '" << source << "' to tower '" << desti << "'" << endl;
        return;
    }

    TowerOfHanoi(n-1,source,auxi,desti);
    cout << "Move disk from Tower '" << source << "' to tower '" << desti << "'" << endl;
    TowerOfHanoi(n-1,auxi,desti,source);
}

int main()
{
    TowerOfHanoi(3,'S','D','A');
}
/*

void deleteAtIndex(Node* &Node1,int index)
{
    int length = lengthLL(Node1);
    if (index < 0 && index >length)
    {
        std::cout << "\nIndex out of range for deletion.\n";
        return;
    }
    if (index == 0)
    {
        deleteAtHead(Node1);
        return;
    }

    Node* ptemp = Node1;
    int k = 1;
    while (k < index)
    {
        //for middle and last index element;
        k++;
        ptemp = ptemp->next;
    }
    Node* temp = ptemp->next;
    ptemp->next = temp->next;
    // temp->next = NULL;
    delete temp;
}

*/