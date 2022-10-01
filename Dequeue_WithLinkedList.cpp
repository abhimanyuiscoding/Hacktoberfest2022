#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node *next;
};

node *rear = NULL;
node *front = NULL;

node *fnq()
{
    if (front == NULL)
    {
        node *m = new node;
        cout << "enter the value: ";
        cin >> m->value;

        m->next = NULL;
        front = m;
        rear = front;
        return front;
    }
    else
    {
        node *m = new node;
        cout << "enter the value: ";
        cin >> m->value;

        m->next = front;
        front = m;
        return m;
    }
}
node *fdq()
{
    if (front == NULL)
    {
        cout << "the QUEUE is empty" << endl;
        return NULL;
    }
    else
    {
        if (front->next != NULL)
        {
            node *m = front;

            cout << "the poped element is: " << m->value << endl;
            front = front->next;
            free(m);
            return front;
        }
        else
        {
            cout << "the poped element is: " << front->value << endl;
            free(front);
            return NULL;
        }
    }
}
node *rnq()
{
    if (front == NULL)
    {
        node *m = new node;
        cout << "enter the value: ";
        cin >> m->value;

        m->next = NULL;
        rear = m;
        front = m;
        return front;
    }
    else
    {
        node *m = new node;

        cout << "enter the value: ";
        cin >> m->value;
        m->next = NULL;

        rear->next = m;
        rear = m;
        return front;
    }
}
node *rdq()
{
    if (front == NULL)
    {
        cout << "the QUEUE is empty" << endl;
        return NULL;
    }

    else
    {
        if (front->next == NULL)
        {
            cout << "the poped element is: " << front->value << endl;
            free(front);
            return NULL;
        }
        else
        {
            node *m = front;
            while (m->next != rear)
            {
                m = m->next;
            }
            cout << "the poped element is: " << rear->value << endl;
            rear = m;
            free(m->next);
            rear->next = NULL;
            return front;
        }
    }
}
void display()
{
    if (front != NULL)
    {
        node *m = front;
        cout << "The element(s) in QUEUE:" << endl;
        while (m->next != NULL)
        {
            printf("%d ", m->value);
            m = m->next;
        };
        cout << m->value << endl;
    }
    else
        cout << "The QUEUE is empty" << endl;
}
int main()
{
    cout << "\n1. fenqueue\n2. fdqueue\n3. renqueue\n4. rdqueue\n5. display\n6. EXIT\n";
    int n;

    do
    {
        printf("\nenter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            front = fnq();
            break;

        case 2:
            front = fdq();
            break;

        case 3:
            front = rnq();
            break;

        case 4:
            front = rdq();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("\n______EXIT POINT______\n ");
            break;

        default:
            printf("INVALID CHOICE\n");
            break;
        }

    } while (n != 6);

    return 0;
}
