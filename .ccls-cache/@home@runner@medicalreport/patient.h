class patient{
  private:
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
    patient(string = "Unnamed", int = 0, string = "Unknown", float = 0, float = 0, float = 0, float = 0, int = 0, int = 0);//default mortality to 0
    void display();
    void update_risk_factor();
    float riskfactor();
    ~patient(); //auto deletes already, doesn't have to include unless we wanna display something as the objects are being deleted
  
};

patient::patient(string n, int a, string r, float f, float w, float h, float b, int p, int g){
  name=n;
  age=a;
  risk=r;
  risk_factor=f;
  weight=w;
  height=h;
  BMI=b;
  blood_pressure=p;
  hemoglobin=g;
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

  if (blood_pressure > 140){
    risk_factor+=2.0;
  }

  if (hemoglobin < 10){
    risk_factor+=3.0;
  }

  if (BMI>=25.0 && BMI<=29.9){
    risk_factor+=2.0;
  } 
  else if (BMI > 29.9){
    risk_factor+=3.0;
  }


}

float patient::riskfactor(){
  return risk_factor;
}

patient::~patient(){
  if (record == 1){
    cout<<name<<" : recorded "<<"\n========================================"<<endl;
  }else {
    cout<<name<<" : patient record cleared"<<endl;
  }
  sleep(1);
  system("clear");
}