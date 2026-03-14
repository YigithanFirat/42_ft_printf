*This project has been created as part of the 42 cirriculum by yfirat.*

# FT_PRINTF

## TANIMLAMA

FT_PRINTF 42 müfredatının bir parçası olarak geliştirilmiştir. Bu projede standart C kütüphanesinde ki printf fonksiyonunu yeniden yazmayı hedefleyen bir projedir.

Bu projenin amacı şunlardır:

* Değişken sayıda argüman alan (variadic functions) yapısını anlamaktır.
* Bellek yönetimi ve veri tiplerini incelemektir.
* Kendi kütüphanemizi oluşturarak kodun yeniden kullanabirliğini sağlamaktır.

Proje %cspdiuxX% desteklemektedir ve standart C kütüphanesi kurallarına uygun hale getirilmiştir.

## TALİMATLAR

### DERLEME

Projenin beraberinde gelen `Makefile` dosyasında ki komutlar ile derlenebilmektedir. Terminale aşağıdaki komutu yazmak yeterli olacaktır.


* **Kütüphaneyi Oluşturmak İçin:**

 ```bash
  make
 ```
* **Oluşturulan Obje Dosyalarını Silmek İçin:**

 ```bash
  make clean
 ```
* **Her Şeyi Silmek İçin: (Arşiv ve Obje Dosyaları):**
 ```bash
  make fclean
 ```

* **Kütüphaneyi Temizleyip Yeniden Derlemek İçin:**
 ```bash
  make re
 ```

Bu komutla birlikte projenin kaynak kodları derlenecek ve `libftprintf.a` dosyasının oluşmasını sağlar.

### ÇALIŞTIRMA

```C
    #include "ft_printf.h"

    int main(void)
    {
        ft_printf("Hello 42");
        return (0);
    }
```

Bu projede recursive fonksiyon kullanımları tercih edilmiştir ( Öz Yinelemeli ). Sayı taban dönüşümleri yapılmıştır ( Hexadecimal, decimal). Sayının her basamağı mod alma ve bölme işlemleriyle yazdırılmıştır. Bu proje yazılırken özel bir struct yapısı kullanılmıştır. Doğrudan stack üzerinde tutulan yerel değişkenler ve variadic list ( va_list ) kullanılmıştır. Bu bizim için bellek kullanımını minimumda tutmamızı sağlamış ve optimize olmasını sağlamıştır.

## KAYNAKLAR

* [Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
* [C stdio printf() Function](https://www.w3schools.com/c/ref_stdio_printf.php)
* [printf() — Print Formatted Characters](https://www.ibm.com/docs/en/i/7.4.0?topic=functions-printf-print-formatted-characters)
* [printf Command](https://www.ibm.com/docs/en/aix/7.2.0?topic=p-printf-command)

## YAPAY ZEKA KULLANIMI

Bu projede yapay zeka şu amaçlarla kullanılmıştır.

* Hata Ayıklama: Oluşan hataları anlamadığım yerlerde yapay zekadan bana hatanın ne demek istediğini sorarak hatayı anlamak için kullandım.
* README.md Hazırlanışı: Proje sonunda README.md hazırlarken şablon ve bana bir taslak oluşturmasını neleri nasıl kurmam ve kullanmam gerektiğini görmek için kullandım.
* Tip Uyumsuzluğu: Projeyi yaparken belli bir yerde tip uyumsuzluğuyla karşılaştım ve bunu bir türlü fark edemedim. Bunu fark etmem için unsigned long long ve unsigned int üstüne bayt açıklaması yaparak uyuşmazlık olduğunu görmemi sağladı.

## PROJENİN DETAYLI ANLATIMI

- Öncelikle format_type.c dosyamda 1 adet static ve 1 adet paylaşımlı yani diğer dosyalarda kullanılabilecek olan bir fonksiyonla birlikte toplam 2 adet fonksiyon barındırmaktadır. Bu dosyadaki ana yani format_type
fonksiyonu aslında %'den sonra gönderilen argümana göre hangi if-else if-else durumuna gireceğini belirliyoruz ve buna göre hangi şartı (csdiupxX%) kontrol ederek gitmesi gereken fonksiyona yönlendirmesi sağlandı. Bu fonksiyon içerisindeki ft_putchar() fonksiyonundan bize döndürülen (-1) durumunun da kontrolünü özellikle ekledim. NORM (25 satır) kuralına takılmaması için de fonksiyonu static olarak böldüm. Hex(x, X), decimal(d), integer(i) ve unsigned int(u) durumları o fonksiyonlar içerisinde ele alınmıştır.

- ft_printf dosyasında ise asıl fonksiyonunun çalışacağı kısımdır. Burada olası hata durumları handle_format fonksiyonunda ele alınmıştır ve -1 döndürerek şart içinde va_end'le bitirilmiş ve return (-1) atılmıştır. Sonrasında ise burada ki işlemler bitirilmiştir.

* va_list Nedir?*

- Argümanların bellekteki yerini tutan bir pointer türüdür.

* va_start Nedir?*

- Bellekte argümandan sonra gelen verinin yerini hesaplayarak listeyi başlatır.

* va_arg Nedir?*

- Listedeki sıradaki argümanı okumamızı sağlar. 2 parametre alır. va_list değişkeni ve değişkeni okumak için verinin türü.

* va_end Nedir?*

- İşlemler bitince listeyi kapatmak için kullanılır. Bellek yönetimi ve kararlılık açısından va_end ile bitirilmesi zorunludur.

- Header dosyasında kullanılacak olan tüm fonksiyon prototipleri ve gerekli kütüphane eklenmiştir.

- ft_putchar içerisinde yazdırıp karakter sayısını saydırma işlemi yapılmıştır. write durumunda -1 gelmesi halinde return (-1) yapılmıştır.

- ft_puthex içerisinde ise `x` veya `X` gelmesi durumu ele alınarak buna göre hexadecimal hesaplama yapılmıştır. putchar'dan gelebilecek -1 durumu kontrol edilmiştir.

- ft_putnbr içerisinde integer aralıklarında ki sayıların yazdırılması ve karakter sayılarının saydırılması sağlanmaktadır. ft_putchar kısmından dönebilecek olan -1 değeri return (-1) ile geri döndürülmektedir.

- ft_putptr içerisinde ise bellek adresi yazdırılması veya (nil) yazdırılması durumu vardır. Bu durumlar ele alınmıştırve aynı şekilde ft_putchar durumunda dönebilecek olan -1 return (-1) ile ele alınmıştır.

- ft_putstr ile kendisine gönderilen char * yazdırılması amaçlanmaktadır ve aynı zamanda karakter sayısı saydırılmaktadır. ft_putchar durumundan gelebilecek -1 durumu return (-1) ile ele alınmıştır.

- ft_putunsign içerisinde ise unsigned int gönderilerek bunun ekrana yazdırılması sağlanmıştır. Burada da ft_putchar durumunda dönebilecek -1 durumu return (-1) ile ele alınmıştır.

- Makefile içerisinde all, clean, fclean ve re komutları eklenmiştir. Burada dosyaların tanımlamaları da koyulmuştur.

- README.md içerisinde ise projeye dair tüm detaylar paylaşılmıştır.
