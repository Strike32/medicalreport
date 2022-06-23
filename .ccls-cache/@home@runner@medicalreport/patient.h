#include <iomanip>
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
    
  
  public:
    patient(string n = "Unnamed", int a = 0, string r = "Unknown" , float w  = 0.0, float h = 0.0, int p = 0, int g = 0);
    void display();
    void update_risk_factor();
    float riskfactor();
    void updaterecorded();
    patient* getnext();
    patient* getprev();
    void setnext(patient*);
    void setprev(patient*);
    string getname(){return name;}
    ~patient();
  
};
typedef patient *NodePtr;

patient* patient::getnext(){
  return nextPatient;
}
patient* patient::getprev(){
  return nextPatient;
}

void patient::setnext(patient* t){
  nextPatient = t;
}
void patient::setprev(patient* t){
  prevPatient = t;
}


patient::patient(string n, int a, string r, float w, float h, int p, int g){
  name=n;
  age=a;
  risk=r;
  weight=w;
  height=h;
  blood_pressure=p;
  hemoglobin=g;
  nextPatient = NULL;
  prevPatient = NULL;
  update_risk_factor();
}

void patient::display(){
  cout<<"Patient name: "<<name<<"\nAge: "<<age<<"\nAdditional Health Risk: "<<risk<<"\nRisk Factor: "<<risk_factor<<endl;
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
  }else{
    cout<<name<<" : record deleted"<<endl;
  }
}