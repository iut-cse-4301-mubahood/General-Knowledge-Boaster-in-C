int game_menu();
int start_new_game();
void sign_out();
void edit_acc();
void view_scores();
void result_();
void resume_();

int game_menu()
{
    logged_in_id=k;
    if(strlen(player[logged_in_id].key)<1)
    {
        no_account=1;
    }

    system("cls");

    resume_();
    return 0;
}

int start_new_game()
{
START:
    system("cls");
    system("cls");
    printf("\n\t\t       Start New Game\n");
    printf("\n\t\t--------[ RESUME ]---------\n");
    printf("\n\t\t        View Scores\n");
    printf("\n\t\t          Settings\n");
    printf("\n\t\t          Sign Out\n\n\t\t");
    choice=getch();

    if(choice=='W' || choice=='w')
    {
        resume_();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        view_scores();
        return;
    }
    else if(choice==13)
    {

        system("cls");
        srand(time(NULL));
        struct tm *time_;
        time_t t;
        error=0;

        questions_func();
        while(1)
        {
            load_data();
            do
            {

                system("cls");
                if(error==1)
                {
                    printf("Wrong input. Enter a number corresponding to correct answer.\n\n");
                }
                if(no_qn>30 && player[logged_in_id].points <1000)
                {
                    system("cls");

                    system("COLOR C");
                    printf("+-----------------------------------+");
                    printf("\n|           GAME OVER!!!            |");
                    printf("\n|          -------------            |");
                    printf("\n|                                   |");
                    printf("\n| You answered many questions       |");
                    printf("\n| but failed to reach the final mark!");
                    printf("\n|                                   |");
                    printf("\n| START A FRESH...                  |");
                    printf("\n+-----------------------------------+");

                    player[logged_in_id].points=0;
                    for(k=0; k<1000; k++)
                    {
                        player[logged_in_id].questions_answered[k]=0;
                    }
                    save_data();
                    printf("\n\n\t    DATA CLEARED\n\n\t\t  ");
                    //choice=getche();
                    choice=getche();
                    system("COLOR 7");
                    start_new_game();
                    return;

                }


                {
                    printf("+---------------------------------------+");
                    printf("\n|                                       |");

                    if(player[logged_in_id].points<3000)
                    {
                        printf("\n|             BEGINER LEVEL             |");
                        printf("\n|   You need more %d points to unlock",3000-player[logged_in_id].points);
                        printf("\n|   the next level.                     |");
                    }
                    else if(player[logged_in_id].points<6000 && player[logged_in_id].points<9000)
                    {
                        printf("\n|             MASTER LEVEL              |");
                        printf("\n|   You need more %d points to unlock",6000-player[logged_in_id].points);
                        printf("\n|   the next level.                     |");
                    }
                    else
                    {
                        printf("\n|              PRO LEVEL              |");
                        printf("\n|   You need more %d points to unlock",9000-player[logged_in_id].points);
                        printf("\n|   to complete the game.                |");
                    }
                }

                printf("\n|                                       |");
                printf("\n+---------------------------------------+");


                /*
                                printf("\n\n----------------\n\n");
                                for(l=0; l<100; l++)
                                {

                                    printf("%d, ",player[logged_in_id].questions_answered[l]);
                                    if(player[logged_in_id].questions_answered[l]==0)
                                        break;

                                }


                                printf("\n\n----------------\n\n");
                */


                struct tm *time_;
                time_t t;
                if(error==0)
                {
                    for(l=0; l<100; l++)
                    {
                        r=rand()%100;
                        if(r!=player[logged_in_id].questions_answered[l])
                        {
                            num=r;
                            break;
                        }
                    }
                }


                if(error==0)
                {
                    for(k=0;;)
                    {
                        if(player[logged_in_id].questions_answered[k]==0)
                        {
                            player[logged_in_id].questions_answered[k]=num;
                            break;
                        }
                        k++;
                    }

                    t=time(NULL);
                    time_=localtime(&t);
                    tm_s1=time_->tm_sec;
                    tm_m1=time_->tm_min;
                }

                printf("\n\n");
                puts(question[num].qn);
                printf("   Ans 1.  %s\n",question[num].opt[0]);
                printf("   Ans 2.  %s\n",question[num].opt[1]);
                printf("   Ans 3.  %s\n",question[num].opt[2]);
                printf("   Ans 4.  %s\n",question[num].opt[3]);
                printf("\n\nEnter your Option:   ");
                choice=getch();

                t=time(NULL);
                time_=localtime(&t);
                tm_s2=time_->tm_sec;
                tm_m2=time_->tm_min;

                tm_s=(tm_s2-tm_s1);
                tm_m=(tm_m2-tm_m1);




                /*for(k=0; k<100; k++)
                {
                    printf("%d,  ",player[logged_in_id].questions_answered[k]);

                }
                choice=getche();*/


                if(tm_s<0)
                {
                    tm_m=tm_m-1;
                    tm_s=60+tm_s;
                    break;
                }
                if(tm_m<0)
                {
                    tm_m<60+tm_m;
                    break;
                }

                if(choice!='1' && choice!='2' && choice!='3' && choice!='4')
                {
                    error=1;
                }
                else
                {
                    error=0;
                }
            }
            while(choice!='1' && choice!='2' && choice!='3' && choice!='4');

            if(choice==question[num].correct_ans)
            {

                mark=0;
                ///Awarding points
                tm=(tm_m*60)+tm_s;
                if(tm>1)
                {
                    mark=1/((double)(tm));
                    mark=mark*1000;
                    k=mark;
                }
                else
                {
                    k=1000;
                }
                player[logged_in_id].points=player[logged_in_id].points+k;
                system("cls");
                save_data();
                system("COLOR A");
                printf("+-----------------------------------+");
                printf("\n|             PERFECT!!!            |");
                printf("\n|             ----------            |");
                printf("\n|                                   |");
                printf("\n| You Answered within %d seconds   ",tm);
                printf("\n| and Earned %d points.           ",k);
                printf("\n|                                   |");
                printf("\n|                                   |");
                printf("\n+-----------------------------------+");
                printf("\n\nEnter ESC to exit or any other key to continue:  ");
                choice=getch();
                system("COLOR 7");
                if(choice==27)
                {
                    goto START;
                }
            }
            else
            {
                mark=0;
                ///Awarding points
                tm=(tm_m*60)+tm_s;
                if(tm>1)
                {
                    mark=((double)(tm));
                    mark=1/mark*1000;
                    k=mark;
                }
                else
                {
                    k=1000;
                }
                player[logged_in_id].points=player[logged_in_id].points-k;
                system("cls");
                save_data();
                system("COLOR C");
                printf("+-------------------------------------+");
                printf("\n|              OOooops!!!             |");
                printf("\n|              ----------             |");
                printf("\n|                                     |");
                printf("\n| You Answered within %d seconds",tm);
                printf("\n| and Lost %d points.",k);
                printf("\n|                                     |");
                printf("\n+-------------------------------------+");

                if(player[logged_in_id].points<0)
                {
//                    system("cls");
                    player[logged_in_id].points=0;
                    save_data();
                }
                printf("\n\nEnter ESC to exit or any other key to continue:  ");

                choice=getche();
                system("COLOR 7");
                system("cls");
                if(choice==27)
                {
                    goto START;
                }
                else
                    printf("+-----------------------------------+");
                printf("\n|          Correct Answer.          |");
                printf("\n|          ---------------          |");
                printf("\n+-----------------------------------+\n\n");
                puts(question[num].opt[4]);
                printf("\n\n");
                choice=getche();
                if(choice==27)
                {
                    goto START;
                }
            }
        }

        return 0;
    }
    else
    {
        start_new_game();
        return 0;
    }
}

void resume_()
{
    system("cls");

    printf("\n\t\t------[START NEW GAME]------\n");
    printf("\n\t\t          Resume\n");
    printf("\n\t\t        View Scores\n");
    printf("\n\t\t          Settings\n");
    printf("\n\t\t          Sign Out\n\n\t\t\t");
    choice=getch();
    if(choice=='W' || choice=='w')
    {
        sign_out();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        start_new_game();
        return;
    }
    else if(choice==13)
    {
        system("cls");
        printf("+--------------------------------+");
        printf("\n|             WARNING!          |");
        printf("\n|            ---------          |");
        printf("\n+--------------------------------+");

        printf("\n\nThis option clears all your games data!");
        printf("\nEnter 'Y' for yes or any key to council:\n\n\t\t  ");

        choice=getche();
        if(choice=='Y' || choice=='y')
        {
            player[logged_in_id].points=0;
            for(k=0; k<1000; k++)
            {
                player[logged_in_id].questions_answered[k]=0;
            }
            save_data();
            printf("\n\n\t    DATA CLEARED\n\n\t\t  ");
            choice=getche();
            start_new_game();
            return;
        }
        else
        {
            start_new_game();
            return;
        }
    }
    else
    {
        start_new_game();
        return;
    }




}

void view_scores()
{
    system("cls");
    printf("\n\t\t       Start New Game\n");
    printf("\n\t\t          Resume  \n");
    printf("\n\t\t------[ VIEW SCORES ]------\n");
    printf("\n\t\t          Settings\n");
    printf("\n\t\t          Sign Out\n\n\t\t");
    choice=getch();

    if(choice=='W' || choice=='w')
    {
        start_new_game();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        edit_acc();
        return;
    }
    else if(choice==13)
    {
        system("cls");
        printf("+-----------------------------------+");
        printf("\n|            YOUR SCORES            |");
        printf("\n|           -------------           |");
        printf("\n+-----------------------------------+");
        load_data();

        printf("\n\n   TOTAL  POINTS        :  %d",player[logged_in_id].points);
        printf("\n   No.    OF QUESTIONS  :  ");

        printf("%d",no_qn);

        printf("\n   LEVEL                :  ");
        if(player[logged_in_id].points<3000)
        {
            printf("Beginner\n\n\n\t      ");
            choice=getche();
            start_new_game();
            return;
        }
        else if(player[logged_in_id].points<3000 && player[logged_in_id].points<6000)
        {
            printf("MASTER\n\n\n\t      ");
            choice=getche();
            start_new_game();
            return;
        }
        else if(player[logged_in_id].points>6000)
        {
            printf("PRO\n\n\n\t      ");
            choice=getche();
            start_new_game();
            return;
        }



        choice=getch();
        start_new_game();
        return;
    }
    else
    {
        view_scores();
        return;
    }
}

void edit_acc()
{
    system("cls");

    printf("\n\t\t       Start New Game\n");
    printf("\n\t\t          Resume  \n");
    printf("\n\t\t        View Scores\n");
    printf("\n\t\t--------[ SETTINGS ]--------\n");
    printf("\n\t\t          Sign Out\n\n\t\t");

    choice=getch();
    if(choice=='W' || choice=='w')
    {
        view_scores();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        sign_out();
        return;
    }
    else if(choice==13)
    {
EDIT:
        system("cls");
        printf("+-----------------------------------+");
        printf("\n|            YOUR SCORES            |");
        printf("\n|           -------------           |");
        printf("\n+-----------------------------------+");
        load_data();
        printf("\n\n  1. CHANGE SECRET KEY ");
        printf("\n  2. RESTORE ACCOUNT ");
        printf("\n  3. DELETE THIS ACCOUNT");
        printf("\n  4. BACK\n\n\t\t");

        choice=getche();
        switch (choice)
        {
            printf("\n\n+-----------------------------------+\n");
        case '1':
        {
            printf("  ENTER NEW SECRET KEY:  ");
            fflush(stdin);
            gets(player[logged_in_id].key);
            save_data();
            load_data();

            system("cls");
            printf("+-----------------------------------+");
            printf("\n|        SECRET KEY CHANGED         |");
            printf("\n|        ------------------         |");
            printf("\n+-----------------------------------+");

            printf("\n Your new key is: %s\n\n\t\t ",player[logged_in_id].key);
            choice=getche();
            goto EDIT;
            break;
        }
        case '2':
        {

            system("cls");
            printf("+--------------------------------+");
            printf("\n|             WARNING!           |");
            printf("\n|            ---------           |");
            printf("\n+--------------------------------+");

            printf("\n\nThis option clears all your games data!");
            printf("\nEnter 'Y' for yes or any key to council:\n\n\t\t  ");

            x=getche();
            if(x=='Y' || x=='y')
            {
                player[logged_in_id].points=0;
                for(k=0; k<1000; k++)
                {
                    player[logged_in_id].questions_answered[k]=0;
                }
                save_data();
                load_data();
                printf("\n\n\t   DATA CLEARED\n\n\t\t  ");
                x=getche();
                goto EDIT;
                break;
            }
            else
            {
                goto EDIT;
            }
        }
        case '3':
        {
            system("cls");
            printf("+--------------------------------+");
            printf("\n|             WARNING!           |");
            printf("\n|            ---------           |");
            printf("\n+--------------------------------+");

            printf("\n\nThis option DELETES this account!");
            printf("\nEnter 'Y' for yes or any key to council:\n\n\t\t  ");

            x=getche();
            if(x=='Y' || x=='y')
            {
                player[logged_in_id].display=0;
                save_data();
                load_data();
                welcome();
                return;
                break;
            }
            else
            {
                goto EDIT;
            }


        }
        case '4':
        {
            resume_();
            return;
        }

        }
        goto EDIT;
    }
    else
    {
        edit_acc();
        return;
    }
}

void sign_out()
{
    system("cls");
    printf("\n\t\t       Start New Game\n");
    printf("\n\t\t          Resume  \n");
    printf("\n\t\t        View Scores\n");
    printf("\n\t\t          Settings\n");
    printf("\n\t\t--------[ SIGN OUT ]---------\n\n\t\t");
    choice=getch();



    if(choice=='W' || choice=='w')
    {
        edit_acc();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        resume_();
        return;
    }
    else if(choice==13)
    {
        system("cls");
        //logged_in_id=-1;
        welcome();
        return;
    }
    else
    {
        sign_out();
        return;
    }
}
