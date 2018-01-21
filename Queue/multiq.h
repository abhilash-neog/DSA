#include<stdio.h>
#include<stdlib.h>
#include "que.h"

typedef struct MQ* MultiQ;
typedef struct ArrElement* arr;
typedef struct task* Task;

struct task{
int taskID;//taskID becomes the key
int priority;
};

struct ArrElement{
Queue que;
int priority;
//arr next;
};

struct MQ{
struct ArrElement* arrEle;
int count;
};
MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq); 
MultiQ delNextMQ(MultiQ mq);
Boolean isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int p);
Queue getQueueFromMQ(MultiQ, int p);
