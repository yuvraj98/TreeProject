# Data Structures and Algorithms (DSA) C++ Project

# Introduction
This project is a collection of various algorithms and data structures implemented in C++ to perform different operations on binary trees. 
It includes functionalities like tree traversal, calculating tree height, finding the diameter of a tree, 
checking if a tree is balanced, converting a tree into a sum tree, finding the lowest common ancestor (LCA) of two nodes, checking if two trees are identical, and more.

# Tree Information
Representation: The binary trees are represented using the TreeNode class, where each node contains an integer value and pointers to its left and right children.
Input: Trees are built by providing input data in a root-left-right fashion. 
Enter -1 for a node if it is NULL.


# Features
# Tree Traversal:
Pre-order: Visit the root node, then recursively traverse the left subtree and the right subtree.

In-order: Recursively traverse the left subtree, visit the root node, then traverse the right subtree.

Post-order: Recursively traverse the left subtree, then the right subtree, and finally visit the root node.

Level-order: Traverse the tree level by level, starting from the root.

# Tree Properties:
Height: Calculate the height of the tree, which is the length of the longest path from the root to a leaf node.

Diameter: Find the diameter of the tree, which is the number of nodes on the longest path between any two leaf nodes.

Balanced Check: Check if the tree is balanced, meaning the heights of the left and right subtrees of every node differ by at most one.

# Tree Transformations:
Sum Tree Conversion: Convert the tree into a sum tree, where each node's value is the sum of its subtree values.

# Tree Comparisons:
Lowest Common Ancestor (LCA): Find the lowest common ancestor of two nodes in the tree.

Identical Trees Check: Check if two trees are identical in structure and node values.

# Tree Views:
Vertical: Traverse the tree vertically, printing nodes at each horizontal distance from the root.

Zigzag: Traverse the tree in a zigzag pattern, alternating between left and right directions at each level.

Boundary: Print the boundary nodes of the tree, including the left boundary, leaves, and right boundary.

Diagonal: Traverse the tree diagonally, printing nodes on each diagonal line from top-left to bottom-right.

Top View: Print the nodes visible from the top of the tree.

Bottom View: Print the nodes visible from the bottom of the tree.

Right View: Print the nodes visible from the right side of the tree.

Left View: Print the nodes visible from the left side of the tree.

# Path Finding:
Root-to-Node Path: Find the path from the root to a specified node in the tree.

# Usage
Building a Tree: Execute the program to build a binary tree by providing input data in a root-left-right fashion.

Choose an Algorithm: Select the desired algorithm from the given list by entering the corresponding number.

View Results: The program will display the result of the chosen algorithm.

# Instructions
Building a Tree: Enter the data for each node in the tree in a root-left-right fashion. Enter -1 for a node if it is NULL.

Choosing an Algorithm: Select the desired algorithm from the given list by entering the corresponding number.

Viewing Results: The program will display the result based on the chosen algorithm.

