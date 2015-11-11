#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std; // such bad practice but this ended up fairly simple so w/e

struct tree; //because this is c++ this is secretly a class
bool isOperator(char c);
void inorder(tree *t);
void preorder(tree *t);
void postorder(tree *t);
tree* newNode(int v);
tree* constructTree(char prefix[]);
bool equals(tree *x, tree *y);
tree* evaluate(tree *e);
int main()
{
  cout << "Please note! I only handle single digit numbers!";
  cout << "\nthat includes the answer if just digits are given\nenter an expression: ";
  char input[1000];
  cin >> input;
  cout << "\ninput =  " << input << endl;
  tree* r = constructTree(input);
  tree* sample = constructTree("*+AB-CD");
  cout << "\ninfix expression of your tree is\t = ";
  inorder(r);
  cout << "\npostfix notation of your tree is\t = ";
  postorder(r);
  cout << "\nprefix notation of your tree is\t\t = ";
  preorder(r);
  cout << "\n\ninfix expression of sample tree is\t = ";
  inorder(sample);
  cout << "\npostfix notation of sample tree is\t = ";
  postorder(sample);
  cout << "\nprefix notation of sample tree is\t = ";
  preorder(sample);
  cout << endl;
  if(equals(r, sample))
    {
      cout << "Both trees are equal!\n";
    }
  else
    cout << "The trees are not equal :(\n";
  return 0;
}

struct tree //secret class
{
  char value;
  tree* left, *right;
};
 
bool isOperator(char c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    return true;
  return false;
}
// recursion is magical
// I can't even believe how
// concice it makes code
void inorder(tree *t)
{
  if(t)
    {
      inorder(t->left);
      printf("%c ", t->value);
      inorder(t->right);
    }
}
void preorder(tree *t)
{
  if(t)
    {
      printf("%c ", t->value);
      preorder(t->left);
      preorder(t->right);
    }
}
void postorder(tree *t)
{      
  if(t)
    {
      postorder(t->left);
      postorder(t->right);
      printf("%c ", t->value);
    }
}
// here is a function that 
tree* newNode(int v)
{
  tree *pivot = new tree;
  pivot->left = pivot->right = NULL;
  pivot->value = v;
  return pivot;
};
 
// Returns root of the bin tree we just made
tree* constructTree(char prefix[])
{
  stack<tree *> st;
  tree *bin_tree;
  
  // I found a algorthm that uses stacks
  // and it had the most readable code
  // so here is the actual parser
  // for the expression tree
  for (int i=strlen(prefix); i>=0; i--)
    {
      if (!isOperator(prefix[i]))
	{
	  bin_tree = newNode(prefix[i]);
	  st.push(bin_tree); // to the stack for operands
	}
      //Right to the tree with the operators
      else
	{
	  bin_tree = newNode(prefix[i]);
	  bin_tree->left = st.top();
	  st.pop();
	  bin_tree->right = st.top();
	  st.pop();
	  bin_tree = evaluate(bin_tree);
	  // Add this to stack
	  st.push(bin_tree);
	}
    }
  //root of the expression
  bin_tree = st.top();
  st.pop();
  
  return bin_tree;
}
bool equals(tree *x, tree *y)
{
  if (x == NULL)
  {
    return y == NULL;   //because if both are empty, they are equal!
  }
  if (y == NULL)
  {
    return false;
  }
  if (x->value != y->value)
  {
    return false;
  }
  if (equals(x->left, y->left) && equals(x->right, y->right)) 
  {
    return true;
  }
  if (equals(x->left, y->right) && equals(x->right, y->left))
  {
    return true;
  }
  return false;
}
tree* evaluate(tree *e)
{ 
  if (isdigit(e->left->value) && isdigit(e->right->value)) // this does the evaluation.
    {
      if (e->value == '+')
	{
	  e->value = ((e->right->value - '0') + (e->left->value - '0')+'0');
	  e->left = e->right = NULL;
	}
      if (e->value == '-')
	{
	  e->value = ((e->right->value - '0') - (e->left->value - '0')+'0');
	  if(e->value > 0)
	    {
	      //fix negitive numbers
	      e->right->value = (abs(e->right->value-'0')+'0'); 
	    }
	  e->left = e->right = NULL;
	}
      if (e->value == '*')
	{
	  e->value = ((e->right->value - '0') * (e->left->value - '0')+'0');
	  e->left = e->right = NULL;
	}
    } 
  return e;
}
