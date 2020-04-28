/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * IMEINo başlık dosyası
 * </p>
 */
#ifndef IMEINO_H
#define IMEINO_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct IMEINO
{
    int *imeiNo;
    char *imeiNoString;

    int *(*getImeiNo)(struct IMEINO *);
    char *(*getImeiNoString)(struct IMEINO *);
    void (*imeiNoKontrol)(char *, int);
    void (*imeiNoOlustur)(struct IMEINO *);
    void (*Yoket)(struct IMEINO *);
};

typedef struct IMEINO *IMEINo;

IMEINo IMEINoConstructor();
int *_getImeiNo(const IMEINo);
char *_getImeiNoString(const IMEINo);
void _imeiKontrol(char *, int);
void _imeiNoOlustur(const IMEINo);
void _imeiNoYoket(IMEINo);

#endif // !IMEINO_H