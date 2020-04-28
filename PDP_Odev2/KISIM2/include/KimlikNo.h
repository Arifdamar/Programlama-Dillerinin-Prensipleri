/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * KimlikNo başlık dosyası
 * </p>
 */
#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include "stdio.h"
#include "string.h"
#include "stdbool.h"

struct KIMLIKNO
{
    int *tcKimlikNo;
    char *tcKimlikNoString;

    int *(*getKimlikNo)(struct KIMLIKNO *);
    void (*tcKimlikOlustur)(struct KIMLIKNO *);
    char *(*getKimlikNoString)(struct KIMLIKNO *);
    void (*KimlikNoKontrol)(char *);
    void (*Yoket)(struct KIMLIKNO *);
};

typedef struct KIMLIKNO *KimlikNo;

KimlikNo KimlikNoConstructor();
int *_getKimlikNo(const KimlikNo);
void _tcKimlikOlustur(const KimlikNo);
char *_getKimlikNoString(const KimlikNo);
void _KimlikNoKontrol(char *);
void KimlikNoYoket(KimlikNo);

#endif // !KIMLIKNO_H