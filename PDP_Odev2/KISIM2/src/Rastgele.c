/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Rastgele kaynak dosyası
 * </p>
 */
#include "Rastgele.h"

// Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
Rastgele RastgeleConstructor()
{
    Rastgele this; // Bir Rastgele referansı oluşturulur

    // Bellekte RASTGELE boyutunda yer açılır ve RASTGELE* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (Rastgele)malloc(sizeof(struct RASTGELE));

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->sayiOlustur = &_sayiOlustur;
    this->Yoket = &RastgeleYoket;

    // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
    return this;
}
int _sayiOlustur(int maxSayi)
{
    static int a = 1;
    static int b = 1;
    static int i = 1;
    int seed;
    time_t t = time(NULL); // Bilgisayardaki o anki zaman tutan bir nesne oluşturulur

    // a, b ve i değerlerinin çok büyümesi durumunda tekrar 1'e ataması yapılır

    if (a > 1000000)
        a = 1;
    if (b > 100000)
        b = 1;
    if (i > 1000000)
        i = 1;

    seed = (int)t + i; // 1 Ocak 1970'den beri geçen milisaniye ile i toplanarak seed'e atanır
    int sayi = (a * seed + b) % maxSayi; // Oluşan seed bir dizi işlem sonucunda maxSayi'ya göre modu alınarak bir sayı üretilir

    /*
        Rastgele sayı üretmedeki yaklaşımımız bilgisayardaki zamanı alarak, bunu her çağrıldığında
        değişen sayılarla(static a,b ve i sayıları) bir dizi işleme sokarak sözde rastgele sayı üretilmesi şeklindedir.
    */
    // a ve b sayılarının aralaında asal olarak artması üretilecek sayının tekrara binmiş bir görüntüde olmasının önüne geçiyor
    a += 19;
    b += 2;
    i += a + b;

    return (sayi < 0 ? (sayi * -1) : sayi);
}
void RastgeleYoket(Rastgele this)
{
    if (this == NULL)
        return;
    free(this); // this iade edilir
}