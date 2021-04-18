#include "schedule.h"
#include "STD_TYPES.h"

str_task_cfg task_array[MAX_NUM_TASKS];
uint8_t task_number=0;

void init_schedule(void)
{
    Timer0Init();
    sei();
}
void add_task(void *callBack(void),enum_task_periodicity periodicity , uint8_t offset)
{
    task_array[task_number].cb = callBack;
    task_array[task_number].period_type = periodicity;
    task_array[task_number].offset = offset;
    task_number++;
}

//uint64_t Timer_counter=0;

void schedule_start(void)
{
    
    uint64_t millis=0;
    uint8_t i=0;
    while (1)
    {
        
        if (!(Timer_counter%4))
        {
            millis++;
            while (task_array[i].cb != 0)
            {
            	task_array[i].cb();
                if (millis%1000 == 0)
                {
                    TOGGLE_BIT(PORTA,4);          
                }
                i++;
            }
            i=0;
        }
        
    }
    
}
