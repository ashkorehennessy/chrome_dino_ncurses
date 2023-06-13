#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>//usleep函数
#include <time.h>//配合rand函数
#include <stdlib.h>//rand函数
#include "main.h"
#include "pattern.h"

#define KEY_SPACE 32
#define DAY     1
#define NIGHT   2


int gameState=0;//游戏状态      
double gameSpeed=1.2;//游戏速度
int frame=0;//当前运行帧
int score=0;//分数
int windowMaxX=0;//窗口长
int ground=0;//地面坐标
wchar_t key;//检测的按键

int gameStartAnimation(int *jumpArray, const Background *dirt, const Background *cloud){
        mvhline(ground-1, 20, '_', 16);//地板
        dinosaurStand(30,ground);
        mvprintw(ground/2,windowMaxX/2-20,"Press space to play");
        mvprintw(ground/2+1,windowMaxX/2-16,"or q to exit");
        refresh();
        //等待按键
        while(key!=' '){
                key=getch();
                if(key=='q')
                {
                        endwin();
                        return 1;
                }
        }
        //原地起跳
        for(int i=0;i<54;i++){
                dinosaurStand(30,ground-jumpArray[i]);
                mvhline(ground-1, 20, '_', 16);
                refresh();
                usleep(10000);
                clear();
        }
        //延展动画
        for(int X=36;X<windowMaxX;X++){
                mvhline(ground-1,5,'_',windowMaxX-3);
                for(int j=0;j<4;j++){
                        dirt1(dirt[j].X, ground);
                }
                for(int j=0;j<4;j++){
                        cloud1(cloud[j].X, cloud[j].Y);
                }
                for(int Y=0;Y<ground+2;Y++){
                        mvhline(Y,X,' ',windowMaxX-X);
                }
                dinosaurStand(30,ground);
                refresh();
                usleep(5000);
        }
        return 0;
}
void show_dino(const Dino *dino){
        //恐龙姿态显示
        int index = (frame%20 < 10 ? 1 : 2) + (dino->height == 5 ? 2 : 0) + (dino->Y < ground ? 4 : 0);
        switch (index)
        {
        case 1: dinosaur1(dino->X, dino->Y);break;//站立，脚步1
        case 2: dinosaur2(dino->X, dino->Y);break;//站立，脚步2
        case 3: dinosaur3(dino->X, dino->Y);break;//蹲下，脚步1
        case 4: dinosaur4(dino->X, dino->Y);break;//蹲下，脚步2
        default:dinosaurStand(dino->X, dino->Y);break;//滞空
        }
}
void update_background(Background *bg){
        bg->X -= bg->speed;
        if (bg->X < 0){
                if (bg->RandRange_X != 0) {
                        bg->X = windowMaxX + rand() % bg->RandRange_X + bg->RandOffset_X;
                } else {
                        bg->X = windowMaxX;
                }
                if (bg->RandRange_Y != 0) {
                        bg->Y = ground - rand() % bg->RandRange_Y - bg->RandOffset_Y;
                }
        }
}
void show_background(const Background *bg){
        switch (bg->ID) {
                case 0:
                        dirt1(bg->X,bg->Y);
                        break;
                case 1:
                        cloud1(bg->X,bg->Y);
                        break;
                case 2:
                        star1(bg->X,bg->Y);
                        break;
                default:
                        switch (bg->ID % 3) {
                                case 0:
                                        moon1(bg->X,bg->Y);
                                        break;
                                case 1:
                                        moon2(bg->X,bg->Y);
                                        break;
                                case 2:
                                        moon3(bg->X,bg->Y);
                                        break;
                        }
        }

    
}
void showBox(const Obstacle *obstacle) {
        switch (obstacle->ID)
        {
        case 1:cactus1(obstacle->X,obstacle->Y);break;
        case 2:cactus2(obstacle->X,obstacle->Y);break;
        case 3:cactus3(obstacle->X,obstacle->Y);break;
        case 4:cactus4(obstacle->X,obstacle->Y);break;
        case 5:cactus5(obstacle->X,obstacle->Y);break;
        case 6:cactus6(obstacle->X,obstacle->Y);break;
        case 7:
        case 8:
        case 9:
                if(frame%20 < 10) //鸟的扇翅动作
                {
                        bird1(obstacle->X,obstacle->Y);
                } else {
                        bird2(obstacle->X,obstacle->Y);
                } break;
        default:break;
        }
}
void refreshBox(Obstacle *obstacle,const float anotherObstacleX) {
        obstacle->ID=rand()%9+1;//随机障碍类型
        obstacle->X=anotherObstacleX+rand()%150+75*gameSpeed;//更新X坐标为另一个障碍X坐标+随机数
        if(obstacle->ID > 6)//障碍类型为鸟时随机高度
        {
                obstacle->Y=ground-rand()%12;
        }
        else
        {
                obstacle->Y=ground;
        }
        switch(obstacle->ID)
        {
        case 1: obstacle->length=11;  obstacle->height=6; break;//仙人掌1
        case 2: obstacle->length=16;  obstacle->height=6; break;//仙人掌2
        case 3: obstacle->length=22;  obstacle->height=6; break;//仙人掌3
        case 4: obstacle->length=14;  obstacle->height=9; break;//仙人掌4
        case 5: obstacle->length=20;  obstacle->height=9; break;//仙人掌5
        case 6: obstacle->length=28;  obstacle->height=9; break;//仙人掌6
        case 7:
        case 8:
        case 9: obstacle->length=20;  obstacle->height=7; break;//鸟
        default:break;
        }
}
int hitBox(const Dino *dino, const Obstacle *obstacle) {
        //碰头，碰脚，碰手检测
        if(((dino->X > obstacle->X)  &&  (dino->X < obstacle->X + obstacle->length)) && ((dino->Y > obstacle->Y - obstacle->height)  &&  (dino->Y - dino->height < obstacle->Y))) {
                return 1;
        } else {
                return 0;
        }
}
int getHistoryScore() {
        FILE *fp=fopen("record.dat","rb");
                if(fp==NULL) // 打开失败，创建新文件
                {
                        fp=fopen("record.dat","wb");
                        if(fp==NULL)// 文件创建失败 
                        {
                                return -1;
                        }
                        int x=0; // 默认写0
                        fwrite(&x,sizeof(int),1,fp);
                        fclose(fp);
                        return x;
                }
        int x;
        fread(&x,sizeof(int),1,fp);
        fclose(fp);
        return x;
}
int main()
{
        initscr();
        start_color();//启用颜色支持
        init_pair(DAY,COLOR_BLACK,COLOR_WHITE);//白天
        init_pair(NIGHT,COLOR_WHITE,COLOR_BLACK);//黑夜
        bkgd(COLOR_PAIR(DAY));//白天
        attrset(A_BOLD);//加粗字体
        srand((unsigned)time(NULL));
        nodelay(stdscr, TRUE);//取消等待按键输入
        cbreak();
        noecho();//禁用输入显示
        keypad(stdscr, TRUE);//读取上下箭头等特殊按键
        windowMaxX=getmaxx(stdscr);//窗口长
        ground=getmaxy(stdscr)-4;//地板Y坐标
        int downKeyDelay=0;//蹲下延时帧
        int jumpArray[]={0,1,3,4,5,6,7,8,9,10,11,12,13,13,14,15,15,16,16,17,17,17,18,18,18,18,18,18,18,18,18,18,17,17,17,16,16,16,15,14,14,13,12,11,11,10,9,8,7,6,5,4,3,2,0};//跳跃高度
        int jumpFrame;//跳跃过程帧
        int checkObstacle;

        //初始化背景类
        Background dirt[4] = {0};
        for(int i=0;i<4;i++){
                dirt[i].ID = 0;
                dirt[i].X = windowMaxX / 4 * i;
                dirt[i].Y = ground;
                dirt[i].speed = gameSpeed;
                dirt[i].RandRange_X = 50;
        }
        Background cloud[4] = {0};
        for(int i=0;i<4;i++){
                cloud[i].ID = 1;
                cloud[i].X = windowMaxX / 4 * i;
                cloud[i].Y = ground - rand()%12 - 12;
                cloud[i].speed = 0.5;
                cloud[i].RandRange_X = 60;
                cloud[i].RandOffset_X = 30;
                cloud[i].RandRange_Y = 12;
                cloud[i].RandOffset_Y = 12;
        }
        Background star[4] = {0};
        for(int i=0;i<4;i++){
                star[i].ID = 2;
                star[i].X = windowMaxX / 4 * i;
                star[i].Y = ground - rand()%14 - 8;
                star[i].speed = 0.25;
                star[i].RandRange_X = 70;
                star[i].RandOffset_X = 30;
                star[i].RandRange_Y = 14;
                star[i].RandOffset_Y = 8;
        }
        Background moon[1]={
                {.ID=3, .X=windowMaxX, .Y=ground-18, .speed=0.1}
        };
        clear();
        //开场动画
        if(gameStartAnimation(jumpArray,dirt,cloud)==1)
        {
                //开局退出
                endwin();
                return 0;
        }
        while(1)
        {
                clear();
                frame=0;
                jumpFrame=0;
                int history=getHistoryScore();
                if(history==-1)//历史文件异常
                {
                        endwin();
                        printf("ERROR: Can not create record file\nPlease check Permission or disk");
                        return -1;  
                }
                Dino dino={
                        .X=30,
                        .Y=ground,
                        .length=10,
                        .height=9
                };
                Obstacle obstacle1={
                        .ID=1,
                        .X=400,
                        .Y=ground,
                        .length=13,
                        .height=6
                };
                Obstacle obstacle2={
                        .ID=2,
                        .X=600,
                        .Y=ground,
                        .length=18,
                        .height=6
                };
                Obstacle *detectObstacle=&obstacle1;//正在检测的障碍物
                Obstacle *unDetectObstacle=&obstacle2;//未检测的障碍物
                //游戏主体
                checkObstacle=1;
                gameState=1;
                while (gameState)
                {
                        clear();//清除上一帧绘制的内容
                        key=getch();
                        if ((key == KEY_SPACE || key == KEY_UP) && jumpFrame == 0) {//检测到空格或上键且没有滞空
                                jumpFrame = 54;
                        }
                        if(jumpFrame>0) {//滞空中
                                jumpFrame--;
                                downKeyDelay=0;//中断蹲下
                                dino.Y=ground-jumpArray[jumpFrame];//恐龙高度
                        } else {
                                if(key == KEY_DOWN) {
                                        downKeyDelay=30;//下蹲延迟
                                } else {
                                        downKeyDelay--;
                                } 
                        } 
                        if (downKeyDelay>0) {
                                dino.height=5;//下蹲
                        } else {
                                dino.height=9;//站立
                        }
                        mvhline(ground-1, 1, '_', windowMaxX - 3);//显示地板
                        //昼夜切换
                        if(score%1000<500) {
                                bkgd(COLOR_PAIR(DAY));//背景切换白天
                        } else {
                                if(score%1000==500){//500、1500、2500分时更新月亮
                                        moon->ID++;
                                        moon->X=windowMaxX;//月亮拉到右侧
                                }
                                bkgd(COLOR_PAIR(NIGHT));//背景切换黑夜
                                for(int i=0;i<4;i++){
                                        update_background(&star[i]);//更新星星坐标
                                        show_background(&star[i]);//显示星星
                                }
                                update_background(moon);//更新月亮坐标
                                show_background(moon);//显示月亮
                        }
                        for(int i=0;i<4;i++){
                                update_background(&dirt[i]);//更新碎石坐标
                                update_background(&cloud[i]);//更新云坐标
                                show_background(&dirt[i]);
                                show_background(&cloud[i]);
                        }
                        showBox(&obstacle1);//显示障碍1
                        showBox(&obstacle2);//显示障碍2
                        //碰撞检测并显示相应恐龙
                        if (hitBox(&dino, detectObstacle) == 1) {
                                dinosaurFail(dino.X, dino.Y);
                                gameState = 0;
                        } else {
                                show_dino(&dino);
                        }
                        //mvprintw(1,windowMaxX-60,"INPUT KEY:%d",key);//输出当前按键
                        //mvprintw(1,windowMaxX-45,"FRAME:%d",frame);//输出当前帧
                        mvprintw(1,windowMaxX-30,"HI SCORE:%d",history);//输出最高分
                        mvprintw(1,windowMaxX-15,"SCORE:%d",score);//输出分数
                        obstacle1.X-=gameSpeed;//移动障碍1
                        obstacle2.X-=gameSpeed;//移动障碍2
                        //障碍刷新
                        if(detectObstacle->X <= 0) {
                                refreshBox(detectObstacle,unDetectObstacle->X);
                                //转换检测的障碍
                                if(checkObstacle == 1) {
                                        checkObstacle=2;
                                        detectObstacle=&obstacle2;
                                        unDetectObstacle=&obstacle1;
                                } else {
                                        checkObstacle=1;
                                        detectObstacle=&obstacle1;
                                        unDetectObstacle=&obstacle2;
                                }
                        }
                        frame++;
                        score=frame/5;
                        //游戏速度
                        if(score<160)           gameSpeed = 1.2;
                        else if(score<280)      gameSpeed = 1.5;
                        else if (score<400)     gameSpeed = 1.8;
                        else                    gameSpeed = 2.4;
                        for(int i=0;i<4;i++){
                                dirt[i].speed = gameSpeed;
                        }
                        refresh();
                        usleep(10000);
                }

                //游戏结束
                mvprintw(ground/2,windowMaxX/2-4,"GAME OVER");
                mvprintw(ground/2+2,windowMaxX/2-11,"Press space to restart");
                mvprintw(ground/2+3,windowMaxX/2-6,"or q to exit");
                if (score > history) { //破纪录
                        FILE *fp = fopen("record.dat", "wb");
                        fwrite(&score, sizeof(int), 1, fp);
                        fclose(fp);
                        mvprintw(ground/2+1,windowMaxX/2-7,"NEW RECORD:%d",score); 
                } else {
                        mvprintw(ground/2+1,windowMaxX/2-6,"YOUR SCORE:%d",score);
                }
                refresh();
                //是否重开
                while(key!=' ') {
                        key=getch();
                        if(key=='q') {
                                endwin();
                                return 0;
                        }
                }   
        }
}