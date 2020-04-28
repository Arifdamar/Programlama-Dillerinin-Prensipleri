/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * RastgeleKisi başlık dosyası
 * </p>
 */
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include "string.h"
#include "stdlib.h"
#include "Kisi.h"
#include "DosyaIslem.h"
#include "Rastgele.h"

struct RASTGELEKISI {
    Kisi kisi;
    DosyaIslem dosya;

    void (*kisiOzellikAta)(struct RASTGELEKISI*, struct DOSYAISLEM*);
    void (*kisileriDosyayaYazdir)(struct RASTGELEKISI*, char*);
    void (*Yoket)(struct RASTGELEKISI*);
};

typedef struct RASTGELEKISI* RastgeleKisi;

RastgeleKisi RastgeleKisiConstructor();
void _kisiOzellikAta(const RastgeleKisi, const DosyaIslem);
void _kisileriDosyayaYazdir(const RastgeleKisi, char*);
void RastgeleKisiYoket(RastgeleKisi);

#endif // !RASTGELEKISI_H