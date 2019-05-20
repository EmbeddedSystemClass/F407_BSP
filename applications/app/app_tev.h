/*
 * @Description: 
 * @Author: zpw
 * @LastEditors: zpw
 * @Date: 2019-04-18 20:35:16
 * @LastEditTime: 2019-04-20 14:57:12
 */
#if !defined(APP_TEV_H)
#define APP_TEV_H

#include <rtdevice.h>
#include <board.h>

#define TEV_CTL_1A_PIN GET_PIN(C, 10)
#define TEV_CTL_1B_PIN GET_PIN(C, 11)
#define TEV_CTL_1C_PIN GET_PIN(C, 12)

#define TEV_CTL_2A_PIN GET_PIN(D, 0)
#define TEV_CTL_2B_PIN GET_PIN(D, 1)
#define TEV_CTL_2C_PIN GET_PIN(D, 2)


static void thread_entry(void *parameter);

#endif // APP_TEV_H
