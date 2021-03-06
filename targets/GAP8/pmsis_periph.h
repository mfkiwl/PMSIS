/*
** ###################################################################
**     Processors:          GAP8
**
**     Compilers:           GNU C Compiler
**
**     Reference manual:    riscv-spec-v2.1, January 2017
**     Version:             rev. 2.9, 2017-07-19
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GAP8
**
**     Copyright (c) 2015 - 2018 GreenWave Technologies, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of GreenWaves Technologies, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 http://greenwaves-technologies.com
**     mail:                 jie.chen@greenwaves-technologies.com
**
**     Revisions:
**     - rev. 1.0 (2017-07-19)
**         Initial version.
** ###################################################################
*/

/*!
 * @file GAP8.h
 * @version 1.0
 * @date 2017-07-19
 * @brief CMSIS Peripheral Access Layer for GAP8
 *
 * CMSIS Peripheral Access Layer for GAP8
 */

#ifndef _PMSIS_PERIPH_GAP8_H_
#define _PMSIS_PERIPH_GAP8_H_                        /**< Symbol preventing repeated inclusion */
/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */
/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS  32                  /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  FC_NOTIFY_CLUSTER_EVENT      = 0,                /**< Software event interrupt */
  CLUSTER_NOTIFY_FC_EVENT      = 1,                /**< Software event interrupt */
  FC_SW_NOTIFY_BRIDGE_EVENT    = 2,                /**< Software event interrupt */
  FC_SW_NOTIFY_EVENT           = 3,                /**< Software event interrupt */
  CLUSTER_NOTIFY_FC_IRQN       = 4,                /**< Software event interrupt */
  PENDSV_IRQN                  = 7,                /**< Software event U -> M PendSV interrupt */

  /* Device specific interrupts */
  DMA_EVT_IRQN                 = 8,                /**< DMA event interrupt */
  DMA_IRQN                     = 9,                /**< DMA interrupt */
  FC_TIMER0_IRQN               = 10,               /**< FC timer0 event interrupt */
  SYSTICK_IRQN                 = 10,               /**< GAP8 U -> M System Tick Interrupt */
  FC_TIMER1_IRQN               = 11,               /**< FC timer1 interrupt */

  EU_HWCE_EVENT                = 12,              /**< GAP8 HWCE SW Event */
  EU_HW_BARRIER_EVENT          = 16,              /**< GAP8 Hardware Barrier SW Event */
  EU_MUTEX_EVENT               = 17,              /**< GAP8 Mutex SW Event */
  EU_DISPATCH_EVENT            = 18,              /**< GAP8 Dispatch SW Event */
  EU_LOOP_EVENT                = 19,              /**< GAP8 Loop SW Event */

  /* Fault interrupts */
  FC_SOC_EVENT_IRQN            = 27,              /**< GAP8 SoC Event Interrupt */
  MPU_ERROR_IRQN               = 28,              /**< GAP8 MPU Error Interrupt */
  ERR_EVENT_IRQN               = 29,              /**< GAP8 Event Error Interrupt */

  /* Core interrupts */
  RST_HANDLER_IRQN             = 32,              /**< GAP8 Reset handler Interrupt */
  ILL_INS_IRQN                 = 33,              /**< GAP8 Usage Fault Interrupt */
  SVCALL_IRQN                  = 34               /**< GAP8 SV Call Interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- GAP8 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GAP8_Core_Configuration GAP8 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               0         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  0         /**< Defines if an FPU is present or not */

#include "core_gap.h"              /* Core Peripheral Access Layer */
#include "core_gap_memory_define.h"       /* Core Memory regions definitions */

#ifdef FEATURE_CLUSTER
#include "core_gap_cluster.h"              /* Cluster Access Layer */
#endif

#include "system_GAP8.h"            /* Device specific configuration file */

/*!
 * @}
 */ /* end of group GAP8_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
/*!
 * @addtogroup udma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*!
 * @}
 */ /* end of group udma_request */



/*!
 * @}
 */ /* end of group Mapping_Information */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */

/* ----------------------------------------------------------------------------
   -- FLL_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLL_CTRL_Peripheral_Access_Layer FLL_CTRL Peripheral Access Layer
 * @{
 */

/** FLL_CTRL - Registers Layout Typedef */
typedef struct {
  __IO  uint32_t SOC_FLL_STATUS;            /**< FLL_CTRL Status register, offset: 0x00 */
  __IO  uint32_t SOC_CONF1;                 /**< FLL_CTRL Configuration1 register, offset: 0x04 */
  __IO  uint32_t SOC_CONF2;                 /**< FLL_CTRL Configuration2 register, offset: 0x08 */
  __IO  uint32_t SOC_INTEGRATOR;            /**< FLL_CTRL INTEGRATOR register, offset: 0x0C */
  __IO  uint32_t CLUSTER_FLL_STATUS;        /**< FLL_CTRL Status register, offset: 0x10 */
  __IO  uint32_t CLUSTER_CONF1;             /**< FLL_CTRL Configuration1 register, offset: 0x14 */
  __IO  uint32_t CLUSTER_CONF2;             /**< FLL_CTRL Configuration2 register, offset: 0x18 */
  __IO  uint32_t CLUSTER_INTEGRATOR;        /**< FLL_CTRL INTEGRATOR register, offset: 0x1C */
  __IO  uint32_t FLL_CONVERGE;              /**< FLL_CTRL Fll Converge register, offset: 0x20 */

} FLL_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- FLL_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLL_CTRL_Register_Masks FLL_CTRL Register Masks
 * @{
 */
/*! @name FLL_STATUS - FLL_CTRL status register */
#define FLL_CTRL_STATUS_MULTI_FACTOR_MASK              (0xFFFFU)
#define FLL_CTRL_STATUS_MULTI_FACTOR_SHIFT             (0U)
#define FLL_CTRL_STATUS_MULTI_FACTOR(x)                (((uint32_t)(((uint32_t)(x)) /* << FLL_CTRL_STATUS_MULTI_FACTOR_SHIFT */)) & FLL_CTRL_STATUS_MULTI_FACTOR_MASK)
#define READ_FLL_CTRL_STATUS_MULTI_FACTOR(x)           (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_STATUS_MULTI_FACTOR_MASK)) /*>> FLL_CTRL_STATUS_MULTI_FACTOR_SHIFT*/)

/*! @name SOC_CONF1 - FLL_CTRL configuration 1 register */
#define FLL_CTRL_CONF1_MULTI_FACTOR_MASK           (0xFFFFU)
#define FLL_CTRL_CONF1_MULTI_FACTOR_SHIFT          (0U)
#define FLL_CTRL_CONF1_MULTI_FACTOR(x)             (((uint32_t)(((uint32_t)(x)) /* << FLL_CTRL_CONF1_MULTI_FACTOR_SHIFT */)) & FLL_CTRL_CONF1_MULTI_FACTOR_MASK)
#define READ_FLL_CTRL_CONF1_MULTI_FACTOR(x)        (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF1_MULTI_FACTOR_MASK)) /*>> FLL_CTRL_CONF1_MULTI_FACTOR_SHIFT*/)

#define FLL_CTRL_CONF1_DCO_INPUT_MASK              (0x3FF0000U)
#define FLL_CTRL_CONF1_DCO_INPUT_SHIFT             (16U)
#define FLL_CTRL_CONF1_DCO_INPUT(x)                (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF1_DCO_INPUT_SHIFT)) & FLL_CTRL_CONF1_DCO_INPUT_MASK)
#define READ_FLL_CTRL_CONF1_DCO_INPUT(x)           (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF1_DCO_INPUT_MASK)) >> FLL_CTRL_CONF1_DCO_INPUT_SHIFT)

#define FLL_CTRL_CONF1_CLK_OUT_DIV_MASK            (0x3C000000U)
#define FLL_CTRL_CONF1_CLK_OUT_DIV_SHIFT           (26U)
#define FLL_CTRL_CONF1_CLK_OUT_DIV(x)              (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF1_CLK_OUT_DIV_SHIFT)) & FLL_CTRL_CONF1_CLK_OUT_DIV_MASK)
#define READ_FLL_CTRL_CONF1_CLK_OUT_DIV(x)         (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF1_CLK_OUT_DIV_MASK)) >> FLL_CTRL_CONF1_CLK_OUT_DIV_SHIFT)

#define FLL_CTRL_CONF1_OUTPUT_LOCK_EN_MASK         (0x40000000U)
#define FLL_CTRL_CONF1_OUTPUT_LOCK_EN_SHIFT        (30U)
#define FLL_CTRL_CONF1_OUTPUT_LOCK_EN(x)           (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF1_OUTPUT_LOCK_EN_SHIFT)) & FLL_CTRL_CONF1_OUTPUT_LOCK_EN_MASK)
#define READ_FLL_CTRL_CONF1_OUTPUT_LOCK_EN(x)      (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF1_OUTPUT_LOCK_EN_MASK)) >> FLL_CTRL_CONF1_OUTPUT_LOCK_EN_SHIFT)

#define FLL_CTRL_CONF1_MODE_MASK                   (0x80000000U)
#define FLL_CTRL_CONF1_MODE_SHIFT                  (31U)
#define FLL_CTRL_CONF1_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF1_MODE_SHIFT)) & FLL_CTRL_CONF1_MODE_MASK)
#define READ_FLL_CTRL_CONF1_MODE(x)                (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF1_MODE_MASK)) >> FLL_CTRL_CONF1_MODE_SHIFT)

/*! @name SOC_CONF2 - FLL_CTRL configuration 2 register */
#define FLL_CTRL_CONF2_LOOPGAIN_MASK               (0xFU)
#define FLL_CTRL_CONF2_LOOPGAIN_SHIF  T            (0U)
#define FLL_CTRL_CONF2_LOOPGAIN(x)                 (((uint32_t)(((uint32_t)(x)) /* << FLL_CTRL_CONF2_LOOPGAIN_SHIFT */)) & FLL_CTRL_CONF2_LOOPGAIN_MASK)
#define READ_FLL_CTRL_CONF2_LOOPGAIN(x)            (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_LOOPGAIN_MASK))/* >> FLL_CTRL_CONF2_LOOPGAIN_SHIFT*/)

#define FLL_CTRL_CONF2_DEASSERT_CYCLES_MASK        (0x3F0U)
#define FLL_CTRL_CONF2_DEASSERT_CYCLES_SHIFT       (4U)
#define FLL_CTRL_CONF2_DEASSERT_CYCLES(x)          (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF2_DEASSERT_CYCLES_SHIFT)) & FLL_CTRL_CONF2_DEASSERT_CYCLES_MASK)
#define READ_FLL_CTRL_CONF2_DEASSERT_CYCLES(x)     (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_DEASSERT_CYCLES_MASK)) >> FLL_CTRL_CONF2_DEASSERT_CYCLES_SHIFT)

#define FLL_CTRL_CONF2_ASSERT_CYCLES_MASK          (0xFC00U)
#define FLL_CTRL_CONF2_ASSERT_CYCLES_SHIFT         (10U)
#define FLL_CTRL_CONF2_ASSERT_CYCLES(x)            (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF2_ASSERT_CYCLES_SHIFT)) & FLL_CTRL_CONF2_ASSERT_CYCLES_MASK)
#define READ_FLL_CTRL_CONF2_ASSERT_CYCLES(x)       (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_ASSERT_CYCLES_MASK)) >> FLL_CTRL_CONF2_ASSERT_CYCLES_SHIFT)

#define FLL_CTRL_CONF2_LOCK_TOLERANCE_MASK         (0xFFF0000U)
#define FLL_CTRL_CONF2_LOCK_TOLERANCE_SHIFT        (16U)
#define FLL_CTRL_CONF2_LOCK_TOLERANCE(x)           (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF2_LOCK_TOLERANCE_SHIFT)) & FLL_CTRL_CONF2_LOCK_TOLERANCE_MASK)
#define READ_FLL_CTRL_CONF2_LOCK_TOLERANCE(x)      (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_LOCK_TOLERANCE_MASK)) >> FLL_CTRL_CONF2_LOCK_TOLERANCE_SHIFT)

#define FLL_CTRL_CONF2_CONF_CLK_SEL_MASK           (0x20000000U)
#define FLL_CTRL_CONF2_CONF_CLK_SEL_SHIFT          (29U)
#define FLL_CTRL_CONF2_CONF_CLK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF2_CONF_CLK_SEL_SHIFT)) & FLL_CTRL_CONF2_CONF_CLK_SEL_MASK)
#define READ_FLL_CTRL_CONF2_CONF_CLK_SEL(x)        (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_CONF_CLK_SEL_MASK)) >> FLL_CTRL_CONF2_CONF_CLK_SEL_SHIFT)

#define FLL_CTRL_CONF2_OPEN_LOOP_MASK              (0x40000000U)
#define FLL_CTRL_CONF2_OPEN_LOOP_SHIFT             (30U)
#define FLL_CTRL_CONF2_OPEN_LOOP(x)                (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF2_OPEN_LOOP_SHIFT)) & FLL_CTRL_CONF2_OPEN_LOOP_MASK)
#define READ_FLL_CTRL_CONF2_OPEN_LOOP(x)           (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_OPEN_LOOP_MASK)) >> FLL_CTRL_CONF2_OPEN_LOOP_SHIFT)

#define FLL_CTRL_CONF2_DITHERING_MASK              (0x80000000U)
#define FLL_CTRL_CONF2_DITHERING_SHIFT             (31U)
#define FLL_CTRL_CONF2_DITHERING(x)                (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CONF2_DITHERING_SHIFT)) & FLL_CTRL_CONF2_DITHERING_MASK)
#define READ_FLL_CTRL_CONF2_DITHERING(x)           (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CONF2_DITHERING_MASK)) >> FLL_CTRL_CONF2_DITHERING_SHIFT)

/*! @name SOC_INTEGRATOR - FLL_CTRL configuration 2 register */
#define FLL_CTRL_INTEGRATOR_FRACT_PART_MASK        (0xFFC0U)
#define FLL_CTRL_INTEGRATOR_FRACT_PART_SHIFT       (6U)
#define FLL_CTRL_INTEGRATOR_FRACT_PART(x)          (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_INTEGRATOR_FRACT_PART_SHIFT)) & FLL_CTRL_INTEGRATOR_FRACT_PART_MASK)
#define READ_FLL_CTRL_INTEGRATOR_FRACT_PART(x)     (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_INTEGRATOR_FRACT_PART_MASK)) >> FLL_CTRL_INTEGRATOR_FRACT_PART_SHIFT)

#define FLL_CTRL_INTEGRATOR_INT_PART_MASK          (0x3FF0000U)
#define FLL_CTRL_INTEGRATOR_INT_PART_SHIFT         (16U)
#define FLL_CTRL_INTEGRATOR_INT_PART(x)            (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_INTEGRATOR_INT_PART_SHIFT)) & FLL_CTRL_INTEGRATOR_INT_PART_MASK)
#define READ_FLL_CTRL_INTEGRATOR_INT_PART(x)       (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_INTEGRATOR_INT_PART_MASK)) >> FLL_CTRL_INTEGRATOR_INT_PART_SHIFT)

/*! @name FLL_CONVERGE - FLL_CTRL configuration 2 register */
#define FLL_CTRL_SOC_FLL_CONV_MASK                 (0x1U)
#define FLL_CTRL_SOC_FLL_CONV_SHIFT                (0U)
#define FLL_CTRL_SOC_FLL_CONV(x)                   (((uint32_t)(((uint32_t)(x)) /*<< FLL_CTRL_SOC_FLL_CONV_SHIFT */)) & FLL_CTRL_SOC_FLL_CONV_MASK)
#define READ_FLL_CTRL_SOC_FLL_CONV(x)              (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_SOC_FLL_CONV_MASK)) /*>> FLL_CTRL_SOC_FLL_CONV_SHIFT*/)

#define FLL_CTRL_CLUSTER_FLL_CONV_MASK             (0x2U)
#define FLL_CTRL_CLUSTER_FLL_CONV_SHIFT            (1U)
#define FLL_CTRL_CLUSTER_FLL_CONV(x)               (((uint32_t)(((uint32_t)(x)) << FLL_CTRL_CLUSTER_FLL_CONV_SHIFT)) & FLL_CTRL_CLUSTER_FLL_CONV_MASK)
#define READ_FLL_CTRL_CLUSTER_FLL_CONV(x)          (((uint32_t)(((uint32_t)(x)) & FLL_CTRL_CLUSTER_FLL_CONV_MASK)) >> FLL_CTRL_CLUSTER_FLL_CONV_SHIFT)


/*!
 * @}
 */ /* end of group FLL_CTRL_Register_Masks */

/* The number of FLL */
#define FLL_NUM        2
/* The FLL reference frequency*/
#define FLL_REF_CLK    32768


/* FLL_CTRL - Peripheral instance base addresses */
/** Peripheral FLL_CTRL base address */
#define FLL_CTRL_BASE                                (SOC_PERI_BASE)
/** Peripheral FLL_CTRL base pointer */
#define FLL_CTRL                                     ((FLL_CTRL_Type *)FLL_CTRL_BASE)
/** Array initializer of FLL_CTRL base addresses */
#define FLL_CTRL_BASE_ADDRS                          { FLL_CTRL_BASE }
/** Array initializer of FLL_CTRL base pointers */
#define FLL_CTRL_BASE_PTRS                           { FLL_CTRL }

/*!
 * @}
 */ /* end of group FLL_CTRL_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO  uint32_t DIR;                       /**< GPIO gpio direction register, offset: 0x00 */
  __IO  uint32_t IN;                        /**< GPIO gpio in register, offset: 0x04 */
  __IO  uint32_t OUT;                       /**< GPIO gpio out register, offset: 0x08 */
  __IO  uint32_t INTEN;                     /**< GPIO gpio inten register, offset: 0x0C */
  __IO  uint32_t INTCFG[2];                 /**< GPIO gpio int configuration register 0, offset: 0x10 */
  __IO  uint32_t INTSTATUS;                 /**< GPIO gpio int status register, offset: 0x18 */
  __IO  uint32_t EN;                        /**< GPIO gpio enable register, offset: 0x1C */
  __IO  uint32_t PADCFG[8];                 /**< GPIO pad configuration registers, offset: 0x020 */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */
/*! @name INTCFG - GPIO pad interrupt configuration registers */
#define GPIO_INTCFG_TYPE_MASK                    (0x3U)
#define GPIO_INTCFG_TYPE_SHIFT                   (0U)
#define GPIO_INTCFG_TYPE(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_INTCFG_TYPE_SHIFT)) & GPIO_INTCFG_TYPE_MASK)

/*! @name PADCFG - GPIO pad configuration registers */
#define GPIO_PADCFG_PULL_EN_MASK                 (0x1U)
#define GPIO_PADCFG_PULL_EN_SHIFT                (0U)
#define GPIO_PADCFG_PULL_EN(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_PADCFG_PULL_EN_SHIFT)) & GPIO_PADCFG_PULL_EN_MASK)

#define GPIO_PADCFG_DRIVE_STRENGTH_MASK          (0x2U)
#define GPIO_PADCFG_DRIVE_STRENGTH_SHIFT         (1U)
#define GPIO_PADCFG_DRIVE_STRENGTH(x)            (((uint32_t)(((uint32_t)(x)) << GPIO_PADCFG_DRIVE_STRENGTH_SHIFT)) & GPIO_PADCFG_DRIVE_STRENGTH_MASK)

#define GPIO_INTCFG_TYPE_BITS_WIDTH_MASK         (0x3U)


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                              (SOC_PERI_BASE + 0x1000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                   ((GPIO_Type *)GPIOA_BASE)
/** Array initializer of GPIO base addresses */
#define GPIO_BASE_ADDRS                         { GPIOA_BASE }
/** Array initializer of GPIO base pointers */
#define GPIO_BASE_PTRS                          { GPIOA }

/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */




/* ----------------------------------------------------------------------------
   -- UDMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UDMA_Peripheral_Access_Layer  UDMA Peripheral Access Layer
 * @{
 */

/** UDMA - General Register Layout Typedef */
typedef struct {
  __IO uint32_t RX_SADDR;                          /**< RX UDMA buffer transfer address register, offset: 0x0 */
  __IO uint32_t RX_SIZE;                           /**< RX UDMA buffer transfer size register, offset: 0x4 */
  __IO uint32_t RX_CFG;                            /**< RX UDMA transfer configuration register, offset: 0x8 */
  __IO uint32_t RX_INITCFG;                        /**< Reserved, offset: 0xC */
  __IO uint32_t TX_SADDR;                          /**< TX UDMA buffer transfer address register, offset: 0x10 */
  __IO uint32_t TX_SIZE;                           /**< TX UDMA buffer transfer size register, offset: 0x14 */
  __IO uint32_t TX_CFG;                            /**< TX UDMA transfer configuration register, offset: 0x18 */
  __IO uint32_t TX_INITCFG;                        /**< Reserved, offset: 0x1C */

} UDMA_Type;


/** UDMA - General Register Layout Typedef */
typedef struct {
  __IO uint32_t rx_saddr;                          /**< RX UDMA buffer transfer address register, offset: 0x0 */
  __IO uint32_t rx_size;                           /**< RX UDMA buffer transfer size register, offset: 0x4 */
  __IO uint32_t rx_cfg;                            /**< RX UDMA transfer configuration register, offset: 0x8 */
  __IO uint32_t rx_initcfg;                        /**< Reserved, offset: 0xC */
  __IO uint32_t tx_saddr;                          /**< TX UDMA buffer transfer address register, offset: 0x10 */
  __IO uint32_t tx_size;                           /**< TX UDMA buffer transfer size register, offset: 0x14 */
  __IO uint32_t tx_cfg;                            /**< TX UDMA transfer configuration register, offset: 0x18 */
  __IO uint32_t tx_initcfg;                        /**< Reserved, offset: 0x1C */

} udma_core_t;

/* ----------------------------------------------------------------------------
   -- UDMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UDMA_Register_Masks UDMA Register Masks
 * @{
 */
/*! @name RX_SADDR - RX TX UDMA buffer transfer address register */
#define UDMA_SADDR_ADDR_MASK                 (0xFFFFU)
#define UDMA_SADDR_ADDR_SHIFT                (0U)
#define UDMA_SADDR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) /*<< UDMA_SADDR_ADDR_SHIFT*/)) & UDMA_SADDR_ADDR_MASK)

/*! @name RX_SIZE - RX TX UDMA buffer transfer size register */
#define UDMA_SIZE_SIZE_MASK                  (0x1FFFFU)
#define UDMA_SIZE_SIZE_SHIFT                 (0U)
#define UDMA_SIZE_SIZE(x)                    (((uint32_t)(((uint32_t)(x)) << UDMA_SIZE_SIZE_SHIFT)) & UDMA_SIZE_SIZE_MASK)


/*! @name RX_CFG - RX TX UDMA transfer configuration register */
#define UDMA_CFG_CONTINOUS_MASK              (0x1U)
#define UDMA_CFG_CONTINOUS_SHIFT             (0U)
#define UDMA_CFG_CONTINOUS(x)                (((uint32_t)(((uint32_t)(x)) /*<< UDMA_CFG_CONTINOUS_SHIFT*/)) & UDMA_CFG_CONTINOUS_MASK)
#define UDMA_CFG_DATA_SIZE_MASK              (0x6U)
#define UDMA_CFG_DATA_SIZE_SHIFT             (1U)
#define UDMA_CFG_DATA_SIZE(x)                (((uint32_t)(((uint32_t)(x)) << UDMA_CFG_DATA_SIZE_SHIFT)) & UDMA_CFG_DATA_SIZE_MASK)
#define UDMA_CFG_EN_MASK                     (0x10U)
#define UDMA_CFG_EN_SHIFT                    (4U)
#define UDMA_CFG_EN(x)                       (((uint32_t)(((uint32_t)(x)) << UDMA_CFG_EN_SHIFT)) & UDMA_CFG_EN_MASK)
#define UDMA_CFG_PENDING_MASK                (0x20U)
#define UDMA_CFG_PENDING_SHIFT               (5U)
#define UDMA_CFG_PENDING(x)                  (((uint32_t)(((uint32_t)(x)) << UDMA_CFG_PENDING_SHIFT)) & UDMA_CFG_PENDING_MASK)
#define UDMA_CFG_CLR_MASK                    (0x20U)
#define UDMA_CFG_CLR_SHIFT                   (5U)
#define UDMA_CFG_CLR(x)                      (((uint32_t)(((uint32_t)(x)) << UDMA_CFG_CLR_SHIFT)) & UDMA_CFG_CLR_MASK)

/*!
 * @}
 */ /* end of group UDMA_Register_Masks */


/* UDMA - Peripheral instance base addresses */
/** Peripheral UDMA base address 0x1A102000 */
#define UDMA_BASE                                (SOC_PERI_BASE + 0x02000u)
/** Peripheral UDMA events number */
#define UDMA_EVENTS_NUM                          19
/** Peripheral UDMA channel number */
#define UDMA_CHANNEL_NUM                         10

/*!
 * @}
 */ /* end of group UDMA_Peripheral_Access_Layer */




/* ----------------------------------------------------------------------------
   -- UDMA Global Configuration Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UDMA_GC_Peripheral_Access_Layer UDMA_GC Peripheral Access Layer
 * @{
 */

/** UDMA Global configuration - Register Layout Typedef */
typedef struct {
  __IO uint32_t CG;                          /**< UDMA_GC clock gating register, offset: 0x0 */
  __IO uint32_t EVTIN;                       /**< UDMA_GC input event register, offset: 0x04 */
} UDMA_GC_Type;

/* ----------------------------------------------------------------------------
   -- UDMA_GC Register Masks
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup UDMA_GC_Register_Masks UDMA_GC Register Masks
 * @{
 */

/*! @name UDMA_GC - UDMA event in register, User chooses which events can come to UDMA as reference events, support up to 4 choices */
#define UDMA_GC_EVTIN_CHOICE0_MASK                  (0xFFU)
#define UDMA_GC_EVTIN_CHOICE0_SHIFT                 (0U)
#define UDMA_GC_EVTIN_CHOICE0(x)                    (((uint32_t)(((uint32_t)(x)) << UDMA_GC_EVTIN_CHOICE0_SHIFT)) & UDMA_GC_EVTIN_CHOICE0_MASK)

#define UDMA_GC_EVTIN_CHOICE1_MASK                  (0xFF00U)
#define UDMA_GC_EVTIN_CHOICE1_SHIFT                 (8U)
#define UDMA_GC_EVTIN_CHOICE1(x)                    (((uint32_t)(((uint32_t)(x)) << UDMA_GC_EVTIN_CHOICE1_SHIFT)) & UDMA_GC_EVTIN_CHOICE1_MASK)

#define UDMA_GC_EVTIN_CHOICE2_MASK                  (0xFF0000U)
#define UDMA_GC_EVTIN_CHOICE2_SHIFT                 (16U)
#define UDMA_GC_EVTIN_CHOICE2(x)                    (((uint32_t)(((uint32_t)(x)) << UDMA_GC_EVTIN_CHOICE2_SHIFT)) & UDMA_GC_EVTIN_CHOICE2_MASK)

#define UDMA_GC_EVTIN_CHOICE3_MASK                  (0xFF000000)
#define UDMA_GC_EVTIN_CHOICE3_SHIFT                 (24U)
#define UDMA_GC_EVTIN_CHOICE3(x)                    (((uint32_t)(((uint32_t)(x)) << UDMA_GC_EVTIN_CHOICE3_SHIFT)) & UDMA_GC_EVTIN_CHOICE3_MASK)

#define UDMA_GC_EVTIN_MASK(evt_in)                  (evt_in&0xFF)
#define UDMA_GC_EVTIN_SHIFT_ID(id)                  (id*8)

/*!
 * @}
 */ /* end of group UDMA_GC_Register_Masks */


/* UDMA Global configuration - instance base addresses */
/** Global configuration UDMA base address */
#define UDMA_GC_BASE                              (UDMA_BASE + 0x780u)
#define UDMA_GC                            ((UDMA_GC_Type *)UDMA_GC_BASE)

/*!
 * @}
 */ /* end of group UDMA_GC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LVDS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LVDS_Peripheral_Access_Layer LVDS Peripheral Access Layer
 * @{
 */

/** LVDS - Register Layout Typedef */
typedef struct {
  UDMA_Type    UDMA_LVDS;                           /**< LVDS UDMA general register, offset: 0x0 */
  __IO  uint32_t RF_CFG;                            /**< LVDS configuration register, offset: 0x20 */
  __IO  uint32_t RF_GPIO;                           /**< Reserved, offset: 0x24 */
  __IO  uint32_t RF_STATUS;                         /**< LVDS Status register, offset: 0x28 */
} LVDS_Type;

/* ----------------------------------------------------------------------------
   -- LVDS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LVDS_Register_Masks LVDS Register Masks
 * @{
 */

/*! @name RF_CFG - LVDS configuration register */
#define LVDS_RF_CFG_TX_ENB_MASK                  (0x1U)
#define LVDS_RF_CFG_TX_ENB_SHIFT                 (0U)
#define LVDS_RF_CFG_TX_ENB(x)                    (((uint32_t)(((uint32_t)(x)) << /*LVDS_RF_CFG_TX_ENB_SHIFT*/)) & LVDS_RF_CFG_TX_ENB_MASK)

#define LVDS_RF_CFG_TX_OEB_MASK                  (0x2U)
#define LVDS_RF_CFG_TX_OEB_SHIFT                 (1U)
#define LVDS_RF_CFG_TX_OEB(x)                    (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_TX_OEB_SHIFT)) & LVDS_RF_CFG_TX_OEB_MASK)

#define LVDS_RF_CFG_TX_MODE_MASK                 (0x4U)
#define LVDS_RF_CFG_TX_MODE_SHIFT                (2U)
#define LVDS_RF_CFG_TX_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_TX_MODE_SHIFT)) & LVDS_RF_CFG_TX_MODE_MASK)

#define LVDS_RF_CFG_TX_VSEL_MASK                 (0x8U)
#define LVDS_RF_CFG_TX_VSEL_SHIFT                (3U)
#define LVDS_RF_CFG_TX_VSEL(x)                   (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_TX_VSEL_SHIFT)) & LVDS_RF_CFG_TX_VSEL_MASK)

#define LVDS_RF_CFG_RX_ENB_MASK                  (0x10U)
#define LVDS_RF_CFG_RX_ENB_SHIFT                 (4U)
#define LVDS_RF_CFG_RX_ENB(x)                    (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_RX_ENB_SHIFT)) & LVDS_RF_CFG_RX_ENB_MASK)

#define LVDS_RF_CFG_SD_RX_EN_MASK                (0x20U)
#define LVDS_RF_CFG_SD_RX_EN_SHIFT               (5U)
#define LVDS_RF_CFG_SD_RX_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_SD_RX_EN_SHIFT)) & LVDS_RF_CFG_SD_RX_EN_MASK)

#define LVDS_RF_CFG_SD_TX_EN_MASK                (0x40U)
#define LVDS_RF_CFG_SD_TX_EN_SHIFT               (6U)
#define LVDS_RF_CFG_SD_TX_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_SD_TX_EN_SHIFT)) & LVDS_RF_CFG_SD_TX_EN_MASK)

#define LVDS_RF_CFG_DDR_RX_EN_MASK               (0x80U)
#define LVDS_RF_CFG_DDR_RX_EN_SHIFT              (7U)
#define LVDS_RF_CFG_DDR_RX_EN(x)                 (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_DDR_RX_EN_SHIFT)) & LVDS_RF_CFG_DDR_RX_EN_MASK)

#define LVDS_RF_CFG_DDR_TX_EN_MASK               (0x100U)
#define LVDS_RF_CFG_DDR_TX_EN_SHIFT              (8U)
#define LVDS_RF_CFG_DDR_TX_EN(x)                 (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_DDR_TX_EN_SHIFT)) & LVDS_RF_CFG_DDR_TX_EN_MASK)

#define LVDS_RF_CFG_CLKSEL_MASK                  (0x200U)
#define LVDS_RF_CFG_CLKSEL_SHIFT                 (9U)
#define LVDS_RF_CFG_CLKSEL(x)                    (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_CLKSEL_SHIFT)) & LVDS_RF_CFG_CLKSEL_MASK)

#define LVDS_RF_CFG_MODE_MASK                    (0x400U)
#define LVDS_RF_CFG_MODE_SHIFT                   (10U)
#define LVDS_RF_CFG_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_MODE_SHIFT)) & LVDS_RF_CFG_MODE_MASK)

#define LVDS_RF_CFG_MODE_VAL_MASK                (0x800U)
#define LVDS_RF_CFG_MODE_VAL_SHIFT               (11U)
#define LVDS_RF_CFG_MODE_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_MODE_VAL_SHIFT)) & LVDS_RF_CFG_MODE_VAL_MASK)

#define LVDS_RF_CFG_MODE_RX_MASK                 (0x1000U)
#define LVDS_RF_CFG_MODE_RX_SHIFT                (12U)
#define LVDS_RF_CFG_MODE_RX(x)                   (((uint32_t)(((uint32_t)(x)) << LVDS_RF_CFG_MODE_RX_SHIFT)) & LVDS_RF_CFG_MODE_RX_MASK)

/*! @name RF_STATUS - LVDS Status register */
#define LVDS_RF_STATUS_SYNC_FLAG_MASK            (0x1U)
#define LVDS_RF_STATUS_SYNC_FLAG_SHIFT           (0U)
#define LVDS_RF_STATUS_SYNC_FLAG(x)              (((uint32_t)(((uint32_t)(x)) /*<< LVDS_RF_STATUS_SYNC_FLAG_SHIFT*/)) & LVDS_RF_STATUS_SYNC_FLAG_MASK)


/*!
 * @}
 */ /* end of group LVDS_Register_Masks */


/* LVDS - Peripheral instance base addresses */
/** Peripheral LVDS base address */
#define LVDS_BASE                                 (UDMA_BASE + 0 * 128U)
/** Peripheral LVDS base pointer */
#define LVDS                                      ((LVDS_Type *)LVDS_BASE)
/** Array initializer of LVDS peripheral base addresses */
#define LVDS_BASE_ADDRS                           { LVDS_BASE }
/** Array initializer of LVDS peripheral base pointers */
#define LVDS_BASE_PTRS                            { LVDS }
/** Interrupt vectors for the LVDS peripheral type */
#define LVDS_RX_IRQS                              { LVDS_RX_IRQn }
#define LVDS_TX_IRQS                              { LVDS_TX_IRQn }

/*!
 * @}
 */ /* end of group LVDS_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- ORCA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ORCA_Peripheral_Access_Layer ORCA Peripheral Access Layer
 * @{
 */

/** ORCA - Register Layout Typedef */
typedef struct {
  UDMA_Type    UDMA_ORCA;                           /**< ORCA UDMA general register, offset: 0x0 */
  __IO  uint32_t RF_CFG;                            /**< ORCA configuration register, offset: 0x20 */
  __IO  uint32_t RF_GPIO;                           /**< Reserved, offset: 0x24 */
  __IO  uint32_t RF_STATUS;                         /**< ORCA Status register, offset: 0x28 */
  __IO  uint32_t PAD;                               /**< ORCA reserved, offset: 0x2C */
  __IO  uint32_t CLKDIV_EN;                         /**< ORCA uDMA clock divider enable register, offset: 0x30 */
  __IO  uint32_t CLKDIV_CFG;                        /**< ORCA uDMA clock divider configuration register, offset: 0x34 */
  __IO  uint32_t CLKDIV_UPD;                        /**< ORCA uDMA clock divider data register, offset: 0x38 */
  __IO  uint32_t ORCA_CFG;                          /**< ORCA configuration register, offset: 0x3C */
  __IO  uint32_t CNT_EVENT;                         /**< ORCA Status register, offset: 0x40 */
} ORCA_Type;

/* ----------------------------------------------------------------------------
   -- ORCA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ORCA_Register_Masks ORCA Register Masks
 * @{
 */

/*! @name RF_CFG - ORCA configuration register */
#define ORCA_RF_CFG_TX_ENB_MASK                  (0x1U)
#define ORCA_RF_CFG_TX_ENB_SHIFT                 (0U)
#define ORCA_RF_CFG_TX_ENB(x)                    (((uint32_t)(((uint32_t)(x)) /*<< ORCA_RF_CFG_TX_ENB_SHIFT*/)) & ORCA_RF_CFG_TX_ENB_MASK)

#define ORCA_RF_CFG_TX_OEB_MASK                  (0x2U)
#define ORCA_RF_CFG_TX_OEB_SHIFT                 (1U)
#define ORCA_RF_CFG_TX_OEB(x)                    (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_TX_OEB_SHIFT)) & ORCA_RF_CFG_TX_OEB_MASK)

#define ORCA_RF_CFG_TX_MODE_MASK                 (0x4U)
#define ORCA_RF_CFG_TX_MODE_SHIFT                (2U)
#define ORCA_RF_CFG_TX_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_TX_MODE_SHIFT)) & ORCA_RF_CFG_TX_MODE_MASK)

#define ORCA_RF_CFG_TX_VSEL_MASK                 (0x8U)
#define ORCA_RF_CFG_TX_VSEL_SHIFT                (3U)
#define ORCA_RF_CFG_TX_VSEL(x)                   (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_TX_VSEL_SHIFT)) & ORCA_RF_CFG_TX_VSEL_MASK)

#define ORCA_RF_CFG_RX_ENB_MASK                  (0x10U)
#define ORCA_RF_CFG_RX_ENB_SHIFT                 (4U)
#define ORCA_RF_CFG_RX_ENB(x)                    (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_RX_ENB_SHIFT)) & ORCA_RF_CFG_RX_ENB_MASK)

#define ORCA_RF_CFG_SD_RX_EN_MASK                (0x20U)
#define ORCA_RF_CFG_SD_RX_EN_SHIFT               (5U)
#define ORCA_RF_CFG_SD_RX_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_SD_RX_EN_SHIFT)) & ORCA_RF_CFG_SD_RX_EN_MASK)

#define ORCA_RF_CFG_SD_TX_EN_MASK                (0x40U)
#define ORCA_RF_CFG_SD_TX_EN_SHIFT               (6U)
#define ORCA_RF_CFG_SD_TX_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_SD_TX_EN_SHIFT)) & ORCA_RF_CFG_SD_TX_EN_MASK)

#define ORCA_RF_CFG_DDR_RX_EN_MASK               (0x80U)
#define ORCA_RF_CFG_DDR_RX_EN_SHIFT              (7U)
#define ORCA_RF_CFG_DDR_RX_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_DDR_RX_EN_SHIFT)) & ORCA_RF_CFG_DDR_RX_EN_MASK)

#define ORCA_RF_CFG_DDR_TX_EN_MASK               (0x100U)
#define ORCA_RF_CFG_DDR_TX_EN_SHIFT              (8U)
#define ORCA_RF_CFG_DDR_TX_EN(x)                 (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_DDR_TX_EN_SHIFT)) & ORCA_RF_CFG_DDR_TX_EN_MASK)

#define ORCA_RF_CFG_CLKSEL_MASK                  (0x200U)
#define ORCA_RF_CFG_CLKSEL_SHIFT                 (9U)
#define ORCA_RF_CFG_CLKSEL(x)                    (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_CLKSEL_SHIFT)) & ORCA_RF_CFG_CLKSEL_MASK)

#define ORCA_RF_CFG_MODE_MASK                    (0x400U)
#define ORCA_RF_CFG_MODE_SHIFT                   (10U)
#define ORCA_RF_CFG_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_MODE_SHIFT)) & ORCA_RF_CFG_MODE_MASK)

#define ORCA_RF_CFG_MODE_VAL_MASK                (0x800U)
#define ORCA_RF_CFG_MODE_VAL_SHIFT               (11U)
#define ORCA_RF_CFG_MODE_VAL(x)                  (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_MODE_VAL_SHIFT)) & ORCA_RF_CFG_MODE_VAL_MASK)

#define ORCA_RF_CFG_MODE_RX_MASK                 (0x1000U)
#define ORCA_RF_CFG_MODE_RX_SHIFT                (12U)
#define ORCA_RF_CFG_MODE_RX(x)                   (((uint32_t)(((uint32_t)(x)) << ORCA_RF_CFG_MODE_RX_SHIFT)) & ORCA_RF_CFG_MODE_RX_MASK)

/*! @name RF_STATUS - ORCA Status register */
#define ORCA_RF_STATUS_SYNC_FLAG_MASK            (0x1U)
#define ORCA_RF_STATUS_SYNC_FLAG_SHIFT           (0U)
#define ORCA_RF_STATUS_SYNC_FLAG(x)              (((uint32_t)(((uint32_t)(x)) /*<< ORCA_RF_STATUS_SYNC_FLAG_SHIFT*/)) & ORCA_RF_STATUS_SYNC_FLAG_MASK)


/*! @name CLKDIV_EN - ORCA uDMA clock divider enable register */
#define ORCA_CLKDIV_EN_MASK              (0x1U)
#define ORCA_CLKDIV_EN_SHIFT             (0U)
#define ORCA_CLKDIV_EN(x)                (((uint32_t)(((uint32_t)(x)) /*<< ORCA_CLKDIV_EN_SHIFT*/)) & ORCA_CLKDIV_EN_MASK)

/*! @name CLKDIV_CFG - ORCA uDMA clock divider configuration register */
#define ORCA_CLKDIV_CFG_MASK             (0xFFU)
#define ORCA_CLKDIV_CFG_SHIFT            (0U)
#define ORCA_CLKDIV_CFG(x)               (((uint32_t)(((uint32_t)(x)) /*<< ORCA_CLKDIV_CFG_SHIFT*/)) & ORCA_CLKDIV_CFG_MASK)

/*! @name CLKDIV_UDP - ORCA uDMA clock divider enable register */
#define ORCA_CLKDIV_UDP_MASK             (0x1U)
#define ORCA_CLKDIV_UDP_SHIFT            (0U)
#define ORCA_CLKDIV_UDP(x)               (((uint32_t)(((uint32_t)(x)) /*<< ORCA_CLKDIV_UDP_SHIFT*/)) & ORCA_CLKDIV_UDP_MASK)

/*! @name ORCA_CFG - ORCA configuration register */
#define ORCA_CFG_SIZE_MASK               (0xFU)
#define ORCA_CFG_SIZE_SHIFT              (0U)
#define ORCA_CFG_SIZE(x)                 (((uint32_t)(((uint32_t)(x)) /*<< ORCA_CFG_SIZE_SHIFT*/)) & ORCA_CFG_SIZE_MASK)

#define ORCA_CFG_DELAY_MASK              (0xF0U)
#define ORCA_CFG_DELAY_SHIFT             (4U)
#define ORCA_CFG_DELAY(x)                (((uint32_t)(((uint32_t)(x)) << ORCA_CFG_DELAY_SHIFT)) & ORCA_CFG_DELAY_MASK)

#define ORCA_CFG_EN_MASK                 (0x100U)
#define ORCA_CFG_EN_SHIFT                (8U)
#define ORCA_CFG_EN(x)                   (((uint32_t)(((uint32_t)(x)) << ORCA_CFG_EN_SHIFT)) & ORCA_CFG_EN_MASK)

/*!
 * @}
 */ /* end of group ORCA_Register_Masks */


/* ORCA - Peripheral instance base addresses */
/** Peripheral ORCA base address */
#define ORCA_BASE                                 (UDMA_BASE + 0 * 128U)
/** Peripheral ORCA base pointer */
#define ORCA                                      ((ORCA_Type *)ORCA_BASE)
/** Array initializer of ORCA peripheral base addresses */
#define ORCA_BASE_ADDRS                           { ORCA_BASE }
/** Array initializer of ORCA peripheral base pointers */
#define ORCA_BASE_PTRS                            { ORCA }
/** Interrupt vectors for the ORCA peripheral type */
#define ORCA_RX_IRQS                              { ORCA_RX_IRQn }
#define ORCA_TX_IRQS                              { ORCA_TX_IRQn }

/*!
 * @}
 */ /* end of group ORCA_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- SPIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPIM_Peripheral_Access_Layer SPIM Peripheral Access Layer
 * @{
 */

/** SPIM - Register Layout Typedef */
typedef struct {
  UDMA_Type    UDMA_SPIM;                           /**< SPIM UDMA general register, offset: 0x0 */
} SPIM_Type;

/* ----------------------------------------------------------------------------
   -- SPIM Register Masks
   ---------------------------------------------------------------------------- */

/*! @name uDMA - SPIM uDMA control CMD */
#define SPIM_CMD_CFG_ID               0
#define SPIM_CMD_SOT_ID               1
#define SPIM_CMD_SEND_CMD_ID          2
#define SPIM_CMD_SEND_ADDR_ID         3
#define SPIM_CMD_DUMMY_ID             4
#define SPIM_CMD_WAIT_ID              5
#define SPIM_CMD_TX_DATA_ID           6
#define SPIM_CMD_RX_DATA_ID           7
#define SPIM_CMD_RPT_ID               8
#define SPIM_CMD_EOT_ID               9
#define SPIM_CMD_RPT_END_ID          10
#define SPIM_CMD_RX_CHECK_ID         11
#define SPIM_CMD_DUPLEX_ID           12

#define SPIM_CMD_MASK                 (0xF0000000U)
#define SPIM_CMD_SHIFT                (28U)
#define SPIM_CMD(x)                   (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SHIFT)) & SPIM_CMD_MASK)

/*!
 * @addtogroup SPIM_Register_Masks SPIM Register Masks
 * @{
 */
/*! @name CMD_CFG - SPIM configuration register */
#define SPIM_CMD_CFG_CLKDIV_MASK                  (0xFFU)
#define SPIM_CMD_CFG_CLKDIV_SHIFT                 (0U)
#define SPIM_CMD_CFG_CLKDIV(x)                    (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_CFG_CLKDIV_SHIFT*/)) & SPIM_CMD_CFG_CLKDIV_MASK)
#define SPIM_CMD_CFG_CPHA_MASK                    (0x100U)
#define SPIM_CMD_CFG_CPHA_SHIFT                   (8U)
#define SPIM_CMD_CFG_CPHA(x)                      (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_CFG_CPHA_SHIFT)) & SPIM_CMD_CFG_CPHA_MASK)
#define SPIM_CMD_CFG_CPOL_MASK                    (0x200U)
#define SPIM_CMD_CFG_CPOL_SHIFT                   (9U)
#define SPIM_CMD_CFG_CPOL(x)                      (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_CFG_CPOL_SHIFT)) & SPIM_CMD_CFG_CPOL_MASK)

/*! @name CMD_SOT - SPIM chip select (CS) */
#define SPIM_CMD_SOT_CS_MASK                      (0x3U)
#define SPIM_CMD_SOT_CS_SHIFT                     (0U)
#define SPIM_CMD_SOT_CS(x)                        (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SOT_CS_SHIFT)) & SPIM_CMD_SOT_CS_MASK)

/*! @name CMD_SEND_CMD - SPIM Transmit a command */
#define SPIM_CMD_SEND_VALUEL_MASK                (0xFFU)
#define SPIM_CMD_SEND_VALUEL_SHIFT                (0U)
#define SPIM_CMD_SEND_VALUEL(x)                   (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_SEND_VALUEL_SHIFT*/)) & SPIM_CMD_SEND_VALUEL_MASK)
#define SPIM_CMD_SEND_VALUEH_MASK                 (0xFF00U)
#define SPIM_CMD_SEND_VALUEH_SHIFT                (8U)
#define SPIM_CMD_SEND_VALUEH(x)                   (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SEND_VALUEH_SHIFT)) & SPIM_CMD_SEND_VALUEH_MASK)
#define SPIM_CMD_SEND_CMD_SIZE_MASK               (0x1F0000U)
#define SPIM_CMD_SEND_CMD_SIZE_SHIFT              (16U)
#define SPIM_CMD_SEND_CMD_SIZE(x)                 (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SEND_CMD_SIZE_SHIFT)) & SPIM_CMD_SEND_CMD_SIZE_MASK)
#define SPIM_CMD_SEND_QPI_MASK                    (0x8000000U)
#define SPIM_CMD_SEND_QPI_SHIFT                   (27U)
#define SPIM_CMD_SEND_QPI(x)                      (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SEND_QPI_SHIFT)) & SPIM_CMD_SEND_QPI_MASK)

/*! @name CMD_SEND_ADDR - SPIM Transmit a address */
#define SPIM_CMD_SEND_ADDR_VALUE_MASK             (0xFFFFU)
#define SPIM_CMD_SEND_ADDR_VALUE_SHIFT            (0U)
#define SPIM_CMD_SEND_ADDR_VALUE(x)               (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_SEND_ADDR_VALUE_SHIFT*/)) & SPIM_CMD_SEND_ADDR_VALUE_MASK)
#define SPIM_CMD_SEND_ADDR_CMD_SIZE_MASK          (0x1F0000U)
#define SPIM_CMD_SEND_ADDR_CMD_SIZE_SHIFT         (16U)
#define SPIM_CMD_SEND_ADDR_CMD_SIZE(x)            (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SEND_ADDR_CMD_SIZE_SHIFT)) & SPIM_CMD_SEND_ADDR_CMD_SIZE_MASK)
#define SPIM_CMD_SEND_ADDR_QPI_MASK               (0x8000000U)
#define SPIM_CMD_SEND_ADDR_QPI_SHIFT              (27U)
#define SPIM_CMD_SEND_ADDR_QPI(x)                 (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_SEND_ADDR_QPI_SHIFT)) & SPIM_CMD_SEND_ADDR_QPI_MASK)

/*! @name CMD_DUMMY - SPIM number of dummy cycle */
#define SPIM_CMD_DUMMY_CYCLE_MASK                 (0x1F0000U)
#define SPIM_CMD_DUMMY_CYCLE_SHIFT                (16U)
#define SPIM_CMD_DUMMY_CYCLE(x)                   (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_DUMMY_CYCLE_SHIFT)) & SPIM_CMD_DUMMY_CYCLE_MASK)

/*! @name CMD_WAIT - SPIM wait in which event - 2 bits */
#define SPIM_CMD_WAIT_EVENT_ID_MASK               (0x3U)
#define SPIM_CMD_WAIT_EVENT_ID_SHIFT              (0U)
#define SPIM_CMD_WAIT_EVENT_ID(x)                 (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_WAIT_EVENT_ID_SHIFT*/)) & SPIM_CMD_WAIT_EVENT_ID_MASK)

/*! @name CMD_TX_DATA - SPIM send datas */
#define SPIM_CMD_TX_DATA_SIZE_MASK                (0xFFFFU)
#define SPIM_CMD_TX_DATA_SIZE_SHIFT               (0U)
#define SPIM_CMD_TX_DATA_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_TX_DATA_SIZE_SHIFT*/)) & SPIM_CMD_TX_DATA_SIZE_MASK)
#define SPIM_CMD_TX_DATA_BYTE_ALIGN_MASK          (0x4000000U)
#define SPIM_CMD_TX_DATA_BYTE_ALIGN_SHIFT         (26U)
#define SPIM_CMD_TX_DATA_BYTE_ALIGN(x)            (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_TX_DATA_BYTE_ALIGN_SHIFT)) & SPIM_CMD_TX_DATA_BYTE_ALIGN_MASK)
#define SPIM_CMD_TX_DATA_QPI_MASK                 (0x8000000U)
#define SPIM_CMD_TX_DATA_QPI_SHIFT                (27U)
#define SPIM_CMD_TX_DATA_QPI(x)                   (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_TX_DATA_QPI_SHIFT)) & SPIM_CMD_TX_DATA_QPI_MASK)

/*! @name CMD_RX_DATA - SPIM receive datas */
#define SPIM_CMD_RX_DATA_SIZE_MASK                (0xFFFFU)
#define SPIM_CMD_RX_DATA_SIZE_SHIFT               (0U)
#define SPIM_CMD_RX_DATA_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_RX_DATA_SIZE_SHIFT*/)) & SPIM_CMD_RX_DATA_SIZE_MASK)
#define SPIM_CMD_RX_DATA_BYTE_ALIGN_MASK          (0x4000000U)
#define SPIM_CMD_RX_DATA_BYTE_ALIGN_SHIFT         (26U)
#define SPIM_CMD_RX_DATA_BYTE_ALIGN(x)            (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_RX_DATA_BYTE_ALIGN_SHIFT)) & SPIM_CMD_RX_DATA_BYTE_ALIGN_MASK)
#define SPIM_CMD_RX_DATA_QPI_MASK                 (0x8000000U)
#define SPIM_CMD_RX_DATA_QPI_SHIFT                (27U)
#define SPIM_CMD_RX_DATA_QPI(x)                   (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_RX_DATA_QPI_SHIFT)) & SPIM_CMD_RX_DATA_QPI_MASK)

/*! @name CMD_RPT - SPIM repeat the next transfer N times */
#define SPIM_CMD_RPT_CNT_MASK                     (0xFFFFU)
#define SPIM_CMD_RPT_CNT_SHIFT                    (0U)
#define SPIM_CMD_RPT_CNT(x)                       (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_RPT_CNT_SHIFT*/)) & SPIM_CMD_RPT_CNT_MASK)

/*! @name CMD_EOT - SPIM clears the chip select (CS), and send a end event or not  */
#define SPIM_CMD_EOT_EVENT_GEN_MASK                (0x1U)
#define SPIM_CMD_EOT_EVENT_GEN_SHIFT               (0U)
#define SPIM_CMD_EOT_EVENT_GEN(x)                  (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_EOT_EVENT_GEN_SHIFT*/)) & SPIM_CMD_EOT_EVENT_GEN_MASK)

/*! @name CMD_RPT_END - SPIM End of the repeat loop */
#define SPIM_CMD_RPT_END_SPI_CMD_MASK              (0xFU)
#define SPIM_CMD_RPT_END_SPI_CMD_SHIFT             (0U)
#define SPIM_CMD_RPT_END_SPI_CMD(x)                (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_RPT_END_SPI_CMD_SHIFT*/)) & SPIM_CMD_RPT_END_SPI_CMD_MASK)

/*! @name CMD_RX_CHECK - SPIM check up to 16 bits of data against an expected value  */
#define SPIM_CMD_RX_CHECK_COMP_DATA_MASK            (0xFFFFU)
#define SPIM_CMD_RX_CHECK_COMP_DATA_SHIFT           (0U)
#define SPIM_CMD_RX_CHECK_COMP_DATA(x)              (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_RX_CHECK_COMP_DATA_SHIFT*/)) & SPIM_CMD_RX_CHECK_COMP_DATA_MASK)
/* The number of bits to check, maximum is 16bits */
#define SPIM_CMD_RX_CHECK_STATUS_SIZE_MASK          (0xFF0000U)
#define SPIM_CMD_RX_CHECK_STATUS_SIZE_SHIFT         (16U)
#define SPIM_CMD_RX_CHECK_STATUS_SIZE(x)            (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_RX_CHECK_STATUS_SIZE_SHIFT)) & SPIM_CMD_RX_CHECK_STATUS_SIZE_MASK)
/* The type of checking, 0 - Equal; 1 - check the bits of one; 2 - check the bits of zero */
#define SPIM_CMD_RX_CHECK_CHECK_TYPE_MASK           (0x3000000U)
#define SPIM_CMD_RX_CHECK_CHECK_TYPE_SHIFT          (24U)
#define SPIM_CMD_RX_CHECK_CHECK_TYPE(x)             (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_RX_CHECK_CHECK_TYPE_SHIFT)) & SPIM_CMD_RX_CHECK_CHECK_TYPE_MASK)
#define SPIM_CMD_RX_CHECK_BYTE_ALIGN_MASK           (0x4000000U)
#define SPIM_CMD_RX_CHECK_BYTE_ALIGN_SHIFT          (26U)
#define SPIM_CMD_RX_CHECK_BYTE_ALIGN(x)             (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_RX_CHECK_BYTE_ALIGN_SHIFT)) & SPIM_CMD_RX_CHECK_BYTE_ALIGN_MASK)
/* The check bits trnsfered by QPI or not */
#define SPIM_CMD_RX_CHECK_QPI_MASK                  (0x8000000U)
#define SPIM_CMD_RX_CHECK_QPI_SHIFT                 (27U)
#define SPIM_CMD_RX_CHECK_QPI(x)                    (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_RX_CHECK_QPI_SHIFT)) & SPIM_CMD_RX_CHECK_QPI_MASK)

/*! @name CMD_FULL_DULP - SPIM Activate full duplex mode */
#define SPIM_CMD_FULL_SIZE_CMD_MASK                 (0xFFFFU)
#define SPIM_CMD_FULL_SIZE_CMD_SHIFT                (0U)
#define SPIM_CMD_FULL_SIZE_CMD(x)                   (((uint32_t)(((uint32_t)(x)) /*<< SPIM_CMD_FULL_SIZE_CMD_SHIFT*/)) & SPIM_CMD_FULL_SIZE_CMD_MASK)
#define SPIM_CMD_FULL_BYTE_ALIGN_CMD_MASK           (0x4000000U)
#define SPIM_CMD_FULL_BYTE_ALIGN_CMD_SHIFT          (26U)
#define SPIM_CMD_FULL_BYTE_ALIGN_CMD(x)             (((uint32_t)(((uint32_t)(x)) << SPIM_CMD_FULL_BYTE_ALIGN_CMD_SHIFT)) & SPIM_CMD_FULL_BYTE_ALIGN_CMD_MASK)



#define SPIM_CMD_CFG(clockDiv,cpol,cpha)   ( SPIM_CMD(SPIM_CMD_CFG_ID) \
                                           | SPIM_CMD_CFG_CLKDIV(clockDiv) \
                                           | SPIM_CMD_CFG_CPOL(cpol) \
                                           | SPIM_CMD_CFG_CPHA(cpha) )

#define SPIM_CMD_SOT(cs)                   ( SPIM_CMD(SPIM_CMD_SOT_ID) \
                                           | SPIM_CMD_SOT_CS(cs) )

#define SPIM_CMD_SEND_CMD(cmd,bits,qpi)    ( SPIM_CMD(SPIM_CMD_SEND_CMD_ID) \
                                           | SPIM_CMD_SEND_VALUEL((cmd >> 8)) \
                                           | SPIM_CMD_SEND_VALUEH((cmd & 0xFF)) \
                                           | SPIM_CMD_SEND_CMD_SIZE(bits - 1) \
                                           | SPIM_CMD_SEND_QPI(qpi) )

#define SPIM_CMD_SEND_ADDR(bits,qpi)       ( SPIM_CMD(SPIM_CMD_SEND_ADDR_ID) \
                                           | SPIM_CMD_SEND_ADDR_VALUE(0) \
                                           | SPIM_CMD_SEND_ADDR_CMD_SIZE((bits - 1)) \
                                           | SPIM_CMD_SEND_ADDR_QPI(qpi) )


#ifndef __PLATFORM_GVSOC__
#define SPIM_CMD_DUMMY(cycles)             (cycles ? ( SPIM_CMD(SPIM_CMD_DUMMY_ID) \
                                           | SPIM_CMD_DUMMY_CYCLE(cycles - 1)) : 0xFFFF0000u)
#else
#define SPIM_CMD_DUMMY(cycles)             (cycles ? ( SPIM_CMD(SPIM_CMD_DUMMY_ID) \
                                           | SPIM_CMD_DUMMY_CYCLE(cycles - 1)) : 0x0u)
#endif

#define SPIM_CMD_TX_DATA(bits,qpi,byte_align)  ( SPIM_CMD(SPIM_CMD_TX_DATA_ID) \
                                           | SPIM_CMD_TX_DATA_SIZE((bits - 1)) \
                                           | SPIM_CMD_TX_DATA_BYTE_ALIGN(byte_align) \
                                           | SPIM_CMD_TX_DATA_QPI(qpi) )

#define SPIM_CMD_RX_DATA(bits,qpi,byte_align)  ( SPIM_CMD(SPIM_CMD_RX_DATA_ID) \
                                           | SPIM_CMD_RX_DATA_SIZE((bits - 1)) \
                                           | SPIM_CMD_RX_DATA_BYTE_ALIGN(byte_align) \
                                           | SPIM_CMD_RX_DATA_QPI(qpi) )

#define SPIM_CMD_RPT(iter)                 ( SPIM_CMD(SPIM_CMD_RPT_ID) \
                                           | SPIM_CMD_RPT_CNT(iter) )

#define SPIM_CMD_EOT(evt)                  ( SPIM_CMD(SPIM_CMD_EOT_ID) \
                                           | SPIM_CMD_EOT_EVENT_GEN(evt) )

#define SPIM_CMD_WAIT(event)               ( SPIM_CMD(SPIM_CMD_WAIT_ID) \
                                           | SPIM_CMD_WAIT_EVENT_ID(event) )

#define SPIM_CMD_RPT_END()                 ( SPIM_CMD(SPIM_CMD_RPT_END_ID) )

#define SPIM_CMD_DUPLEX(bits,byte_align)   ( SPIM_CMD(SPIM_CMD_DUPLEX_ID) \
                                           | SPIM_CMD_FULL_SIZE_CMD((bits - 1 )) \
                                           | SPIM_CMD_FULL_BYTE_ALIGN_CMD(byte_align) )

#define SPIM_CMD_RX_CHECK(mode,bits,value,qpi,byte_align) \
                                           ( SPIM_CMD(SPIM_CMD_RX_CHECK_ID) \
                                           | SPIM_CMD_RX_CHECK_COMP_DATA(value) \
                                           | SPIM_CMD_RX_CHECK_STATUS_SIZE((bits - 1)) \
                                           | SPIM_CMD_RX_CHECK_CHECK_TYPE(mode) \
                                           | SPIM_CMD_RX_CHECK_BYTE_ALIGN(byte_align) \
                                           | SPIM_CMD_RX_CHECK_QPI(qpi) )
/*!
 * @}
 */ /* end of group SPIM_Register_Masks */


/* SPIM - Peripheral instance base addresses */
/** Peripheral SPIM0 base address */
#define SPIM0_BASE                                (UDMA_BASE + 1 * 128U)
/** Peripheral SPIM0 base pointer */
#define SPIM0                                     ((SPIM_Type *)SPIM0_BASE)
/** Peripheral SPIM1 base address */
#define SPIM1_BASE                                (UDMA_BASE + 2 * 128U)
/** Peripheral SPIM1 base pointer */
#define SPIM1                                     ((SPIM_Type *)SPIM1_BASE)
/** Array initializer of SPIM peripheral base addresses */
#define SPIM_BASE_ADDRS                           { SPIM0_BASE, SPIM1_BASE }
/** Array initializer of SPIM peripheral base pointers */
#define SPIM_BASE_PTRS                            { SPIM0, SPIM1 }
/** Array initializer of SPIM peripheral base pointers */
#define QSPIM_BASE_PTRS                           { SPIM0 }
/** Interrupt vectors for the SPIM peripheral type */
#define SPIM_RX_IRQS                              { SPIM0_RX_IRQn, SPIM1_RX_IRQn }
#define SPIM_TX_IRQS                              { SPIM0_TX_IRQn, SPIM1_TX_IRQn }

/*!
 * @}
 */ /* end of group SPIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- HYPERBUS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HYPERBUS_Peripheral_Access_Layer HYPERBUS Peripheral Access Layer
 * @{
 */

/** HYPERBUS - Register Layout Typedef */
typedef struct {
  UDMA_Type    UDMA_HYPERBUS;                        /**< HYPERBUS UDMA general register, offset: 0x0 */
  __IO  uint32_t EXT_ADDR;                           /**< HYPERBUS Memory access address register, offset: 0x20 */
  __IO  uint32_t EXT_CFG;                            /**< Reserved, offset: 0x24 */
  __IO  uint32_t MEM_CFG0;                           /**< HYPERBUS Memory control Configuration register0, offset: 0x28 */
  __IO  uint32_t MEM_CFG1;                           /**< HYPERBUS Memory control Configuration register1, offset: 0x2C */
  __IO  uint32_t MEM_CFG2;                           /**< HYPERBUS Memory control Configuration register2, offset: 0x30 */
  __IO  uint32_t MEM_CFG3;                           /**< HYPERBUS Memory control Configuration register3, offset: 0x34 */
  __IO  uint32_t MEM_CFG4;                           /**< HYPERBUS Memory control Configuration register4, offset: 0x38 */
  __IO  uint32_t MEM_CFG5;                           /**< HYPERBUS Memory control Configuration register5, offset: 0x3C */
  __IO  uint32_t MEM_CFG6;                           /**< HYPERBUS Memory control Configuration register6, offset: 0x40 */
  __IO  uint32_t MEM_CFG7;                           /**< HYPERBUS Memory control Configuration register7, offset: 0x44 */
} HYPERBUS_Type;

/* ----------------------------------------------------------------------------
   -- HYPERBUS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HYPERBUS_Register_Masks HYPERBUS Register Masks
 * @{
 */

/*! @name MEM_CFG0 - HYPERBUS Memory control Configuration register0 */
#define HYPERBUS_MEM_CFG0_MBR0_MASK                    (0xFFU)
#define HYPERBUS_MEM_CFG0_MBR0_SHIFT                   (0U)
#define HYPERBUS_MEM_CFG0_MBR0(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG0_MBR0_SHIFT)) & HYPERBUS_MEM_CFG0_MBR0_MASK)
#define HYPERBUS_MEM_CFG0_LATENCY0_MASK                (0xF00U)
#define HYPERBUS_MEM_CFG0_LATENCY0_SHIFT               (8U)
#define HYPERBUS_MEM_CFG0_LATENCY0(x)                  (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG0_LATENCY0_SHIFT)) & HYPERBUS_MEM_CFG0_LATENCY0_MASK)
#define HYPERBUS_MEM_CFG0_WRAP_SIZE0_MASK              (0x3000U)
#define HYPERBUS_MEM_CFG0_WRAP_SIZE0_SHIFT             (12U)
#define HYPERBUS_MEM_CFG0_WRAP_SIZE0(x)                (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG0_WRAP_SIZE0_SHIFT)) & HYPERBUS_MEM_CFG0_WRAP_SIZE0_MASK)

/*! @name MEM_CFG1 - HYPERBUS Memory control Configuration register1 */
#define HYPERBUS_MEM_CFG1_RD_CSHI0_MASK                (0xFU)
#define HYPERBUS_MEM_CFG1_RD_CSHI0_SHIFT               (0U)
#define HYPERBUS_MEM_CFG1_RD_CSHI0(x)                  (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG1_RD_CSHI0_SHIFT)) & HYPERBUS_MEM_CFG1_RD_CSHI0_MASK)
#define HYPERBUS_MEM_CFG1_RD_CSS0_MASK                 (0xF0U)
#define HYPERBUS_MEM_CFG1_RD_CSS0_SHIFT                (4U)
#define HYPERBUS_MEM_CFG1_RD_CSS0(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG1_RD_CSS0_SHIFT)) & HYPERBUS_MEM_CFG1_RD_CSS0_MASK)
#define HYPERBUS_MEM_CFG1_RD_CSH0_MASK                 (0xF00U)
#define HYPERBUS_MEM_CFG1_RD_CSH0_SHIFT                (8U)
#define HYPERBUS_MEM_CFG1_RD_CSH0(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG1_RD_CSH0_SHIFT)) & HYPERBUS_MEM_CFG1_RD_CSH0_MASK)
#define HYPERBUS_MEM_CFG1_WR_CSHI0_MASK                (0xF000U)
#define HYPERBUS_MEM_CFG1_WR_CSHI0_SHIFT               (12U)
#define HYPERBUS_MEM_CFG1_WR_CSHI0(x)                  (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG1_WR_CSHI0_SHIFT)) & HYPERBUS_MEM_CFG1_WR_CSHI0_MASK)
#define HYPERBUS_MEM_CFG1_WR_CSS0_MASK                 (0xF0000U)
#define HYPERBUS_MEM_CFG1_WR_CSS0_SHIFT                (16U)
#define HYPERBUS_MEM_CFG1_WR_CSS0(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG1_WR_CSS0_SHIFT)) & HYPERBUS_MEM_CFG1_WR_CSS0_MASK)
#define HYPERBUS_MEM_CFG1_WR_CSH0_MASK                 (0xF00000U)
#define HYPERBUS_MEM_CFG1_WR_CSH0_SHIFT                (20U)
#define HYPERBUS_MEM_CFG1_WR_CSH0(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG1_WR_CSH0_SHIFT)) & HYPERBUS_MEM_CFG1_WR_CSH0_MASK)


/*! @name MEM_CFG2 - HYPERBUS Memory control Configuration register2 */
#define HYPERBUS_MEM_CFG2_RD_MAX_LENGTH0_MASK          (0x1FFU)
#define HYPERBUS_MEM_CFG2_RD_MAX_LENGTH0_SHIFT         (0U)
#define HYPERBUS_MEM_CFG2_RD_MAX_LENGTH0(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG2_RD_MAX_LENGTH0_SHIFT)) & HYPERBUS_MEM_CFG2_RD_MAX_LENGTH0_MASK)
#define HYPERBUS_MEM_CFG2_WR_MAX_LENGTH0_MASK          (0x1FF0000U)
#define HYPERBUS_MEM_CFG2_WR_MAX_LENGTH0_SHIFT         (16U)
#define HYPERBUS_MEM_CFG2_WR_MAX_LENGTH0(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG2_WR_MAX_LENGTH0_SHIFT)) & HYPERBUS_MEM_CFG2_WR_MAX_LENGTH0_MASK)

/*! @name MEM_CFG3 - HYPERBUS Memory control Configuration register3 */
#define HYPERBUS_MEM_CFG3_ACS0_MASK                    (0x1U)
#define HYPERBUS_MEM_CFG3_ACS0_SHIFT                   (0U)
#define HYPERBUS_MEM_CFG3_ACS0(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_ACS0_SHIFT)) & HYPERBUS_MEM_CFG3_ACS0_MASK)
#define HYPERBUS_MEM_CFG3_TCO0_MASK                    (0x2U)
#define HYPERBUS_MEM_CFG3_TCO0_SHIFT                   (1U)
#define HYPERBUS_MEM_CFG3_TCO0(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_TCO0_SHIFT)) & HYPERBUS_MEM_CFG3_TCO0_MASK)
#define HYPERBUS_MEM_CFG3_DT0_MASK                     (0x4U)
#define HYPERBUS_MEM_CFG3_DT0_SHIFT                    (2U)
#define HYPERBUS_MEM_CFG3_DT0(x)                       (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_DT0_SHIFT)) & HYPERBUS_MEM_CFG3_DT0_MASK)
#define HYPERBUS_MEM_CFG3_CRT0_MASK                    (0x8U)
#define HYPERBUS_MEM_CFG3_CRT0_SHIFT                   (3U)
#define HYPERBUS_MEM_CFG3_CRT0(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_CRT0_SHIFT)) & HYPERBUS_MEM_CFG3_CRT0_MASK)
#define HYPERBUS_MEM_CFG3_RD_MAX_LEN_EN0_MASK          (0x10U)
#define HYPERBUS_MEM_CFG3_RD_MAX_LEN_EN0_SHIFT         (4U)
#define HYPERBUS_MEM_CFG3_RD_MAX_LEN_EN0(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_RD_MAX_LEN_EN0_SHIFT)) & HYPERBUS_MEM_CFG3_RD_MAX_LEN_EN0_MASK)
#define HYPERBUS_MEM_CFG3_WR_MAX_LEN_EN0_MASK          (0x20U)
#define HYPERBUS_MEM_CFG3_WR_MAX_LEN_EN0_SHIFT         (5U)
#define HYPERBUS_MEM_CFG3_WR_MAX_LEN_EN0(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_WR_MAX_LEN_EN0_SHIFT)) & HYPERBUS_MEM_CFG3_WR_MAX_LEN_EN0_MASK)
#define HYPERBUS_MEM_CFG3_RDS_DELAY_ADJ_MASK           (0x300U)
#define HYPERBUS_MEM_CFG3_RDS_DELAY_ADJ_SHIFT          (8U)
#define HYPERBUS_MEM_CFG3_RDS_DELAY_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG3_RDS_DELAY_ADJ_SHIFT)) & HYPERBUS_MEM_CFG3_RDS_DELAY_ADJ_MASK)


/*! @name MEM_CFG4 - HYPERBUS Memory control Configuration register4 */
#define HYPERBUS_MEM_CFG4_MBR1_MASK                    (0xFFU)
#define HYPERBUS_MEM_CFG4_MBR1_SHIFT                   (0U)
#define HYPERBUS_MEM_CFG4_MBR1(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG4_MBR1_SHIFT)) & HYPERBUS_MEM_CFG4_MBR1_MASK)
#define HYPERBUS_MEM_CFG4_LATENCY1_MASK                (0xF00U)
#define HYPERBUS_MEM_CFG4_LATENCY1_SHIFT                (8U)
#define HYPERBUS_MEM_CFG4_LATENCY1(x)                  (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG4_LATENCY1_SHIFT)) & HYPERBUS_MEM_CFG4_LATENCY1_MASK)
#define HYPERBUS_MEM_CFG4_WRAP_SIZE1_MASK              (0x3000U)
#define HYPERBUS_MEM_CFG4_WRAP_SIZE1_SHIFT             (12U)
#define HYPERBUS_MEM_CFG4_WRAP_SIZE1(x)                (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG4_WRAP_SIZE1_SHIFT)) & HYPERBUS_MEM_CFG4_WRAP_SIZE1_MASK)


/*! @name MEM_CFG5 - HYPERBUS Memory control Configuration register5 */
#define HYPERBUS_MEM_CFG5_RD_CSHI1_MASK                (0xFU)
#define HYPERBUS_MEM_CFG5_RD_CSHI1_SHIFT               (0U)
#define HYPERBUS_MEM_CFG5_RD_CSHI1(x)                  (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG5_RD_CSHI1_SHIFT)) & HYPERBUS_MEM_CFG5_RD_CSHI1_MASK)
#define HYPERBUS_MEM_CFG5_RD_CSS1_MASK                 (0xF0U)
#define HYPERBUS_MEM_CFG5_RD_CSS1_SHIFT                (4U)
#define HYPERBUS_MEM_CFG5_RD_CSS1(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG5_RD_CSS1_SHIFT)) & HYPERBUS_MEM_CFG5_RD_CSS1_MASK)
#define HYPERBUS_MEM_CFG5_RD_CSH1_MASK                 (0xF00U)
#define HYPERBUS_MEM_CFG5_RD_CSH1_SHIFT                (8U)
#define HYPERBUS_MEM_CFG5_RD_CSH1(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG5_RD_CSH1_SHIFT)) & HYPERBUS_MEM_CFG5_RD_CSH1_MASK)
#define HYPERBUS_MEM_CFG5_WR_CSHI1_MASK                (0xF000U)
#define HYPERBUS_MEM_CFG5_WR_CSHI1_SHIFT               (12U)
#define HYPERBUS_MEM_CFG5_WR_CSHI1(x)                  (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG5_WR_CSHI1_SHIFT)) & HYPERBUS_MEM_CFG5_WR_CSHI1_MASK)
#define HYPERBUS_MEM_CFG5_WR_CSS1_MASK                 (0xF0000U)
#define HYPERBUS_MEM_CFG5_WR_CSS1_SHIFT                (16U)
#define HYPERBUS_MEM_CFG5_WR_CSS1(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG5_WR_CSS1_SHIFT)) & HYPERBUS_MEM_CFG5_WR_CSS1_MASK)
#define HYPERBUS_MEM_CFG5_WR_CSH1_MASK                 (0xF00000U)
#define HYPERBUS_MEM_CFG5_WR_CSH1_SHIFT                (20U)
#define HYPERBUS_MEM_CFG5_WR_CSH1(x)                   (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG5_WR_CSH1_SHIFT)) & HYPERBUS_MEM_CFG5_WR_CSH1_MASK)

/*! @name MEM_CFG6 - HYPERBUS Memory control Configuration register6 */
#define HYPERBUS_MEM_CFG6_RD_MAX_LENGTH1_MASK          (0x1FFU)
#define HYPERBUS_MEM_CFG6_RD_MAX_LENGTH1_SHIFT         (0U)
#define HYPERBUS_MEM_CFG6_RD_MAX_LENGTH1(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG6_RD_MAX_LENGTH1_SHIFT)) & HYPERBUS_MEM_CFG6_RD_MAX_LENGTH1_MASK)
#define HYPERBUS_MEM_CFG6_WR_MAX_LENGTH1_MASK          (0x1FF0000U)
#define HYPERBUS_MEM_CFG6_WR_MAX_LENGTH1_SHIFT         (16U)
#define HYPERBUS_MEM_CFG6_WR_MAX_LENGTH1(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG6_WR_MAX_LENGTH1_SHIFT)) & HYPERBUS_MEM_CFG6_WR_MAX_LENGTH1_MASK)


/*! @name MEM_CFG7 - HYPERBUS Memory control Configuration register7 */
#define HYPERBUS_MEM_CFG7_ACS1_MASK                    (0x1U)
#define HYPERBUS_MEM_CFG7_ACS1_SHIFT                   (0U)
#define HYPERBUS_MEM_CFG7_ACS1(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG7_ACS1_SHIFT)) & HYPERBUS_MEM_CFG7_ACS1_MASK)
#define HYPERBUS_MEM_CFG7_TCO1_MASK                    (0x2U)
#define HYPERBUS_MEM_CFG7_TCO1_SHIFT                   (1U)
#define HYPERBUS_MEM_CFG7_TCO1(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG7_TCO1_SHIFT)) & HYPERBUS_MEM_CFG7_TCO1_MASK)
#define HYPERBUS_MEM_CFG7_DT1_MASK                     (0x4U)
#define HYPERBUS_MEM_CFG7_DT1_SHIFT                    (2U)
#define HYPERBUS_MEM_CFG7_DT1(x)                       (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG7_DT1_SHIFT)) & HYPERBUS_MEM_CFG7_DT1_MASK)
#define HYPERBUS_MEM_CFG7_CRT1_MASK                    (0x8U)
#define HYPERBUS_MEM_CFG7_CRT1_SHIFT                   (3U)
#define HYPERBUS_MEM_CFG7_CRT1(x)                      (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG7_CRT1_SHIFT)) & HYPERBUS_MEM_CFG7_CRT1_MASK)
#define HYPERBUS_MEM_CFG7_RD_MAX_LEN_EN1_MASK          (0x10U)
#define HYPERBUS_MEM_CFG7_RD_MAX_LEN_EN1_SHIFT         (4U)
#define HYPERBUS_MEM_CFG7_RD_MAX_LEN_EN1(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG7_RD_MAX_LEN_EN1_SHIFT)) & HYPERBUS_MEM_CFG7_RD_MAX_LEN_EN1_MASK)
#define HYPERBUS_MEM_CFG7_WR_MAX_LEN_EN1_MASK          (0x20U)
#define HYPERBUS_MEM_CFG7_WR_MAX_LEN_EN1_SHIFT         (5U)
#define HYPERBUS_MEM_CFG7_WR_MAX_LEN_EN1(x)            (((uint32_t)(((uint32_t)(x)) << HYPERBUS_MEM_CFG7_WR_MAX_LEN_EN1_SHIFT)) & HYPERBUS_MEM_CFG7_WR_MAX_LEN_EN1_MASK)
/*!
 * @}
 */ /* end of group HYPERBUS_Register_Masks */


/* HYPERBUS - Peripheral instance base addresses */
/** Peripheral HYPERBUS base address */
#define HYPERBUS_BASE0                                 (UDMA_BASE + 3 * 128U)
/** Peripheral HYPERBUS base pointer */
#define HYPERBUS0                                      ((HYPERBUS_Type *)HYPERBUS_BASE0)
/** Array initializer of HYPERBUS peripheral base addresses */
#define HYPERBUS_BASE_ADDRS                           { HYPERBUS_BASE0 }
/** Array initializer of HYPERBUS peripheral base pointers */
#define HYPERBUS_BASE_PTRS                            { HYPERBUS0 }
/** Interrupt vectors for the HYPERBUS peripheral type */
#define HYPERBUS_RX_IRQS                              { HYPERBUS_RX_IRQn }
#define HYPERBUS_TX_IRQS                              { HYPERBUS_TX_IRQn }

/*!
 * @}
 */ /* end of group HYPERBUS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  UDMA_Type    UDMA_UART;                           /**< UART UDMA general register, offset: 0x0 */
  __IO  uint32_t STATUS;                            /**< UART Status register, offset: 0x20 */
  __IO  uint32_t SETUP;                             /**< UART Configuration register, offset: 0x24 */
} UART_Type;

/** UART - Register Layout Typedef */
typedef struct {
  udma_core_t    udma_uart;                           /**< UART UDMA general register, offset: 0x0 */
  __IO  uint32_t STATUS;                            /**< UART Status register, offset: 0x20 */
  __IO  uint32_t SETUP;                             /**< UART Configuration register, offset: 0x24 */
} uart_t;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */
/*! @name STATUS - UART Status register */
#define UART_STATUS_TX_BUSY_MASK                    (0x1U)
#define UART_STATUS_TX_BUSY_SHIFT                   (0U)
#define UART_STATUS_TX_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_STATUS_TX_BUSY_SHIFT)) & UART_STATUS_TX_BUSY_MASK)
#define UART_STATUS_RX_BUSY_MASK                    (0x2U)
#define UART_STATUS_RX_BUSY_SHIFT                   (1U)
#define UART_STATUS_RX_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << UART_STATUS_RX_BUSY_SHIFT)) & UART_STATUS_RX_BUSY_MASK)
#define UART_STATUS_RX_PE_MASK                      (0x4U)
#define UART_STATUS_RX_PE_SHIFT                     (2U)
#define UART_STATUS_RX_PE(x)                        (((uint32_t)(((uint32_t)(x)) << UART_STATUS_RX_PE_SHIFT)) & UART_STATUS_RX_PE_MASK)

/*! @name SETUP - UART SETUP register */
#define UART_SETUP_PARITY_ENA_MASK                  (0x1U)
#define UART_SETUP_PARITY_ENA_SHIFT                 (0U)
#define UART_SETUP_PARITY_ENA(x)                    (((uint32_t)(((uint32_t)(x)) << UART_SETUP_PARITY_ENA_SHIFT)) & UART_SETUP_PARITY_ENA_MASK)

#define UART_SETUP_BIT_LENGTH_MASK                  (0x6U)
#define UART_SETUP_BIT_LENGTH_SHIFT                 (1U)
#define UART_SETUP_BIT_LENGTH(x)                    (((uint32_t)(((uint32_t)(x)) << UART_SETUP_BIT_LENGTH_SHIFT)) & UART_SETUP_BIT_LENGTH_MASK)

#define UART_SETUP_STOP_BITS_MASK                   (0x8U)
#define UART_SETUP_STOP_BITS_SHIFT                  (3U)
#define UART_SETUP_STOP_BITS(x)                     (((uint32_t)(((uint32_t)(x)) << UART_SETUP_STOP_BITS_SHIFT)) & UART_SETUP_STOP_BITS_MASK)

#define UART_SETUP_TX_ENA_MASK                      (0x100U)
#define UART_SETUP_TX_ENA_SHIFT                     (8U)
#define UART_SETUP_TX_ENA(x)                        (((uint32_t)(((uint32_t)(x)) << UART_SETUP_TX_ENA_SHIFT)) & UART_SETUP_TX_ENA_MASK)

#define UART_SETUP_RX_ENA_MASK                      (0x200U)
#define UART_SETUP_RX_ENA_SHIFT                     (9U)
#define UART_SETUP_RX_ENA(x)                        (((uint32_t)(((uint32_t)(x)) << UART_SETUP_RX_ENA_SHIFT)) & UART_SETUP_RX_ENA_MASK)

#define UART_SETUP_CLKDIV_MASK                      (0xFFFF0000U)
#define UART_SETUP_CLKDIV_SHIFT                     (16U)
#define UART_SETUP_CLKDIV(x)                        (((uint32_t)(((uint32_t)(x)) << UART_SETUP_CLKDIV_SHIFT)) & UART_SETUP_CLKDIV_MASK)

/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
#define UDMA_UART_BASE_ID                              (4)
/** Peripheral UART base address */
#define UART_BASE                                 (UDMA_BASE + 4 * 128U)
/** Peripheral UART base pointer */
#define UART                                      ((UART_Type *)UART_BASE)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                           { UART_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                            { UART }
/** Interrupt vectors for the UART peripheral type */
#define UART_RX_IRQS                              { UART_RX_IRQn }
#define UART_TX_IRQS                              { UART_TX_IRQn }

/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */

/** I2C - Register Layout Typedef */
typedef struct {
  UDMA_Type     UDMA_I2C;                           /**< I2C UDMA general register, offset: 0x0 */
  __IO  uint32_t STATUS;                            /**< I2C Status register, offset: 0x20 */
  __IO  uint32_t SETUP;                             /**< I2C Configuration register, offset: 0x24 */

} I2C_Type;

/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */
/*! @name STATUS - I2C Status register */
#define I2C_STATUS_BUSY_MASK                    (0x1U)
#define I2C_STATUS_BUSY_SHIFT                   (0U)
#define I2C_STATUS_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << I2C_STATUS_BUSY_SHIFT)) & I2C_STATUS_BUSY_MASK)
#define I2C_STATUS_ARB_LOST_MASK                (0x2U)
#define I2C_STATUS_ARB_LOST_SHIFT               (1U)
#define I2C_STATUS_ARB_LOST(x)                  (((uint32_t)(((uint32_t)(x)) << I2C_STATUS_ARB_LOST_SHIFT)) & I2C_STATUS_ARB_LOST_MASK)

/*! @name SETUP - I2C SETUP register */
#define I2C_SETUP_DO_RST_MASK                   (0x1U)
#define I2C_SETUP_DO_RST_SHIFT                  (0U)
#define I2C_SETUP_DO_RST(x)                     (((uint32_t)(((uint32_t)(x)) << I2C_SETUP_DO_RST_SHIFT)) & I2C_SETUP_DO_RST_MASK)

/*! @name uDMA - I2C uDMA control CMD */
#define I2C_CMD_MASK                 (0xF0U)
#define I2C_CMD_SHIFT                (4U)

#define I2C_CMD_START                (((uint32_t)(((uint32_t)(0x0)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0x00
#define I2C_CMD_WAIT_EV              (((uint32_t)(((uint32_t)(0x1)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0x10
#define I2C_CMD_STOP                 (((uint32_t)(((uint32_t)(0x2)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0x20
#define I2C_CMD_RD_ACK               (((uint32_t)(((uint32_t)(0x4)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0x40
#define I2C_CMD_RD_NACK              (((uint32_t)(((uint32_t)(0x6)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0x60
#define I2C_CMD_WR                   (((uint32_t)(((uint32_t)(0x8)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0x80
#define I2C_CMD_WAIT                 (((uint32_t)(((uint32_t)(0xA)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0xA0
#define I2C_CMD_RPT                  (((uint32_t)(((uint32_t)(0xC)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0xC0
#define I2C_CMD_CFG                  (((uint32_t)(((uint32_t)(0xE)) << I2C_CMD_SHIFT)) & I2C_CMD_MASK) // 0xE0

/*!
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (UDMA_BASE + 5 * 128U)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
/** Peripheral I2C1 base address */
#define I2C1_BASE                                (UDMA_BASE + 6 * 128U)
/** Peripheral I2C1 base pointer */
#define I2C1                                     ((I2C_Type *)I2C1_BASE)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE, I2C1_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0, I2C1}
/** Interrupt vectors for the I2C peripheral type */
#define I2C_RX_IRQS                              { I2C0_RX_IRQn, I2C1_RX_IRQn }
#define I2C_TX_IRQS                              { I2C0_TX_IRQn, I2C1_TX_IRQn }

/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- DMACPY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMACPY_Peripheral_Access_Layer DMACPY Peripheral Access Layer
 * @{
 */

/** DMACPY - Register Layout Typedef */
typedef struct {
  UDMA_Type     UDMA_DMACPY;                         /**< DMACPY UDMA general register, offset: 0x00 */
  __IO  uint32_t DST_ADDR;                           /**< DMACPY destination address register, offset: 0x20 */
  __IO  uint32_t SRC_ADDR;                           /**< DMACPY source address register, offset: 0x24 */
  __IO  uint32_t MEM_SEL;                            /**< DMACPY transfer direction register, offset: 0x28 */
} DMACPY_Type;

/* ----------------------------------------------------------------------------
   -- DMACPY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMACPY_Register_Masks DMACPY Register Masks
 * @{
 */
/*! @name DMACPY_ADDR - DST SRC DMACPY destination address register */
#define DMACPY_ADDR_MASK                          (0x1FFFFU)
#define DMACPY_ADDR_SHIFT                         (0)
#define DMACPY_ADDR(x)                            (((uint32_t)(((uint32_t)(x)) /*<< DMACPY_ADDR_SHIFT*/)) & DMACPY_ADDR_MASK)

/*! @name MEM_SEL - DMACPY transfer direction selection */
#define DMACPY_MEM_SEL_MASK                       (0x1U)
#define DMACPY_MEM_SEL_SHIFT                      (0)
#define DMACPY_MEM_SEL(x)                         (((uint32_t)(((uint32_t)(x)) << DMACPY_MEM_SEL_SHIFT)) & DMACPY_MEM_SEL_MASK)
/*!
 * @}
 */ /* end of group DMACPY_Register_Masks */


/* DMACPY - Peripheral instance base addresses */
/** Peripheral DMACPY base address */
#define DMACPY_BASE                                 (UDMA_BASE + 7 * 128U)
/** Peripheral DMACPY base pointer */
#define DMACPY                                      ((DMACPY_Type *)DMACPY_BASE)
/** Array initializer of DMACPY peripheral base addresses */
#define DMACPY_BASE_ADDRS                           { DMACPY_BASE }
/** Array initializer of DMACPY peripheral base pointers */
#define DMACPY_BASE_PTRS                            { DMACPY }
/** Interrupt vectors for the DMACPY peripheral type */
#define DMACPY_RX_IRQS                              { DMACPY_RX_IRQn }
#define DMACPY_TX_IRQS                              { DMACPY_TX_IRQn }

/*!
 * @}
 */ /* end of group DMACPY_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Register Layout Typedef */
typedef struct {
  UDMA_Type      UDMA_I2S;                         /**< I2S UDMA general register, offset: 0x0 */
  __IO  uint32_t EXT;                              /**< I2S external clock configuration register, offset: 0x20 */
  __IO  uint32_t CFG_CLKGEN0;                      /**< I2S clock/WS generator 0 configuration register, offset: 0x24 */
  __IO  uint32_t CFG_CLKGEN1;                      /**< I2S clock/WS generator 1 configuration register, offset: 0x28 */
  __IO  uint32_t CHMODE;                           /**< I2S channels mode configuration register, offset: 0x2C */
  __IO  uint32_t FILT_CH0;                         /**< I2S channels 0 filtering configuration register, offset: 0x30 */
  __IO  uint32_t FILT_CH1;                         /**< I2S channels 0 filtering configuration register, offset: 0x34 */
} I2S_Type;

/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */
/*! @name EXT - I2S external clock configuration Register */
#define I2S_EXT_BITS_WORD_MASK                        (0x1FU)
#define I2S_EXT_BITS_WORD_SHIFT                       (0U)
#define I2S_EXT_BITS_WORD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_EXT_BITS_WORD_SHIFT)) & I2S_EXT_BITS_WORD_MASK)

/*! @name CFG_CLKGEN0 - I2S clock/WS generator 0 configuration Register */
#define I2S_CFG_CLKGEN0_BITS_WORD_MASK                (0x1FU)
#define I2S_CFG_CLKGEN0_BITS_WORD_SHIFT               (0U)
#define I2S_CFG_CLKGEN0_BITS_WORD(x)                  (((uint32_t)(((uint32_t)(x)) << I2S_CFG_CLKGEN0_BITS_WORD_SHIFT)) & I2S_CFG_CLKGEN0_BITS_WORD_MASK)
#define I2S_CFG_CLKGEN0_CLK_EN_MASK                   (0x100U)
#define I2S_CFG_CLKGEN0_CLK_EN_SHIFT                  (8U)
#define I2S_CFG_CLKGEN0_CLK_EN(x)                     (((uint32_t)(((uint32_t)(x)) << I2S_CFG_CLKGEN0_CLK_EN_SHIFT)) & I2S_CFG_CLKGEN0_CLK_EN_MASK)
#define I2S_CFG_CLKGEN0_CLK_DIV_MASK                  (0xFFFF0000U)
#define I2S_CFG_CLKGEN0_CLK_DIV_SHIFT                 (16U)
#define I2S_CFG_CLKGEN0_CLK_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_CFG_CLKGEN0_CLK_DIV_SHIFT)) & I2S_CFG_CLKGEN0_CLK_DIV_MASK)

/*! @name CFG_CLKGEN1 - I2S clock/WS generator 1 configuration Register */
#define I2S_CFG_CLKGEN1_BITS_WORD_MASK                (0x1FU)
#define I2S_CFG_CLKGEN1_BITS_WORD_SHIFT               (0U)
#define I2S_CFG_CLKGEN1_BITS_WORD(x)                  (((uint32_t)(((uint32_t)(x)) << I2S_CFG_CLKGEN1_BITS_WORD_SHIFT)) & I2S_CFG_CLKGEN1_BITS_WORD_MASK)
#define I2S_CFG_CLKGEN1_CLK_EN_MASK                   (0x100U)
#define I2S_CFG_CLKGEN1_CLK_EN_SHIFT                  (8U)
#define I2S_CFG_CLKGEN1_CLK_EN(x)                     (((uint32_t)(((uint32_t)(x)) << I2S_CFG_CLKGEN1_CLK_EN_SHIFT)) & I2S_CFG_CLKGEN1_CLK_EN_MASK)
#define I2S_CFG_CLKGEN1_CLK_DIV_MASK                  (0xFFFF0000U)
#define I2S_CFG_CLKGEN1_CLK_DIV_SHIFT                 (16U)
#define I2S_CFG_CLKGEN1_CLK_DIV(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_CFG_CLKGEN1_CLK_DIV_SHIFT)) & I2S_CFG_CLKGEN1_CLK_DIV_MASK)

/*! @name CHMODE - I2S channels mode configuration Register */
#define I2S_CHMODE_CH0_SNAP_CAM_MASK                (0x1U)
#define I2S_CHMODE_CH0_SNAP_CAM_SHIFT               (0U)
#define I2S_CHMODE_CH0_SNAP_CAM(x)                  (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH0_SNAP_CAM_SHIFT)) & I2S_CHMODE_CH0_SNAP_CAM_MASK)
#define I2S_CHMODE_CH0_LSB_FIRST_MASK               (0x10U)
#define I2S_CHMODE_CH0_LSB_FIRST_SHIFT              (4U)
#define I2S_CHMODE_CH0_LSB_FIRST(x)                 (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH0_LSB_FIRST_SHIFT)) & I2S_CHMODE_CH0_LSB_FIRST_MASK)
#define I2S_CHMODE_CH0_PDM_USEFILTER_MASK           (0x100U)
#define I2S_CHMODE_CH0_PDM_USEFILTER_SHIFT          (8U)
#define I2S_CHMODE_CH0_PDM_USEFILTER(x)             (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH0_PDM_USEFILTER_SHIFT)) & I2S_CHMODE_CH0_PDM_USEFILTER_MASK)
#define I2S_CHMODE_CH0_PDM_EN_MASK                  (0x1000U)
#define I2S_CHMODE_CH0_PDM_EN_SHIFT                 (12U)
#define I2S_CHMODE_CH0_PDM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH0_PDM_EN_SHIFT)) & I2S_CHMODE_CH0_PDM_EN_MASK)
#define I2S_CHMODE_CH0_USEDDR_MASK                  (0x10000U)
#define I2S_CHMODE_CH0_USEDDR_SHIFT                 (16U)
#define I2S_CHMODE_CH0_USEDDR(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH0_USEDDR_SHIFT)) & I2S_CHMODE_CH0_USEDDR_MASK)
#define I2S_CHMODE_CH0_MODE_MASK                    (0x3000000U)
#define I2S_CHMODE_CH0_MODE_SHIFT                   (24U)
#define I2S_CHMODE_CH0_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH0_MODE_SHIFT)) & I2S_CHMODE_CH0_MODE_MASK)

#define I2S_CHMODE_CH1_SNAP_CAM_MASK                (0x2U)
#define I2S_CHMODE_CH1_SNAP_CAM_SHIFT               (1U)
#define I2S_CHMODE_CH1_SNAP_CAM(x)                  (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH1_SNAP_CAM_SHIFT)) & I2S_CHMODE_CH1_SNAP_CAM_MASK)
#define I2S_CHMODE_CH1_LSB_FIRST_MASK               (0x20U)
#define I2S_CHMODE_CH1_LSB_FIRST_SHIFT              (5U)
#define I2S_CHMODE_CH1_LSB_FIRST(x)                 (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH1_LSB_FIRST_SHIFT)) & I2S_CHMODE_CH1_LSB_FIRST_MASK)
#define I2S_CHMODE_CH1_PDM_USEFILTER_MASK           (0x200U)
#define I2S_CHMODE_CH1_PDM_USEFILTER_SHIFT          (9U)
#define I2S_CHMODE_CH1_PDM_USEFILTER(x)             (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH1_PDM_USEFILTER_SHIFT)) & I2S_CHMODE_CH1_PDM_USEFILTER_MASK)
#define I2S_CHMODE_CH1_PDM_EN_MASK                  (0x2000U)
#define I2S_CHMODE_CH1_PDM_EN_SHIFT                 (13U)
#define I2S_CHMODE_CH1_PDM_EN(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH1_PDM_EN_SHIFT)) & I2S_CHMODE_CH1_PDM_EN_MASK)
#define I2S_CHMODE_CH1_USEDDR_MASK                  (0x20000U)
#define I2S_CHMODE_CH1_USEDDR_SHIFT                 (17U)
#define I2S_CHMODE_CH1_USEDDR(x)                    (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH1_USEDDR_SHIFT)) & I2S_CHMODE_CH1_USEDDR_MASK)
#define I2S_CHMODE_CH1_MODE_MASK                    (0xC000000U)
#define I2S_CHMODE_CH1_MODE_SHIFT                   (26U)
#define I2S_CHMODE_CH1_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << I2S_CHMODE_CH1_MODE_SHIFT)) & I2S_CHMODE_CH1_MODE_MASK)

/*! @name FILT_CH0 - I2S channels 0 filtering configuration Register */
#define I2S_FILT_CH0_DECIMATION_MASK                (0x3FFU)
#define I2S_FILT_CH0_DECIMATION_SHIFT               (0U)
#define I2S_FILT_CH0_DECIMATION(x)                  (((uint32_t)(((uint32_t)(x)) << I2S_FILT_CH0_DECIMATION_SHIFT)) & I2S_FILT_CH0_DECIMATION_MASK)
#define I2S_FILT_CH0_SHIFT_MASK                     (0x70000U)
#define I2S_FILT_CH0_SHIFT_SHIFT                    (16U)
#define I2S_FILT_CH0_SHIFT(x)                       (((uint32_t)(((uint32_t)(x)) << I2S_FILT_CH0_SHIFT_SHIFT)) & I2S_FILT_CH0_SHIFT_MASK)

/*! @name FILT_CH1 - I2S channels 0 filtering configuration Register */
#define I2S_FILT_CH1_DECIMATION_MASK                (0x3FFU)
#define I2S_FILT_CH1_DECIMATION_SHIFT               (0U)
#define I2S_FILT_CH1_DECIMATION(x)                  (((uint32_t)(((uint32_t)(x)) << I2S_FILT_CH1_DECIMATION_SHIFT)) & I2S_FILT_CH1_DECIMATION_MASK)
#define I2S_FILT_CH1_SHIFT_MASK                     (0x70000U)
#define I2S_FILT_CH1_SHIFT_SHIFT                    (16U)
#define I2S_FILT_CH1_SHIFT(x)                       (((uint32_t)(((uint32_t)(x)) << I2S_FILT_CH1_SHIFT_SHIFT)) & I2S_FILT_CH1_SHIFT_MASK)

/*!
 * @}
 */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/** Peripheral I2S base address */
#define I2S_BASE                                 (UDMA_BASE + 8 * 128U)
/** Peripheral I2S base pointer */
#define I2S                                      ((I2S_Type *)I2S_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { I2S_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { I2S }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_L_IRQS                               { I2S0_L_IRQn, I2S1_L_IRQn }
#define I2S_R_IRQS                               { I2S0_R_IRQn, I2S1_R_IRQn }
/*!
 * @}
 */ /* end of group I2S_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- CPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPI_Peripheral_Access_Layer CPI Peripheral Access Layer
 * @{
 */

/** CPI - Register Layout Typedef */
typedef struct {
  UDMA_Type     UDMA_CPI;                           /**< CPI UDMA general register, offset: 0x0 */
  __IO  uint32_t CFG_GLOB;                          /**< CPI global configuration register, offset: 0x20 */
  __IO  uint32_t CFG_LL;                            /**< CPI lower left comer configuration register, offset: 0x24 */
  __IO  uint32_t CFG_UR;                            /**< CPI upper right comer configuration register, offset: 0x28 */
  __IO  uint32_t CFG_SIZE;                          /**< CPI horizontal resolution configuration register, offset: 0x2C */
  __IO  uint32_t CFG_FILTER;                        /**< CPI RGB coefficients configuration register, offset: 0x30 */
} CPI_Type;

/* ----------------------------------------------------------------------------
   -- CPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CPI_Register_Masks CPI Register Masks
 * @{
 */
/*! @name CFG_GLOB - CPI global configuration register */
#define CPI_CFG_GLOB_FRAMEDROP_EN_MASK             (0x1U)
#define CPI_CFG_GLOB_FRAMEDROP_EN_SHIFT            (0U)
#define CPI_CFG_GLOB_FRAMEDROP_EN(x)               (((uint32_t)(((uint32_t)(x)) << CPI_CFG_GLOB_FRAMEDROP_EN_SHIFT)) & CPI_CFG_GLOB_FRAMEDROP_EN_MASK)
#define CPI_CFG_GLOB_FRAMEDROP_VAL_MASK            (0x7EU)
#define CPI_CFG_GLOB_FRAMEDROP_VAL_SHIFT           (1U)
#define CPI_CFG_GLOB_FRAMEDROP_VAL(x)              (((uint32_t)(((uint32_t)(x)) << CPI_CFG_GLOB_FRAMEDROP_VAL_SHIFT)) & CPI_CFG_GLOB_FRAMEDROP_VAL_MASK)
#define CPI_CFG_GLOB_FRAMESLICE_EN_MASK            (0x80U)
#define CPI_CFG_GLOB_FRAMESLICE_EN_SHIFT           (7U)
#define CPI_CFG_GLOB_FRAMESLICE_EN(x)              (((uint32_t)(((uint32_t)(x)) << CPI_CFG_GLOB_FRAMESLICE_EN_SHIFT)) & CPI_CFG_GLOB_FRAMESLICE_EN_MASK)
#define CPI_CFG_GLOB_FORMAT_MASK                   (0x700U)
#define CPI_CFG_GLOB_FORMAT_SHIFT                  (8U)
#define CPI_CFG_GLOB_FORMAT(x)                     (((uint32_t)(((uint32_t)(x)) << CPI_CFG_GLOB_FORMAT_SHIFT)) & CPI_CFG_GLOB_FORMAT_MASK)
#define CPI_CFG_GLOB_SHIFT_MASK                    (0x7800U)
#define CPI_CFG_GLOB_SHIFT_SHIFT                   (11U)
#define CPI_CFG_GLOB_SHIFT(x)                      (((uint32_t)(((uint32_t)(x)) << CPI_CFG_GLOB_SHIFT_SHIFT)) & CPI_CFG_GLOB_SHIFT_MASK)
#define CPI_CFG_GLOB_EN_MASK                       (0x80000000U)
#define CPI_CFG_GLOB_EN_SHIFT                      (31U)
#define CPI_CFG_GLOB_EN(x)                         (((uint32_t)(((uint32_t)(x)) << CPI_CFG_GLOB_EN_SHIFT)) & CPI_CFG_GLOB_EN_MASK)

/*! @name CFG_LL - CPI lower left comer configuration register */
#define CPI_CFG_LL_FRAMESLICE_LLX_MASK             (0xFFFFU)
#define CPI_CFG_LL_FRAMESLICE_LLX_SHIFT            (0U)
#define CPI_CFG_LL_FRAMESLICE_LLX(x)               (((uint32_t)(((uint32_t)(x)) << CPI_CFG_LL_FRAMESLICE_LLX_SHIFT)) & CPI_CFG_LL_FRAMESLICE_LLX_MASK)
#define CPI_CFG_LL_FRAMESLICE_LLY_MASK             (0xFFFF0000U)
#define CPI_CFG_LL_FRAMESLICE_LLY_SHIFT            (16U)
#define CPI_CFG_LL_FRAMESLICE_LLY(x)               (((uint32_t)(((uint32_t)(x)) << CPI_CFG_LL_FRAMESLICE_LLY_SHIFT)) & CPI_CFG_LL_FRAMESLICE_LLY_MASK)

/*! @name CFG_UR - CPI upper right comer configuration register */
#define CPI_CFG_UR_FRAMESLICE_URX_MASK             (0xFFFFU)
#define CPI_CFG_UR_FRAMESLICE_URX_SHIFT            (0U)
#define CPI_CFG_UR_FRAMESLICE_URX(x)               (((uint32_t)(((uint32_t)(x)) << CPI_CFG_UR_FRAMESLICE_URX_SHIFT)) & CPI_CFG_UR_FRAMESLICE_URX_MASK)
#define CPI_CFG_UR_FRAMESLICE_URY_MASK             (0xFFFF0000U)
#define CPI_CFG_UR_FRAMESLICE_URY_SHIFT            (16U)
#define CPI_CFG_UR_FRAMESLICE_URY(x)               (((uint32_t)(((uint32_t)(x)) << CPI_CFG_UR_FRAMESLICE_URY_SHIFT)) & CPI_CFG_UR_FRAMESLICE_URY_MASK)

/*! @name CFG_SIZE - CPI horizontal resolution configuration register */
#define CPI_CFG_SIZE_MASK                          (0xFFFF0000U)
#define CPI_CFG_SIZE_SHIFT                         (16U)
#define CPI_CFG_SIZE(x)                            (((uint32_t)(((uint32_t)(x)) << CPI_CFG_SIZE_SHIFT)) & CPI_CFG_SIZE_MASK)

/*! @name CFG_FILTER - CPI RGB coefficients  configuration register */
#define CPI_CFG_FILTER_B_COEFF_MASK                (0xFFU)
#define CPI_CFG_FILTER_B_COEFF_SHIFT               (0U)
#define CPI_CFG_FILTER_B_COEFF(x)                  (((uint32_t)(((uint32_t)(x)) << CPI_CFG_FILTER_B_COEFF_SHIFT)) & CPI_CFG_FILTER_B_COEFF_MASK)
#define CPI_CFG_FILTER_G_COEFF_MASK                (0xFF00U)
#define CPI_CFG_FILTER_G_COEFF_SHIFT               (8U)
#define CPI_CFG_FILTER_G_COEFF(x)                  (((uint32_t)(((uint32_t)(x)) << CPI_CFG_FILTER_G_COEFF_SHIFT)) & CPI_CFG_FILTER_G_COEFF_MASK)
#define CPI_CFG_FILTER_R_COEFF_MASK                (0xFF0000U)
#define CPI_CFG_FILTER_R_COEFF_SHIFT               (16U)
#define CPI_CFG_FILTER_R_COEFF(x)                  (((uint32_t)(((uint32_t)(x)) << CPI_CFG_FILTER_R_COEFF_SHIFT)) & CPI_CFG_FILTER_R_COEFF_MASK)

/*!
 * @}
 */ /* end of group CPI_Register_Masks */


/* CPI - Peripheral instance base addresses */
/** Peripheral CPI base address */
#define CPI_BASE                                 (UDMA_BASE + 9 * 128U)
/** Peripheral CPI base pointer */
#define CPI                                      ((CPI_Type *)CPI_BASE)
/** Array initializer of CPI peripheral base addresses */
#define CPI_BASE_ADDRS                           { CPI_BASE }
/** Array initializer of CPI peripheral base pointers */
#define CPI_BASE_PTRS                            { CPI }
/** Interrupt vectors for the CPI peripheral type */
#define CPI_RX_IRQS                              { CPI_RX_IRQn }

/*!
 * @}
 */ /* end of group CPI_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- SOC_CTRL  Peripheral Access Layer
   ---------------------------------------------------------------------------- */

#include "periph/soc_ctrl.h"

/*!
 * @}
 */ /* end of group SOC_CTRL_Register_Masks */


/* SOC_CTRL - Peripheral instance base addresses */
/** Peripheral SOC_CTRL base address */
#define SOC_CTRL_BASE                                (SOC_PERI_BASE + 0x4000u)
/** Peripheral SOC_CTRL base pointer */
#define SOC_CTRL                                     ((soc_ctrl_t *)SOC_CTRL_BASE)
/** Array initializer of SOC_CTRL base addresses */
#define SOC_CTRL_BASE_ADDRS                          { SOC_CTRL_BASE }
/** Array initializer of SOC_CTRL base pointers */
#define SOC_CTRL_BASE_PTRS                           { SOC_CTRL }

/*!
 * @}
 */ /* end of group SOC_CTRL_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- PMU CTRL Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_CTRL_Peripheral_Access_Layer PMU_CTRL Peripheral Access Layer
 * @{
 */

/** PMU - General Register Layout Typedef */
typedef struct {
  __IO uint32_t RAR_DCDC;                     /**< PMU CTRL control register, offset: 0x000 */
  __IO uint32_t SLEEP_CTRL;                   /**< PMU CTRL sleep control register, offset: 0x004 */
  __IO uint32_t FORCE;                        /**< PMU CTRL register, offset: 0x008 */

} PMU_CTRL_Type;


/* ----------------------------------------------------------------------------
   -- PMU_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_CTRL_Register_Masks PMU_CTRL Register Masks
 * @{
 */
/*! @name RAR_DCDC - PMU control register */
#define PMU_CTRL_RAR_DCDC_NV_MASK         (0x1FU)
#define PMU_CTRL_RAR_DCDC_NV_SHIFT        (0U)
#define PMU_CTRL_RAR_DCDC_NV(x)           (((uint32_t)(((uint32_t)(x)) /* << PMU_CTRL_RAR_DCDC_NV_SHIFT*/)) & PMU_CTRL_RAR_DCDC_NV_MASK)
#define READ_PMU_CTRL_RAR_DCDC_NV(x)      (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_RAR_DCDC_NV_MASK)) /*>> PMU_CTRL_RAR_DCDC_NV_SHIFT*/)
#define PMU_CTRL_RAR_DCDC_MV_MASK         (0x1F00U)
#define PMU_CTRL_RAR_DCDC_MV_SHIFT        (8U)
#define PMU_CTRL_RAR_DCDC_MV(x)           (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_RAR_DCDC_MV_SHIFT)) & PMU_CTRL_RAR_DCDC_MV_MASK)
#define READ_PMU_CTRL_RAR_DCDC_MV(x)      (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_RAR_DCDC_MV_MASK)) >> PMU_CTRL_RAR_DCDC_MV_SHIFT)
#define PMU_CTRL_RAR_DCDC_LV_MASK         (0x1F0000U)
#define PMU_CTRL_RAR_DCDC_LV_SHIFT        (16U)
#define PMU_CTRL_RAR_DCDC_LV(x)           (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_RAR_DCDC_LV_SHIFT)) & PMU_CTRL_RAR_DCDC_LV_MASK)
#define READ_PMU_CTRL_RAR_DCDC_LV(x)      (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_RAR_DCDC_LV_MASK)) >> PMU_CTRL_RAR_DCDC_LV_SHIFT)
#define PMU_CTRL_RAR_DCDC_RV_MASK         (0x1F000000U)
#define PMU_CTRL_RAR_DCDC_RV_SHIFT        (24U)
#define PMU_CTRL_RAR_DCDC_RV(x)           (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_RAR_DCDC_RV_SHIFT)) & PMU_CTRL_RAR_DCDC_RV_MASK)
#define READ_PMU_CTRL_RAR_DCDC_RV(x)      (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_RAR_DCDC_RV_MASK)) >> PMU_CTRL_RAR_DCDC_RV_SHIFT)

/*! @name SLEEP_CTRL - PMU control register */
#define PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET_MASK         (0xFU)
#define PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET_SHIFT        (0U)
#define PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET(x)           (((uint32_t)(((uint32_t)(x)) /* << PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET_SHIFT*/)) & PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET(x)      (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET_MASK)) /*>> PMU_CTRL_SLEEP_CTRL_CFG_MEM_RET_SHIFT*/)

#define PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET_MASK     (0x10U)
#define PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET_SHIFT    (4U)
#define PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET(x)       (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET_SHIFT)) & PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET(x)  (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET_MASK)) >> PMU_CTRL_SLEEP_CTRL_CFG_FLL_SOC_RET_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET_MASK  (0x20U)
#define PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET_SHIFT (5U)
#define PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET(x)    (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET_SHIFT)) & PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET(x)   (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET_MASK)) >> PMU_CTRL_SLEEP_CTRL_CFG_FLL_CLUSTER_RET_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL_MASK      (0x7C0U)
#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL_SHIFT     (6U)
#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL(x)        (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL_SHIFT)) & PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL(x)   (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL_MASK)) >> PMU_CTRL_SLEEP_CTRL_EXT_WAKE_SEL_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE_MASK     (0x1800U)
#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE_SHIFT    (11U)
#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE(x)       (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE_SHIFT)) & PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE(x)  (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE_MASK)) >> PMU_CTRL_SLEEP_CTRL_EXT_WAKE_TYPE_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN_MASK       (0x2000U)
#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN_SHIFT      (13U)
#define PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN(x)         (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN_SHIFT)) & PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN(x)    (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN_MASK)) >> PMU_CTRL_SLEEP_CTRL_EXT_WAKE_EN_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_WAKEUP_MASK            (0xC000U)
#define PMU_CTRL_SLEEP_CTRL_WAKEUP_SHIFT           (14U)
#define PMU_CTRL_SLEEP_CTRL_WAKEUP(x)              (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_WAKEUP_SHIFT)) & PMU_CTRL_SLEEP_CTRL_WAKEUP_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_WAKEUP(x)         (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_WAKEUP_MASK)) >> PMU_CTRL_SLEEP_CTRL_WAKEUP_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_BOOT_L2_MASK           (0x10000U)
#define PMU_CTRL_SLEEP_CTRL_BOOT_L2_SHIFT          (16U)
#define PMU_CTRL_SLEEP_CTRL_BOOT_L2(x)             (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_BOOT_L2_SHIFT)) & PMU_CTRL_SLEEP_CTRL_BOOT_L2_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_BOOT_L2(x)        (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_BOOT_L2_MASK)) >> PMU_CTRL_SLEEP_CTRL_BOOT_L2_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_REBOOT_MASK            (0xC0000U)
#define PMU_CTRL_SLEEP_CTRL_REBOOT_SHIFT           (18U)
#define PMU_CTRL_SLEEP_CTRL_REBOOT(x)              (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_REBOOT_SHIFT)) & PMU_CTRL_SLEEP_CTRL_REBOOT_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_REBOOT(x)         (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_REBOOT_MASK)) >> PMU_CTRL_SLEEP_CTRL_REBOOT_SHIFT)

#define PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP_MASK      (0x100000U)
#define PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP_SHIFT     (20U)
#define PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP(x)        (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP_SHIFT)) & PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP_MASK)
#define READ_PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP(x)   (((uint32_t)(((uint32_t)(x)) & PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP_MASK)) >> PMU_CTRL_SLEEP_CTRL_CLUSTER_WAKEUP_SHIFT)

/*! @name FORCE - PMU control register */
#define PMU_CTRL_FORCE_MEM_RET_MASK                (0xFU)
#define PMU_CTRL_FORCE_MEM_RET_SHIFT               (0U)
#define PMU_CTRL_FORCE_MEM_RET(x)                  (((uint32_t)(((uint32_t)(x)) /* << PMU_CTRL_FORCE_MEM_RET_SHIFT*/)) & PMU_CTRL_FORCE_MEM_RET_MASK)

#define PMU_CTRL_FORCE_MEM_PWD_MASK                (0xF0U)
#define PMU_CTRL_FORCE_MEM_PWD_SHIFT               (4U)
#define PMU_CTRL_FORCE_MEM_PWD(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_FORCE_MEM_PWD_SHIFT)) & PMU_CTRL_FORCE_MEM_PWD_MASK)

#define PMU_CTRL_FORCE_FLL_CLUSTER_RET_MASK        (0x100U)
#define PMU_CTRL_FORCE_FLL_CLUSTER_RET_SHIFT       (8U)
#define PMU_CTRL_FORCE_FLL_CLUSTER_RET(x)          (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_FORCE_FLL_CLUSTER_RET_SHIFT)) & PMU_CTRL_FORCE_FLL_CLUSTER_RET_MASK)

#define PMU_CTRL_FORCE_FLL_CLUSTER_PWD_MASK        (0x200U)
#define PMU_CTRL_FORCE_FLL_CLUSTER_PWD_SHIFT       (9U)
#define PMU_CTRL_FORCE_FLL_CLUSTER_PWD(x)          (((uint32_t)(((uint32_t)(x)) << PMU_CTRL_FORCE_FLL_CLUSTER_PWD_SHIFT)) & PMU_CTRL_FORCE_FLL_CLUSTER_PWD_MASK)

/*!
 * @}
 */ /* end of group PMU_CTRL_Register_Masks */


/* PMU CTRL- Peripheral instance base addresses */
/** Peripheral PMU CTRL base address */
#define PMU_CTRL_BASE                               (SOC_CTRL_BASE + 0x0100u)
/** Peripheral PMU_CTRL0 base pointer */
#define PMU_CTRL                                    ((PMU_CTRL_Type *)PMU_CTRL_BASE)
/** Array initializer of PMU_CTRL base addresses */
#define PMU_CTRL_BASE_ADDRS                         { PMU_CTRL_BASE }
/** Array initializer of PMU_CTRL base pointers */
#define PMU_CTRL_BASE_PTRS                          { PMU_CTRL }

/*!
 * @}
 */ /* end of group PMU_CTRL_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct {
  __IO  uint32_t PADFUN[4];                       /**< PORT pad function register 0, offset: 0x000 */
  __IO  uint32_t SLEEP_PADCFG[4];                 /**< PORT sleep pad configuration register 0, offset: 0x010 */
  __IO  uint32_t PAD_SLEEP;                       /**< PORT pad sleep register, offset: 0x020 */
  __IO  uint32_t _reserved0[7];                   /**< reserved, offset: 0x010 */
  __IO  uint32_t PADCFG[16];                      /**< PORT pad configuration register 0, offset: 0x040 */

} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks GPIO Register Masks
 * @{
 */
#define GPIO_NUM                                 32

/*! @name PADFUN - GPIO pad mux registers */
#define PORT_PADFUN_MUX_MASK                     (0x3U)
#define PORT_PADFUN_MUX_SHIFT                    (0U)
#define PORT_PADFUN_MUX(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_PADFUN_MUX_SHIFT)) & PORT_PADFUN_MUX_MASK)

/*! @name PADCFG - GPIO pad configuration registers */
#define PORT_PADCFG_PULL_EN_MASK                 (0x1U)
#define PORT_PADCFG_PULL_EN_SHIFT                (0U)
#define PORT_PADCFG_PULL_EN(x)                   (((uint32_t)(((uint32_t)(x)) << PORT_PADCFG_PULL_EN_SHIFT)) & PORT_PADCFG_PULL_EN_MASK)
#define PORT_PADCFG_DRIVE_STRENGTH_MASK          (0x2U)
#define PORT_PADCFG_DRIVE_STRENGTH_SHIFT         (1U)
#define PORT_PADCFG_DRIVE_STRENGTH(x)            (((uint32_t)(((uint32_t)(x)) << PORT_PADCFG_DRIVE_STRENGTH_SHIFT)) & PORT_PADCFG_DRIVE_STRENGTH_MASK)

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE                              (SOC_CTRL_BASE + 0x0140u)
/** Peripheral PORTA base pointer */
#define PORTA                                   ((PORT_Type *)PORTA_BASE)
/** Array initializer of PORT base addresses */
#define PORT_BASE_ADDRS                         { PORTA_BASE }
/** Array initializer of PORT base pointers */
#define PORT_BASE_PTRS                          { PORTA }

/*!
 * @}
 */ /* end of group PORT_Access_Layer */



/* ----------------------------------------------------------------------------
   -- IO POWER DOMAINS ISOLATION Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IO_ISO_Peripheral_Access_Layer IO_ISO Peripheral Access Layer
 * @{
 */

/** IO_ISO - Register Layout Typedef */
typedef struct {
  __IO  uint32_t GPIO_ISO;                       /**< IO_ISO GPIO power domains isolation, offset: 0x000 */
  __IO  uint32_t CAM_ISO;                        /**< IO_ISO Cemera power domains isolation, offset: 0x004 */
  __IO  uint32_t LVDS_ISO;                       /**< IO_ISO LVDS power domains isolation, offset: 0x008 */

} IO_ISO_Type;

/* ----------------------------------------------------------------------------
   -- IO_ISO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IO_ISO_Register_Masks GPIO Register Masks
 * @{
 */
#define IO_ISO_GPIO_ISO_MASK                 (0x1U)
#define IO_ISO_GPIO_ISO_SHIFT                (0U)
#define IO_ISO_GPIO_ISO(x)                   (((uint32_t)(((uint32_t)(x)) /* << IO_ISO_GPIO_ISO_SHIFT */)) & IO_ISO_GPIO_ISO_MASK)

#define IO_ISO_CAM_ISO_MASK                 (0x1U)
#define IO_ISO_CAM_ISO_SHIFT                (0U)
#define IO_ISO_CAM_ISO(x)                   (((uint32_t)(((uint32_t)(x)) /* << IO_ISO_CAM_ISO_SHIFT */)) & IO_ISO_CAM_ISO_MASK)

#define IO_ISO_LVDS_ISO_MASK                 (0x1U)
#define IO_ISO_LVDS_ISO_SHIFT                (0U)
#define IO_ISO_LVDS_ISO(x)                   (((uint32_t)(((uint32_t)(x)) /* << IO_ISO_LVDS_ISO_SHIFT */)) & IO_ISO_LVDS_ISO_MASK)


/*!
 * @}
 */ /* end of group IO_ISO_Register_Masks */


/* IO_ISO - Peripheral instance base addresses */
/** Peripheral IO_ISO base address */
#define IO_ISO_BASE                               (SOC_CTRL_BASE + 0x01C0u)
/** Peripheral IO_ISO base pointer */
#define IO_ISO                                    ((IO_ISO_Type *)IO_ISO_BASE)
/** Array initializer of IO_ISO base addresses */
#define IO_ISO_BASE_ADDRS                         { IO_ISO_BASE }
/** Array initializer of IO_ISO base pointers */
#define IO_ISO_BASE_PTRS                          { IO_ISO }

/*!
 * @}
 */ /* end of group IO_ISO_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PWM CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_CTRL_Peripheral_Access_Layer PWM_CTRL Peripheral Access Layer
 * @{
 */

/** PWM - Register Layout Typedef */
typedef struct {
  __IO  uint32_t EVENT_CFG;       /**< PWM event configuration register, offset: 0x100 */
  __IO  uint32_t CH_EN;           /**< PWM channel enable register, offset: 0x104 */
} PWM_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- PWM_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_CTRL_Register_Masks PWM_CTRL Register Masks
 * @{
 */

/* Register Access. */
/* Set Event. */
#define PWM_CTRL_EVENT_TIMER_CHAN_SET_MASK               ( 0xFFFFU )
#define PWM_CTRL_EVENT_TIMER_CHAN_SET_SHIFT( x )         ( (uint32_t)(x) )
#define PWM_CTRL_EVENT_TIMER_CHAN_SET( tim, chan, evt )  (((uint32_t)((uint32_t)((uint32_t)tim << 2 | (uint32_t)chan)) << PWM_CTRL_EVENT_TIMER_CHAN_SET_SHIFT( evt << 2 )) & PWM_CTRL_EVENT_TIMER_CHAN_SET_MASK)

/* Enable Event. */
#define PWM_CTRL_EVENT_TIMER_ENA_MASK                    ( 0xF0000U )
#define PWM_CTRL_EVENT_TIMER_ENA_SHIFT                   ( 16 )
#define PWM_CTRL_EVENT_TIMER_ENA( x )                    (((uint32_t)(((uint32_t)(x)) << PWM_CTRL_EVENT_TIMER_ENA_SHIFT)) & PWM_CTRL_EVENT_TIMER_ENA_MASK)

/* Timer enable. */
#define PWM_CTRL_CG_ENA_MASK                             ( 0xFU )
#define PWM_CTRL_CG_ENA_SHIFT                            ( 0 )
#define PWM_CTRL_CG_ENA( x )                             (((uint32_t)(((uint32_t)(x)) << PWM_CTRL_CG_ENA_SHIFT)) & PWM_CTRL_CG_ENA_MASK)

/*!
 * @}
 */ /* end of group PWM_CTRL_Register_Masks */

/* PWM_CTRL - Peripheral instance base addresses */
/** Peripheral PWM_CTRL_CTRL base address */
#define PWM_CTRL_BASE                                (SOC_PERI_BASE + 0x05100u)
/** Peripheral PWM_CTRL_CTRL base pointer */
#define PWM_CTRL                                     ((PWM_CTRL_Type *)PWM_CTRL_BASE)
/** Array initializer of PWM_CTRL_CTRL base addresses */
#define PWM_CTRL_BASE_ADDRS                          { PWM_CTRL_BASE }
/** Array initializer of PWM_CTRL_CTRL base pointers */
#define PWM_CTRL_BASE_PTRS                           { PWM_CTRL }

/*!
 * @}
 */ /* end of group PWM_CTRL_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Peripheral_Access_Layer PWM Peripheral Access Layer
 * @{
 */

/** ADV_TIMER - Register Layout Typedef */
typedef struct {
  __O   uint32_t CMD;              /**< TIMER control register, offset: 0x00 */
  __IO  uint32_t CFG;              /**< TIMER configuration register, offset: 0x04 */
  __IO  uint32_t TH;               /**< TIMER threshold register, offset: 0x08 */
  __IO  uint32_t CH_TH[4];         /**< TIMER Channles' threshold register, offset: 0x0c */
  __IO  uint32_t CH_LUT[4];        /**< TIMER Channles' LUT register, offset: 0x1c */
  __I   uint32_t COUNTER;          /**< TIMER Counter register, offset: 0x2c */
} PWM_Type;

/* ----------------------------------------------------------------------------
   -- PWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PWM_Register_Masks PWM Register Masks
 * @{
 */

/* Register Access. */
/* Send command. */
#define PWM_CMD_MASK                                ( 0x1FU )
#define PWM_CMD_SHIFT                               ( 0 )
#define PWM_CMD( x )                                (((uint32_t)(((uint32_t)(x)) << PWM_CMD_SHIFT)) & PWM_CMD_MASK)

/* Timer config. */
#define PWM_CONFIG_INPUT_SRC_MASK                   ( 0xFFU )
#define PWM_CONFIG_INPUT_SRC_SHIFT                  ( 0 )
#define PWM_CONFIG_INPUT_SRC( x )                   (((uint32_t)(((uint32_t)(x)) << PWM_CONFIG_INPUT_SRC_SHIFT)) & PWM_CONFIG_INPUT_SRC_MASK)

#define PWM_CONFIG_INPUT_MODE_MASK                  ( 0x700U )
#define PWM_CONFIG_INPUT_MODE_SHIFT                 ( 8 )
#define PWM_CONFIG_INPUT_MODE( x )                  (((uint32_t)(((uint32_t)(x)) << PWM_CONFIG_INPUT_MODE_SHIFT)) & PWM_CONFIG_INPUT_MODE_MASK)

#define PWM_CONFIG_CLKSEL_MASK                      ( 0x800U )
#define PWM_CONFIG_CLKSEL_SHIFT                     ( 11 )
#define PWM_CONFIG_CLKSEL( x )                      (((uint32_t)(((uint32_t)(x)) << PWM_CONFIG_CLKSEL_SHIFT)) & PWM_CONFIG_CLKSEL_MASK)

#define PWM_CONFIG_UPDOWNSEL_MASK                   ( 0x1000U )
#define PWM_CONFIG_UPDOWNSEL_SHIFT                  ( 12 )
#define PWM_CONFIG_UPDOWNSEL( x )                   (((uint32_t)(((uint32_t)(x)) << PWM_CONFIG_UPDOWNSEL_SHIFT)) & PWM_CONFIG_UPDOWNSEL_MASK)

#define PWM_CONFIG_PRESCALE_MASK                   ( 0xFF0000U )
#define PWM_CONFIG_PRESCALE_SHIFT                  ( 16 )
#define PWM_CONFIG_PRESCALE( x )                   (((uint32_t)(((uint32_t)(x)) << PWM_CONFIG_PRESCALE_SHIFT)) & PWM_CONFIG_PRESCALE_MASK)

/* Channel config. */
#define PWM_THRESHOLD_LOW_MASK                      ( 0xFFFFU )
#define PWM_THRESHOLD_LOW_SHIFT                     ( 0 )
#define PWM_THRESHOLD_LOW( x )                      (((uint32_t)(((uint32_t)(x)) << PWM_THRESHOLD_LOW_SHIFT)) & PWM_THRESHOLD_LOW_MASK)

#define PWM_THRESHOLD_HIGH_MASK                     ( 0xFFFF0000U )
#define PWM_THRESHOLD_HIGH_SHIFT                    ( 16 )
#define PWM_THRESHOLD_HIGH( x )                     (((uint32_t)(((uint32_t)(x)) << PWM_THRESHOLD_HIGH_SHIFT)) & PWM_THRESHOLD_HIGH_MASK)

/* Channel config. */
#define PWM_CHANNEL_CONFIG_THRESHOLD_MASK           ( 0xFFFFU )
#define PWM_CHANNEL_CONFIG_THRESHOLD_SHIFT          ( 0 )
#define PWM_CHANNEL_CONFIG_THRESHOLD( x )           (((uint32_t)(((uint32_t)(x)) << PWM_CHANNEL_CONFIG_THRESHOLD_SHIFT)) & PWM_CHANNEL_CONFIG_THRESHOLD_MASK)

#define PWM_CHANNEL_CONFIG_MODE_MASK                ( 0x70000U )
#define PWM_CHANNEL_CONFIG_MODE_SHIFT               ( 16 )
#define PWM_CHANNEL_CONFIG_MODE( x )                (((uint32_t)(((uint32_t)(x)) << PWM_CHANNEL_CONFIG_MODE_SHIFT)) & PWM_CHANNEL_CONFIG_MODE_MASK)

/*!
 * @}
 */ /* end of group PWM_Register_Masks */


/* PWM - Peripheral instance base addresses */
/** Peripheral PWM base address */
#define PWM0_BASE                               (SOC_PERI_BASE + 0x05000u)
/** Peripheral PWM base pointer */
#define PWM0                                    ((PWM_Type *)PWM0_BASE)
/** Peripheral PWM base address */
#define PWM1_BASE                               (PWM0_BASE + 0x40u)
/** Peripheral PWM base pointer */
#define PWM1                                    ((PWM_Type *)PWM1_BASE)
/** Peripheral PWM base address */
#define PWM2_BASE                               (PWM1_BASE + 0x40u)
/** Peripheral PWM base pointer */
#define PWM2                                    ((PWM_Type *)PWM2_BASE)
/** Peripheral PWM base address */
#define PWM3_BASE                               (PWM2_BASE + 0x40u)
/** Peripheral PWM base pointer */
#define PWM3                                    ((PWM_Type *)PWM3_BASE)
/** Array initializer of PWM base addresses */
#define PWM_BASE_ADDRS                          { PWM0_BASE, PWM1_BASE, PWM2_BASE, PWM3_BASE }
/** Array initializer of PWM base pointers */
#define PWM_BASE_PTRS                           { PWM0, PWM1, PWM2, PWM3 }

/*!
 * @}
 */ /* end of group PWM_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- SOCEU (SOC EVENT UNIT) Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SOCEU_Peripheral_Access_Layer SOCEU Peripheral Access Layer
 * @{
 */

/** SOCEU - Register Layout Typedef */
typedef struct {
  __IO  uint32_t EVENT;                          /**< SOCEU event register, offset: 0x00 */
  __IO  uint32_t FC_MASK_MSB;                    /**< SOCEU fc mask MSB register, offset: 0x04 */
  __IO  uint32_t FC_MASK_LSB;                    /**< SOCEU fc mask LSB register, offset: 0x08 */
  __IO  uint32_t CL_MASK_MSB;                    /**< SOCEU cluster mask MSB register, offset: 0x0C */
  __IO  uint32_t CL_MASK_LSB;                    /**< SOCEU cluster mask LSB register, offset: 0x10 */
  __IO  uint32_t PR_MASK_MSB;                    /**< SOCEU propagate mask MSB register, offset: 0x14 */
  __IO  uint32_t PR_MASK_LSB;                    /**< SOCEU propagate mask LSB register, offset: 0x18 */
  __IO  uint32_t ERR_MASK_MSB;                   /**< SOCEU error mask MSB register, offset: 0x1C */
  __IO  uint32_t ERR_MASK_LSB;                   /**< SOCEU error mask LSB register, offset: 0x20 */
  __IO  uint32_t TIMER_SEL_HI;                   /**< SOCEU timer high register, offset: 0x24 */
  __IO  uint32_t TIMER_SEL_LO;                   /**< SOCEU timer low register, offset: 0x28 */
} SOCEU_Type;

/* ----------------------------------------------------------------------------
   -- SOCEU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SOCEU_Register_Masks SOCEU Register Masks
 * @{
 */
/* The SOC events number */
#define SOC_EVENTS_NUM              0x08
/*!
 * @}
 */ /* end of group SOCEU_Register_Masks */


/* SOCEU - Peripheral instance base addresses */
/** Peripheral SOCEU base address */
#define SOCEU_BASE                               (SOC_PERI_BASE + 0x06000u)
/** Peripheral SOCEU base pointer */
#define SOCEU                                    ((SOCEU_Type *)SOCEU_BASE)
/** Array initializer of SOCEU base addresses */
#define SOCEU_BASE_ADDRS                         { SOCEU_BASE }
/** Array initializer of SOCEU base pointers */
#define SOCEU_BASE_PTRS                          { SOCEU }

/*!
 * @}
 */ /* end of group SOCEU_Peripheral_Access_Layer */





/* ----------------------------------------------------------------------------
   -- SW EVENT TRIGGER Register Address
   ---------------------------------------------------------------------------- */

#define EU_EVT_GETCLUSTERBASE(coreId)     (0x00200800u + (coreId << 6))


/* ----------------------------------------------------------------------------
   -- PMU DLC Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_DLC_Peripheral_Access_Layer PMU_DLC Peripheral Access_Layer
 * @{
 */

/** PMU - General Register Layout Typedef */
typedef struct {
  __IO uint32_t PCTRL;                          /**< PMU DLC control register, offset: 0x00 */
  __IO uint32_t PRDATA;                         /**< PMU DLC data register, offset: 0x04 */
  __IO uint32_t DLC_SR;                         /**< PMU DLC register, offset: 0x08 */
  __IO uint32_t DLC_IMR;                        /**< PMU DLC register, offset: 0x0C */
  __IO uint32_t DLC_IFR;                        /**< PMU DLC register, offset: 0x10 */
  __IO uint32_t DLC_IOIFR;                      /**< PMU DLC register, offset: 0x14 */
  __IO uint32_t DLC_IDIFR;                      /**< PMU DLC register, offset: 0x18 */
  __IO uint32_t DLC_IMCIFR;                     /**< PMU DLC register, offset: 0x1C */

} PMU_DLC_Type;

/* ----------------------------------------------------------------------------
   -- SOCEU Register Masks
   ---------------------------------------------------------------------------- */
/*!
 * @addtogroup PMU_DLC_Register_Masks PMU_DLC Register Masks
 * @{
 */

/*! @name PCTRL - PMU DLC PICL control register */
#define PMU_DLC_PCTRL_START_MASK              (0x1U)
#define PMU_DLC_PCTRL_START_SHIFT             (0U)
#define PMU_DLC_PCTRL_START(x)                (((uint32_t)(((uint32_t)(x)) /* << PMU_DLC_PCTRL_START_SHIFT */)) & PMU_DLC_PCTRL_START_MASK)
#define PMU_DLC_PCTRL_PADDR_MASK              (0x7FFEU)
#define PMU_DLC_PCTRL_PADDR_SHIFT             (1U)
#define PMU_DLC_PCTRL_PADDR(x)                (((uint32_t)(((uint32_t)(x)) << PMU_DLC_PCTRL_PADDR_SHIFT)) & PMU_DLC_PCTRL_PADDR_MASK)
#define PMU_DLC_PCTRL_DIR_MASK                (0x8000U)
#define PMU_DLC_PCTRL_DIR_SHIFT               (15U)
#define PMU_DLC_PCTRL_DIR(x)                  (((uint32_t)(((uint32_t)(x)) << PMU_DLC_PCTRL_DIR_SHIFT)) & PMU_DLC_PCTRL_DIR_MASK)
#define PMU_DLC_PCTRL_PWDATA_MASK             (0xFFFF0000U)
#define PMU_DLC_PCTRL_PWDATA_SHIFT            (16U)
#define PMU_DLC_PCTRL_PWDATA(x)               (((uint32_t)(((uint32_t)(x)) << PMU_DLC_PCTRL_PWDATA_SHIFT)) & PMU_DLC_PCTRL_PWDATA_MASK)

/*! @name PRDATA - PMU DLC PICL data read register */
#define PMU_DLC_PRDATA_PRDATA_MASK            (0xFFU)
#define PMU_DLC_PRDATA_PRDATA_SHIFT           (0U)
#define PMU_DLC_PRDATA_PRDATA(x)              (((uint32_t)(((uint32_t)(x)) /* << PMU_DLC_PRDATA_PRDATA_SHIFT */)) & PMU_DLC_PRDATA_PRDATA_MASK)

/*! @name SR - PMU DLC DLC Status register */
#define PMU_DLC_SR_PICL_BUSY_MASK             (0x1U)
#define PMU_DLC_SR_PICL_BUSY_SHIFT            (0U)
#define PMU_DLC_SR_PICL_BUSY(x)               (((uint32_t)(((uint32_t)(x)) /* << PMU_DLC_SR_PICL_BUSY_SHIFT */)) & PMU_DLC_SR_PICL_BUSY_MASK)
#define PMU_DLC_SR_SCU_BUSY_MASK              (0x2U)
#define PMU_DLC_SR_SCU_BUSY_SHIFT             (1U)
#define PMU_DLC_SR_SCU_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << PMU_DLC_SR_SCU_BUSY_SHIFT)) & PMU_DLC_SR_SCU_BUSY_MASK)

/*! @name IMR - PMU DLC Interrupt mask register */
#define PMU_DLC_IMR_ICU_OK_MASK_MASK          (0x1U)
#define PMU_DLC_IMR_ICU_OK_MASK_SHIFT         (0U)
#define PMU_DLC_IMR_ICU_OK_MASK(x)            (((uint32_t)(((uint32_t)(x)) /* << PMU_DLC_IMR_ICU_OK_MASK_SHIFT */)) & PMU_DLC_IMR_ICU_OK_MASK_MASK)
#define PMU_DLC_IMR_ICU_DELAYED_MASK_MASK     (0x2U)
#define PMU_DLC_IMR_ICU_DELAYED_MASK_SHIFT    (1U)
#define PMU_DLC_IMR_ICU_DELAYED_MASK(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IMR_ICU_DELAYED_MASK_SHIFT)) & PMU_DLC_IMR_ICU_DELAYED_MASK_MASK)
#define PMU_DLC_IMR_ICU_MODE_CHANGED_MASK_MASK     (0x4U)
#define PMU_DLC_IMR_ICU_MODE_CHANGED_MASK_SHIFT    (2U)
#define PMU_DLC_IMR_ICU_MODE_CHANGED_MASK(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IMR_ICU_MODE_CHANGED_MASK_SHIFT)) & PMU_DLC_IMR_ICU_MODE_CHANGED_MASK_MASK)
#define PMU_DLC_IMR_PICL_OK_MASK_MASK         (0x8U)
#define PMU_DLC_IMR_PICL_OK_MASK_SHIFT        (3U)
#define PMU_DLC_IMR_PICL_OK_MASK(x)           (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IMR_PICL_OK_MASK_SHIFT)) & PMU_DLC_IMR_PICL_OK_MASK_MASK)
#define PMU_DLC_IMR_SCU_OK_MASK_MASK          (0x10U)
#define PMU_DLC_IMR_SCU_OK_MASK_SHIFT         (4U)
#define PMU_DLC_IMR_SCU_OK_MASK(x)            (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IMR_SCU_OK_MASK_SHIFT)) & PMU_DLC_IMR_SCU_OK_MASK_MASK)

/*! @name IFR - PMU DLC Interrupt flag register */
#define PMU_DLC_IFR_ICU_OK_FLAG_MASK          (0x1U)
#define PMU_DLC_IFR_ICU_OK_FLAG_SHIFT         (0U)
#define PMU_DLC_IFR_ICU_OK_FLAG(x)            (((uint32_t)(((uint32_t)(x)) /* << PMU_DLC_IFR_ICU_OK_FLAG_SHIFT */)) & PMU_DLC_IFR_ICU_OK_FLAG_MASK)
#define PMU_DLC_IFR_ICU_DELAYED_FLAG_MASK     (0x2U)
#define PMU_DLC_IFR_ICU_DELAYED_FLAG_SHIFT    (1U)
#define PMU_DLC_IFR_ICU_DELAYED_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IFR_ICU_DELAYED_FLAG_SHIFT)) & PMU_DLC_IFR_ICU_DELAYED_FLAG_MASK)
#define PMU_DLC_IFR_ICU_MODE_CHANGED_FLAG_MASK     (0x4U)
#define PMU_DLC_IFR_ICU_MODE_CHANGED_FLAG_SHIFT    (2U)
#define PMU_DLC_IFR_ICU_MODE_CHANGED_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IFR_ICU_MODE_CHANGED_FLAG_SHIFT)) & PMU_DLC_IFR_ICU_MODE_CHANGED_FLAG_MASK)
#define PMU_DLC_IFR_PICL_OK_FLAG_MASK         (0x8U)
#define PMU_DLC_IFR_PICL_OK_FLAG_SHIFT        (3U)
#define PMU_DLC_IFR_PICL_OK_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IFR_PICL_OK_FLAG_SHIFT)) & PMU_DLC_IFR_PICL_OK_FLAG_MASK)
#define PMU_DLC_IFR_SCU_OK_FLAG_MASK          (0x10U)
#define PMU_DLC_IFR_SCU_OK_FLAG_SHIFT         (4U)
#define PMU_DLC_IFR_SCU_OK_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IFR_SCU_OK_FLAG_SHIFT)) & PMU_DLC_IFR_SCU_OK_FLAG_MASK)

/*! @name IOIFR - PMU DLC icu_ok interrupt flag register */
#define PMU_DLC_IOIFR_ICU_OK_FLAG_MASK          (0xFFFFFFFEU)
#define PMU_DLC_IOIFR_ICU_OK_FLAG_SHIFT         (1U)
#define PMU_DLC_IOIFR_ICU_OK_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IOIFR_ICU_OK_FLAG_SHIFT)) & PMU_DLC_IOIFR_ICU_OK_FLAG_MASK)

/*! @name IDIFR - PMU DLC icu_delayed interrupt flag register */
#define PMU_DLC_IDIFR_ICU_DELAYED_FLAG_MASK     (0xFFFFFFFEU)
#define PMU_DLC_IDIFR_ICU_DELAYED_FLAG_SHIFT    (1U)
#define PMU_DLC_IDIFR_ICU_DELAYED_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IDIFR_ICU_DELAYED_FLAG_SHIFT)) & PMU_DLC_IDIFR_ICU_DELAYED_FLAG_MASK)

/*! @name IMCIFR - PMU DLC icu_mode changed interrupt flag register */
#define PMU_DLC_IMCIFR_ICU_MODE_CHANGED_FLAG_MASK     (0xFFFFFFFEU)
#define PMU_DLC_IMCIFR_ICU_MODE_CHANGED_FLAG_SHIFT    (1U)
#define PMU_DLC_IMCIFR_ICU_MODE_CHANGED_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_IMCIFR_ICU_MODE_CHANGED_FLAG_SHIFT)) & PMU_DLC_IMCIFR_ICU_MODE_CHANGED_FLAG_MASK)

/*! @name PCTRL_PADDR The address to write in the DLC_PADDR register is CHIP_SEL_ADDR[4:0] concatenated with REG_ADDR[4:0]. */
#define PMU_DLC_PICL_REG_ADDR_MASK          (0x1FU)
#define PMU_DLC_PICL_REG_ADDR_SHIFT         (0U)
#define PMU_DLC_PICL_REG_ADDR(x)            (((uint32_t)(((uint32_t)(x)) /* << PMU_DLC_PICL_REG_ADDR_SHIFT */)) & PMU_DLC_PICL_REG_ADDR_MASK)
#define PMU_DLC_PICL_CHIP_SEL_ADDR_MASK     (0x3E0U)
#define PMU_DLC_PICL_CHIP_SEL_ADDR_SHIFT    (5U)
#define PMU_DLC_PICL_CHIP_SEL_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << PMU_DLC_PICL_CHIP_SEL_ADDR_SHIFT)) & PMU_DLC_PICL_CHIP_SEL_ADDR_MASK)

/* CHIP_SEL_ADDR[4:0]*/
#define  PICL_WIU_ADDR         0x00
#define  PICL_ICU_ADDR         0x01

/* REG_ADDR[4:0]*/
#define  WIU_ISPMR_0           (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x00))
#define  WIU_ISPMR_1           (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x01))
#define  WIU_IFR_0             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x02))
#define  WIU_IFR_1             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x03))
#define  WIU_ICR_0             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x04))
#define  WIU_ICR_1             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x05))
#define  WIU_ICR_2             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x06))
#define  WIU_ICR_3             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x07))
#define  WIU_ICR_4             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x08))
#define  WIU_ICR_5             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x09))
#define  WIU_ICR_6             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x0A))
#define  WIU_ICR_7             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x0B))
#define  WIU_ICR_8             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x0C))
#define  WIU_ICR_9             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x0D))
#define  WIU_ICR_10            (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x0E))
#define  WIU_ICR_11            (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x0F))
#define  WIU_ICR_12            (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x10))
#define  WIU_ICR_13            (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x11))
#define  WIU_ICR_14            (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x12))
#define  WIU_ICR_15            (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_WIU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x13))

/* REG_ADDR[4:0]*/
#define  ICU_CR                (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_ICU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x00))
#define  ICU_MR                (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_ICU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x01))
#define  ICU_ISMR              (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_ICU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x02))
#define  ICU_DMR_0             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_ICU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x03))
#define  ICU_DMA_1             (PMU_DLC_PICL_CHIP_SEL_ADDR(PICL_ICU_ADDR) | PMU_DLC_PICL_REG_ADDR(0x04))

/*!
 * @}
 */ /* end of group PMU_DLC_Register_Masks */

/* PMU DLC- Peripheral instance base addresses */
/** Peripheral PMU DLC base address */
#define PMU_DLC_BASE                                (SOC_PERI_BASE + 0x7000u)
/** Peripheral PMU_DLC base pointer */
#define PMU_DLC                                     ((PMU_DLC_Type *)PMU_DLC_BASE)
/** Array initializer of PMU_DLC base addresses */
#define PMU_DLC_BASE_ADDRS                          { PMU_DLC_BASE }
/** Array initializer of PMU_DLC base pointers */
#define PMU_DLC_BASE_PTRS                           { PMU_DLC }

/*!
 * @}
 */ /* end of group PMU_DLC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC_APB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_APB_Peripheral_Access_Layer RTC_APB Peripheral Access Layer
 * @{
 */

/** RTC_APB - Register Layout Typedef */
typedef struct {
  __IO  uint32_t STATUS;                     /**< RTC_APB_Status register, offset: 0x00 */
  __IO  uint32_t REQUEST;                    /**< RTC_APB_Request register, offset: 0x04 */
  __IO  uint32_t DATA;                       /**< RTC_APB_Data register, offset: 0x08 */
  __IO  uint32_t _reserved;                  /**< reserved, offset: 0x0C */
  __IO  uint32_t IRQ_CTRL;                   /**< RTC_APB_IRQ_Control register, offset: 0x10 */
  __IO  uint32_t IRQ_MASK;                   /**< RTC_APB_IRQ_Mask register, offset: 0x14 */
  __IO  uint32_t IRQ_FLAG;                   /**< RTC_APB_IRQ_Flag register, offset: 0x18 */
} RTC_APB_Type;

/* ----------------------------------------------------------------------------
   -- RTC_APB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_APB_Register_Masks RTC_APB Register Masks
 * @{
 */
/*! @name STATUS - RTC_APB STATUS register */
#define RTC_APB_STATUS_IRQ_EN_MASK                     (0x3FU)
#define RTC_APB_STATUS_IRQ_EN_SHIFT                    (0U)
#define RTC_APB_STATUS_IRQ_EN(x)                       (((uint32_t)(((uint32_t)(x))/* << RTC_APB_STATUS_IRQ_EN_SHIFT*/)) & RTC_APB_STATUS_IRQ_EN_MASK)

/*! @name REQUEST - RTC_APB REQUEST Access register */
#define RTC_APB_REQUEST_ACCESS_ADDR_MASK               (0x3FU)
#define RTC_APB_REQUEST_ACCESS_ADDR_SHIFT              (0U)
#define RTC_APB_REQUEST_ACCESS_ADDR(x)                 (((uint32_t)(((uint32_t)(x))/* << RTC_APB_REQUEST_ACCESS_ADDR_SHIFT*/)) & RTC_APB_REQUEST_ACCESS_ADDR_MASK)
#define RTC_APB_REQUEST_ACCESS_RW_MASK                 (0x10000U)
#define RTC_APB_REQUEST_ACCESS_RW_SHIFT                (16U)
#define RTC_APB_REQUEST_ACCESS_RW(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_APB_REQUEST_ACCESS_RW_SHIFT)) & RTC_APB_REQUEST_ACCESS_RW_MASK)

/*! @name IRQ_FLAG - RTC_APB IRQ_FLAG Access register */
#define RTC_APB_IRQ_FLAG_READ_MASK                     (0x1U)
#define RTC_APB_IRQ_FLAG_READ_SHIFT                    (0U)
#define RTC_APB_IRQ_FLAG_READ(x)                       (((uint32_t)(((uint32_t)(x))/* << RTC_APB_IRQ_FLAG_READ_SHIFT*/)) & RTC_APB_IRQ_FLAG_READ_MASK)
#define RTC_APB_IRQ_FLAG_WRITE_MASK                    (0x2U)
#define RTC_APB_IRQ_FLAG_WRITE_SHIFT                   (1U)
#define RTC_APB_IRQ_FLAG_WRITE(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_APB_IRQ_FLAG_WRITE_SHIFT)) & RTC_APB_IRQ_FLAG_WRITE_MASK)





/*!
 * @}
 */ /* end of group RTC_APB_Register_Masks */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */
/* Bit field of RTC indirect Access Register */
#define RTC_STATUS_ADDR                     0x00
#define RTC_CTRL_ADDR                       0x01
#define RTC_CLK_CTRL_ADDR                   0x02
#define RTC_IRQ_CTRL_ADDR                   0x08
#define RTC_IRQ_MASK_ADDR                   0x09
#define RTC_IRQ_FLAG_ADDR                   0x0A
#define RTC_CALENDAR_CTRL_ADDR              0x10
#define RTC_CALENDAR_TIME_ADDR              0x12
#define RTC_CALENDAR_DATE_ADDR              0x13
#define RTC_ALARM_CTRL_ADDR                 0x18
#define RTC_ALARM_TIME_ADDR                 0x1A
#define RTC_ALARM_DATE_ADDR                 0x1B
#define RTC_TIMER_CTRL_ADDR                 0x20
#define RTC_TIMER_INIT_ADDR                 0x21
#define RTC_TIMER_VALUE_ADDR                0x22
#define RTC_CLKIN_DIV_ADDR                  0x28
#define RTC_REF_CLK_CONF_ADDR               0x2A
#define RTC_TEST_ADDR                       0x30

/*! @name SR - RTC Status register */
#define RTC_SR_INT_RTC_MASK                 (0x1U)
#define RTC_SR_INT_RTC_SHIFT                (0U)
#define RTC_SR_INT_RTC(x)                   (((uint32_t)(((uint32_t)(x))/* << RTC_SR_INT_RTC_SHIFT*/)) & RTC_SR_INT_RTC_MASK)

/*! @name CR - RTC Control register */
#define RTC_CR_STANDBY_MASK                  (0x1U)
#define RTC_CR_STANDBY_SHIFT                 (0U)
#define RTC_CR_STANDBY(x)                    (((uint32_t)(((uint32_t)(x))/* << RTC_CR_STANDBY_SHIFT*/)) & RTC_CR_STANDBY_MASK)
#define RTC_CR_CALIBRATION_EN_MASK           (0x10U)
#define RTC_CR_CALIBRATION_EN_SHIFT          (4U)
#define RTC_CR_CALIBRATION_EN(x)             (((uint32_t)(((uint32_t)(x)) << RTC_CR_CALIBRATION_EN_SHIFT)) & RTC_CR_CALIBRATION_EN_MASK)
#define RTC_CR_SOFT_RST_MASK                 (0x100U)
#define RTC_CR_SOFT_RST_SHIFT                (8U)
#define RTC_CR_SOFT_RST(x)                   (((uint32_t)(((uint32_t)(x)) << RTC_CR_SOFT_RST_SHIFT)) & RTC_CR_SOFT_RST_MASK)

/*! @name CCR - RTC Clock Control register */
#define RTC_CCR_CKOUT_STANDBY_MASK           (0x1U)
#define RTC_CCR_CKOUT_STANDBY_SHIFT          (0U)
#define RTC_CCR_CKOUT_STANDBY(x)             (((uint32_t)(((uint32_t)(x))/* << RTC_CCR_CKOUT_STANDBY_SHIFT*/)) & RTC_CCR_CKOUT_STANDBY_MASK)
#define RTC_CCR_DIV_AUTOCAL_MASK             (0x1000U)
#define RTC_CCR_DIV_AUTOCAL_SHIFT            (12U)
#define RTC_CCR_DIV_AUTOCAL(x)               (((uint32_t)(((uint32_t)(x)) << RTC_CCR_DIV_AUTOCAL_SHIFT)) & RTC_CCR_DIV_AUTOCAL_MASK)
#define RTC_CCR_DIV_COMP_MASK                (0x1F0000U)
#define RTC_CCR_DIV_COMP_SHIFT               (16U)
#define RTC_CCR_DIV_COMP(x)                  (((uint32_t)(((uint32_t)(x)) << RTC_CCR_DIV_COMP_SHIFT)) & RTC_CCR_DIV_COMP_MASK)

/*! @name ICR - RTC IRQ Control register */
/*
  00  INT_RTC high;
  01  INT_RTC low;
  10; INT_RTC high pulse with duration of 1 CKIN cycle
  11; INT_RTC low pulse with duration of 1 CKIN cycle
*/
#define RTC_ICR_FORM_MASK                    (0x3U)
#define RTC_ICR_FORM_SHIFT                   (0U)
#define RTC_ICR_FORM(x)                      (((uint32_t)(((uint32_t)(x))/* << RTC_ICR_FORM_SHIFT*/)) & RTC_ICR_FORM_MASK)

/*! @name IMR - RTC IRQ MASK register */
#define RTC_IMR_ALARM_MASK                   (0x1U)
#define RTC_IMR_ALARM_SHIFT                  (0U)
#define RTC_IMR_ALARM(x)                     (((uint32_t)(((uint32_t)(x))/* << RTC_IMR_ALARM_SHIFT*/)) & RTC_IMR_ALARM_MASK)
#define RTC_IMR_TIMER_MASK                   (0x10U)
#define RTC_IMR_TIMER_SHIFT                  (4U)
#define RTC_IMR_TIMER(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_IMR_TIMER_SHIFT)) & RTC_IMR_TIMER_MASK)
#define RTC_IMR_CALIBRATION_MASK             (0x1000U)
#define RTC_IMR_CALIBRATION_SHIFT            (12U)
#define RTC_IMR_CALIBRATION(x)               (((uint32_t)(((uint32_t)(x)) << RTC_IMR_CALIBRATION_SHIFT)) & RTC_IMR_CALIBRATION_MASK)

/*! @name IFR - RTC IRQ Flag register */
#define RTC_IFR_ALARM_MASK                   (0x1U)
#define RTC_IFR_ALARM_SHIFT                  (0U)
#define RTC_IFR_ALARM(x)                     (((uint32_t)(((uint32_t)(x))/* << RTC_IFR_ALARM_SHIFT*/)) & RTC_IFR_ALARM_MASK)
#define RTC_IFR_TIMER_MASK                   (0x10U)
#define RTC_IFR_TIMER_SHIFT                  (4U)
#define RTC_IFR_TIMER(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_IFR_TIMER_SHIFT)) & RTC_IFR_TIMER_MASK)
#define RTC_IFR_CALIBRATION_MASK             (0x1000U)
#define RTC_IFR_CALIBRATION_SHIFT            (12U)
#define RTC_IFR_CALIBRATION(x)               (((uint32_t)(((uint32_t)(x)) << RTC_IFR_CALIBRATION_SHIFT)) & RTC_IFR_CALIBRATION_MASK)

/*! @name CALENDAR CTRL - RTC CALENDAR Control register */
#define RTC_CALENDAR_CTRL_STANDBY_MASK       (0x1U)
#define RTC_CALENDAR_CTRL_STANDBY_SHIFT      (0U)
#define RTC_CALENDAR_CTRL_STANDBY(x)         (((uint32_t)(((uint32_t)(x))/* << RTC_CALENDAR_CTRL_STANDBY_SHIFT*/)) & RTC_CALENDAR_CTRL_STANDBY_MASK)

/*! @name ALARM_CTRL - RTC Alarm control register */
#define RTC_ALARM_CTRL_STANDBY_MASK           (0x1U)
#define RTC_ALARM_CTRL_STANDBY_SHIFT          (0U)
#define RTC_ALARM_CTRL_STANDBY(x)             (((uint32_t)(((uint32_t)(x))/* << RTC_ALARM_CTRL_STANDBY_SHIFT*/)) & RTC_ALARM_CTRL_STANDBY_MASK)
#define RTC_ALARM_CTRL_MODE_MASK              (0x10U)
#define RTC_ALARM_CTRL_MODE_SHIFT             (4U)
#define RTC_ALARM_CTRL_MODE(x)                (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_CTRL_MODE_SHIFT)) & RTC_ALARM_CTRL_MODE_MASK)
#define RTC_ALARM_CTRL_CONFIG_MASK            (0xF0000U)
#define RTC_ALARM_CTRL_CONFIG_SHIFT           (16U)
#define RTC_ALARM_CTRL_CONFIG(x)              (((uint32_t)(((uint32_t)(x)) << RTC_ALARM_CTRL_CONFIG_SHIFT)) & RTC_ALARM_CTRL_CONFIG_MASK)

/*! @name TIMER - RTC Count down register */
#define RTC_TIMER_STANDBY_MASK                (0x1U)
#define RTC_TIMER_STANDBY_SHIFT               (0U)
#define RTC_TIMER_STANDBY(x)                  (((uint32_t)(((uint32_t)(x))/* << RTC_TIMER_STANDBY_SHIFT*/)) & RTC_TIMER_STANDBY_MASK)
#define RTC_TIMER_MODE_MASK                   (0x10U)
#define RTC_TIMER_MODE_SHIFT                  (4U)
#define RTC_TIMER_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_TIMER_MODE_SHIFT)) & RTC_TIMER_MODE_MASK)

/*! @name CLKIN_DIV - RTC Clock in divider register */
#define RTC_CLKIN_DIV_VAL_MASK                (0xFFFFU)
#define RTC_CLKIN_DIV_VAL_SHIFT               (0U)
#define RTC_CLKIN_DIV_VAL(x)                  (((uint32_t)(((uint32_t)(x))/* << RTC_CLKIN_DIV_VAL_SHIFT*/)) & RTC_CLKIN_DIV_VAL_MASK)

/*! @name CKREF_CONF - RTC Reference Clock configuration */
#define RTC_CKREF_CONF_VAL_MASK               (0x3FFFFFU)
#define RTC_CKREF_CONF_VAL_SHIFT              (0U)
#define RTC_CKREF_CONF_VAL(x)                 (((uint32_t)(((uint32_t)(x))/* << RTC_CKREF_CONF_VAL_SHIFT*/)) & RTC_CKREF_CONF_VAL_MASK)


/*!
 * @}
 */ /* end of group RTC_Register_Masks */



/* RTC_APB - Peripheral instance base addresses */
/** Peripheral RTC_APB base address */
#define RTC_APB_BASE                               (SOC_PERI_BASE + 0x08000u)
/** Peripheral RTC_APB base pointer */
#define RTC_APB                                    ((RTC_APB_Type *)RTC_APB_BASE)
/** Array initializer of RTC_APB base addresses */
#define RTC_APB_BASE_ADDRS                         { RTC_APB_BASE }
/** Array initializer of RTC_APB base pointers */
#define RTC_APB_BASE_PTRS                          { RTC_APB }

/*!
 * @}
 */ /* end of group RTC_APB_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- EFUSE CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFUSE_CTRL_Peripheral_Access_Layer EFUSE_CTRL Peripheral Access Layer
 * @{
 */

/** EFUSE_CTRL - Register Layout Typedef */
typedef struct {
  __O  uint32_t CMD;                       /**< EFUSE_Control register, offset: 0x00 */
  __O  uint32_t CFG;                       /**< EFUSE_Control register, offset: 0x04 */
} EFUSE_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- EFUSE_CTRL Register Masks
   ---------------------------------------------------------------------------- */
/*! @name CFG - EFUSE control configure register */
#define EFUSE_CTRL_SHORT_MASK                           (0x3FFU)
#define EFUSE_CTRL_SHORT_SHIFT                          (0U)
#define EFUSE_CTRL_SHORT(x)                             (((uint32_t)(((uint32_t)(x)) /* << EFUSE_CTRL_SHORT_SHIFT */)) & EFUSE_CTRL_SHORT_MASK)

#define EFUSE_CTRL_MEDIUM_MASK                          (0xFFC00U)
#define EFUSE_CTRL_MEDIUM_SHIFT                         (10U)
#define EFUSE_CTRL_MEDIUM(x)                            (((uint32_t)(((uint32_t)(x)) << EFUSE_CTRL_MEDIUM_SHIFT)) & EFUSE_CTRL_MEDIUM_MASK)

#define EFUSE_CTRL_LONG_MASK                            (0x3FF00000U)
#define EFUSE_CTRL_LONG_SHIFT                           (20U)
#define EFUSE_CTRL_LONG(x)                              (((uint32_t)(((uint32_t)(x)) << EFUSE_CTRL_LONG_SHIFT)) & EFUSE_CTRL_LONG_MASK)

/*!
 * @addtogroup EFUSE_CTRL_Register_Masks EFUSE_CTRL Register Masks
 * @{
 */
#define    EFUSE_CTRL_CMD_READ       0x1
#define    EFUSE_CTRL_CMD_WRITE      0x2
#define    EFUSE_CTRL_CMD_SLEEP      0x4
/*!
 * @}
 */ /* end of group EFUSE_CTRL_Register_Masks */


/* EFUSE_CTRL - Peripheral instance base addresses */
/** Peripheral EFUSE_CTRL base address */
#define EFUSE_CTRL_BASE                               (SOC_PERI_BASE + 0x09000u)
/** Peripheral EFUSE_CTRL base pointer */
#define EFUSE_CTRL                                    ((EFUSE_CTRL_Type *)EFUSE_CTRL_BASE)
/** Array initializer of EFUSE_CTRL base addresses */
#define EFUSE_CTRL_BASE_ADDRS                         { EFUSE_CTRL_BASE }
/** Array initializer of EFUSE_CTRL base pointers */
#define EFUSE_CTRL_BASE_PTRS                          { EFUSE_CTRL }

/*!
 * @}
 */ /* end of group EFUSE_CTRL_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- EFUSE REG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFUSE_REGS_Peripheral_Access_Layer EFUSE_REGS Peripheral Access Layer
 * @{
 */

/** EFUSE_REGS - Registers Layout Typedef */
typedef struct {
  __IO  uint32_t INFO;                    /**< EFUSE INFO register, offset: 0x000 */
  __IO  uint32_t INFO2;                   /**< EFUSE_INFO2 register, offset: 0x004 */
  __IO  uint32_t AES_KEY[16];             /**< EFUSE_AES_KEY registers, offset: 0x008 */
  __IO  uint32_t AES_IV[8];               /**< EFUSE_AES_IV registers, offset: 0x048 */
  __IO  uint32_t WAIT_XTAL_DELTA_LSB;     /**< EFUSE_WAIT_XTAL_DELTA_LSB register, offset: 0x068 */
  __IO  uint32_t WAIT_XTAL_DELTA_MSB;     /**< EFUSE_WAIT_XTAL_DELTA_MSB register, offset: 0x06C */
  __IO  uint32_t WAIT_XTAL_MIN;           /**< EFUSE_WAIT_XTAL_MIN registers, offset: 0x070 */
  __IO  uint32_t WAIT_XTAL_MAX;           /**< EFUSE_WAIT_XTAL_MAX registers, offset: 0x074 */
  __IO  uint32_t HYPER_RDS_DELAY;         /**< EFUSE_WAIT_XTAL_MAX registers, offset: 0x078 */
  __IO  uint32_t FLL_FREQ;                /**< EFUSE_FLL_FREQ registers, offset: 0x07C */
  __IO  uint32_t FLL_TOLERANCE;           /**< EFUSE_FLL_TOLERANCE registers, offset: 0x080 */
  __IO  uint32_t FLL_ASSERT_CYCLE;        /**< EFUSE_FLL_ASSERT_CYCLE registers, offset: 0x084 */
  __IO  uint32_t _reserved[6];            /**< EFUSE_reserved registers, offset: 0x088 */
  __IO  uint32_t USER_REG[88];            /**< EFUSE_USER_REG, offset: 0x0A0 */
} EFUSE_REGS_Type;

/* ----------------------------------------------------------------------------
   -- EFUSE_REGS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EFUSE_REGS_Register_Masks EFUSE_REGS Register Masks
 * @{
 */
/*! @name INFO - EFUSE information register */
#define EFUSE_INFO_PLT_MASK                           (0x07U)
#define EFUSE_INFO_PLT_SHIFT                          (0U)
#define EFUSE_INFO_PLT(x)                             (((uint32_t)(((uint32_t)(x)) /* << EFUSE_INFO_PLT_SHIFT */)) & EFUSE_INFO_PLT_MASK)

#define EFUSE_INFO_BOOT_MASK                          (0x38U)
#define EFUSE_INFO_BOOT_SHIFT                         (3U)
#define EFUSE_INFO_BOOT(x)                            (((uint32_t)(((uint32_t)(x)) << EFUSE_INFO_BOOT_SHIFT)) & EFUSE_INFO_BOOT_MASK)

#define EFUSE_INFO_ENCRYPTED_MASK                     (0x40U)
#define EFUSE_INFO_ENCRYPTED_SHIFT                    (6U)
#define EFUSE_INFO_ENCRYPTED(x)                       (((uint32_t)(((uint32_t)(x)) << EFUSE_INFO_ENCRYPTED_SHIFT)) & EFUSE_INFO_ENCRYPTED_MASK)

#define EFUSE_INFO_WAIT_XTAL_MASK                     (0x80U)
#define EFUSE_INFO_WAIT_XTAL_SHIFT                    (7U)
#define EFUSE_INFO_WAIT_XTAL(x)                       (((uint32_t)(((uint32_t)(x)) << EFUSE_INFO_WAIT_XTAL_SHIFT)) & EFUSE_INFO_WAIT_XTAL_MASK)


/*!
 * @}
 */ /* end of group EFUSE_REGS_Register_Masks */


/* EFUSE_REGS - Peripheral instance base addresses */
/** Peripheral EFUSE_REGS base address */
#define EFUSE_REGS_BASE                                (SOC_PERI_BASE + 0x09200u)
/** Peripheral EFUSE_REGS base pointer */
#define EFUSE_REGS                                     ((EFUSE_REGS_Type *)EFUSE_REGS_BASE)
/** Array initializer of EFUSE_REGS base addresses */
#define EFUSE_REGS_BASE_ADDRS                          { EFUSE_REGS_BASE }
/** Array initializer of EFUSE_REGS base pointers */
#define EFUSE_REGS_BASE_PTRS                           { EFUSE_REGS }

/*!
 * @}
 */ /* end of group EFUSE_REGS_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- FC_STDOUT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FC_STDOUT_Peripheral_Access_Layer FC_STDOUT Peripheral Access Layer
 * @{
 */

/** FC_STDOUT - Registers Layout Typedef */
typedef struct {
  __IO  uint32_t PUTC[16];                    /**< FC_STDOUT INFO register, offset: 0x000 */
} FC_STDOUT_Type;

/* ----------------------------------------------------------------------------
   -- FC_STDOUT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FC_STDOUT_Register_Masks FC_STDOUT Register Masks
 * @{
 */
/*! @name INFO - FC_STDOUT information register */

/*!
 * @}
 */ /* end of group FC_STDOUT_Register_Masks */


/* FC_STDOUT - Peripheral instance base addresses */
/** Peripheral FC_STDOUT base address */
#define FC_STDOUT_BASE                                (SOC_PERI_BASE + 0x10000u + (FC_CLUSTER_ID << 7))
/** Peripheral FC_STDOUT base pointer */
#define FC_STDOUT                                     ((FC_STDOUT_Type *)FC_STDOUT_BASE)
/** Array initializer of FC_STDOUT base addresses */
#define FC_STDOUT_BASE_ADDRS                          { FC_STDOUT_BASE }
/** Array initializer of FC_STDOUT base pointers */
#define FC_STDOUT_BASE_PTRS                           { FC_STDOUT }

/*!
 * @}
 */ /* end of group FC_STDOUT_Peripheral_Access_Layer */


#ifdef FEATURE_CLUSTER
/* ----------------------------------------------------------------------------
   -- CLUSTER_STDOUT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLUSTER_STDOUT_Peripheral_Access_Layer CLUSTER_STDOUT Peripheral Access Layer
 * @{
 */

/** CLUSTER_STDOUT - Registers Layout Typedef */
typedef struct {
  __IO  uint32_t PUTC[16];                    /**< CLUSTER_STDOUT INFO register, offset: 0x000 */
} CLUSTER_STDOUT_Type;

/* ----------------------------------------------------------------------------
   -- CLUSTER_STDOUT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLUSTER_STDOUT_Register_Masks CLUSTER_STDOUT Register Masks
 * @{
 */
/*! @name INFO - CLUSTER_STDOUT information register */

/*!
 * @}
 */ /* end of group CLUSTER_STDOUT_Register_Masks */


/* CLUSTER_STDOUT - Peripheral instance base addresses */
/** Peripheral CLUSTER_STDOUT base address */
#define CLUSTER_STDOUT_BASE                                (SOC_PERI_BASE + 0x10000u)
/** Peripheral CLUSTER_STDOUT base pointer */
#define CLUSTER_STDOUT                                     ((CLUSTER_STDOUT_Type *)CLUSTER_STDOUT_BASE)
/** Array initializer of CLUSTER_STDOUT base addresses */
#define CLUSTER_STDOUT_BASE_ADDRS                          { CLUSTER_STDOUT_BASE }
/** Array initializer of CLUSTER_STDOUT base pointers */
#define CLUSTER_STDOUT_BASE_PTRS                           { CLUSTER_STDOUT }

/*!
 * @}
 */ /* end of group CLUSTER_STDOUT_Peripheral_Access_Layer */




/* ----------------------------------------------------------------------------
   -- HWCE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HWCE Peripheral_Access_Layer HWCE Peripheral Access Layer
 * @{
 */

/** HWCE - Registers Layout Typedef */
typedef struct {
    __IO  uint32_t HWCE_TRIGGER_REG;              /**< HWCE Trigger register, offset: 0x00 */
    __IO  uint32_t HWCE_ACQUIRE_REG;              /**< HWCE Acquire register, offset: 0x04 */
    __IO  uint32_t HWCE_FINISHED_REG;             /**< HWCE Finished register, offset: 0x08 */
    __IO  uint32_t HWCE_STATUS_REG;               /**< HWCE Status register, offset: 0x0C */
    __IO  uint32_t HWCE_RUNNING_JOB_REG;          /**< HWCE Running Job register, offset: 0x10 */
    __IO  uint32_t HWCE_SOFT_CLEAR_REG;           /**< HWCE Soft_Clear register, offset: 0x14 */
    __IO  uint32_t _reserved0[2];                 /**< HWCE Non used registers, offser: 0x18 */
    __IO  uint32_t HWCE_GEN_CONFIG0_REG;          /**< HWCE Gen_Config0 register, offset: 0x20 */
    __IO  uint32_t HWCE_GEN_CONFIG1_REG;          /**< HWCE Gen_Config1 register, offset: 0x24 */
    __IO  uint32_t _reserved1[6];                 /**< HWCE unused registers, offset: 0x28 */
    __IO  uint32_t HWCE_Y_TRANS_SIZE_REG;         /**< HWCE Y_Trans_Size register, offset: 0x40 */
    __IO  uint32_t HWCE_Y_LINE_STRIDE_LENGTH_REG; /**< HWCE Y_Line_Stride_Length register, offset: 0x44 */
    __IO  uint32_t HWCE_Y_FEAT_STRIDE_LENGTH_REG; /**< HWCE Y_Feat_Stride_Length register, offset: 0x48 */
    __IO  uint32_t HWCE_Y_OUT_3_REG;              /**< HWCE Y_Out_3 register, offset: 0x4C */
    __IO  uint32_t HWCE_Y_OUT_2_REG;              /**< HWCE Y_Out_2 register, offset: 0x50 */
    __IO  uint32_t HWCE_Y_OUT_1_REG;              /**< HWCE Y_Out_1 register, offset: 0x54 */
    __IO  uint32_t HWCE_Y_OUT_0_REG;              /**< HWCE Y_Out_0 register, offset: 0x58 */
    __IO  uint32_t HWCE_Y_IN_3_REG;               /**< HWCE Y_In_3 register, offset: 0x5C */
    __IO  uint32_t HWCE_Y_IN_2_REG;               /**< HWCE Y_In_2 register, offset: 0x60 */
    __IO  uint32_t HWCE_Y_IN_1_REG;               /**< HWCE Y_In_1 register, offset: 0x64 */
    __IO  uint32_t HWCE_Y_IN_0_REG;               /**< HWCE Y_In_0 register, offset: 0x68 */
    __IO  uint32_t HWCE_X_TRANS_SIZE_REG;         /**< HWCE X_Trans_Size register, offset: 0x6C */
    __IO  uint32_t HWCE_X_LINE_STRIDE_LENGTH_REG; /**< HWCE X_Line_Stride_Length register, offset: 0x70 */
    __IO  uint32_t HWCE_X_FEAT_STRIDE_LENGTH_REG; /**< HWCE X_Feat_Stride_Length register, offset: 0x74 */
    __IO  uint32_t HWCE_X_IN_REG;                 /**< HWCE X_In register, offset: 0x78 */
    __IO  uint32_t HWCE_W_REG;                    /**< HWCE W register, offset: 0x7C */
    __IO  uint32_t HWCE_JOB_CONFIG0_REG;          /**< HWCE Job_Config0 register, offset: 0x80 */
    __IO  uint32_t HWCE_JOB_CONFIG1_REG;          /**< HWCE Job_Config1 register, offset: 0x84 */
} HWCE_Type;


/* ----------------------------------------------------------------------------
   -- HWCE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HWCE_Register_Masks HWCE Register Masks
 * @{
 */
/*! @name INFO - HWCE information register */
/* Internal registers */
#define HWCE_TRIGGER              ( 0x00 )
#define HWCE_ACQUIRE              ( 0x04 )
#define HWCE_FINISHED             ( 0x08 )
#define HWCE_STATUS               ( 0x0C )
#define HWCE_RUNNING_JOB          ( 0x10 )
#define HWCE_SOFT_CLEAR           ( 0x14 )
#define HWCE_GEN_CONFIG0          ( 0x20 )
#define HWCE_GEN_CONFIG1          ( 0x24 )

/* Configuration registers */
#define HWCE_Y_TRANS_SIZE         ( 0x40 )
#define HWCE_Y_LINE_STRIDE_LENGTH ( 0x44 )
#define HWCE_Y_FEAT_STRIDE_LENGTH ( 0x48 )
#define HWCE_Y_OUT_3_BASE_ADDR    ( 0x4C )
#define HWCE_Y_OUT_2_BASE_ADDR    ( 0x50 )
#define HWCE_Y_OUT_1_BASE_ADDR    ( 0x54 )
#define HWCE_Y_OUT_0_BASE_ADDR    ( 0x58 )
#define HWCE_Y_IN_3_BASE_ADDR     ( 0x5C )
#define HWCE_Y_IN_2_BASE_ADDR     ( 0x60 )
#define HWCE_Y_IN_1_BASE_ADDR     ( 0x64 )
#define HWCE_Y_IN_0_BASE_ADDR     ( 0x68 )
#define HWCE_X_TRANS_SIZE         ( 0x6C )
#define HWCE_X_LINE_STRIDE_LENGTH ( 0x70 )
#define HWCE_X_FEAT_STRIDE_LENGTH ( 0x74 )
#define HWCE_X_IN_BASE_ADDR       ( 0x78 )
#define HWCE_W_BASE_ADDR          ( 0x7C )
#define HWCE_JOB_CONFIG0          ( 0x80 )
#define HWCE_JOB_CONFIG1          ( 0x84 )

#define HWCE_NB_IO_REGS           ( 18 )

#define HWCE_ACQUIRE_CONTEXT_COPY ( -3 )
#define HWCE_ACQUIRE_LOCKED       ( -2 )
#define HWCE_ACQUIRE_QUEUE_FULL   ( -1 )
#define HWCE_ACQUIRE_READY        ( 0 )

#define HWCE_GEN_CONFIG0_WSTRIDE(x)           ((x) >> 16)
#define HWCE_GEN_CONFIG0_NCP(x)               (((x) >> 13) & 0x1)
#define HWCE_GEN_CONFIG0_CONV(x)              (((x) >> 11) & 0x3)
#define HWCE_GEN_CONFIG0_VECT(x)              (((x) >> 9) & 0x3)
#define HWCE_GEN_CONFIG0_UNS(x)               (((x) >> 8) & 1)
#define HWCE_GEN_CONFIG0_NY(x)                (((x) >> 7) & 1)
#define HWCE_GEN_CONFIG0_NF(x)                (((x) >> 6) & 1)
#define HWCE_GEN_CONFIG0_QF(x)                ((x) & 0x3f)

#define HWCE_GEN_CONFIG0_CONV_5x5 ( 0 )
#define HWCE_GEN_CONFIG0_CONV_3x3 ( 1 )
#define HWCE_GEN_CONFIG0_CONV_4x7 ( 2 )

#define HWCE_GEN_CONFIG0_VECT_1   ( 0 )
#define HWCE_GEN_CONFIG0_VECT_2   ( 1 )
#define HWCE_GEN_CONFIG0_VECT_4   ( 2 )

#define HWCE_GEN_CONFIG1_PIXSHIFTR(x)         (((x) >> 16) & 0x1F)
#define HWCE_GEN_CONFIG1_PIXMODE(x)           (((x) >> 8) & 0x3)
#define HWCE_GEN_CONFIG1_PIXSHIFTL(x)         (((x) >> 0) & 0x1F)

#define HWCE_JOB_CONFIG0_NOYCONST(x)          ((x) >> 16)
#define HWCE_JOB_CONFIG0_LBUFLEN(x)           ((x) & 0x3ff)

#define HWCE_JOB_CONFIG1_LO(x)                (((x) >> 24) & 0x1)
#define HWCE_JOB_CONFIG1_WIF(x)               (((x) >> 16) & 0x3F)
#define HWCE_JOB_CONFIG1_WOF(x)               (((x) >> 8) & 0x1F)
#define HWCE_JOB_CONFIG1_VECT_DISABLE_MASK(x) (((x) >> 0) & 0xF)

#define HWCE_JOB_STRIDE(x)                    ((x) >> 16)
#define HWCE_JOB_LENGTH(x)                    ((x) & 0xffff)

  /*!
   * @}
   */ /* end of group HWCE_Register_Masks */


/* HWCE - Peripheral instance base addresses */
/** Peripheral HWCE base address */
#define HWCE_BASE                                (CORE_PERI_BASE + 0x00001000)
/** Peripheral HWCE base pointer */
#define HWCE                                     ((HWCE_Type *) HWCE_BASE)
/** Array initializer of HWCE base addresses */
#define HWCE_BASE_ADDRS                          { HWCE_BASE }
/** Array initializer of HWCE base pointers */
#define HWCE_BASE_PTRS                           { HWCE }

/*!
 * @}
 */ /* end of group HWCE_Peripheral_Access_Layer */


#endif


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */

/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* _GAP8_H_ */
