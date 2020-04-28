/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Rastgele sınıfının dosyasıdır
 * </p>
 */
package Paket;

import java.util.Date;

public class Rastgele {

    private int seed;
    private static int a = 1;
    private static int b = 1;
    private static int i = 0;

    public int sayiOlustur(int maxSayi) {
        Date zmn = new Date(); // Bilgisayardaki o anki zaman tutan bir nesne oluşturulur

        // a, b ve i değerlerinin çok büyümesi durumunda tekrar 1'e ataması yapılır
        if (a > 100000) a = 1;
        if (b > 10000) b = 1;
        if (i > 100000) i = 1;

        this.seed = (int) zmn.getTime() + i; // 1 Ocak 1970'den beri geçen milisaniye ile i toplanarak seed'e atanır
        int sayi = (a * this.seed + b) % maxSayi; // Oluşan seed bir dizi işlem sonucunda maxSayi'ya göre modu alınarak bir sayı üretilir

        /*
            Rastgele sayı üretmedeki yaklaşımımız bilgisayardaki zamanı alarak, bunu her çağrıldığında
            değişen sayılarla(static a,b ve i sayıları) bir dizi işleme sokarak sözde rastgele sayı üretilmesi şeklindedir.
         */
        // a ve b sayılarının aralaında asal olarak artması üretilecek sayının tekrara binmiş bir görüntüde olmasının önüne geçiyor
        a += 11;
        b += 2;
        // i sayısını a ve b'nin toplamları şeklinde tanımlayarak üretilecek sayının karmaşıklığını ve rastgelelik kalitesi arttırmış oluyoruz
        i += a + b;
        return (sayi < 0 ? (sayi * -1) : sayi);
    }
}
