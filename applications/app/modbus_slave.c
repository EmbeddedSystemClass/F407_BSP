/*
 * @Description: 
 * @Author: zpw
 * @LastEditors: zpw
 * @Date: 2019-04-30 17:02:42
 * @LastEditTime: 2019-05-01 15:17:48
 */

#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>
#include "drv_usart.h"

#include "modbus_slave.h"
#include "modbus.h"

#define RS485_RE GET_PIN(A, 1)

static void test_thread(void *param)
{

#define SAMPLE_UART_NAME "uart2" /* 串口设备名称 */
    static struct rt_serial_device *serial;
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT; /* 配置参数 */

    static rt_device_t device; /* 串口设备句柄 */
    /* 查找串口设备 */
    device = rt_device_find(SAMPLE_UART_NAME);
    struct stm32_uart *uart = (struct stm32_uart *)(device->user_data);
    serial = &uart->serial;
    config.baud_rate = BAUD_RATE_115200;
    config.data_bits = DATA_BITS_8;
    config.stop_bits = STOP_BITS_1;
    config.parity = PARITY_NONE;

    modbus_t *ctx = RT_NULL;
    ctx = modbus_new_rtu(serial, &config);

    modbus_rtu_set_serial_mode(ctx, MODBUS_RTU_RS485);
    modbus_rtu_set_rts(ctx, RS485_RE, MODBUS_RTU_RTS_UP);
    modbus_set_slave(ctx, 1);
    modbus_connect(ctx);
    modbus_set_response_timeout(ctx, 0, 1000000);

    modbus_mapping_t *mb_mapping = NULL;
    mb_mapping = modbus_mapping_new(0, 0,
                                    5, 0);
    if (mb_mapping == NULL)
    {
        modbus_free(ctx);
        return;
    }

    int rc;
    uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
    uint8_t rsp[MAX_MESSAGE_LENGTH];
    for (;;)
    {

        rc = modbus_receive(ctx, query);
        if (rc > 0)
        {
            modbus_reply(ctx, query, rsp, rc, mb_mapping);
        }
        else if (rc == -1)
        {
            /* Connection closed by the client or error */
            //break;
        }
    }
}

static int rtu_test_init(void)
{
    rt_pin_mode(RS485_RE, PIN_MODE_OUTPUT);
    rt_thread_t tid;
    tid = rt_thread_create("test",
                           test_thread, RT_NULL,
                           2048,
                           12, 10);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
    return RT_EOK;
}
INIT_APP_EXPORT(rtu_test_init);
