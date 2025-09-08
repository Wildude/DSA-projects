#include <iostream>
template <class T>
struct treeNode {
    treeNode* left;
    treeNode* right;
    T value;
    treeNode(
        treeNode* lt = NULL,
        treeNode* rt = NULL
    ):left(lt), right(rt) {}
    treeNode(
        T val, 
        treeNode* lt = NULL,
        treeNode* rt = NULL
    ): value(val), left(lt), right(rt){}
};
template <class T>
void inorder(treeNode<T>* node, std::ostream& os = std::cout){
    if(node == NULL)return;
    inorder(node->left, os);
    os << node->value ;
    inorder(node->right, os);
}
template <class T>
void preorder(treeNode<T>* node, std::ostream& os = std::cout){
    if(node == NULL)return;
    os << node->value;
    preorder(node->left, os);
    preorder(node->right, os);
}
template <class T>
void postorder(treeNode<T>* node, std::ostream& os = std::cout){
    if(node == NULL)return;
    postorder(node->left, os);
    postorder(node->right, os);
    os << node->value;
}
template <class T>
void eraseTree(treeNode<T>* node){
    if(node == NULL)return;
    eraseTree(node->left);
    eraseTree(node->right);
    delete node;
}
