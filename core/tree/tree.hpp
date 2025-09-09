#include <iostream>
#include <queue>
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
    node = NULL;
}
template <class T>
void insert(treeNode<T>*& node, T val){
    if(node == NULL) node = new treeNode<T>(val);
    if(node->value > val)insert(node->left, val);
    if(node->value < val)insert(node->right, val);
}
template <class T>
class AvlTree;
template <class T>
class AvlNode{
    T element;
    AvlNode* left;
    AvlNode* right;
    int height;
    public:
    const T val() const {return element;}
    const AvlNode<T>* lt() const {return left;}
    const AvlNode<T>* rt() const {return right;}
    AvlNode<T>* lt()  {return left;}
    AvlNode<T>* rt()  {return right;}
    AvlNode(
        const T& theElement, 
        AvlNode* lt = NULL, 
        AvlNode* rt = NULL, 
        int h = 0
    ): element(theElement), left(lt), right(rt), height(h) {}
    friend class AvlTree<T>;
};
template <class T>
class AvlTree{
    public:
    // return the height of node t, or -1, if NULL
    int height(AvlNode<T>*) const;
    void insert(const T&, AvlNode<T>*&) const;
    void rotateWithLeftChild(AvlNode<T>*&) const;
    void rotateWithRightChild(AvlNode<T>*&) const;
    void doubleWithLeftChild(AvlNode<T>*&) const;
    void doubleWithRightChild(AvlNode<T>*&) const;
    void deleteTree(AvlNode<T>*&) const;
};
template <class T>
int AvlTree<T>::height(AvlNode<T>* t) const{
    return t == NULL ? -1 : t->height;
}
template <class T>
void AvlTree<T>::insert(const T& x, AvlNode<T>*& t) const {
    //std::cout << " insertion starts: " << x <<" \n";
    if(t == NULL){
        //std::cout  << " new insertion\n";
        t = new AvlNode<T>(x);
    }
    else if(x < t->element){
        //std::cout << " left insertion\n";
        insert(x, t->left);
        if(height(t->left) - height(t->right) == 2){
            //std::cout << " imbalance detected\n";
            if(x < t->left->element){
                //std::cout << " left left imbalance\n";
                rotateWithLeftChild(t);
            } 
            else {
                //std::cout << " left right imbalance\n";
                doubleWithLeftChild(t);
            }
        }
    }
    else if(x > t->element){
        //std::cout << " right insertion\n";
        insert(x, t->right);
        if(height(t->right) - height(t->left) == 2){
            //std::cout << " imbalance detected\n";
            if(x > t->right->element){
                //std::cout << " right right imbalance\n";
                rotateWithRightChild(t);
            } 
            else {
                //std::cout << " right left imbalance\n";
                doubleWithRightChild(t);
            }
        }
    }
    else ; //duplicate do nothing
    //std::cout << " setting height of " << t->element << "\n";
    t->height = std::max(height(t->left), height(t->right)) + 1;
}
template <class T>
void AvlTree<T>::rotateWithLeftChild(AvlNode<T>*& k2) const {
    AvlNode<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), k2->height);
    k2 = k1;
}
template <class T>
void AvlTree<T>::rotateWithRightChild(AvlNode<T>*& k2) const {
    AvlNode<T>* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->right), k2->height);
    k2 = k1;
}
template <class T>
void AvlTree<T>::doubleWithLeftChild(AvlNode<T>*& k3) const {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}
template <class T>
void AvlTree<T>::doubleWithRightChild(AvlNode<T>*& k3) const {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}
template <class T>
void AvlTree<T>::deleteTree(AvlNode<T>*& t) const {
    if(t == NULL)return;
    deleteTree(t->left);
    deleteTree(t->right);
    delete t;
    t = NULL;
}
