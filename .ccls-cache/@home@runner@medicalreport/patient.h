#include<iomanip>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class patient{
  private:
    patient *nextPatient;
    patient *prevPatient;
    string name;
    int age;
    string risk;
    float risk_factor;
    float weight;
    float height;
    float BMI;
    int blood_pressure;
    int hemoglobin;
    int record;
    string organ;
  
  public:
    patient(string n = "Unnamed", int a = 0, string r = "Unknown" , float w  = 0.0, float h = 0.0, int p = 0, int g = 0, string o = "Unknown");
    void display();
    void update_risk_factor();
    void reduce_risk_factor();
    float riskfactor();
    int give_med();
    void updaterecorded();
    void updaterecorded(int x){record = x;}
    patient* getnext();
    patient* getprev();
    void setnext(patient*);
    void setprev(patient*);
    string getname(){return name;}
    string getorgan(){return organ;}
    patient* duplicate();
    string getrisk(){return risk;}
    ~patient();
  
};
typedef patient *NodePtr;

patient* patient::duplicate(){
  NodePtr returning = new patient(name, age, risk, weight, height, blood_pressure, hemoglobin, organ);
  record = 5;
  return returning;
}

patient* patient::getnext(){
  return nextPatient;
}
patient* patient::getprev(){
  return prevPatient;
}

void patient::setnext(patient* t){
  nextPatient = t;
}
void patient::setprev(patient* t){
  prevPatient = t;
}


patient::patient(string n, int a, string r, float w, float h, int p, int g, string o){
  name=n;
  age=a;
  risk=r;
  weight=w;
  height=h;
  blood_pressure=p;
  hemoglobin=g;
  organ=o;
  nextPatient = NULL;
  prevPatient = NULL;
  update_risk_factor();
}

void patient::display(){
  cout<<"Patient name: "<<name<<"\nAge: "<<age<<"\nAdditional Health Risk: "<<risk<<"\nRisk Factor: "<<risk_factor<<"\nOrgan needed: "<<organ<<endl;
  cout<<"========================================"<<endl;
}

void patient::update_risk_factor(){
  //for calculating risk_factor
  record = 1;
  BMI = weight/(height * height);

  risk_factor = 1.0;

  risk_factor+=(float(age) * 0.21);

  if (blood_pressure >= 140){
    risk_factor+=2.0;
    //cout<<"+2"<<endl;
  }

  if (hemoglobin < 10){
    risk_factor+=3.0;
    //cout<<"+3"<<endl;
  }

  if (BMI < 25.0){
    risk_factor+=0.0;
    //cout<<"+0"<<endl;
  } else if (BMI>=25.0 && BMI<=29.9){
    risk_factor+=3.0;
    //cout<<"+3"<<endl;
  } else {
    risk_factor+=4.0;
    //cout<<"+4"<<endl;
  }

}

void patient::reduce_risk_factor(){
  string r=risk;
  int med;
  
  transform(r.begin(), r.end(), r.begin(), ::tolower);//I don't think this work
  med = give_med();
  if(strcmp(r.c_str(),"heart")==0||strcmp(r.c_str(),"Heart")==0){
    
    if(med==1){
      risk_factor-=5.0;
    } else {
      risk_factor+=10.0;
    }
  } else if(strcmp(r.c_str(),"lungs")==0||strcmp(r.c_str(),"Lungs")==0){
    
    if(med==2){
      risk_factor-=5.0;
    } else {
      risk_factor+=10.0;
    }
  } else if(strcmp(r.c_str(),"kidneys")==0||strcmp(r.c_str(),"Kidneys")==0){
    
    if(med==3){
      risk_factor-=5.0;
    } else {
      risk_factor+=10.0;
    }
  } else if(strcmp(r.c_str(),"liver")==0||strcmp(r.c_str(),"Liver")==0){
    
    if(med==4){
      risk_factor-=5.0;
    } else {
      risk_factor+=10.0;
    }
  } else {
    cout<<"Medicine not needed, just rest"<<endl;
  }
}

int patient::give_med(){
  int i, again = 1;
  cout<<"Please Select the Medicine from the List below: \n";
  cout<<"1. Warfarin\n2. Azilsartan\n3. Theophylline\n4. Carbocisteine\n5. Azathioprine\n6. Prednisolone\n7. Ursodiol\n8. Propranolol\n";
  cin>>i;
  //Warfarin, Azilsartan fur das Herz
  //Theophylline, Carbocisteine fur die Lungen
  //Azathioprine, Prednisolone for the kidneys
  //Ursodiol, Propranolol for liver
  while (again){
    switch(i){
    case 1: 
    case 2: again=0; return 1;
      break;
    case 3: 
    case 4: again=0; return 2;
      break;
    case 5: 
    case 6: again=0; return 3;
      break;
    case 7: 
    case 8: again=0; return 4;
      break;
    default: cout<<"No such medicine, please select again."<<endl; again=1;
      break;
    }
  }
}

float patient::riskfactor(){
  return risk_factor;
}

void patient::updaterecorded(){
  record++;
}

patient::~patient(){
  if (record == 1){
    cout<<name<<" : recorded "<<"\n========================================"<<endl;
    sleep(1);
    system("clear");
  }else if (record == 4){
    cout<<"Patient risk factor has been updated"<<endl;
    sleep(1);
    system("clear");
  }else if (record == 5){
    sleep(1);
    system("clear");  
  }else{
    cout<<name<<" : record deleted"<<endl;
  }
}

