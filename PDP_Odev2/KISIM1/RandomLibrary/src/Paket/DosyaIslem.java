/**
 *
 * @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
 * @since 20/04/2020
 * <p>
 * DosyaIslem sınıfının dosyasıdır
 * </p>
 */
package Paket;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DosyaIslem {

    // Gerekli alt alanlar tanımlanır
    String[] isimler;
    String[] soyIsimler;
    List<String[]> uretilmis;

    public DosyaIslem() {
        this.isimler = new String[3000]; // 3000 boyutlu bir string dizisi atanır
        this.soyIsimler = new String[3000]; // 3000 boyutlu bir string dizisi atanır
        this.uretilmis = new ArrayList<>(); // Bir ArrayList üretilir
    }

    public void icerikDosyaOku() {

        List<String[]> icerik = new ArrayList<>(); // İçeriğin tutulması için bir string dizisi listesi oluşturulur
        try {
            File file = new File("random_isimler.txt"); // Sisteme yüklenen random_isimler dosyasından okuma yapılır

            Scanner reader = new Scanner(file); // Dosyadan okuma işlemleri yapılır
            while (reader.hasNextLine()) {
                String[] line;
                String data = reader.nextLine();
                line = data.split(" "); // Her satır boşluk karakterine göre split edilerek line içerisinde tutulur
                icerik.add(line); // Her satır icerik listesine eklenir
            }
            reader.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DosyaIslem.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("*****Dosya Okunamadı*****"); // Dosyanın okunmasıyla ilgili hata oluşursa ekrana uyarı yazdırılır
        }

        int isimlerBoyut = 0;
        int soyIsimlerBoyut = 0;

        int index = 0;
        for (String[] satir : icerik) { // Her satır tek tek döndürülür
            for (String eleman : satir) { // Her satırdaki elemanlar tek tek döndürülür
                if (index % 2 == 0) { // Her satırdaki çift indisler isimleri temsil ettiğinden isimler dizisine atanır
                    this.isimler[isimlerBoyut] = eleman;
                    isimlerBoyut++;
                } else { // Her satırdaki tek indisler soyisimleri temsil ettiğinden soyisimler dizisine atanır
                    this.soyIsimler[soyIsimlerBoyut] = eleman;
                    soyIsimlerBoyut++;
                }
                index++;
            }
        }
    }

    public void dosyaYaz(String dosyaIsmi, String yazilacak) {

        try {
            BufferedWriter writer;
            writer = new BufferedWriter(new FileWriter(dosyaIsmi, true));

            writer.write(yazilacak); // gelen yazılacak parametresi dosyaya yazılır
            writer.newLine(); // yeni satır oluşturur
            writer.close();
        } catch (IOException ex) {
            Logger.getLogger(DosyaIslem.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void dosyaTemizle(String dosyaIsmi) {
        try {
            FileWriter writer = new FileWriter(dosyaIsmi);
        } catch (IOException ex) {
            Logger.getLogger(DosyaIslem.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    public void uretilmisDosyaOku() {
        try {
            File file = new File("Kisiler.txt"); // Üretilmiş Kisiler.txt dosyası açılır
            this.uretilmis = null; // uretilmis listesinin null'ı göstermesi sağlanır
            this.uretilmis = new ArrayList<>(); // uretilmis'e yeni bir list ataması yapılır
            Scanner reader = new Scanner(file);
            while (reader.hasNextLine()) {
                String[] line;
                String data = reader.nextLine();
                line = data.split(" "); // Her satır boşluk karakterine göre split edilerek line içerisinde tutulur

                this.uretilmis.add(line); // Her satır uretilmis listesine eklenir

            }
            reader.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DosyaIslem.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("*****Dosya Okunamadı*****"); // Dosyanın okunmasıyla ilgili hata oluşursa ekrana uyarı yazdırılır
        }
    }

    public void Kontrol() {
        KimlikNo kimlik = new KimlikNo(); // Yeni bir KimlikNo nesnesi oluşturulur
        IMEINo imei = new IMEINo(); // Yeni bir IMEINo nesnesi oluşturulur
        int bozukSatir = 0;
        List<String> tcKimlikNumaraları = null; // tcKimlikNumaraları listesinin null'ı göstermesi sağlanır
        List<String> imeiNumaraları = null; // imeiNumaraları listesinin null'ı göstermesi sağlanır
        tcKimlikNumaraları = new ArrayList<>(); // tcKimlikNumaraları'na yeni bir list ataması yapılır
        imeiNumaraları = new ArrayList<>(); // imeiNumaraları'na yeni bir list ataması yapılır
        for (String[] line : this.uretilmis) {
            if (line.length != 6) {
                // Eğer satır istenen formatın dışındaysa bozuk satır olarak değerlendirilir ve içindeki değerlerin kontrolü yapılmaz
                bozukSatir++;
            } else {
                tcKimlikNumaraları.add(line[0]); // 0 ise TC
                imeiNumaraları.add(line[5]); // 5 ise Imei
            }
        }
        if (bozukSatir > 0) {
            System.out.println("**" + bozukSatir + " adet bozuk satır var**");
            System.out.println("Bozuk satırlar T.C. kimlik ve Imei kontrollerine tabi tutulmaz");
        }
        kimlik.tcKimlikKontrol(tcKimlikNumaraları); // KimlikNo nesnesinin kontrol metodu çağrılır
        imei.imeiNoKontrol(imeiNumaraları); // IMEINo nesnesinin kontrol metodu çağrılır
    }

}
