#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
typedef struct {                      
    int dd;    
    int MM;    
    int yyyy;  
    }date;     

typedef struct {                         
    char *name;      
    char *pren;       
    char *nationality;
    char *position;   
    date date_birth;  
    int length;       
    int nb;           
    }player;


typedef struct {                   
    char *name;     
    char *coach_pr; 
    char *coach_n;  
    char *stadium;  
    int yyyy;       
    int np;         
    player *players;    
    }club;

FILE *file;

 void main(){
    system("cls");
            printf("\n\033[1m**************************Welcome**************************\033[0m\n\n");
                
                        printf("\t\033[32mProjet fait par:\n\n");                        
                        printf("\tEtudiant 1\033[0m:\033[33m\033[1mMOUID ABDELAALI\033[0m\n\n");   
                        printf("\t\033[32mEtudiant 2\033[0m:\033[33m\033[1mOUBELLA ISMAIL\033[0m\n\n");              
                
            printf("\033[1m**********************************************************\033[0m\n");
    void intro();
    intro();
    }

    void intro(){
        int i;
        int n;
        
        void read_clubs(club *, int *);
        void display_club(club *eq);
        void display_clubs(club *, int *);
        void recherche(club *, int *);
        void Modifier(club *, int *);
        void readfile(club *,int *);
        int index_n();

        n=index_n();
        //read_clubs(eq,&n);
        club *eq=(club*)malloc(n*sizeof(club));
        readfile(eq,&n); 
        dir:printf("\n\033[1m**************************Welcom**************************\033[0m\n\n");
                
                        printf("\t\033[32m1:Display all clubs\n\n");                        
                        printf("\t2:Display all clubs with their players\n\n");   
                        printf("\t3:Search for a clubs/player\n\n");              
                        printf("\t4:Edit(Add/Delete) a club/Player\n\n");         
                        printf("\t5:Exit\033[0m\n\n");
                
            printf("\033[1m**********************************************************\033[0m\n");
        scanf("%d",&i);
        switch (i)
        {
        case 5 :system("cls");exit(1);
        case 1 :system("cls");
                for(int j=0; j<n; j++)
                {
                    display_club(eq+j);
                }
                goto dir;break;
        case 2 :system("cls");
                display_clubs(eq,&n);goto dir;
                break;
        case 3 :system("cls");
                recherche(eq,&n);goto dir;
                break;
        case 4 :system("cls");
                Modifier(eq,&n);goto dir;
                break;
        default:
            break;
        }
        free(eq);
    }

    int index_n(){
        int n;
        file=fopen("clubst.txt","r+");
        fscanf(file,"%d",&n);
        fclose(file);
        return n;
    }

    void read_clubs(club *eq, int *n){
        file=fopen("clubst.txt","a+");
        *n=6;
        fprintf(file,"%d\n",*n);
        eq=(club*)malloc(*n*sizeof(club));
        for(int i=0; i<*n; i++)
        {
            (eq+i)->name=malloc(20);
            printf("Name of club : ");gets((eq+i)->name);fprintf(file,"%s\t",(eq+i)->name);
            (eq+i)->coach_pr=malloc(20);
            printf("prName of coach : ");scanf("%s",(eq+i)->coach_pr);fprintf(file,"%s\t",(eq+i)->coach_pr);
            (eq+i)->coach_n=malloc(20);
            printf("Name of coach : ");scanf("%s",(eq+i)->coach_n);fprintf(file,"%s\t",(eq+i)->coach_n);
            (eq+i)->stadium=malloc(20);
            printf("Name of stadiuem : ");scanf("%s",(eq+i)->stadium);fprintf(file,"%s\t",(eq+i)->stadium);
            do{printf("yyyy : ");scanf("%d",&(eq+i)->yyyy);}while((eq+i)->yyyy<=1000 || (eq+i)->yyyy>2030);fprintf(file,"%d\t",(eq+i)->yyyy);
            printf("Number of players : ");scanf("%d",&(eq+i)->np);fprintf(file,"%d\n",(eq+i)->np);
            (eq+i)->players=(player*)malloc(20*sizeof(player));
            for(int j=0; j<(eq+i)->np; j++)
            {
                ((eq+i)->players+j)->pren=malloc(20);
                printf("Pre of player : ");scanf("%s",(((eq+i)->players+j)->pren));fprintf(file,"%s\t",((eq+i)->players+j)->pren);
                ((eq+i)->players+j)->name=malloc(20);
                printf("Name of player : ");scanf("%s",(((eq+i)->players+j)->name));fprintf(file,"%s\t",((eq+i)->players+j)->name);
                ((eq+i)->players+j)->nationality=malloc(20);
                printf("Nationality : ");scanf("%s",(((eq+i)->players+j)->nationality));fprintf(file,"%s\t",((eq+i)->players+j)->nationality);
                ((eq+i)->players+j)->position=malloc(20);
                printf("Position : ");scanf("%s",((eq+i)->players+j)->position);fprintf(file,"%s\t",((eq+i)->players+j)->position);
                printf("Date of Birth (dd/MM/yyyy): \n");
                do{printf("dd : ");scanf("%d",&((eq+i)->players+j)->date_birth.dd);}while(((eq+i)->players+j)->date_birth.dd<=0 || ((eq+i)->players+j)->date_birth.dd>31);fprintf(file,"%d\t",((eq+i)->players+j)->date_birth.dd);
                do{printf("MM : ");scanf("%d",&((eq+i)->players+j)->date_birth.MM);}while(((eq+i)->players+j)->date_birth.MM<=0 || ((eq+i)->players+j)->date_birth.MM>12);fprintf(file,"%d\t",((eq+i)->players+j)->date_birth.MM);
                do{printf("yyyy : ");scanf("%d",&((eq+i)->players+j)->date_birth.yyyy);}while(((eq+i)->players+j)->date_birth.yyyy<=1000 || ((eq+i)->players+j)->date_birth.yyyy>2030);fprintf(file,"%d\t",((eq+i)->players+j)->date_birth.yyyy);
                printf("length : ");scanf("%d",&((eq+i)->players+j)->length);fprintf(file,"%d\t",((eq+i)->players+j)->length);
                printf("Number : ");scanf("%d",&((eq+i)->players+j)->nb);fprintf(file,"%d\n",((eq+i)->players+j)->nb);
            }
            fclose(file);
       }
    }

    void display_clubs(club *eq, int *n){ 
        for(int i=0; i<*n; i++)
        {
            printf("\033[1m\033[35m Name club :\033[0m \033[1m%s\t\033[35mCoach :\033[0m \033[1m%s %s\t\033[35mStadium :\033[0m \033[1m%s\t\033[35myear of creation :\033[0m \033[1m%d\t\033[35mNumber of players :\033[0m \033[1m%d\033[0m\n",(eq+i)->name,(eq+i)->coach_pr,(eq+i)->coach_n,(eq+i)->stadium,(eq+i)->yyyy,(eq+i)->np);
            printf("\n\033[1m\033[34m===========================================================================================================\033[0m\n");
            for(int j=0;j<(eq+i)->np;j++)
            {
                printf("\033[1m\033[36m Name player :\033[0m \033[1m%s %s\t\033[36mNationality :\033[0m \033[1m%s\t\033[36mPosition :\033[0m \033[1m%s\t\033[36mDate :\033[0m\033[1m(%d/%d/%d)\t\033[36mLength :\033[0m \033[1m%d\t\033[36mNumber :\033[0m \033[1m%d\033[0m\n",((eq+i)->players+j)->pren,((eq+i)->players+j)->name,((eq+i)->players+j)->nationality,((eq+i)->players+j)->position,((eq+i)->players+j)->date_birth.dd,((eq+i)->players+j)->date_birth.MM,((eq+i)->players+j)->date_birth.yyyy,((eq+i)->players+j)->length,((eq+i)->players+j)->nb);
            }
            printf("\n\033[1m\033[34m*************************************************************************************************************\033[0m\n");
        }
    }

    void display_club(club *eq){
        printf("\033[1m\033[36mName club :\033[0m \033[1m%s\033[0m\t\033[1m\033[36mCoach :\033[0m \033[1m%s %s\033[0m\t\033[1m\033[36mStadium :\033[0m \033[1m%s\033[0m\t\033[1m\033[36myear of creation :\033[0m \033[1m%d\033[0m\t\033[1m\033[36mNumber of players :\033[0m \033[1m%d\033[0m\n",eq->name,eq->coach_pr,eq->coach_n,eq->stadium,eq->yyyy,eq->np);
    }

    void display_players(club *eq){
        printf("Name club : %s\t",eq->name);
        printf("\n");
        printf("\n\033[1m\033[34m===========================================================================================================\033[0m\n");
        for(int j=0;j<eq->np;j++)
        {
            printf("\033[1m\033[36m Name player :\033[0m \033[1m%s %s\t\033[36mNationality :\033[0m \033[1m%s\t\033[36mPosition :\033[0m \033[1m%s\t\033[36mDate :\033[0m\033[1m(%d/%d/%d)\t\033[36mLength :\033[0m \033[1m%d\t\033[36mNumber :\033[0m \033[1m%d\033[0m\n",(eq->players+j)->pren,(eq->players+j)->name,(eq->players+j)->nationality,(eq->players+j)->position,(eq->players+j)->date_birth.dd,(eq->players+j)->date_birth.MM,(eq->players+j)->date_birth.yyyy,(eq->players+j)->length,(eq->players+j)->nb);
        }
        printf("\n\033[1m\033[34m*************************************************************************************************************\033[0m\n");

    }

    void readfile(club *eq, int *n){
        file=fopen("clubst.txt","r+");
        fscanf(file,"%d",n);
        for(int i=0;i<*n;i++)
        {
            (eq+i)->name=malloc(20);(eq+i)->stadium=malloc(20);(eq+i)->coach_pr=malloc(20);(eq+i)->coach_n=malloc(20);(eq+i)->players=(player*)malloc(20*sizeof(player));
            fscanf(file,"%s%s%s%s%d%d",(eq+i)->name,(eq+i)->coach_pr,(eq+i)->coach_n,(eq+i)->stadium,&(eq+i)->yyyy,&(eq+i)->np);
            
            for(int j=0;j<(eq+i)->np;j++)
            {
                ((eq+i)->players+j)->name=malloc(20);((eq+i)->players+j)->pren=malloc(20);((eq+i)->players+j)->nationality=malloc(20);((eq+i)->players+j)->position=malloc(20);
                fscanf(file,"%s%s%s%s%d%d%d%d%d",((eq+i)->players+j)->pren,((eq+i)->players+j)->name,((eq+i)->players+j)->nationality,((eq+i)->players+j)->position,&((eq+i)->players+j)->date_birth.dd,&((eq+i)->players+j)->date_birth.MM,&((eq+i)->players+j)->date_birth.yyyy,&((eq+i)->players+j)->length,&((eq+i)->players+j)->nb);
            }
        }
        fclose(file);  
    }

    void rempfile(club *eq, int *n){ 
        file=fopen("clubst.txt","w+");
        fprintf(file,"%d\n",*n);
        for(int i=0;i<*n;i++)
        {
            fprintf(file,"%s\t%s %s\t%s\t%d\t%d\n",(eq+i)->name,(eq+i)->coach_pr,(eq+i)->coach_n,(eq+i)->stadium,(eq+i)->yyyy,(eq+i)->np);
            for(int j=0;j<(eq+i)->np;j++)
            {
                fprintf(file,"%s %s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",((eq+i)->players+j)->pren,((eq+i)->players+j)->name,((eq+i)->players+j)->nationality,((eq+i)->players+j)->position,((eq+i)->players+j)->date_birth.dd,((eq+i)->players+j)->date_birth.MM,((eq+i)->players+j)->date_birth.yyyy,((eq+i)->players+j)->length,((eq+i)->players+j)->nb);
            }
        }
        fclose(file); 
    }
    
    void display_player(club *eq, int j){ 
        printf("\n\033[1m\033[34m===========================================================================================================\033[0m\n");
        printf("\033[1m\033[36m Name player :\033[0m \033[1m%s %s\t\033[36mNationality :\033[0m \033[1m%s\t\033[36mClub:\033[0m \033[1m%s\t\033[36mPosition :\033[0m \033[1m%s\t\033[36mDate :\033[0m\033[1m(%d/%d/%d)\t\033[36mLength :\033[0m \033[1m%d\t\033[36mNumber :\033[0m \033[1m%d\033[0m\n",(eq->players+j)->pren,(eq->players+j)->name,(eq->players+j)->nationality,eq->name,(eq->players+j)->position,(eq->players+j)->date_birth.dd,(eq->players+j)->date_birth.MM,(eq->players+j)->date_birth.yyyy,(eq->players+j)->length,(eq->players+j)->nb);
        printf("\n\033[1m\033[34m*************************************************************************************************************\033[0m\n");
    }
    
    void Modifier(club *eq, int *n){
        int b,k=0;
        int i,j;
        char *ptr=malloc(20);
        void add_club(club *, int *);
        void rempfile(club *, int *);
        void add_player(club *, int *);

            debut:printf("\n\033[1m**************************Edit**************************\033[0m\n\n");
                
                        printf("\t\033[32m1:Supprimer un club\n\n");                        
                        printf("\t2:Supprimer un joueur\n\n");   
                        printf("\t3:Ajouter un club\n\n");  
                        printf("\t4:Ajouter un joueur \n\n");
                        printf("\t5:Quitter le programme\033[0m\n\n");            
                
            printf("\033[1m**********************************************************\033[0m\n");
        scanf("%d",&b);
        switch(b)
        {
            case 5 :system("cls");break;
            case 1 :system("cls");
                    printf("Donnez le nom de club :\t");scanf("%s",ptr);
                    for(i=0; i<*n; i++)
                    {
                        if(strcmp((eq+i)->name,ptr)==0)
                        {
                            printf("\n",k++);
                            break;
                        } 
                    }
                    if(k==0){printf("\nClub not founded \n");goto debut;}
                    for(int j=i;j<*n;j++)
                    {
                        *(eq+j)=*(eq+j+1);
                    }
                    (*n)--;
                    rempfile(eq,n);break;
            case 2 :system("cls");
                    printf("Donnez le nom de joueur :\t");scanf("%s",ptr);
                    for(i=0; i<*n; i++)
                    {
                        for(j=0;j<(eq+i)->np;j++)
                        {
                            if(strcmp(((eq+i)->players+j)->name,ptr)==0)
                            {
                                printf("\n",k++);
                                break;
                            }
                        }
                        if(k==1){break;}
                    }
                    if(k==0){printf("\nPlayer not founded \n");goto debut;}

                    for(int z=j;z<(eq+i)->np;z++)
                    {
                        *((eq+i)->players+j)=*((eq+i)->players+j+1);
                    }
                    ((eq+i)->np)--;
                    printf("%d",(eq+i)->np);
                    rempfile(eq,n);
                    break;       
            case 3 :system("cls");
                    (*n)++;
                    eq=(club*)realloc(eq,(*n)*sizeof(club));
                    add_club(eq+*n-1,n);
                    rempfile(eq,n);
                    printf("\nIf you want to add players go back to the menu\n");
                    break;
            case 4 :system("cls");
                    add_player(eq,n);
                    break;
            default :printf("erreur!");
        }
    }

    void add_club(club *eq, int *n){
        char *ptr=malloc(20);
        printf("Donnez le nom de nouvel club :\t");scanf("%s",ptr);
        eq->name=malloc(20);
        strcpy(eq->name,ptr);
        eq->coach_pr=malloc(20);
        printf("prName of coach : ");scanf("%s",eq->coach_pr);
        eq->coach_n=malloc(20);
        printf("Name of coach : ");scanf("%s",eq->coach_n);
        eq->stadium=malloc(20);
        printf("Name of stadiuem : ");scanf("%s",eq->stadium);
        do{printf("yyyy : ");scanf("%d",&eq->yyyy);}while(eq->yyyy<=1000 || eq->yyyy>2030);
        eq->np=0;
    }

    void add_player(club *eq, int *n){
        int x;
        void rempfile(club *, int *);
        char *ptr=malloc(20);
        printf("\nHow many player do you want to add ?\t");scanf("%d",&x);
        printf("\nTo wich club ?\t");scanf("%s",ptr);
        for(int i=0; i<*n;i++)
        {
            if(strcmp((eq+i)->name,ptr)==0)
            {
                int y=(eq+i)->np;
                (eq+i)->np+=x;
                for(int j=y;j<(eq+i)->np;j++)
                {
                    ((eq+i)->players+j)->pren=malloc(20);
                    printf("Pre of player : ");scanf("%s",(((eq+i)->players+j)->pren));
                    ((eq+i)->players+j)->name=malloc(20);
                    printf("Name of player : ");scanf("%s",(((eq+i)->players+j)->name));
                    ((eq+i)->players+j)->nationality=malloc(20);
                    printf("Nationality : ");scanf("%s",(((eq+i)->players+j)->nationality));
                    ((eq+i)->players+j)->position=malloc(20);
                    printf("Position : ");scanf("%s",((eq+i)->players+j)->position);
                    printf("Date of Birth (dd/MM/yyyy): \n");
                    do{printf("dd : ");scanf("%d",&((eq+i)->players+j)->date_birth.dd);}while(((eq+i)->players+j)->date_birth.dd<=0 || ((eq+i)->players+j)->date_birth.dd>31);
                    do{printf("MM : ");scanf("%d",&((eq+i)->players+j)->date_birth.MM);}while(((eq+i)->players+j)->date_birth.MM<=0 || ((eq+i)->players+j)->date_birth.MM>12);
                    do{printf("yyyy : ");scanf("%d",&((eq+i)->players+j)->date_birth.yyyy);}while(((eq+i)->players+j)->date_birth.yyyy<=1000 || ((eq+i)->players+j)->date_birth.yyyy>2030);
                    printf("length : ");scanf("%d",&((eq+i)->players+j)->length);
                    printf("Number : ");scanf("%d",&((eq+i)->players+j)->nb);
                }
            }
        }
        rempfile(eq,n);
    }

    void recherche(club *eq, int *n){ 
        int b,k=0;
        char *ptr=malloc(20);
        void display_players(club *);
        void display_player(club *, int );
        void display_coach(club *);
        void display_club(club *);
            debut:printf("\n\033[1m**************************Research**************************\033[0m\n\n");
                
                        printf("\t\033[32m1:Chercher par nom de club\n\n");                        
                        printf("\t2:chercher par nom de joueur\n\n");   
                        printf("\t3:Quitter le programme\033[0m\n\n");              
                
            printf("\033[1m**********************************************************\033[0m\n");
        scanf("%d",&b);
        switch(b)
        {
            case 3 :system("cls");
                    break;
            case 1 :system("cls");
                    printf("Donnez le nom de club :\t");scanf("%s",ptr);
                    for(int i=0; i<*n; i++)
                    {
                        if(strcmp((eq+i)->name,ptr)==0)
                        {
                            printf("\n",k++);
                            display_club(eq+i);
                            printf("do you want to see players of this club :\n");
                            printf("0:Non\n");
                            printf("1:Oui \n");
                            scanf("%d",&b);
                            if(b==1)
                                display_players(eq+i);
                            else
                                exit(1);
                            break;
                        } 
                    }
                    if(k==0){printf("\nClub not founded \n");goto debut;}
                    break;
            case 2 :system("cls");
                    printf("Donnez le nom de joueur :\t");scanf("%s",ptr);
                    for(int i=0; i<*n; i++)
                    {
                        for(int j=0;j<(eq+i)->np;j++)
                        {
                            if(strcmp(((eq+i)->players+j)->name,ptr)==0)
                            {
                                printf("\n",k++);
                               display_player(eq+i,j);
                                break;
                            }
                        }
                    }
                    if(k==0){printf("\nPlayer not founded \n");goto debut;}
                    break;           
            default : printf("\nereur!\n");free(ptr);goto debut;
        }
    }
