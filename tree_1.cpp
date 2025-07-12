#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int data;
    int left;  
    int right;
    int prev;
    int next;

    Node()
    {
        data = 0;
        left = right = -1;
        prev = next = -1;
    }
};

void toList(Node tree[], int index, int& prevIndex, int& headIndex) 
{
    if (index == -1) 
    {
        return;
    }

    toList(tree, tree[index].left, prevIndex, headIndex);

    if (prevIndex == -1) 
    {
        headIndex = index;
    } 
    else 
    {
        tree[prevIndex].next = index;
        tree[index].prev = prevIndex;
    }

    prevIndex = index;

    toList(tree, tree[index].right, prevIndex, headIndex);
}

void printList(Node tree[], int headIndex) 
{
    int i = headIndex;

    while (i != -1) 
    {
        cout << tree[i].data;
        if (tree[i].next != -1) cout << " <-> ";
        i = tree[i].next;
    }
    cout << "\n";
}

int main() {
    Node tree[MAX];

    tree[0].data = 10;
    tree[0].left = 1;
    tree[0].right = 2;

    tree[1].data = 12;
    tree[1].left = 3;
    tree[1].right = 4;

    tree[2].data = 15;

    tree[3].data = 25;

    tree[4].data = 30;
    tree[4].right = 5;

    tree[5].data = 36;

    int prev = -1, head = -1;

    toList(tree, 0, prev, head);

    cout << "Двусвязный список: ";
    printList(tree, head);

    return 0;
}
﻿
