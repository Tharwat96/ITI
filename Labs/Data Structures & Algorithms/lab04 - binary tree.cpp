#include <iostream>
#include <math.h>

using namespace std;

class Employee
{
    string name;
    int code;
public:
    Employee *pRight;
    Employee *pLeft;
    void setName(string name);
    string getName();
    void setCode(int code);
    int getCode();
};

void Employee::setName(string name)
{
    this->name = name;
}

string Employee::getName()
{
    return this->name;
}

void Employee::setCode(int code)
{
    this->code = code;
}

int Employee::getCode()
{
    return this->code;
}
//---------------BINARY TREE CLASS---------------
class BinaryTree
{
    Employee *pParent;
    Employee *insert(Employee *pRoot, Employee *data);
    void inOrder(Employee *pRoot);
    void preOrder(Employee *pRoot);
    void postOrder(Employee *pRoot);
    Employee *deleteT(Employee *pRoot, int key);
    int getHeight(Employee *pRoot);
public:
    BinaryTree()
    {
        pParent = NULL;
    }
    void insertNode(Employee *data);
    Employee *searchTree(int code);
    void inOrderTraverse();
    void preOrderTraverse();
    void postOrderTraverse();
    void deleteNode(int key);
    int getTreeHeight();
};

void BinaryTree::insertNode(Employee *data)
{
    pParent = insert(pParent, data);
}

Employee *BinaryTree::insert(Employee *pRoot, Employee *data)
{
    //if the tree is empty, return a new single node as a root of the tree
    if(pRoot == NULL)
    {
        data->pRight = NULL;
        data->pLeft = NULL;
        return data;
    }
    //if not empty:
    else
    {
        if(data->getCode() <= pRoot->getCode())
            pRoot->pLeft = insert(pRoot->pLeft, data);
        else
            pRoot->pRight = insert(pRoot->pRight, data);
        return(pRoot); //return the unchanged pParent pointer
    }
}

Employee* BinaryTree::searchTree(int code)
{
    Employee *pRoot;
    pRoot = pParent;
    while (pRoot && code != pRoot->getCode())
    {
        if(code < pRoot->getCode())
            pRoot = pRoot->pLeft;
        else
            pRoot = pRoot->pRight;
    }
    return pRoot;
}

void BinaryTree::inOrderTraverse()
{
    inOrder(pParent);
}

void BinaryTree::inOrder(Employee *pRoot)
{
    if(pRoot)
    {
        inOrder(pRoot->pLeft);
        cout<<"Code: "<<pRoot->getCode()<<endl;
        inOrder(pRoot->pRight);
    }
}void BinaryTree::preOrderTraverse()
{
    preOrder(pParent);
}

void BinaryTree::preOrder(Employee *pRoot)
{
    if(pRoot)
    {
        cout<<"Code: "<<pRoot->getCode()<<endl;
        inOrder(pRoot->pLeft);
        inOrder(pRoot->pRight);
    }
}void BinaryTree::postOrderTraverse()
{
    postOrder(pParent);
}

void BinaryTree::postOrder(Employee *pRoot)
{
    if(pRoot)
    {
        inOrder(pRoot->pLeft);
        inOrder(pRoot->pRight);
        cout<<"Code: "<<pRoot->getCode()<<endl;

    }
}

int BinaryTree::getTreeHeight()
{
    return getHeight(pParent);
}

int BinaryTree::getHeight(Employee *pRoot)
{
    if (pRoot==NULL)
        return 0;
    else
    {
        int x = getHeight(pRoot->pLeft);
        int y = getHeight(pRoot->pRight);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
}

void BinaryTree:: deleteNode (int key)
{
    pParent = deleteT(pParent , key);
}
Employee * BinaryTree:: deleteT ( Employee * pRoot, int key)
{
    // 1. Empty or Not found
    Employee *p,*p2;
    if(!pRoot)
        return pRoot; /* Empty or Not found */
    // 2. Delete the Root there is only one element in the tree
    if(pRoot->getCode() == key)
    {
        if(pRoot->pLeft == pRoot->pRight)
        {
            delete pRoot ;
            return NULL;
        }
        // 3. has one subtree
        else if (pRoot->pLeft == NULL)
        {
            p = pRoot->pRight;
            delete pRoot;
            return p;
        }
        else if(pRoot->pRight == NULL)
        {
            p = pRoot->pLeft;
            delete pRoot ;
            return p;
        }
    }
    // 4. has two subtrees
    else {
        p2 = pRoot->pRight;
        p = pRoot->pRight;
        while(p->pLeft)
        p = p->pLeft;
        p->pLeft = pRoot->pLeft;
        delete pRoot;
        return p2;
    }
// 3
}

int main()
{
    int key;
    Employee e1, e2, e3, e4;
    e1.setCode(5);
    e1.setName("tharwat");
    e2.setCode(15);
    e2.setName("hasan");
    e3.setCode(16);
    e3.setName("mostafa");
    e4.setCode(4);
    e4.setName("mina");

    BinaryTree tree;
    tree.insertNode(&e1);
    tree.insertNode(&e2);
    tree.insertNode(&e3);
    tree.insertNode(&e4);
    cout<<"----In Order Traverse----"<<endl;
    tree.inOrderTraverse();

    cout<<"----Pre Order Traverse----"<<endl;
    tree.preOrderTraverse();

    cout<<"----Post Order Traverse----"<<endl;
    tree.postOrderTraverse();
    cout<<"-----Tree Height-----"<<endl<<tree.getTreeHeight()<<endl;
    cout<<"Please enter a code to search for"<<endl;
    cin>>key;

    cout<<"Search result: "<<endl;
    if (Employee* pEmp=tree.searchTree(key))
    {
        cout<<"ID: "<<pEmp->getName()<<endl;
        cout<<"Name: "<<pEmp->getName()<<endl;
    }
    else
        cout<<"Not found"<<endl;

    //DELETE
    cout<<"Please enter a code to delete its node"<<endl;
    cin>>key;
    if(key)
        tree.deleteNode(key);
    cout<<"Search result after delete: "<<endl;
    if (Employee* pEmp=tree.searchTree(key))
    {
        cout<<"ID: "<<pEmp->getName()<<endl;
        cout<<"Name: "<<pEmp->getName()<<endl;
    }
    else
        cout<<"Not found"<<endl;

    cout<<"----In Order Traverse----"<<endl;
    tree.inOrderTraverse();


    return 0;
}
