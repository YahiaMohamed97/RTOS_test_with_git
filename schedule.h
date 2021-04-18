#ifndef schedule_h
#define schedule_h
#include "Timer0.h"
#include "ADC_AVR.h"

typedef enum{
PERIODIC=0,
NOT_PERIODIC
}enum_task_periodicity;

typedef struct 
{
    void (*cb)(void);
    enum_task_periodicity period_type;
    uint8_t offset;
    uint8_t priority;
}str_task_cfg;

#define MAX_NUM_TASKS 10


void init_schedule(void);
void schedule_start(void);
//void add_task((void)*callBack(void),enum_task_periodicity periodicity , uint8_t offset);

void add_task(void *callBack(void),enum_task_periodicity periodicity , uint8_t offset);


#endif /* SCHEDULE_H_ */
