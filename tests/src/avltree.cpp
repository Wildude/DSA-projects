#include "../../core/tree/tree.hpp"
#include <gfx/graphics.h>
#include <iostream>
#include <cmath>
#include <cstring>
/*
each character has (approximately) width 7 and height 10
circles are positioned from their center
*/
void drawNode(const AvlNode<int>* node, int x, int y) {
    if(node == NULL)return;
    std::string thestr = std::to_string(node->val());
    int width = 7 * thestr.length();
    int radius = std::max(width, 10);
    outtextxy(x - radius, y + radius/2 - 5, const_cast<char*>(thestr.c_str()));
    circle(x - radius/2, y + radius/2, radius);
}
void drawBNode(treeNode<int>*& node, int x, int y) {
    if(node == NULL)return;
    std::string thestr = std::to_string(node->value);
    int width = 7 * thestr.length();
    int radius = std::max(width, 10);
    outtextxy(x - radius, y + radius/2 - 5, const_cast<char*>(thestr.c_str()));
    circle(x - radius/2, y + radius/2, radius);
}
void inorderDraw(const AvlNode<int>* root, int x, int y)  {
    if(root == NULL)return;
    if(root->lt())inorderDraw(root->lt(), x - 20, y + 20);
    drawNode(root, x, y);
    if(root->rt())inorderDraw(root->rt(), x + 20, y + 20);
}
void inorderBDraw(treeNode<int>*& root, int x, int y)  {
    if(root == NULL)return;
    if(root->left){
        std::string thestr = std::to_string(root->value);
        int width = 7 * thestr.length();
        int radius = std::max(width, 10);
        line(x - radius/2, y + radius/2, x - 20, y + 20);
        inorderBDraw(root->left, x - 20, y + 20);
    }
    drawBNode(root, x, y);
    if(root->right){
        std::string thestr = std::to_string(root->value);
        int width = 7 * thestr.length();
        int radius = std::max(width, 10);
        line(x + radius/2, y + radius/2, x + 20, y + 20);
        inorderBDraw(root->right, x + 20, y + 20);
    }
}
template <class T> 
void BFS(const AvlNode<T>*& root){
    std::queue<AvlNode<T>*> trav;
    if(root == NULL)return;
    trav.push(root);
    while(!trav.empty()){
        std::cout << trav.front()->val() << ' ';
        if(trav.front()->lt())trav.push(trav.front()->lt());
        if(trav.front()->rt())trav.push(trav.front()->rt());
        trav.pop();
    }
}
void BFSDraw(AvlNode<int>*& root, int x, int y)  {
    if(root == NULL)return;
    struct triple{
        AvlNode<int>* node;
        int x, y;
        triple(AvlNode<int>* n, int x_, int y_):
        node(n), x(x_), y(y_){}
    };
    std::queue<triple> trav;
    trav.push(triple(root, x, y));
    while(!trav.empty()){
        drawNode(trav.front().node, trav.front().x, trav.front().y);
        std::string thestr = std::to_string(root->val());
        int width = 7 * thestr.length();
        int radius = std::max(width, 10);
        if(trav.front().node->lt()){
            line(trav.front().x - radius/2, trav.front().y + radius/2, trav.front().x - 20, trav.front().y + 20);
            trav.push(triple(trav.front().node->lt(), trav.front().x - 20, trav.front().y + 20));
        }
        if(trav.front().node->rt()){
            line(trav.front().x + radius/2, trav.front().y + radius/2, trav.front().x + 20, trav.front().y + 20);
            trav.push(triple(trav.front().node->rt(), trav.front().x + 20, trav.front().y + 20));
        }
        trav.pop();
    }
}
int main(){
    int gd = DETECT, gm, color, angle = 0;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    setbkcolor(WHITE);
    if(gd == DETECT){
        std::cerr << "Graphics driver not detected!" << std::endl;
        return 1;
    }
    int delayer = 0;
    AvlTree<int> intTree;
    AvlNode<int>* intNode = new AvlNode<int>(0);
    int counter = 0;
    while(counter < 10){
        setcolor(RED);
        BFSDraw(intNode, 320, 10);
        counter++;
        intTree.insert(counter, intNode);
        angle += 10;
        delay(500);
        delayer++;
        cleardevice();
    }
    BFSDraw(intNode, 320, 10);
    delay(3000);
    closegraph();
    return 0;
}