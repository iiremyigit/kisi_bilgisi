#include <stdio.h>
#include <stdlib.h>

struct DTarih {
    int gun;
    int ay;
    int yil;
};

struct sahis_bilgileri {
    char adi[50];
    struct DTarih dogum_tarihi;
};

int
main() {
    printf("kisi sayisi girin: ");
    int kisisayisi;

    scanf("%d", & kisisayisi);
    struct sahis_bilgileri bilgiler[kisisayisi];
    printf("Bilgileri giriniz: \n");
    int yesienbuyukIndex = -1;
    for (int i = 0; i < kisisayisi; i++) {

        struct sahis_bilgileri s;

        printf("\nAdi: ");
        scanf("%s", s.adi);
        printf("Gun: ");
        scanf("%d", &s.dogum_tarihi.gun);
        printf("Ay: ");
        scanf("%d", &s.dogum_tarihi.ay);
        printf("Yil: ");
        scanf("%d", &s.dogum_tarihi.yil);
        printf("\n");
        
        bilgiler[i]=s;
        
        if (i == 0) {
            yesienbuyukIndex = 0;
        } else {
            struct sahis_bilgileri kisi = s;
            struct sahis_bilgileri yesienbuyuk = bilgiler[yesienbuyukIndex];
            if (kisi.dogum_tarihi.yil < yesienbuyuk.dogum_tarihi.yil) {
                yesienbuyukIndex = i;
            } else if (kisi.dogum_tarihi.yil == yesienbuyuk.dogum_tarihi.yil) {
                if (kisi.dogum_tarihi.ay < yesienbuyuk.dogum_tarihi.ay) {
                    yesienbuyukIndex = i;
                } else if (kisi.dogum_tarihi.ay == yesienbuyuk.dogum_tarihi.ay) {
                    if (kisi.dogum_tarihi.gun < yesienbuyuk.dogum_tarihi.gun) {
                        yesienbuyukIndex = i;
                    }
                }
            }
        }
    }
    printf("\nKayitlar Yazdiriliyor....\n");
    for (int i = 0; i < kisisayisi; i++) {
        printf("\n");
        printf("Adi: ");
        printf("%s\n", bilgiler[i].adi);
        printf("Dogum tarihi: ");
        printf("%d.%d.%d\n", bilgiler[i].dogum_tarihi.gun,
               bilgiler[i].dogum_tarihi.ay, bilgiler[i].dogum_tarihi.yil);
        printf("\n");
    }
    printf("\nYasi en buyuk kisi:\n");
    printf("\n");
    printf("adi: ");
    printf("%s\n", bilgiler[yesienbuyukIndex].adi);
    printf("Dogum tarihi: ");
    printf("%d.%d.%d\n", bilgiler[yesienbuyukIndex].dogum_tarihi.gun,
           bilgiler[yesienbuyukIndex].dogum_tarihi.ay, bilgiler[yesienbuyukIndex].dogum_tarihi.yil);
    printf("\n");

}
