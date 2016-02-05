   #include <direct.h>
   #include <iostream>
   #include <windows.h>
   using namespace std;

void start()
{
     char direktorij[255]; 
     getcwd(direktorij,255); 
     char a = direktorij[0];  
    
          string firefox =a+ string (":/FirefoxOSforenzika/FirefoxPortable/FirefoxOS_forenzika.exe -no-remote file:///");
          string stran =a+ string (":/FirefoxOSforenzika/index.html");
          string zagon = firefox+stran; 
          system ( zagon.c_str() );  
             
 //system("C:/FirefoxOSforenzika/FirefoxPortable/FirefoxOS_forenzika.exe -no-remote file:///C:/FirefoxOSforenzika/index.html");
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
    
    //system("adb devices"); // pokaži vse naprave

   system ("pause");     
}

void kopiraj()
{

              if (mkdir("/FirefoxOSforenzika1/Datoteke") == 0)
              {
                 cout<<"Mapa za vhodne podatke je bila izbrisana - ponovno kreiranje ... \n"<<endl;
                 mkdir("/FirefoxOSforenzika1/Datoteke");
                 cout<<"V mapo 'Datoteke' kopirajte datoteke za analizo."<<endl;
              }              
              else
              {
               cout<<"Mapa obstaja"<<endl;
              }
              
              system("pause");
         // }
         
            if (mkdir("/FirefoxOSforenzika1/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/") == 0)
            {
                cout<<"Datoteka 'file++++C++FirefoxOSforenzika+index.html' ne obstaja - ponovno kreiranje ... \n"<<endl;
                mkdir("/FirefoxOSforenzika1/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb/");        
            }
                                                                                                    
          cout<<"Zacetek kopiranja:"<<endl;
          
          char direktorij[255]; 
          getcwd(direktorij,255); 
          char a = direktorij[0];  
          
                                 string 
                                 source =a+ string(":/FirefoxOSforenzika1/Datoteke"),
                                 destiny =a+ string(":/FirefoxOSforenzika1/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb");
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
                cout<<"Neveljavna izbira"<<endl;
            case 0:
                 cout<<"Izhod iz programa"<<endl;
            }
       }
       while(izbira!=0);
               
       system("pause");
}
    
    
