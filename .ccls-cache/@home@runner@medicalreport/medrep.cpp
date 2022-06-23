#include <iostream>
using namespace std;
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include "ll.h"
#include "sorting.h"
#include <cstdlib>

int modeselection(char*);
string menu(int*,int*,LL*,int);

int main(int argc, char **argv) {
  string target;
  int mainmenu,submenu;
  LL patientlist;
  system("clear");
  if (argc == 1){ cout<<"No mode selected\nENDING PROGRAM\n"; return 0;}
  int mode = modeselection(argv[1]);
  if (mode == 0) return 0;
  while(mainmenu!= 4){
    target = menu(&mainmenu,&submenu,&patientlist,mode);
    if(mainmenu == 4) break;
    switch(mode){
      case 1://does stuff by inserting;
        switch(mainmenu){
          case 1: patientlist.insert(); break;
          case 2: patientlist.deletes(target); break;
          case 3:
            if(submenu == 1){
              patientlist.print();
            }else{
              patientlist.printR();
            }break;
        }
        break;
      case -1://does stuff in queue;
        switch(mainmenu){
          case 1: patientlist.queue(); break;
          case 2: patientlist.deletes(target); break;
          case 3:
            patientlist.print();
            break;
        }
        break;
    }
  }
  //call destructor
  cout<<"Exiting Program"<<endl<<"Thank you for using"<<endl;
  
}

int modeselection(char* mode){

  if(strcmp(mode, "-i")==0){
    cout<<"Inserting mode selected"<<endl;
    return 1;
  }else if(strcmp(mode, "-q")== 0){
    cout<<"Standard Queuing mode selected"<<endl;
    return -1;
  }else{
    cout<<"Invalid mode selection, exiting program"<<endl;
    return 0;
  }
}

string menu(int* mainmenu,int* submenu,LL* patientlist, int mode){
  string target;
  int choice;
  cout<<"Please select action"<<endl;
  cout<<"1.Add patient"<<endl;
  cout<<"2.Delete patient"<<endl;
  cout<<"3.Print current stored patient list"<<endl;
  cout<<"4.Stop program and delete record"<<endl;
  cin>>choice;
  *mainmenu = choice;
  *submenu = 0;
  if(*mainmenu == 3&&mode == 1){
    cout<<"1.Printing in Ascending risk order"<<endl;
    cout<<"2.Printing in Descending risk order"<<endl;
    cin>>choice;
    *submenu = choice;
  }else{
    *submenu = 1;
  }
  if(*mainmenu == 2&& patientlist->isEmpty()){
    cout<<"No patient in system"<<endl;
    cout<<"Please choose again"<<endl;
    system("clear");
    return menu(mainmenu,submenu,patientlist,mode);
  }   
  if(*mainmenu == 2){
    cout<<"Patient to delete (input name): ";
    cin>>target;
    return target;
  }else{
    return "0";
  }
  
  
  
  
}