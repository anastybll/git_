// ���� ������. ������� ���� �� ����� �� ���� X.
#include <iostream>

using namespace std;

struct tree
{
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x)
{ //��������� ����
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x)
{ //�������
    tree* n = node(x);
    if (!tr)
        tr = n;
    else
    {
        tree* y = tr;
        while (y)
        {
            if (n->inf > y->inf)
                if (y->right)
                    y = y->right;
                else
                {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)
                if (y->left)
                    y = y->left;
                else
                {
                    n->parent = y;
                    y->left = n;
                    break;
                }
        }
    }
}

void inorder(tree* tr)
{ //������������ �����
    if (tr)
    {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

tree* find(tree* tr, int x)
{                            //�����
    if (!tr || x == tr->inf) //����� ��� ����� �� ����� �����
        return tr;
    if (x < tr->inf)
        return find(tr->left, x); //���� �� ����� �����
    else
        return find(tr->right, x); //���� �� ������ �����
}

void pathToNode(tree* tr, int x)
{
    cout << tr->inf << " ";
    if (x == tr->inf)
        return;
    else if (x < tr->inf)
        pathToNode(tr->left, x);
    else
        pathToNode(tr->right, x);
}

int main()
{
    int n, x;
    cout << "n = ";
    cin >> n;
    tree* Tree = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        cin >> x;
        insert(Tree, x);
    }
    cout << "Tree: ";
    inorder(Tree);
    cout << endl
        << "Path to node: ";
    cin >> x;
    if (find(Tree, x))
        pathToNode(Tree, x);
    cout << endl;
    return 0;
}