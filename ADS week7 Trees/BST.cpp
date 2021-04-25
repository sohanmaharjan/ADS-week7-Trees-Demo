#include <fstream>
#include "BST.h"

void BST::insert(StudentNode* newStudent)
{
    //IF the root is NULL(tree is empty), then make this student the root
    if (root == NULL)
    {
        root = newStudent;
        return; //exit function early, we are done here
    }

    //some pointers to help us navigate the tree to find where to put the new student
    StudentNode* current = root; //current node we're pointing at
    StudentNode* parent = NULL; //parent of current (node visitored last time)

    while (true)//infinite loop
    {
        //lets keep track of where we were before moving down further
        parent = current;
        //LEFT OR RIGHT?!
        //if new students studentID is less then the student at current node, then go down LEFT
        if (newStudent->studentID < current->studentID)
        {
            //< means we go down deeper into tree on left side
            current = current->leftChild;
            //if current is NULL, we just found an empty space to insert our new Student :D
            if (current == NULL)
            {
                //done, stick student here
                parent->leftChild = newStudent;
                return; //done, bail
            }
        }
        else
        {
            //go down right path
            current = current->rightChild;
            //if current is NULL, insert there
            if (current == NULL)
            {
                parent->rightChild = newStudent;
                return;
            }
        }
    }
}

StudentNode* BST::search(int studentID, bool showSearchPath)
{
    //if tree empty, cant find student matching studentID then
    if (root == NULL)
    {
        return NULL;
    }

    StudentNode* current = root;

    //keep looping until I find a match
    while (current->studentID != studentID)
    {
        

        if (showSearchPath)
            cout << current->studentID << endl;

        //havent found it yet, lefts explore left or right down in the tree
        if (studentID < current->studentID)
        {
            //go left
            current = current->leftChild;
        }
        else
        {
            //go right
            current = current->rightChild;
        }

        //if current is NULL, search studentID cannot be found
        if (current == NULL)
        {
            return NULL;
        }

    }

    return current; //should be pointing to match in tree :D
}

//outputs stuff in the tree in ascending order :D
void BST::inOrderTraversal(StudentNode* current)
{
    //current == null is end of this branch path, this if
    //stops from infinite looping
    if (current != NULL)
    {
        inOrderTraversal(current->leftChild);
        cout << current->studentID << endl;
        inOrderTraversal(current->rightChild);
    }
}

void BST::preOrderTraversal(StudentNode* current)
{
    if (current != NULL)
    {
        cout << current->studentID << endl;
        preOrderTraversal(current->leftChild);
        preOrderTraversal(current->rightChild);
    }
}

void BST::postOrderTraversal(StudentNode* current)
{
    if (current != NULL)
    {
        postOrderTraversal(current->leftChild);
        postOrderTraversal(current->rightChild);
        cout << current->studentID << endl;
    }
}

//referenced second algorithm here https://www.geeksforgeeks.org/level-order-tree-traversal/
void BST::show(StudentNode* p)
{
    ofstream myFile("output-a1q1.txt"); //create a .txt file to write the output
    // Base Case 
    if (root == NULL)  return;

    // Create an empty queue for level order traversal 
    queue<StudentLevelNode> q;

    // Enqueue Root and initialize height 
    q.push(StudentLevelNode(root, 0));

    int previousOutputLevel = -1;

    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue 
        StudentLevelNode node = q.front();
        if (node.level != previousOutputLevel)
        {
            cout << endl;
            cout << node.level << "- ";
            previousOutputLevel = node.level;
            myFile << endl;
            myFile << node.level << ": ";
        }
        cout << node.student->studentID <<" ";
        myFile << node.student->studentID << " ";
        q.pop();

        /* Enqueue left child */
        if (node.student->leftChild != NULL)
            q.push(StudentLevelNode(node.student->leftChild, node.level+1));

        /*Enqueue right child */
        if (node.student->rightChild != NULL)
            q.push(StudentLevelNode(node.student->rightChild, node.level+1));
       
    }
}
