struct Node
{
    int data;
    Node* left;
    Node* right;
};

void mirror(Node* root)
{
    if (root == NULL)
        return;

    // Swap children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Mirror left subtree
    mirror(root->left);

    // Mirror right subtree
    mirror(root->right);
}

//INSERTION BST BY HEAP
Node* insert(Node* root, float value)
{
    Node* newNode = new Node(value);

    if (root == NULL)
        return newNode;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Node* temp = queue[front++];

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
        {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
        {
            queue[rear++] = temp->right;
        }
    }

    return root;
}
//MIRROR
void mirror(Node* root)
{
    if (root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}
