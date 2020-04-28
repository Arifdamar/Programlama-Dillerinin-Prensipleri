/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * RastgeleKisi sınıfının dosyasıdır
 * </p>
 */
package Paket;

import java.util.ArrayList;
import java.util.List;

public class RastgeleKisi {

    private Kisi kisi; // Kisi referansı oluşturulur
    private DosyaIslem dosya; // DosyaIslem referansı oluşturulur

    public RastgeleKisi() {
        kisi = new Kisi(); // Oluşturulan referansa Kisi nesnesi atanır
        dosya = new DosyaIslem(); // Oluşturulan referansa DosyaIslem nesnesi atanır
    }

    public void kisiÖzellikAta() {
        Rastgele rastgele = new Rastgele(); // Rastgele sayı üretebilmek için Rastgele nesnesi oluşturulur
        int rastgeleIndex = rastgele.sayiOlustur(3000); // Rastgele isim ve soyisim için 0-3000 aralığında rastgele bir sayı üretilir

        this.dosya.icerikDosyaOku(); // random_isimler.txt dosyası okunur

        // Dosya üzerinden alınan isim ve soyisimler kisi'ye atanır
        this.kisi.setIsim(this.dosya.isimler[rastgeleIndex]);
        this.kisi.setSoyIsim(this.dosya.soyIsimler[rastgeleIndex]);

        // 0-101 aralığında rastgele bir sayı oluşturulup yaş olarak atanır
        this.kisi.setYas(rastgele.sayiOlustur(101));

        // TC, Telefon ve IMEI sınıflarının rastgele TC, Telefon ve IMEI oluşturma metodları çağrılır
        this.kisi.getTc().tcKimlikOlustur();
        this.kisi.getTelefon().telefonOlustur();
        this.kisi.getTelefon().getImei().imeiNoOlustur();
    }

    public void kisileriDosyayaYazdir(String dosyaIsmi) {
        String yazilacak;

        // Kişi'nin yazılacak olan bilgileri ilgili stringe düzgün formatta atanır
        String yazilacakTc = listeYap(this.kisi.getTc().getKimlikNo());
        String yazilacakTel = listeYap(this.kisi.getTelefon().getTelefonNo());
        String yazilacakImei = listeYap(this.kisi.getTelefon().getImei().getImeiNo());
        String yazilacakIsim = this.kisi.getIsim();
        String yazilacakSoyisim = this.kisi.getSoyIsim();
        String yazilacakYas = Integer.toString(this.kisi.getYas());

        // Yukarıda oluşan stringler "yazilacak" stringine uygun biçimde atanır
        yazilacak = (yazilacakTc + " " + yazilacakIsim + " " + yazilacakSoyisim + " " + yazilacakYas + " " + yazilacakTel + " (" + yazilacakImei + ")");
        this.dosya.dosyaYaz(dosyaIsmi, yazilacak); // Oluşturulan "yazilacak" stringi dosyaya yazılır
    }

    private String listeYap(int[] dizi) { // Gelen integer dizileri string formata dönüştürülüp geri döndürülür
        String dizilim = "";
        List<String> liste = new ArrayList();
        for (int i = 0; i < dizi.length; i++) {
            liste.add(Integer.toString(dizi[i]));
        }
        for (String listeElemani : liste) {
            dizilim += listeElemani;
        }
        return dizilim;
    }

}
