/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * KimlikNo kaynak dosyası
 * </p>
 */
#include "KimlikNo.h"
#include "Rastgele.h"

// Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
KimlikNo KimlikNoConstructor()
{
    KimlikNo this; // Bir KimlikNo referansı oluşturulur

    // Bellekte KIMLIKNO boyutunda yer açılır ve KIMLIKNO* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));

    this->tcKimlikNoString = malloc(sizeof(char) * 12); // heap'te olusturuldu, yoket metodunda temizlendi
    this->tcKimlikNo = (int *)malloc(sizeof(int) * 12); // heap'te olusturuldu, yoket metodunda temizlendi

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->getKimlikNo = &_getKimlikNo;
    this->getKimlikNoString = &_getKimlikNoString;
    this->tcKimlikOlustur = &_tcKimlikOlustur;
    this->KimlikNoKontrol = &_KimlikNoKontrol;
    this->Yoket = &KimlikNoYoket;

    // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
    return this;
}

// T.C. kimlik numarasının hesaplanmasında kullanılacak yardımcı metodlar tanımlanır
// Tek ve çift indis toplamlarına göre 9. indisi hesaplayıp geri döndüren yardımcı metod
int dokuzuncuIndisBul(int tekIndisToplami, int ciftIndisToplami)
{
    return ((7 * ciftIndisToplami) - tekIndisToplami) % 10;
}

// Tüm indislerin toplamına göre 10. indisi hesaplayıp geri döndüren yardımcı metod
int onuncuIndisBul(int tumIndislerinToplami)
{
    return tumIndislerinToplami % 10;
}

// Kimlik numarasının tüm indislerinin toplamını bulup geri döndüren yardımcı metod
int tumIndislerinToplaminiBul(int *tckimlikNo)
{
    int tumIndislerinToplami = 0;
    for (int i = 0; i < 10; i++)
    {
        tumIndislerinToplami += tckimlikNo[i];
    }
    return tumIndislerinToplami;
}

// Kimlik numarasının çift indislerinin toplamını bulup geri döndüren yardımcı metod
int ciftIndisToplamiBul(int *tckimlikNo)
{
    int ciftIndisToplami = 0;
    for (int i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            ciftIndisToplami += tckimlikNo[i];
        }
    }
    return ciftIndisToplami;
}

// Kimlik numarasının tek indislerinin toplamını bulup geri döndüren yardımcı metod
int tekIndisToplamiBul(int *tckimlikNo)
{
    int tekIndisToplami = 0;
    for (int i = 0; i < 9; i++)
    {
        if (i % 2 != 0)
        {
            tekIndisToplami += tckimlikNo[i];
        }
    }
    return tekIndisToplami;
}
void _KimlikNoKontrol(char *kimlikler)
{
    int gecersizTc = 0;
    int gecerliTc = 0;

    int i = 0;
    while (1)
    {
        if (kimlikler[i] == '\0')
        {
            break;
        }
        if (kimlikler[i] != '\n')
        {
            bool gecersizMi = false;
            int j;
            int *tcInt = (int *)malloc(sizeof(int) * 11);
            for (j = 0; j < 11 && !gecersizMi; j++)
            {
                if (kimlikler[i] == '0')
                    tcInt[j] = 0;
                else if (kimlikler[i] == '1')
                    tcInt[j] = 1;
                else if (kimlikler[i] == '2')
                    tcInt[j] = 2;
                else if (kimlikler[i] == '3')
                    tcInt[j] = 3;
                else if (kimlikler[i] == '4')
                    tcInt[j] = 4;
                else if (kimlikler[i] == '5')
                    tcInt[j] = 5;
                else if (kimlikler[i] == '6')
                    tcInt[j] = 6;
                else if (kimlikler[i] == '7')
                    tcInt[j] = 7;
                else if (kimlikler[i] == '8')
                    tcInt[j] = 8;
                else if (kimlikler[i] == '9')
                    tcInt[j] = 9;
                else
                {
                    gecersizTc++;
                    gecersizMi = true;
                }
                i++;
            }
            if (!gecersizMi) // Formata uymayan kimlik numaralari hesaplama islemlerine tabi tutulmaz
            {
                // TC numarasının kuralına göre onay işlemleri yapılır
                int dokuzuncuIndis = dokuzuncuIndisBul(tekIndisToplamiBul(tcInt), ciftIndisToplamiBul(tcInt));
                int indisToplam = tumIndislerinToplaminiBul(tcInt);
                int onuncuIndis = onuncuIndisBul(indisToplam);
                if (tcInt[0] == 0)
                {
                    gecersizTc++;
                }
                else if (tcInt[9] != dokuzuncuIndis)
                {
                    gecersizTc++;
                }
                else if (tcInt[10] != onuncuIndis)
                {
                    gecersizTc++;
                }
                else
                {
                    gecerliTc++;
                }
            }
        }
        i++;
    }
    printf("T.C. Kimlik Kural Kontrol\n");
    printf("Gecerli T.C.: %d\n", gecerliTc);
    printf("Gecersiz T.C.: %d\n", gecersizTc);
}

int *_getKimlikNo(const KimlikNo this)
{
    return this->tcKimlikNo;
}
char *_getKimlikNoString(const KimlikNo this)
{
    return this->tcKimlikNoString;
}
void _tcKimlikOlustur(const KimlikNo this)
{
    Rastgele rastgele = RastgeleConstructor(); // Rastgele sayı üretebilmek için Rastgele nesnesi oluşturulur

    int i;
    for (i = 0; i < 9; i++) // Kimlik numarasının ilk 9 basamağı rastgele biçimde oluşturulur
    {
        this->tcKimlikNo[i] = rastgele->sayiOlustur(10); // 0-10 aralığında rastgele sayılar üretilir
        this->tcKimlikNoString[i] = this->tcKimlikNo[i] + '0';
        if (this->tcKimlikNo[0] == 0) // İlk basamak 0 olarak atanırsa tekrarlanması için i 1 azaltılır
        {
            i--;
        }
    }

    // Kimlik numarasının 10. basamağının(9. indis) hesaplama işlemleri yapılır
    this->tcKimlikNo[9] = dokuzuncuIndisBul(tekIndisToplamiBul(this->tcKimlikNo), ciftIndisToplamiBul(this->tcKimlikNo));
    this->tcKimlikNoString[9] = this->tcKimlikNo[9] + '0';

    // Kimlik numarasının 11. basamağının(10. indis) hesaplama işlemleri yapılır
    this->tcKimlikNo[10] = onuncuIndisBul(tumIndislerinToplaminiBul(this->tcKimlikNo));
    this->tcKimlikNoString[10] = this->tcKimlikNo[10] + '0';

    rastgele->Yoket(rastgele); // rastgele iade edilir
}

void KimlikNoYoket(KimlikNo this)
{
    if (this == NULL)
        return;
    free(this->tcKimlikNo); // tcKimlikNo iade edilir
    free(this->tcKimlikNoString); // tcKimlikNoString iade edilir
    free(this); // this iade edilir
}