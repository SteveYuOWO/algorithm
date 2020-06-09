#include <assert.h>
#include <iostream>
using namespace std;
// Basic type definitions:

enum color_t { BLACK, RED };

struct Node {
  Node* parent;
  Node* left;
  Node* right;
  enum color_t color;
  int key;
  Node(int k): key(k){}
};

void InsertRepairTree(Node* n);
void InsertCase4Step2(Node* n);

// Helper functions:

Node* GetParent(Node* n) {
  // Note that parent is set to null for the root node.
  return n == nullptr ? nullptr : n->parent;
}

Node* GetGrandParent(Node* n) {
  // Note that it will return nullptr if this is root or child of root
  return GetParent(GetParent(n));
}

Node* GetSibling(Node* n) {
  Node* p = GetParent(n);

  // No parent means no sibling.
  if (p == nullptr) {
    return nullptr;
  }

  if (n == p->left) {
    return p->right;
  } else {
    return p->left;
  }
}

Node* GetUncle(Node* n) {
  Node* p = GetParent(n);

  // No parent means no uncle
  return GetSibling(p);
}

void RotateLeft(Node* n) {
  Node* nnew = n->right;
  Node* p = GetParent(n);
  assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  n->right = nnew->left;
  nnew->left = n;
  n->parent = nnew;
  // Handle other child/parent pointers.
  if (n->right != nullptr) {
    n->right->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

void RotateRight(Node* n) {
  Node* nnew = n->left;
  Node* p = GetParent(n);
  assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->left = nnew->right;
  nnew->right = n;
  n->parent = nnew;

  // Handle other child/parent pointers.
  if (n->left != nullptr) {
    n->left->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}




void InsertCase1(Node* n) {
  n->color = BLACK;
}

void InsertCase2(Node* n) {
  // Do nothing since tree is still valid.
  return;
}

void InsertCase3(Node* n) {
  GetParent(n)->color = BLACK;
  GetUncle(n)->color = BLACK;
  GetGrandParent(n)->color = RED;
  InsertRepairTree(GetGrandParent(n));
}

void InsertCase4(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  if (n == p->right && p == g->left) {
    RotateLeft(p);
    n = n->left;
  } else if (n == p->left && p == g->right) {
    RotateRight(p);
    n = n->right;
  }

  InsertCase4Step2(n);
}

void InsertRepairTree(Node* n) {
  if (GetParent(n) == nullptr) {
    InsertCase1(n);
  } else if (GetParent(n)->color == BLACK) {
    InsertCase2(n);
  } else if (GetUncle(n) != nullptr && GetUncle(n)->color == RED) {
    InsertCase3(n);
  } else {
    InsertCase4(n);
  }
}

void InsertCase4Step2(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  if (n == p->left) {
    RotateRight(g);
  } else {
    RotateLeft(g);
  }
  p->color = BLACK;
  g->color = RED;
}


void InsertRecurse(Node* root, Node* n) {
  // Recursively descend the tree until a leaf is found.
  if (root != nullptr)
  {
    if (n->key < root->key) {
      if (root->left != nullptr) {
        InsertRecurse(root->left, n);
        return;
      } else {
        root->left = n;
      }
    } else { // n->key >= root->key
      if (root->right != nullptr) {
        InsertRecurse(root->right, n);
        return;
      } else {
        root->right = n;
      }
    }
  }

  // Insert new Node n.
  n->parent = root;
  n->left = nullptr;
  n->right = nullptr;
  n->color = RED;
}


Node* Insert(Node* root, Node* n) {
  // Insert new Node into the current tree.
  InsertRecurse(root, n);

  // Repair the tree in case any of the red-black properties have been violated.
  InsertRepairTree(n);

  // Find the new root to return.
  root = n;
  while (GetParent(root) != nullptr) {
    root = GetParent(root);
  }
  return root;
}

int main() {
    Node *tree;
    // bst tree;
    Insert(tree, new Node(11));
    Insert(tree, new Node(2));
    Insert(tree, new Node(14));
    Insert(tree, new Node(15));
    Insert(tree, new Node(1));
    Insert(tree, new Node(7));
    Insert(tree, new Node(5));
    Insert(tree, new Node(8));
    Insert(tree, new Node(4));
    cout << tree->key << endl;
    return 0;
}