struct player
{
    int id,hide;
    char name[25];
    char key[25];
    int age;
    int questions_answered[1000];
    int points;
    int display;
}player[51];

struct questions
{
    char qn[200];
    char opt[5][100];
    char category[20];
    char correct_ans;
    int level;
}question[300];


char choice,x,y,z,temp_age[50],logged_in_id=-1;
double mark;
int i,j,k,l,tm_s1,tm_s2,tm_m1,tm_m2,num=0,tm_h1,tm_h2,tm_s,tm_m,tm_h,tm,num,error=0,r, number_of_players,no_account=0,no_qn;

