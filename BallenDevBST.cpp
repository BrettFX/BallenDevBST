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

/*Deletes a leaf node from the BST if it exists
*There are three different scenarios to be handled in a BST leaf node removal algorithm.
*Either the leaf node being removed has:
*
*1) No children
*2) Only one child
*3) Two children (most sophisticated)
*
*@param key a unique identifier that represents each individual node in a BST.
**/
void BallenDevBST::remove(int key)
{
	Node* nodeToDelete = NULL;
	Node* currentNode = NULL;
	
	//Removing the root
	if(root)
	{
		if(root->key == key)
		{
			nodeToDelete = root;
			root = root->right;
			currentNode = root;
			
			while(currentNode->left)
				currentNode = currentNode->left;
			
			currentNode->left = nodeToDelete->left;
			
			delete nodeToDelete;
			
			std::cout << "\nRoot node deleted.\n\n";
		}
		//Call the recursive definition of the remove method to search for the node to delete and delete it
		else
		{
			nodeToDelete = remove(key, root);
			
			if(nodeToDelete)
			{
				std::cout << "\nThe node is located at address location: " << nodeToDelete << "\n";				
				//delete nodeToDelete;
				std::cout << "Node deleted.\n\n";
			}
			else
				std::cout << "\nCould not find the node with a matching key.\n\n";
		}	
	}
	else
		std::cout << "\nNo nodes to be deleted.\n\n";
}

/*Recursive overload of the remove method to find the node to be deleted and delete it*/
BallenDevBST::Node* BallenDevBST::remove(int key, BallenDevBST::Node* currentNode)
{
	if(key > currentNode->key && currentNode->right)
		return remove(key, currentNode->right);
	
	if(key < currentNode->key && currentNode->left)
		return remove(key, currentNode->left);
	
	if(key == currentNode->key)
	{
		std::cout << "\nFound leaf node to be deleted with key " << key;
		
		//Determine if the node has more than one child
		//No children
		if(!currentNode->left && !currentNode->right)
		{
			std::cout << "\nLeaf had no children...\n";	

			//Have to get the parentNode and set wichever pointer is pointing to the nodeToDelete to NULL
			
			return currentNode;			
		}	
	}
	
	return NULL;
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