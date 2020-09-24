#include<bits/stdc++.h>
using namespace std;

class BST{
    struct node{
        int data;
        struct node* child[2];
    }*root;
    struct node* newNode(int data){
        struct node *ptr = new node;
        ptr->data = data;
        ptr->child[0] = NULL;
        ptr->child[1] = NULL;
        return ptr;
    }
    void viewTree(struct node* ptr, int indent){
        if(ptr){
            if(indent){
                std::cout << std::setw(indent) << ' ';
            }
            cout << ptr->data << "\n";
            if(ptr->child[0])viewTree(ptr->child[0],indent-1);
            if(ptr->child[1])viewTree(ptr->child[1],indent+1);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void insert(int data){
        if(root == NULL){
            root = newNode(data);
            return;
        }
        struct node *ptr = root;
        while(ptr!=NULL){
            if(ptr->data >= data){
                if(ptr->child[0])ptr = ptr->child[0];
                else{
                    ptr->child[0] = newNode(data);
                    break;
                }
            }else{
                if(ptr->child[1])ptr = ptr->child[1];
                else{
                    ptr->child[1] = newNode(data);
                    break;
                }
            }
        }
    }
    void displayTree(){
        // int indent = 0;
        // struct node* ptr = root;
        // while(ptr){
        //     ptr = ptr->child[0];
        //     indent++;
        // }
        // viewTree(root,indent);
        postorder(root);
    }
    void postorder(struct node *p)
    {
        int height = getHeight(p) * 2;
        for (int i = 0 ; i < height; i ++) {
            printRow(p, height, i);
        }
    }
    void printRow(const Node *p, const int height, int depth)
    {
        vector<int> vec;
        getLine(p, depth, vec);
        cout << setw((height - depth)*2); // scale setw with depth
        bool toggle = true; // start with left
        if (vec.size() > 1) {
                for (int v : vec) {
                        if (v != placeholder) {
                                if (toggle)
                                        cout << "/" << "   ";
                                else
                                        cout << "\\" << "   ";
                        }
                        toggle = !toggle;
                }
                cout << endl;
                cout << setw((height - depth)*2);
        }
        for (int v : vec) {
                if (v != placeholder)
                        cout << v << "   ";
        }
        cout << endl;
    }

};

int main(){
    BST tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    tree.insert(7);
    tree.insert(5);
    tree.insert(8);
    tree.displayTree();
}