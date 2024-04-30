#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h" // fields.h kütüphanesini dahil et

IS is; // Input struct

void write(char karakter, int sayi, FILE *file) {
    for (int i = 0; i < sayi; i++) {
        fprintf(file, "%c", karakter);
        printf("%c", karakter);
    }
}
void delete_chars(char karakter ,int sayi, FILE *file) {
    fseek(file, -sayi, SEEK_CUR); // Move backward by count characters
    long pos = ftell(file); // Son pozisyonu al
    char ch;
    for (int i = 0; i < sayi; i++) {
       	
        while (pos >= 0) { // Geriye doğru tarayarak karakteri bul
        fseek(file, pos, SEEK_SET);
        ch = fgetc(file);
        if (ch == karakter) {
            fseek(file, pos, SEEK_SET);
            fputc(' ', file); // Karakteri boşlukla değiştir
            break;
        }
        pos--;
    }
    
    }
    
}

int main() {
    FILE *outputFile;
    int sayi;
    char komut[100], karakter;

    // Giriş dosyasını aç ve kontrol et
    if ((is = new_inputstruct("giris.dat")) == NULL) {
        printf("Giris dosyasi acilamadi.\n");
        return 1;
    }

    // Çıkış dosyasını aç ve kontrol et
    outputFile = fopen("cikis.dat", "w+");
    if (outputFile == NULL) {
        printf("Cikis dosyasi olusturulamadi.\n");
        return 1;
    }

    // Her satırı oku ve işle
    while (get_line(is) >= 0) {
        strcpy(komut, is->fields[0]);
        if (strcmp(komut, "yaz:") == 0) {
            int i = 1;
            while (is->fields[i] != NULL) {
                sayi = atoi(is->fields[i]);
                karakter = is->fields[i + 1][0];
                if (karakter == '\\' && is->fields[i + 1][1] == 'n') {
                    write('\n', sayi, outputFile); // Alt satıra geç
                } else if (karakter == '\\' && is->fields[i + 1][1] == 'b') {
                    write(' ', sayi, outputFile); // boşluk bırak
                } else {
                    write(karakter, sayi, outputFile); // Normal karakter yazdırma
                }
                i += 2;
            }
        } else if (strcmp(komut, "sil:") == 0) {
    	int i = 1;
    	while (is->fields[i] != NULL ) {
        // Sadece bu satır için işlem yap
        	if (strcmp(is->fields[0], komut) == 0) {
            		karakter = is->fields[i+1][0];
            		sayi = atoi(is->fields[i]);
            		delete_chars(karakter, sayi, outputFile); // Karakteri sil
            		break;
        	}
        		i+=2;
    	}
	} else if (strcmp(komut, "sonagit:") == 0) {
     		fseek(outputFile, 0, SEEK_END); // Dosyanın sonuna git
	} else {
		break;
		} 
		



    }

    // Dosyaları kapat
    jettison_inputstruct(is);
    fclose(outputFile);

    printf("\nIslem tamamlandi.\n");

    exit(0);
}

