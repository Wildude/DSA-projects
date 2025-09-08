# DSA Projects
This repo contains projects built on the foundations of Data structures and algorithms.
## Initial publish
This initial publish explores practical applications of stacks and trees in data structure projects.

- **Stacks**  
    Implemented using `std::vector` as the underlying container. Stacks were utilized for:
    - Converting infix expressions to postfix notation
    - Building expression trees from postfix expressions
    - Evaluating postfix expressions (only single digited numbers for now)

- **Trees**  
    Expression trees were constructed from postfix expressions. Inorder traversal of these trees was used to convert postfix expressions back to infix notation.


### Source Files
- [Stack implementations](tests/src/infpos.cpp)
- [Expression Tree Implementation (cpp)](tests/src/exptree.cpp)
- [Tree header](core/tree/tree.hpp)
