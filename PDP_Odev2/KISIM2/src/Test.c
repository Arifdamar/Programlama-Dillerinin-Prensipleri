/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Projenin test dosyasıdır
 * </p>
 */
#include "stdio.h"
#include "DosyaIslem.h"
#include "RastgeleKisi.h"

void KisiUret(DosyaIslem dosya)
{
    int kisiAdet;
    scanf("%d", &kisiAdet); // Kullanıcıdan kişi adeti alınır

    dosya->dosyaTemizle("Kisiler.txt");
    
    // Kullanıcının girdiği sayı * RASTGELEKISI boyutunda bellekten yer ayrılır
    RastgeleKisi *kisiler = (RastgeleKisi *)malloc(sizeof(struct RASTGELEKISI) * kisiAdet);
    int i;
    for (i = 0; i < kisiAdet; i++)
    {
        kisiler[i] = RastgeleKisiConstructor(); // Bellekteki ayrılan yerlerde RastgeleKisi oluşturulur
    }

    for (i = 0; i < kisiAdet; i++)
    {
        kisiler[i]->kisiOzellikAta(kisiler[i], dosya);                // Kişilerin rastgele özellikleri ataması yapılır
        kisiler[i]->kisileriDosyayaYazdir(kisiler[i], "Kisiler.txt"); // Rastgele özellikleri atanan kişiler "Kisiler.txt" dosyasına yazdırılır
    }

    for (i = 0; i < kisiAdet; i++)
    {
        kisiler[i]->Yoket(kisiler[i]); // Her RastgeleKisi bellekten tek tek temizlenir
    }
    free(kisiler);
}

void UretilmisDosyaKontrolEt(DosyaIslem dosya)
{
    dosya->uretilmisDosyaOku(dosya); // Üretilmiş dosya okunur
    dosya->kontrol(dosya);           // Okunan dosya kontrol edilir
}

int main()
{

    DosyaIslem dosya = DosyaIslemConstructor();

    int secim;

    do
    {
        printf("1-Rastgele Kisi Uret\n");
        printf("2-Uretilmis Dosya Kontrol Et\n");
        printf("3-Cikis\n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            KisiUret(dosya); // Rastgele kişi üretmek için metod çağrılır
            break;

        case 2:
            UretilmisDosyaKontrolEt(dosya); // Üretilmiş dosyayı kontrol etmek için metod çağrılır
            break;

        default:
            break;
        }
    } while (secim != 3);

    return 0;
}