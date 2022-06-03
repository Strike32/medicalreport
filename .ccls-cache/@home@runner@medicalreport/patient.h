class patient{
  private:
    string name;
    int age;
    string risk;
    float mortality_rate;
  
  public:
    patient(string = "Unnamed", int = 0, string = "Unknown", float = 0);//default mortality to 0
    void display();
    void update_mortality();
    float mortality();
    ~patient(); //auto deletes already, doesn't have to include unless we wanna display something as the objects are being deleted
  
};

patient::patient(string n, int a, string r, float m){
  name=n;
  age=a;
  risk=r;
  mortality_rate=m;
}

void patient::display(){
  cout<<"Patient name: "<<name<<"\nAge: "<<age<<"\nRisk: "<<risk<<"\nMortality rate: "<<mortality_rate<<endl;
}

void patient::update_mortality(){
  //for calculating mortality
  


  //mortality_rate =
}

float patient::mortality(){
  return mortality_rate;
}

patient::~patient(){
  if (mortality_rate == 0){
  cout<<name<<" : recorded "<<"\n================"<<endl;
    }else{
    cout<<name<<" : patient record cleared"<<endl;
    }
}