#include <iostream>
#include <cstdio>
using namespace std;

struct{
    char name[7];
    int strength;
}Worriers[5]={
    {"dragon",0},
    {"ninja",0},
    {"iceman",0},
    {"lion",0},
    {"wolf",0},
};

struct{
    char name[6];
}Weapons[3]={
    {"sword"},
    {"bomb"},
    {"arrow"},
};

class Red{  // iceman、lion、wolf、ninja、dragon
    public:
        int life;
        int stop;
        int now;
        int count;
        int total;
        const int seq[5]={2,3,4,1,0};
        int num[5]={0};

        Red(int _life){
            life=_life;
            stop=0;
            now=0;
            count=0;
            total=0;
        }

        void Prepare(int mission){
            while(count<5){
                if(life>=Worriers[seq[now]].strength){
                    life-=Worriers[seq[now]].strength;
                    num[now]++;
                    total++;
                    printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n",
                    mission,Worriers[seq[now]].name,mission+1,Worriers[seq[now]].strength,num[now],
                    Worriers[seq[now]].name);
                    switch(now){
                        case 0: // iceman
                            printf("It has a %s\n",Weapons[total%3].name);
                            break;
                        case 1: // lion
                            printf("It's loyalty is %d\n",life);
                            break;
                        case 3: // ninja
                            printf("It has a %s and a %s\n",Weapons[total%3].name,Weapons[(total+1)%3].name);
                            break;
                        case 4: // dragon
                            printf("It has a %s,and it's morale is %.2f\n",Weapons[total%3].name,(double)life/Worriers[0].strength);
                            break;
                    }
                    now=(now+1)%5;
                    count=0;
                    break;
                }else{
                    now=(now+1)%5;
                    count++;
                }
            }
            if(count==5 && stop==0) {
                printf("%03d red headquarter stops making warriors\n",mission);
                stop=1;
            }
        }
};

class Blue{ // lion、dragon、ninja、iceman、wolf
    public:
        int life;
        int stop;
        int now;
        int count;
        int total;
        const int seq[5]={3,0,1,2,4};
        int num[5]={0};

        Blue(int _life){
            life=_life;
            stop=0;
            now=0;
            count=0;
            total=0;
        }

        void Prepare(int mission){
            while(count<5){
                if(life>=Worriers[seq[now]].strength){
                    life-=Worriers[seq[now]].strength;
                    num[now]++;
                    total++;
                    printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n",
                    mission,Worriers[seq[now]].name,mission+1,Worriers[seq[now]].strength,num[now],
                    Worriers[seq[now]].name);
                    switch(now){
                        case 3: // iceman
                            printf("It has a %s\n",Weapons[total%3].name);
                            break;
                        case 0: // lion
                            printf("It's loyalty is %d\n",life);
                            break;
                        case 2: // ninja
                            printf("It has a %s and a %s\n",Weapons[total%3].name,Weapons[(total+1)%3].name);
                            break;
                        case 1: // dragon
                            printf("It has a %s,and it's morale is %.2f\n",Weapons[total%3].name,(double)life/Worriers[0].strength);
                            break;
                    }
                    now=(now+1)%5;
                    count=0;
                    break;
                }else{
                    now=(now+1)%5;
                    count++;
                }
            }
            if(count==5 && stop==0) {
                printf("%03d blue headquarter stops making warriors\n",mission);
                stop=1;
            }
        }
};


int main(){
    int Case;
    cin>>Case;
    for(int i=1;i<=Case;i++){
        cout<<"Case:"<<i<<endl;
        int life;
        cin>>life;
        Red r(life);
        Blue b(life);
        int j;
        for(j=0;j<5;j++) cin>>Worriers[j].strength;   // dragon 、ninja、iceman、lion、wolf
        j=0;
        while(!r.stop || !b.stop){
            r.Prepare(j);
            b.Prepare(j);
            j++;
        }
    }
    return 0;
}
