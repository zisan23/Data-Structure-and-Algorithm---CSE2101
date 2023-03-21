/*
 *Zisan-23
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left_child;
    Node *right_child;

    Node()
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};

class BinarySearchTree
{
public:
    // Node* root = NULL;
    Node *root;

    BinarySearchTree()
    {
        root = NULL;
    }

private:
    // insert value in BST

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
        {
            node = new Node(value);
            return node;
        }

        if (value <= node->data)
        {
            node->left_child = insert(node->left_child, value);
        }

        else if (value > node->data)
        {
            node->right_child = insert(node->right_child, value);
        }

        return node;
    }

    Node *minValue(Node *node)
    {
        Node *current = node;

        while (current and current->left_child != NULL)
        {
            current = current->left_child;
        }

        return current;
    }

    Node *deleteNode(Node *node, int value)
    {
        if (node == NULL)
        {
            return node;
        }

        if (value < node->data)
        {
            node->left_child = deleteNode(node->left_child, value);
        }

        else if (value > node->data)
        {
            node->right_child = deleteNode(node->right_child, value);
        }

        else
        { // if eqaul

            if (node->left_child == NULL and node->right_child == NULL)
            {
                free(node);
                return NULL;
            }
            else if (node->left_child == NULL)
            {
                Node *temp = node->right_child;
                free(node);
                return temp;
            }

            else if (node->right_child == NULL)
            {
                Node *temp = node->left_child;
                free(node);
                return temp;
            }

            Node *temp = minValue(node->right_child);

            node->data = temp->data;

            node->right_child = deleteNode(node->right_child, temp->data);
        }

        return node;
    }

    Node *Search(Node *root, int value)
    {
        if (root == NULL or root->data == value)
        {
            return root;
        }

        if (value < root->data)
        {
            return Search(root->left_child, value);
        }

        else if (value > root->data)
        {
            return Search(root->right_child, value);
        }
    }

    void inorder(Node *node)        // left - root - right
    {
        if (node == NULL)
        {
            return;
        }

        inorder(node->left_child);
        cout << node->data << " ";
        inorder(node->right_child);
    }

    void preorder(Node *node)       //root - left - right
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << " ";
        preorder(node->left_child);
        preorder(node->right_child);
    }

    void postorder(Node *node)      //left - right - root
    {
        if (node == NULL)
        {
            return;
        }
        postorder(node->left_child);
        postorder(node->right_child);
        cout << node->data << " ";
    }

    // Level Order Traversal

    int height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        else
        {
            int lDepth = height(node->left_child);
            int rDepth = height(node->right_child);

            if (lDepth > rDepth)
            {
                return (lDepth + 1);
            }
            else
            {
                return (rDepth + 1);
            }
        }
    }

    // To print a specific level

    void printAtGivenLevel(Node *node, int level)
    {
        if (node == NULL)
        {
            return;
        }
        if (level == 1)
        {
            cout << node->data << " ";
        }
        else if (level > 1)
        {
            printAtGivenLevel(node->left_child, level - 1);
            printAtGivenLevel(node->right_child, level - 1);
        }
    }

    // To print all the level sequentially

    void printLevelOrder(Node *node)
    {
        int h = height(node);

        int i;

        for (i = 0; i <= h; i++)
        {
            printAtGivenLevel(node, i);
            cout << endl;
        }
    }

    void printLeafNodes(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        if (node->left_child == NULL and node->right_child == NULL)
        {
            cout << node->data << " ";
            return;
        }

        if (node->left_child != NULL)
        {
            printLeafNodes(node->left_child);
        }
        if (node->right_child != NULL)
        {
            printLeafNodes(node->right_child);
        }
    }

    void printNonLeafNode(Node *node)
    {
        if (node == NULL or (node->left_child == NULL and node->right_child == NULL))
        {
            return;
        }

        if (node->left_child != NULL or node->right_child != NULL)
        {
            cout << node->data << " ";
        }

        printNonLeafNode(node->left_child);
        printNonLeafNode(node->right_child);
    }

    int totalNodes(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        else
        {
            int x = totalNodes(node->left_child);
            int y = totalNodes(node->right_child);

            return x + y + 1;
        }
    }

    Node *ClearBST(Node *node)
    {

        if(node == NULL){
            return NULL;
        }

        
        ClearBST(node->left_child);

        ClearBST(node->right_child);

        // cout << node->data << endl;
        
        Node *temp;
        temp = node;
        free(temp);
        node = NULL;

        return node;
    }

    int totalLeafs(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        if (node->left_child == NULL and node->right_child == NULL)
        {
            return 1;
        }

        return totalLeafs(node->left_child) + totalLeafs(node->right_child);
    }

    int totalFullNode(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        if (node->left_child == NULL and node->right_child == NULL)
        {
            return 0;
        }

        return totalFullNode(node->left_child) + totalFullNode(node->right_child) + (node->left_child and node->right_child) ? 1 : 0;
    }

    Node *findMax(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        else if (node->right_child == NULL)
        {
            return node;
        }
        else
        {
            return findMax(node->right_child);
        }
    }

public:
    void addNode(int value)
    {
        root = insert(root, value);
    }

    int getMinValue()
    {
        Node *current = root;

        while (current and current->left_child != NULL)
        {
            current = current->left_child;
        }

        return current->data;
    }

    void DeleteNode(int value)
    {
        root = deleteNode(root, value);
    }

    void printPreOrder()
    {
        preorder(root);
    }

    void printInOrder()
    {
        inorder(root);
    }

    void printPostOrder()
    {
        postorder(root);
    }

    int Height()
    {
        return height(root);
    }

    void SingleLevelPrint(int level)
    {
        printAtGivenLevel(root, level);
    }

    void AllLevelPrint()
    {
        printLevelOrder(root);
    }

    void AllLeafPrint()
    {
        printLeafNodes(root);
    }

    void AllNonLeafPrint()
    {
        printNonLeafNode(root);
    }

    int NumberOfNodes()
    {
        return totalNodes(root);
    }

    void EmptyBST()
    {
        root = ClearBST(root);
    }

    int NumberOfLeafs()
    {
        return totalLeafs(root);
    }

    int NumberofFullNodes()
    {
        return totalFullNode(root);
    }

    int MaxValue()
    {
        Node* temp = findMax(root);
        return temp->data;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BinarySearchTree t = BinarySearchTree();

    int x;

    while((scanf("%d", &x)) != EOF){
        t.addNode(x);
    }

    t.printPreOrder();

    cout << endl;



    t.printInOrder();

    cout << endl;

    t.printPostOrder();

    cout << endl;

    cout << "Height = " << t.Height() << endl;

    int h = t.Height();

    //t.DeleteNode(20);
    //t.DeleteNode(50);

    

    //t.EmptyBST();
    //t.printPreOrder();
    //cout << endl;

    cout << "Print at Given Level : \n";
    for(int i=0; i<h; i++){
        t.SingleLevelPrint(i+1);
        cout << endl;
    }

    cout << "Print leaf nodes : \n";

    t.AllLeafPrint();

    cout << endl;

    cout << "Print non-leaf nodes : \n";

    t.AllNonLeafPrint();
    cout << endl;

    cout << "Min Value = " << t.getMinValue() << endl;

    cout << "Total Node = " << t.NumberOfNodes() << endl;

    cout << "Max Value = " << t.MaxValue() << endl;

    return 0;
}
