#ifndef _AVLDICT_CPP
#define _AVLDICT_CPP

//AVLDict.cpp
#include "AVLDict.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of a dictionary ADT as an unsorted linked list.
//
AVLDict::AVLDict() {
  root = NULL;

  // Initialize array of counters for depth statistics
  depth_stats = new int[MAX_STATS]();
}

void AVLDict::destructor_helper(node * x) {
  if (x == NULL) return; // Nothing to destroy.
  destructor_helper(x->left);
  destructor_helper(x->right);
  delete x->key;
  delete x;
}

AVLDict::~AVLDict() {
  // Clean up the tree.
  // This is most easily done recursively.
  destructor_helper(root);

  // It's not good style to put this into a destructor,
  // but it's convenient for this assignment...
  cout << "Depth Statistics for find():\n";
  for (int i=0; i<MAX_STATS; i++)
    cout << i << ": " << depth_stats[i] << endl;
  delete [] depth_stats;
}

bool AVLDict::find_helper(node *r, string keyID, PuzzleState *&pred, int depth) {
  if (r==NULL) {
    if (depth<MAX_STATS) depth_stats[depth]++;
    return false; // Didn't find it.
  }
  if (keyID == r->keyID) {
    if (depth<MAX_STATS) depth_stats[depth]++;
    pred = r->data; // Got it!  Get the result.
    return true;
  }
  if (keyID < r->keyID) return find_helper(r->left, keyID, pred, depth+1);
  else return find_helper(r->right, keyID, pred, depth+1);
}

bool AVLDict::find(PuzzleState *key, PuzzleState *&pred) {
  return find_helper(root, key->getUniqId(), pred, 0);
}

bool AVLDict::update_height( node * x ) {
  //
  // Recalculates the height of x from the height of its children.
  // Returns true iff the height of x changes.
  //
  // :TODO: Write this function!
  if (x == NULL) return false; 
  int m = std::max(height(x->left), height(x->right)) + 1;
  if (x->height != m) {
     x->height = m;
     return true;
  }
  return false; // Remove this line when you've implemented this function.
}

void AVLDict::rotate_left( node *& a ) {
  // "rotates" the subtree rooted at a to the left (counter-clockwise)

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Rotate Left: " << a->keyID << std::endl;
#endif
// End of "DO NOT CHANGE" Block

  // :TODO: Write this function!
  assert (a != NULL);
  assert (a->right != NULL);
  node * temp = a->right;
  a->right = temp->left;
  temp->left = a;
  update_height(a);
  update_height(temp);
  a = temp;
}

void AVLDict::rotate_right( node *& b ) {
  // "rotates" the subtree rooted at b to the right (clockwise)

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
cout << "Rotate Right: " << b->keyID << endl;
#endif
// End of "DO NOT CHANGE" Block

  // :TODO: Write this function!
  assert (b != NULL);
  assert (b->left != NULL);
  node * temp = b->left;
  b->left = temp->right;
  temp->right = b;
  update_height(b);
  update_height(temp);
  b = temp;
}

void AVLDict::doubleRotateLeft(node *& c) {
  assert (c != NULL);
  assert (c->right != NULL);
  assert (c->right->left != NULL);
  rotate_right(c->right);
  rotate_left(c);
}

void AVLDict::doubleRotateRight(node *& c) {
  assert(c != NULL);
  assert(c->left != NULL);
  assert(c->left->right != NULL);
  rotate_left(c->left);
  rotate_right(c);
}

//int AVLDict::get_balance(node* x) {
//  return (height(x->left) - height(x->right));
//}

void AVLDict::balance(node *& x) {
  if (! x) return;
 
  int left_height = height(x->left);
  int right_height = height(x->right);

   if (abs(right_height - left_height) <=1) return;

   if (right_height > left_height) {  
      assert( right_height > 1 + left_height );  // asserts are often used as a kind of documentation 
      
      if (x->right && x->right->left  // always check that it's OKAY to dereference the pointers
      && (right_height == 1 + x->right->left->height)){
         doubleRotateLeft( x ); 
      }
      else { 
         rotate_left( x ); 
      }
     
   }
   else { 
      assert( left_height > right_height + 1 ); 
           
      if (x->left && x->left->right
      && (left_height == 1 + x->left->right->height)){
         doubleRotateRight( x );  
      }
      else { 
         rotate_right( x ); 
      }
   } 
}

bool AVLDict::isValidAVLTree(node* x){
  if (!x) return true;
  if (isValidAVLTree(x->left) && isValidAVLTree(x->right)) {
     if (abs(height(x->left) - height(x->right)) > 1) return false;
     return true;
  }
  else return false;
}
 

// You may assume that no duplicate PuzzleState is ever added.
void AVLDict::add(PuzzleState *key, PuzzleState *pred) {
  // :TODO: Write this function!
  node * new_node = new node;
  new_node->key = key;
  new_node->keyID = key->getUniqId();
  new_node->data = pred;
  new_node->height = 0;
  new_node->left = NULL;
  new_node->right = NULL;

  add_helpfunction(key, pred, root, new_node);
  assert (isValidAVLTree(root));
}

void AVLDict::add_helpfunction(PuzzleState *key, PuzzleState *pred, node*& root, node *& new_node) {
  if (root == NULL) {
     root = new_node;
     //return;
  }
  if (new_node->keyID < root->keyID) {
    add_helpfunction(key, pred, root->left, new_node);
  }
  else if (new_node->keyID > root->keyID) {
     add_helpfunction(key, pred, root->right, new_node);
  }
    if (update_height(root))
	balance(root);
}

#endif 
