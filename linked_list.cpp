#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};
node *head = NULL;

//---------------------------------------------------------------------------

void insert_tail(node *&Node = head, int value = 0)
{
    node *n = new node(value);

    if (Node == NULL)
    {
        Node = n;
        return;
    }
    else
    {
        node *temp = Node;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        return;
    }
}

void insert_tail_circular(node *&Node = head, int value = 0)
{
    node *n = new node(value);

    if (Node == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    else
    {
        node *temp = Node;
        while (temp->next != Node)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
        return;
    }
}

//---------------------------------------------------------------------------

void insert_head(node *&Node = head, int value = 0)
{
    node *n = new node(value);

    n->next = Node;
    Node = n;
    return;
}

void insert_head_circular(node *&Node = head, int value = 0)
{
    node *n = new node(value);

    if (Node == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    else
    {
        node *temp = Node;
        while (temp->next != Node)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = Node;
        Node = n;
        return;
    }
}

//---------------------------------------------------------------------------

bool search(node *Node = head, int key = 0)
{
    node *temp = Node;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << " present ";
            return true;
        }
        temp = temp->next;
    }
    cout << "  not present ";
    return false;
}

bool search_circular(node *Node = head, int key = 0)
{
    node *temp = Node;
    if (temp->data == key)
    {
        cout << " present ";
        return true;
    }

    else
    {
        temp = temp->next;
        while (temp != Node)
        {
            if (temp->data == key)
            {
                cout << " present ";
                return true;
            }
            temp = temp->next;
        }
        cout << "  not present ";
        return false;
    }
}

//---------------------------------------------------------------------------

void delete_head()
{
    node *to_delete = head;
    head = head->next;
    delete to_delete;
    return;
}

void deletion(node *&Node = head, int value = 0)
{
    if (Node == NULL)
    {
        return;
    }
    else if (Node->data == value || Node->next == NULL)
    {
        delete_head();
        return;
    }

    node *temp = Node;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    node *to_delete = temp->next;
    temp->next = temp->next->next;

    delete to_delete;
    return;
}

void delete_head_circular()
{
    node *to_delete = head;
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    delete to_delete;
    return;
}

void deletion_circular(node *&Node = head, int value = 0)
{
    if (Node == NULL)
    {
        return;
    }
    else if (Node->data == value || Node->next == NULL)
    {
        delete_head_circular();
        return;
    }

    node *temp = Node;
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    node *to_delete = temp->next;
    temp->next = temp->next->next;

    delete to_delete;
    return;
}

//---------------------------------------------------------------------------

node *reverse_recursive(node *Node = head)
{

    if (Node == NULL || Node->next == NULL)
    {
        return Node;
    }

    node *new_head = reverse_recursive(Node->next);

    Node->next->next = Node;
    Node->next = NULL;

    head = new_head;
    return head;
}

//---------------------------------------------------------------------------

node *reverse_N_nodes(node *Node = head, int k = 0)
{
    node *prev = NULL;
    node *current = Node;
    node *Next;

    int count = 0;

    while (current != NULL && count < k)
    {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
        count = count + 1;
    }

    if (Next != NULL)
    {
        Node->next = reverse_N_nodes(Next, k);
    }

    head = prev;
    return head;
}

//---------------------------------------------------------------------------

bool detect_cycle(node *&Node = head)
{
    node *slow = Node;
    node *fast = Node;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;

        if (fast == slow)
        {
            cout << "cycle present";
            return true;
        }
    }
    cout << "cycle not present";
    return false;
}

void remove_cycle(node *&Node = head)
{
    node *slow = Node;
    node *fast = Node;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = Node;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
    return;
}

//---------------------------------------------------------------------------

int length(node *&Node = head)
{
    int l = 0;
    node *temp = Node;
    while (temp != NULL)
    {
        l = l + 1;
        temp = temp->next;
    }
    return l;
}

node *k_append(node *&Node = head, int k = 0)
{
    node *new_head;
    node *new_tail;
    node *tail = Node;

    int l = length(Node);
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            new_tail = tail;
        }
        if (count == l - k + 1)
        {
            new_head = tail;
        }
        tail = tail->next;
        count = count + 1;
    }
    new_tail->next = NULL;
    tail->next = Node;

    Node = new_head;
    return Node;
}

//---------------------------------------------------------------------------

int intersection(node *&head_1, node *&head_2)
{
    int l1 = length(head_1);
    int l2 = length(head_2);

    int d = 0;

    node *ptr_1;
    node *ptr_2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr_1 = head_1;
        ptr_2 = head_2;
    }
    else
    {
        d = l2 - l1;
        ptr_1 = head_2;
        ptr_2 = head_1;
    }

    while (d)
    {
        ptr_1 = ptr_1->next;
        if (ptr_1 == NULL)
        {
            return -1;
        }
        d = d - 1;
    }

    while (ptr_1 != NULL && ptr_2 != NULL)
    {
        if (ptr_1 == ptr_2)
        {
            return ptr_1->data;
        }
        ptr_1 = ptr_1->next;
        ptr_2 = ptr_2->next;
    }
    return -1;
}

//---------------------------------------------------------------------------

node *merge(node *&Node_1, node *&Node_2)
{
    node *p1 = Node_1;
    node *p2 = Node_2;
    node *dummy_node = new node(-1);
    node *p3 = dummy_node;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy_node->next;
}

node *recursive_merge(node *&Node_1, node *&Node_2)
{
    if (Node_1 == NULL)
    {
        return Node_2;
    }
    if (Node_2 == NULL)
    {
        return Node_1;
    }

    node *result;
    if (Node_1->data < Node_2->data)
    {
        result = Node_1;
        result->next = recursive_merge(Node_1->next, Node_2);
    }
    else
    {
        result = Node_2;
        result->next = recursive_merge(Node_1, Node_2->next);
    }
    return result;
}

//---------------------------------------------------------------------------

void even_after_odd(node *Node)
{
    node *odd = Node;
    node *even = Node->next;
    node *even_start = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_start;
    if (odd->next == NULL)
    {
        even->next = NULL;
    }
    return;
}

//---------------------------------------------------------------------------

void display(node *&Node)
{
    node *temp = Node;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << " NULL " << endl;

    return;
}

void display_cirular(node *&Node)
{
    node *temp = Node;
    cout << temp->data << "->";
    temp = temp->next;

    while (temp != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << " NULL " << endl;

    return;
}

int main()
{
    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 5);
    insert_head(head, 6);
    insert_head(head, 7);
    display(head);
    even_after_odd(head);
    display(head);
}