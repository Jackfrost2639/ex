#include <iostream>

using namespace std;

typedef struct node{
    int item;
    node *next;
}node;

void printLL(node *head)
{//TODO : print all numbers in LL
    while(head != NULL)
    {
        cout << head->item << ' ';
        head = head->next;
    }
}

int main()
{
    
    node *head = NULL;
    int N, M, number;
    cin >> N >> M;
    
    for(int i=0; i<N; i++)
    {
        cin >> number;
        node *temp = head;
        if(head == NULL || head->item > number)
        {
            node *newhead = new node;
            newhead->item = number;
            newhead->next = head;
            head = newhead;
        }
        else
        {
            while(temp->next != NULL && number > temp->next->item)
            {
                temp = temp->next;
            }

            node *newnode = new node;
            newnode->item = number;
            newnode->next = temp->next;
            temp->next = newnode;
        }

    }

    printLL(head);

        
    for(int i =0; i<M; i++)
    {
        int toDelete;
        cin >> toDelete;

        // Delete the number & print
        node *temp = head;

            
        while(temp->next != NULL)
        {
            if(temp->next->item == toDelete)
            {
                temp->next = temp->next->next;
                continue;
            }
            temp = temp->next;
        }
            
        if(head->item == toDelete)
        {
        head = head->next;
        }
            
        printLL(head);
    }
}