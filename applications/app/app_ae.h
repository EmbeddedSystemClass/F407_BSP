/*
 * @Description: 
 * @Author: zpw
 * @LastEditors: zpw
 * @Date: 2019-04-18 20:35:09
 * @LastEditTime: 2019-04-19 15:57:19
 */
#if !defined(APP_AE_H)
#define APP_AE_H

#include <rtdevice.h>
#include <board.h>


#define AE_CTL_1A_PIN    GET_PIN(D, 3)
#define AE_CTL_1B_PIN    GET_PIN(D, 4)
#define AE_CTL_1C_PIN    GET_PIN(D, 5)

#define AE_CTL_2A_PIN    GET_PIN(D, 6)
#define AE_CTL_2B_PIN    GET_PIN(D, 7)
#define AE_CTL_2C_PIN    GET_PIN(B, 3)


static void thread_entry(void *parameter);

#endif // APP_AE_H
