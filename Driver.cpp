#include <iostream>

#include "BallenDevBST.h"

using namespace std;

enum Choice
{
	INSERT = 1,
	REMOVE,
	IN_ORDER,
	PRE_ORDER,
	POST_ORDER,
	EXIT
};

void displayMenu();
void renderChoice(int choice, BallenDevBST& bst);

int main(int argc, char** argv)
{
	int choice = 0;
	BallenDevBST bst;
	
	do
	{
		do
		{	
			displayMenu();
			cin >> choice;
			
			if(choice < INSERT || choice > EXIT)
				cout << "\nInvalid Choice.\n\n";
			else
				renderChoice(choice, bst);
			
		}while(choice < INSERT || choice > EXIT);
		
		if(choice == EXIT)
			cout << "\nExiting...\n\n";
		
	}while(choice != EXIT);
	
	return 0;
}

void displayMenu()
{
	cout << "\n**************Binary Search Tree**************\n";
	cout << INSERT << ". Insert Leaf\n";
	cout << REMOVE << ". Remove Leaf\n";
	cout << IN_ORDER << ". Display in-order (Ascending)\n";
	cout << PRE_ORDER << ". Display pre-order\n";
	cout << POST_ORDER << ". Display post-order\n";
	cout << EXIT << ". Exit\n\n";
	cout << ">> ";
}

void renderChoice(int choice, BallenDevBST& bst)
{
	int input = 0;
	
	switch(choice)
	{
		case INSERT:
			cout << "Enter key for leaf node to be inserted: ";
			cin >> input;
			bst.insertLeaf(input);
			break;
			
		case REMOVE:
			break;
			
		case IN_ORDER:
			cout << "In-Order: ";
			bst.inOrder();
			break;
			
		case PRE_ORDER:
			cout << "Pre-Order: ";
			bst.preOrder();
			break;
			
		case POST_ORDER:
			cout << "Post-Order: ";
			bst.postOrder();
			break;
	}
}