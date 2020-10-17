

#include <iostream>
#include <time.h>


struct list {
    int data;
    struct list* subbling;

};

struct list* init() {
    int a;
    struct list* lst = new struct list;
    a = rand() % 20;
    lst->data = a;
    lst->subbling = NULL;
    return(lst);
}


struct list* additem(list* lst) {
    struct list* temp = init();
    lst->subbling = temp;
    temp->data = rand() % 20;
    return temp;
}

struct list* deleteitem(list* lst, list* root) {
    struct list* temp;
    temp = root;
    while (temp->subbling != lst) {
        temp = temp->subbling;

    }
    temp->subbling = lst->subbling;
    delete lst;
    return temp;
}



void listprint(list* root) {
    struct list* p;
    p = root;

    do {
        std::cout << p->data << " ";
        p = p->subbling;
    } while (p != NULL);

}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    setlocale(LC_ALL, "Russian");
    struct list* temp, *root;
    root = init();
    temp = root;
    struct list* p;
    for (int i = 1; i < 20; i++) {
        temp = additem(temp);
    }
    for (int n = 1; n < 16; n++) {
        p = root;
        p = p->subbling;
        
    }
    deleteitem(p, root);
    listprint(root);

    return(0);
}

