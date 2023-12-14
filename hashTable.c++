#include <iostream>
using namespace std;

struct node
{
    int key;
    node *next;
};

#define max_size 10
node *table[max_size], *temp;

void init();
void Add(int value);
string LookUp(int value);
void Remove(int value);




int main()
{
    init();
    Add(33);
    cout<<LookUp(33);
    Remove(33);
    cout<<LookUp(33);
    Add(33);
    cout<<LookUp(33);
    
    return 0;
}




void init()
{
    for (int i = 0; i < max_size; i++)
    {
        table[i] = NULL;
    }
}

int findIndex(int key)
{
    return key % max_size;
}

void Add(int value)
{
    int index = findIndex(value);
    node *new_node = new node;
    new_node->next = NULL;
    new_node->key = value;
    if (table[index] == NULL)
    {
        table[index] = new_node;
        return;
    }
    temp = table[index];
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

string LookUp(int value)
{
    int index = findIndex(value);
    temp = table[index];
    while (temp != NULL)
    {
        if (temp->key == value)
        {
            return "Is found\n";
        }
        temp = temp->next;
    }
    return "Not found\n";
}

void Remove(int value)
{
    int index = findIndex(value);
    temp = table[index];
    node *pre = NULL;
    while (temp != NULL)
    {
        if (temp->key == value)
        {
            if (pre == NULL)
            {
                table[index] = temp->next;
                free(temp);
                return;
            }
            pre->next = temp->next;
            free(temp);
            return;
        }
        pre = temp;
        temp = temp->next;
    }
    cout << "Error --> Not found!\t";
}