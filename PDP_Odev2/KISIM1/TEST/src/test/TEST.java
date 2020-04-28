/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Projenin test dosyasıdır.
 * </p>
 */
package test;

import Paket.DosyaIslem;
import Paket.RastgeleKisi;
import java.util.Scanner;

public class TEST {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        DosyaIslem dosya = new DosyaIslem(); // Dosya işlemlerinin yapılması için bir dosya nesnesi üretilir
        int secim;

        do {
            Scanner giris = new Scanner(System.in);
            System.out.print("1- Rastgele Kişi Üret\n");
            System.out.print("2- Üretilmiş Dosya Kontrol Et\n");
            System.out.print("3- Çıkış\n");
            secim = giris.nextInt();
            switch (secim) {
                case 1:
                    KisiUret(dosya); // Rastgele kişi üretmek için metod çağrılır
                    break;
                case 2:
                    UretilmisDosyaKontrolEt(dosya); // Üretilmiş dosyayı kontrol etmek için metod çağrılır
                    break;

                default:
                    break;
            }
        } while (secim != 3);

    }

    static void KisiUret(DosyaIslem dosya) {

        Scanner kisiAdet = new Scanner(System.in);
        int adet = kisiAdet.nextInt(); // Kullanıcıdan kişi adeti alınır

        dosya.dosyaTemizle("Kisiler.txt"); // Yeni kişiler yazılmadan önce dosya temizlenir
        RastgeleKisi[] kisiler = new RastgeleKisi[adet]; // Kullanıcının girdiği sayıda RastgeleKisi referansı oluşur

        for (int i = 0; i < adet; i++) {
            kisiler[i] = new RastgeleKisi(); // Oluşan referanslara RastgeleKisi nesnesi atanır
        }

        for (int i = 0; i < adet; i++) {
            kisiler[i].kisiÖzellikAta(); // Kişilerin rastgele özellikleri ataması yapılır
            kisiler[i].kisileriDosyayaYazdir("Kisiler.txt"); // Rastgele özellikleri atanan kişiler "Kisiler.txt" dosyasına yazdırılır
        }
    }

    static void UretilmisDosyaKontrolEt(DosyaIslem dosya) {
        dosya.uretilmisDosyaOku(); // Üretilmiş dosya okunur
        dosya.Kontrol(); // Okunan dosya kontrol edilir
    }
}
