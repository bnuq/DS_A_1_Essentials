/*
* Geeks For Geeks 에 있던 문제, Binary Tree 의 Node 를 출력하는 데 Spiral Order 로 출력
* 왼쪽으로 갔다가 오른쪽으로 갔다가 하면서, 위에서부터 아래까지 모든 노드를 출력하는 문제
* 
* Recursion 을 이용해서 어떻게 푸는가?
* 각 Node 의 Level 을 먼저 인식하고, Tree 의 각 Level 을 출력한다고 생각
* Root 노드에서 Level l 을 출력한다 => 그 및 노드에서 Level l-1 을 출력한다
* 이런 식으로 문제를 작게 줄일 수 있다 => 결국 Level 0 에서 자기자신을 출력하는 데 까지 문제를 작게 만든다
*/

// C++ program for recursive level 
// order traversal in spiral form
#include <vector>
#include <iostream>
using namespace std;

// A binary tree node has data, 
// pointer to left child and a
// pointer to right child 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// Function prototypes 
void printGivenLevel(struct node* root,
    int level, int ltr);
int height(struct node* node);
struct node* newNode(int data);

// Function to print spiral traversal of a tree
void printSpiral(struct node* root)
{
    int h = height(root);
    int i;

    // ltr -> Left to Right. If this variable
    // is set,then the given level is traversed 
    // from left to right. 
    bool ltr = false;
    for (i = 1; i <= h; i++)
    {
        printGivenLevel(root, i, ltr);

        // Revert ltr to traverse next 
        // level in opposite order
        ltr = !ltr;
    }
}

// Print nodes at a given level 
void printGivenLevel(struct node* root,
    int level, int ltr)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";

    else if (level > 1)
    {
        if (ltr)
        {
            printGivenLevel(root->left,
                level - 1, ltr);
            printGivenLevel(root->right,
                level - 1, ltr);
        }
        else
        {
            printGivenLevel(root->right,
                level - 1, ltr);
            printGivenLevel(root->left,
                level - 1, ltr);
        }
    }
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else
    {

        // Compute the height of each subtree 
        int lheight = height(node->left);
        int rheight = height(node->right);

        // Use the larger one 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

// Helper function that allocates a new 
// node with the given data and NULL left
// and right pointers. 
struct node* newNode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return (newnode);
}

// Driver code
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of "
        "binary tree is \n");

    printSpiral(root);

    return 0;
}

// This code is contributed by samrat2825