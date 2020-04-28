/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Kisi başlık dosyası
 * </p>
 */
#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "KimlikNo.h"
#include "Telefon.h"

struct KISI{
    char *isim;
    char *soyIsim;
    int yas;
    KimlikNo tcNo;
    Telefon telefon;

    char* (*getIsim)(struct KISI*);
    void (*setIsim)(struct KISI*, char*);
    char* (*getSoyIsim)(struct KISI*);
    void (*setSoyIsim)(struct KISI*, char*);
    int (*getYas)(struct KISI*);
    void (*setYas)(struct KISI*, int);
    KimlikNo (*getTc)(struct KISI*);
    Telefon (*getTelefon)(struct KISI*);
    void (*Yoket)(struct KISI*);
};

typedef struct KISI* Kisi;

Kisi KisiConstructor();
char* _getIsim(const Kisi);
void _setIsim(const Kisi, char*);
char* _getSoyIsim(const Kisi);
void _setSoyIsim(const Kisi, char*);
int _getYas(const Kisi);
void _setYas(const Kisi, int);
KimlikNo _getTc(const Kisi);
Telefon _getTelefon(const Kisi);
void KisiYoket(Kisi);

#endif