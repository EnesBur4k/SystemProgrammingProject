#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Yeni düğüm oluşturma fonksiyonu
struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Hata: Bellek tahsisi yapilamadi.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // 'prev' işaretçisini NULL olarak ayarlıyoruz
    return newNode;
}

// Bağlı listeye eleman ekleme fonksiyonu
void insert(struct Node **headRef, char data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL)
        newNode->prev = (*headRef)->prev;
    if (*headRef != NULL)
        (*headRef)->prev = newNode; // Eğer başlangıç düğümü varsa, onun 'prev' işaretçisini güncelliyoruz
    *headRef = newNode;
}

// Bağlı listeden eleman silme fonksiyonu
void deleteNode(struct Node *delNode)
{
    if (delNode != NULL) // verilen node null mu kontrol eder
    {
        printf("Silinecek node: %c \n", delNode->data);
        if (delNode->prev == NULL && delNode->next == NULL) // verilen node'un tek node olduğu durum
        {
            free(delNode);
            return;
        }
        else if (delNode->prev == NULL) // verilen node'un başlangıç node olduğu durum
        {
            delNode->next->prev = NULL;
        }
        else if (delNode->next == NULL) // verilen node'un son node olduğu durum
        {
            delNode->prev->next = NULL;
        }
        else
        {
            delNode->next->prev = delNode->prev;
            delNode->prev->next = delNode->next;
        }
        free(delNode);
    }
}

// Bağlı listeyi yazdırma fonksiyonu
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%c -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
