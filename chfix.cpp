#include<bits/stdc++.h>
using namespace std; // such bad practice but this ended up fairly simple so w/e
 
struct tree
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
	  // Add this to stack
	  st.push(bin_tree);
	}
    }
  //root of the expression
  bin_tree = st.top();
  st.pop();
  
  return bin_tree;
}

int main()
{
  cout << "enter expression: ";
  //cin >> input;
  char input[1000];
  cin >> input;
  cout << "\ninput =  " << input << endl;
  tree* r = constructTree(input);
  cout << "\ninfix expression is\t = ";
  inorder(r);
  cout << "\npostfix notation\t = ";
  postorder(r);
  cout << "\nprefix notation\t\t = ";
  preorder(r);
  cout << endl;
  return 0;
}
