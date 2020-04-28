/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * IMEINo kaynak dosyası
 * </p>
 */
#include "IMEINo.h"
#include "Rastgele.h"

// Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
IMEINo IMEINoConstructor()
{
    IMEINo this; // Bir IMEINo referansı oluşturulur

    // Bellekte IMEINO boyutunda yer açılır ve IMEINO* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (IMEINo)malloc(sizeof(struct IMEINO));

    this->imeiNo = (int *)malloc(sizeof(int) * 15);         // heap'te olusturuldu, yoket metodunda temizlendi'
    this->imeiNoString = (char *)malloc(sizeof(char) * 15); // heap'te olusturuldu, yoket metodunda temizlendi'

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->getImeiNo = &_getImeiNo;
    this->getImeiNoString = &_getImeiNoString;
    this->imeiNoOlustur = &_imeiNoOlustur;
    this->imeiNoKontrol = &_imeiKontrol;
    this->Yoket = &_imeiNoYoket;

    // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
    return this;
}
int *_getImeiNo(const IMEINo this)
{
    return this->imeiNo;
}
char *_getImeiNoString(const IMEINo this)
{
    return this->imeiNoString;
}

// IMEI'nin hesaplanmasında kullanılacak yardımcı metodlar tanımlanır
// IMEI'nin çift basamaklarındaki toplama işlemini yapıp geri döndüren yardımcı metod
int ciftToplamBul(int *dizi)
{
    int ciftToplam = 0;
    for (int i = 0; i < 15 - 1; i++)
    {
        if (i % 2 == 1)
        {
            if ((dizi[i] * 2) >= 10)
            {
                ciftToplam += 1;
                ciftToplam += (dizi[i] * 2) % 10;
            }
            else
            {
                ciftToplam += dizi[i] * 2;
            }
        }
    }
    return ciftToplam;
}

// IMEI'nin tek basamaklarındaki toplama işlemini yapıp geri döndüren yardımcı metod
int tekToplamBul(int *dizi)
{
    int tekToplam = 0;
    for (int i = 0; i < 15 - 1; i++)
    {
        if (i % 2 == 0)
        {
            tekToplam += dizi[i];
        }
    }
    return tekToplam;
}

// Çift ve tek toplamlara göre genel toplamı hesaplayıp geri döndüren yardımcı metod
int genelToplamBul(int ciftToplam, int tekToplam)
{
    return ciftToplam + tekToplam;
}

// Genel toplama göre son hanenin bulunması işlemlerini yapıp geri döndüren yardımcı metod
int sonHaneBul(int genelToplam)
{
    int sonHane;
    sonHane = (10 - (genelToplam % 10)) == 10 ? 0 : (10 - (genelToplam % 10));
    return sonHane;
}

void _imeiNoOlustur(const IMEINo this)
{
    Rastgele rastgele = RastgeleConstructor(); // Rastgele sayı üretebilmek için Rastgele nesnesi oluşturulur

    while (1)
    {
        // Imei'nin ilk iki hanesi https://www.wikiwand.com/en/Reporting_Body_Identifier kaynağındaki listeye göre oluşturulur
        this->imeiNo[0] = rastgele->sayiOlustur(10);
        this->imeiNoString[0] = this->imeiNo[0] + '0';
        if (this->imeiNo[0] == 0)
        {
            this->imeiNo[1] = 1;
            this->imeiNoString[1] = '1';
            break;
        }
        else if (this->imeiNo[0] == 1)
        {
            this->imeiNo[1] = 0;
            this->imeiNoString[1] = '0';
            break;
        }
        else if (this->imeiNo[0] == 3)
        {
            while (!(this->imeiNo[1] == 0 || this->imeiNo[1] == 3 || this->imeiNo[1] == 5))
            {
                this->imeiNo[1] = rastgele->sayiOlustur(10);
            }
            this->imeiNoString[1] = this->imeiNo[1] + '0';
            break;
        }
        else if (this->imeiNo[0] == 4)
        {
            while (!(this->imeiNo[1] == 4 || this->imeiNo[1] == 5 || this->imeiNo[1] == 9))
            {
                this->imeiNo[1] = rastgele->sayiOlustur(10);
            }
            this->imeiNoString[1] = this->imeiNo[1] + '0';
            break;
        }
        else if (this->imeiNo[0] == 5)
        {
            while (!(this->imeiNo[1] == 0 || this->imeiNo[1] == 1 || this->imeiNo[1] == 2 || this->imeiNo[1] == 3 || this->imeiNo[1] == 4))
            {
                this->imeiNo[1] = rastgele->sayiOlustur(10);
            }
            this->imeiNoString[1] = this->imeiNo[1] + '0';
            break;
        }
        else if (this->imeiNo[0] == 8)
        {
            this->imeiNo[1] = 6;
            this->imeiNoString[1] = '6';
            break;
        }
        else if (this->imeiNo[0] == 9)
        {
            while (!(this->imeiNo[1] == 1 || this->imeiNo[1] == 8 || this->imeiNo[1] == 9))
            {
                this->imeiNo[1] = rastgele->sayiOlustur(10);
            }
            this->imeiNoString[1] = this->imeiNo[1] + '0';
            break;
        }
    }

    // IMEI'nin diğer basamakları rastgele şekilde oluşturulur
    for (int i = 2; i < 14; i++)
    {
        this->imeiNo[i] = rastgele->sayiOlustur(10);
        this->imeiNoString[i] = this->imeiNo[i] + '0';
    }
    
    // IMEI kuralına göre son hane hesaplamaları yapılır
    int tekToplam = tekToplamBul(this->imeiNo);
    int ciftToplam = ciftToplamBul(this->imeiNo);
    int genelToplam = genelToplamBul(tekToplam, ciftToplam);
    int sonHane = sonHaneBul(genelToplam);
    this->imeiNo[14] = sonHane; // Hesaplanan sonHane imeiNo'nun son indisine atanır
    this->imeiNoString[14] = this->imeiNo[14] + '0';
}

void _imeiKontrol(char *imeiler, int satirSayisi)
{
    int gecersizImei = 0;
    int gecerliImei = 0;
    int i = 0;

    int *imeiUzunluklar = (int *)malloc(sizeof(int) * satirSayisi);
    int imeiUzunluk = 0;
    int j = 0;

    while (true) // Gelen imeiler içerisinde imei uzunluklarını hesaplamak için dönülür
    {
        if (imeiler[i] == '\0') // While döngüsü imeilerin sonuna gelinene kadar döner
        {
            break;
        }
        if (imeiler[i] != '\n') // '\n' karakteri gelmediği sürece imei'nin uzunluğu arttırılır
        {
            imeiUzunluk++;
        }
        else // '\n' geldiğinde uzunluklar dizisine elde edilen uzunluk değeri atanır ve yeni satır için 0'a eşitlenir
        {
            imeiUzunluklar[j] = imeiUzunluk;
            imeiUzunluk = 0;
            j++;
        }
        i++; // bir sonraki karaktere geçilir
    }

    i = 0;
    int k = 0;
    while (true) // Gelen imeiler içerisinde imei kontrolü için dönülür
    {
        if (imeiler[i] == '\0') // While döngüsü imeilerin sonuna gelinene kadar döner
        {
            break;
        }
        if (imeiler[i] != '\n') // '\n' karakteri gelmediği sürece tek bir imei üzerinde olduğumuz anlamına gelir ve o imei'nin kontrol işlemleri yapılır
        {
            bool gecersizMi = false;
            int j;
            int *imeiInt = (int *)malloc(sizeof(int) * imeiUzunluklar[k]); // bellekte (imei uzunluğu * int) boyutunda bir yer açılır ve imeiInt'in burayı göstermesi sağlanır
            for (j = 0; j < imeiUzunluklar[k]; j++)
            {
                // IMEI'nin her bir basamağı, int şeklinde işlem yapılabilmesi için bir int dizisine aktarılır
                if (imeiler[i] == '0')
                    imeiInt[j] = 0;
                else if (imeiler[i] == '1')
                    imeiInt[j] = 1;
                else if (imeiler[i] == '2')
                    imeiInt[j] = 2;
                else if (imeiler[i] == '3')
                    imeiInt[j] = 3;
                else if (imeiler[i] == '4')
                    imeiInt[j] = 4;
                else if (imeiler[i] == '5')
                    imeiInt[j] = 5;
                else if (imeiler[i] == '6')
                    imeiInt[j] = 6;
                else if (imeiler[i] == '7')
                    imeiInt[j] = 7;
                else if (imeiler[i] == '8')
                    imeiInt[j] = 8;
                else if (imeiler[i] == '9')
                    imeiInt[j] = 9;
                else
                {
                    // imei içerisinde sayısal olmayan bir ifade varsa gecersiz imei olarak sayılır
                    gecersizImei++;
                    gecersizMi = true;
                }
                i++;
            }
            k++;
            if (!gecersizMi) // Formata uymayan IMEI'ler asagidaki islemlere tabi tutulmaz
            {
                // Imei'nin ilk iki hanesi https://www.wikiwand.com/en/Reporting_Body_Identifier kaynağındaki listeye göre kontrol edilir
                if (imeiInt[0] == 0)
                {
                    if (!(imeiInt[1] == 1))
                    {
                        gecersizImei++;
                        continue;
                    }
                }
                else if (imeiInt[0] == 1)
                {
                    if (!(imeiInt[1] == 0))
                    {
                        gecersizImei++;
                        continue;
                    }
                }
                else if (imeiInt[0] == 3)
                {
                    if (!(imeiInt[1] == 0 || imeiInt[1] == 3 || imeiInt[1] == 5))
                    {
                        gecersizImei++;
                        continue;
                    }
                }
                else if (imeiInt[0] == 4)
                {
                    if (!(imeiInt[1] == 4 || imeiInt[1] == 5 || imeiInt[1] == 9))
                    {
                        gecersizImei++;
                        continue;
                    }
                }
                else if (imeiInt[0] == 5)
                {
                    if (!(imeiInt[1] == 0 || imeiInt[1] == 1 || imeiInt[1] == 2 || imeiInt[1] == 3 || imeiInt[1] == 4))
                    {
                        gecersizImei++;
                        continue;
                    }
                }
                else if (imeiInt[0] == 8)
                {
                    if (!(imeiInt[1] == 6))
                    {
                        gecersizImei++;
                        continue;
                    }
                }
                else if (imeiInt[0] == 9)
                {
                    if (!(imeiInt[1] == 1 || imeiInt[1] == 8 || imeiInt[1] == 9))
                    {
                        gecersizImei++;
                        continue;
                    }
                }

                // Imei numarasının kuralına göre onay işlemleri yapılır
                int tekToplam = tekToplamBul(imeiInt);
                int ciftToplam = ciftToplamBul(imeiInt);
                int genelToplam = genelToplamBul(tekToplam, ciftToplam);
                int sonHane = sonHaneBul(genelToplam);
                if (imeiInt[14] == sonHane)
                { // son basamağın imei kuralına uygun olup olmadığı kontrol edilir
                    gecerliImei++;
                }
                else
                {
                    gecersizImei++;
                }
            }
        }
        i++;
    }
    printf("IMEI Kontrol\n");
    printf("Gecerli IMEI: %d\n", gecerliImei);
    printf("Gecersiz IMEI: %d\n", gecersizImei);
}

void _imeiNoYoket(IMEINo this)
{
    if (this == NULL)
        return;
    free(this->imeiNo); // imeiNo iade edilir
    free(this->imeiNoString); // imeiNoString iade edilir
    free(this); // this iade edilir
}