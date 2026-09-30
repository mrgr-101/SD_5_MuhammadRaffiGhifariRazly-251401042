#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int value;
    node* next;
};

node* head = NULL;
node* tail = NULL;

// Insert First
void insertFirst(int n){
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL){
        head = newnode;
        tail = newnode;
    }
    else {
        newnode -> next = head;
        head = newnode;
    }
}
// Insert Last
void insertLast(int n){
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL){
        head = newnode;
        tail = head;
    }
    else {
        tail -> next = newnode;
        tail = newnode;
    }

}
// Insert After
void insertAfter(int n, int check){
    if(head == NULL){
     cout << "list kosong!" << endl;
     return;
    }

    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    node *p = head;
    while (p != NULL && p -> value != check){
        p = p -> next;
    }

    if (p == NULL){
        cout << "Node dengan nilai " << check << "tidak ditemukan !" << endl ;
        delete newnode;
    }
    else {
        newnode -> next = p -> next;
        p -> next = newnode;
        if (p == tail){
            tail = newnode;
        }
    }
}

// Delete Fisrt
void deletefirst(){
    if (head == NULL){
        cout << "List Kosong !" << endl;
        return;
    }

    node *temp = head;
    head = head -> next;
    if (head == NULL) tail = NULL;
    delete temp;
}

// Delete Last
void deletelast(){
    if (head == NULL){
        cout << "List Kosong !" << endl;
        return;
    }

    if (head == tail){
        delete head;
        head = tail = NULL;
        return;
    }

    node *p = head;
    while (p -> next != tail){
        p = p -> next;
    }

    delete tail;
    tail = p;
    tail -> next = NULL;
}
// Delete Middle
void deletemiddle(int check){
    if (head == NULL){
        cout << "List Kosong !" << endl;
        return;
    }

    if (head->value == check){
        deletefirst();
        return;
    }

    node *p = head;

    while (p->next != NULL && p->next->value != check) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan" << endl;
    }
    else {
        node *temp = p->next;
        p->next = temp->next;

        if (temp == tail)
            tail = p;

        delete temp;
    }
}

void display(){
    node *temp  = head;
    cout << "List Linked List: \n ";
    while (temp != NULL){
        cout << temp -> value << "-> ";
        temp = temp -> next;
        
    }
}

int main() {
    system("cls");
    int pilih, nilai;

    do {
        cout << "IMPLEMENTASI QUEUE\n";
        cout << "1. Enqueue / Tambah Antrean)\n";
        cout << "2. Dequeue / Hapus Antrean\n";
        cout << "3. Tampilkan Antrean\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nilai untuk antrean (Enqueue): ";
                cin >> nilai;
                insertLast(nilai);
                cout << "Data " << nilai << " berhasil ditambahkan ke dalam antrean.\n";
                break;

            case 2:
                if (head == NULL) {
                    cout << "Antrean Kosong! Tidak ada data yang bisa di-dequeue.\n";
                } else {
                    cout << "Data terdepan (" << head->value << ") keluar dari antrean (Dequeue).\n";
                    deletefirst(); 
                }
                break;

            case 3:
                cout << "\n";
                display();
                cout << "NULL\n";
                break;

            case 4:
                cout << "Keluar dari program Queue.\n";
                break;

            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilih != 4);

    return 0;
}