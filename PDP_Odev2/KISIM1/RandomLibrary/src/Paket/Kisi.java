/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Kisi sınıfı dosyasıdır
 * </p>
 */
package Paket;

public class Kisi {

    // Her Kisi'nin sahip olduğu alt alanlar tanımlanır
    private String isim;
    private String soyIsim;
    private int yas;
    private KimlikNo tcNo; // KimlikNo referansı oluşur
    private Telefon telefon; // Telefon referansı oluşur
    
    public Kisi() {
        this.tcNo = new KimlikNo(); // Oluşan KimlikNo referansına bir KimlikNo nesnesi atanır
        this.telefon = new Telefon(); // Oluşan Telefon referansına bir Telefon nesnesi atanır
    }

    // Alt alanların get ve set metodları tanımlanır
    public String getIsim() {
        return this.isim;
    }

    public void setIsim(String isim) {
        this.isim = isim;
    }

    public String getSoyIsim() {
        return this.soyIsim;
    }

    public void setSoyIsim(String soyIsim) {
        this.soyIsim = soyIsim;
    }

    public int getYas() {
        return this.yas;
    }

    public void setYas(int yas) {
        this.yas = yas;
    }

    public KimlikNo getTc() {
        return this.tcNo;
    }

    public Telefon getTelefon() {
        return this.telefon;
    }
}
