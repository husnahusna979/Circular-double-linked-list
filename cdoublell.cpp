#include <iostream>
using namespace ::std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *insertend(int k, struct node *root)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    temp->data = k;
    if (root == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        root = temp;
        return root;
    }
    temp->next = root;
    p = root->prev;
    p->next = temp;
    temp->prev = p;
    root->prev = temp;
    return root;
}
struct node *insertbegin(int k, struct node *root)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    temp->data = k;
    if (root == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        root = temp;
        return root;
    }
    p = root->prev;
    root->prev = temp;
    p->next = temp;
    temp->prev = p;
    temp->next = root;
    root = temp;
    return root;
}
struct node *delend(struct node *root)
{
    struct node *p;
    struct node *q;
    if (root == NULL)
    {
        cout << "cdll is empty";
        return root;
    }
    cout << "my root is :" << root->data;
    p = root->prev;
    q = p->prev;
    q->next = root;
    root->prev = q;
    p->prev = NULL;
    p->next = NULL;
    free(p);
    if (root->prev == NULL && root->next == NULL)
    {
        root = NULL;
        free(root);
        free(q);
    }
    return root;
}
struct node *delbegin(struct node *root)
{
    struct node *p;
    struct node *q;
    if (root == NULL)
    {
        cout << "cdll is empty";
        return root;
    }
    cout << "my root is :" << root->data;
    p = root->prev;
    q = root->next;
    p->next = q;
    q->prev = p;
    root->prev = NULL;
    root->next = NULL;
    root = q;
    if (root->prev == NULL && root->next == NULL)
    {
        root = NULL;
        free(root);
        free(p);
        free(q);
    }
    return root;
}
struct node *insertafter(int k, int m, struct node *root)
{
    int c = 0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    struct node *q;
    temp->data = k;
    if (root == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        root = temp;
        return root;
    }
    p = root;
    do
    {
        if (p->data == m)
        {
            c++;
            break;
        }
        else
            p = p->next;
    } while (p != root);
    if (p == root && c == 0)
        cout << "element not found";
    else
    {
        q = p->next;
        temp->prev = p;
        temp->next = q;
        p->next = temp;
        q->prev = temp;
    }

    return root;
}
struct node *delafter(int m, struct node *root)
{
    struct node *p;
    struct node *q;
    struct node *r;
    int c = 0;
    if (root == NULL)
    {
        cout << "cdll is empty";
        return root;
    }
    cout << "my root is :" << root->data;
    p = root;
    do
    {
        if (p->data == m)
        {
            c++;
            break;
        }
        else
            p = p->next;
    } while (p != root);
    if (p == root && c == 0)
        cout << "element not found";
    else
    {
        q = p->prev;
        r = p->next;
        q->next = r;
        r->prev = q;
        p->prev = NULL;
        p->next = NULL;
        free(p);
    }
    if (root->prev == NULL && root->next == NULL)
    {
        root = NULL;
        free(root);
        free(q);
        free(r);
    }
    return root;
}
void print(struct node *root)
{
    struct node *p = root;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != root);
    cout << endl;
}
void revprint(struct node *root)
{
    struct node *p = root;
    cout << "\n IN REVERSE ";
    do
    {
        cout << p->data << " ";
        p = p->prev;
    } while (root != p);
    cout << endl;
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = NULL;
    int k, s, m;
    char c;
    do
    {
        cout << "insert an element";
        cin >> k;
        cout << "enter 1 for beginng, 2 for end, 3 for insert after, 4 to skip" << endl;
        cin >> s;
        if (s == 1)
            root = insertbegin(k, root);
        else if (s == 2)
            root = insertend(k, root);
        else if (s == 3)
        {
            print(root);
            cout << "say the ele after which you want to insert";
            cin >> m;
            root = insertafter(k, m, root);
        }
        cout << "insert again: y  or n" << endl;
        cin >> c;
    } while (c == 'y');
    print(root);
    do
    {
        cout << "delete an element";
        cout << "enter 1 for beginng and 2 for end, 3 del middle ele, 4 to skip: " << endl;
        cin >> s;
        if (s == 1)
            root = delbegin(root);
        else if (s == 2)
            root = delend(root);
        else if (s == 3)
        {
            print(root);
            cout << "say the ele which you want to delete";
            cin >> m;
            root = delafter(m, root);
        }
        cout << "delete again: y  or n" << endl;
        cin >> c;
    } while (c == 'y');
    print(root);
    root = root->prev;
    revprint(root);
    return 0;
}