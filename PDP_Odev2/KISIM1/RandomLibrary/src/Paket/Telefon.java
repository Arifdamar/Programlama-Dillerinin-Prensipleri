/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * Telefon sınıfının dosyasıdır
 * </p>
 */
package Paket;

public class Telefon {

    private int[] telefonNO;
    private IMEINo imeiNo; // Bir IMEINo referansı üretilir

    public Telefon() {
        this.telefonNO = new int[11];
        this.imeiNo = new IMEINo(); // IMEINo referansına bir IMEINo nesnesi atanır
    }

    public void telefonOlustur() {

        Rastgele rastRakam = new Rastgele(); // Rastgele sayı üretmek için bir Rastgele nesnesi üretilir
        this.telefonNO = new int[11]; // 11 boyutlu bir int dizisi oluşturulur
        this.telefonNO[0] = 0; // Telefonun 0. indisine 0 atanır

        this.telefonNO[1] = 5; // Telefonun 1. indisine 5 atanır

        // Türkiye'deki telefon numaralarına uygun olacak şekilde rastgele telefon numarası üretme işlemleri yapılır
        this.telefonNO[2] = rastRakam.sayiOlustur(10);
        while (this.telefonNO[2] != 3 && this.telefonNO[2] != 4 && this.telefonNO[2] != 0 && this.telefonNO[2] != 5) {
            this.telefonNO[2] = rastRakam.sayiOlustur(10);
        }

        if (this.telefonNO[2] == 0) {
            this.telefonNO[3] = rastRakam.sayiOlustur(10);
            while (this.telefonNO[3] != 1 && this.telefonNO[3] != 5 && this.telefonNO[3] != 6 && this.telefonNO[2] != 7) {
                this.telefonNO[3] = rastRakam.sayiOlustur(10);
            }
            for (int i = 4; i < 11; i++) {
                this.telefonNO[i] = rastRakam.sayiOlustur(10);
            }
        } else if (this.telefonNO[2] == 3) {
            for (int i = 3; i < 11; i++) {
                this.telefonNO[i] = rastRakam.sayiOlustur(10);
            }
        } else if (this.telefonNO[2] == 4) {
            for (int i = 3; i < 11; i++) {
                this.telefonNO[i] = rastRakam.sayiOlustur(10);
            }
        } else if (this.telefonNO[2] == 5) {
            this.telefonNO[3] = rastRakam.sayiOlustur(10);
            while (this.telefonNO[3] != 2 && this.telefonNO[3] != 3 && this.telefonNO[3] != 4 && this.telefonNO[3] != 5 && this.telefonNO[3] != 9) {
                this.telefonNO[3] = rastRakam.sayiOlustur(10);
            }
            for (int i = 4; i < 11; i++) {
                this.telefonNO[i] = rastRakam.sayiOlustur(10);
            }
        }
    }

    public int[] getTelefonNo() {
        return this.telefonNO;
    }

    public IMEINo getImei() {
        return this.imeiNo;
    }
}
