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
