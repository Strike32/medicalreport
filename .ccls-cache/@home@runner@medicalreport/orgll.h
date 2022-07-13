#include "organ.h"

class OrgLL{
  private:
    OrgNode orghead,orgtail;
    int orgsize;
  public:
    OrgLL();
    void organqueue();
    void printorg();
    int organhit(OrgNode,LL*);
    void checker(LL*);
    inline void returningscreen();
    int isEmpty(){if(orgsize== 0){return 1;}else{return 0;}}
    ~OrgLL();
};

OrgLL::OrgLL(){
  orghead = NULL;
  orgtail = NULL;
  orgsize = 0;
}
inline void OrgLL::returningscreen(){
  cout<<"Task successful"<<endl;
  cout<<"Returning to main menu"<<endl;
  sleep(2);
  system("clear");
}

void OrgLL::checker(LL *patientlist){
  int hit = 0;
  OrgNode t = orghead;

  for (int i = 0; i<orgsize; i++){
    hit = organhit(t,patientlist);
    if(hit == 1){
      break;
    }else{
      t = t->getnext();
    }
  }
  if(hit){
    t->updateused();
    if(t!= orghead&&t!= orgtail){
      OrgNode prev = t->getprev();
      OrgNode next = t->getnext();
      prev->setnext(next);
      next->setprev(prev);
    }else if(t == orghead&&orgsize != 1){
      orghead = orghead->getnext();
    }else if(t == orgtail&&orgsize != 1){
      orgtail = orgtail->getprev();
    }else{
      orghead = NULL;
      orgtail = NULL;
    }
    //cout<<"reached here"<<endl;
    delete t;
    orgsize--;
  }
}


void OrgLL::organqueue(){
  string organname;string donor;
  int quality;
  cout<<"Organ name: ";
  cin>>organname;
  cout<<"Donor name: ";
  cin>>donor;
  cout<<"Organ quality: ";
  cin>>quality;
  OrgNode newin = new organ(organname,quality,donor);
  if(orgsize == 0){
    orghead = newin;
    orgtail = orghead;
  }else{
    orgtail->setnext(newin);
    newin->setprev(orgtail);
    orgtail = newin;
  }
  orgsize++;
  returningscreen();
  //printorg();
}

int OrgLL::organhit(OrgNode t, LL *patientlist){
  int hit = 0;
  hit = patientlist->foundorgan(t->getorgan());

  return hit;
}


void OrgLL::printorg(){
  OrgNode t = orghead;
  cout<<"==========================="<<endl;
  for (int i = 0; i<orgsize; i++){
    cout<<"Organ : "<<t->getorgan()<<"\nDonor : "<<t->getdonorname()<<"\nQuality : "<<t->getquality()<<endl;
    cout<<"==========================="<<endl;
    t = t->getnext();
  }
  cout<<"==========================="<<endl;
}

OrgLL::~OrgLL(){
  int call = 0;
  OrgNode t = orghead;
  if(orgsize != 0){
    cout<<"Organ left unused : "<<orgsize<<endl;
    cout<<"Deleting donated Organ list"<<endl;
    cout<<"==========================="<<endl;
    call = 1;
  }
  for(int i = 0; i<orgsize; i++){
    orghead = orghead->getnext();
    delete t;
    t = orghead;
  }
  if(call){
    cout<<"==========================="<<endl;
  }
}