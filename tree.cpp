#include <iostream>

using namespace std;

typedef struct tree{
    int item;
    tree *rightchild;
    tree *leftchild;
}tree;

tree* Insert(tree* root, int item)
{
    if(root == NULL)
    {
        tree *newtree = new tree;
        newtree->item = item;
        newtree->rightchild = NULL;
        newtree->leftchild = NULL;
        return newtree;
    }

    if(root->item == item)
    {

    }
    else if(root->item < item)
    {
        root->rightchild = Insert(root->rightchild, item);
    }
    else
    {
        root->leftchild = Insert(root->leftchild, item);
    }
    return root;
}

void Search(tree* root, int item)
{
    if(root == NULL)
    {
        return;
    }

    if(root->item == item)
    {
        cout << "Find" << ' ' << item << endl;
    }
    else if(root->item < item)
    {
        Search(root->rightchild, item);
    }
    else
    {
        Search(root->leftchild, item);
    }    
}

tree* Delete(tree* root, int item)
{
    if(root == NULL)
    {
        cout << "No " << item << endl;
        return NULL;
    }

    if(root->item == item)
    {
        if(root->leftchild == NULL && root->rightchild == NULL)
        {   
            return NULL;
        }
        else if(root->leftchild != NULL && root->rightchild == NULL)
        {
            return root->rightchild;
        }
        else if(root->leftchild == NULL && root->rightchild != NULL)
        {
            return root->leftchild;
        }
        else
        {
            int min = extractMin(root->rightchild);
            tree *node = new tree;
            node->item = min;
            node->rightchild = ;
            node->leftchild = ;
        }
    }

    else if(root->item < item)
    {
        root->rightchild = Delete(root->rightchild, item);
    }
    else
    {
        root->leftchild = Delete(root->leftchild, item);
    }
    return root;
}

int extractMin(tree* root)
{
    if(root->leftchild != NULL)
    {
        return extractMin(root->leftchild);
    }
    else
    {
        int min = root->item;
        Delete(root, min);
        return min;
    }
}

int main()
{
    tree *root;

    root = Insert(root, 3); // No Print
    Search(root, 1); // "No 1" or No Print
    Search(root, 3); // "Find 3"

    Delete(root, 3); // "Deleted 3" or "No 3"
    Search(root, 3); // "No 3" or No Print

}