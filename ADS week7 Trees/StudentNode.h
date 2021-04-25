#pragma once
#include <iostream>
#include <string>

using namespace std;

class StudentNode
{
public:
	int studentID;
	StudentNode* leftChild;
	StudentNode* rightChild;

	StudentNode(int studentID);
};


