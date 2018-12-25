//Implementation file for IntBinaryTree class
#include "IntBinaryTree.h"
#include <iostream>

// ********************************************************
// functionName: destroysubTree                           *
// called by:    ~IntBinaryTree                           *
// passed:       TreeNode                                 *
// returns:      nothing                                  *
// calls:        none                                     *
//                                                        *
// The destroySubTree function will travers the tree and  *
// delete the tree when fnished.                          * 
// ********************************************************
void IntBinaryTree::destroySubTree(TreeNode *node)
{
	if (node)
	{
		if (node->left)
		{
			destroySubTree(node->left);
		}
		if (node->right)
		{
			destroySubTree(node->right);
		}

		delete node;
	}
}

// ********************************************************
// functionName: getTreeInput                             *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      int                                      *
// calls:        validate_Int(integer)                    *
//                                                        *
// The getTreeInput function will get the user input when *
// the program is called to insert values into the tree.  *
// It will also work to validate input.                   * 
// ********************************************************
int IntBinaryTree::getTreeInput()
{
	// Gets the input and stores it as a string, variables to handle that
	string input;
	int convertedInput;
	cout << "\nEnter a number to add: " << endl;
	cin >> input;
	// Convert the string to integer for function to return it later, if applicables
	// If the input is not an integer, return -1, and end the program
	if (validate_Int(input) == false)
	{
		return -0;
	}
	else
		// Otherwise, return the integer for use on the stack
	{
		cout << "\nNumber: " << input << " added to the Tree.\n" << endl;
		convertedInput = stoi(input);
		return convertedInput;
	}

}

// ********************************************************
// functionName: insertNode                               *
// called by:    main                                     *
// passed:       integer                                  *
// returns:      nothing                                  *
// calls:        insert                                   *
//                                                        *
// The insertNode function will allow the user to input   *
// data a vlaue into the tree.                            * 
// ********************************************************
void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode = nullptr;
	//Create new node and store num there
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}

// ********************************************************
// functionName: insert                                   *
// called by:    insertNode                               *
// passed:       2 TreeNodes                              *
// returns:      nothing                                  *
// calls:        insert                                   *
//                                                        *
// The insert function is a helper function of the        *
// insertNode funciton. this will check and see if the    *
// node is ampty ot not by recusrsion.                    * 
// ********************************************************
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	//If current node empty, insert newNode value into current node 
	if (nodePtr == nullptr)
	{
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value)
	{
		//Recursion allows loop to keep checking if left branch is open	
		//If new value less than current value, insert on a left branch
		insert(nodePtr->left, newNode);
	}
	else
	{
		//Otherwise, if value greater than current value, insert on a right branch
		//Recursion allows right branch to be searched
		//If new value equal to current value, will insert on right branch
		insert(nodePtr->right, newNode);
	}
}

// ********************************************************
// functionName: leafcount                                *
// called by:    displayLeafcount                         *
// passed:       TreeNode                                 *
// returns:      integer                                  *
// calls:        leafCount                                *
//                                                        *
// The displayLeafcount function will count and return    *
// the number of leaves in the tree by recursion.         * 
// ********************************************************
int IntBinaryTree::leafCount(TreeNode *node)
{
	//Variable to keep count
	int count = 0;
	//Check is node is empty
	if (node == NULL)
	{
		count = 0;
	}
	//If left and right childs are empty, add one
	else if ((node->left == NULL) && (node->right == NULL))
	{
		count += 1;
	}
	else
	{
		//Keep track and count the nodes by recursion. Keep running total
		count = leafCount(node->left) + leafCount(node->right);
	}
	return count;
}

// ********************************************************
// functionName: getLeafCOunt                             *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      nothing                                  *
// calls:        none                                     *
//                                                        *
// The getLeafCount function will call the LeafCount      *
// function which counts the leaves. This function handles*
// the printing.                                          *
// ********************************************************
void IntBinaryTree::getLeafCount()
{
	cout << "\nNumber of Leaves: " << leafCount(root) << "\n" << endl;
}

// ********************************************************
// functionName: treeHeight                               *
// called by:    getTreeHeight                            *
// passed:       TreeNode                                 *
// returns:      integer                                  *
// calls:        treeHeight                               *
//                                                        *
// The treeHeight function will count the number of nodes *
// in each subtree by recursion. It will then increment if*
// a node is found. Then it will compare which tree is    *
// larger and return that value.                          * 
// ********************************************************
int IntBinaryTree::treeHeight(TreeNode *node)
{
	//Check is node is empty
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		//If not, count the number of nodes
		int a = treeHeight(node->left);
		a++;
		int b = treeHeight(node->right);
		b++;
		//Compare ehich subtree (left or right) is larger
		if (a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
}

// ********************************************************
// functionName: getTreeHeight                            *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      nothing                                  *
// calls:        treeHeight                               *
//                                                        *
// The getTreeHright function calls the treeHeight        *
// funciton and handle the printing of the values.        * 
// ********************************************************
void IntBinaryTree::getTreeHeight()
{
	cout << "\nHeight of the Tree: " << treeHeight(root) << "\n" << endl;
}

// ********************************************************
// functionName: displayInOrder                           *
// called by:    display                                  *
// passed:       TreeNode                                 *
// returns:      nothing                                  *
// calls:        displayInOrder                           *
//                                                        *
// The displayInOrder funciton traverses the tree and     *
// prints our the values in order to the consle. It will  *
// also check for empty trees.                            * 
// ********************************************************
void IntBinaryTree::displayInOrder(TreeNode *nodePtr)
{
	if (nodePtr != nullptr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << "\n" << endl;
		displayInOrder(nodePtr->right);
	}
	else if (root == nullptr)
	{
		cout << "The Tree is currently empty. Please add items before using this function" << "\n" << endl;
	}
}

// ********************************************************
// functionName: display                                  *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      nothing                                  *
// calls:        displayInOrder                           *
//                                                        *
// The display function will call the displayInOrder      *
// function and print out all values. It also adds a      *
// title for the option.                                  * 
// ********************************************************
void IntBinaryTree::display()
{
	cout << "\nHere is the Tree: " << "\n" << endl;
	displayInOrder(root);
}

// ********************************************************
// functionName: getMaxWidth                              *
// called by:    getTreeWidth                             *
// passed:       TreeNode                                 *
// returns:      integer                                  *
// calls:        getWidth                                 *
//                                                        *
// The getMaxWith function will uses a for loop to make   *
// sure it traverses the tree until the last node is found*
// It will then call getWidth which counts the node in    * 
// each level for the left and right. After it will       * 
// compare vales and return the maximum width.            *
// Used StackOverflow to assist with the function.        * 
// ********************************************************
int IntBinaryTree::getMaxWidth(TreeNode *root)
{
	int maxWidth = 0;
	int width;
	int h = treeHeight(root);
	int i;

	/* Get width of each level and compare
	the width with maximum width so far */
	for (i = 1; i <= h; i++)
	{
		width = getWidth(root, i);

		if (width > maxWidth)
		{
			maxWidth = width;
		}
	}
	return maxWidth;
}

// ********************************************************
// functionName: getWidth                                 *
// called by:    getMaxWidth                              *
// passed:       TreeNode, integer                        *
// returns:      integer                                  *
// calls:        getWidth                                 *
//                                                        *
// The getWidth function will go through the level that   *
// was specified by the for loop above. It will count the *
// number of nodes found and return thet number. Traversal*
// by recursion.                                          * 
// Used StackOverflow to assist with the function.        * 
// ********************************************************
int IntBinaryTree::getWidth(TreeNode *root, int level)
{
	//If root or node is empty, return 0, no node found
	if (root == NULL)
	{
		return 0;
	}
	//If level value is 1(node found) return 1
	else if (level == 1)
	{
		return 1;
	}
	//if level greater than 2, keep recurse
	else if (level > 1)
	{
		//For loop in above function will tell which level to traverse through
		//Root (level 1) is handled
		//Second level below root (level 2). since level equals 2, causes this block to execute once (2>1)
		//Block runs when level = 2. Recursion casues level - 1, results in returning 1 from if statement
		//Check the left child and right child, if any are founc, then if block above will handle it
		//Child found, return 1. Null, then return 0.
		//Third level (level 3), cause this block to execute twice (level - 1 = 2).
		//Since root->left/right called first time around
		//2nd recusre will result in root->left->left/root->left->right, moves to the next left child
		//Checks to see if there is a node
		//For loop above operates based on height of tree, provides level numbers
		//Allows this function to always check levels that contain at least one node
		return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
	}
}

// ********************************************************
// functionName: getTreeWidth                             *
// called by:    main                                     *
// passed:       nothing                                  *
// returns:      nothing                                  *
// calls:        none                                     *
//                                                        *
// The getTreeWidth function will call the getmaxWidth    *
// function which finds the width of the tree. It will    *
// handle the printing as well.                           * 
// ********************************************************
void IntBinaryTree::getTreeWidth()
{
	cout << "\nWidth of the Tree: " << getMaxWidth(root) << "\n" << endl;
}