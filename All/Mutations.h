void BasicMutation(float ***BaseStructure, float ***FullList, float *Fitness, int *CardsStudied,int realcards,int manysites,int manyparentals,int manycards, int mutvar){
    int *provisoryArray;
    int *Shipps=calloc((manycards),sizeof(int));
    int therand,position,addable,summer,definer,randcromossome,provisorysite;
    int *MutVector=calloc(manycards,sizeof(int));
    srand(time(NULL));

    for(int i=0;i<manycards;i++){
        MutVector[i]=-1;
    }

    randcromossome=(rand()%(manyparentals-1))+1;
    for(int i=0;i<mutvar;i++){
        provisorysite=rand()%(manycards);
        if(MutVector[provisorysite]==-1){
            MutVector[provisorysite]=rand()%(manysites);
        }
    }
    Fitness[randcromossome]=0;
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

            if(MutVector[position]>=0){
                therand=MutVector[position];
            }
            else{
                therand=FullList[randcromossome][position][0];
            }

            provisoryArray[o]=therand;
            FullList[randcromossome][position][0]=(float)(therand);
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
                FullList[randcromossome][position][1]=(float)(1000000);
                Fitness[randcromossome]+=(float)(1000000);  
            }
            else{
                FullList[randcromossome][position][1]=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                Fitness[randcromossome]+=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
            }
        }
        free(provisoryArray);
    }

    for(int i=0;i<summer;i++){
        Fitness[randcromossome]+=BaseStructure[(Shipps[i])][realcards][0];
    }

    free(Shipps);
}

void PureCromossomeMutation(float ***BaseStructure, float ***FullList, float *Fitness, int *CardsStudied,int realcards,int manysites,int manyparentals){
    int therand,position,randcromossome;
    srand(time(NULL));


    randcromossome=(rand()%(manyparentals-1))+1;
    therand=(rand()%(manysites));

    Fitness[randcromossome]=0;
    position=-1;

    for(int n=0;n<realcards;n++){
        for(int o=0;o<CardsStudied[n];o++){
            position+=1;

            FullList[randcromossome][position][0]=(float)(therand);

            if(BaseStructure[(int)(therand)][n][o]==(float)(1000000)){
                FullList[randcromossome][position][1]=(float)(1000000);
                Fitness[randcromossome]+=(float)(1000000);  
            }
            else{
                FullList[randcromossome][position][1]=BaseStructure[(int)(therand)][n][o]*BaseStructure[(int)(therand)][realcards][1];
                Fitness[randcromossome]+=BaseStructure[(int)(therand)][n][o]*BaseStructure[(int)(therand)][realcards][1];
            }
        }
    }
    Fitness[randcromossome]+=BaseStructure[therand][realcards][0];
}

void RandomCromossomeMutation(float ***BaseStructure, float ***FullList, float *Fitness, int *CardsStudied,int realcards,int manysites,int manyparentals,int manycards){
    int *provisoryArray;
    int *Shipps=calloc((manycards),sizeof(int));
    int therand,position,addable,summer,definer,randcromossome;
    srand(time(NULL));


    randcromossome=(rand()%(manyparentals-1))+1;

    Fitness[randcromossome]=0;
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
            FullList[randcromossome][position][0]=(float)(therand);
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
                FullList[randcromossome][position][1]=(float)(1000000);
                Fitness[randcromossome]+=(float)(1000000);  
            }
            else{
                FullList[randcromossome][position][1]=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
                Fitness[randcromossome]+=BaseStructure[(int)(therand)][n][addable]*BaseStructure[(int)(therand)][realcards][1];
            }
        }
        free(provisoryArray);
    }

    for(int i=0;i<summer;i++){
        Fitness[randcromossome]+=BaseStructure[(Shipps[i])][realcards][0];
    }

    free(Shipps);
}

void MutationEvalAndPrintCoordinates(float *Fitness,float *IfMutation,int *coef,int *mutvar,int manyparentals,int xaxis){
    float average=0;
    srand(time(NULL));
    FILE *filec= fopen("coordinates.txt","a+");
    if(Fitness[0]!=(*(IfMutation))){
        for(int i=0;i<manyparentals;i++){
            average+=Fitness[i];
        }
        average/=manyparentals;
        fprintf(filec,"%d\t\t%f\t\t%f\n",(xaxis+1),Fitness[0],average);
        (*(mutvar))=1;
        (*(coef))=-1;
        (*(IfMutation))=Fitness[0];
    }
    fclose(filec);
    *(coef)+= 1;
    if(((*(coef))!=0)&&((*(coef))%5==0)){
        (*(mutvar))*=((rand()%2)+1);
        if((*(mutvar))>=(3*manyparentals)){(*(mutvar))=(3*manyparentals);}
    }
}