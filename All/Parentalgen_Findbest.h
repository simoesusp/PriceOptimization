void ParentalGeneration(float ****FullListAd, float **FitnessAd,float ****FullList2Ad, float **Fitness2Ad, float ***BaseStructure, int *CardsStudied,int realcards,int manysites,int manyparentals,int manycards){
    int *provisoryArray;
    int *Shipps=calloc((manycards),sizeof(int));
    int therand,position,addable,summer,definer;

    *FullListAd=malloc((manyparentals)*sizeof(float**));
    *FitnessAd=calloc(manyparentals,sizeof(float));
    *FullList2Ad=malloc((manyparentals)*sizeof(float**));
    *Fitness2Ad=calloc(manyparentals,sizeof(float));

    srand(time(NULL));

    for(int i=0;i<manyparentals;i++){
        (*FullListAd)[i]=malloc(manycards*sizeof(float*));
        (*FullList2Ad)[i]=malloc(manycards*sizeof(float*));
        for(int j=0;j<manycards;j++){
            (*FullListAd)[i][j]=calloc(2,sizeof(float));
            (*FullList2Ad)[i][j]=calloc(2,sizeof(float));
        }
    }

    for(int m=0;m<manyparentals;m++){
        (*FitnessAd)[m]=0;
        summer=0;
        position=-1;
        definer=1;
        for(int i=0;i<manycards;i++){
            Shipps[i]=-1;
        }


        for(int n=0;n<realcards;n++){
            provisoryArray=calloc(CardsStudied[n],sizeof(int));
            for(int o=0;o<CardsStudied[n];o++){
                position+=1;
                therand=rand()%(manysites);
                provisoryArray[o]=therand;
                (*FullListAd)[m][position][0]=(float)(therand);
                addable=0;
                
                for(int q=0;q<o;q++){
                    if(provisoryArray[q]==therand){
                        addable+=1;
                    }
                }

                for(int q=0;q<summer;q++){
                    if(Shipps[q]==therand){
                        definer=0;
                        break;
                    }
                }

                if(definer){
                    Shipps[summer]=therand;
                    summer+=1;
                }
                definer=1;

                if(BaseStructure[(int)(therand)][n][addable]==(float)(1000000)){
                    (*FullListAd)[m][position][1]=(float)(1000000);
                    (*FitnessAd)[m]+=(float)(1000000);  
                }
                else{
                    (*FullListAd)[m][position][1]=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                    (*FitnessAd)[m]+=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                }
                
            }
            free(provisoryArray);
        }
        for(int i=0;i<summer;i++){
            (*FitnessAd)[m]+=BaseStructure[(Shipps[i])][realcards][0];
        }
    }
    free(Shipps);
}

void FindBest(float *Fitness,float ***FullList,int manyparentals,int manycards){
    int min=0;
    float Provisory=0;

    for(int i=1;i<manyparentals;i++){
        if(Fitness[i]<=Fitness[min]){
            min=i;
        }
    }

    for(int i=0;i<manycards;i++){
        Provisory=FullList[0][i][0];
        FullList[0][i][0]=FullList[min][i][0];
        FullList[min][i][0]=Provisory;

        Provisory=FullList[0][i][1];
        FullList[0][i][1]=FullList[min][i][1];
        FullList[min][i][1]=Provisory;
    }

    Provisory=Fitness[0];
    Fitness[0]=Fitness[min];
    Fitness[min]=Provisory;
}