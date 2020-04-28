/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Telefon başlık dosyası
 * </p>
 */
#ifndef TELEFON_H
#define TELEFON_H

#include "IMEINo.h"
#include "stdlib.h"

struct TELEFON{
    int *telefonNo;
    char *telefonNoString;
    IMEINo imeiNo;

    void (*telefonNoOlustur)(struct TELEFON*);
    int* (*getTelefonNo)(struct TELEFON*);
    char* (*getTelefonNoString)(struct TELEFON*);
    IMEINo (*getImei)(struct TELEFON*);
    void (*Yoket)(struct TELEFON*);
};

typedef struct TELEFON* Telefon;

Telefon TelefonConstructor();
void _telefonNoOlustur(const Telefon);
int* _getTelefonNo(const Telefon);
char* _getTelefonNoString(const Telefon);
IMEINo _getImei(const Telefon);
void TelefonYoket(Telefon);

#endif