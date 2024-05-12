Proje Ekibi:
	ENES BURAK KAYA  B221210351
	Umut Can Konukçu B211210069

Amaç:
  	Bu kod, bir dosyadan alınan komutlarla bir bağlı liste üzerinde değişiklikler yapmayı sağlar.
	Kodun genel amacı şu işlemleri gerçekleştirmektir:
		1-Giriş dosyasından komutları oku ve işle.
		2-"yaz:" komutuyla belirtilen karakterleri belirtilen sayıda listeye ekle.
		3-"sil:" komutuyla belirtilen karakterleri belirtilen sayıda listeden sil.
		4-"sonagit:" komutuyla listedeki işlemi en baştan başa geri al.
		5-"dur:" komutuyla listenin son halini bir çıkış dosyasına yaz.

Projenin içeriği:
	linkedlist.h
		Bu başlık dosyası, bağlı listenin düğüm yapısını ve bu yapıya ait temel işlevleri içermektedir. Yapı aşağıdaki elemanlardan oluşur:
		data: Düğümde tutulan veri
		next: Bir sonraki düğümü işaret eden işaretçi
		prev: Bir önceki düğümü işaret eden işaretçi (yenilik olarak eklenmiştir)
		Aşağıdaki işlevler başlık dosyasında tanımlanmıştır:
		createNode: Yeni bir düğüm oluşturur ve veri ile başlatır.
		insert: Belirtilen veriyi listenin başına ekler.
		printList: Bağlı listeyi ekrana yazdırır.
		deleteNode: Belirtilen düğümü listeden siler.
	
	linkedlist.c
		Bu dosya, linkedlist.h başlık dosyasında tanımlanan işlevlerin kodlarını içerir. createNode, insert, printList, ve deleteNode işlevleri bu dosyada uygulanmıştır.
	
	Program.c
		Ana program dosyası, bağlı liste işlemlerini kullanarak veri manipülasyonu sağlar. Program, komutlar alır ve bu komutlara göre bağlı listeyi günceller. Ayrıca, bir giriş dosyasından
		komutları okur, bu komutları yorumlar ve sonuçları bir çıkış dosyasına yazar.

	Programın ana işlevleri şunlardır:
		write: Belirtilen karakterleri belirtilen sayıda listeye ekler.
		delete_chars: Belirtilen karakterleri belirtilen sayıda listeden siler.
		goToLastNode: Listenin son düğümüne gitmeyi sağlayan yardımcı işlev.
		printListToFile: Listeyi bir dosyaya yazdıran işlev.
		main: Ana işlem, giriş dosyasından komutları okur, işler ve çıktıyı bir dosyaya yazar.
