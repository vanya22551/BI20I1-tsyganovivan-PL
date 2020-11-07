#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

struct list {
    int field;
    struct list* left;
    struct list* right;
};

struct list* init() {
    int field;
    struct list* list;
    list = new struct list;
    field = 3;
    list->field = field;
    list->left = NULL;
    list->right = NULL;
    return list;
}

struct list* additem(list* parent) {
    int data = rand() % 101;

    struct list* temp;
    temp = init();
    if (parent->field > data) {
        parent->right = temp;
    }
    else if (parent->field < data) {
        parent->left = temp;
    }
    else {
        delete temp;
    }
    return parent;
}

struct list* addItemManual(list* root, int data) {
    struct list* temp;
    struct list* temp1;
    int lft, rght;
    lft = 0; rght = 0;
    temp = init();
    temp->field = data;
    temp1 = root;
    while (temp1->left != NULL and temp1->right != NULL) {
        if (temp1->field > data) {
            temp1 = temp1->left;
            
        }
        else if (temp1->field < data) {
            temp1 = temp1->right;
           
        }
    }
    if (temp1->field > data) {
        temp1->left = temp;
    }
    else if (temp1->field < data) {
        temp1->right = temp;
    }
    return root;
    cout<< lft << " "<< rght;
}


struct list* deleteitem(list* del_item, list* root) {
    struct list* temp;
    temp = root;
    while (temp->left != del_item) {
        temp = temp->left;
    }
    temp->left = del_item->left;
    delete del_item;
    return temp;
}

struct list* deleteItemByValue(list* root, int data) {
    struct list* temp;
    struct list* temp1;
    temp1 = root;
    bool flag = true;
    while (data != temp1->left->field and data != temp1->right->field) {
        if (temp1->field > data) {
            temp1 = temp1->left;
        }
        else if (temp1->field < data) {
            temp1 = temp1->right;
        }
        else {

            flag = false;
        }

    }
    if (temp1->left->field == data) {
        delete temp1->left;
        temp1->left = NULL;
    }
    else {
        delete temp1->right;
        temp1->right = NULL;
    }

    return NULL;
}

void treeprint(list* lst)
{
    
    if (lst != NULL)
    {
        cout << lst->field;
        treeprint(lst->left);
        treeprint(lst->right);
    }
}



int main() {
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    struct list* temp, * root;
    root = init();
    temp = root;
    struct list* del_item;
    temp = addItemManual(root, 1);
    temp = addItemManual(root, 5);
    temp = addItemManual(root, 4);
    temp = addItemManual(root, 8);
    temp = addItemManual(root, 2);
    temp = addItemManual(root, 0);
    
    temp = addItemManual(temp, 9);
    //listprint(root);
    treeprint(root);
    
    return 0;
}


