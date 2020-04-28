/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * DosyaIslem kaynak dosyası
 * </p>
 */
#include "DosyaIslem.h"
#include "KimlikNo.h"
#include "ImeiNo.h"

 // Nesne yönelimli programlamaya benzetim yapmak için constructor metodu oluşturulur
DosyaIslem DosyaIslemConstructor()
{
    DosyaIslem this; // Bir DosyaIslem referansı oluşturulur

    // Bellekte DOSYAISLEM boyutunda yer açılır ve DOSYAISLEM* şekline çevrilip this tarafından gösterilmesi sağlanır
    this = (DosyaIslem)malloc(sizeof(struct DOSYAISLEM));

    // Fonksiyonlar nesne yönelimli programlamaya benzetim için fonksiyon göstericilerine atanır
    this->dosyaSatirSayisi = &_dosyaSatirSayisi;
    this->uretilmisDosyaOku = &_uretilmisDosyaOku;
    this->icerikDosyaOku = &_icerikDosyaOku;
    this->dosyaTemizle = &_dosyaTemizle;
    this->dosyaYaz = &_dosyaYaz;
    this->kontrol = &_kontrol;
    this->Yoket = &DosyaIslemYoket;

    return this; // this'i geri döndürerek nesne yönelimli programlamada bir constructorun yaptığı görev yapılır
}

int _dosyaSatirSayisi(char *dosyaIsmi)
{
    FILE *fileptr;
    int count_lines = 1;
    char chr;

    fileptr = fopen(dosyaIsmi, "r"); // Dosya okuma için açılır

    chr = getc(fileptr); // bir karakter okunup chr'ye atılır
    while (chr != EOF) // Dosya sonuna gelene kadar okuma devam eder
    {
        if (chr == '\n') // '/n' karakterini gördüğünde satır sayısını 1 arttırır
        {
            count_lines = count_lines + 1;
        }
        
        chr = getc(fileptr); // Dosyadaki bir sonraki karakter okunur
    }
    fclose(fileptr); // Dosya kapatılır
    return count_lines; // Hesaplanan satır sayısı geri döndürülür
}

void _icerikDosyaOku(const DosyaIslem this)
{
    FILE *file;
    file = fopen("random_isimler.txt", "r"); // Dosya okuma için açılır

    if (file != NULL) // Dosya açıldıysa işlemler yapılır
    {
        int i = 0;
        while (!feof(file)) // Dosyanın sonuna gelene kadar devam eder
        {
            fscanf(file, "%s %s", this->isimler[i], this->soyIsimler[i]); // okunan isimler ve soyisimler teker teker isimler ve soyisimler dizilerine atanır
            i++;
        }
    }
    else
    {
        printf("Dosya Bulunamadi.");
    }

    fclose(file); // Dosya kapatılır
}

void _dosyaTemizle(char *dosyaIsmi)
{
    FILE *file;
    file = fopen(dosyaIsmi, "w"); // Dosya yazma modunda açılır
    fclose(file);
}

void _dosyaYaz(char *dosyaIsmi, char *yazilacak)
{
    FILE *file;
    file = fopen(dosyaIsmi, "a"); // Dosya ekleme modunda açılır

    if (file != NULL) 
    {
        fprintf(file, yazilacak); // Dosya açıldıysa parametre olarak gelen yazilacak dosyaya yazılır
    }

    fclose(file);
}

void _uretilmisDosyaOku(const DosyaIslem this)
{
    int satirSayisi = this->dosyaSatirSayisi("Kisiler.txt"); // "Kisiler.txt" dsoyasının satır sayısı alınır

    char *kimlik = (char *)malloc(11); // heap'te olusturuldu, yoket metodunda temizlendi
    strcpy(kimlik, "");
    // kimlikler için satır sayısına oranla bellekte yer açılır
    this->kimlikler = (char *)malloc((satirSayisi * 11) + satirSayisi * 2); // heap'te olusturuldu, yoket metodunda temizlendi
    strcpy(this->kimlikler, "");

    char *imei = (char *)malloc(20); // heap'te olusturuldu, yoket metodunda temizlendi
    strcpy(imei, "");
    
    // imeiler için satır sayısına oranla bellekte yer açılır
    this->imeiler = (char *)malloc((satirSayisi * 16) + satirSayisi * 2); // heap'te olusturuldu, yoket metodunda temizlendi
    strcpy(this->imeiler, "");

    char ch;

    FILE *file;
    file = fopen("Kisiler.txt", "r"); // Dosya okuma için açılır

    int bozukTcSayisi = 0;
    bool bozukTcMi = false;
    int tcIndex = 0;

    int bozukImeiSayisi = 0;
    bool bozukImeiMi = false;
    int imeiIndex = 0;
    bool imeiOkunuyor = 0;
    if (file != NULL)
    {
        while ((ch = fgetc(file)) != EOF)
        {
             // her satırın ilk 11 satırı tc olması gerektiği için ilk 11 karakter tc olarak atanır
            if (tcIndex < 11)
            {
                kimlik[tcIndex] = ch;
                tcIndex++;
            }

            if (imeiOkunuyor) // imei okunduğu sürece gelen karakterleri imei içine atar
            {
                if (ch == ')') // ')' karakterini gördüğünde imeiOkunuyor false yapılır
                {
                    imeiOkunuyor = false;
                    continue;
                }

                imei[imeiIndex] = ch;
                imeiIndex++;
            }

            if (ch == '(') // '(' karakterini gördüğünde imeiOkunuyor true yapılır
            {
                imeiOkunuyor = true;
            }

            if (ch == '\n') // '\n' gördüğünde yeni satıra geçilir ve indeksler sıfırlanır
            {
                strcat(this->kimlikler, kimlik); // her satırdaki kimlik, kimlikler'e atanır
                strcat(this->kimlikler, "\n"); // kimlikler arasına '\n' atanır

                strcat(this->imeiler, imei); // her satırdaki imei, imeiler'e atanır
                strcat(this->imeiler, "\n"); // imeiler arasına '\n' atanır

                tcIndex = 0;
                imeiIndex = 0;
            }
        }
    }
    else
    {
        printf("Dosya Bulunamadi.\n");
    }
    fclose(file); // Dosya kapatılır
    free(kimlik); // kimlik iade edilir
    free(imei); // imei iade edilir
}
void _kontrol(const DosyaIslem this)
{
    KimlikNo kimlik = KimlikNoConstructor(); // heap'te olusturuldu, metodun sonunda temizlendi
    IMEINo imei = IMEINoConstructor(); // heap'te olusturuldu, metodun sonunda temizlendi

    kimlik->KimlikNoKontrol(this->kimlikler); // kimlikler, KimlikNo yapısının KimlikNoKontrol metoduna gönderilir
    imei->imeiNoKontrol(this->imeiler, this->dosyaSatirSayisi("Kisiler.txt")); // imeiler, IMEINo yapısının imeiNoKontrol metoduna gönderilir

    kimlik->Yoket(kimlik); // kimlik iade edilir
    imei->Yoket(imei); // imei iade edilir
}
void DosyaIslemYoket(DosyaIslem this)
{
    if (this == NULL)
        return;
    free(this->kimlikler); // kimlikler iade edilir
    free(this->imeiler); // imeiler iade edilir
    free(this); // this iade edilir
}