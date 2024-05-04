#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <stack>
#include <vector>

using namespace std;
vector<int> path;
class TreeNode {
public:
  int data = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};


// Buiding a tree (root-left-right fashion)
// Sample Test Case 1 2 4 8 -1 -1 -1 5 9 -1 -1 -1 3 6 -1 -1 7 -1 -1
TreeNode *buildTree() {
  int data;
  cout << "Enter the data: " << endl;
  cin >> data;

  if (data == -1) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(data);

  cout << "Enter left side data of root " << data << " node" << endl;
  root->left = buildTree();

  cout << "Enter right side data of root " << data << " node " << endl;
  root->right = buildTree();

  return root;
}

// TreeTraversal 
// PreOrderTraversal
void preOrderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

// PostOrderTraversal
void postOrderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

// InorderTraversal
void inOrderTraversal(TreeNode *root) {
  if (root == nullptr)
    return;

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

// LevelOrderTraversal
void levelOrderTraversal(TreeNode *root) {
  if (root == NULL) {
    return;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode *temp = q.front();
      q.pop();
      cout << temp->data << " ";

      if (temp->left) {
        q.push(temp->left);
      }

      if (temp->right) {
        q.push(temp->right);
      }
    }
    cout << endl;
  }
}

// Finding A height if Tree
int heightofTree(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  int leftHeight = heightofTree(root->left);
  int rightHeight = heightofTree(root->right);

  int maxi = max(leftHeight, rightHeight) + 1;
  return maxi;
}

// Diameter of Tree
int DiameterofTree(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  int leftHeight = heightofTree(root->left);
  int rightHeight = heightofTree(root->right);
  int leftDiameter = DiameterofTree(root->left);
  int rightDiameter = DiameterofTree(root->right);

  return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
}


// Checking if a tree is balanced or not
bool checkisBalanced(TreeNode *root) {
  if (root == NULL) {
    return true;
  }

  int leftHeight = heightofTree(root->left);
  int rightHeight = heightofTree(root->right);

  int difference = abs(leftHeight - rightHeight);

  bool ans = false;
  if (difference <= 1) {
    ans = true;
  }

  if (ans && checkisBalanced(root->left) && checkisBalanced(root->right)) {
    return true;
  }

  return false;
}

// Covnert into Sum Tree
int convertIntoSumTree(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }

  int leftAns = convertIntoSumTree(root->left);
  int rightAns = convertIntoSumTree(root->right);

  int ans = 0;
  ans = root->data + leftAns + rightAns;
  return ans;
}

// Finding Least Common Ancestor
TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == NULL) {
    return NULL;
  }

  if (p->data == root->data) {
    return p;
  }

  if (q->data == root->data) {
    return q;
  }

  TreeNode *leftAns = LCA(root->left, p, q);
  TreeNode *rightaAns = LCA(root->right, p, q);

  if (leftAns == NULL && rightaAns == NULL) {
    return NULL;
  }

  else if (leftAns != NULL && rightaAns == NULL) {
    return rightaAns;
  } else if (leftAns == NULL && rightaAns != NULL) {
    return leftAns;
  }

  else {
    return root;
  }
}

// Check is Two Tree are Identical or not
bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  }
  if (p != NULL && q == NULL) {
    return false;
  }

  if (p == NULL && q != NULL) {
    return false;
  }

  return p->data == q->data && isSameTree(p->left, q->left) &&
         isSameTree(p->right, q->right);
}


// Vertical Order Traversal
void verticalOrderTraversalUtil(TreeNode *root, int hd, map<int, vector<int>> &verticalMap) {
    if (root == nullptr)
        return;

    verticalMap[hd].push_back(root->data);

    verticalOrderTraversalUtil(root->left, hd - 1, verticalMap);
    verticalOrderTraversalUtil(root->right, hd + 1, verticalMap);
}

void verticalOrderTraversal(TreeNode *root) {
    map<int, vector<int>> verticalMap;
    verticalOrderTraversalUtil(root, 0, verticalMap);

    for (auto& entry : verticalMap) {
        for (int val : entry.second)
            cout << val << " ";
        cout << endl;
    }
}

// ZigZag Traversal
void zigzagTraversal(TreeNode *root) {
    if (root == nullptr)
        return;

    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;

    bool leftToRight = true;
    currentLevel.push(root);

    while (!currentLevel.empty()) {
        TreeNode* temp = currentLevel.top();
        currentLevel.pop();

        if (temp != nullptr) {
            cout << temp->data << " ";

            if (leftToRight) {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            } else {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }

        if (currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

// Printing Leaves of the tree
void printLeaves(TreeNode *root) {
    if (root == nullptr)
        return;

    printLeaves(root->left);
    if (root->left == nullptr && root->right == nullptr)
        cout << root->data << " ";
    printLeaves(root->right);
}

// Printing LeftBoundary of Tree
void printBoundaryLeft(TreeNode *root) {
    if (root == nullptr)
        return;

    if (root->left) {
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    } else if (root->right) {
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
}

// Printing RightBoundary of Tree
void printBoundaryRight(TreeNode *root) {
    if (root == nullptr)
        return;

    if (root->right) {
        printBoundaryRight(root->right);
        cout << root->data << " ";
    } else if (root->left) {
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }
}

// Boundary OrderTraversal
void boundaryTraversal(TreeNode *root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";

    printBoundaryLeft(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    printBoundaryRight(root->right);
}

// Diagonal Traversal
void diagonalTraversalUtil(TreeNode *root, int d, map<int, vector<int>> &diagonalMap) {
    if (root == nullptr)
        return;

    diagonalMap[d].push_back(root->data);

    diagonalTraversalUtil(root->left, d + 1, diagonalMap);
    diagonalTraversalUtil(root->right, d, diagonalMap);
}

void diagonalTraversal(TreeNode *root) {
    map<int, vector<int>> diagonalMap;
    diagonalTraversalUtil(root, 0, diagonalMap);

    for (auto& entry : diagonalMap) {
        for (int val : entry.second)
            cout << val << " ";
        cout << endl;
    }
}

// Top View
void topView(TreeNode *root) {
    if (root == nullptr)
        return;

    map<int, int> topViewMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto nodePair = q.front();
        q.pop();
        TreeNode *node = nodePair.first;
        int hd = nodePair.second;

        if (topViewMap.find(hd) == topViewMap.end())
            topViewMap[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto& entry : topViewMap)
        cout << entry.second << " ";
}

// Bottom View
void bottomView(TreeNode *root) {
    if (root == nullptr)
        return;

    map<int, int> bottomViewMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto nodePair = q.front();
        q.pop();
        TreeNode *node = nodePair.first;
        int hd = nodePair.second;

        bottomViewMap[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto& entry : bottomViewMap)
        cout << entry.second << " ";
}

// Right View
void rightView(TreeNode *root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        TreeNode *curr = nullptr;

        for (int i = 0; i < size; i++) {
            curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        cout << curr->data << " ";
    }
}

// Left View
void leftView(TreeNode *root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode *curr = q.front();
            q.pop();

            if (i == 0)
                cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

// Root to Node Path in Binary Tree
bool rootToNodePath(TreeNode *root, int key, vector<int> &path) {
    if (root == nullptr)
        return false;

    path.push_back(root->data);

    if (root->data == key)
        return true;

    if ((root->left && rootToNodePath(root->left, key, path)) || (root->right && rootToNodePath(root->right, key, path)))
        return true;

    path.pop_back();
    return false;
}



int main() {
  TreeNode *root = nullptr;
  root = buildTree();

  TreeNode *lca = nullptr;
  TreeNode *root2 = nullptr;
  cout << endl << endl;
  for(int i=0; i<30; i++) {
    cout << "*";
  }
  cout << endl;
  
  for(int i=0; i<30; i++) {
    cout << "*";
  }
  cout << endl << endl;
  int choice;
  cout << "Choose an algorithm to execute:" << endl;
  cout << "1. Pre-order Traversal" << endl;
  cout << "2. In-order Traversal" << endl;
  cout << "3. Post-order Traversal" << endl;
  cout << "4. Level-order Traversal" << endl;
  cout << "5. Height of Tree" << endl;
  cout << "6. Diameter of Tree" << endl;
  cout << "7. Check if Tree is Balanced" << endl;
  cout << "8. Convert Tree into Sum Tree" << endl;
  cout << "9. Lowest Common Ancestor (LCA) of Two Nodes" << endl;
  cout << "10. Check if Two Trees are Identical" << endl;
  cout << "11. Vertical Order Traversal" << endl;
  cout << "12. Zigzag Traversal" << endl;
  cout << "13. Boundary Traversal" << endl;
  cout << "14. Diagonal Traversal" << endl;
  cout << "15. Top View" << endl;
  cout << "16. Bottom View" << endl;
  cout << "17. Right View" << endl;
  cout << "18. Left View" << endl;
  cout << "19. Root to Node Path in Binary Tree" << endl;
  cout<<endl << endl;
  for(int i=0; i<30; i++) {
    cout << "*";
  }
  cout << endl;

  for(int i=0; i<30; i++) {
    cout << "*";
  }
  cout << endl << endl;
  cout << "Enter your choice: ";
  cin >> choice;

  switch (choice) {
  case 1:
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    break;
  case 2:
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    break;
  case 3:
    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    break;
  case 4:
    cout << "Level-order Traversal: ";
    levelOrderTraversal(root);
    break;
  case 5:
    cout << "Height of Tree: " << heightofTree(root);
    break;
  case 6:
    cout << "Diameter of Tree: " << DiameterofTree(root);
    break;
  case 7:
    if (checkisBalanced(root))
      cout << "The tree is balanced.";
    else
      cout << "The tree is not balanced.";
    break;
  case 8:
    cout << "Sum Tree: " << convertIntoSumTree(root);
    break;
  case 9:
    TreeNode *p, *q;
    cout << "Enter the value of first node: ";
    int val1;
    cin >> val1;
    cout << "Enter the value of second node: ";
    int val2;
    cin >> val2;
    // Assume p and q are valid nodes in the tree
    // Example: p = findNode(root, val1), q = findNode(root, val2);
    p = new TreeNode(val1);
    q = new TreeNode(val2);
    lca = LCA(root, p, q);
    if (lca != NULL)
      cout << "Lowest Common Ancestor of " << val1 << " and " << val2
           << " is: " << lca->data;
    else
      cout << "Lowest Common Ancestor not found.";
    break;
  case 10:
    cout << "Enter the elements of the second tree: " << endl;
    root2 = buildTree();
    if (isSameTree(root, root2))
      cout << "The trees are identical.";
    else
      cout << "The trees are not identical.";
    break;
  case 11:
    cout << "Vertical Order Traversal:" << endl;
    verticalOrderTraversal(root);
    break;
  case 12:
    cout << "Zigzag Traversal:" << endl;
    zigzagTraversal(root);
    break;
  case 13:
    cout << "Boundary Traversal:" << endl;
    boundaryTraversal(root);
    break;
  case 14:
    cout << "Diagonal Traversal:" << endl;
    diagonalTraversal(root);
    break;
  case 15:
    cout << "Top View:" << endl;
    topView(root);
    break;
  case 16:
    cout << "Bottom View:" << endl;
    bottomView(root);
    break;
  case 17:
    cout << "Right View:" << endl;
    rightView(root);
    break;
  case 18:
    cout << "Left View:" << endl;
    leftView(root);
    break;
  case 19:
    cout << endl;
    int key;
    cout << "Enter the value of the node: ";
    cin >> key;
    cout << "Root to Node Path in Binary Tree:" << endl;
    
    if (rootToNodePath(root, key, path)) {
        for (int val : path)
            cout << val << " ";
    } else {
        cout << "Node not found in the tree.";
    }
    break;
  default:
    {
        cout << "Invalid choice!";
        break;
    }

  return 0;
}
}
