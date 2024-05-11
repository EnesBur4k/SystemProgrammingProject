#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Bağlı listenin düğüm yapısı
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev; // Yeni bir 'prev' işaretçisi ekliyoruz
};

// Yeni düğüm oluşturma fonksiyonu
struct Node *createNode(char data);

// Bağlı listeye eleman ekleme fonksiyonu
void insert(struct Node **headRef, char data);

// Bağlı listeyi yazdırma fonksiyonu
void printList(struct Node *node);

// Bağlı listeden eleman silme fonksiyonu
void deleteNode(struct Node *delNode);

#endif
