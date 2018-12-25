//Specification file for IntBinaryTree class
#ifndef IntBinaryTree_H
#define IntBinaryTree_H
#include "Menu.h"

class IntBinaryTree : public Menu
{
private:
	struct TreeNode
	{
		//Value of node
		int value;
		//Pointer to the left child node
		TreeNode *left;
		//Pointer to the right child node
		TreeNode *right;
	};

	//Pointer to the root node (pointer to first node)
	TreeNode *root;

	//Private member funcitons
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void displayInOrder(TreeNode *);
	int leafCount(TreeNode *);
	int treeHeight(TreeNode *);
	int getMaxWidth(TreeNode *);
	int getWidth(TreeNode *, int);
	
	

public:
	//Constructor
	IntBinaryTree()
	{
		root = nullptr;
	}

	//Destructor
	~IntBinaryTree()
	{
		destroySubTree(root);
	}



	//Binary Tree operations
	void insertNode(int);
	void display();
	

	int getTreeInput();

	void getLeafCount();
	void getTreeHeight();
	void getTreeWidth();

};

#endif // !IntBinaryTree_H

