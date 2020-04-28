/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * IMEINo sınıfının dosyasıdır
 * </p>
 */
package Paket;

import java.util.List;

public class IMEINo {

    private int[] imeiNo;

    public IMEINo() {
        this.imeiNo = new int[15]; // imeiNo için 15 boyutlu bir int dizisi oluşturulur
    }

    public int[] getImeiNo() {
        return this.imeiNo;
    }

    // IMEI'nin hesaplanmasında kullanılacak yardımcı metodlar tanımlanır
    // IMEI'nin çift basamaklarındaki toplama işlemini yapıp geri döndüren yardımcı metod
    private int ciftToplamBul(int[] dizi) {
        int ciftToplam = 0;
        for (int i = 0; i < dizi.length - 1; i++) {
            if (i % 2 == 1) {
                if ((dizi[i] * 2) >= 10) {
                    ciftToplam += 1;
                    ciftToplam += (dizi[i] * 2) % 10;
                } else {
                    ciftToplam += dizi[i] * 2;
                }
            }
        }
        return ciftToplam;
    }

    // IMEI'nin tek basamaklarındaki toplama işlemini yapıp geri döndüren yardımcı metod
    private int tekToplamBul(int[] dizi) {
        int tekToplam = 0;
        for (int i = 0; i < dizi.length - 1; i++) {
            if (i % 2 == 0) {  //tekler bunlar
                tekToplam += dizi[i];
            }
        }
        return tekToplam;
    }

    // Çift ve tek toplamlara göre genel toplamı hesaplayıp geri döndüren yardımcı metod
    private int genelToplamBul(int ciftToplam, int tekToplam) {
        return ciftToplam + tekToplam;
    }

    // Genel toplama göre son hanenin bulunması işlemlerini yapıp geri döndüren yardımcı metod
    private int sonHaneBul(int genelToplam) {
        int sonHane;
        sonHane = (10 - (genelToplam % 10)) == 10 ? 0 : (10 - (genelToplam % 10));
        return sonHane;
    }

    public void imeiNoKontrol(List<String> imei) {
        int gecersizImei = 0;
        int gecerliImei = 0;
        for (String imeiString : imei) { // Her bir IMEI tek tek döndürülür
            int[] imeiInt = new int[15]; // 15 boyutlu bir int dizisi oluşturulur

            // Imei stringi ile ilgili formatsal kontroller yapılır
            if ((!imeiString.equals("")) // boş imei stringleri geçersiz sayılır
                    && (!imeiString.equals(" ")) // boşluk karakterinden oluşan imei stringleri geçersiz sayılır
                    && ((imeiString.charAt(0) == '(') && (imeiString.charAt(imeiString.length() - 1) == ')')) // '(' ile başlamayıp ve ')' ile bitmeyen imeiler geçersiz sayılır 
                    && (imeiString.length() == 17)) { // imei(15) ve parantezlerle(2) birlikte 17 karakter olmayan imeiler geçersiz sayılır

                // IMEI'nin her bir basamağı, int şeklinde işlem yapılabilmesi için bir int dizisine aktarılır
                for (int j = 0; j < imeiString.length(); j++) {
                    if (j == 15) {
                        break;
                    }
                    imeiInt[j] = Character.getNumericValue(imeiString.charAt(j + 1));
                }
            } else {
                gecersizImei++;
                continue; // Düzgün formatta olmayan imei'leri aşağıdaki işlemlere sokmamak için döngü ilerletilir
            }

            // Imei'nin ilk iki hanesi https://www.wikiwand.com/en/Reporting_Body_Identifier kaynağındaki listeye göre kontrol edilir
            if (imeiInt[0] == 0) {
                if (!(imeiInt[1] == 1)) {
                    gecersizImei++;
                    continue;
                }
            } else if (imeiInt[0] == 1) {
                if (!(imeiInt[1] == 0)) {
                    gecersizImei++;
                    continue;
                }
            } else if (imeiInt[0] == 3) {
                if (!(imeiInt[1] == 0 || imeiInt[1] == 3 || imeiInt[1] == 5)) {
                    gecersizImei++;
                    continue;
                }
            } else if (imeiInt[0] == 4) {
                if (!(imeiInt[1] == 4 || imeiInt[1] == 5 || imeiInt[1] == 9)) {
                    gecersizImei++;
                    continue;
                }
            } else if (imeiInt[0] == 5) {
                if (!(imeiInt[1] == 0 || imeiInt[1] == 1 || imeiInt[1] == 2 || imeiInt[1] == 3 || imeiInt[1] == 4)) {
                    gecersizImei++;
                    continue;
                }
            } else if (imeiInt[0] == 8) {
                if (!(imeiInt[1] == 6)) {
                    gecersizImei++;
                    continue;
                }
            } else if (imeiInt[0] == 9) {
                if (!(imeiInt[1] == 1 || imeiInt[1] == 8 || imeiInt[1] == 9)) {
                    gecersizImei++;
                    continue;
                }
            }

            // Imei numarasının kuralına göre onay işlemleri yapılır
            int tekToplam = tekToplamBul(imeiInt);
            int ciftToplam = ciftToplamBul(imeiInt);
            int genelToplam = genelToplamBul(tekToplam, ciftToplam);
            int sonHane = sonHaneBul(genelToplam);
            if (imeiInt[14] == sonHane) { // son basamağın imei kuralına uygun olup olmadığı kontrol edilir
                gecerliImei++;
            } else {
                gecersizImei++;
            }
        }
        System.out.println("IMEI Kontrol");
        System.out.println(gecerliImei + "   Gecerli Imei");
        System.out.println(gecersizImei + "  Gecersiz Imei");
    }

    public void imeiNoOlustur() {
        Rastgele rastgele = new Rastgele(); // Rastgele sayı üretmek için bir Rastgele nesnesi oluşturulur

        while (true) {
            // Imei'nin ilk iki hanesi https://www.wikiwand.com/en/Reporting_Body_Identifier kaynağındaki listeye göre oluşturulur
            this.imeiNo[0] = rastgele.sayiOlustur(10);
            if (this.imeiNo[0] == 0) {
                this.imeiNo[1] = 1;
                break;
            } else if (this.imeiNo[0] == 1) {
                this.imeiNo[1] = 0;
                break;
            } else if (this.imeiNo[0] == 3) {
                while (!(this.imeiNo[1] == 0 || this.imeiNo[1] == 3 || this.imeiNo[1] == 5)) {
                    this.imeiNo[1] = rastgele.sayiOlustur(10);
                }
                break;
            } else if (this.imeiNo[0] == 4) {
                while (!(this.imeiNo[1] == 4 || this.imeiNo[1] == 5 || this.imeiNo[1] == 9)) {
                    this.imeiNo[1] = rastgele.sayiOlustur(10);
                }
                break;
            } else if (this.imeiNo[0] == 5) {
                while (!(this.imeiNo[1] == 0 || this.imeiNo[1] == 1 || this.imeiNo[1] == 2 || this.imeiNo[1] == 3 || this.imeiNo[1] == 4)) {
                    this.imeiNo[1] = rastgele.sayiOlustur(10);
                }
                break;
            } else if (this.imeiNo[0] == 8) {
                this.imeiNo[1] = 6;
                break;
            } else if (this.imeiNo[0] == 9) {
                while (!(this.imeiNo[1] == 1 || this.imeiNo[1] == 8 || this.imeiNo[1] == 9)) {
                    this.imeiNo[1] = rastgele.sayiOlustur(10);
                }
                break;
            }
        }

        // IMEI'nin diğer basamakları rastgele şekilde oluşturulur
        for (int i = 2; i < this.imeiNo.length - 1; i++) {
            this.imeiNo[i] = rastgele.sayiOlustur(10);
        }
        // IMEI kuralına göre son hane hesaplamaları yapılır
        int tekToplam = tekToplamBul(this.imeiNo);
        int ciftToplam = ciftToplamBul(this.imeiNo);
        int genelToplam = genelToplamBul(tekToplam, ciftToplam);
        int sonHane = sonHaneBul(genelToplam);
        this.imeiNo[14] = sonHane; // Hesaplanan sonHane imeiNo'nun son indisine atanır
    }

}
