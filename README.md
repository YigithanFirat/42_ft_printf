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

```bash
    make
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
