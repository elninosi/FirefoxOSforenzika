   #include <direct.h>
   #include <iostream>
   #include <windows.h>
   using namespace std;

void start()
{
 system("C:/FirefoxOSforenzika/FirefoxPortable/FirefoxOS_forenzika.exe -no-remote file:///C:/FirefoxOSforenzika/index.html");
}

void adb_baze()
{
 cout<<"ADB - BAZE"<<endl;
    
    char direktorij[255]; //polje
    getcwd(direktorij,255); 
    char a = direktorij[0];
    
        int os;
    cout<<"-------------------------------"<<endl
        <<"|  (1) Firefox OS: 1.0 - 1.4  |"<<endl
        <<"|  (2) Firefox OS: 2.0 - 2.2  |"<<endl
        <<"|  (3) Firefox OS: 2.2 - 2.5+ |"<<endl
        <<"-------------------------------"<<endl;
    cout<<"Izberi verzijo operacijskega sistema:"<<endl;
    cin>>os;
    
    if(os == 1)
    {
        string adbpull = string ("adb pull /data/local/indexedDB/ ");
        string lokacija = a+ string(":/FirefoxOSforenzika/adbPull/");
        string prevzem = adbpull+lokacija;
        system ( prevzem.c_str() );
    }
    
    if(os == 2)
    {
        string adbpull = string ("adb pull /data/local/storage/persistent/ ");
        string lokacija = a+ string(":/FirefoxOSforenzika/adbPull/");
        string prevzem = adbpull+lokacija;
        system ( prevzem.c_str() );
    }
    
    if(os == 3)
    {
        string adbpull = string ("adb pull /data/local/storage/ ");
        string lokacija = a+ string(":/FirefoxOSforenzika/adbPull/");
        string prevzem = adbpull+lokacija;
        system ( prevzem.c_str() );
    }
    else 
    {
     cout<<"Nepravilen vnos."<<endl; 
    } 
    
    //system ("adb pull /data/local/storage/persistent/chrome/idb/ C:\\FirefoxOSforenzika\\adbPull\\ ");

}

void adb_sdcard()
{
    cout<<"ADB - SD CARD"<<endl;
    
    char direktorij[255]; //polje
    getcwd(direktorij,255); 
    char a = direktorij[0];
    
    int os;
    cout<<"-------------------------------"<<endl
        <<"|  (1) Firefox OS: 1.0 - 2.1  |"<<endl
        <<"|  (2) Firefox OS: 2.2 - 2.5+ |"<<endl
        <<"-------------------------------"<<endl;
    cout<<"Izberi verzijo operacijskega sistema:"<<endl;
    cin>>os;
    
    if(os == 1)
    {
          string adbpull = string ("adb pull /mnt/ ");
          string lokacija = a+ string(":/FirefoxOSforenzika/SDCARD/");
          string prevzem = adbpull+lokacija; 
          system ( prevzem.c_str() );
          
          string shell ("adb shell");
          string dodatek (" ls -lR mnt/ >");
          string izpis = a+ string(":/FirefoxOSforenzika/files.txt");
          string skupaj = shell+dodatek+izpis;
          system (skupaj.c_str());
    }
    
    if (os == 2)
    {
          string adbpull = string ("adb pull /storage/ ");
          string lokacija = a+ string(":/FirefoxOSforenzika/SDCARD/");
          string prevzem = adbpull+lokacija; 
          system ( prevzem.c_str() );
  
          string shell ("adb shell");
          string dodatek (" ls -lR storage/sdcard >");
          string izpis = a+ string(":/FirefoxOSforenzika/files.txt");
          string skupaj = shell+dodatek+izpis;
          system (skupaj.c_str());
    }
    else 
    {
     cout<<"Nepravilen vnos."<<endl; 
    }
    //system ("adb pull /data/local/storage/persistent/chrome/idb/ C:\\FirefoxOSforenzika\\adbPull\\ ");
    
    //system("adb devices"); // poka�i vse naprave

   system ("pause");     
}

void kopiraj()
{
if (mkdir("C:/FirefoxOSforenzika/Datoteke") == mkdir("C:/FirefoxOSforenzika/Datoteke"))
          {
            cout<<"Pozdravljeni nazaj!"<<endl<<endl;
            cout<<"V mapo 'Datoteke' kopirajte datoteke za analizo."<<endl;
            system("pause");                                       
          }
          else
          {
              cout<<"Kreiranje mape za vhodne podatke."<<endl;
              mkdir("C:/FirefoxOSforenzika/Datoteke");
              cout<<"V mapo Datoteke kopirajte datoteke za analizo."<<endl;
              system("pause");
          }
          
          if(mkdir("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html") == mkdir("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html"))
          {
                                                                                                           
          cout<<"Zacetek kopiranja:"<<endl;
          
                                 string 
                                 source = string("C:/FirefoxOSforenzika/Datoteke"),
                                 destiny = string("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb");
                                 source = string("\"") + source + string("\"");
                                 destiny = string("\"") + destiny + string("\"");
                                 string command = string("xcopy") + string(" ") + source + string(" ") + destiny + string(" /s");
                                 system( command.c_str() );
          cout<<"Kopiranje koncano."<<endl<<endl;
          system("pause");
          cout<<"Odpri podatke?"<<endl<<endl;
          system("pause");                   
          start(); 
          }
          
          else
          {
          cout<<"Ni ujemanja, kopiram potrebne datoteke."<<endl;
          mkdir("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb");
                                 
                                 string 
                                 source = string("C:/FirefoxOSforenzika/file++++C++FirefoxOSforenzika+index.html"),
                                 destiny = string("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html");
                                 source = string("\"") + source + string("\"");
                                 destiny = string("\"") + destiny + string("\"");
                                 string command = string("xcopy") + string(" ") + source + string(" ") + destiny;
                                 system( command.c_str() );
                           
                                 string 
                                 source1 = string("C:/FirefoxOSforenzika/file++++C++FirefoxOSforenzika+index.html/idb"),
                                 destiny1 = string("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb");
                                 source1 = string("\"") + source1 + string("\"");
                                 destiny1 = string("\"") + destiny1 + string("\"");
                                 string command1 = string("xcopy") + string(" ") + source1 + string(" ") + destiny1;
                                 system( command1.c_str() );
          
                                 string 
                                 source2 = string("C:/FirefoxOSforenzika/Datoteke"),
                                 destiny2 = string("C:/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb");
                                 source2 = string("\"") + source2 + string("\"");
                                 destiny2 = string("\"") + destiny2 + string("\"");
                                 string command2 = string("xcopy") + string(" ") + source2 + string(" ") + destiny2;
                                 system( command2.c_str() );
                                 start();
          }
     
}

    int main()
    {     
          int izbira;
          cout<<"Program za Forenziko - Firefox OS"<<endl;
      do
       {
           cout<<"------------------------------------"<<endl
               <<"|  (1) Pridobi pravice             |"<<endl
               <<"|  (2) Preglej naprave             |"<<endl
               <<"|  (3) Prenesi baze iz naprave     |"<<endl
               <<"|  (4) Prenesi datoteke iz naprave |"<<endl
               <<"|  (5) Preglej baze                |"<<endl
               <<"|----------------------------------|"<<endl
               <<"|  (0) Izhod iz programa           |"<<endl
               <<"------------------------------------"<<endl;
           
           cout<<"Vnesi izbiro: ";
           cin>>izbira;
           cout<<"\n";
                     
           switch(izbira)
            {
            case 1:
                 system("adb root");
                 break;
            case 2:
                system("adb devices");
                break;
            case 3:
                adb_baze();
                break;
            case 4:
                adb_sdcard();
                break;
            case 5:
                 kopiraj();
                 break;
            default:
                cout<<"Napacna izbira"<<endl;
            case 0:
                 cout<<"Izhod iz programa"<<endl;
            }
       }
       while(izbira!=0);
             
          
          system("pause");
    }
    
    
