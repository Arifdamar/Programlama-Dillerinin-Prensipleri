/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Telefon kaynak dosyası
 * </p>
 */
#include "Telefon.h"
#include "IMEINo.h"
#include "Rastgele.h"

// Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
Telefon TelefonConstructor()
{
    Telefon this; // Bir Telefon referansı oluşturulur

    // Bellekte RASTGELE boyutunda yer açılır ve RASTGELE* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (Telefon)malloc(sizeof(struct TELEFON));

    this->telefonNo = (int *)malloc(sizeof(int) * 11);         // heap'te olusturuldu, yoket metodunda temizlendi
    this->telefonNoString = (char *)malloc(sizeof(char) * 11); // heap'te olusturuldu, yoket metodunda temizlendi
    this->imeiNo = IMEINoConstructor();                        // heap'te olusturuldu, yoket metodunda temizlendi

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->telefonNoOlustur = &_telefonNoOlustur;
    this->getTelefonNo = &_getTelefonNo;
    this->getTelefonNoString = &_getTelefonNoString;
    this->getImei = &_getImei;
    this->Yoket = &TelefonYoket;

    // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
    return this;
}

void _telefonNoOlustur(const Telefon this)
{
    Rastgele rastgele = RastgeleConstructor(); // Rastgele sayı üretebilmek için Rastgele nesnesi oluşturulur

    this->telefonNo[0] = 0; // Telefonun 0. indisine 0 atanır
    this->telefonNoString[0] = '0';

    this->telefonNo[1] = 5; // Telefonun 1. indisine 5 atanır
    this->telefonNoString[1] = '5';

    // Türkiye'deki telefon numaralarına uygun olacak şekilde rastgele telefon numarası üretme işlemleri yapılır
    this->telefonNo[2] = rastgele->sayiOlustur(10);
    while (this->telefonNo[2] != 3 && this->telefonNo[2] != 4 && this->telefonNo[2] != 0 && this->telefonNo[2] != 5)
    {
        this->telefonNo[2] = rastgele->sayiOlustur(10);
    }
    this->telefonNoString[2] = this->telefonNo[2] + '0';

    if (this->telefonNo[2] == 0)
    {
        this->telefonNo[3] = rastgele->sayiOlustur(10);
        while (this->telefonNo[3] != 1 && this->telefonNo[3] != 5 && this->telefonNo[3] != 6 && this->telefonNo[2] != 7)
        {
            this->telefonNo[3] = rastgele->sayiOlustur(10);
        }
        this->telefonNoString[3] = this->telefonNo[3] + '0';
        for (int i = 4; i < 11; i++)
        {
            this->telefonNo[i] = rastgele->sayiOlustur(10);
            this->telefonNoString[i] = this->telefonNo[i] + '0';
        }
    }
    else if (this->telefonNo[2] == 3)
    {
        for (int i = 3; i < 11; i++)
        {
            this->telefonNo[i] = rastgele->sayiOlustur(10);
            this->telefonNoString[i] = this->telefonNo[i] + '0';
        }
    }
    else if (this->telefonNo[2] == 4)
    {
        for (int i = 3; i < 11; i++)
        {
            this->telefonNo[i] = rastgele->sayiOlustur(10);
            this->telefonNoString[i] = this->telefonNo[i] + '0';
        }
    }
    else if (this->telefonNo[2] == 5)
    {
        this->telefonNo[3] = rastgele->sayiOlustur(10);
        while (this->telefonNo[3] != 2 && this->telefonNo[3] != 3 && this->telefonNo[3] != 4 && this->telefonNo[3] != 5 && this->telefonNo[3] != 9)
        {
            this->telefonNo[3] = rastgele->sayiOlustur(10);
        }
        this->telefonNoString[3] = this->telefonNo[3] + '0';
        for (int i = 4; i < 11; i++)
        {
            this->telefonNo[i] = rastgele->sayiOlustur(10);
            this->telefonNoString[i] = this->telefonNo[i] + '0';
        }
    }
    rastgele->Yoket(rastgele);
}
int *_getTelefonNo(const Telefon this)
{
    return this->telefonNo;
}
char *_getTelefonNoString(const Telefon this)
{
    return this->telefonNoString;
}
IMEINo _getImei(const Telefon this)
{
    return this->imeiNo;
}
void TelefonYoket(Telefon this)
{
    if (this == NULL)
        return;
    free(this->telefonNo); // telefonNo iade edilir
    free(this->telefonNoString); // telefonNoString iade edilir
    free(this->imeiNo); // imeiNo iade edilir
    free(this); // this iade edilir
}