/*
 * @Description: 
 * @Author: zpw
 * @LastEditors: zpw
 * @Date: 2019-04-18 19:21:03
 * @LastEditTime: 2019-04-29 21:03:08
 */
/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018.10.30     SummerGift   first version
 * 2019.03.05     whj4674672   add stm32h7 
 */

#ifndef __DRV_USART_H__
#define __DRV_USART_H__

#include <rtthread.h>
#include "rtdevice.h"
#include <rthw.h>
#include <drv_common.h>
#include "drv_dma.h"

int rt_hw_usart_init(void);

#if defined(SOC_SERIES_STM32F0) || defined(SOC_SERIES_STM32F1) || defined(SOC_SERIES_STM32L4) \
    || defined(SOC_SERIES_STM32L0) || defined(SOC_SERIES_STM32G0)
#define DMA_INSTANCE_TYPE              DMA_Channel_TypeDef
#elif defined(SOC_SERIES_STM32F4) || defined(SOC_SERIES_STM32F7) || defined(SOC_SERIES_STM32H7)
#define DMA_INSTANCE_TYPE              DMA_Stream_TypeDef
#endif /*  defined(SOC_SERIES_STM32F1) || defined(SOC_SERIES_STM32L4) */

#if defined(SOC_SERIES_STM32F1) || defined(SOC_SERIES_STM32L4) || defined(SOC_SERIES_STM32F4) \
    || defined(SOC_SERIES_STM32L0) || defined(SOC_SERIES_STM32G0)
#define UART_INSTANCE_CLEAR_FUNCTION    __HAL_UART_CLEAR_FLAG
#elif defined(SOC_SERIES_STM32F7) || defined(SOC_SERIES_STM32F0) || defined(SOC_SERIES_STM32H7)
#define UART_INSTANCE_CLEAR_FUNCTION    __HAL_UART_CLEAR_IT
#endif

/* stm32 config class */
struct stm32_uart_config
{
    const char *name;
    USART_TypeDef *Instance;
    IRQn_Type irq_type;
    struct dma_config *dma_rx;
};

/* stm32 uart dirver class */
struct stm32_uart
{
    UART_HandleTypeDef handle;
    struct stm32_uart_config *config;
    
#ifdef RT_SERIAL_USING_DMA
 
        rt_size_t last_index;
  
#endif
    rt_uint8_t uart_dma_flag;
    struct rt_serial_device serial;
};

#define RT_DEVICE_DMA_CONFIG    0x50


#endif  /* __DRV_USART_H__ */
