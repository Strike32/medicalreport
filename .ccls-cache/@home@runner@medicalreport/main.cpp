                                                                
                                //no longer in use
/*
#include <iostream>
using namespace std;
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "sorting.h"
#include <cstdlib>


void printingloop(patient *, int);
int modeselection(char*);
patient patientset();


int main(int argc, char **argv) {
  system("clear");
  if (argc == 1){ cout<<"No mode selected\nENDING PROGRAM\n"; return 0;}
  int mode = modeselection(argv[1]);
  int patientnum;
  //optional/argv[1] for mode selection, for ascending and descending order, then argv[2] for number of patients inputting
  if (mode == 0) return 0;
  
  //start of program, user cin patient records in a while loop, exit condition type 0
  cout<<"Enter number of patient : "; cin>>patientnum;
  patient *now = (patient*) malloc(patientnum * sizeof(patient));
  for (int i =0; i<patientnum; i++){
    *(now+i) = patientset();
    (now+i)->updaterecorded();
    //(now+i)->display(); //for debugging, already worked
  }
  if(mode==1){
    insertionSortASC(now,patientnum);
  }else{
    insertionSortDEC(now,patientnum);
  }
  if(mode == 1){
    cout<<"Ordering Patient Survivability in ascending order accoding to Risk Factor : "<<endl;
  }else{
    cout<<"Ordering Patient Survivability in descending order according to Risk Factor : "<<endl;
  }
  cout<<"========================================"<<endl;
  printingloop(now,patientnum);
  //printingloop(now,patientnum); //for debugging
  

  //freeing the array
  free(now);
  
}


void printingloop(patient *p, int n){
  for(int i = 0; i<n;i++){
    (p+i)->display();
    (p+i)->updaterecorded();
  }
}

int modeselection(char* mode){

  if(strcmp(mode, "-a")==0){
    cout<<"Ascending mode selected"<<endl;
    return 1;
  }else if(strcmp(mode, "-d")== 0){
    cout<<"Descending mode selected"<<endl;
    return -1;
  }else{
    cout<<"Invalid mode selection, exiting program"<<endl;
    return 0;
  }
}

patient patientset(){
  string name, risk; int age, blood_pressure, hemoglobin; float mortality, weight, height;
  cout<<"NAME : "; 
  cin>>name;
  cout<<"AGE : ";
  cin>>age;
  cout<<"HEALTH CONCERS (Type none if none) : ";
  cin>>risk;
  cout<<"WEIGHT (kilogram) : "; 
  cin>>weight;
  cout<<"HEIGHT (metre) : ";
  cin>>height;
  cout<<"BLOOD PRESSURE : ";
  cin>>blood_pressure;
  cout<<"HEMOGLOBIN : ";
  cin>>hemoglobin;
  system("clear");
  patient a(name, age, risk, weight, height, blood_pressure, hemoglobin);
  return a;
}
*/