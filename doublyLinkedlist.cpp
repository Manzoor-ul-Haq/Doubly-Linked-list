#include <iostream>
#include <fstream>
using namespace std;

class Node
{
private:
    int value;
    Node* next;
    Node* previous;
public:
    Node();
    Node(int);
    void setValue(int);
    int getValue();
    void setNext(Node*);
    Node* getNext();
    void setPrevious(Node*);
    Node* getPrevious();
};
class Linkedlist
{
private:
    Node* head;
public:
    Linkedlist();
    void addAtEnd(int);
    void addAtStart(int);
    void rmvStart();
    void rmvEnd();
    void rmv(int);
    void rmvAtIndex(int);
    void addAt(int, int);
    int getAt(int);
    int find(int); //return index
    int getSize();
    void display();
    bool isEmpty();
    void rvrsdisp();
    void display(Node*);
    Node* first();
    Node* last();
    Node* findNode(int);
    void actionFile();
    bool isFull();
};
Node::Node()
{
    value = 0;
    next = NULL;
    previous = NULL;
}
Node::Node(int v)
{
    value = v;
    next = NULL;
    previous = NULL;
}
void Node::setValue(int v)
{
    value = v;
}
int Node::getValue()
{
    return value;
}
void Node::setNext(Node* next)
{
    this->next = next;
}
Node* Node::getNext()
{
    return next;
}
void Node::setPrevious(Node* previous)
{
    this->previous = previous;
}
Node* Node::getPrevious()
{
  return previous;
}
Linkedlist::Linkedlist()
{
    head == NULL;
}
void Linkedlist::addAtEnd(int v)
{
    if(isEmpty() == true)
    {
        head = new Node(v);
    }
    else
    {
        Node* temp = last();
        last()->setNext(new Node(v));
        temp->getNext()->setPrevious(temp);
    }
}
void Linkedlist::addAtStart(int v)
{
    if (isEmpty() == true)
    {
        head = new Node(v);
    }
    else
    {
        Node* temp = head;
        head = new Node(v);
        head->setNext(temp);
        temp->setPrevious(head);
    }
}
void Linkedlist::rmvStart()
{
    if(head == last())
    {
      head->setPrevious(NULL);
      head = NULL;
    }
    else
    {
      head = head->getNext();
      head->setPrevious(NULL);
    }
}
void Linkedlist::rmvEnd()
{
    if(isEmpty() == true)
    {
        return;
    }
    else
    {
        Node* temp = head;
        while (temp->getNext() != last())
        {
            temp = temp->getNext();
        }
        temp->setNext(NULL);
    }
}
void Linkedlist::rmv(int v)
{
    if(isEmpty() == true)
        return;
    else
    {
        if(find(v) == getSize()-1)
            rmvEnd();
        else if (find(v) == 0)
            rmvStart();
        else if (find(v)+1 == 0)
            return;
        else
        {
            Node* temp = head;
            while (temp->getNext() != findNode(find(v)))
            {
                temp = temp->getNext();
            }
            temp->setNext(findNode(find(v)+1));
            findNode(find(v)+1)->setPrevious(findNode(find(v)-1));
        }
    }
}
void Linkedlist::rmvAtIndex(int index)
{
  if(i == 0)
          rmvStart();
      else if(i == getSize()-1)
          rmvEnd();
      else if(i<0 || i>=getSize())
          return;
      else
      {
          findNode(i-1)->setNext(findNode(i+1));
          findNode(i)->setPrevious(findNode(i-1));
      }
}
void Linkedlist::display()
{
    if (head == NULL)
    {
        cerr << "No List" << endl;
    }
    else
    {
        Node* temp = head;
        cout << "Values: ";
        while (temp != NULL)
        {
            if (temp != last())
                cout << temp->getValue() << ", " ;
            else
                cout << last()->getValue() << endl;
            temp = temp->getNext();
        }
      }
}
void Linkedlist::addAt(int i, int v)
{
    if(i <= 0)
    {
        addAtStart(v);
    }
    else if (i >= getSize())
    {
        addAtEnd(v);
    }
    else
    {
        Node* temp = head;
        while(temp->getNext() != findNode(i))
        {
            temp = temp->getNext();
        }
        Node* t = new Node(v);
        t->setPrevious(temp);
        t->setNext(findNode(i));
        temp->setNext(t);
        findNode(i-1)->setPrevious(t);
    }
}
int Linkedlist::getAt(int i)
{
    if(i<0 || i>=getSize())
        return -1;
    else
        return findNode(i)->getValue();
}
int Linkedlist::getSize()
{
    int i = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        i++;
        temp = temp->getNext();
    }
    return i;
}
bool Linkedlist::isEmpty()
{
    return head == NULL;
}
void Linkedlist::rvrsdisp()
{
    int arr[getSize()];
    Node* temp = head;
    int i = 0;
    while (temp != NULL)
    {
        arr[i] = temp->getValue();
        temp = temp->getNext();
        i++;
    }
    for (int i=getSize()-1; i>=0; i--)
    {
        cout << arr[i] << " ";
    }
}
void Linkedlist::display(Node* t)
{
    if (t->getNext() != NULL)
    {
        display(t->getNext());
    }
    cout << t->getValue() << " ";
}
Node* Linkedlist::first()
{
    return head;
}
Node* Linkedlist::last()
{
    Node* temp = head;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    return temp;
}
Node* Linkedlist::findNode(int i)
{
    int index = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        if (index == i)
            break;
        temp = temp->getNext();
        index++;
    }
    return temp;
}
int Linkedlist::find(int v)
{
    int index = 1;
    Node* temp = head;
    if (temp->getValue() == v)
        return 0;
    else
    {
        while (temp->getNext() != NULL)
        {
            if (temp->getNext()->getValue() == v)
                break;
            temp = temp->getNext();
            index++;
        }
        if(findNode(index) == last())
            return getSize()-1;
        else
            return index;
    }
    return index;
}
void Linkedlist::actionFile()
{
  int i = 0;
  string word;
  int integer;
  ifstream file;
  file.open("data.txt");
  if(!file)
  {
    cout<<"Not Open\n";
  }
  else
  {
    while(file.eof() == 0)
    {
      file >> word;
      if (word == "A")
      {
        file >> integer;
        addAtEnd(integer);
      }
      else if (word == "AAS")
      {
        file >> integer;
        addAtStart(integer);
      }
      else if (word == "AT")
      {
        file >> integer;
        int i = integer;
        file >> integer;
        int v = integer;
        addAt(i, v);
      }
      else if (word == "D")
      {
        if (i<2)
          display();
        i++;
      }
      else if (word == "RFS")
      {
        rmvStart();
      }
      else if (word == "RA")
      {
        file >> integer;
        rmvAtIndex(integer);
      }
      else if (word == "R")
      {
        file >> integer;
        rmv(integer);
      }
      else if (word == "RFE")
      {
        rmvEnd();
      }
    }
  }
}
bool Linkedlist::isFull()
{
  return getSize() == 20;
}
int main()
{
    Linkedlist* l = new Linkedlist();
    int value = 0;
    int index = 0;
    char a  = '0';
    do
    {
        cout << "Press 'A' for adding to the end of list." << endl;
        cout << "Press 'B' for adding to the start of the list." << endl;
        cout << "Press 'C' for removing from the start of the list." << endl;
        cout << "Press 'D' for removing from the end of the list." << endl;
        cout << "Press 'E' for removing by matching value in the list." << endl;
        cout << "Press 'F' for removing from specific index in the list." << endl;
        cout << "Press 'G' for adding to specific index in the list." << endl;
        cout << "Press 'H' for getting value from specific index in the list." << endl;
        cout << "Press 'I' for getting index by matching value in the list." << endl;
        cout << "Press 'J' for getting size of list." << endl;
        cout << "Press 'K' for displaying values of all nodes in the list." << endl;
        cout << "Press 'L' for action on file." << endl;
        cin >> a;
        switch (a)
        {
            case 'A':
                {
                    cout << "Value: ";
                    cin >> value;
                    l->addAtEnd(value);
                    break;
                }
            case 'B':
                {
                    cout << "Value: ";
                    cin >> value;
                    l->addAtStart(value);
                    break;
                }
            case 'C':
                {
                    l->rmvStart();
                    break;
                }
            case 'D':
                {
                    l->rmvEnd();
                    break;
                }
            case 'E':
                {
                    cout << "Value: ";
                    cin >> value;
                    l->rmv(value);
                    break;
                }
            case 'F':
                {
                    cout << "Index: ";
                    cin >> index;
                    l->rmvAtIndex(index);
                    break;
                }
            case 'G':
                {
                    cout << "Index: ";
                    cin >> index;
                    cout << "Value: ";
                    cin >> value;
                    l->addAt(index, value);
                    break;
                }
            case 'H':
                {
                    cout << "Index: ";
                    cin >> index;
                    cout << "Value: " <<l->getAt(index) << endl;
                    break;
                }
            case 'I':
                {
                    cout << "Value: ";
                    cin >> value;
                    cout << "Index: " << l->find(value) << endl;
                    break;
                }
            case 'J':
                {
                    cout << "Length of list: " << l->getSize() << endl;
                    break;
                }
            case 'K':
                {
                    l->display();
                    break;
                }
            case 'L':
                {
                  l->actionFile();
                  break;
                }
        }
        cout << "If you want to run again. Press '0'." << endl;
        cin >> a;
        system("clear");
    }
    while (a == '0');
    return 0;
}
