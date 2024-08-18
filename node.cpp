#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *next;
};

Node *headNode = NULL;
Node *currentNode = NULL;

bool isEmpty() {
    return (headNode == NULL);
}

void insertNode(string data) {
    Node *newNode = new Node;
    newNode->data = data;
    if (isEmpty()) {
        headNode = newNode;
    } else {
        currentNode->next = newNode;
    }
    currentNode = newNode;
    currentNode->next = NULL;
    cout << "Node berhasil ditambahkan" << endl << endl;
}

void deleteFromFront() {
    if (!isEmpty()) {
        Node *hapusNode = headNode;
        headNode = headNode->next;
        delete hapusNode;
        if (headNode == NULL) {
            currentNode = NULL;
        }
        cout << "Node berhasil dihapus dari depan" << endl;
    } else {
        cout << "List masih kosong !!!" << endl;
    }
}

void deleteFromEnd() {
    if (isEmpty()) {
        cout << "List masih kosong !!!" << endl;
        return;
    }
    if (headNode == currentNode) {
        delete headNode;
        headNode = NULL;
        currentNode = NULL;
    } else {
        Node *bantu = headNode;
        while (bantu->next != currentNode) {
            bantu = bantu->next;
        }
        delete currentNode;
        currentNode = bantu;
        currentNode->next = NULL;
    }
    cout << "Node berhasil dihapus dari belakang" << endl;
}

void deleteAll() {
    if (isEmpty()) {
        cout << "List masih kosong !!!" << endl;
        return;
    }
    Node *bantu = headNode;
    Node *hapusNode;
    while (bantu != NULL) {
        hapusNode = bantu;
        bantu = bantu->next;
        delete hapusNode;
    }
    headNode = NULL;
    currentNode = NULL;
    cout << "Semua node berhasil dihapus" << endl;
}

void printNode() {
    if (isEmpty()) {
        cout << "List masih kosong !!!" << endl;
        return;
    }
    Node *awalNode = headNode;
    int i = 1;
    while (awalNode != NULL) {
        cout << "Data pada node #" << i << " = " << awalNode->data << endl;
        awalNode = awalNode->next;
        i++;
    }
}

void menu() {
    int pilihan;
    string data;
    do {
        cout << ">>>> PILIHAN MENU SINGLY LINKED LIST <<<<" << endl;
        cout << "1. menambahkan node" << endl;
        cout << "2. menghapus node dari depan" << endl;
        cout << "3. menghapus node dari belakang" << endl;
        cout << "4. mengosongkan node" << endl;
        cout << "5. menampilkan node" << endl;
        cout << "6. selesai" << endl;
        cout << endl;
        cout << "masukkan pilihan anda: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                for (int i = 0; i < 5; ++i) {
                    cout << "masukkan data: ";
                    cin >> data;
                    insertNode(data);
                }
                break;
            case 2:
                deleteFromFront();
                cout << endl;
                break;
            case 3:
                deleteFromEnd();
                cout << endl;
                break;
            case 4:
                deleteAll();
                cout << endl;
                break;
            case 5:
                printNode();
                cout << endl;
                break;
            case 6:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Menu yang Anda pilih tidak terdaftar !!!" << endl << endl;
        }
    } while (pilihan != 6);
}

int main() {
    menu();
    return 0;
}

