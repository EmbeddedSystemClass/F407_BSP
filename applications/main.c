/*
 * @Description: 
 * @Author: zpw
 * @LastEditors: zpw
 * @Date: 2019-04-18 19:21:02
 * @LastEditTime: 2019-04-30 17:04:00
 */
/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *1
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 */

#include <rtthread.h>
#include <rtdevice.h>

#include <board.h>
#include "drv_usart.h"

#include "app_ae.h"
#include "app_tev.h"
#include "ledblink.h"

#include "modbus.h"

#define LOG_TAG "main"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

 rt_err_t tx_done(rt_device_t dev,void *buffer)
 {
     led_blink(2, 100, 100);
 	return 0;
 }
 void uarttest()
 {

 #define SAMPLE_UART_NAME "uart2"                               /* 串口设备名称 */
     static rt_device_t serial;                                 /* 串口设备句柄 */
     struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT; /* 配置参数 */
			serial = rt_device_find(SAMPLE_UART_NAME);
     config.baud_rate = BAUD_RATE_115200;
     config.data_bits = DATA_BITS_8;
     config.stop_bits = STOP_BITS_1;
     config.parity = PARITY_NONE;

     /* 打开设备后才可修改串口配置参数 */
 		 rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);
     //rt_device_control(serial, RT_DEVICE_DMA_CONFIG, &config);
     rt_device_set_tx_complete(serial, tx_done);

     rt_pin_mode(GET_PIN(A, 1), PIN_MODE_OUTPUT);
     rt_pin_write(GET_PIN(A, 1), 0);
     //static char str[] = "hello RT-Thread!\r\n";
     //rt_device_write(serial, 0, str, (sizeof(str) - 1));
 }



/* defined the LED0 pin: PB1 */
#define LED0_PIN GET_PIN(D, 13)
#define LED1_PIN GET_PIN(D, 14)
#define LED2_PIN GET_PIN(D, 15)
int main(void)
{

    int cnt = 0;

    led_add_device(LED0_PIN);
    led_add_device(LED1_PIN);
    led_add_device(LED2_PIN);

    led_on(1);

    led_blink(1, 500, 500);
    led_blink(2, 200, 200);
    led_blink(3, 100, 500);

    //uarttest();
    while (1)
    {
        cnt++;
        if (cnt == 1000)
            led_blink(1, 100, 1000);
        led_process(10);
        rt_thread_mdelay(10);
    }

    return RT_EOK;
}
