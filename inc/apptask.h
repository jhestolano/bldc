#ifndef APP_TASK_H
#define APP_TASK_H

#define APP_TASK_PRINTK_TS (1000)
#define APP_TASK_PRINTK_PRIO (1)
#define APP_TASK_PRINTK_STACK_SIZE (50)


#define APP_TASK_FLASH_TS (100)
#define APP_TASK_FLASH_PRIO (1)
#define APP_TASK_FLASH_STACK_SIZE (50)

void AppTask_PrintK(void* params);

void AppTask_Flash(void* params);

#endif // APP_TASK_H
