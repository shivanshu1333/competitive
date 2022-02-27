#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r)
{
    int pi = l;
    int pvt = v[r];
    for (int i = l; i < r; i++)
    {
        if (v[i] < pvt)
        {
            swap(v[i], v[pi]);
            pi++;
        }
    }
    swap(v[pi], v[r]);
    return pi;
}

void quickSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int pi = partition(v, l, r);
        quickSort(v, l, pi - 1);
        quickSort(v, pi + 1, r);
    }
}

int main()
{
    vector<int> v = {4, 6, 9, 8, 7, 2, 0};
    quickSort(v, 0, 6);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}

struct node *insert(struct node *node, int key){
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}