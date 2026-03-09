# FT_PRINTF

*This project has been created as part of the 42 cirriculum by yfirat.*

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
