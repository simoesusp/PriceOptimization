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

void PrintBase(float ***BaseStructure,int manysites,int realcards, int *CardsStudied){
    for(int i=0;i<manysites;i++){
        printf("%d:",i);
        for(int j=0;j<realcards+1;j++){
            printf("[");
            for(int k=0;k<CardsStudied[j];k++){
                printf("%f ",BaseStructure[i][j][k]);
            }
            printf("]\t");
        }
        printf("\n###\n");
    }
    printf("\n\n##############\n\n");
}

void PrintList(float ***FullList,float *Fitness,int manyparentals,int manycards){
    for(int m=0;m<manyparentals;m++){
        printf("\n\n\n#%d:\n[",m);
        for(int n=0;n<manycards;n++){
            printf("[");   
            printf("[%f;%f],",FullList[m][n][0],FullList[m][n][1]);
            printf("],");
        }
        printf("]\n%f\n##############################################################################",Fitness[m]);
    }
}

void FreeForAll(float ***BaseStructure, float ***FullList, float *Fitness, float ***FullList2, float *Fitness2, float ***FullList3, float *Fitness3, int *CardsStudied,int realcards,int manysites,int manyparentals,int manycards){
    for(int i=0;i<manysites;i++){
        for(int j=0;j<realcards;j++){
            free(BaseStructure[i][j]);
        }
        free(BaseStructure[i]);
    }
    free(CardsStudied);
    free(BaseStructure);
    for(int i=0;i<manyparentals;i++){
        for(int j=0;j<manycards;j++){
            free(FullList[i][j]);
            free(FullList2[i][j]);
            free(FullList3[i][j]);
        }
        free(FullList[i]);
        free(FullList2[i]);
        free(FullList3[i]);
    }

    free(Fitness);
    free(Fitness2);        
    free(Fitness3);        
    free(FullList);
    free(FullList2);
    free(FullList3);
}