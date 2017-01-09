#include "BallenDevBST.h"

BallenDevBST::BallenDevBST()
{
	root = NULL;
}

/*Creates and returns a new leaf*/
BallenDevBST::Node* BallenDevBST::createLeaf(int key)
{
	Node* nodeToInsert = new Node;
	nodeToInsert->key = key;
	nodeToInsert->left = NULL;
	nodeToInsert->right = NULL;
	
	return nodeToInsert;
}
		
/*Creates a leaf node and inserts the correct location within the BST*/
void BallenDevBST::insertLeaf(int key)
{
	insertLeaf(key, root);
}

/*Recursive override of the insertLeaf method to find the correct location to insert a node*/
void BallenDevBST::insertLeaf(int key, BallenDevBST::Node* currentNode)
{
	if(!root)
	{
		root = createLeaf(key);
		std::cout << "Root node created.\n";
	}
	else if(key < currentNode->key)
	{
		if(currentNode->left)
			insertLeaf(key, currentNode->left);
		else
		{
			currentNode->left = createLeaf(key);
			std::cout << "Leaf node created and inserted as left child to " << currentNode << ".\n";
		}			
	}
	else if(key > currentNode->key)
	{
		if(currentNode->right)
			insertLeaf(key, currentNode->right);
		else
		{
			currentNode->right = createLeaf(key);
			std::cout << "Leaf node created and inserted as right child to " << currentNode << ".\n";
		}	
	}
	else
		std::cout << "\nNo duplicates permitted.\n\n";
}

/*Deletes a leaf node from the BST if it exists*/
void BallenDevBST::remove(int key)
{
	
}

/*Traverses the BST and displays each leaf node following the in-order approach: left, process, right*/
void BallenDevBST::inOrder()
{
	inOrder(root);
}

/*Recursive override of the in-order traversal method*/
void BallenDevBST::inOrder(BallenDevBST::Node* currentNode)
{
	if(root)
	{
		if(currentNode->left)
			inOrder(currentNode->left);
		
		std::cout << currentNode->key << "\t";
	
		if(currentNode->right)
			inOrder(currentNode->right);
	}
	else
		std::cout << "No tree to traverse.\n";
}

/*Traverses the BST and displays each leaf node following the pre-order approach: process, left, right*/
void BallenDevBST::preOrder()
{
	preOrder(root);
}

/*Recursive override of the pre-order traversal method*/
void BallenDevBST::preOrder(BallenDevBST::Node* currentNode)
{
	if(root)
	{
		std::cout << currentNode->key << "\t";
		
		if(currentNode->left)
			preOrder(currentNode->left);
	
		if(currentNode->right)
			preOrder(currentNode->right);
	}	
	else
		std::cout << "No tree to traverse.\n";
}

/*Traverses the BST and displays each leaf node following the post-order approach: left, right, process*/
void BallenDevBST::postOrder()
{
	postOrder(root, DISPLAY);
}

/*Recursive override of the post-order traversal method*/
void BallenDevBST::postOrder(BallenDevBST::Node* currentNode, BallenDevBST::Mode mode)
{
	if(root)
	{
		if(currentNode->left)
			postOrder(currentNode->left, mode);
	
		if(currentNode->right)
			postOrder(currentNode->right, mode);
		
		if(mode == DISPLAY)
			std::cout << currentNode->key << "\t";
		else if(mode == DELETE)
		{
			std::cout << "Deleting " << currentNode << "...\n";
			delete currentNode;
		}	
	}
	else
		std::cout << "No tree to traverse.\n";
}

BallenDevBST::~BallenDevBST()
{
	postOrder(root, DELETE);
	std::cout << "All nodes deleted successfully.\n\n";
}