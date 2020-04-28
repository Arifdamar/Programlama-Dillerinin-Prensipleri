/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * DosyaIslem başlık dosyası
 * </p>
 */
#ifndef DOSYAISLEM_H
#define DOSYAISLEM_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

struct DOSYAISLEM{
    char isimler[3000][30];
    char soyIsimler[3000][30];
    char *kimlikler;
    char *imeiler;

    int (*dosyaSatirSayisi)(char*);
    void (*icerikDosyaOku)(struct DOSYAISLEM*);
    void (*dosyaYaz)(char*, char*);
    void (*dosyaTemizle)(char *);
    void (*uretilmisDosyaOku)(struct DOSYAISLEM*);
    void (*kontrol)(struct DOSYAISLEM*);
    void (*Yoket)(struct DOSYAISLEM*);
};
typedef struct DOSYAISLEM* DosyaIslem;

DosyaIslem DosyaIslemConstructor();
int _dosyaSatirSayisi(char*);
void _icerikDosyaOku(const DosyaIslem);
void _dosyaYaz(char*, char*);
void _dosyaTemizle(char*);
void _uretilmisDosyaOku(const DosyaIslem);
void _kontrol(const DosyaIslem);
void DosyaIslemYoket(DosyaIslem);

#endif // !DOSYAISLEM_H