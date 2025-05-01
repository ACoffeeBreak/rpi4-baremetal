#ifndef UART_BETA_H
#define UART_BETA_H

void sends_uart(/* Hızlıca ve kolayca gönderilmek istenen veri */) {
    /* Veri parçalara ayrılır ve her birinin tipi belirlenerek
    uygun ASM fonksiyonları, verimli bir şekilde çağırılır.
    */

    /* Verideki parçalar, string ise mümkünse verimli char dizilerine
    dönüştürülür, daha verimli olmayacaksa klasik string şeklinde 
    işlenir. (Buna göre tek bir kod yazacağız, ona sen karar ver.)
    Sayısal veriler ayrıştırılarak tam ya da kayan noktalı haliyle 
    iletilir. Her verinin doğru şekilde iletilmesi, işleyen tarafın
    algoritmalarının yükünü azaltmak içindir. Fakat doğrudan tüm
    mesajı string/char dizisi halinde gönderebilmek ve veri işlemeyi
    alıcıya yüklemek şeklinde bir seçenek de olacaktır.
    Sistemde açık olmaması bakımından bool ve diğer türleri ayıran
    bir ayar olur. Bu ayara göre bool verileri ya yalnızca true ya da
    false şeklinde yazılmak zorundadır ya da diğer seçeneğe göre bu C
    fonksiyonumuz, onu 1 ya da 0 olarak gördüğü her veriyi boola çevirir.
    Bunu önlemek için bu fonksiyona veri gönderirken sayısal 1 değeri
    için //int(1) değeri şeklinde yazılmalıdır.
    Veri dizisindeki istenen değerler belirli spesifik değişkenler
    şeklinde gönderilebilir, //int(), //float(), //short()... bu
    şekilde. Fakat bu şekilde özel olarak belirtilen verilerin de
    istenen tipe uygun olup olmadığı inceleyen bir ana ayar, korumalı
    mod gibi fonksiyona eklenmelidir. Normalde, varsayılan olarak
    gönderilen veriler optimize edilir. Yani 127 değeri int olarak
    belirtilmezse char olarak gönderilecektir. Eğer istenen uzunlukta
    byte'larla gönderilmek istenirse, ya bunun ayarı başta fonksiyona
    ayar parametreleri gönderilirken yapılmalı ya da her istenen veri
    için özel bir değer ayarlanmalı. Örneğin: \\64//float(5.56)
    Burada, eğer float veri tipinin varsayılan bit uzunluğundan küçük
    bir değer girilirse hata verilir. Ama büyük bir değer girilirse
    ona göre yüksek bitler boş halde gönderilir.
    
    Bu fonksiyonda mesela şöyle bir gönderim yapılır:
    
    void sends_uart(const *char[] complex_data, int global_data_length, bool type_saving);*/

}

#endif