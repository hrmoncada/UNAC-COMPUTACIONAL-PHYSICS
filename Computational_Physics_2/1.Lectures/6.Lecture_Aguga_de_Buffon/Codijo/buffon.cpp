//Buffon's problem-C/C++ coding
//by Scott.Park
// https://mathanddream.wordpress.com/2012/08/19/buffons-problem-c-coding/
 
//header
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<cmath>
#include<ctime>
 
using namespace std;
 
//constants
#define pi 3.1415926536 //π
 
//macros
#define randomize() srand((unsigned)time(NULL))
 
//global variables
double dist; //distance between two lines
int ScreenMode; //screenmode
 
//needle class
class needle{
public:
    double len; //length of the needle
    double angle; //angle-RANDOM between 0 ~ π
    double x; //distance between needle and line-RANDOM between (dist-len*a) ~ dist
    bool check(); //whether the needle meets the line or not
    bool needleShort(); //whether len<=dist
};
 
bool needle::needleShort(){
    if(len<=dist) return true;
    else return false;
}
 
bool needle::check(){
    double b=len*sin(angle);
    if(needleShort()){
        if(x+b>=dist) return true;
        else return false;
    }
    else{
        if(b>=dist) return true;
        else{
            if(x+b>=dist) return true;
            else return false;
        }
    }
}
 
void getScreenMode(){
    int sc;
    cin.clear();
    sc=_getch();
    switch(sc){
    case 's': //show all steps
        ScreenMode=1;
        break;
    case 'p': //step by step
        ScreenMode=2;
        break;
    case 'a': //just see final result
        ScreenMode=3;
        break;
    default:
        getScreenMode();
        break;
    }
}
 
struct prob{
    unsigned int tot; //total
    unsigned int num; //number of success
};
 
int main(){
    unsigned int n; //number of trying
    unsigned int i; //loop index
    needle L; //needle "L"
    register bool* ifNeedle; //whether the needle meets the line or not
    prob p; //probability
    double res;
    double piCal;
    int ch;
 
    for(;;){
        //
        randomize();
 
        //
        cout<<"Buffon's needle problem - C++ simulation"<<endl<<endl;
        cin.clear();
        cout<<"Set : distance between lines"<<endl; //Input dist
        cin>>dist;
 
        cin.clear();
        cout<<"Set : length of a needle"<<endl; //Input len
        cin>>L.len;
 
        cin.clear();
        cout<<"How many times do you want to throw needle?"<<endl; //Input n
        cin>>n;
        ifNeedle=(bool *)malloc(n*sizeof(bool));
 
        cin.clear();
        cout<<endl<<"s : view all steps, p: step by step, a : just see total result"<<endl<<endl; //Input ScreenMode
        getScreenMode();
 
        cout<<"Throwing..."<<endl<<endl;
 
        //
        /*when len<=dist*/
        if(L.needleShort()){
            p.tot=1; //as prob must not be 0;
            p.num=1, ifNeedle[0]=true;
            for(i=1;i<n;i++){
                p.tot++;
 
                L.angle=(rand()%30000)/29999.0*pi;
                L.x=(rand()%30000)/29999.0*dist;
 
                if(L.check()){
                    p.num++;
                    ifNeedle[i]=true;
                }
                else ifNeedle[i]=false;
            }
        }
        /*when len>dist*/
        else{
            p.tot=1; //as prob must not be 1;
            p.num=0, ifNeedle[0]=false;
            for(i=1;i<n;i++){
                p.tot++;
 
                L.angle=(rand()%30000)/29999.0*pi;
                L.x=(rand()%30000)/29999.0*dist;
 
                if(L.check()){
                    p.num++;
                    ifNeedle[i]=true;
                    ifNeedle[i]=false;
                }
            }
        }
 
        //
        switch(ScreenMode){
        case 1:
            for(i=0;i<n;i++){
                cout<<" Trying "<<i;
                if(ifNeedle[i]) cout<<" : "<<"good"<<endl;
                else cout<<" : "<<"no"<<endl;
            }
            cout<<endl<<endl;
            break;
        case 2:
            for(i=0;i<n;i++){
                _getch();
                cout<<" Trying "<<i;
                if(ifNeedle[i]) cout<<" : "<<"good"<<endl;
                else cout<<" : "<<"no"<<endl;
            }
            cout<<endl<<endl;
            break;
        default:
            break;
        }
 
        //
        res=p.num/(p.tot*1.0);
        if(L.len<=dist) piCal=2*L.len/(dist*res);
        else piCal=(1/(res-1))*((2*L.len/dist)-(2/dist)*(sqrt(L.len*L.len-dist*dist)+dist*asin(dist/L.len)));
 
        //
        cout<<"Total numbers of trying : ";
        cout<<p.tot<<endl<<endl;
        cout<<"Number of success : ";
        cout<<p.num<<endl<<endl;
        cout<<"Probability : ";
        cout<<res<<endl<<endl<<endl;
        cout<<"Calculated pi ";
        cout<<piCal<<endl<<endl;
 
        cout<<"press q to exit, otherwise restart"<<endl;
 
        //
        cin.clear();
        ch=_getch();
        switch(ch){
        case 'q':
            exit(0);
            break;
        default:
            system("cls");
            break;
        }
 
        free(ifNeedle);
    }
 
    return 0;
}
