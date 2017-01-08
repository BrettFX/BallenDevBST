#ifndef BALLENDEVBST_H_
#define BALLENDEVBST_H_

class BallenDevBST
{
	private:
		struct Node
		{
			int key;
			Node* next;
			Node* prev;
		};
		
		Node* root;
		
	public:
		BallenDevBST();
		
		/*Creates a leaf node and inserts the correct location within the BST*/
		void create(int key);
		
		/*Deletes a leaf node from the BST if it exists*/
		void remove(int key);
		
		/*Traverses the BST and displays each leaf node following the in-order approach*/
		void inOrder();
		
		/*Traverses the BST and displays each leaf node following the pre-order approach*/
		void preOrder();
		
		/*Traverses the BST and displays each leaf node following the post-order approach*/
		void postOrder();
		
		~BallenDevBST();
};

#endif