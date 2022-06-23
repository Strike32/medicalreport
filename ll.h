#include "patient.h"

class LL{
  private:
    NodePtr head, tail;
    int size;
  public:
    LL();
    void deletes(string name);
    int isEmpty();
    void insert();
    void queue();
    void print();
    void printR();
//print and printR
    ~LL();
    
};

LL::LL(){
  head = NULL;
  size = 0;
}

void LL::deletes(string name){
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
      return;
    }
    if(target == tail){
      tail = tail->getprev();
      delete target;
      size --;
      return;
    }
      beforeTar->setnext(afterTar);
      afterTar->setprev(beforeTar);     
    delete target;
    size --;
    return;//hit
  }else{
    cout<<"Patient not found in list"<<endl;
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
  sleep(2);
  system("clear");
  
  NodePtr newPtr = new patient(name,age,risk,weight,height,blood_pressure,hemoglobin);
  NodePtr prevPtr;
  NodePtr currPtr;

  
  if(newPtr!=NULL){
    prevPtr = NULL;
    currPtr = head;

    while(currPtr != NULL && newPtr->riskfactor() > currPtr->riskfactor()){
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

  NodePtr last = head;
  NodePtr newPtr = new patient(name,age,risk,weight,height,blood_pressure,hemoglobin);
  if(size == 0){
    head = newPtr;
    tail = head;
  }else{
    for(int i =0; i<size;i++){
      if(last->getnext()== NULL){
        break;
      }
      last = last->getnext();
    }
    last->setnext(newPtr);
    tail = last->getnext();
  }
  size++;
}

void LL::print(){
  if(isEmpty()) return;
  NodePtr t = head;
  for(int i = 0; i<size;i++){
    t->display();
    t = t->getnext();
  }
}

void LL::printR(){
  if(isEmpty()) return;
  NodePtr t = tail;
  for (int i = 0; i<size;i++){
    t->display();
    t = t->getprev();
  }
}

LL::~LL(){
  cout<<"Deleting Patient list"<<endl;
  NodePtr t = head;
  for(int i = 0; i<size;i++){
    head = head->getnext();
    t->updaterecorded();
    delete t;
    t = head;
  }
  cout<<"======================================="<<endl;
}