   #include <direct.h>
   #include <iostream>
   #include <windows.h>
   using namespace std;

void stop()
{
 system("TASKKILL /F /IM Firefox.exe /T"); 
}

void start()
{
 system("C:/FirefoxOSforenzika/FirefoxPortable/FirefoxOS_forenzika.exe -no-remote file:///C:/FirefoxOSforenzika/index.html");
}

    int main()
    {     
          cout<<"Program za Forenziko Firefox OS"<<endl;   
          if (mkdir("C:/FirefoxOSforenzika/Datoteke") == mkdir("C:/FirefoxOSforenzika/Datoteke"))
          {
            cout<<"Pozdravljeni nazaj!"<<endl<<endl;
            cout<<"V mapo Datoteke kopirajte datoteke za analizo."<<endl;
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
          system("pause");
    }
    
    
