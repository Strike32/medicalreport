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
    ~OrgLL();
};

OrgLL::OrgLL(){
  orghead = NULL;
  orgtail = NULL;
  orgsize = 0;
}

void OrgLL::checker(LL *patientlist){
  int hit = 0;
  OrgNode t = orghead;

  for (int i = 0; i<orgsize; i++){
    hit = organhit(t,patientlist);
    if(hit == 1){
      t->updateused();
      if(orgsize != 1){
        OrgNode prev = t->getprev();
        OrgNode next = t->getnext();
        prev->setnext(next);
        next->setprev(prev);
      }else{
        orghead = NULL;
        orgtail = NULL;
      }
      delete t;
      orgsize--;
      break;
    }else{
      t = t->getnext();
    }
  }
}


void OrgLL::organqueue(){
  string organname;string donor;
  int quality;
  cout<<"Organ name: "<<endl;
  cin>>organname;
  cout<<"Donor name: "<<endl;
  cin>>donor;
  cout<<"Organ quality: "<<endl;
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
  printorg();
}

int OrgLL::organhit(OrgNode t, LL *patientlist){
  int hit = 0;
  hit = patientlist->foundorgan(t->getorgan());

  return hit;
}


void OrgLL::printorg(){
  OrgNode t = orghead;
  for (int i = 0; i<orgsize; i++){
    cout<<"Organ : "<<t->getorgan()<<"\nDonor : "<<t->getdonorname()<<"\nQuality : "<<t->getquality()<<endl;
    t = t->getnext();
  }
}

OrgLL::~OrgLL(){
  OrgNode t = orghead;
  cout<<"Deleting donated Organ list"<<endl;
  cout<<"==========================="<<endl;
  for(int i = 0; i<orgsize; i++){
    orghead = orghead->getnext();
    delete t;
    t = orghead;
  }
  cout<<"==========================="<<endl;
}