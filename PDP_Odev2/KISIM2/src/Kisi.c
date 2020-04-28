/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Kisi kaynak dosyası
 * </p>
 */
#include "Kisi.h"

// Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
Kisi KisiConstructor()
{
    Kisi this; // Bir Kisi referansı oluşturulur

    // Bellekte KISI boyutunda yer açılır ve KISI* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (Kisi)malloc(sizeof(struct KISI));

    this->tcNo = KimlikNoConstructor();   // heap'te olusturuldu, yoket metodunda temizlendi
    this->telefon = TelefonConstructor(); // heap'te olusturuldu, yoket metodunda temizlendi

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->getIsim = &_getIsim;
    this->setIsim = &_setIsim;
    this->getSoyIsim = &_getSoyIsim;
    this->setSoyIsim = &_setSoyIsim;
    this->getYas = &_getYas;
    this->setYas = &_setYas;
    this->getTc = &_getTc;
    this->getTelefon = &_getTelefon;
    this->Yoket = &KisiYoket;

    // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
    return this;
}

// Alt alanların get ve set metodları tanımlanır
char *_getIsim(const Kisi this)
{
    return this->isim;
}
void _setIsim(const Kisi this, char *isim)
{
    this->isim = isim;
}
char *_getSoyIsim(const Kisi this)
{
    return this->soyIsim;
}
void _setSoyIsim(const Kisi this, char *soyisim)
{
    this->soyIsim = soyisim;
}
int _getYas(const Kisi this)
{
    return this->yas;
}
void _setYas(const Kisi this, int yas)
{
    this->yas = yas;
}
KimlikNo _getTc(const Kisi this)
{
    return this->tcNo;
}
Telefon _getTelefon(const Kisi this)
{
    return this->telefon;
}
void KisiYoket(Kisi this)
{
    if (this == NULL)
        return;
    this->getTc(this)->Yoket(this->getTc(this)); // KimlikNo yapısının Yoket fonksiyonu çalıştırılır
    this->getTelefon(this)->Yoket(this->getTelefon(this)); // Telefon yapısının Yoket fonksiyonu çalıştırılır
    free(this); // this iade edilir
}