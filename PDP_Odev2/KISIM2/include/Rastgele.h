/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Rastgele başlık dosyası
 * </p>
 */
#ifndef RASTGELE_H
#define RASTGELE_H

#include "time.h"
#include "stdlib.h"
#include "stdio.h"

struct RASTGELE{
    int (*sayiOlustur)(int);
    void(*Yoket)(struct RASTGELE*);
};

typedef struct RASTGELE* Rastgele;

Rastgele RastgeleConstructor();
int _sayiOlustur(int);
void RastgeleYoket(Rastgele);

#endif 