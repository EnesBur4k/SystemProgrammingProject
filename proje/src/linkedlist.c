#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Yeni düğüm oluşturma fonksiyonu
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Hata: Bellek tahsisi yapilamadi.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // 'prev' işaretçisini NULL olarak ayarlıyoruz
    return newNode;
}

// Bağlı listeye eleman ekleme fonksiyonu
void insert(struct Node** headRef, char data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL)
        (*headRef)->prev = newNode; // Eğer başlangıç düğümü varsa, onun 'prev' işaretçisini güncelliyoruz
    *headRef = newNode;
}

// Bağlı listeyi yazdırma fonksiyonu
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

