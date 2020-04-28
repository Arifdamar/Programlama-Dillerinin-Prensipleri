/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * KimlikNo sınıfının dosyasıdır
 * </p>
 */
package Paket;

import java.util.List;

public class KimlikNo {

    private int[] tckimlikNo;

    public KimlikNo() {
        tckimlikNo = new int[11];
    }

    public int[] getKimlikNo() {
        return this.tckimlikNo;
    }

    // T.C. kimlik numarasının hesaplanmasında kullanılacak yardımcı metodlar tanımlanır
    // Tek ve çift indis toplamlarına göre 9. indisi hesaplayıp geri döndüren yardımcı metod
    private int dokuzuncuIndisBul(int tekIndisToplami, int ciftIndisToplami) {
        return ((7 * ciftIndisToplami) - tekIndisToplami) % 10;
    }

    // Tüm indislerin toplamına göre 10. indisi hesaplayıp geri döndüren yardımcı metod
    private int onuncuIndisBul(int tumIndislerinToplami) {
        return tumIndislerinToplami % 10;
    }

    // Kimlik numarasının tüm indislerinin toplamını bulup geri döndüren yardımcı metod
    private int tümIndislerinToplaminiBul(int[] tckimlikNo) {
        int tümIndislerinToplami = 0;
        for (int i = 0; i < tckimlikNo.length - 1; i++) {
            tümIndislerinToplami += tckimlikNo[i];
        }
        return tümIndislerinToplami;
    }

    // Kimlik numarasının çift indislerinin toplamını bulup geri döndüren yardımcı metod
    private int ciftIndisToplamiBul(int[] tckimlikNo) {
        int ciftIndisToplami = 0;
        for (int i = 0; i < tckimlikNo.length - 2; i++) {
            if (i % 2 == 0) {
                ciftIndisToplami += tckimlikNo[i];
            }
        }
        return ciftIndisToplami;
    }

    // Kimlik numarasının tek indislerinin toplamını bulup geri döndüren yardımcı metod
    private int tekIndisToplamiBul(int[] tckimlikNo) {
        int tekIndisToplami = 0;
        for (int i = 0; i < tckimlikNo.length - 2; i++) {
            if (i % 2 != 0) {
                tekIndisToplami += tckimlikNo[i];
            }
        }
        return tekIndisToplami;
    }

    public void tcKimlikOlustur() {
        Rastgele rastgele = new Rastgele(); // Rastgele sayılar üretmek için bir Rastgele nesnesi oluşturulur
        for (int i = 0; i < tckimlikNo.length - 2; i++) { // Kimlik numarasının ilk 9 basamağı rastgele biçimde oluşturulur
            tckimlikNo[i] = rastgele.sayiOlustur(10); // 0-10 aralığında rastgele sayılar üretilir
            if (tckimlikNo[0] == 0) { // İlk basamak 0 olarak atanırsa tekrarlanması için i 1 azaltılır
                i--;
            }
        }

        // Kimlik numarasının 10. basamağının(9. indis) hesaplama işlemleri yapılır
        tckimlikNo[9] = dokuzuncuIndisBul(tekIndisToplamiBul(tckimlikNo), ciftIndisToplamiBul(tckimlikNo));

        // Kimlik numarasının 11. basamağının(10. indis) hesaplama işlemleri yapılır
        tckimlikNo[10] = onuncuIndisBul(tümIndislerinToplaminiBul(tckimlikNo));
    }

    public void tcKimlikKontrol(List<String> gelenTc) {
        int gecersizTc = 0;
        int gecerliTc = 0;
        for (String tcString : gelenTc) {
            int[] tcInt = new int[11];

            // TC stringi ile ilgili formatsal kontroller yapılır
            if ((!tcString.equals("")) // boş TC stringleri geçersiz sayılır
                    && (!tcString.equals(" ")) // boşluk karakterinden oluşan TC stringleri geçersiz sayılır
                    && (tcString.length() == 11)) { // TC stringinin uzunluğu 11 olmalıdır

                // Kimlik numarasının her bir basamağı, int şeklinde işlem yapılabilmesi için bir int dizisine aktarılır
                for (int i = 0; i < tcString.length(); i++) {
                    tcInt[i] = Character.getNumericValue(tcString.charAt(i));
                }
            } else {
                gecersizTc++;
                continue; // Düzgün formatta olmayan TC'leri aşağıdaki işlemlere sokmamak için döngü ilerletilir
            }

            // TC numarasının kuralına göre onay işlemleri yapılır
            int dokuzuncuIndis = dokuzuncuIndisBul(tekIndisToplamiBul(tcInt), ciftIndisToplamiBul(tcInt));
            int indisToplam = tümIndislerinToplaminiBul(tcInt);
            int onuncuIndis = onuncuIndisBul(indisToplam);
            if (tcInt[0] == 0) {
                gecersizTc++;
            } else if (tcInt[9] != dokuzuncuIndis) {
                gecersizTc++;
            } else if (tcInt[10] != onuncuIndis) {
                gecersizTc++;
            } else {
                gecerliTc++;
            }
        }
        System.out.println("T.C. Kimlik Kontrol");
        System.out.println(gecerliTc + "    Gecerli  Tc ");
        System.out.println(gecersizTc + "    Gecersiz Tc ");
    }
}
