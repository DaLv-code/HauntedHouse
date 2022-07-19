#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heart(int num)  //목숨함수 
{
   // while(1)
   // {   
        if (num==3)
        {
            printf("\t❤️  ❤️  ❤️");
    //        break;
        }
        else if(num==2)
        {
            printf("\t❤️  ❤️");
    //        break;
        }
        else if(num==1)
        {
            printf("\t❤️");
    //        break;
        }
    //    else if(num==0)     밖에 있어서 일단 주석처리
    //    { 
    //        printf("게임패배\n");
        //    break;
    //    }
  //  }
}    

void map()
{   
    char input; //입력
    int num[22][22]={0,}; //맵
    int i,j;  
    int k=11,m=11; //캐릭터 초기위치    
    int count=0; //움직임 횟수
    int ghost[21]={0,}; //유령 몹
    int skull[21]={0,}; //해골 몹
    int item[21]={0,}; //아이템
    int randomDir=0;
    int LV=1; //레벨
    int score=0; //점수
    int life=3; //시작 목숨 갯수 ++++++
    
    srand(time(NULL));       
    
    while(1) //캐릭터 움직이는 반복문 
    {
        system("clear");   
        count++; //움직임 횟수       
        score+=10; //움직일때마다 점수 10점씩 오름      
            
        int difficulty = 12 - LV; //LV업 하면 몹이 더 자주나옴

        num[k][m]=2;
        printf("\n");
        for(i=0;i<22;i++) //출력문
        {
            num[i][0]=1,num[i][21]=1; 
            for(j=0;j<22;j++)
            {
                num[0][j]=1,num[21][j]=1;
                if(num[i][j]==0)
                    printf("  ");
                else if(num[i][j]==1)
                    printf("▒▒");
                else if(num[i][j]==2)
                    printf("👦");
                else if(num[i][j]==3)
                    printf("👻");
                else if(num[i][j]==4)
                    printf("🎁");  
                else if(num[i][j]==5)
                    printf("💀");              
            } 
            if(i==1)
                printf("  __    ____  ___  ____  __ _  ____  ");
            if(i==2)
                printf(" (  )  (  __)/ __)(  __)(  ( \\(    \\"); 
            if(i==3)
                printf(" / (_/\\ ) _)( (_ \\ ) _) /    / ) D ("); 
            if(i==4)
                printf(" \\____/(____)\\___/(____)\\_)__)(____/"); 
            if(i==5)
                printf("   __  ____    ____   __  __ _  __  ");
            if(i==6)
                printf("  /  \\(  __)  (  _ \\ /  \\(  / )(  ) ");
            if(i==7)
                printf(" (  O )) _)    ) _ ((  O ))  (  )(  ");
            if(i==8)
                printf("  \\__/(__)    (____/ \\__/(__\\_)(__) ");
            if(i==9)
                printf("                      Haunted house");

            if(i==11)
                printf(" ┌─────────────────────────────────┐");
            if(i==13)
                printf("      게임방법 : w,a,s,d로 이동");
            if(i==15)
                printf("          LV\t%5d", LV);
            if(i==17)
                printf("       SCORE\t%5d점",score);    
            if(i==19)
            {
                printf("        LIFE ");
                heart(life); 
            }
              
            if(i==21)
                printf(" └─────────────────────────────────┘");
            printf("\n");
        } 
       
        //목숨 함수 
        scanf(" %c",&input);//움직이게 a,d누르면 m(열로)w,s누르면 k(행으로)
	    // 여기에 목숨 보이는 함수넣어야지 

        if(count==50) //50번 이동시 레벨업
        {
            count=0;
            LV++;      
            if(LV==11)
            {
                printf("\n\n       🏁 축하합니다! 게임 클리어 🏁\n\n");
                printf("   이번 게임에서 획득한 점수 : %d점입니다!\n\n\n",score);
                break;
            }    
        }
        else if(life==0) //라이프 0 되면 종료되게
       {
            printf("\n\n   🏳️  LIFE가 0이 되었습니다. 게임 오버 🏳️\n\n\n");
            break;
       }        
        else if(count==20 || count==40) //20번, 40번 이동시 아이템 생성
        {
            randomDir=rand()%21;
            j = randomDir;
            randomDir=rand()%21;
            i = randomDir;
            num[i][j]=4;
        }
        else if(count%difficulty==0) //LV업 하면 몹이 더 자주나옴
        {           
            randomDir=rand()%21;            
            ghost[randomDir]++;
            randomDir=rand()%21;            
            skull[randomDir]++; 
        }                    
            
        for(i=0; i<21; i++)
        {
            if(ghost[i]!=0 && ghost[i]!=20) 
            {
                ghost[i]++; 
                num[ghost[i]][i]=3;                
                num[ghost[i]-1][i]=0;                             
            }                               
            else if(ghost[i]>=20)
            {
                num[ghost[i]][i]=0;  
                ghost[i]=0;                              
            }            
        } 

        for(i=0; i<21; i++)
        {
            if(skull[i]!=0 && skull[i]!=21) 
            {
                skull[i]++; 
                num[i][skull[i]]=5;                
                num[i][skull[i]-1]=0;                            
            }                               
            else if(ghost[i]>=21)
            {
                num[i][skull[i]]=0;  
                skull[i]=0;                              
            }            
        }      
         
        
        if(input=='w'&& k>1) //wd
        {               
            num[k][m]=0;  //기존에 있던 값을 0으로 초기화 시켜줘야 이동되는걸로 보이니까
            k--;
            if(num[k][m]==3 || num[k][m]==5)
            {   
                life--; //목숨 깎기   
                printf("      💔 몬스터를 만났습니다 LIFE -1 💔");          
            }
            else if(num[k][m]==4)
            {   
                score +=50; //아이템 먹으면 점수 오르게 
                //굳이 함수로 넣으면 score = getScore(score)
                printf("       ✨ 아이템 획득! SCORE + 50 ✨");             
            }                  
            num[k][m]=2;                            
        }
        else if(input=='s'&& k<20)
        {        
            num[k][m]=0;
            k++;
            if(num[k][m]==3 || num[k][m]==5)
            {
                life--;        
                printf("      💔 몬스터를 만났습니다 LIFE -1 💔");        
            }
            else if(num[k][m]==4)
            {
                score +=50;
                printf("       ✨ 아이템 획득! SCORE + 50 ✨");
              
            }  
            num[k][m]=2;                 
        }
        else if(input=='a'&& m>1)
        {            
            num[k][m]=0;
            m--;
           if(num[k][m]==3 || num[k][m]==5)
            {
                life--;      
                printf("      💔 몬스터를 만났습니다 LIFE -1 💔");         
            }
            else if(num[k][m]==4)
            {
                score +=50;
                printf("       ✨ 아이템 획득! SCORE + 50 ✨");
           
            }  
            num[k][m]=2;                  
        }
        else if(input=='d'&& m<20)
        {            
            num[k][m]=0;
            m++;
           if(num[k][m]==3 || num[k][m]==5)
            {
                life--;
                printf("      💔 몬스터를 만났습니다 LIFE -1 💔");
            }             
            else if(num[k][m]==4)
            {   
                score +=50;
                printf("       ✨ 아이템 획득! SCORE + 50 ✨");              
            }  
            num[k][m]=2;                 
        }     
        if(input=='f')  
            LV++;
    }//와일문     
}

int main(void)
{
    map();
    return 0;
}