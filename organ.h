class organ{
  private:
    string organname;
    int organquality;
    string donorname;
    organ *nextOrg;
    organ *prevOrg;
    int used;

  public:
    organ(string,int,string);
    string getorgan(){return organname;}
    int getquality(){return organquality;}
    string getdonorname(){return donorname;}
    void updateused(){used = 1;}
    void setnext(organ*);
    void setprev(organ*);
    organ* getnext(){return nextOrg;}
    organ* getprev(){return prevOrg;}
    ~organ();
};
typedef organ *OrgNode;

organ::organ(string in, int quality, string donor){
  organname = in;
  organquality = quality;
  donorname = donor;
  nextOrg = NULL;
  prevOrg = NULL;
  used = 0;
}

void organ::setnext(organ* t){
  nextOrg = t;
}

void organ::setprev(organ* t){
  prevOrg = t;
}

organ::~organ(){
  if(!used){
    cout<<"Deleting Organ: "<<organname<<" from system"<<endl;
  }else{
    cout<<"Organ : "<<organname<<"\nDonor name: "<<donorname<<"\nIs being transplanted"<<endl;
    sleep(5);
    system("clear");
  }
}

