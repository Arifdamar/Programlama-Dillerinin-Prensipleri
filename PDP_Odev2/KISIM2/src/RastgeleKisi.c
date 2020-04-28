/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * RastgeleKisi kaynak dosyası
 * </p>
 */
#include "RastgeleKisi.h"

// Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
RastgeleKisi RastgeleKisiConstructor()
{
    RastgeleKisi this; // Bir RastgeleKisi referansı oluşturulur

    // Bellekte RASTGELEKISI boyutunda yer açılır ve RASTGELEKISI* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));

    this->kisi = KisiConstructor();        // heap'te olusturuldu, yoket metodunda temizlendi
    this->dosya = DosyaIslemConstructor(); // heap'te olusturuldu, yoket metodunda temizlendi

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->kisiOzellikAta = &_kisiOzellikAta;
    this->kisileriDosyayaYazdir = &_kisileriDosyayaYazdir;
    this->Yoket = &RastgeleKisiYoket;

    // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
    return this;
}
void _kisiOzellikAta(const RastgeleKisi this, const DosyaIslem dosya)
{
    Rastgele rastgele = RastgeleConstructor();       // Rastgele sayı üretebilmek için Rastgele nesnesi oluşturulur
    int rastgeleIndex = rastgele->sayiOlustur(3000); // Rastgele isim ve soyisim için 0-3000 aralığında rastgele bir sayı üretilir

    dosya->icerikDosyaOku(dosya); // random_isimler.txt dosyası okunur

    // Dosya üzerinden alınan isim ve soyisimler kisi'ye atanır
    this->kisi->setIsim(this->kisi, dosya->isimler[rastgeleIndex]);
    this->kisi->setSoyIsim(this->kisi, dosya->soyIsimler[rastgeleIndex]);

    // 0-101 aralığında rastgele bir sayı oluşturulup yaş olarak atanır
    this->kisi->setYas(this->kisi, rastgele->sayiOlustur(101));

    // TC, Telefon ve IMEI yapılarının rastgele TC, Telefon ve IMEI oluşturma fonksiyonları çağrılır
    this->kisi->getTc(this->kisi)->tcKimlikOlustur(this->kisi->getTc(this->kisi));
    this->kisi->getTelefon(this->kisi)->telefonNoOlustur(this->kisi->getTelefon(this->kisi));
    this->kisi->getTelefon(this->kisi)->getImei(this->kisi->getTelefon(this->kisi))->imeiNoOlustur(this->kisi->getTelefon(this->kisi)->getImei(this->kisi->getTelefon(this->kisi)));

    rastgele->Yoket(rastgele); // rastgele iade edilir
}
void _kisileriDosyayaYazdir(const RastgeleKisi this, char *dosyaIsmi)
{
    // Kişi'nin yazılacak olan bilgileri ilgili stringe düzgün formatta atanır
    char *yazilacakIsim = this->kisi->getIsim(this->kisi);
    char *yazilacakSoyIsim = this->kisi->getSoyIsim(this->kisi);

    char *yazilacakYas = (char *)malloc(3); // heap'te olusturuldu, metodun sonunda temizlendi
    sprintf(yazilacakYas, "%d", this->kisi->getYas(this->kisi));

    char *yazilacakTc = this->kisi->getTc(this->kisi)->getKimlikNoString(this->kisi->getTc(this->kisi));
    char *yazilacakTelefon = this->kisi->getTelefon(this->kisi)->getTelefonNoString(this->kisi->getTelefon(this->kisi));
    char *yazilacakImei = this->kisi->getTelefon(this->kisi)->getImei(this->kisi->getTelefon(this->kisi))->getImeiNoString(this->kisi->getTelefon(this->kisi)->getImei(this->kisi->getTelefon(this->kisi)));

    char *yazilacak = (char *)malloc(100); // bellekte 100 char boyutunda yer açılır ve yazilacak'ın orayı göstermesi sağlanır

    // Yukarıda oluşan stringler "yazilacak" stringine uygun biçimde atanır
    strcpy(yazilacak, yazilacakTc);
    strcat(yazilacak, " ");

    strcat(yazilacak, yazilacakIsim);
    strcat(yazilacak, " ");

    strcat(yazilacak, yazilacakSoyIsim);
    strcat(yazilacak, " ");

    strcat(yazilacak, yazilacakYas);
    strcat(yazilacak, " ");

    strcat(yazilacak, yazilacakTelefon);
    strcat(yazilacak, " ");

    strcat(yazilacak, "(");
    strcat(yazilacak, yazilacakImei);
    strcat(yazilacak, ")");
    strcat(yazilacak, "\n");

    this->dosya->dosyaYaz(dosyaIsmi, yazilacak); // Oluşturulan "yazilacak" stringi dosyaya yazılır

    free(yazilacakYas); // yazilacakYas iade edilir
    free(yazilacak); // yazilacak iade edilir
}
void RastgeleKisiYoket(RastgeleKisi this)
{
    if (this == NULL)
        return;
    this->kisi->Yoket(this->kisi); // Kisi yapısının Yoket fonksiyonu çalıştırılır
    this->dosya->Yoket(this->dosya); // DosyaIslem yapısının Yoket fonksiyonu çalıştırılır
    free(this); // this iade edilir
}