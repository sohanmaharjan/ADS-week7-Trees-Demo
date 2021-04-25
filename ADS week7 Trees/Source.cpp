#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
#include "AVL.h"

using namespace std;

void main() 
{
	BST bst1;
	AVL avl1;
	int size;
	int array[100];
	ifstream inFile("input-a1q2.txt"); //read .txt file 
	inFile >> size;
	for (int i = 0; i < size; i++)
	{
		inFile >> array[i];
	}


	cout << "====AVL====" << endl;
	avl1.displayRotations = true;
	for (int i = 0; i < size; i++)
	{
		avl1.insert(new StudentNode(array[i]));
	}

	
	cout << endl << "=====FINAL TREE=====" << endl;
	avl1.show(bst1.root);
	cout << endl << endl;

	system("pause");
}