#include <iostream>
using namespace std;
#include <string.h>
#include "patient.h"
#include "sorting.h"
#include <cstdlib>

void printingloop(patient *, int);
int modeselection(char*);
patient patientset();


int main(int argc, char **argv) {
  if (argc == 1){ cout<<"No mode selected\nENDING PROGRAM\n"; return 0;}
  int mode = modeselection(argv[1]);
  int patientnum;
  //optional/argv[1] for mode selection, for ascending and decending order, then argv[2] for number of patients inputting
  if (mode == 0) return 0;
  
  //start of program, user cin patient records in a while loop, exit condition type 0
  cout<<"Enter number of patient : "; cin>>patientnum;
  patient *now = (patient*) malloc(patientnum * sizeof(patient));
  for (int i =0; i<patientnum; i++){
    *(now+i) = patientset();
    //(now+i)->display(); //for debugging, already worked
  }
  
  
  //will create object, while creating, also call sorting to sort, use insertion sort

  //print patient from ascending or decending once entering name has been exited

  //freeing the array
  free(now);
}


void printingloop(patient *p, int n){
  for(int i = 0; i<n;i++){
    (p+i)->display();
  }
}

int modeselection(char* mode){

  if(strcmp(mode, "-a")==0){
    cout<<"Ascending mode selected"<<endl;
    return 1;
  }else if(strcmp(mode, "-d")== 0){
    cout<<"Decending mode selected"<<endl;
    return -1;
  }else{
    cout<<"Invalid mode selection, exiting program"<<endl;
    return 0;
  }
}

patient patientset(){
  string name, risk; int age; float mortality;
  cout<<"NAME : "; 
  cin>>name;
  cout<<"AGE : ";
  cin>>age;
  cout<<"RISK : ";
  cin>>risk;
  patient a(name, age, risk);
  return a;
}