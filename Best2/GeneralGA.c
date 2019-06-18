#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Appendfromtxt_Printall.h"
#include "Parentalgen_Findbest.h"
#include "Crossovers.h"
#include "Mutations.h"

int main(void){

    int realcards=0,manycards=0,manysites=0,manyparentals=100,coef=0,mutvar=1,crossovertype=0,repetitions=0;
    int *CardsStudied=NULL;
    time_t start;
    float IfMutation=0,average=0;
    float *Fitness=NULL;
    float *Fitness2=NULL;
    float ***FullList=NULL;
    float ***FullList2=NULL;
    float ***BaseStructure=NULL;
    FILE *filem= fopen("coordinates.txt","a+");
    FILE *clearf= fopen("coordinates.txt","w");

    fprintf (clearf,"");
    fclose(clearf);

    printf("type the crossover type:\n\t0 - Basic\n\t1 - Torneio de dois\n");
    scanf("%d",&crossovertype);
    printf("\ntype the number of repetitions(must be a multiple of 100): ");
    scanf("%d",&repetitions);
    printf("\n");
    AppendFromTxt(&BaseStructure,&CardsStudied,&realcards,&manycards,&manysites);
    //PrintBase(BaseStructure,manysites,realcards,CardsStudied);
    ParentalGeneration(&FullList,&Fitness,&FullList2,&Fitness2,BaseStructure,CardsStudied,realcards,manysites,manyparentals,manycards);
    FindBest(Fitness,FullList,manyparentals,manycards);
    //PrintList(FullList,Fitness,manyparentals,manycards);

    IfMutation=Fitness[0];
    for(int i=0;i<manyparentals;i++){
        average+=Fitness[i];
    }
    average/=manyparentals;
    fprintf(filem,"x-max\t\ty-max\n\n%d\t\t%f\n\n\nx-axis\t\ty-axis of best value\ty-axis of average value\n\n0\t\t%f\t\t%f\n",repetitions,IfMutation,IfMutation,average);
    fclose(filem);
    start=time(NULL);
    for(int i=0;i<repetitions;i++){
        if(crossovertype){TournmentOfTwo(BaseStructure,&FullList,&Fitness,&FullList2,&Fitness2,CardsStudied,realcards,manysites,manyparentals,manycards);}
        else{BasicCrossover(BaseStructure,&FullList,&Fitness,&FullList2,&Fitness2,CardsStudied,realcards,manysites,manyparentals,manycards);}
        if((i!=0)&&(i%10==0)&&(i%20!=1)){PureCromossomeMutation(BaseStructure,FullList,Fitness,CardsStudied,realcards,manysites,manyparentals);}
        if((i!=0)&&(i%20==0)){RandomCromossomeMutation(BaseStructure,FullList,Fitness,CardsStudied,realcards,manysites,manyparentals,manycards);}
        BasicMutation(BaseStructure,FullList,Fitness,CardsStudied,realcards,manysites,manyparentals,manycards,mutvar);
        FindBest(Fitness,FullList,manyparentals,manycards);
        MutationEvalAndPrintCoordinates(Fitness,&IfMutation,&coef,&mutvar,manyparentals,i);
        if((i!=0)&&(i%(repetitions/100)==0)){printf("\n%d%%\n",((100*i)/repetitions));}
    }
    //PrintList(FullList,Fitness,manyparentals,manycards);

    FreeForAll(BaseStructure,FullList,Fitness,FullList2,Fitness2,CardsStudied,realcards,manysites,manyparentals,manycards);
    printf("\n100%%\n\nAccess the results on 'coordinates.txt' in this same directory.\n\n");    

    return 0;
}
