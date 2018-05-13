#include "preprocessors.h"//calling for all constants that are common in the entire program
int welcome();
int create_acc();
int  quiting();
void   choose_acc();
int   read_me();
int   load_data();
void  display();
void save_data();
void errors(int error_number);
int key_check(char *temp1, char *temp2);

int welcome()
{
    number_of_players=load_data();

    system("cls");//clearing screen
    printf("\n\n\t\t--------->>> DEMO <<<<----------\n");
    printf("\n\t\t     Create a Player Account\n");
    printf("\n\t\t      Choose Player Account\n");
    printf("\n\t\t            Read ME\n");
    printf("\n\t\t              Quit        \n\n\t\t\t        ");

    choice=getch();//waiting for choice from the user

    if(choice=='W' || choice=='w')
    {
        quiting();
        return 0;
    }
    else if(choice=='S' || choice=='s')
    {
        create_acc();
        return 0;
    }
    else if(choice==13)
    {

        questions_func();
        srand(time(NULL));
        for(k=0; k<15; k++)
        {
HERE:
            system("cls");
            printf("+-----------------------------------+");
            printf("\n|            DEMO PLAYER            |");
            printf("\n|            -----------            |");
            printf("\n+-----------------------------------+");

            r=rand()%100;
            printf("\n\n%s",question[r].qn);
            printf("\n  Ans. 1 %s",question[r].opt[0]);
            printf("\n  Ans. 2 %s",question[r].opt[1]);
            printf("\n  Ans. 3 %s",question[r].opt[2]);
            printf("\n  Ans. 4 %s\n\t\t  ",question[r].opt[3]);
            do
            {
                choice=getch();
            }
            while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 27);

            if(choice==27)
            {
                welcome();
                return;
            }

            if((choice==question[r].correct_ans))
            {
                system("cls");
                system("COLOR A");
                printf("+---------------------------------+");
                printf("\n|             PERFECT!            |");
                printf("\n|            ----------           |");
                printf("\n+---------------------------------+");
                printf("\n\n%s\n\n\t\t  ",question[r].opt[4]);
                choice=getche();
                system("COLOR 7");
            }
            else
            {
                system("cls");
                system("COLOR C");
                printf("+---------------------------------+");
                printf("\n|              OOooops            |");
                printf("\n|            ----------           |");
                printf("\n+---------------------------------+");
                printf("\n\n%s\n\n\t\t  ",question[r].opt[4]);
                choice=getche();
                system("COLOR 7");
            }

        }
        system("cls");

        printf("\n\n  Trial Chances are over.\n   a player account to proceed.\n\t\t ");
        choice=getch();
        welcome();
        return;
    }

    else welcome();
    return;

}


int create_acc()
{
START2:
    number_of_players = load_data();
    system("cls");//clearing screen

    printf("\n\n\t\t             Demo\n");
    printf("\n\t      --->>> CREATE A PLAYER ACCOUNT <<<---\n");
    printf("\n\t              Choose Player Account\n");
    printf("\n\t\t            Read ME\n");
    printf("\n\t\t              Quit         \n\n\t\t\t        ");

    choice=getch();//waiting for choice from the user

    if(choice=='W' || choice=='w')
    {
        welcome();
        return 0;
    }
    else if(choice=='S' || choice=='s')
    {
        choose_acc();
        return 0;
    }
    else if(choice==13)
    {
//NOW CREATING A PLAYER IN CASE THE USER PRSSES ENTER
        system("cls");
        printf("+---------------------------------+");
        printf("\n|   CREATING PLAYERS' ACCOUNTS    |");
        printf("\n|   --------------------------    |");
        printf("\n+---------------------------------+");


        player[number_of_players].display=1;
        fflush(stdin);
        printf("\n\n  PLAYER's NAME    :  ");



        fflush(stdin);
        gets(player[number_of_players].name);
        printf("  PLAYER's AGE     :   ");
        gets(temp_age);
        player[number_of_players].age=0;
        player[number_of_players].age = convert_str_to_int(temp_age);

        if(player[number_of_players].age<=2 || player[number_of_players].age >=100 )
        {
            errors(1);
        }

        while(1)
        {
            printf("\nWould you like to protect this account with a Key?\ntEnter 'Y' or 'y' for yes OR any key for no: ");
            choice=getch();
            if(choice=='y' || choice=='Y')
            {
                int m=0,q=0;
HERE:
                system("cls");
                fflush(stdin);
                printf("+---------------------------------+");
                printf("\n|   CREATING PLAYERS' ACCOUNTS    |");
                printf("\n|   --------------------------    |");
                printf("\n+---------------------------------+");


                printf("\n\n  PLAYER's NAME    :  ");
                puts(player[number_of_players].name);
                fflush(stdin);
                printf("  PLAYER's AGE     :  ");
                printf("%d",player[number_of_players].age);
                fflush(stdin);
                printf("\n  ENTER SECRET KEY :  ");

                if(l==100)
                {
                    for(q=0; q<m; q++)
                        printf("*"); //choice=getch();
                    l=0;
                }

                for(; m<25;)
                {
                    player[number_of_players].key[m]=getch();
                    if(player[number_of_players].key[m]==8)
                    {
                        if(m>0)
                            m--;
                        l=100;
                        goto HERE;
                    }
                    printf("*");
                    if(player[number_of_players].key[m]==13)
                    {
                        player[number_of_players].key[m]='\0';
                        //puts(player[number_of_players].key);
                        //choice=getch();
                        break;
                    }
                    m++;
                }

                fflush(stdin);
                for(k=0; k<1000; k++)
                {
                    player[number_of_players].questions_answered[k]=0;
                }
                player[number_of_players].points=0;



                save_data();///calling a function to update data
                printf("\n\n ACCOUNT CREATED SUCCESSFULLY");
                printf("\n YOUR SECRET KEY IS:  [ %s ]\n\n\t\t  ",player[number_of_players].key);
                choice=getch();
                goto START2;
            }
            else
            {
                for(k=0; k<1000; k++)
                {
                    player[number_of_players].questions_answered[k]=0;
                }
                player[number_of_players].display=1;
                player[number_of_players].points=0;
                save_data();///calling a function to update data
                load_data();

                player[number_of_players].display=1;
                printf("\nACCOUNT CREATED SUCCESSFULLY\n\n\t\t  ");
                choice=getch();
                goto START2;
            }
        }


    }
    else create_acc();
    return 0;

}

void   choose_acc()
{

    system("cls");//clearing screen

    printf("\n\n\t\t             Demo\n");
    printf("\n\t\t     Create a Player Account\n");
    printf("\n\t\t--->> CHOOSE PLAYER ACCOUNT <<---\n");
    printf("\n\t\t            Read ME\n");
    printf("\n\t\t              Quit         \n\n\t\t\t        ");

    choice=getch();//waiting for choice from the user

    if(choice=='W' || choice=='w')
    {
        create_acc();
        return ;
    }
    else if(choice=='S' || choice=='s')
    {
        read_me();
        return ;
    }
    else if(choice==13)
    {
        system("cls");
        printf("+-----------------------------------+");
        printf("\n|        PLAYERS' ACCOUNTS          |");
        printf("\n|        -----------------          |");
        // printf("\n|                                       |");
        printf("\n+-----------------------------------+");
        display();

        if(number_of_players<1)
        {
            choice=getche();
            welcome();
            return;
        }
        scanf("%s",temp_age);
        k=convert_str_to_int(temp_age);
        k=k-1;

        if(k>number_of_players-1 || player[k].display==0)
        {
            errors(3);
            welcome();
            return;
        }
        else if(strlen(player[k].key)>=1)
        {
            system("cls");

            printf("+------------------------------------+");
            printf("\n|           AUNTHENTICATION          |");
            printf("\n|          -----------------         |");
            printf("\n+------------------------------------+");
            printf("\n\nHello %s,\nYour Account is protected by a secret key.\n\nENTER YOUR SECRET :  ",player[k].name);



///----

            int m=0,q=0,l=0;
HERE2:

            if(l==100)
            {
                system("cls");

                printf("+------------------------------------+");
                printf("\n|           AUNTHENTICATION          |");
                printf("\n|          -----------------         |");
                printf("\n+------------------------------------+");
                printf("\n\nHello %s,\nYour Account is protected by a secret key.\n\nENTER YOUR SECRET :  ",player[k].name);


                for(q=0; q<m; q++)
                    printf("*"); //choice=getch();
                l=0;
            }

            for(; m<25;)
            {
                temp_age[m]=getch();
                if( temp_age[m]==8)
                {
                    if(m>0)
                        m--;
                    l=100;
                    goto HERE2;
                }
                printf("*");
                if( temp_age[m]==13)
                {
                    temp_age[m]='\0';
                    break;
                }
                m++;
            }
            ///----
            char *temp1, *temp2;
            temp1 = temp_age;
            temp2 = player[k].key;

            if(key_check(temp1, temp2)==1)
            {
                temp1=NULL;
                temp2=NULL;
                game_menu();
                logged_in_id=k;
                welcome();
            }
            else
            {
                errors(2);
                choose_acc();
            }
        }
        else
        {
            game_menu(k);
            welcome();
        }

    }
    else choose_acc();

}

int  read_me()
{

    system("cls");//clearing screen

    printf("\n\n\t\t             Demo\n");
    printf("\n\t\t     Create a Player Account\n");
    printf("\n\t\t      Choose Player Account\n");
    printf("\n\t\t  ------>>> READ ME <<<------- \n");
    printf("\n\t\t              Quit        \n\n\t\t\t        ");

    choice=getch();//waiting for choice from the user

    if(choice=='W' || choice=='w')
    {
        choose_acc();
        return 0;
    }

    else if(choice=='S' || choice=='s')
    {
        quiting();
        return 0;
    }
    else if(choice==13)
    {
        system("cls");
        printf("+-----------------------------------+");
        printf("\n|            HELP TIPS              |");
        printf("\n|           -----------             |");
        printf("\n+-----------------------------------+");

        printf("\n\n 1. --> Press 'ESC' key to go back");
        printf("\n\n 2. --> Press 'W' or 'S' key to navigate up or down respectively");
        printf("\n\n 3. --> For some options, Enter a corresponding number to select an option");
        printf("\n\n 4. --> The faster you chose a correct answer, the higher the points you gain");
        printf("\n\n 5. --> A wrong answer leads to loss of mark.");
        printf("\n\n 6. --> The game does not store records for DEMO player account.\n\n\t\t  ");

        choice=getch();
        welcome();
        return;
    }
    else read_me();
    return;
}


int quiting()
{

    system("cls");//clearing screen

    printf("\n\n\t\t             Demo\n");
    printf("\n\t\t     Create a Player Account\n");
    printf("\n\t\t      Choose Player Account\n");
    printf("\n\t\t            Read ME\n");
    printf("\n\t\t  ------->>>> QUIT <<<<-------\n\n\t\t\t        ");

    choice=getch();//waiting for choice from the user
    if(choice=='W' || choice=='w')
    {
        read_me();
        return 0;
    }

    else if(choice=='S' || choice=='s')
    {
        welcome();
        return 0;
    }
    else if(choice==13)
    {
        system("cls");
        printf("\n   Are you sure you want to quit the game? ");
        printf("\n  Enter Y or 'y' for yes. or any key for No.");
        printf("\n\n\t\t   ");
        choice = getch();
        if(choice=='y' || choice=='Y')
        {
            system("cls");
            printf("\n\t\t GOOD BYE.\n\n");
            choice=getche();
            exit(1);
            return 0;
        }
        else if(choice=='N' || choice=='n')
        {
            welcome();
            return 0;
        }
        else quiting();
        return 0;
    }

}


void display()
{
    printf("\n ____________________________________");
    printf("\n|                                    |");
    int pk=0;
    number_of_players = load_data();
    for(i=0; i<number_of_players; i++)
    {
        if(player[i].display==1)
        {
            pk=1;
            printf("%\n  PLAYER %d: [ %s ]",i+1,player[i].name); //printf("\t\t%s  ",player[i].key);
        }

    }

    if(number_of_players<1 || pk==0)
    {
        printf("\n\nList empty. Create at least one account.\n\n\t\t  ");
    }
    else
    {
        printf("\n|____________________________________|");
        printf("\n\n  Enter a number that corresponds \n  with your player account:  ");
    }

}


void save_data()
{
    FILE *fpt_players_save; //file pointer for the player
    fpt_players_save=fopen("players_data.txt","w");
    fwrite(player,sizeof(player), 1,fpt_players_save);
    fclose(fpt_players_save);
}

int load_data()
{
    FILE *fpt_players_load; //file pointer for the player

    fflush(stdin);
    fpt_players_load=fopen("players_data.txt","r");
    fread(player,sizeof(player),1,fpt_players_load);
    fclose(fpt_players_load);

    number_of_players=0;

    for(i=0; i<=100; i++)
    {
        if(strlen(player[i].name)>1)
        {
            number_of_players++;
        }
        else break;
    }

    for(r=0; r<100; r++)
    {

        if(player[logged_in_id].questions_answered[r]==0)
        {
            no_qn=r;
            break;
        }
    }

//    system("cls");
//    printf("%d",number_of_players);
//    choice=getch();

    return number_of_players;
}

int convert_str_to_int(char h[6])
{
    k= (int)(h[0]);
    k=k-48;
    if((int)(h[1])>=48)
    {
        l=(int)(h[1]);
        l=l-48;
        k=k*10;
        k=l+k;
    }

    return k;
}


void errors(int error_number)
{
    if(error_number==1)
    {
        system("cls");
        system("COLOR C");
        system("cls");
        printf("+-----------------------------------+");
        printf("\n|           ERROR OCCURED            |");
        printf("\n|        ------------------          |");
        printf("\n+-----------------------------------+");

        printf("\a\n\n  Sorry This game does not support people of your age.\n\n\t\t\t");
        choice = getche();
        system("COLOR 7");
        welcome();

        /*0 = Black       8 = Gray
        1 = Blue        9 = Light Blue
        2 = Green       A = Light Green
        3 = Aqua        B = Light Aqua
        4 = Red         C = Light Red
        5 = Purple      D = Light Purple
        6 = Yellow      E = Light Yellow
        7 = White       F = Bright White*/

    }
    else if(error_number==2)
    {
        system("cls");
        system("COLOR C");
        printf("+-----------------------------------+");
        printf("\n|           ERROR OCCURED           |");
        printf("\n|        ------------------         |");
        printf("\n+-----------------------------------+");
        printf("\a\n\n  You entered a wrong secret key.\n  Please select Your own player account \n  and TRY again.\n\n\t\t   ");
        choice = getche();
        system("COLOR 7");
        choose_acc();
    }

    else if(error_number==3)
    {
        system("cls");
        system("COLOR C");
        printf("+-----------------------------------+");
        printf("\n|           ERROR OCCURED            |");
        printf("\n|        ------------------          |");
        printf("\n+-----------------------------------+");
        printf("\a\n\n  The account you selected does not exist\n  Please create Your own player account\n  and TRY again.\n\n\t\t   ");
        choice = getche();
        system("COLOR 7");
        create_acc();
    }
}

int key_check(char *temp1, char *temp2)
{
    int i=0,j;
    if(strlen(temp1)!=strlen(temp2))
    {
        return 0;
    }
    else
    {
        for(i=0; i<strlen(temp1); i++)
        {
            if(temp1[i]!=temp2[i])
            {
                j=0;
                break;
            }
            else
            {
                j=1;
                break;
            }
            temp1++;
            temp2++;
        }
        return j;
    }
}


void questions_func();

void questions_func()
{

    strcpy(question[i].category,"alphabets");
    question[i].level=2;
    strcpy(question[i].qn,"How many letters does Hawaiian alphabets have?");
    strcpy(question[i].opt[0],"21 letters.");
    strcpy(question[i].opt[1],"18 letters.");
    strcpy(question[i].opt[2],"13 letters.");
    strcpy(question[i].opt[3],"42 letters.");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"The Hawaiian alphabets have 13 letters.");


    strcpy(question[i].category,"alphabets");
    question[i].level=1;
    strcpy(question[i].qn,"Which of the following Sentences has all English Alphabets?");
    strcpy(question[i].opt[0],"the quick brown fox jumps over the lazy dog.");
    strcpy(question[i].opt[1],"The world is most wonderful place for ever.");
    strcpy(question[i].opt[2],"the quick brown fox jumps over the lazy boy.");
    strcpy(question[i].opt[3],"Non of the above.");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4]," the sentence \"the quick brown fox jumps over the lazy dog uses every letter in the English alphabet.\"");

    strcpy(question[i].category,"alphabets");
    question[i].level=3;
    strcpy(question[i].qn,"Which Alphabet has two syllables?");
    strcpy(question[i].opt[0],"M");
    strcpy(question[i].opt[1],"W");
    strcpy(question[i].opt[2],"Q");
    strcpy(question[i].opt[3],"X");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"the letter W is the only letter in the alphabet that has 3 syllables (all others have 1)");

    strcpy(question[i].category,"alphabets");
    question[i].level=3;
    strcpy(question[i].qn,"______Is written as 1 out 8 letters?");
    strcpy(question[i].opt[0],"E");
    strcpy(question[i].opt[1],"e");
    strcpy(question[i].opt[2],"F");
    strcpy(question[i].opt[3],"A");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"1 out of every 8 letters written is an \"e\"");

    strcpy(question[i].category,"alphabets");
    question[i].level=2;
    strcpy(question[i].qn,"How many letters does Cambodian alphabet have?");
    strcpy(question[i].opt[0],"78 letters.");
    strcpy(question[i].opt[1],"18 letters.");
    strcpy(question[i].opt[2],"13 letters.");
    strcpy(question[i].opt[3],"42 letters.");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"The Cambodian alphabet have 74 letters.");

///ANIMALS CATEGORY
    i=4;
    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"How many teeth does a beer have?");
    strcpy(question[i].opt[0],"52.");
    strcpy(question[i].opt[1],"32.");
    strcpy(question[i].opt[2],"46.");
    strcpy(question[i].opt[3],"42.");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"a bear has 42 teeth.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"The eye of ___________ is bigger thank its brain.");
    strcpy(question[i].opt[0],"an ostrich");
    strcpy(question[i].opt[1],"a fish");
    strcpy(question[i].opt[2],"a man");
    strcpy(question[i].opt[3],"a hen");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"an ostrich's eye is bigger than its brain");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"Which of the following animals needs gravity force to swallow.");
    strcpy(question[i].opt[0],"Human beings");
    strcpy(question[i].opt[1],"goats");
    strcpy(question[i].opt[2],"fish");
    strcpy(question[i].opt[3],"birds");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"Birds need gravity to swallow.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"How many muscles does a cat have in each ear?");
    strcpy(question[i].opt[0],"46 muscles");
    strcpy(question[i].opt[1],"32 muscles");
    strcpy(question[i].opt[2],"56 muscles");
    strcpy(question[i].opt[3],"58 muscles");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"a cat has 32 muscles in each ear.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"Which of the following fish can see both infrared and ultraviolet light?");
    strcpy(question[i].opt[0],"Silk fish");
    strcpy(question[i].opt[1],"Tilapia fish");
    strcpy(question[i].opt[2],"Gold fish");
    strcpy(question[i].opt[3],"Cat fish");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"a goldfish can see both infrared and ultraviolet light.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"What percentage does a cat spend sleeping in their life?");
    strcpy(question[i].opt[0],"20%%");
    strcpy(question[i].opt[1],"66%%");
    strcpy(question[i].opt[2],"80%%");
    strcpy(question[i].opt[3],"30%%");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"cats spend 66% of their life asleep.");


    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"Which of the following nuts are toxic to dogs?");
    strcpy(question[i].opt[0],"Ground nuts");
    strcpy(question[i].opt[1],"Macadamica nuts");
    strcpy(question[i].opt[2],"Coco nuts");
    strcpy(question[i].opt[3],"none of the above");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"macadamia nuts are toxic to dogs.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"Spiders are in a category of ____________.");
    strcpy(question[i].opt[0],"Arachnids");
    strcpy(question[i].opt[1],"insects");
    strcpy(question[i].opt[2],"Arthropods");
    strcpy(question[i].opt[3],"none of the above");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"spiders are arachnids and not insects.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"Which of the following animal sleeps 18 hours a day.");
    strcpy(question[i].opt[0],"Rabbit");
    strcpy(question[i].opt[1],"Dogs");
    strcpy(question[i].opt[2],"Cats");
    strcpy(question[i].opt[3],"Koala");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"Koalas sleep around 18 hours a day.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"How many pairs of legs do insects have?");
    strcpy(question[i].opt[0],"4");
    strcpy(question[i].opt[1],"2");
    strcpy(question[i].opt[2],"6");
    strcpy(question[i].opt[3],"3");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"all insects have 6 legs");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"Which animal has tongue that is long enough to rich its ear?");
    strcpy(question[i].opt[0],"Giraffe");
    strcpy(question[i].opt[1],"Buffalo");
    strcpy(question[i].opt[2],"Lion");
    strcpy(question[i].opt[3],"Elephant");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"a giraffe can clean its ears with its 21 inch tongue");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"Which of the following animals can't swallow with their eyes open?");
    strcpy(question[i].opt[0],"A frog");
    strcpy(question[i].opt[1],"A man");
    strcpy(question[i].opt[2],"A duck");
    strcpy(question[i].opt[3],"A hen");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"frogs can't swallow with their eyes open.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"Among all mammals, which one of these can't jump?");
    strcpy(question[i].opt[0],"A frog");
    strcpy(question[i].opt[1],"An Elephant");
    strcpy(question[i].opt[2],"A goat");
    strcpy(question[i].opt[3],"A bat");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"elephants are the only mammal that can't jump.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"A________can't walk without bobbing its head");
    strcpy(question[i].opt[0],"duck");
    strcpy(question[i].opt[1],"sheep");
    strcpy(question[i].opt[2],"man");
    strcpy(question[i].opt[3],"dog");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"a duck can't walk without bobbing its head.");


    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"Which animal has killed more people in Africa than any other animal?");
    strcpy(question[i].opt[0],"Lion");
    strcpy(question[i].opt[1],"Elephant");
    strcpy(question[i].opt[2],"Leopard");
    strcpy(question[i].opt[3],"Hippopotamus");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"hippopotamuses have killed more people in Africa than any other animal.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"Which animal does not have upper front teeth?");
    strcpy(question[i].opt[0],"Goat");
    strcpy(question[i].opt[1],"Cow");
    strcpy(question[i].opt[2],"Leopard");
    strcpy(question[i].opt[3],"Sheep");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"cows don't have upper front teeth.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"Which of the following animal has a rectangular pupil?");
    strcpy(question[i].opt[0],"Crocodile");
    strcpy(question[i].opt[1],"Cow");
    strcpy(question[i].opt[2],"Octopus");
    strcpy(question[i].opt[3],"Lion");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"an octopus pupil is rectangular.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=1;
    strcpy(question[i].qn,"Which of the following animals can't move their jaws side by side?");
    strcpy(question[i].opt[0],"A camel");
    strcpy(question[i].opt[1],"Cow");
    strcpy(question[i].opt[2],"a cat");
    strcpy(question[i].opt[3],"An elephant");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"cats can't move their jaw sideways.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"A group of frogs id called___________.");
    strcpy(question[i].opt[0],"An army");
    strcpy(question[i].opt[1],"Crowd");
    strcpy(question[i].opt[2],"a hard");
    strcpy(question[i].opt[3],"None of the above");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"a group of frogs is called an army.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"A group of rhinos id called___________.");
    strcpy(question[i].opt[0],"An army");
    strcpy(question[i].opt[1],"Crowd");
    strcpy(question[i].opt[2],"a hard");
    strcpy(question[i].opt[3],"a crash");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"a group of rhinos is called a crash.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"Who invented a cat door?");
    strcpy(question[i].opt[0],"Isaac Newton");
    strcpy(question[i].opt[1],"Peter Norton");
    strcpy(question[i].opt[2],"A.B Johnathan");
    strcpy(question[i].opt[3],"None of the above");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"Isaac Newton invented the cat door.");


    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"What is lifespan of a squirrel?");
    strcpy(question[i].opt[0],"40 years");
    strcpy(question[i].opt[1],"27 years");
    strcpy(question[i].opt[2],"9 years");
    strcpy(question[i].opt[3],"20 years");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"the lifespan of a squirrel is 9 years.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"Can a giraffe go longer than a camel,...");
    strcpy(question[i].opt[0],"No, camel goes longer than a giraffe");
    strcpy(question[i].opt[1],"Yes, giraffe goes longer than a camel");
    strcpy(question[i].opt[2],"No, They both go the same distance");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"a giraffe can go longer without water than a camel.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=2;
    strcpy(question[i].qn,"There are more chickens than people,...");
    strcpy(question[i].opt[0],"No, people are more than a chicken");
    strcpy(question[i].opt[1],"Yes, there are more chickens than people");
    strcpy(question[i].opt[2],"No, they both have same population");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"there are more chickens than people.");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"What is maximum speed of a dolphin?");
    strcpy(question[i].opt[0],"60km/hr");
    strcpy(question[i].opt[1],"10Km/hr");
    strcpy(question[i].opt[2],"100Km/hr");
    strcpy(question[i].opt[3],"200Km/hr");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"a dolphins top speed is 60kmh (37mph).");

    i++;
    strcpy(question[i].category,"animals");
    question[i].level=3;
    strcpy(question[i].qn,"What is maximum speed of a shark?");
    strcpy(question[i].opt[0],"60km/hr");
    strcpy(question[i].opt[1],"100Km/hr");
    strcpy(question[i].opt[2],"70Km/hr");
    strcpy(question[i].opt[3],"200Km/hr");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"a sharks top speed is 70kmh (44mph).");

///Average questions
    i++;
    strcpy(question[i].category,"average");
    question[i].level=1;
    strcpy(question[i].qn,"What is the average time that a normal man falls asleep in?");
    strcpy(question[i].opt[0],"20 minutes");
    strcpy(question[i].opt[1],"7 minutes");
    strcpy(question[i].opt[2],"30 minutes");
    strcpy(question[i].opt[3],"2 minutes");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"The average person falls asleep in 7.");

    i++;
    strcpy(question[i].category,"average");
    question[i].level=1;
    strcpy(question[i].qn,"What is the average percentage of water does human contain?");
    strcpy(question[i].opt[0],"20%%");
    strcpy(question[i].opt[1],"50%%");
    strcpy(question[i].opt[2],"30%%");
    strcpy(question[i].opt[3],"78%%");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"The average human brain contains around 78% water.");

    i++;
    strcpy(question[i].category,"average");
    question[i].level=1;
    strcpy(question[i].qn,"How many times does an average person laugh per day?");
    strcpy(question[i].opt[0],"50 times");
    strcpy(question[i].opt[1],"90 times ");
    strcpy(question[i].opt[2],"10 times");
    strcpy(question[i].opt[3],"70 times");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4]," the average person laughs 10 times a day.");

    i++;
    strcpy(question[i].category,"average");
    question[i].level=1;
    strcpy(question[i].qn,"What is the average lifespan of a mosquito?");
    strcpy(question[i].opt[0],"3 weeks");
    strcpy(question[i].opt[1],"2 weeks");
    strcpy(question[i].opt[2],"2 days");
    strcpy(question[i].opt[3],"1 month");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4]," the average life span of a mosquito is 2 weeks");

    i++;
    strcpy(question[i].category,"average");
    question[i].level=1;
    strcpy(question[i].qn,"What is the average weight of skin a person shades off in a year?");
    strcpy(question[i].opt[0],"3Kg");
    strcpy(question[i].opt[1],"20Kg");
    strcpy(question[i].opt[2],"250g");
    strcpy(question[i].opt[3],"700g");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"The average person sheds .7kg (1.5 pounds) of skin each year");

    ///BRANDS
    i++;
    strcpy(question[i].category,"brands");
    question[i].level=2;
    strcpy(question[i].qn,"Which of the following carbonated drinks originally contained cocaine?");
    strcpy(question[i].opt[0],"Mirinda");
    strcpy(question[i].opt[1],"Coca-cola");
    strcpy(question[i].opt[2],"Fanta");
    strcpy(question[i].opt[3],"Pepsi-cola");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"Coca-Cola originally contained cocaine.");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=2;
    strcpy(question[i].qn,"How many stars are found in the Paramount Studios logo?");
    strcpy(question[i].opt[0],"22");
    strcpy(question[i].opt[1],"41");
    strcpy(question[i].opt[2],"33");
    strcpy(question[i].opt[3],"10");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"there are 22 stars in the Paramount studios logo.");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=2;
    strcpy(question[i].qn,"When did Coca cola launched its second product spite?");
    strcpy(question[i].opt[0],"1990");
    strcpy(question[i].opt[1],"2000");
    strcpy(question[i].opt[2],"1961");
    strcpy(question[i].opt[3],"1980");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"Coca Cola launched its 3rd product Sprite in 1961.");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=2;
    strcpy(question[i].qn,"What was the previous name of MasterCard?");
    strcpy(question[i].opt[0],"MasterCharge");
    strcpy(question[i].opt[1],"MasterPoster");
    strcpy(question[i].opt[2],"Twitter");
    strcpy(question[i].opt[3],"MasterDelivery");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"MasterCard was originally called MasterCharge.");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=3;
    strcpy(question[i].qn,"What was the first product to have a bar-code?");
    strcpy(question[i].opt[0],"Mobile Telephone");
    strcpy(question[i].opt[1],"Parked soap");
    strcpy(question[i].opt[2],"Wrigley's gum");
    strcpy(question[i].opt[3],"A computer");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"the first product to have a bar code was Wrigley's gum.");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=3;
    strcpy(question[i].qn,"Who was the founder of Coca Cola?");
    strcpy(question[i].opt[0],"Fracklin J");
    strcpy(question[i].opt[1],"Parked soap");
    strcpy(question[i].opt[2],"Willy Swatz");
    strcpy(question[i].opt[3],"Joseph A Biedenharn");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"Coca Cola was founded by Joseph A Biedenharn.");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=3;
    strcpy(question[i].qn,"How did credit card idea came into existence?");
    strcpy(question[i].opt[0],"Because of Government issues");
    strcpy(question[i].opt[1],"It was invented by bank.");
    strcpy(question[i].opt[2],"It was a Diner's Club card issue.");
    strcpy(question[i].opt[3],"None of the above");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"the original name of Bank of America was Bank of Italy");

    i++;
    strcpy(question[i].category,"brands");
    question[i].level=3;
    strcpy(question[i].qn,"What was the original name of Bank of America?");
    strcpy(question[i].opt[0],"Bank of Italy");
    strcpy(question[i].opt[1],"London Bank.");
    strcpy(question[i].opt[2],"Bank of U.S");
    strcpy(question[i].opt[3],"None of the above");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the original name of Bank of America was Bank of Italy.");

//CAN'T
    i++;
    strcpy(question[i].category,"cant");
    question[i].level=3;
    strcpy(question[i].qn,"If food is not mixed up with saliva, you can't feel its test.");
    strcpy(question[i].opt[0],"True.");
    strcpy(question[i].opt[1],"FALSE.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"unless food is mixed with saliva you can't taste it.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"the cheetah is the only cat that can retract it's claws");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"the cheetah is the only cat that can't retract it's claws.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"roosters can't crow if they can't fully extend their necks");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"roosters can't crow if they can't fully extend their necks.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"a crocodile can't move its tongue");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"a crocodile can't move its tongue.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"whales can swim backwards");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"whales can't swim backwards.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"giraffes can swim");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"giraffes can't swim.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn," snakes can't bite in rivers or swamps (they would drown otherwise)");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"Yes!, snakes can't bite in rivers or swamps (they would drown otherwise).");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"giraffes can't cough");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"Yes!, giraffes can't cough.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"you can't tickle yourself and then laugh because of that tickle");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"you can't tickle yourself.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"At which age can a lion start roaring?");
    strcpy(question[i].opt[0],"1 year");
    strcpy(question[i].opt[1],"2 years");
    strcpy(question[i].opt[2],"5 years");
    strcpy(question[i].opt[3],"10 years");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"lion's can't roar until the age of 2 years.");

    i++;
    strcpy(question[i].category,"cant");
    question[i].level=2;
    strcpy(question[i].qn,"Is it possible for you to trademark your surname?");
    strcpy(question[i].opt[0],"Yes.");
    strcpy(question[i].opt[1],"No.");
    strcpy(question[i].opt[2],"None of these options");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"you can't trademark surnames.");

///color
    i++;
    strcpy(question[i].category,"colour");
    question[i].level=2;
    strcpy(question[i].qn,"What is the colour of a lobster's blood?");
    strcpy(question[i].opt[0],"Green");
    strcpy(question[i].opt[1],"Yellow");
    strcpy(question[i].opt[2],"Colourless");
    strcpy(question[i].opt[3],"Red");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"a lobsters blood is colorless but when exposed to oxygen it turns blue.");

///Counties ???????
    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"How many rivers are found in Jamaica?");
    strcpy(question[i].opt[0],"50 rivers");
    strcpy(question[i].opt[1],"100 rivers");
    strcpy(question[i].opt[2],"120 rivers");
    strcpy(question[i].opt[3],"20 rivers");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"Jamaica has 120 rivers.");

    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"Which country 70% of all toys in the world?");
    strcpy(question[i].opt[0],"America");
    strcpy(question[i].opt[1],"China");
    strcpy(question[i].opt[2],"England");
    strcpy(question[i].opt[3],"Saudi Arabia");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"China manufacturers 70% of the worlds toys.");


    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"Which country did paper originated from?");
    strcpy(question[i].opt[0],"America");
    strcpy(question[i].opt[1],"China");
    strcpy(question[i].opt[2],"England");
    strcpy(question[i].opt[3],"Saudi Arabia");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"China manufacturers 70% of the worlds toys.");

    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"Which country did wheelbarrow originated from?");
    strcpy(question[i].opt[0],"America");
    strcpy(question[i].opt[1],"India");
    strcpy(question[i].opt[2],"South Africa");
    strcpy(question[i].opt[3],"China");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"the wheelbarrow is invented in China.");

    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"Which country has most post offices in the world than any other country?");
    strcpy(question[i].opt[0],"America");
    strcpy(question[i].opt[1],"India");
    strcpy(question[i].opt[2],"South Africa");
    strcpy(question[i].opt[3],"China");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4]," India has the most post offices than any other country (over 100,000).");


    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"Which of the following countries boarders 9 countries?");
    strcpy(question[i].opt[0],"Uganda");
    strcpy(question[i].opt[1],"India");
    strcpy(question[i].opt[2],"Egypt");
    strcpy(question[i].opt[3],"Germany");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"Germany borders 9 other countries.");

    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"Peru has more pyramids than Egypt.");
    strcpy(question[i].opt[0],"True");
    strcpy(question[i].opt[1],"False");
    strcpy(question[i].opt[2],"No one knows");
    strcpy(question[i].opt[3],"None of the above");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"it's true, Peru has more pyramids than Egypt.");

    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"In which country is the most smallest bird found.");
    strcpy(question[i].opt[0],"Cuba");
    strcpy(question[i].opt[1],"India");
    strcpy(question[i].opt[2],"Bangladesh");
    strcpy(question[i].opt[3],"Togo");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the worlds smallest bird is the 'bee hummingbird' found in Cuba.");


    i++;
    strcpy(question[i].category,"countries");
    question[i].level=2;
    strcpy(question[i].qn,"How many strips are found in United States of America National flag.");
    strcpy(question[i].opt[0],"11");
    strcpy(question[i].opt[1],"21");
    strcpy(question[i].opt[2],"13");
    strcpy(question[i].opt[3],"8");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"the US flag has 13 stripes (representing the original 13 states).");

///DISTANCE
    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"Where is the longest street found?");
    strcpy(question[i].opt[0],"In china");
    strcpy(question[i].opt[1],"New-York");
    strcpy(question[i].opt[2],"Dubai");
    strcpy(question[i].opt[3],"Canada");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"the longest street in the world is Yonge street in Toronto Canada measuring 1,896 km (1,178 miles).");

    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"Does sound travel faster in water than in air?");
    strcpy(question[i].opt[0],"Yes");
    strcpy(question[i].opt[1],"No");
    strcpy(question[i].opt[2],"There is no difference");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"sound travels 4.3 times faster through water than in air");


    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"What is the moon's diameter?");
    strcpy(question[i].opt[0],"500km");
    strcpy(question[i].opt[1],"3021km");
    strcpy(question[i].opt[2],"3476km");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"the Moons diameter is 3,476km");

    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"What is the diameter of planet Jupiter?");
    strcpy(question[i].opt[0],"152,800km");
    strcpy(question[i].opt[1],"3021km");
    strcpy(question[i].opt[2],"3476");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the diameter of Jupiter is 152,800km (88 700 miles)");


    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"What is the diameter of the sun?");
    strcpy(question[i].opt[0],"152,800km");
    strcpy(question[i].opt[1],"3021km");
    strcpy(question[i].opt[2],"3476");
    strcpy(question[i].opt[3],"1,390,176km");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"the Sun has a diameter of 1,390,176km (864,000miles)");

    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"What is the diameter of the earth?");
    strcpy(question[i].opt[0],"12,756 km");
    strcpy(question[i].opt[1],"3021km");
    strcpy(question[i].opt[2],"3476km");
    strcpy(question[i].opt[3],"1,390,176km");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the diameter of Earth is 12,756 km (7,926 miles).");

    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"How long can a dolphin detect sound in water?");
    strcpy(question[i].opt[0],"127 km");
    strcpy(question[i].opt[1],"302 km");
    strcpy(question[i].opt[2],"24 km");
    strcpy(question[i].opt[3],"1,176km");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"dolphin's can detect underwater sounds from 24 km (15 miles) away.");

    i++;
    strcpy(question[i].category,"distance");
    question[i].level=2;
    strcpy(question[i].qn,"How long can the sun penetrate through clean water?");
    strcpy(question[i].opt[0],"73m");
    strcpy(question[i].opt[1],"31m");
    strcpy(question[i].opt[2],"97,m");
    strcpy(question[i].opt[3],"191m");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"sun light can penetrate clean ocean water up to a depth of 73m (240 feet).");

///drinks
    i++;
    strcpy(question[i].category,"drinks");
    question[i].level=2;
    strcpy(question[i].qn,"Where did beer made from bananas originated from?");
    strcpy(question[i].opt[0],"America");
    strcpy(question[i].opt[1],"Africa");
    strcpy(question[i].opt[2],"Asia");
    strcpy(question[i].opt[3],"Australia");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"Beer made from bananas was originated fromAfrica.");

    i++;
    strcpy(question[i].category,"drinks");
    question[i].level=2;
    strcpy(question[i].qn,"Where did beer made from bananas originated from?");
    strcpy(question[i].opt[0],"America");
    strcpy(question[i].opt[1],"Africa");
    strcpy(question[i].opt[2],"Asia");
    strcpy(question[i].opt[3],"Australia");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"Beer made from bananas was originated fromAfrica.");

///english
    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"What is the most used word in English conversation?");
    strcpy(question[i].opt[0],"I");
    strcpy(question[i].opt[1],"is");
    strcpy(question[i].opt[2],"yes");
    strcpy(question[i].opt[3],"ok");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4]," the most commonly used word in English conversation is 'I'.");

    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"What is the longest English word with most of its letters arranged in alphabetical order?");
    strcpy(question[i].opt[0],"Almost");
    strcpy(question[i].opt[1],"Abduct");
    strcpy(question[i].opt[2],"Abandon");
    strcpy(question[i].opt[3],"Alphabets");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the word 'almost' is the longest in the English language with all the letters in alphabetical order.");

    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"Which language do all pilots in the world use to identify themselves no matter what country the come from?");
    strcpy(question[i].opt[0],"English");
    strcpy(question[i].opt[1],"Chinese");
    strcpy(question[i].opt[2],"French");
    strcpy(question[i].opt[3],"German");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"all pilots on international flights identify themselves in English regardless of their country of origin.");

    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"When was the first English dictionary written?");
    strcpy(question[i].opt[0],"in 1980");
    strcpy(question[i].opt[1],"in 1860");
    strcpy(question[i].opt[2],"in 1755");
    strcpy(question[i].opt[3],"in 1680");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"The first English dictionary was written in 1755.");

    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"How do we call the dot on top of letter 'i'?");
    strcpy(question[i].opt[0],"a dot");
    strcpy(question[i].opt[1],"a little");
    strcpy(question[i].opt[2],"a pinch");
    strcpy(question[i].opt[3],"a dangle");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"The dot on top of the letter 'i' is called a tittle.");

    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"What is the longest English word that uses a single vowel?");
    strcpy(question[i].opt[0],"me");
    strcpy(question[i].opt[1],"little");
    strcpy(question[i].opt[2],"strength");
    strcpy(question[i].opt[3],"pot");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"the word 'Strengths' is the longest word in the English language with just one vowel.");

    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"What is the oldest English word?");
    strcpy(question[i].opt[0],"God");
    strcpy(question[i].opt[1],"little");
    strcpy(question[i].opt[2],"Food");
    strcpy(question[i].opt[3],"town");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"the oldest word in the English language is 'town'.");


    i++;
    strcpy(question[i].category,"english");
    question[i].level=2;
    strcpy(question[i].qn,"How many words in English language ends with letters 'dous'?");
    strcpy(question[i].opt[0],"8 words");
    strcpy(question[i].opt[1],"20 words");
    strcpy(question[i].opt[2],"10 words");
    strcpy(question[i].opt[3],"4 words");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"there are only 4 words in the English language which end in 'dous' (they are: hazardous, horrendous, stupendous and tremendous).");

///people
    i++;
    strcpy(question[i].category,"people");
    question[i].level=2;
    strcpy(question[i].qn,"At what age did Bill Gates begin programming computers?");
    strcpy(question[i].opt[0],"8");
    strcpy(question[i].opt[1],"19");
    strcpy(question[i].opt[2],"10");
    strcpy(question[i].opt[3],"13");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"Bill Gates began programming computers at the of age 13.");

    i++;
    strcpy(question[i].category,"people");
    question[i].level=2;
    strcpy(question[i].qn,"How many hours did Einstein used to sleep for a night?");
    strcpy(question[i].opt[0],"8");
    strcpy(question[i].opt[1],"19");
    strcpy(question[i].opt[2],"10");
    strcpy(question[i].opt[3],"13");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"Einstein slept 10 hours a night.");

    i++;
    strcpy(question[i].category,"people");
    question[i].level=2;
    strcpy(question[i].qn,"How old was Sir Isaac Newton when he discovered gravitational force?");
    strcpy(question[i].opt[0],"35");
    strcpy(question[i].opt[1],"30");
    strcpy(question[i].opt[2],"10");
    strcpy(question[i].opt[3],"23");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"Sir Isaac Newton was 23 when he discovered the law of gravity.");

    i++;
    strcpy(question[i].category,"people");
    question[i].level=2;
    strcpy(question[i].qn,"Who invented a word 'Assassination'?");
    strcpy(question[i].opt[0],"Isaac Newton");
    strcpy(question[i].opt[1],"Shakespeare");
    strcpy(question[i].opt[2],"Johnson K.");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"Shakespeare invented the words 'assassination' and 'bump'.");

    i++;
    strcpy(question[i].category,"people");
    question[i].level=2;
    strcpy(question[i].qn,"How long did Leonardo Da Vinci took to paint Mona Lisa?");
    strcpy(question[i].opt[0],"10 years");
    strcpy(question[i].opt[1],"5 years");
    strcpy(question[i].opt[2],"12 months");
    strcpy(question[i].opt[3],"15 years");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"it took Leonardo Da Vinci 10 years to paint Mona Lisa");

    i++;
    strcpy(question[i].category,"people");
    question[i].level=2;
    strcpy(question[i].qn,"Did Albert Einstein new how to drive a car?");
    strcpy(question[i].opt[0],"Yes he knew");
    strcpy(question[i].opt[1],"No he didn't know");
    strcpy(question[i].opt[2],"No one knows the real answer");
    strcpy(question[i].opt[3],"none of these options is correct.");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"Albert Einstein never knew how to drive a car");

///first
    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"When was the first Telephone Phonebook made?");
    strcpy(question[i].opt[0],"in 1990");
    strcpy(question[i].opt[1],"in 1800");
    strcpy(question[i].opt[2],"in 1870");
    strcpy(question[i].opt[3],"none of these options is correct.");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"in 1878 the first telephone book made contained only 50 names");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"What was the maximum number of contacts could first Telephone Phonebook save?");
    strcpy(question[i].opt[0],"10 contacts");
    strcpy(question[i].opt[1],"5 contacts");
    strcpy(question[i].opt[2],"100 contacts");
    strcpy(question[i].opt[3],"50 contacts.");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"in 1878 the first telephone book made contained only 50 names");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"Which country used paper money for the first time?");
    strcpy(question[i].opt[0],"China");
    strcpy(question[i].opt[1],"America");
    strcpy(question[i].opt[2],"India");
    strcpy(question[i].opt[3],"Egypt.");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"paper money was first used in China");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"Which was the first country to use postage stamp?");
    strcpy(question[i].opt[0],"China");
    strcpy(question[i].opt[1],"America");
    strcpy(question[i].opt[2],"Britain");
    strcpy(question[i].opt[3],"Egypt.");
    question[i].correct_ans='3';
    strcpy(question[i].opt[4],"Britain was the first country to use postage stamps");


    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"Which was the first country to legalize abortion?");
    strcpy(question[i].opt[0],"Iceland");
    strcpy(question[i].opt[1],"America");
    strcpy(question[i].opt[2],"Britain");
    strcpy(question[i].opt[3],"Egypt.");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"Iceland was the first country to legalise abortion in 1935");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"When were the first foods introduced?");
    strcpy(question[i].opt[0],"in 1920");
    strcpy(question[i].opt[1],"in 1980");
    strcpy(question[i].opt[2],"in 1999");
    strcpy(question[i].opt[3],"in 1990");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the frozen foods were first introduced in the 1920.");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"When were the first toothbrush invented?");
    strcpy(question[i].opt[0],"in 1920");
    strcpy(question[i].opt[1],"in 1498");
    strcpy(question[i].opt[2],"in 1680");
    strcpy(question[i].opt[3],"in 1999");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"the first toothbrush was invented in 1498.");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"What was the first movie tittle for James Bond's movie?");
    strcpy(question[i].opt[0],"Dr. No.");
    strcpy(question[i].opt[1],"The puzzle");
    strcpy(question[i].opt[2],"Wheels on meals");
    strcpy(question[i].opt[3],"The expendibles");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"the first James Bond movie was called 'Dr. No'.");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"When did the first puzzle appear?");
    strcpy(question[i].opt[0],"In 1990");
    strcpy(question[i].opt[1],"1913");
    strcpy(question[i].opt[2],"2000");
    strcpy(question[i].opt[3],"1900");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"the first crossword puzzle appeared in 1913.");

    i++;
    strcpy(question[i].category,"first");
    question[i].level=2;
    strcpy(question[i].qn,"Who was the first person to produce the fist playing card?");
    strcpy(question[i].opt[0],"Nintendo");
    strcpy(question[i].opt[1],"Amanie");
    strcpy(question[i].opt[2],"Isaac Newton");
    strcpy(question[i].opt[3],"No one knows");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"Nintendo first produced playing cards.");


///words
    i++;
    strcpy(question[i].category,"words");
    question[i].level=2;
    strcpy(question[i].qn,"How do we call a group of owls in English Language?");
    strcpy(question[i].opt[0],"Parliament");
    strcpy(question[i].opt[1],"Government");
    strcpy(question[i].opt[2],"A crew");
    strcpy(question[i].opt[3],"A scrand");
    question[i].correct_ans='1';
    strcpy(question[i].opt[4],"a group of owls is called a parliament.");

    i++;
    strcpy(question[i].category,"words");
    question[i].level=2;
    strcpy(question[i].qn,"How do we call a group of owls in English Language?");
    strcpy(question[i].opt[0],"Parliament");
    strcpy(question[i].opt[1],"A scoop");
    strcpy(question[i].opt[2],"A crew");
    strcpy(question[i].opt[3],"A gaggle");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"a group of geese is called a gaggle.");

    i++;
    strcpy(question[i].category,"words");
    question[i].level=2;
    strcpy(question[i].qn,"How do we call a group of whales in English Language?");
    strcpy(question[i].opt[0],"Parliament");
    strcpy(question[i].opt[1],"Government");
    strcpy(question[i].opt[2],"A pod");
    strcpy(question[i].opt[3],"A gaggle");
    question[i].correct_ans='4';
    strcpy(question[i].opt[4],"a group of whales is called a pod.");

    i++;
    strcpy(question[i].category,"words");
    question[i].level=2;
    strcpy(question[i].qn,"How do we call a group of kangaroos in English Language?");
    strcpy(question[i].opt[0],"Parliament");
    strcpy(question[i].opt[1],"mob");
    strcpy(question[i].opt[2],"A pod");
    strcpy(question[i].opt[3],"A gaggle");
    question[i].correct_ans='2';
    strcpy(question[i].opt[4],"a group of kangaroos is called a mob.");

}




















