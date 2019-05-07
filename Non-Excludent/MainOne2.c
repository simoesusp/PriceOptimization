#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int CopyTest(float *Fitness,float *FullListvoid,int befores,int manyterms){
    int toreturn=0,itsacoppy;
    itsacoppy=1;
    for(int i=0;i<befores;i++){
        if(Fitness[i]==Fitness[befores]){        
            for(int j=0;j<manyterms;j++){
                if((int)FullListvoid[220*i+2*j]!=(int)FullListvoid[220*befores+2*j]){
                    itsacoppy=0;
                    break;
                }
            }
            if(itsacoppy==1){
                toreturn=1;
            }
            itsacoppy=1;
        }
        if(toreturn){
            break;
        }
    }
   return toreturn;
}
int MutationCopyTest(float *Fitness,float *FullListvoid,float MutatedFitness,float *MutatedCromossomevoid,int exeption,int manyterms,int limitation){
    int toreturn=0,itsacoppy;
    itsacoppy=1;
    for(int i=0;i<limitation;i++){
        if(i!=exeption){
            if(Fitness[i]==MutatedFitness){        
                for(int j=0;j<manyterms;j++){
                    if(FullListvoid[220*i+2*j]!=MutatedCromossomevoid[2*j]){
                        itsacoppy=0;
                        break;
                    }
                }
                if(itsacoppy==1){
                    toreturn=1;
                }
                itsacoppy=1;
            }
            if(toreturn){
                break;
            }
        }
    }
    return toreturn;
}

void AppendFromTxt(float *BaseStructurevoid,int *ThePositions,int *CardsStudied,int *realcards,int *manycards,int *manysites){
    FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
    int i=-1,starterarray=-1,ArrayCardPos=0,ArraySitePos=0,ArrayTypePos=0,definer=0;



    for(int i=0;i<200;i++){
        ThePositions[i]=i;
    }

 
	stream = fopen("summary.txt", "r");
	if (stream == NULL){
		exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, stream)) != -1) {
        i+=1;
		//printf("\nthe value of the down one: %s\n\n",line);
        if(i==0){
            //printf("\nnoppe!\n");
        }
        else if(i==1){
            (*(manycards))=atoi(line);
        }
        else if(i==2){
            (*(manysites))=atoi(line);
        }
        else if(i<=5){
            starterarray=-1;
        }
        else{
            starterarray+=1;
        }

        if((atoi(line))>123456780){
            //printf("\naaa\n");
            starterarray-=1;
            if(definer==0){
                CardsStudied[ArrayCardPos]=(atoi(line))%10;
                (*(realcards))+=1;
            }
            ArrayCardPos+=1;
            ArrayTypePos=0;
            
        }
        else{
            if(starterarray>=0){
                BaseStructurevoid[525*ArraySitePos + 5*ArrayCardPos + ArrayTypePos] =(float)atof(line);
                //printf("\nthe value[%d][%d][%d]: %f\n\n",ArraySitePos,ArrayCardPos,ArrayTypePos,(*((float*)(BaseStructurevoid + 4*(525*ArraySitePos + 5*ArrayCardPos + ArrayTypePos)))));
                ArrayTypePos+=1;
            }
            if(starterarray==((*(manycards))+1)){
                ArrayTypePos=0;
                starterarray=-1;
                ArraySitePos+=1;
                ArrayCardPos=0;
                definer=1;
            }
            
        }
	}
    //printf("\n\n\n\n\n\n\n\nrealcards:%d\n\n\nthe three:%d,%d,%d\n\n\n",(*(realcards)),CardsStudied[0],CardsStudied[1],CardsStudied[2]);

    for(int i=0;i<(*(manysites));i++){
        //printf("\n\n\n");
        for(int j=0;j<((*(realcards))+1);j++){
            for(int k=0;k<5;k++){
                //printf("%f\t",(*((float*)(BaseStructurevoid + 4*(525*i + 5*j + k)))));
            }
            
        }
    }

    for(int i=0;i<(*(manysites));i++){
        //printf("\n\n\n");
        for(int j=0;j<((*(realcards))+1);j++){
            for(int k=0;k<5;k++){
                //printf("%f\t",(*((float*)(BaseStructurevoid + 4*(525*i + 5*j + k)))));
            }
            
        }
    }

	free(line);
	fclose(stream);
    //printf("\n\n\nreal cards:%d\n\n\n",(*(realcards)));
}

void ParentalGeneration(float *BaseStructurevoid,float *FullListvoid, float *Fitness, int *CardsStudied,int *realcards,int *manysites,int manyparentals){
    int provisoryArray[5];
    int Shipps[525];
    int therand,position,addable,summer,definer,test,m;
    srand(time(NULL));
    m=0;

    while(m<manyparentals){
        Fitness[m]=0;
        summer=0;
        //
        position=-1;
        definer=1;
        for(int i=0;i<525;i++){
            Shipps[i]=-1;
        }


        for(int n=0;n<(*(realcards));n++){
            //printf("CSt:%d\n",CardsStudied[n]);
            for(int o=0;o<CardsStudied[n];o++){
                //
                position+=1;
                therand=rand()%(*(manysites));
                provisoryArray[o]=therand;
                FullListvoid[220*m+2*position]=(float)(therand);
                addable=0;
                
                for(int q=0;q<o;q++){
                    if(provisoryArray[q]==therand){
                        addable+=1;
                    }
                }

                for(int q=0;q<summer;q++){
                    if(Shipps[q]==therand){
                        definer=0;
                    }
                }

                if(definer){
                    Shipps[summer]=therand;
                    summer+=1;
                }
                definer=1;

                //printf("%d/%d-%d/",therand,n,addable);
                if(BaseStructurevoid[525*((int)(therand)) + 5*n + addable]==(float)(1000000)){
                    FullListvoid[220*m+2*position+1]=(float)(1000000);
                    Fitness[m]+=(float)(1000000);
                    //printf("%f\n",(float)(1000000));   
                }
                else{
                    FullListvoid[220*m+2*position+1]=BaseStructurevoid[525*((int)(therand)) + 5*n + addable]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                    Fitness[m]+=BaseStructurevoid[525*((int)(therand)) + 5*n + addable]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                    //printf("%f\n",((*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*n + addable))))*(*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*(*(realcards)) + 1))))));   
                }
                
            }
        }
        for(int i=0;i<summer;i++){
            Fitness[m]+=BaseStructurevoid[525*(Shipps[i]) + 5*(*(realcards))];
        }
        test=CopyTest(Fitness,FullListvoid,m,position);
        if(test==0){
            m+=1;            
        }
    }
}

void swapi(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

void swapf(float* a, float* b) 
{ 
    float t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (float arr[], int arr2[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swapf(&arr[i], &arr[j]);
            swapi(&arr2[i], &arr2[j]); 
        } 
    } 
    swapf(&arr[i + 1], &arr[high]);
    swapi(&arr2[i +1], &arr2[high]); 
    return (i + 1); 
}


  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(float arr[], int arr2[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr,arr2, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr,arr2, low, pi - 1); 
        quickSort(arr,arr2, pi + 1, high); 
    } 
}
void Sorting(float *Fitness,int *ThePositions,float *FullListvoid,int *manycards, int *CardsStudied,int *realcards,int quantity){
    float FullList2[199][110][2]={0};

    quickSort(Fitness,ThePositions,0,(quantity-1));
 
    for(int m=0;m<quantity;m++){
        for(int n=0;n<110;n++){
            FullList2[m][n][0]=FullListvoid[220*ThePositions[m]+2*n];
            FullList2[m][n][1]=FullListvoid[220*ThePositions[m]+2*n+1];  
        }
    }

    for(int m=0;m<quantity;m++){
        for(int n=0;n<110;n++){
            FullListvoid[220*m+2*n]=FullList2[m][n][0];
            FullListvoid[220*m+2*n+1]=FullList2[m][n][1];  
        }
    }
    for(int i=0;i<200;i++){
        ThePositions[i]=i;
    }

}

int Breeding(float *BaseStructurevoid,float *FullListvoid, float *Fitness, int *CardsStudied,int *realcards,int *manysites,int manyparentals){
    int provisoryArray[5];
    int Shipps[525];
    int therand,position,addable,summer,definer,test,m,actual;
    srand(time(NULL));
    actual=manyparentals;

    for(int m=manyparentals;m<(2*manyparentals-1);m++){
        Fitness[actual]=(float)(0);
        summer=0;
        position=-1;
        definer=1;
        for(int i=0;i<525;i++){
            Shipps[i]=-1;
        }

        for(int n=0;n<(*(realcards));n++){
            for(int o=0;o<CardsStudied[n];o++){

                position+=1;
                //
                therand=rand()%2;
                if(therand){
                    therand=(int)(FullListvoid[220*(m-manyparentals+1)+2*position]);                    
                }
                else{
                    therand=(int)(FullListvoid[2*position]);
                }
                //
                provisoryArray[o]=therand;
                FullListvoid[220*actual+2*position]=(float)(therand);
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

                //printf("%d/%d-%d/",therand,n,addable);
                if(BaseStructurevoid[525*((int)(therand)) + 5*n + addable]==(float)(1000000)){
                    FullListvoid[220*actual+2*position+1]=(float)(1000000);
                    Fitness[actual]+=(float)(1000000);
                    //printf("%f\n",(float)(1000000));   
                }
                else{
                    FullListvoid[220*actual+2*position+1]=BaseStructurevoid[525*((int)(therand)) + 5*n + addable]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                    Fitness[actual]+=BaseStructurevoid[525*((int)(therand)) + 5*n + addable]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                    //printf("%f\n",((*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*n + addable))))*(*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*(*(realcards)) + 1))))));   
                }
                
            }
        }
        for(int i=0;i<summer;i++){
            Fitness[actual]+=BaseStructurevoid[525*(Shipps[i]) + 5*(*(realcards))];
        }
 //jkejhgiouerwhiougwerhuilgwrhoiugeruioghier
        test=CopyTest(Fitness,FullListvoid,actual,position);
        if(test==0){
            actual+=1;            
        }

    }
    return actual;
}

void BasicMutation(float *BaseStructurevoid,float *FullListvoid, float *Fitness, int *CardsStudied,int *realcards,int *manysites,int limitation, int coef){
    int provisoryArray[5];
    float MutatedCromossome[110][2];
    float *MutatedCromossomevoid=(float*)(MutatedCromossome);
    float MutatedFitness=0;
    int Shipps[525];
    int therand,position,addable,summer,definer,test,thecard,thepos,thechange,theswaped,therealpos;
    srand(time(NULL));

    for(int p=0;p<coef;p++){
        thecard=rand()%(*(realcards));
        thepos=rand()%(CardsStudied[thecard]);
        thechange=rand()%(*(manysites));
        theswaped=(rand()%(limitation-1))+1;
        therealpos=0;
        for(int i=0;i<thecard;i++){
            therealpos+=CardsStudied[i];
        }
        therealpos+=thepos;
        if(thechange!=((int)(FullListvoid[220*theswaped+2*therealpos]))){
            summer=0;
            position=-1;
            definer=1;
            for(int i=0;i<525;i++){
                Shipps[i]=-1;
            }

            for(int n=0;n<(*(realcards));n++){
                for(int o=0;o<CardsStudied[n];o++){

                    position+=1;
                    if((n==thecard)&&(o==thepos)){
                        therand=thechange;
                    }
                    else{
                        therand=(int)(FullListvoid[220*theswaped+2*position]);
                    }

                    provisoryArray[o]=therand;
                    MutatedCromossome[position][0]=(float)(therand);
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

                    //printf("%d/%d-%d/",therand,n,addable);
                    if(BaseStructurevoid[525*((int)(therand)) + 5*n + addable]==(float)(1000000)){
                        MutatedCromossome[position][1]=(float)(1000000);
                        MutatedFitness+=(float)(1000000);
                        //printf("%f\n",(float)(1000000));   
                    }
                    else{
                        MutatedCromossome[position][1]=BaseStructurevoid[525*((int)(therand)) + 5*n + addable]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                        MutatedFitness+=BaseStructurevoid[525*((int)(therand)) + 5*n + addable]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                        //printf("%f\n",((*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*n + addable))))*(*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*(*(realcards)) + 1))))));   
                    }
                    
                }
            }
            for(int i=0;i<summer;i++){
                MutatedFitness+=BaseStructurevoid[525*(Shipps[i]) + 5*(*(realcards))];
            }
        //jkejhgiouerwhiougwerhuilgwrhoiugeruioghier
            test=MutationCopyTest(Fitness,FullListvoid,MutatedFitness,MutatedCromossomevoid,theswaped,position,limitation);
            if(test==0){
                for(int n=0;n<110;n++){
                    FullListvoid[220*theswaped+2*n]=MutatedCromossome[n][0];
                    FullListvoid[220*theswaped+2*n+1]=MutatedCromossome[n][1];  
                }
                Fitness[theswaped]=MutatedFitness;
            }
        }
    }

}
void PureCromossomeMutation(float *BaseStructurevoid,float *FullListvoid, float *Fitness,int *CardsStudied,int *realcards,int *manysites,int manyparentals){
    int therand,position,theswaped,test;
    float MutatedCromossome[110][2];
    float *MutatedCromossomevoid=(float*)(MutatedCromossome);
    float MutatedFitness=0;

    srand(time(NULL));

    therand=rand()%(*(manysites));
    theswaped=(rand()%(manyparentals-1))+1;

    position=-1;

    for(int n=0;n<(*(realcards));n++){
        for(int o=0;o<CardsStudied[n];o++){

            position+=1;

            MutatedCromossome[position][0]=(float)(therand);

            if(BaseStructurevoid[525*((int)(therand)) + 5*n + o]==(float)(1000000)){
                MutatedCromossome[position][1]=(float)(1000000);
                MutatedFitness+=(float)(1000000);
                //printf("%f\n",(float)(1000000));   
            }
            else{
                MutatedCromossome[position][1]=BaseStructurevoid[525*((int)(therand)) + 5*n + o]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                MutatedFitness+=BaseStructurevoid[525*((int)(therand)) + 5*n + o]*BaseStructurevoid[525*((int)(therand)) + 5*(*(realcards)) + 1];
                //printf("%f\n",((*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*n + addable))))*(*((float*)(BaseStructurevoid + 4*(525*((int)(therand)) + 5*(*(realcards)) + 1))))));   
            }
            
        }
    }
    MutatedFitness+=BaseStructurevoid[525*therand + 5*(*(realcards))];
    test=MutationCopyTest(Fitness,FullListvoid,MutatedFitness,MutatedCromossomevoid,theswaped,position,manyparentals);
    if(test==0){
        for(int n=0;n<110;n++){
            FullListvoid[220*theswaped+2*n]=MutatedCromossome[n][0];
            FullListvoid[220*theswaped+2*n+1]=MutatedCromossome[n][1];  
        }
        Fitness[theswaped]=MutatedFitness;
    }

}

int main(void){

 
 // Declaring Variables//
    int manycards=0,manysites=0,starterarray,i,ArrayCardPos,ArraySitePos,ArrayTypePos,addable,manyparentals=100,nt;

    float BaseStructure[120][105][5];
    float *BaseStructurevoid=(float*)(BaseStructure);

    float FullList[199][110][2];
    float *FullListvoid=(float*)(FullList);
    float FullList2[199][110][2];

    float Fitness[200];
    int therand,realcards=0,definer=0,quantity=0,coef,mutcoef;
    int CardsStudied[110];
    int ThePositions[200];
    float IfMutation;

 // Create the array//
    AppendFromTxt(BaseStructurevoid,ThePositions,CardsStudied,&realcards,&manycards,&manysites);

 
    for(int i=0;i<manysites;i++){
        printf("%d:",i);
        for(int j=0;j<realcards+1;j++){
            printf("[%f,%f,%f,%f,%f],",BaseStructure[i][j][0],BaseStructure[i][j][1],BaseStructure[i][j][2],BaseStructure[i][j][3],BaseStructure[i][j][4]);
        }
        printf("\n###\n");
    }

    printf("\n\n##############\n\n");

 
 
 //  Create the first 100 individuals //
    ParentalGeneration(BaseStructurevoid,FullListvoid,Fitness,CardsStudied,&realcards,&manysites,manyparentals);

    printf("\n\n##############\n\n");


 //  FirstSorting  //
    printf("\n\nunsorted\n\n");

 /*
    for(int m=0;m<100;m++){
        printf("\n\n\n#%d:\n[",m);
        for(int n=0;n<realcards;n++){
            printf("[");
            for(int o=0;o<CardsStudied[n];o++){    
                printf("[%f;%f],",FullList[m][n+o][0],FullList[m][n+o][1]);
            }
            printf("],");
        }
        printf("]\n%f\n##############################################################################",Fitness[m]);
    }
 */
    for(int m=0;m<199;m++){
        printf("\n\n\n#%d:\n[",m);
        for(int n=0;n<110;n++){
            printf("[");   
            printf("[%f;%f],",FullList[m][n][0],FullList[m][n][1]);
            printf("],");
        }
        printf("]\n%f\n##############################################################################",Fitness[m]);
    }

    printf("\n\nfirst sorted\n\n");

    quantity=manyparentals;
    Sorting(Fitness,ThePositions,FullListvoid,&manycards,CardsStudied,&realcards,quantity);

    for(int i=0;i<199;i++){
        printf("\n:%d:\n",ThePositions[i]);
    }

    for(int m=0;m<199;m++){
        printf("\n\n\n#%d:\n[",m);
        for(int n=0;n<110;n++){
            printf("[%f;%f],",FullList[m][n][0],FullList[m][n][1]);
        }
        printf("]\n%f\n##############################################################################",Fitness[m]);
    }

 
 //////////////////////////////////////////////////////////////////////////////////////////////////
 // General //
    printf("\n\n\n\n\n\n\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$\n\n\n\n\n\n");
    quantity=(2*manyparentals)-1;
    coef=0;
    IfMutation=Fitness[0];
    for(int i=0;i<100000;i++){
        PureCromossomeMutation(BaseStructurevoid,FullListvoid,Fitness,CardsStudied,&realcards,&manysites,manyparentals);
        nt=Breeding(BaseStructurevoid,FullListvoid,Fitness,CardsStudied,&realcards,&manysites,manyparentals);
        BasicMutation(BaseStructurevoid,FullListvoid,Fitness,CardsStudied,&realcards,&manysites,nt,mutcoef);
        Sorting(Fitness,ThePositions,FullListvoid,&manycards,CardsStudied,&realcards,nt);
    
        if(Fitness[0]!=IfMutation){
            mutcoef=1;
            coef=-1;
            IfMutation=Fitness[0];
        }
        coef+= 1;
        if((coef>999) &&(coef%1000==0)){
            mutcoef+=1;
        }
    
    }

    //Sorting(Fitness,ThePositions,FullListvoid,&manycards,CardsStudied,&realcards,quantity);


    printf("n\n\nLet's Check this:\n\n\n");
    for(int m=0;m<199;m++){
        printf("\n\n\n#%d:\n[",m);
        for(int n=0;n<110;n++){
            printf("[");   
            printf("[%f;%f],",FullList[m][n][0],FullList[m][n][1]);
            printf("],");
        }
        printf("]\n%f\n##############################################################################",Fitness[m]);
    }

}





/*
[[[27.000000;0.510000],[8.000000;12.240000],[21.000000;2.000000],[23.000000;2.233800],],[[8.000000;12.240000],[21.000000;2.000000],[23.000000;2.233800],[12.000000;2.029800],],]
31.168400

[[[27.000000;0.510000],[8.000000;12.240000],[21.000000;2.000000],[23.000000;2.233800],],[[8.000000;12.240000],[21.000000;2.000000],[23.000000;2.233800],[12.000000;2.029800],],]
39.756001
*/