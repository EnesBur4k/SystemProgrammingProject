#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"     // fields.h kütüphanesini dahil et
#include "linkedlist.h" //bağlı liste kütüphanesini dahil et

struct Node *head = NULL;
IS is; // Input struct

void write(char karakter, int sayi, struct Node **headRef)
{
    for (int i = 0; i < sayi; i++)
    {
        insert(headRef, karakter);
    }
}

void delete_chars(char karakter, int sayi, struct Node **headRef)
{
    struct Node *current = *headRef;
    int count = 0;
    while (current->next != NULL)
    {
        if (current->data == karakter)
        {
            count++;
        }
        current = current->next;
    }
    if (current->data == karakter)
    {
        count++;
    }
    if (sayi <= count)
    {
        struct Node *current2 = *headRef;
        while (current2 != NULL && sayi > 0)
        {
            if (current2->data == karakter)
            {
                struct Node *delNode = current2;
                current2 = current2->next;
                deleteNode(delNode);
                sayi--;
                continue;
            }
            current2 = current2->next;
        }
        *headRef = current2;
    }
    else{
        // Buraya silme işleminde silinecek sayısı listedeki eleman sayısından daha fazlaysa head'in satır başına geleceği kodu yaz.
        // while((*headRef)->next != NULL || strcmp((*headRef)->next->data,"\n") != 0)
        // {
        //     (*headRef) = (*headRef)->next;
        // }
    }
}

void printListToFile(struct Node *node, FILE *dosya)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    while (node != NULL)
    {
        fprintf(dosya, "%c", node->data);
        node = node->prev;
    }
}

int main(int argc, char *argv[])
{
    int i = 1;
    char *girisDosyasi = NULL; // İşaretçiyi NULL olarak başlatın

    // Komut satırından argüman alındı mı kontrol edin
    if (argv[1] != NULL)
    {
        girisDosyasi = malloc(strlen(argv[1]) + 1); // Bellek tahsis edin
        if (girisDosyasi == NULL)
        {
            printf("Bellek tahsisi basarisiz.\n");
            return 1;
        }
        strcpy(girisDosyasi, argv[1]); // Argümanı kopyalayın
    }
    else
    {
        girisDosyasi = malloc(strlen("giris.dat") + 1); // Bellek tahsis edin
        if (girisDosyasi == NULL)
        {
            printf("Bellek tahsisi basarisiz.\n");
            return 1;
        }
        strcpy(girisDosyasi, "giris.dat"); // Varsayılan dosya adını kopyalayın
    }
    FILE *outputFile;
    int sayi;
    char komut[100], karakter;

    // Giriş dosyasını aç ve kontrol et
    if ((is = new_inputstruct(girisDosyasi)) == NULL)
    {
        printf("Giris dosyasi acilamadi.\n");
        return 1;
    }

    // Çıkış dosyasını aç ve kontrol et
    outputFile = fopen("cikis.dat", "w+");
    if (outputFile == NULL)
    {
        printf("Cikis dosyasi olusturulamadi.\n");
        return 1;
    }
    // Her satırı oku ve işle
    while (get_line(is) >= 0)
    {
        strcpy(komut, is->fields[0]);
        if (strcmp(komut, "yaz:") == 0)
        {
            i = 1;
            while (is->fields[i] != NULL)
            {
                sayi = atoi(is->fields[i]);
                karakter = is->fields[i + 1][0];
                if (karakter == '\\' && is->fields[i + 1][1] == 'n')
                {
                    write('\n', sayi, &head); // Alt satıra geç
                }
                else if (karakter == '\\' && is->fields[i + 1][1] == 'b')
                {
                    write(' ', sayi, &head); // boşluk bırak
                }
                else
                {
                    write(karakter, sayi, &head); // Normal karakter yazdırma
                }
                i += 2;
            }
        }
        else if (strcmp(komut, "sil:") == 0)
        {
            i = 1;
            // bu işlem
            while (is->fields[i] != NULL)
            {
                // Sadece bu satır için işlem yap
                karakter = is->fields[i + 1][0];
                sayi = atoi(is->fields[i]);
                delete_chars(karakter, sayi, &head); // Karakteri sil
                i = i + 2;
            }
        }
        else if (strcmp(komut, "sonagit:") == 0)
        {
            // bu işlem head'ı en başa götürecek.
            while (head->prev != NULL)
            {

                head = head->prev;
            }
        }
        else if (strcmp(komut, "dur:") == 0)
        {
            // bu işlem head'ı en başa götürecek.
            while (head->prev != NULL)
            {

                head = head->prev;
            }
            printListToFile(head, outputFile);
        }
        int a = 0;
        while (is->fields[a] != NULL)
        {
            is->fields[a] = NULL;
            a++;
        }
    }
    printList(head);

    // Dosyaları kapat
    jettison_inputstruct(is);
    fclose(outputFile);

    printf("\nIslem tamamlandi.\n");

    exit(0);
}
