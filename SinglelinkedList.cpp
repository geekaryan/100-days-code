// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node *&head, int data)
{

    // new node create
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToinsert = new Node(d);

    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {

        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// For detecting loop in singly linked lists
bool detectLoop(Node *head)
{

    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return 1;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

// floyd loop detection

Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            cout << "present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

// getting starting node
Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *intersection = floydDetectLoop(head);
    if (intersection == NULL)
    {
        return NULL;
    }
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

// remove loop
void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL)
    {
        return head;
    }
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

int main()
{

    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(tail, head, 3, 22);
    print(head);

    deleteNode(1, head);
    print(head);

    // manually used for making loops
    tail->next = head->next;

    // detecting whether the loop is present or not
    if (detectLoop(head))
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    removeLoop(head);
    print(head);

    return 0;
}