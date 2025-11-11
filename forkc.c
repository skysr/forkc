#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void task_run_one(void);
void task_run_two(void);
void task_run_three(void);
void task_run_four(void);
void task_run_five(void);
void task_run_six(void);

void task_schedule(void);
void task_time_schedule(void);
void task_start(int task_id, int time_interval);
int register_task(void);
void delay_1ms(void);

//定义十个任务的时间片
unsigned int task_time[10]={0,0,0,0,0,0,0,0,0,0};
//定时当前任务数量
unsigned int task_num=0;
//定时当前任务时间间隔，初设为600000ms,即是6分钟，不执行
unsigned int task_time_interval[10]={600000,600000,600000,600000,600000,600000,600000,600000,600000,600000};

//定时1ms
#define TIME_1MS 1000
void delay_1ms(void){
    usleep(TIME_1MS);
}

//时间片调度
void task_time_schedule(void){
    delay_1ms();
    //进行所有时间片的计数
    for(int i=0;i<task_num;i++){
        task_time[i]++;
    }
    //判断时间片是否超过120s，如果超过，则重置为0
    for(int i=0;i<task_num;i++){
        if(task_time[1] > 120000){
            task_time[1] = 0;
        }
    }
}

//注册任务
int register_task(void){
    //判断时间片是否都满了
    if(task_num<10){
        //注册任务
        task_num++;
        return task_num-1;
    }else{
        //打印错误信息
        printf("任务数量已满\n");
        return -1;
    }
}

//任务调度
void task_schedule(void){
    for(int i=0;i<task_num;i++){
        if (i==0 && task_time[i] > task_time_interval[i])
        {
            task_time[i] = 0;
            task_run_one();
        }
        if (i==1 && task_time[i] > task_time_interval[i]){
            task_time[i] = 0;
            task_run_two();
        }
        if (i==2 && task_time[i] > task_time_interval[i]){
            task_time[i] = 0;
            task_run_three();
        }
        if (i==3 && task_time[i] > task_time_interval[i]){
            task_time[i] = 0;
            task_run_four();
        }
        if (i==4 && task_time[i] > task_time_interval[i]){
            task_time[i] = 0;
            task_run_five();
        }
        if (i==5 && task_time[i] > task_time_interval[i]){
            task_time[i] = 0;
            task_run_six();
        }
    }
}

//开启任务
void task_start(int task_id, int time_interval){
    task_time_interval[task_id] = time_interval;
}

//任务1功能
void task_run_one(void){
    //执行任务
    printf("执行任务0\n");
}

//任务2功能
void task_run_two(void){
    //执行任务
    printf("执行任务1\n");
}

//任务3功能
void task_run_three(void){
    //执行任务
    printf("执行任务2\n");
}

//任务4功能
void task_run_four(void){
    //执行任务
    printf("执行任务3\n");
}

//任务5功能
void task_run_five(void){
    //执行任务
    printf("执行任务4\n");
}

//任务6功能
void task_run_six(void){
    //执行任务
    printf("执行任务5\n");
}


void main(){
    
    //注册任务1
    int task_one = register_task();
    if(task_one == -1){
        printf("注册任务失败\n");
        exit(1);
    }
    //设定任务执行时间间隔
    task_start(task_one,1000);
    printf("注册任务成功\t 任务编号:%d\n",task_one);

    //注册任务2
    int task_two = register_task();
    if(task_two == -1){
        printf("注册任务失败\n");
        exit(1);
    }
    task_start(task_two,1200);
    printf("注册任务成功\t 任务编号:%d\n",task_two);

    //注册任务3
    int task_three = register_task();
    if(task_three == -1){
        printf("注册任务失败\n");
        exit(1);
    }
    task_start(task_three,1500);
    printf("注册任务成功\t 任务编号:%d\n",task_three);

    //注册任务4
    int task_four = register_task();
    if(task_four == -1){
        printf("注册任务失败\n");
        exit(1);
    }
    task_start(task_four,2000);
    printf("注册任务成功\t 任务编号:%d\n",task_four);

    //注册任务5
    int task_five = register_task();
    if(task_five == -1){
        printf("注册任务失败\n");
        exit(1);
    }
    task_start(task_five,2500);
    printf("注册任务成功\t 任务编号:%d\n",task_five);

    //注册任务6
    int task_six = register_task();
    if(task_six == -1){
        printf("注册任务失败\n");
        exit(1);
    }
    task_start(task_six,5000);
    printf("注册任务成功\t 任务编号:%d\n",task_six);

    //执行时间片调度&&任务调度
    while(1){
        task_time_schedule();
        task_schedule();
    }
    exit(0);
}

