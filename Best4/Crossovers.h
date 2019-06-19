void BasicCrossover(float ***BaseStructure, float ****FullListAd, float **FitnessAd, float ****FullList2Ad, float **Fitness2Ad, int *CardsStudied,int realcards,int manysites,int manyparentals,int manycards){
    int *provisoryArray=NULL;
    float ***TheSwapFL=NULL;
    float *TheSwapFit=NULL;
    int *Shipps=calloc((manycards),sizeof(int));
    int therand,position,addable,summer,definer;

    for(int i=0;i<manycards;i++){
        (*FullList2Ad)[0][i][0]=(*FullListAd)[0][i][0];
        (*FullList2Ad)[0][i][1]=(*FullListAd)[0][i][1];
    }
    (*Fitness2Ad)[0]=(*FitnessAd)[0];

    for(int m=1;m<manyparentals;m++){
        (*Fitness2Ad)[m]=0;
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

                therand=rand()%2;
                if(therand){
                    therand=(*FullListAd)[m][position][0];
                }
                else{
                    therand=(*FullListAd)[0][position][0];
                }

                provisoryArray[o]=therand;
                (*FullList2Ad)[m][position][0]=(float)(therand);
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
                    (*FullList2Ad)[m][position][1]=(float)(1000000);
                    (*Fitness2Ad)[m]+=(float)(1000000);  
                }
                else{
                    (*FullList2Ad)[m][position][1]=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                    (*Fitness2Ad)[m]+=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                }
            }
            free(provisoryArray);
        }
        for(int i=0;i<summer;i++){
            (*Fitness2Ad)[m]+=BaseStructure[(Shipps[i])][realcards][0];
        }
    }
    free(Shipps);


    TheSwapFL=(*FullList2Ad);
    (*FullList2Ad)=(*FullListAd);
    (*FullListAd)=TheSwapFL;


    TheSwapFit=(*Fitness2Ad);
    (*Fitness2Ad)=(*FitnessAd);
    (*FitnessAd)=TheSwapFit;
}

void TournmentOfTwo(float ***BaseStructure, float ****FullListAd, float **FitnessAd, float ****FullList2Ad, float **Fitness2Ad, int *CardsStudied,int realcards,int manysites,int manyparentals,int manycards){
    int *provisoryArray=NULL;
    float ***TheSwapFL=NULL;
    float *TheSwapFit=NULL;
    int *Shipps=calloc((manycards),sizeof(int));
    int competitors[2];
    int therand,position,addable,summer,definer,competitor,competitor2;

    for(int i=0;i<manycards;i++){
        (*FullList2Ad)[0][i][0]=(*FullListAd)[0][i][0];
        (*FullList2Ad)[0][i][1]=(*FullListAd)[0][i][1];
    }
    (*Fitness2Ad)[0]=(*FitnessAd)[0];

    for(int m=1;m<manyparentals;m++){
        (*Fitness2Ad)[m]=0;
        summer=0;
        position=-1;
        definer=1;
        for(int i=0;i<manycards;i++){
            Shipps[i]=-1;
        }

        for(int i=0;i<2;i++){
            competitor=rand()%(manyparentals);
            competitor2=rand()%(manyparentals);
            if((*FitnessAd)[competitor2]<=(*FitnessAd)[competitor]){
                competitor=competitor2;
            }
            competitors[i]=competitor;
        }

        for(int n=0;n<realcards;n++){
            provisoryArray=calloc(CardsStudied[n],sizeof(int));
            for(int o=0;o<CardsStudied[n];o++){
                position+=1;

                therand=rand()%2;
                if(therand){
                    therand=(*FullListAd)[(competitors[1])][position][0];
                }
                else{
                    therand=(*FullListAd)[(competitors[0])][position][0];
                }

                provisoryArray[o]=therand;
                (*FullList2Ad)[m][position][0]=(float)(therand);
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
                    (*FullList2Ad)[m][position][1]=(float)(1000000);
                    (*Fitness2Ad)[m]+=(float)(1000000);  
                }
                else{
                    (*FullList2Ad)[m][position][1]=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                    (*Fitness2Ad)[m]+=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                }
            }
            free(provisoryArray);
        }
        for(int i=0;i<summer;i++){
            (*Fitness2Ad)[m]+=BaseStructure[(Shipps[i])][realcards][0];
        }
    }
    free(Shipps);

    TheSwapFL=(*FullList2Ad);
    (*FullList2Ad)=(*FullListAd);
    (*FullListAd)=TheSwapFL;

    TheSwapFit=(*Fitness2Ad);
    (*Fitness2Ad)=(*FitnessAd);
    (*FitnessAd)=TheSwapFit;
}