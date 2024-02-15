# C++ OOP Solid Class Tanımı

> *Şimdi ilk temel kısmımızda OOP nedir, class nedir, nesne nedir, nasıl tanımlama yaparız gibi temellerimizi öğrendik. Şimdi burada Kurucu Methodlar (constructor), Yıkıcı Methodlar (destructor), vb. bunları göreceğiz.*
> 

---

*Yukarıda ki konuları anlatmadan önce method overloading ( methodun aşırı yüklenmesi) konusunu size anlatmam gerekiyor.*

*Method overloading aynı isimde bir methoddan birden fazla bulunması ancak farklı işlemler yapması durumudur.*

*Örneğin Toplama işlemi yapan bir methodu aşırı yükleme yapalım.*

```cpp
int topla(int x, int y){
	return x + y;
}

int topla(int x, int y, int z){ // 1. Kural Örneği
	return x + y;
}

double topla (int x, double y){ // 2. Kural Örneği
	return x + y;
}

double topla (double x, int y) { // 3. Kural Örneği
	return x + y;
}
```

*Bunun için şu şekilde basit kurallar vardır.*

1. *Paremetre sayı farklı olmalıdır.*
2. *Paremetre sayıları aynı ise aldığı parametreler farklı olmalıdır.*
3. *Paremetre sayısı aynı ve aldığı paremetrelerde aynı ise bu sefer sıraları farklı olmalıdır.*

*Daha fazla overloading yöntemleri vardır ancak şuan için bu kadarı yeterlidir.*

---

*Şimdi Solid Class Tanımında genellikle kullanılan bir form var. Bu formun adı “Orthodox Canonical Form” olarak geçkmekte. Bu forma göre oluşturulan her class’ın şu methodlara sahip olması gerekmektedir.*

- *Bir adet Default Constructor ( Default Yapıcı Method)*
- *Bir adet destructor ( Yıkcı Method)*
- *Bir adet Copy Constructor ( Kopya Oluşturucu Method)*
- *Bir adet assignment operator ( Atama operatörü aşırı yüklemesi)*

*Şimdi bunların neler olduğunu ve nasıl yazılacağını görelim.*

- *CONSTRUCTOR*
    
    İlk başta Constructor (Yapıcı Method) ile başlayalım.
    
    - Kendisinin adı Class adı ile birebir aynı olmak zorundadır.
        
        ```cpp
        class template {
        	private :
        		// class üyeleri...
        	public :
        		template();
        		// diğer methodlar...
        };
        ```
        
    - Bir sınıfta birden fazla constructor olabilir. (Farklı paremetrelere sahip olmak şartıyla.)
        
        ```cpp
        class template {
        	private :
        		// class üyeleri...
        	public :
        		template();
        		template(int x);
        		template(int x, int y)
        		//template(int x); bir daha yazarsam hata alırım.
        		//Bu işlem aynı zamanda bir
        		//methodun aşırı yüklenmesi (method overloading) olarakta adlandırılır.
        		
        		// diğer methodlar...
        };
        ```
        
    - Bir sınıfın nesnesi oluşturulurken çağrılan özel metodlardır.
    - Genellikle üye değişkenlere başlangıç değerlerinin atanmasını ve diğer başlangıç işlemlerini gerçekleştirmek için kullanılır
    - Yapıcı Methotlar ikiye ayrılmaktadır.
        - Paremetreli ve Paremetresiz / Yapıcı Method (Constructor) ve  Kurucu Method (Default Constructor) olarak adlandırılırlar.
    
    ```cpp
    // şimdi bir tane yapıcı method örneği görelim.
    #include <iostream>
    using namespace std;
    
    class kare {
    	private:
    		int x;
    	public:
    		kare(); // Default Constructor
    		kare(int x); // Constructor
    		// Nasıl işlemler yapıcaksanız ona göre bir constructor kurabilirsiniz.
    		void set_x(int x);
    		int get_x();
    };
    
    kare::Kare(){ // Default Constructor genellikle üyelerin değer tanımları yapılır.
    	this->x = 0;
    }
    
    kare::Kare(int x){ // Burada x değerini kullanıcı veriyor bu sayede istedeği değeri atamış oluyoruz.
    	this->x = x;
    }
    
    void kare::set_x(int x){
    	this->x = x;
    }
    
    int kare::get_x(){
    	return this->x;
    }
    
    int main(){
    	int value = 10;
    
    	kare a();
    	kare b(5);
    	kare c(value);
    
    	cout << "a Default Constructor X Değeri : " << a.get_x() << endl;
    	cout << "b Default Constructor X Değeri : " << b.get_x() << endl;
    	cout << "c Default Constructor X Değeri : " << c.get_x() << endl;
    }
    ```
    
    - Şimdi size son olarak dizi halinde bir nesne tanımlarken yapıcı methodu farklı bir şekilde nasıl çağırabileceğimizi gösterceğim.
        
        ```cpp
        #include <iostream>
        using namespace std;
        class dikdortgen{
        	private:
        		int x;
        		int y;
        		std::string name;
        	public:
        		dikdortgen();
        		dikdortgen(int x, int y, std::string name);
        		int get_x();
        		int get_y();
        		//void set_y(int y); (burada kullanmıcağım bu örnekte.)
        		//void set_x(int x);
        };
        
        dikdortgen::dikdortgen(){
        	this->x = 0;
        	this->y = 0;
        	this->name = "";
        	std::cout << "Default Constrcutor Çağırıldı" << std::endl;
        }
        
        dikdortgen::dikdortgen(int x, int y, std::string name){
        	this->x = x;
        	this->y = y;
        	this->name = name;
        
        	std::cout << "Constructor Çağrıldı " << this->name << " tarafından." << std::endl;
        	std::cout << "Sınıf değerleri:\nx: " << this->x << "\ny: " << this->y << std::endl;
        }
        
        int main(){
        	dikdortgen A;
        	dikdortgen B(5, 10, "B");
        
        	// bunlar az önce öğrendiğiniz constructor kullanım şekli.
        	dikdortgen C[3];// Burada tamamen default constructor çalışacaktır.
        	dikdortgen D[3] = { dikdortgen(1,2,"D"), dikdortgen(3,5,"D"), dikdortgen(4,5,"D") };
        	// Bu şekilde D dikdörtgen nesne dizisinin her bir barındığı nesne için 
        	// ikinci yapıcı methodumuz çalışır.
        }
        ```
        
        Ekran çıktısı şu şekilde olacaktır.
        
        > Default Constrcutor Çağırıldı
        Constructor Çağrıldı B tarafından.
        Sınıf değerleri:
        x: 5
        y: 10
        Default Constrcutor Çağırıldı
        Default Constrcutor Çağırıldı
        Default Constrcutor Çağırıldı
        Constructor Çağrıldı D tarafından.
        Sınıf değerleri:
        x: 1
        y: 2
        Constructor Çağrıldı D tarafından.
        Sınıf değerleri:
        x: 3
        y: 5
        Constructor Çağrıldı D tarafından.
        Sınıf değerleri:
        x: 4
        y: 5
        > 
        
- DESTRUCTOR
    
    Destructor (Yıkıcı method),  sınıfların ömrünü sonlandırmak ve sınıfın sahip olduğu kaynakları serbest bırakmak için kullanılan özel bir üye metoddur. Bir sınıfın destructor'ı, nesnesi bir kapsamdan (scope) çıkarken veya ***“delete”*** operatörü ile bellekten serbest bırakıldığında otomatik olarak çağrılır.
    
    Destructor tanımlamak için “***~ (Tilda)classAdı()***” şeklinde tanımlanır. Burada “~” işareti bu methodun Destructor olduğunu temsil eder. Constructorların aksine Destructor’lar sadece bir tane olmak zorundadır.  
    
    Destructor’ a neden ihtiyacımız vardır?
    
    - Leaks (sızıntıları) engellemek amacıyla kullanırız. Sınıf içerisinde kullandığımız dinamik bellek adreslerini burada serbest bırakarak hem clean hem okunaklı bir koda sahip olmuş oluruz.
    - Aynı zamanda bu method, sınıfın ömrü sona erdiğinde otomatik olarak gerçekleştiği için bizim manuel bir müdahale etmemize gerek kalmaz.
    
    Örnek bir Destructor Kullanımı;
    
    ```cpp
    #include <iostream>
    
    class Template {
    private:
        int* data;
    
    public:
        // Constructor
        Template();
        // Destructor
        ~Template();
        void displayData();
    };
    
    Template::Template() {
    	data = new int[5];
      std::cout << "Constructor çağrıldı" << std::endl;
    }
    
    Template::~Template() {
    	delete[] data;  // Dinamik olarak tahsis edilmiş belleği serbest bırak
      std::cout << "Destructor çağrıldı" << std::endl;
    }
    
    void Template::displayData(){
    	for (int i = 0; i < 5; ++i) {
         std::cout << data[i] << " ";
      }
      std::cout << std::endl;
    }
    
    int main() {
        Template temp1;  // Constructor çağrılır
        temp1.displayData();   // Sınıfın bir metodunu çağırabiliriz
        // Programın sonunda obj'nin ömrü sona erdiği için Destructor çağrılır
    
    	Template *temp2 = new Template; // Pointer Olarak oluşturursak eğer
    	temp2->displayData();
    	delete temp2; // Kendimiz el ile silmek zorundayız yoksa leaks olarak kalır
      return 0;
    }
    ```
    
    > Ekran Çıktısı bu şekilde olacaktır.
    > 
    > 
    > Constructor çağrıldı
    > 0 0 0 0 0
    > Constructor çağrıldı
    > 0 0 0 0 0
    > Destructor çağrıldı // Temp2’nin Destructor’ı
    > Destructor çağrıldı // Temp1’in Destructor’ı
    > 
    > Temp1’in en son çalışma nedeni pointer olarak tanımlamadığımız için scope bittiğinde otomatik olarak çalışmasıdır.
    > 
    
    Bellekte dinamik bir yer ayırmadıysak ne yapcağız?
    
    ```cpp
    ~Template() {
    	std::cout << "Destructor çağrıldı" << std::endl;
    }
    ```
    
- *COPY CONSTRUCTOR*
    
    *Şimdi **Copy Constructor**  bizim hali hazırda oluşturduğumuz olan bir nesnemizi başka bir nesneye kopyalama yapmamızı sağlayan bir methoddur.*
    
    ***Buna neden ihtiyaç duyuyoruz?***
    
    - *Copy constructor, genellikle bir sınıftan türetilen bir nesne oluşturulduğunda, bir nesnenin değerlerini başka bir nesneye kopyalamanın nasıl yapılacağını belirlemede kullanılır. Bu işlemi sınıf üstünde bir constructor ile yapmak hem daha güvenli hem okunabilirlik açısından daha iyidir. Bu, özellikle dinamik bellek tahsisi, kaynak yönetimi veya diğer özel durumlar söz konusu olduğunda önemli bir işlemdir.*
    - *Bazı durumlarda, C++ derleyicisi tarafından otomatik olarak bir copy constructor oluşturulabilir. Ancak, özel kaynak yönetimi veya özellikle derin kopyalama (Deep Copy) gerektiren durumlarda, programcılar kendi copy constructor'larını tanımlamayı tercih ederler. Bunun nedeni oluşabilecek bir bellek hatası sorunun önüne geçmektir.*
    
    *Şimdi Copy Constructor’ı nasıl yazıcağımızı görelim 🙂*
    
    ```cpp
    #include <iostream>
    using namespace std;
    
    class Human {
    	private:
    		std::string name;
    		std::string surname;
    		int age;
    	public:
    		Human();
    		Human(std::string name, std::string surname, int age);
    		Human(const Human& copy);
    
    		// get ve set methodlarını ben şimdilik yazmıyorum.
    		// siz kendiniz örnek olarak mainler yazarken 
    		// kendiniz yazıp hem alışmış olursunuz
    		// (Kesinlikle gece gece yazarken üşenmedim :) )
    };
    
    Human::Human() {
    	this->name = "";
    	this->surname = "";
    	this->age = 0;
    }
    
    Human::Human(std::string name, std::string surname, int age) {
    	this->name = name;
    	this->surname = surname;
    	this->age = age;
    }
    
    Human::Human(const Human& copy) {
    	//şimdi burası copy constructor'ımız.
    	//Burada bu işlemi iki şekilde yapabiliriz.
    
    	// Birincisi tüm değişkenleri teker teker eşitleyebiliriz.
    	this->name = copy.name;
    	this->surname = copy.surname;
    	this->age = copy.age;
    
    	// İkincisi ise Assignment Operator kullanarakta yapabiliriz.
    	//*this = copy;
    	// burada işi assigment operator'e devrederek devam ederiz.
    	// özel bir kopyalamaya ihtiyacımız yoksa.
    }
    ```
    
    *Şimdi aklınıza iki soru gelebilir.* 
    
    - *Birincisi neden Copy Constructor ‘da aldığımız nesne “**const**” alıyoruz?*
        - *Bunun nedeni kopyalayacağımız nesnenin değerlerinin üyelerinin değiştirebilme olasağını ortadan kaldırmaktır. Çünkü bu kopyalama işleminde isticeğimiz bir şey değildir.*
    - *İkincisi ise neden “**& (Referans)**” kullanıyoruz? (**const Human& copy**)*
        - Şimdi referans kullanmak yerine pointer kullanabilirdik veya sadece “const Human copy” yazabilirdik. Bunları tercih etmeme nedenimiz tamamen optimizasyondur.
        - Öncelikle referanslar biliyorsunuz ki bellekte ayrı bir yerleri yoktur. Değişkenle aynı yerde küçük bir alan kaplamaktadır. Pointerlar ise bellekte bir adrese sahiptir. Fazladan bir pointer tutmuş oluruz ramde belirli bir süre boyunca. Bu yüzden referans kullanmak pointer kullanmaktan daha verimlidir.
        - “***const Human copy***” kullanmama nedenimiz ise bu şekilde yazdığımızda bu methoda Human class’nı geçici bir kopyası gönderilmiş olur. Bu sırada arka planda bir kopyalama süreci yaşanır. Büyük class yapılarında ciddi bir optimizasyon sorununa sebep olacaktır.
- ASSIGNMENT OPERATOR OVERLOADING
    
    Evet doğru okudun “=” operatörünü aşırı yükleme yapcağız.
    
    Neden?
    
    Şimdi bildiğin üzere “=” bir atama yapmak için kullanıyoruz ancak bir nesneyi başka bir nesneye aktarmaya çalıştığımızda hata alırız. Çünkü bir nesneyi normal şartlarda başka bir nesneye atayamayız. Bunu yapabilmek için ***“Assignment Operator Overloading”*** yapıyoruz.
    
    ```cpp
    class temp1{
    	public:
    		int x;
    		int y;
    
    		//.. diğer methodlar
    }
    
    int main(){
    	temp1 a;
    	temp2 b;
    
    	// a nesnesini b nesnesine atamak istersen hata alırız.
    	b = a;
    }
    // buradaki "b = a" hata vericektir.
    ```
    
    Atama operatörüne aşırı yükleme yaparak istediğimiz işlemesini yapmayı sağlayabiliriz.
    
    C++ dilinde, farklı/aynı sınıflar arasında doğrudan bir nesnenin diğerine ataması yapılamaz, çünkü sınıflar arasında varsayılan olarak tanımlı bir atama işlemi yoktur. Yani, **`b = a;`** ifadesinde **`a`** ve **`b`** nesneleri aynı sınıfa (**`temp1`**) ait olmasına rağmen, C++ dilinde otomatik olarak bir atama operatörü bulunmaz. Bu nedenle, **`b = a;`** ifadesi geçerli değildir ve derleme hatası alırsınız.
    
    Eğer **`a`** ve **`b`** nesneleri aynı sınıfa (**`temp1`**) ait olduğu için değerlerini kopyalamak istiyorsanız, **`temp1`** sınıfı için uygun bir kopyalama (copy) işlemi tanımlamanız gerekecektir. **`temp1`** sınıfına özel bir ***assignment operatörü*** yazarak bu işlemin yapılmasını sağlayabiliriz.
    
    ```cpp
    class temp1 {
    public:
        int x;
        int y;
    
    		//diger methodlar...
    
        // Assignment operator tanımı
        temp1& operator=(const temp1& copy);
      }
    };
    
    temp1& temp1::operator=(const temp1& copy) {
            this->x = other.x;
            this->y = other.y;
            return *this;
    // Burada değerlerin kopyalama işlemlerini manuel bir şekilde yapmış oluyoruz.
    // Bu sayede b = a; işlemindeki kopyalama işlemi gerçekleşmiş oluyor.
    }
    int main() {
        temp1 a;
        temp1 b;
    
        // a nesnesinin değerlerini b nesnesine kopyalamak için assignment operatörü tanımlanmıştır
        b = a;
    
        return 0;
    }
    ```
    

Şimdi şuraya bir Deep Copy Örneği Bırakıyorum 🙂

- *Deep Copy*
    
    ```cpp
    #include <iostream>
    #include <cstring>
    
    class DeepCopy {
    	public:
       		int size;
        	int* data;
    
    		// Default constructor
    		DeepCopy(int size) : size(size) {
    			data = new int[size];
    		}
    		// Buradaki size(size) aklınızı karıştırmasın bu aslında şu anlama geliyor
    		/*
    		DeepCopy(int size) {
    			this->size = size;
    			data = new int[size];
    		}
    		Kısaltma bir kullanımdır. */
    
    		// Copy constructor (deep copy)
    		DeepCopy(const DeepCopy& other) : size(other.size) {
    			//Burada ki de aynı anlama geliyor this->size = other.size;
    			data = new int[size];
    			std::memcpy(data, other.data, size * sizeof(int));
    			std::cout << "Deep copy constructor çağırıldı." << std::endl;
    		}
    
    		// Destructor
    		~DeepCopy() {
    			// Dinamik bellek kullandığımız için Destructor da siliyoruz.
    			delete[] data;
    		}
    };
    
    int main() {
        // Orijinal nesne oluşturuluyor
        DeepCopy obj1(3);
        obj1.data[0] = 1;
        obj1.data[1] = 2;
        obj1.data[2] = 3;
    
        // Derin kopya yapılıyor
        DeepCopy obj2 = obj1;
    
        // Birinci nesnenin verileri değiştiriliyor
        obj1.data[0] = 10;
    
        // İkinci nesnenin verileri bastırılıyor
        std::cout << "obj2.data[0]: " << obj2.data[0] << std::endl; // Derin kopya olduğu için obj2.data[0] hala 1
        std::cout << "obj2.data[1]: " << obj2.data[1] << std::endl;
        std::cout << "obj2.data[2]: " << obj2.data[2] << std::endl;
    
        return 0;
    }
    ```