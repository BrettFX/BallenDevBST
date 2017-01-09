#ifndef BALLENDEVBST_H_
#define BALLENDEVBST_H_

#include <iostream>

class BallenDevBST
{
	private:
		/*
		An enum to split the functionality of the post-order traversal method such that it can be used to display nodes or to 
		delete the entire tree (for the destructor method)
		*/
		enum Mode
		{
			DISPLAY,
			DELETE
		};
		
		struct Node
		{
			int key;
			Node* left;
			Node* right;
		};
		
		Node* root;
		
		/*Recursive override of the insertLeaf method to find the correct location to insert a node*/
		void insertLeaf(int key, Node* currentNode);
		
		/*Recursive override of the in-order traversal method*/
		void inOrder(Node* currentNode);
		
		/*Recursive override of the pre-order traversal method*/
		void preOrder(Node* currentNode);
		
		/*Recursive override of the post-order traversal method*/
		void postOrder(Node* currentNode, Mode mode);
		
	public:
		BallenDevBST();
		
		/*Creates and returns a new leaf*/
		Node* createLeaf(int key);
		
		/*Creates a leaf node and inserts the correct location within the BST*/
		void insertLeaf(int key);
		
		/*Deletes a leaf node from the BST if it exists*/
		void remove(int key);
		
		/*Traverses the BST and displays each leaf node following the in-order approach: left, process, right*/
		void inOrder();
		
		/*Traverses the BST and displays each leaf node following the pre-order approach: process, left, right*/
		void preOrder();
		
		/*Traverses the BST and displays each leaf node following the post-order approach: left, right, process*/
		void postOrder();
		
		~BallenDevBST();
};

#endif