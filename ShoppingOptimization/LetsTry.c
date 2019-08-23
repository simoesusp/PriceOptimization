#include<stdio.h>
#include<stdlib.h>
#include<time.h>


float **AppendFromTxt(float ****BaseStructureAd,int **CardsStudiedAd,int *realcards,int *manycards,int *manysites){
    FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
    int i=-1,starterarray=-1,ArrayCardPos=-1,ArraySitePos=0,ArrayTypePos=0,definer=0;




	stream = fopen("summary.txt", "r");
	if (stream == NULL){
		exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, stream)) != -1) {
        i+=1;
        if(i==0){
        }
        else if(i==1){
            (*(manysites))=atoi(line);
            *BaseStructureAd=malloc((*(manysites))*(sizeof(float**)));

        }
        else if(i==2){
            (*(realcards))=atoi(line);
            *CardsStudiedAd=calloc((*(realcards)),sizeof(int));
            for(int r=0;r<(*(manysites));r++){
                (*BaseStructureAd)[r]=malloc(((*(realcards))+1)*(sizeof(float*)));
            }
        }
        else if(i==3){
            (*(manycards))=atoi(line);
        }
        else if(i<=6){
            starterarray=-1;
        }
        else{
            starterarray+=1;
        }

        if((atoi(line))>123456780){
            starterarray-=1;
            ArrayCardPos+=1;
            if(definer==0){
                (*CardsStudiedAd)[ArrayCardPos]=(atoi(line))%10;
                for(int r=0;r<(*(manysites));r++){
                    (*BaseStructureAd)[r][ArrayCardPos]=calloc(((atoi(line))%10),(sizeof(float)));
                }
            }
            ArrayTypePos=0;
        }
        else{
            if(starterarray>=0){
                (*BaseStructureAd)[ArraySitePos][ArrayCardPos][ArrayTypePos]=(float)atof(line);
                ArrayTypePos+=1;
            }
            if(starterarray==((*(manycards))+1)){
                ArrayTypePos=0;
                starterarray=-1;
                ArraySitePos+=1;
                ArrayCardPos=-1;
                definer=1;
                
            }   
        }
	}

	free(line);
	fclose(stream);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void CreateAll(float ***FullListAd, float **FitnessAd,float ***FullListAd2, float **FitnessAd2,int ***quantitylistAd,int ***quantitylistAd2,int ***siteslistAd,int ***siteslistAd2,int manyparentals,int manycards,int manysites){

    *FullListAd=malloc((manyparentals)*sizeof(float*));
    *FitnessAd=calloc(manyparentals,sizeof(float));
    *FullListAd2=malloc((manyparentals)*sizeof(float*));
    *FitnessAd2=calloc(manyparentals,sizeof(float));
    *quantitylistAd=malloc((manyparentals)*sizeof(int*));
    *quantitylistAd2=malloc((manyparentals)*sizeof(int*));
    *siteslistAd=malloc((manyparentals)*sizeof(int*));
    *siteslistAd2=malloc((manyparentals)*sizeof(int*));

    for(int i=0;i<manyparentals;i++){
        (*FullListAd)[i]=calloc(manycards,sizeof(float));
        (*FullListAd2)[i]=calloc(manycards,sizeof(float));
        (*quantitylistAd)[i]=calloc((manycards+1),sizeof(int));
        (*quantitylistAd2)[i]=calloc((manycards+1),sizeof(int));
        (*siteslistAd)[i]=calloc(manysites,sizeof(float));
        (*siteslistAd2)[i]=calloc(manysites,sizeof(float));
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void ManyParentalsStart(int manysites,int m,int manycards,int ***quantitylistAd,int *allsites,int ***siteslistAd){
    int torand=manysites,randpart,numberofsites;
    numberofsites=(rand()%(manycards))+1;
    if(numberofsites>manysites) numberofsites=manysites;
    (*quantitylistAd)[m][0]=numberofsites;
    for(int i=1;i<=numberofsites;i++){
        randpart=rand()%(torand);
        (*quantitylistAd)[m][i]=allsites[randpart];
        (*siteslistAd)[m][(allsites[randpart])]=1;
        torand-=1;
        allsites[randpart]=allsites[torand];
        allsites[torand]=(*quantitylistAd)[m][i];
    }
}

void ManyParentalsStart2(int manysites,int m,int manycards,int ***quantitylistAd,int *allsites,int ***siteslistAd){
    int torand=manysites,randpart,numberofsites;
    numberofsites=15;
    (*quantitylistAd)[m][0]=numberofsites;
    for(int i=1;i<=numberofsites;i++){
        randpart=rand()%(torand);
        (*quantitylistAd)[m][i]=allsites[randpart];
        (*siteslistAd)[m][(allsites[randpart])]=1;
        torand-=1;
        allsites[randpart]=allsites[torand];
        allsites[torand]=(*quantitylistAd)[m][i];
    }
}


void CrossoverStart(int m,int manysites,int ***siteslistAd2,int ***quantitylistAd,int ***quantitylistAd2){
    int torand,randpart,pos=1, theswap,numberofsites;    
    int members[2]={0};

    for(int i=0;i<manysites;i++) (*siteslistAd2)[m][i]=0;

    if(((*quantitylistAd)[0][0]%2)&&((*quantitylistAd)[m][0]%2)) members[(rand()%2)]=1;
    else if((*quantitylistAd)[0][0]%2) members[0]=(rand()%2);
    else if((*quantitylistAd)[m][0]%2) members[1]=(rand()%2);

    numberofsites=(((*quantitylistAd)[0][0])/2)+(((*quantitylistAd)[m][0])/2)+members[0]+members[1];

    torand=(*quantitylistAd)[0][0];
    for(int i=0;i<(((*quantitylistAd)[0][0]/2)+members[0]);i++){
        randpart=1+rand()%(torand);
        theswap=(*quantitylistAd)[0][randpart];
        if(!((*siteslistAd2)[m][theswap])){
            (*quantitylistAd2)[m][pos]=theswap;
            pos+=1;
            (*siteslistAd2)[m][theswap]=1;
        }

        (*quantitylistAd)[0][randpart]=(*quantitylistAd)[0][torand];
        (*quantitylistAd)[0][torand]=theswap;
        torand-=1;
    }

    torand=(*quantitylistAd)[m][0];
    for(int i=0;i<(((*quantitylistAd)[m][0]/2)+members[1]);i++){
        randpart=1+rand()%(torand);
        theswap=(*quantitylistAd)[m][randpart];
        if(!((*siteslistAd2)[m][theswap])){
            (*quantitylistAd2)[m][pos]=theswap;
            pos+=1;
            (*siteslistAd2)[m][theswap]=1;
        }

        (*quantitylistAd)[m][randpart]=(*quantitylistAd)[m][torand];
        (*quantitylistAd)[m][torand]=theswap;
        torand-=1;
    }

    (*quantitylistAd2)[m][0]=pos-1;

}

void MutationStart(int m,int ***quantitylistAd,int mutation,int ***siteslistAd,int manysites,int *allsites){
    int variable=0,torand,randpart,theswap,newrand;    

    torand=(*quantitylistAd)[m][0];
    while((mutation>variable) && (torand>variable)){
        randpart=1+rand()%(torand-variable);
        (*siteslistAd)[m][((*quantitylistAd)[m][randpart])]=0;
        newrand=rand()%(manysites-variable);
        if((*siteslistAd)[m][(allsites[newrand])]){
            (*quantitylistAd)[m][randpart]=(*quantitylistAd)[m][(torand-variable)];
            (*quantitylistAd)[m][(torand-variable)]=(*quantitylistAd)[m][((*quantitylistAd)[m][0])];
            (*quantitylistAd)[m][((*quantitylistAd)[m][0])]=0;
            (*quantitylistAd)[m][0]-=1;
            theswap=allsites[newrand];            
            allsites[newrand]=allsites[(manysites-variable-1)];
            allsites[(manysites-variable-1)]=theswap;
        }
        else{
            (*siteslistAd)[m][(allsites[newrand])]=1;
            (*quantitylistAd)[m][randpart]=(*quantitylistAd)[m][(torand-variable)];
            (*quantitylistAd)[m][(torand-variable)]=allsites[newrand];
            allsites[newrand]=allsites[(manysites-variable-1)];
            allsites[(manysites-variable-1)]=(*quantitylistAd)[m][(torand-variable)];
        }
        variable+=1;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////
void ParentalGeneration(int initial,int manysites,int manyparentals,float **FitnessAd,int manycards, int ***quantitylistAd,int ***siteslistAd,float ***BaseStructure,int realcards,float ***FullListAd,int *CardsStudied){
    int *provisoryArray;
    int therand,position,randpos,theswap,increases,numberofsites;
    int *allsites=calloc(manysites,sizeof(int));
    int *turninto;
    int *Shipps;
    for(int i=0;i<manysites;i++) allsites[i]=i;


    for(int m=initial;m<manyparentals;m++){
        turninto=calloc((manycards+1),sizeof(int));
        (*FitnessAd)[m]=0;
        position=-1;
        ManyParentalsStart(manysites,m,manycards,quantitylistAd,allsites,siteslistAd);
        Shipps=calloc(manysites,sizeof(int));
        for(int n=0;n<realcards;n++){
            provisoryArray=calloc(manysites,sizeof(int));
            for(int o=0;o<CardsStudied[n];o++){
                position+=1;
                therand=(*quantitylistAd)[m][1];
                for(int i=2;i<=((*quantitylistAd)[m][0]);i++){
                    if(((BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1])>(BaseStructure[((*quantitylistAd)[m][i])][n][(provisoryArray[((*quantitylistAd)[m][i])])]*BaseStructure[((*quantitylistAd)[m][i])][realcards][1]))||(((BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1])==(BaseStructure[((*quantitylistAd)[m][i])][n][(provisoryArray[((*quantitylistAd)[m][i])])]*BaseStructure[((*quantitylistAd)[m][i])][realcards][1]))&&(rand()%2))){
                        therand=(*quantitylistAd)[m][i];        
                    }
                }
                if(!(Shipps[therand])){
                    Shipps[therand]=1;
                    (*FitnessAd)[m]+=BaseStructure[therand][realcards][0];
                    turninto[(turninto[0]+1)]=therand;
                    turninto[0]+=1;        
                }
                (*FitnessAd)[m]+=BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1];
                (*FullListAd)[m][position]=(float)(therand);

                provisoryArray[therand]+=1;
            }
            free(provisoryArray);
        }
        for(int i=0;i<=(turninto[0]);i++){
            (*quantitylistAd)[m][i]=turninto[i];        
        }
        free(Shipps);
        free(turninto);
    }
}


void MutationGeneration(int manysites,int manyparentals,float **FitnessAd,int mutation,int manycards, int ***quantitylistAd,int ***siteslistAd,float ***BaseStructure,int realcards,float ***FullListAd,int *CardsStudied){
    int *provisoryArray;
    int therand,position,randpos,theswap,increases,numberofsites;
    int *possibilities;
    int *Shipps;
    int *allsites=calloc(manysites,sizeof(int));
    int *turninto;

    for(int i=0;i<manysites;i++) allsites[i]=i;


    for(int m=1;m<manyparentals;m++){
        turninto=calloc((manycards+1),sizeof(int));
        (*FitnessAd)[m]=0;
        position=-1;
        MutationStart(m,quantitylistAd,mutation,siteslistAd,manysites,allsites);
        Shipps=calloc(manysites,sizeof(int));
        for(int n=0;n<realcards;n++){
            provisoryArray=calloc(manysites,sizeof(int));
            for(int o=0;o<CardsStudied[n];o++){
                position+=1;
                therand=(*quantitylistAd)[m][1];
                for(int i=2;i<=((*quantitylistAd)[m][0]);i++){
                    if(((BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1])>(BaseStructure[((*quantitylistAd)[m][i])][n][(provisoryArray[((*quantitylistAd)[m][i])])]*BaseStructure[((*quantitylistAd)[m][i])][realcards][1]))||(((BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1])==(BaseStructure[((*quantitylistAd)[m][i])][n][(provisoryArray[((*quantitylistAd)[m][i])])]*BaseStructure[((*quantitylistAd)[m][i])][realcards][1]))&&(rand()%2))){
                        therand=(*quantitylistAd)[m][i];        
                    }
                }
                if(!(Shipps[therand])){
                    Shipps[therand]=1;
                    (*FitnessAd)[m]+=BaseStructure[therand][realcards][0];        
                    turninto[(turninto[0]+1)]=therand;
                    turninto[0]+=1;        
                }
                (*FitnessAd)[m]+=BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1];
                (*FullListAd)[m][position]=(float)(therand);

                provisoryArray[therand]+=1;
            }
            free(provisoryArray);
        }
        for(int i=0;i<=(turninto[0]);i++){
            (*quantitylistAd)[m][i]=turninto[i];        
        }
        free(Shipps);
        free(turninto);
    }

}

void CrossoverGeneration(int manysites,int manyparentals,float **FitnessAd, int ***siteslistAd2,int ***quantitylistAd2,int manycards, int ***quantitylistAd,int ***siteslistAd,float ***BaseStructure,int realcards,float ***FullListAd,float **FitnessAd2,float ***FullListAd2,int *CardsStudied){
    int *provisoryArray;
    int therand,position,randpos,theswap,increases,numberofsites;
    int *possibilities;
    int *Shipps;
    void *theswapAd=NULL;
    int *turninto;
    int *allsites=calloc(manysites,sizeof(int));
    for(int i=0;i<manysites;i++) allsites[i]=i;
    int realq=0;
    (*FitnessAd2)[0]=(*FitnessAd)[0];



    for(int m=1;m<manyparentals;m++){
        turninto=calloc((manycards+1),sizeof(int));
        (*FitnessAd2)[m]=0;
        position=-1;
        CrossoverStart(m,manysites,siteslistAd2,quantitylistAd,quantitylistAd2);
        Shipps=calloc(manysites,sizeof(int));
        for(int n=0;n<realcards;n++){
            provisoryArray=calloc(manysites,sizeof(int));
            for(int o=0;o<CardsStudied[n];o++){
                position+=1;
                therand=(*quantitylistAd2)[m][1];
                for(int i=2;i<=((*quantitylistAd2)[m][0]);i++){
                    if(((BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1])>(BaseStructure[((*quantitylistAd2)[m][i])][n][(provisoryArray[((*quantitylistAd2)[m][i])])]*BaseStructure[((*quantitylistAd2)[m][i])][realcards][1]))||(((BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1])==(BaseStructure[((*quantitylistAd2)[m][i])][n][(provisoryArray[((*quantitylistAd2)[m][i])])]*BaseStructure[((*quantitylistAd2)[m][i])][realcards][1]))&&(rand()%2))){
                        therand=(*quantitylistAd2)[m][i];        
                    }
                }
                if(!(Shipps[therand])){
                    Shipps[therand]=1;
                    (*FitnessAd2)[m]+=BaseStructure[therand][realcards][0];        
                    turninto[(turninto[0]+1)]=therand;
                    turninto[0]+=1;        
                }
                (*FitnessAd2)[m]+=BaseStructure[therand][n][(provisoryArray[therand])]*BaseStructure[therand][realcards][1];
                (*FullListAd2)[m][position]=(float)(therand);

                provisoryArray[therand]+=1;
            }
            free(provisoryArray);
        }
        for(int i=0;i<=(turninto[0]);i++){
            (*quantitylistAd2)[m][i]=turninto[i];        
        }
        free(Shipps);
        free(turninto);
    }



    theswapAd=(*quantitylistAd);
    (*quantitylistAd)=(*quantitylistAd2);
    (*quantitylistAd2)=theswapAd;

    theswapAd=(*siteslistAd);
    (*siteslistAd)=(*siteslistAd2);
    (*siteslistAd2)=theswapAd;

    theswapAd=(*FullListAd);
    (*FullListAd)=(*FullListAd2);
    (*FullListAd2)=theswapAd;

    theswapAd=(*FitnessAd);
    (*FitnessAd)=(*FitnessAd2);
    (*FitnessAd2)=theswapAd;


}
///////////////////////////////////////////////////////////////////////////////////////////////////


void FindBest(float *Fitness,float *Fitness2,float **FullList,float **FullList2,int **quantitylist,int **quantitylist2,int **siteslist,int **siteslist2,int manyparentals,int manycards,int manysites,int *last,int posi){
    int min=0;
    float theswapf;
    int theswapi;
    
    for(int i=1;i<manyparentals;i++) if(Fitness[min]>Fitness[i]) min=i;

    if(min){
        printf("..\n");
        (*last)=posi;
        theswapf=Fitness[0];
        Fitness[0]=Fitness[min];
        Fitness[min]=theswapf;
        Fitness2[0]=Fitness[0];
        Fitness2[min]=Fitness[min];

        for(int i=0;i<manycards;i++){
            theswapf=FullList[0][i];
            FullList[0][i]=FullList[min][i];
            FullList[min][i]=theswapf;
            FullList2[0][i]=FullList[0][i];
            FullList2[min][i]=FullList[min][i];

        }

        for(int i=0;i<=manycards;i++){
            theswapi=quantitylist[0][i];
            quantitylist[0][i]=quantitylist[min][i];
            quantitylist[min][i]=theswapi;
            quantitylist2[0][i]=quantitylist[0][i];
            quantitylist2[min][i]=quantitylist[min][i];
        }


        for(int i=0;i<manysites;i++){
            theswapi=siteslist[0][i];
            siteslist[0][i]=siteslist[min][i];
            siteslist[min][i]=theswapi;
            siteslist2[0][i]=siteslist[0][i];
            siteslist2[min][i]=siteslist[min][i];
        }
    }
}

int Evaluation(float *PreviousBest, float *Fitness, int *mutation,int *occurences,int manyparentals,int xaxis){
    FILE *filec = fopen("coordinates.txt","a+");
    float average=0;

    if(((*PreviousBest)>Fitness[0])&&(Fitness[0])){
        printf(".\n");
        //fprintf(filec,"%d,%f\n",(xaxis+1),Fitness[0]);
        //fclose(filec);
        printf("xx\n");

        (*PreviousBest)=Fitness[0];
        (*mutation)=1;
        (*occurences)=0;
        return 2;
    }
    else{
        (*occurences)+=1;

        if(!((*occurences)%10)){
            (*mutation)+=1;
        }
        if(!((*occurences)%100)){
            (*mutation)=1;
            return 1;        
        }
    }
    return 0;
}

void PrintParentals(int manyparentals,int **quantitylist,float *Fitness){

    for(int i=0;i<manyparentals;i++){
        printf("%d #%d#\n",i,quantitylist[i][0]);
        for(int j=1;j<=(quantitylist[i][0]);j++) printf("%d ",quantitylist[i][j]);
        printf("Fitness of (%d): %f\n",i,Fitness[i]);
    }


}

int main(void){
    float ***BaseStructure=NULL;
    float **FullList=NULL;
    float **FullList2=NULL;
    float *Fitness=NULL;
    float *Fitness2=NULL;
    int **quantitylist=NULL;
    int **quantitylist2=NULL;
    int **siteslist=NULL;
    int **siteslist2=NULL;
    int *CardsStudied=NULL;
    float partial=0;
    int eval=0;
    int last=0;
    int realcards=0,manycards=0,manysites=0,manyparentals=100,mutation=1,occurences=0,total=0,repetitions=10000,position;
    float PreviousBest;
    FILE *clearf= fopen("coordinates.txt","w");
    fclose(clearf);
    FILE *filem= fopen("coordinates.txt","a+");

    srand(time(NULL));

 /*
    printf("\nnumber of parentals: ");
    scanf("%d",&manyparentals);

    printf("\nnumber of repetitions: ");
    scanf("%d",&repetitions);
 */

    AppendFromTxt(&BaseStructure,&CardsStudied,&realcards,&manycards,&manysites);
    for(int k=0;k<manysites;k++){
        for(int i=0;i<realcards;i++){
            for(int j=0;j<CardsStudied[i];j++){
                if(BaseStructure[k][i][j]==0) BaseStructure[k][i][j]=1000000; 
            }
        }
    }



    CreateAll(&FullList,&Fitness,&FullList2,&Fitness2,&quantitylist,&quantitylist2,&siteslist,&siteslist2,manyparentals,manycards,manysites);
    ParentalGeneration(0,manysites,manyparentals,&Fitness,manycards,&quantitylist,&siteslist,BaseStructure,realcards,&FullList,CardsStudied);
    FindBest(Fitness,Fitness2,FullList,FullList2,quantitylist,quantitylist2,siteslist,siteslist2,manyparentals,manycards,manysites,&last,0);
    PreviousBest=Fitness[0];

    printf("\n%f / %f\n",BaseStructure[0][realcards][0],BaseStructure[0][realcards][1]);
    //PrintParentals(manyparentals,quantitylist);
    printf("Good: %f\n",PreviousBest);

    fprintf(filem,"%d,%f\n",0,Fitness[0]);
    fclose(filem);

    for(int r=0;r<repetitions;r++){
        if(eval==2) printf("...");
        CrossoverGeneration(manysites,manyparentals,&Fitness,&siteslist2,&quantitylist2,manycards,&quantitylist,&siteslist,BaseStructure,realcards,&FullList,&Fitness2,&FullList2,CardsStudied);
        MutationGeneration(manysites,manyparentals,&Fitness,mutation,manycards,&quantitylist,&siteslist,BaseStructure,realcards,&FullList,CardsStudied);        
        FindBest(Fitness,Fitness2,FullList,FullList2,quantitylist,quantitylist2,siteslist,siteslist2,manyparentals,manycards,manysites,&last,(r+1));
        eval=Evaluation(&PreviousBest,Fitness,&mutation,&occurences,manyparentals,r);
        if(eval==1) ParentalGeneration(1,manysites,manyparentals,&Fitness,manycards,&quantitylist,&siteslist,BaseStructure,realcards,&FullList,CardsStudied);
        if(!(r%(repetitions/100))) printf("%d%%\n",(r/(repetitions/100)));
    }
 /*
    filem= fopen("coordinates.txt","a+");
    fprintf(filem,"%d\t\t%f\n",repetitions,Fitness[0]);
    fclose(filem);
 */

    PrintParentals(manyparentals,quantitylist,Fitness);
    position=-1;
    for(int i=0;i<realcards;i++){
        printf("Card %d:\t",i);
        for(int j=0;j<CardsStudied[i];j++){
            position+=1;
            printf(" %f(%f)",FullList[0][position],BaseStructure[(int)(FullList[0][position])][i][0]);
        }
        printf("\n");
    }

    for(int i=1;i<=(quantitylist[0][0]);i++){
        printf("%d: %f(%f)\n",quantitylist[0][i],BaseStructure[(quantitylist[0][i])][realcards][0],BaseStructure[(quantitylist[0][i])][realcards][1]);
    }
    printf("\nBest Fitness: %f\tlast:%d\n\n",Fitness[0],last);
    return 0;
}

