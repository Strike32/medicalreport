#include "patient.h"

#include <string.h>
class LL{
  private:
    NodePtr head, tail;
    int size;
  public:
    LL();
    void deletes(string,int);
    int isEmpty();
    void insert();
    void queue();
    void print();
    void printR();
    inline void returningscreen();
    inline void returningscreen(int);
    int foundorgan(string);
//print and printR
    ~LL();
    
};

LL::LL(){
  head = NULL; tail = NULL;
  size = 0;
}

int LL::foundorgan(string in){
  int hit = 0;
  string patientname;
  NodePtr t = head;
  for(int i =0; i<size; i++){
    patientname = t->getname();
    if(strcmp(t->getorgan().c_str(), in.c_str())==0){
      hit = 1;
      cout<<"Donor organ found"<<"\nDischarging patient from list : "<<t->getname()<<endl;
      deletes(patientname, 0);
      return hit;
    }else{
      t = t->getnext();
    }
  }
  return hit;
}


inline void LL::returningscreen(){
  cout<<"Task successful"<<endl;
  cout<<"Returning to main menu"<<endl;
  sleep(2);
  system("clear");
}

inline void LL::returningscreen(int in){
  cout<<"Task successful"<<endl;
  cout<<"Returning to main menu"<<endl;
  sleep(in);
  if(in != 0){
    system("clear");
  }
}

void LL::deletes(string name, int sleeper){
  //find target patient, delete from linked list
  string tarname;
  NodePtr target, find, afterTar,beforeTar;
  find = head;
  int found = 0;
  for (int i = 0; i<size;i++){
    string findName = find->getname();
    if(strcmp(findName.c_str(),name.c_str())== 0){
      target = find;
      tarname = target->getname();
      beforeTar = target->getprev();
      afterTar = target->getnext();
      found = 1;
      break;
    }
    find = find->getnext();
  }
  if(found){
    cout<<"Deleting "<<tarname<<" from list"<<endl;
    target->updaterecorded();
    if(target == head){
      head = head->getnext();
      delete target;
      size --;
      returningscreen(sleeper);
      return;
    }
    if(target == tail){
      tail = tail->getprev();
      delete target;
      size --;
      returningscreen(sleeper);
      return;
    }
      beforeTar->setnext(afterTar);
      afterTar->setprev(beforeTar);     
    delete target;
    size --;
    returningscreen(sleeper);
    return;//hit
  }else{
    cout<<"Patient not found in list"<<endl;
    returningscreen(sleeper);
    return;//doesn't hit
  }
}

int LL::isEmpty(){
  return head == NULL;
}

void LL::insert(){
  //insert patient, makes a new patient class here to set insertion
  string name, risk;
  int age, blood_pressure, hemoglobin;
  float mortality, weight, height;
  string organ;
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
  cout<<"ORGAN NEEDED : ";
  cin>>organ;
  returningscreen();
  
  NodePtr newPtr = new patient(name,age,risk,weight,height,blood_pressure,hemoglobin,organ);
  NodePtr prevPtr;
  NodePtr currPtr;

  
  if(newPtr!=NULL){
    prevPtr = NULL;
    currPtr = head;

    while(currPtr != NULL && newPtr->riskfactor() < currPtr->riskfactor()){
      //insert from most severe to least severe
      prevPtr = currPtr;
      currPtr = currPtr->getnext();
    }
    
    if(prevPtr == NULL){
      newPtr->setnext(head);
      head = newPtr;
      
    }else{
      prevPtr->setnext(newPtr);
      newPtr->setnext(currPtr);
      newPtr->setprev(prevPtr);//for some reason this doesn't work, newPtr prevPatient kept being unlinked
    }
    
    if(currPtr == NULL){
      tail = newPtr;
    }
    if(currPtr != NULL){
      currPtr->setprev(newPtr);
    }

    size++;
  }else{
    cout<<name<<" :patient not inserted\nSYSTEM MEMORY FULL"<<endl;
  }
}

void LL::queue(){
  //from mode select in main, if queue, no insertion, just normal linking
  string name, risk;
  int age, blood_pressure, hemoglobin;
  float mortality, weight, height;
  string organ;
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
  cout<<"ORGAN NEEDED : ";
  cin>>organ;
  returningscreen();

  NodePtr last = tail;
  NodePtr newPtr = new patient(name,age,risk,weight,height,blood_pressure,hemoglobin,organ);
  if(size == 0){
    head = newPtr;
    tail = head;
  }else{
    last->setnext(newPtr);
    tail = last->getnext();
  }
  size++;
}

void LL::print(){
  if(isEmpty()){
    cout<<"Record empty"<<endl;
    returningscreen();
    return;
  }
  NodePtr t = head;
  for(int i = 0; i<size;i++){
    t->display();
    t = t->getnext();
  }
}

void LL::printR(){
  if(isEmpty()){
    cout<<"Record empty"<<endl;
    returningscreen();
    return;
  }
  NodePtr t = tail;
  for (int i = 0; i<size;i++){
    t->display();
    t = t->getprev();
  }
}

LL::~LL(){
  int call = 0;
  if(!isEmpty()){
    cout<<"Patient left untreated: "<<size<<endl;
    cout<<"Deleting Patient list"<<endl;
    cout<<"====================="<<endl;
    call = 1;
  }else{
    c
  }
  NodePtr t = head;
  for(int i = 0; i<size;i++){
    head = head->getnext();
    t->updaterecorded();
    delete t;
    t = head;
  }
  if(call){

    cout<<"====================="<<endl;
  }
}