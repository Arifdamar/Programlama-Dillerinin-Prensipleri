/**
*
* @author Arif Damar arif.damar@ogr.sakarya.edu.tr || Arif Yusuf Yılmaz arif.yilmaz3@ogr.sakarya.edu.tr
* @since 07/03/2020
* <p>
* Bir metin dosyasını okuyup içerisindeki email, web sitesi, sesli harf, karakter ve cümle sayısını bulan program
* </p>
*/

package pdp_odev1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;


public class PDP_Odev1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        // Gerekli sayaçların tanımlanması
        int email = 0;
        int sesliHarf = 0;
        int cümle = 0;
        int web = 0;
        int kelime = 0;
        
        //Bütün dosyanın içeriğini tutacak string dizilerinden oluşan bir Liste yapısı tanımlanır
        List<String[]> content = new ArrayList<>();
        
        // Gerekli regex yapıları kurulur
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$"; 
        String webRegex = "^(http:\\/\\/www\\.|https:\\/\\/www\\.|http:\\/\\/|https:\\/\\/)?[a-z0-9]+([\\-\\.]{1}[a-z0-9]+)*\\.[a-z]{2,5}(:[0-9]{1,5})?(\\/.*)?$";
        
        // Dosyanın okunması işlemine başlanır
        try
        {
            File myObj = new File("icerik.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) // Dosyadaki her bir satır tek tek okunur
            {
                String[] line;
                String data = myReader.nextLine(); // okuyucu bir sonraki satırı okumaya geçer
                line = data.split(" "); // Her satır boşluk karakterine göre split edilir
                content.add(line); // her bir satır liste içerisine eklenir
            }
        }
        catch(FileNotFoundException e) // Dosya yolu bulunamadığı durumda hata mesajı verilir
        {
            System.out.println("Dosya bulunamadı.");
            e.printStackTrace();
        }
        
        // Regex yapıları compile edilir
        Pattern patemail = Pattern.compile(emailRegex); 
        Pattern patweb = Pattern.compile(webRegex);
        
        for (String line[] : content) // Dosya içerisindeki her bir satır tek tek dolaşılır
        { 
            for (String var : line) // Her bir satırdaki boşluklarına göre ayrılmış yapılar tek tek dolaşılır
            {
                for (int i = 0; i < var.length(); i++) // Her bir yapının bütün harfleri tek tek dolaşılır
                {
                    if (var.charAt(i) == 'a' || var.charAt(i) == 'A' || var.charAt(i) == 'e' || var.charAt(i) == 'E' || 
                        var.charAt(i) == 'i' || var.charAt(i) == 'İ' || var.charAt(i) == 'ı' || var.charAt(i) == 'I' ||
                        var.charAt(i) == 'ö' || var.charAt(i) == 'Ö' || var.charAt(i) == 'o' || var.charAt(i) == 'O' ||
                        var.charAt(i) == 'u' || var.charAt(i) == 'U' || var.charAt(i) == 'ü' || var.charAt(i) == 'Ü')
                    { // Dolaşılan harfin sesli harf olması durumunda sesli harf sayacı 1 arttırılır
                        sesliHarf++;
                    }
                }
                
                if(patemail.matcher(var).matches())
                {// Yapılar içerisinde email regexine uyan bir format bulunduğunda email sayacı 1 arttırılır
                    email++;
                }
                
                if(patweb.matcher(var).matches())
                {// Yapılar içerisinde web sitesi regexine uyan bir format bulunduğunda email sayacı 1 arttırılır
                    web++;
                }
                
                if (var.length()==0) 
                {// Art arda birden fazla boşluk girilmesi durumunda onlar da kelime olarak sayıldığından
                 // düzenleme yapılması için kelime sayısı azaltılır
                    kelime--;
                }
                else
                {// Yapının boşluk olduğu durumdan kaçınıldığı için artık yapının son karakterine bakıp cümle ifade edip etmediğine bakabiliriz
                    if(var.charAt(var.length()-1) == '.')
                    {// Yapının son karakteri . ise cümle sayacı 1 arttırılır
                        cümle++;
                    }
                }
                
                kelime++; // Her yapı döngüsünde kelime sayısı 1 arttırılır
            }
        }
        
        // Programın çalışması bittikten sonra veriler ekrana yazdırılır
        System.out.println("Toplam Sesli Harf Sayısı: " + sesliHarf);
        System.out.println("Toplam Kelime Sayısı: " + kelime);
        System.out.println("Toplam Cümle Sayısı: " + cümle);
        System.out.println("Toplam Email Sayısı: " + email);
        System.out.println("Toplam Web Sitesi Sayısı: " + web);
    }
    
}
