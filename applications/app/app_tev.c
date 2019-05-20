/*
 * @Description: 
 * @Author: zpw
 * @LastEditors: zpw
 * @Date: 2019-04-18 20:34:43
 * @LastEditTime: 2019-04-20 14:56:59
 */
#include "app_tev.h"

#define LOG_TAG "TEV"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

#define THREAD_STACK_SIZE 4096
#define THREAD_PRIORITY 6
#define THREAD_TIMESLICE 10

static rt_thread_t tev_rt_id = RT_NULL;

static int app_tev_init(void)
{
    rt_pin_mode(TEV_CTL_1A_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(TEV_CTL_1B_PIN, PIN_MODE_OUTPUT);
    rt_pin_mode(TEV_CTL_1C_PIN, PIN_MODE_OUTPUT);

    /* 创建线程 */
    tev_rt_id = rt_thread_create("tev",
                                 thread_entry, RT_NULL, /* 线程入口是thread_entry, 入口参数是1 */
                                 THREAD_STACK_SIZE, THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tev_rt_id != RT_NULL)
        rt_thread_startup(tev_rt_id);

    LOG_D("app tev init over");
    return RT_EOK;
}
/* start tev thread */
INIT_APP_EXPORT(app_tev_init);

/**
 * @brief 选择TEV输入通道
 * @note   
 * @param  ch: 1-8
 * @retval None
 */
void app_tev_ch_in(uint16_t ch)
{
    rt_pin_write(TEV_CTL_1A_PIN, ch & 1);
    rt_pin_write(TEV_CTL_1B_PIN, ch & (1 << 1));
    rt_pin_write(TEV_CTL_1C_PIN, ch & (1 << 2));
}

/**
 * @brief  线程入口
 * @note   
 * @param  parameter: 
 * @retval None
 */
static void thread_entry(void *parameter)
{

    while (1)
    {

        /* 休眠10个OS Tick */
        rt_thread_delay(10);
    }
}
