#include <iostream>
using namespace std;
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include "ll.h"
//#include "sorting.h" sorting already done in ll.h
#include "orgll.h"
#include <cstdlib>
int modeselection(char*);
string menu(int*,int*,LL*,int,OrgLL*);

int main(int argc, char **argv) {
  string target;
  int mainmenu,submenu;
  LL patientlist;
  OrgLL organlist;
  system("clear");
  if (argc == 1){ cout<<"No mode selected\nENDING PROGRAM\n"; return 0;}
  int mode = modeselection(argv[1]);
  if (mode == 0) return 0;
  while(mainmenu!= 5){
    target = menu(&mainmenu,&submenu,&patientlist,mode,&organlist);
    if(mainmenu == 5) break;
    switch(mode){
      case 1://does stuff by inserting;
        switch(mainmenu){
          case 1: patientlist.insert(); break;
          case 2: organlist.organqueue(); break;
          case 3: patientlist.deletes(target,2); break;
          case 4:
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
          case 2: organlist.organqueue(); break;
          case 3: patientlist.deletes(target,2); break;
          case 4:
            patientlist.print();
            break;
        }
        break;
    }
    organlist.checker(&patientlist);
  }
  //call destructor
  system("clear");
  cout<<"Exiting Program"<<endl<<"Thank you for using our system"<<endl;
  
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

string menu(int* mainmenu,int* submenu,LL* patientlist, int mode,OrgLL* organlist){
  string target;
  int choice;
  if(mode == 1){
    cout<<"Inserting Queue mode"<<endl;
  }else if (mode == -1){
    cout<<"Standard Queuing mode"<<endl;
  }
  if(organlist->isEmpty()==0){
    cout<<"Donor Organ in system:\n";
    organlist->printorg();
  }
  cout<<"Please select action"<<endl;
  cout<<"1.Add patient"<<endl;
  cout<<"2.Add donor organ"<<endl;
  cout<<"3.Discharge patient"<<endl;
  cout<<"4.Print current stored patient list"<<endl;
  cout<<"5.Stop program and delete record"<<endl;
  cin>>choice;
  *mainmenu = choice;
  *submenu = 0;
  
  if(*mainmenu == 4){
    cout<<"1.Printing Queue from first to last"<<endl;
    cout<<"2.Printing Queue from last to first"<<endl;
    cin>>choice;
    *submenu = choice;
  }else{
    *submenu = 1;
  }
  
  if(*mainmenu == 3&& patientlist->isEmpty()){
    cout<<"No patient in system"<<endl;
    cout<<"Please choose again"<<endl;
    sleep(2);
    system("clear");
    return menu(mainmenu,submenu,patientlist,mode,organlist);
  }
  
  if(*mainmenu == 3){
    cout<<"Patient to discharge (input name): ";
    cin>>target;
    return target;
  }else{
    return "0";
  }
  
}