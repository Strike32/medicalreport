//no need to include patient.h here, already included in main sort patient by risk_factor, to get risk_factor object.riskfactor() or pointer->riskfactor()\

//use insertion sort

void insertionSortASC(patient *p,int n){
  int i,j;
  patient *temp = (patient*) malloc(sizeof(patient));
  for (i = 1; i < n; i++){
      *temp = *(p+i);  
      j = i - 1;
      while (j >= 0 && (p+j)->riskfactor() > temp->riskfactor()){  
          *(p+j+1) = *(p+j);  
          j = j - 1;      
      }
      *(p+j+1) = *temp;      
  }
  free(temp);
}
void insertionSortDEC(patient *p,int n){
  int i,j;
  patient *temp = (patient*) malloc(sizeof(patient));
  for (i = 1; i < n; i++){
      *temp = *(p+i);
      j = i - 1;
      while (j >= 0 && (p+j)->riskfactor() < temp->riskfactor()){
          *(p+j+1) = *(p+j);
          j = j - 1;
      }
      *(p+j+1) = *temp;
  }
  free(temp);
}

