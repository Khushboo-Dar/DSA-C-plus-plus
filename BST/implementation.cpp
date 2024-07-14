#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minVal(Node* root) {
    Node* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteNODE(Node* root, int val)
{
    //base case
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        // 0 child
        if(root->left==NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }


        //1child  

        //left child
        if(root->left!=NULL  && root->right ==NULL)
        {
            Node * temp=root->left;
            delete root;
            return temp;

        }
        //right child
        if(root->left==NULL  && root->right !=NULL)
        {
            Node * temp=root->right;
            delete root;
            return temp;

        }

        //2 children
         if(root->left !=NULL && root->right !=NULL)
         {
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteNODE(root->right,mini);
            return root;
         }


    }
    else if(root->data> val)
    {
        root->left=deleteNODE(root->left,val);
        return root;
    }
    else{
        root->right=deleteNODE(root->right,val);
        return root;
    }

}



int main() {
    Node* root = NULL;
    cout << "Enter data to create BST (end input with -1):" << endl;
    takeInput(root);

    cout << "Print the BST:" << endl;
    levelOrderTraversal(root);
    cout << "Min val is: " << minVal(root)->data << endl;
    cout << "Max val is: " << maxVal(root)->data << endl;
    
    return 0;
}
