#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
    private:
        Node* root;
    public:
        void insert(int value){
            Node* newNode = new Node(value);
            if(root == NULL){
                root = newNode;
            }
            else{
                Node* currentNode = root;
                while(true){
                    if(value < currentNode->value){
                        if(currentNode->left == NULL){
                            currentNode->left = newNode;
                            break;
                        }
                        currentNode = currentNode->left;
                    }
                    else{
                        if(currentNode->right == NULL){
                            currentNode->right = newNode;
                            break;
                        }
                        currentNode = currentNode->right;
                    }
                }
            }            
        }        
        vector<int> BFS(){
            Node* currentNode = root;
            queue<Node*> q;
            vector<int> list;
            q.push(currentNode);
            
            while(q.size()){
                currentNode = q.front();
                q.pop();
                list.push_back(currentNode->value);
                
                if(currentNode->left){
                    q.push(currentNode->left);
                }
                if(currentNode->right){
                    q.push(currentNode->right);
                }
            }
            return list;
        }
        
vector<int> DFSInOrder(){
    vector<int> list;
    DFSInOrder(root, list);
    return list;
}
void DFSInOrder(Node* currentNode, vector<int>& list){
    
    if(currentNode->left)
        DFSInOrder(currentNode->left, list);
    list.push_back(currentNode->value);
        
    if(currentNode->right)
        DFSInOrder(currentNode->right, list);
}

vector<int> DFSPreOrder(){
    vector<int> list;
    DFSPreOrder(root, list);
    return list;
}
void DFSPreOrder(Node* currentNode, vector<int>& list){
    list.push_back(currentNode->value);
    if(currentNode->left)
        DFSPreOrder(currentNode->left, list);
        
    if(currentNode->right)
        DFSPreOrder(currentNode->right, list);
}

vector<int> DFSPostOrder(){
    vector<int> list;
    DFSPostOrder(root, list);
    return list;
}
void DFSPostOrder(Node* currentNode, vector<int>& list){
    
    if(currentNode->left)
        DFSPostOrder(currentNode->left, list);
        
    if(currentNode->right)
        DFSPostOrder(currentNode->right, list);
    list.push_back(currentNode->value);
}
};
//         9
//    4       20
//  1   6  15    170
//  
//DFS-In    = [1,4,6,9,15,20,170]
//DFS-pre   = [9,4,1,6,20,15,170]
//DFS-post  = [1,6,4,15,170,20,9]


int main()
{
    BinaryTree tree;
    tree.insert(9);
    tree.insert(4);
    tree.insert(6);
    tree.insert(20);
    tree.insert(170);
    tree.insert(15);
    tree.insert(1);

    auto bfs = tree.BFS();
    auto inorder = tree.DFSInOrder();
    auto preorder = tree.DFSPreOrder();
    auto postorder = tree.DFSPostOrder();
    
    cout << "BFS           : " ;
    for(auto val : bfs)
        cout << val << " " ;
    cout << endl;
   
    cout << "DFS-PostOrder : " ;
    for(auto val : postorder)
        cout << val << " " ;
    cout << endl;
    
    cout << "DFS-PreOrder  : " ;
    for(auto val : preorder)
        cout << val << " " ;
    cout << endl;
    
    cout << "DFS-InOrder   : " ;
    for(auto val : inorder)
        cout << val << " " ;
    cout << endl;
    
    
    return 0;
}
