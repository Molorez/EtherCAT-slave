/****************************************Copyright (c)****************************************************
**
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               SPI1.h
** Descriptions:            SPI1 hardware driver for STM32F4 + LAN9252 ESC
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Version:                 v2.0
** Descriptions:            Ported from PIC to STM32F4
**
*********************************************************************************************************/

#ifndef _TOUCHPANEL_H_
#define _TOUCHPANEL_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


#define SPIx                           SPI1
#define SPIx_CLK                       RCC_APB2Periph_SPI1
#define SPIx_CLK_INIT                  RCC_APB2PeriphClockCmd

#define SPIx_SCK_PIN                   GPIO_Pin_5
#define SPIx_SCK_GPIO_PORT             GPIOA
#define SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
#define SPIx_SCK_SOURCE                GPIO_PinSource5
#define SPIx_SCK_AF                    GPIO_AF_SPI1

#define SPIx_MISO_PIN                  GPIO_Pin_6
#define SPIx_MISO_GPIO_PORT            GPIOA
#define SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define SPIx_MISO_SOURCE               GPIO_PinSource6
#define SPIx_MISO_AF                   GPIO_AF_SPI1

#define SPIx_MOSI_PIN                  GPIO_Pin_7
#define SPIx_MOSI_GPIO_PORT            GPIOA
#define SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define SPIx_MOSI_SOURCE               GPIO_PinSource7
#define SPIx_MOSI_AF                   GPIO_AF_SPI1

/*-----------------------------------------------------------------------------
 * GPIO Bit Set/Reset (STM32F4 uses single BSRR register)
 *   BSRR[15:0]  (BS): write 1 = set output high
 *   BSRR[31:16] (BR): write 1 = reset output low
 * CS (PA4) is active-low: SELECT = CS low, DESELECT = CS high
 *-----------------------------------------------------------------------------*/
#define SELECT_SPI       GPIOA->BSRR = (uint32_t)GPIO_Pin_4 << 16;
#define DESELECT_SPI     GPIOA->BSRR = GPIO_Pin_4;

#define CSLOW()          SELECT_SPI
#define CSHIGH()         DESELECT_SPI

/*-----------------------------------------------------------------------------
 * SPI hardware abstraction (PIC register names → STM32F4)
 *-----------------------------------------------------------------------------*/
#define SPI1_BUF              SPI1->DR
#define SPI1_ClearRxFlag()    do { volatile uint8_t _dummy = (uint8_t)SPI1->DR; (void)_dummy; } while(0)
#define WAIT_SPI_IF           while(!(SPI1->SR & SPI_I2S_FLAG_RXNE));
#define SPI1_CON1             SPI1->CR1
#define SPI1_CON1_VALUE       0x037C
#define SPI1_STAT             SPI1->SR
#define SPI1_STAT_VALUE       0x00

#define SPIWriteByte          SPIWrite
#define SPIReadByte()         SPIRead()

/*-----------------------------------------------------------------------------
 * Interrupt macros
 *   ESC IRQ (AL Event):  PC0 -> EXTI0
 *   SYNC0:               PC3 -> EXTI3
 *   SYNC1:               PC1 -> EXTI1
 *-----------------------------------------------------------------------------*/
#define PORT_CFG                  SPI1_GPIO_Init()

#define INIT_ESC_INT              IRQ_EXTI0_Configuration();
#define ENABLE_ESC_INT()          NVIC_EnableIRQ(EXTI0_IRQn)
#define DISABLE_ESC_INT()         NVIC_DisableIRQ(EXTI0_IRQn)
#define ACK_ESC_INT               EXTI_ClearITPendingBit(EXTI_Line0)

#define DISABLE_AL_EVENT_INT      NVIC_DisableIRQ(EXTI0_IRQn)
#define ENABLE_AL_EVENT_INT       NVIC_EnableIRQ(EXTI0_IRQn)

#define INIT_SYNC0_INT            SYNC0_EXTI3_Configuration();
#define ENABLE_SYNC0_INT          NVIC_EnableIRQ(EXTI3_IRQn)
#define ACK_SYNC0_INT             EXTI_ClearITPendingBit(EXTI_Line3)

#define INIT_SYNC1_INT            SYNC1_EXTI2_Configuration();
#define ENABLE_SYNC1_INT          NVIC_EnableIRQ(EXTI1_IRQn)
#define ACK_SYNC1_INT             EXTI_ClearITPendingBit(EXTI_Line1)

/*-----------------------------------------------------------------------------
 * Timer macros (TIM2 @ 2MHz = 2000 ticks/ms)
 *-----------------------------------------------------------------------------*/
#define ECAT_TIMER_INC_P_MS       2000
#define INIT_ECAT_TIMER           TIM_Configuration(10)
#define START_ECAT_TIMER          TIM_Cmd(TIM2, ENABLE)
#define HW_GetTimer()             TIM2->CNT

/*-----------------------------------------------------------------------------
 * Global interrupt enable
 *-----------------------------------------------------------------------------*/
#define ENABLE_GLOBAL_INT         __enable_irq()

// *****************************************************************************
// Section: File Scope or Global Data Types
// *****************************************************************************
#define CMD_SERIAL_READ           0x03
#define CMD_FAST_READ             0x0B
#define CMD_DUAL_OP_READ          0x3B
#define CMD_DUAL_IO_READ          0xBB
#define CMD_QUAD_OP_READ          0x6B
#define CMD_QUAD_IO_READ          0xEB
#define CMD_SERIAL_WRITE          0x02
#define CMD_DUAL_DATA_WRITE       0x32
#define CMD_DUAL_ADDR_DATA_WRITE  0xB2
#define CMD_QUAD_DATA_WRITE       0x62
#define CMD_QUAD_ADDR_DARA_WRITE  0xE2

#define CMD_SERIAL_READ_DUMMY     0
#define CMD_FAST_READ_DUMMY       1
#define CMD_DUAL_OP_READ_DUMMY    1
#define CMD_DUAL_IO_READ_DUMMY    2
#define CMD_QUAD_OP_READ_DUMMY    1
#define CMD_QUAD_IO_READ_DUMMY    4
#define CMD_SERIAL_WRITE_DUMMY    0
#define CMD_DUAL_DATA_WRITE_DUMMY 0
#define CMD_DUAL_ADDR_DATA_WRITE_DUMMY 0
#define CMD_QUAD_DATA_WRITE_DUMMY 0
#define CMD_QUAD_ADDR_DARA_WRITE_DUMMY 0

// ESC (LAN9252) CSR registers
#define ESC_CSR_CMD_REG           0x304
#define ESC_CSR_DATA_REG          0x300
#define ESC_WRITE_BYTE            0x80
#define ESC_READ_BYTE             0xC0
#define ESC_CSR_BUSY              0x80

// LAN9252 Process RAM (PRAM) direct access registers
#define PRAM_READ_CMD_REG         0x01F4
#define PRAM_READ_ADDR_LEN_REG    0x01F8
#define PRAM_READ_FIFO_REG        0x01FC
#define PRAM_WRITE_CMD_REG        0x01E4
#define PRAM_WRITE_ADDR_LEN_REG   0x01E8
#define PRAM_WRITE_FIFO_REG       0x01EC

// PRAM bit masks
#define PRAM_RW_ABORT_MASK        0x00000001
#define PRAM_RW_BUSY_8B           0x80
#define PRAM_RW_BUSY_32B          0x80000000
#define IS_PRAM_SPACE_AVBL_MASK   0x01
#define PRAM_SPACE_AVBL_COUNT_MASK 0x1F

/////////////////////////////////////////////////////////////////////////////////

typedef union
{
    uint32_t Val;
    uint8_t v[4];
    uint16_t w[2];
    struct
    {
        uint8_t LB;
        uint8_t HB;
        uint8_t UB;
        uint8_t MB;
    }byte;
} UINT32_VAL;

typedef union
{
    uint16_t Val;
    struct
    {
        uint8_t LB;
        uint8_t HB;
    }byte;
} UINT16_VAL;

///////////////////////////////////////////////////////////////////////////////////////

/* Private function prototypes -----------------------------------------------*/
void SPI1_GPIO_Init(void);
uint8_t WR_CMD(uint8_t cmd);
void ADC_GPIO_Configuration(void);
void ADC_Configuration(void);
void NVIC_Configuration(void);
void TIM_Configuration(uint8_t period);
void EXTI1_Configuration(void);
void EXTI2_Configuration(void);
void EXTI3_Configuration(void);
void IRQ_EXTI0_Configuration(void);
void SYNC0_EXTI3_Configuration(void);
void SYNC1_EXTI2_Configuration(void);
void SPIReadDRegister(uint8_t *ReadBuffer, uint16_t Address, uint16_t Count);
void SPIWriteRegister(uint8_t *WriteBuffer, uint16_t Address, uint16_t Count);
uint32_t SPIReadDWord(uint16_t Address);
void SPIWriteDWord(uint16_t Address, uint32_t Val);
void SPIWrite(uint8_t data);
uint8_t SPIRead(void);

void mem_test(void);
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
