# DSA Projects
This repo contains projects built on the foundations of Data structures and algorithms.
## Second publish
This Second publish explores queues and trees in data structure projects.

- **Queues**  
    Implemented using `std::queue` as the underlying container. Queues were utilized for:
    - Breadth first search (BFS) of trees

- **AVL Trees**  
    Adelson-Velskii and Landis trees are binary search trees with a balance condition.
    The balance condition must be easy to maintain, and ensure that the depth of the tree is O(logN).
    The height of the left and right subtrees of every node can differ by at most 1 (empty trees are of height, "-1")
    This makes the tree resist changes in it's depth from insertions and deletions, via rotation.
    AVL trees are used to minimize the depth of a binary tree, which helps in reducing access times.
    Especially in **splay trees** where every access to some node reduces the depth of all subtrees almost by half.

    Implementations made:
    - Insertion
    - Rotation (single and double)

    Expression trees were constructed from postfix expressions. Inorder traversal of these trees was used to convert postfix expressions back to infix notation.

### Source Files
- [AVL tree implementations](tests/src/avltree.cpp)
- [Stack implementations](tests/src/infpos.cpp)
- [Expression Tree Implementation (cpp)](tests/src/exptree.cpp)
- [Tree header](core/tree/tree.hpp)
### ScreenCapture
1. **AVL tree visualization**
<img src = "screenshots/AVL tree insertion.gif">

- Uses simple [graphics](src/include/gfx/graphics.h) library for tree visualization.
- Using breadth first search, it draws every adjacent node to the last drawn node.
- A node is inserted in to The AVL tree from 1 to 10 (incrementally)
- Normally, it could have caused a very deep and right sided tree, but since it's an avl tree it rotates and balances itself.
- one can edit the [test](tests/src/avltree.cpp) file to increase the number and/or sequence of insertions to the tree.
- in which case must run this in [tests/src/](tests/src) directory:
```sh
g++ -I../../src/include -L../../src/lib avltree.cpp -o avltree -lbgi -lgdi32 
```
- However, the tree drawing mechanism is not scalable enough for large trees.
