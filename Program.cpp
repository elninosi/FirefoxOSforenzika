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
        <<"|  (1) Firefox OS: 1.0 - 1.2  |"<<endl
        <<"|  (2) Firefox OS: 1.3 - 2.2  |"<<endl
        <<"|  (3) Firefox OS: 2.2 - 2.5+ |"<<endl
        <<"-------------------------------"<<endl;
    cout<<"Izberi verzijo operacijskega sistema:"<<endl;
    cin>>os;
    cin.clear();
    cin.ignore(1000,'\n'); //clear buffer to prevent infinite loop
    
    if(os == 1)
    {
        string adbpull = string ("adb pull /data/local/indexedDB/ ");
        string lokacija = a+ string(":/FirefoxOSforenzika/adbPull/");
        string prevzem = adbpull+lokacija;
        system ( prevzem.c_str() );
    }
    
   else if(os == 2)
    {
        string adbpull = string ("adb pull /data/local/storage/persistent/ ");
        string lokacija = a+ string(":/FirefoxOSforenzika/adbPull/");
        string prevzem = adbpull+lokacija;
        system ( prevzem.c_str() );
    }
    
    else if(os == 3)
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
    
   else if (os == 2)
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
              if (mkdir("/FirefoxOSforenzika/Datoteke") == 0)
              {
                 cout<<"Mapa za vhodne podatke je bila izbrisana - ponovno kreiranje ... \n"<<endl;
                 mkdir("/FirefoxOSforenzika/Datoteke");
                 
              }              
              else
              {
               //cout<<"Mapa obstaja"<<endl;
              }
              
            if (mkdir("/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/") == 0)
            {
                cout<<"Datoteka 'file++++C++FirefoxOSforenzika+index.html' ne obstaja - ponovno kreiranje ... \n"<<endl;
                mkdir("/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb/");        
            }
            else 
            {   
                cout<<"Brisanje predhodnih datotek ... \n"<<endl;
                system("rmdir /s \\FirefoxOSforenzika\\FirefoxPortable\\Data\\profile\\storage\\default\\file++++C++FirefoxOSforenzika+index.html\\");
                cout<<"\n"<<endl;  
            }
          cout<<"V mapo 'Datoteke' kopirajte datoteke za analizo. \n"<<endl;  
          system("pause");                                                                                        
          cout<<"Zacetek kopiranja:"<<endl;
          
          char direktorij[255]; 
          getcwd(direktorij,255); 
          char a = direktorij[0];  
          
                                 string 
                                 source =a+ string(":/FirefoxOSforenzika/Datoteke"),
                                 destiny =a+ string(":/FirefoxOSforenzika/FirefoxPortable/Data/profile/storage/default/file++++C++FirefoxOSforenzika+index.html/idb");
                                 source = string("\"") + source + string("\"");
                                 destiny = string("\"") + destiny + string("\"");
                                 string command = string("xcopy") + string(" ") + source + string(" ") + destiny + string(" /s /i");
                                 system( command.c_str() );
          cout<<"Kopiranje koncano.\n"<<endl;
          cout<<"Odpiranje podatkov ...\n"<<endl;
          system("pause");                   
          start();      
}

void adb_backupData()
{
    start();
    //cout<<"ADB - Backup App Data"<<endl;
    
    char direktorij[255]; //polje
    getcwd(direktorij,255); 
    char a = direktorij[0];
    
    int os;
    cout<<"-------------------------------"<<endl
        <<"|  (1) Firefox OS: 1.0 - 2.1  |"<<endl
        <<"|  (2) Firefox OS: 2.2 - 2.5+ |"<<endl
        <<"-------------------------------"<<endl
        <<"|  (0) Nazaj na glavni meni   |"<<endl
        <<"-------------------------------"<<endl;
    cout<<"Izberi opcijo:"<<endl;
    cin>>os;
    
    if(os == 1)
    {
          string adbpull_contacts = string ("adb pull /mnt/sdcard/backup-contacts.html ");
          string lokacija_contacts = a+ string(":/FirefoxOSforenzika/BackupAppData");
          string prevzem_contacts = adbpull_contacts+lokacija_contacts; 
          system ( prevzem_contacts.c_str() );
          
          string adbpull_messages = string ("adb pull /mnt/sdcard/backup-messages.html ");
          string lokacija_messages = a+ string(":/FirefoxOSforenzika/BackupAppData");
          string prevzem_messages = adbpull_messages+lokacija_messages; 
          system ( prevzem_messages.c_str() );
          
          string adbpull_WIFI = string ("adb pull /mnt/sdcard/backup-WIFI.html ");
          string lokacija_WIFI = a+ string(":/FirefoxOSforenzika/BackupAppData");
          string prevzem_WIFI = adbpull_WIFI+lokacija_WIFI; 
          system ( prevzem_WIFI.c_str() );
          
          start();
          
          string shell_contacts ("adb shell");
          string ukaz_contacts (" rm /mnt/sdcard/backup-contacts.html ");
          string skupaj_contacts = shell_contacts+ukaz_contacts;
          system (skupaj_contacts.c_str());
          
          string shell_messages ("adb shell");
          string ukaz_messages (" rm /mnt/sdcard/backup-messages.html ");
          string skupaj_messages = shell_messages+ukaz_messages;
          system (skupaj_messages.c_str());
          
          string shell_WIFI ("adb shell");
          string ukaz_WIFI(" rm /mnt/sdcard/backup-WIFI.html ");
          string skupaj_WIFI = shell_messages+ukaz_WIFI;
          system (skupaj_WIFI.c_str());
    }
    else if (os == 2)
    {
          string adbpull_contacts = string ("adb pull /storage/sdcard0/backup-contacts.html ");
          string lokacija_contacts = a+ string(":/FirefoxOSforenzika/BackupAppData");
          string prevzem_contacts = adbpull_contacts+lokacija_contacts; 
          system ( prevzem_contacts.c_str() );
          
          string adbpull_messages = string ("adb pull /storage/sdcard0/backup-messages.html ");
          string lokacija_messages = a+ string(":/FirefoxOSforenzika/BackupAppData");
          string prevzem_messages = adbpull_messages+lokacija_messages; 
          system ( prevzem_messages.c_str() );
          
          string adbpull_WIFI = string ("adb pull /storage/sdcard0/backup-WIFI.html ");
          string lokacija_WIFI = a+ string(":/FirefoxOSforenzika/BackupAppData");
          string prevzem_WIFI = adbpull_WIFI+lokacija_WIFI; 
          system ( prevzem_WIFI.c_str() );
          
          start();
          
          string shell_contacts ("adb shell");
          string ukaz_contacts (" rm /storage/sdcard0/backup-contacts.html ");
          string skupaj_contacts = shell_contacts+ukaz_contacts;
          system (skupaj_contacts.c_str());
          
          string shell_messages ("adb shell");
          string ukaz_messages (" rm /storage/sdcard0/backup-messages.html ");
          string skupaj_messages = shell_messages+ukaz_messages;
          system (skupaj_messages.c_str());
          
          string shell_WIFI ("adb shell");
          string ukaz_WIFI(" rm /storage/sdcard0/backup-WIFI.html ");
          string skupaj_WIFI = shell_messages+ukaz_WIFI;
          system (skupaj_WIFI.c_str());
    }
    else if (os == 0)
    {
         //cout<<"Vracanje na glavni meni"<<endl;
    }
    else 
    {
     cout<<"Nepravilen vnos."<<endl; 
    }
   system ("pause");     
}

int main()
{     
          int izbira;
          cout<<"Program za Forenziko - Firefox OS"<<endl;
      do
       {
           cout<<"---------------------------------------"<<endl
               <<"|  (1) Pridobi pravice                |"<<endl
               <<"|  (2) Preglej naprave                |"<<endl
               <<"|  (3) Prenesi baze iz naprave        |"<<endl
               <<"|  (4) Prenesi datoteke iz naprave    |"<<endl
               <<"|  (5) Preglej baze                   |"<<endl
               <<"|  (6) Odpri pregledovalnik Firefox   |"<<endl
               <<"|-------------------------------------|"<<endl
               <<"|  (0) Izhod iz programa              |"<<endl
               <<"---------------------------------------"<<endl;
           
           cout<<"Vnesi izbiro: ";
           cin>>izbira;         
           cout<<"\n";
           cin.clear();
           cin.ignore(1000,'\n'); //clear buffer to prevent infinite loop
                     
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
             case 6:
                 adb_backupData();
                 break;
            default:  
                cout<<"Neveljavna izbira. \n"<<endl;
            case 0:
                 cout<<"Izhod iz programa"<<endl;
            }
       }
        while(izbira!=0);
           
       system("pause");
       return 0;
}
    
    
