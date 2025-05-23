/****************************************************************************
 * arch/arm/src/samv7/hardware/sam_xdmac.h
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_SAMV7_HARDWARE_SAM_XDMAC_H
#define __ARCH_ARM_SRC_SAMV7_HARDWARE_SAM_XDMAC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <arch/samv7/chip.h>

/****************************************************************************
 * Included Files
 ****************************************************************************/

/* XDMAC Register Offsets ***************************************************/

#define SAM_XDMAC_GTYPE_OFFSET      0x0000 /* Global Type Register */
#define SAM_XDMAC_GCFG_OFFSET       0x0004 /* Global Configuration Register */
#define SAM_XDMAC_GWAC_OFFSET       0x0008 /* Global Weighted Arbiter Configuration Register */
#define SAM_XDMAC_GIE_OFFSET        0x000c /* Global Interrupt Enable Register */
#define SAM_XDMAC_GID_OFFSET        0x0010 /* Global Interrupt Disable Register */
#define SAM_XDMAC_GIM_OFFSET        0x0014 /* Global Interrupt Mask Register */
#define SAM_XDMAC_GIS_OFFSET        0x0018 /* Global Interrupt Status Register */
#define SAM_XDMAC_GE_OFFSET         0x001c /* Global Channel Enable Register */
#define SAM_XDMAC_GD_OFFSET         0x0020 /* Global Channel Disable Register */
#define SAM_XDMAC_GS_OFFSET         0x0024 /* Global Channel Status Register */
#define SAM_XDMAC_GRS_OFFSET        0x0028 /* Global Channel Read Suspend Register */
#define SAM_XDMAC_GWS_OFFSET        0x002c /* Global Channel Write Suspend Register */
#define SAM_XDMAC_GRWS_OFFSET       0x0030 /* Global Channel Read Write Suspend Register */
#define SAM_XDMAC_GRWR_OFFSET       0x0034 /* Global Channel Read Write Resume Register */
#define SAM_XDMAC_GSWR_OFFSET       0x0038 /* Global Channel Software Request Register */
#define SAM_XDMAC_GSWS_OFFSET       0x003c /* Global Channel Software Request Status Register */
#define SAM_XDMAC_GSWF_OFFSET       0x0040 /* Global Channel Software Flush Request Register */
                                           /* 0x0044-0x004c Reserved */

/* Offsets to the base of the DMA channel registers */

#define SAM_XDMACH_OFFSET(n)     (0x0050 + ((n) << 6))
#  define SAM_XDMACH0_OFFSET     0x0050
#  define SAM_XDMACH1_OFFSET     0x0090
#  define SAM_XDMACH2_OFFSET     0x00d0
#  define SAM_XDMACH3_OFFSET     0x0110
#  define SAM_XDMACH4_OFFSET     0x0150
#  define SAM_XDMACH5_OFFSET     0x0190
#  define SAM_XDMACH6_OFFSET     0x01d0
#  define SAM_XDMACH7_OFFSET     0x0210
#  define SAM_XDMACH8_OFFSET     0x0250
#  define SAM_XDMACH9_OFFSET     0x0290
#  define SAM_XDMACH10_OFFSET    0x02d0
#  define SAM_XDMACH11_OFFSET    0x0310
#  define SAM_XDMACH12_OFFSET    0x0350
#  define SAM_XDMACH13_OFFSET    0x0390
#  define SAM_XDMACH14_OFFSET    0x03d0
#  define SAM_XDMACH15_OFFSET    0x0410
#  define SAM_XDMACH16_OFFSET    0x0450
#  define SAM_XDMACH17_OFFSET    0x0490
#  define SAM_XDMACH18_OFFSET    0x04d0
#  define SAM_XDMACH19_OFFSET    0x0510
#  define SAM_XDMACH20_OFFSET    0x0550
#  define SAM_XDMACH21_OFFSET    0x0590
#  define SAM_XDMACH22_OFFSET    0x05d0
#  define SAM_XDMACH23_OFFSET    0x0610

/* Offsets to channel registers relative to the base of the DMA channel
 * registers
 */

#define SAM_XDMACH_CIE_OFFSET       0x0000 /* Channel Interrupt Enable Register */
#define SAM_XDMACH_CID_OFFSET       0x0004 /* Channel Interrupt Disable Register */
#define SAM_XDMACH_CIM_OFFSET       0x0008 /* Channel Interrupt Mask Register */
#define SAM_XDMACH_CIS_OFFSET       0x000c /* Channel Interrupt Status Register */
#define SAM_XDMACH_CSA_OFFSET       0x0010 /* Channel Source Address Register */
#define SAM_XDMACH_CDA_OFFSET       0x0014 /* Channel Destination Address Register */
#define SAM_XDMACH_CNDA_OFFSET      0x0018 /* Channel Next Descriptor Address Register */
#define SAM_XDMACH_CNDC_OFFSET      0x001c /* Channel Next Descriptor Control Register */
#define SAM_XDMACH_CUBC_OFFSET      0x0020 /* Channel Microblock Control Register */
#define SAM_XDMACH_CBC_OFFSET       0x0024 /* Channel Block Control Register */
#define SAM_XDMACH_CC_OFFSET        0x0028 /* Channel Configuration Register */
#define SAM_XDMACH_CDSMSP_OFFSET    0x002c /* Channel Data Stride Memory Set Pattern */
#define SAM_XDMACH_CSUS_OFFSET      0x0030 /* Channel Source Microblock Stride */
#define SAM_XDMACH_CDUS_OFFSET      0x0034 /* Channel Destination Microblock Stride */
                                           /* 0x0038-0x003c Reserved */
                                           /* 0x0fec-0x0ffc Reserved */

/* XDMAC Register Addresses *************************************************/

#define SAM_XDMAC_GTYPE             (SAM_XDMAC_BASE+SAM_XDMAC_GTYPE_OFFSET)
#define SAM_XDMAC_GCFG              (SAM_XDMAC_BASE+SAM_XDMAC_GCFG_OFFSET)
#define SAM_XDMAC_GWAC              (SAM_XDMAC_BASE+SAM_XDMAC_GWAC_OFFSET)
#define SAM_XDMAC_GIE               (SAM_XDMAC_BASE+SAM_XDMAC_GIE_OFFSET)
#define SAM_XDMAC_GID               (SAM_XDMAC_BASE+SAM_XDMAC_GID_OFFSET)
#define SAM_XDMAC_GIM               (SAM_XDMAC_BASE+SAM_XDMAC_GIM_OFFSET)
#define SAM_XDMAC_GIS               (SAM_XDMAC_BASE+SAM_XDMAC_GIS_OFFSET)
#define SAM_XDMAC_GE                (SAM_XDMAC_BASE+SAM_XDMAC_GE_OFFSET)
#define SAM_XDMAC_GD                (SAM_XDMAC_BASE+SAM_XDMAC_GD_OFFSET)
#define SAM_XDMAC_GS                (SAM_XDMAC_BASE+SAM_XDMAC_GS_OFFSET)
#define SAM_XDMAC_GRS               (SAM_XDMAC_BASE+SAM_XDMAC_GRS_OFFSET)
#define SAM_XDMAC_GWS               (SAM_XDMAC_BASE+SAM_XDMAC_GWS_OFFSET)
#define SAM_XDMAC_GRWS              (SAM_XDMAC_BASE+SAM_XDMAC_GRWS_OFFSET)
#define SAM_XDMAC_GRWR              (SAM_XDMAC_BASE+SAM_XDMAC_GRWR_OFFSET)
#define SAM_XDMAC_GSWR              (SAM_XDMAC_BASE+SAM_XDMAC_GSWR_OFFSET)
#define SAM_XDMAC_GSWS              (SAM_XDMAC_BASE+SAM_XDMAC_GSWS_OFFSET)
#define SAM_XDMAC_GSWF              (SAM_XDMAC_BASE+SAM_XDMAC_GSWF_OFFSET)

/* Base addresses of XDMAC channel registers */

#define SAM_XDMACH_BASE(n)          (SAM_XDMAC_BASE+SAM_XDMACH_OFFSET(n))
#  define SAM_XDMACH0_BASE          (SAM_XDMAC_BASE+SAM_XDMACH0_OFFSET)
#  define SAM_XDMACH1_BASE          (SAM_XDMAC_BASE+SAM_XDMACH1_OFFSET)
#  define SAM_XDMACH2_BASE          (SAM_XDMAC_BASE+SAM_XDMACH2_OFFSET)
#  define SAM_XDMACH3_BASE          (SAM_XDMAC_BASE+SAM_XDMACH3_OFFSET)
#  define SAM_XDMACH4_BASE          (SAM_XDMAC_BASE+SAM_XDMACH4_OFFSET)
#  define SAM_XDMACH5_BASE          (SAM_XDMAC_BASE+SAM_XDMACH5_OFFSET)
#  define SAM_XDMACH6_BASE          (SAM_XDMAC_BASE+SAM_XDMACH6_OFFSET)
#  define SAM_XDMACH7_BASE          (SAM_XDMAC_BASE+SAM_XDMACH7_OFFSET)
#  define SAM_XDMACH8_BASE          (SAM_XDMAC_BASE+SAM_XDMACH8_OFFSET)
#  define SAM_XDMACH9_BASE          (SAM_XDMAC_BASE+SAM_XDMACH9_OFFSET)
#  define SAM_XDMACH10_BASE         (SAM_XDMAC_BASE+SAM_XDMACH10_OFFSET)
#  define SAM_XDMACH11_BASE         (SAM_XDMAC_BASE+SAM_XDMACH11_OFFSET)
#  define SAM_XDMACH12_BASE         (SAM_XDMAC_BASE+SAM_XDMACH12_OFFSET)
#  define SAM_XDMACH13_BASE         (SAM_XDMAC_BASE+SAM_XDMACH13_OFFSET)
#  define SAM_XDMACH14_BASE         (SAM_XDMAC_BASE+SAM_XDMACH14_OFFSET)
#  define SAM_XDMACH15_BASE         (SAM_XDMAC_BASE+SAM_XDMACH15_OFFSET)
#  define SAM_XDMACH16_BASE         (SAM_XDMAC_BASE+SAM_XDMACH16_OFFSET)
#  define SAM_XDMACH17_BASE         (SAM_XDMAC_BASE+SAM_XDMACH17_OFFSET)
#  define SAM_XDMACH18_BASE         (SAM_XDMAC_BASE+SAM_XDMACH18_OFFSET)
#  define SAM_XDMACH19_BASE         (SAM_XDMAC_BASE+SAM_XDMACH19_OFFSET)
#  define SAM_XDMACH20_BASE         (SAM_XDMAC_BASE+SAM_XDMACH20_OFFSET)
#  define SAM_XDMACH21_BASE         (SAM_XDMAC_BASE+SAM_XDMACH21_OFFSET)
#  define SAM_XDMACH22_BASE         (SAM_XDMAC_BASE+SAM_XDMACH22_OFFSET)
#  define SAM_XDMACH23_BASE         (SAM_XDMAC_BASE+SAM_XDMACH23_OFFSET)

/* Addresses of XDMAC channel registers */

#define SAM_XDMACH_CIE(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CIE_OFFSET)
#define SAM_XDMACH_CID(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CID_OFFSET)
#define SAM_XDMACH_CIM(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CIM_OFFSET)
#define SAM_XDMACH_CIS(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CIS_OFFSET)
#define SAM_XDMACH_CSA(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CSA_OFFSET)
#define SAM_XDMACH_CDA(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CDA_OFFSET)
#define SAM_XDMACH_CNDA(n)          (SAM_XDMACH_BASE(n)+SAM_XDMACH_CNDA_OFFSET)
#define SAM_XDMACH_CNDC(n)          (SAM_XDMACH_BASE(n)+SAM_XDMACH_CNDC_OFFSET)
#define SAM_XDMACH_CUBC(n)          (SAM_XDMACH_BASE(n)+SAM_XDMACH_CUBC_OFFSET)
#define SAM_XDMACH_CBC(n)           (SAM_XDMACH_BASE(n)+SAM_XDMACH_CBC_OFFSET)
#define SAM_XDMACH_CC(n)            (SAM_XDMACH_BASE(n)+SAM_XDMACH_CC_OFFSET)
#define SAM_XDMACH_CDSMSP(n)        (SAM_XDMACH_BASE(n)+SAM_XDMACH_CDSMSP_OFFSET)
#define SAM_XDMACH_CSUS(n)          (SAM_XDMACH_BASE(n)+SAM_XDMACH_CSUS_OFFSET)
#define SAM_XDMACH_CDUS(n)          (SAM_XDMACH_BASE(n)+SAM_XDMACH_CDUS_OFFSET)

/* XDMAC Register Bit Definitions *******************************************/

/* Global Type Register */

#define XDMAC_GTYPE_NB_CH_SHIFT     (0)       /* Bits 0-4: Number of Channels Minus One */
#define XDMAC_GTYPE_NB_CH_MASK      (31 << XDMAC_GTYPE_NB_CH_SHIFT)
#  define XDMAC_GTYPE_NB_CH(n)      ((uint32_t)(n) << XDMAC_GTYPE_NB_CH_SHIFT)
#define XDMAC_GTYPE_FIFO_SZ_SHIFT   (5)       /* Bits 5-15: Number of Bytes */
#define XDMAC_GTYPE_FIFO_SZ_MASK    (0x7ff << XDMAC_GTYPE_FIFO_SZ_SHIFT)
#  define XDMAC_GTYPE_FIFO_SZ(n)    ((uint32_t)(n) << XDMAC_GTYPE_FIFO_SZ_SHIFT)
#define XDMAC_GTYPE_NB_REQ_SHIFT    (16)      /* Bits 16-22: Number of Peripheral Requests Minus One */
#define XDMAC_GTYPE_NB_REQ_MASK     (0x7f << XDMAC_GTYPE_NB_REQ_SHIFT)
#  define XDMAC_GTYPE_NB_REQ(n)     ((uint32_t)(n) << XDMAC_GTYPE_NB_REQ_SHIFT)

/* Global Configuration Register */

#define XDMAC_GCFG_CGDISREG         (1 << 0)  /* Bit 0:  Configuration Registers Clock Gating Disable */
#define XDMAC_GCFG_CGDISPIPE        (1 << 1)  /* Bit 1:  Pipeline Clock Gating Disable */
#define XDMAC_GCFG_CGDISFIFO        (1 << 2)  /* Bit 2:  FIFO Clock Gating Disable */
#define XDMAC_GCFG_CGDISIF          (1 << 3)  /* Bit 3:  Bus Interface Clock Gating Disable */
#define XDMAC_GCFG_BXKBEN           (1 << 8)  /* Bit 8:  Boundary X Kilo byte Enable */

/* Global Weighted Arbiter Configuration Register */

#define XDMAC_GWAC_PW0_SHIFT        (0)       /* Bits 0-3: Pool Weight 0 */
#define XDMAC_GWAC_PW0_MASK         (15 << XDMAC_GWAC_PW0_SHIFT)
#  define XDMAC_GWAC_PW0(n)         ((uint32_t)(n) << XDMAC_GWAC_PW0_SHIFT)
#define XDMAC_GWAC_PW1_SHIFT        (4)       /* Bits 4-7: Pool Weight 1 */
#define XDMAC_GWAC_PW1_MASK         (15 << XDMAC_GWAC_PW1_SHIFT)
#  define XDMAC_GWAC_PW1(n)         ((uint32_t)(n) << XDMAC_GWAC_PW1_SHIFT)
#define XDMAC_GWAC_PW2_SHIFT        (8)       /* Bits 8-11: Pool Weight 2 */
#define XDMAC_GWAC_PW2_MASK         (15 << XDMAC_GWAC_PW2_SHIFT)
#  define XDMAC_GWAC_PW2(n)         ((uint32_t)(n) << XDMAC_GWAC_PW2_SHIFT)
#define XDMAC_GWAC_PW3_SHIFT        (12)      /* Bits 12-15: Pool Weight 3 */
#define XDMAC_GWAC_PW3_MASK         (15 << XDMAC_GWAC_PW3_SHIFT)
#  define XDMAC_GWAC_PW3(n)         ((uint32_t)(n) << XDMAC_GWAC_PW3_SHIFT)

/* All of these registers have the same layout:
 *
 * - Global Interrupt Enable Register, Global Interrupt Disable Register,
 *   Interrupt Mask Register, and Global Interrupt Status Register.
 *
 * - Global Channel Enable Register, Global Channel Disable Register, and
 *   Global Channel Status Register
 *
 * - Global Channel Read Suspend Register, Global Channel Write Suspend
 *   Register, Channel Read Write Suspend Register, and Global Channel
 *   Read Write Resume Register
 *
 * - Global Channel Software Request Register, Global Channel Software
 *   Request Status Register, and Global Channel Software Flush Request
 *   Register
 */

#define XDMAC_CHAN(n)               (1 << (n))
#define XDMAC_CHAN_ALL              (0x0000ffff)

/* Channel Interrupt Enable Register, Channel Interrupt Disable Register,
 * Channel Interrupt Mask Register, and Channel Interrupt Status Register.
 */

#define XDMAC_CHINT_BI              (1 << 0)  /* Bit 0:  End of Block Interrupt  */
#define XDMAC_CHINT_LI              (1 << 1)  /* Bit 1:  End of Linked List Interrupt  */
#define XDMAC_CHINT_DI              (1 << 2)  /* Bit 2:  End of Disable Interrupt  */
#define XDMAC_CHINT_FI              (1 << 3)  /* Bit 3:  End of Flush Interrupt  */
#define XDMAC_CHINT_RBI             (1 << 4)  /* Bit 4:  Read Bus Error Interrupt  */
#define XDMAC_CHINT_WBI             (1 << 5)  /* Bit 5:  Write Bus Error Interrupt */
#define XDMAC_CHINT_ROI             (1 << 6)  /* Bit 6:  Request Overflow Error Interrupt Disable Bit */

#define XDMAC_CHINT_ERRORS          (0x00000070)
#define XDMAC_CHINT_ALL             (0x0000007f)

/* Channel Source Address (SA) Register (aligned 32-bit address) */

/* Channel Destination Address (DA) Register (aligned 32-bit address) */

/* Channel Next Descriptor Address (CNDA) Register
 * (aligned 32-bit address)
 */

#define XDMACH_CNDA_NDAIF           (1 << 0)     /* Bit 0:  Channel Next Descriptor Interface */
#define XDMACH_CNDA_NDA_MASK        (0xfffffffc) /* Bit 2-31:  Channel Next Descriptor Address */

/* Channel Next Descriptor Control Register */

#define XDMACH_CNDC_NDE             (1 << 0)  /* Bit 0:  Channel Next Descriptor Enable */
#define XDMACH_CNDC_NDSUP           (1 << 1)  /* Bit 1:  Channel Next Descriptor Source Update */
#define XDMACH_CNDC_NDDUP           (1 << 2)  /* Bit 2:  Channel Next Descriptor Destination Update */
#define XDMACH_CNDC_NDVIEW_SHIFT    (3)       /* Bits 3-4: Channel Next Descriptor View */
#define XDMACH_CNDC_NDVIEW_MASK     (3 << XDMACH_CNDC_NDVIEW_SHIFT)
#  define XDMACH_CNDC_NDVIEW_NDV0   (0 << XDMACH_CNDC_NDVIEW_SHIFT) /* Next Descriptor View 0 */
#  define XDMACH_CNDC_NDVIEW_NDV1   (1 << XDMACH_CNDC_NDVIEW_SHIFT) /* Next Descriptor View 1 */
#  define XDMACH_CNDC_NDVIEW_NDV2   (2 << XDMACH_CNDC_NDVIEW_SHIFT) /* Next Descriptor View 2 */
#  define XDMACH_CNDC_NDVIEW_NDV3   (3 << XDMACH_CNDC_NDVIEW_SHIFT) /* Next Descriptor View 3 */

/* Channel Microblock Control Register */

#define XDMACH_CUBC_UBLEN_SHIFT     (0)       /* Bits 0-23: Channel Microblock Length */
#define XDMACH_CUBC_UBLEN_MASK      (0x00ffffff << XDMACH_CUBC_UBLEN_SHIFT)
#  define XDMACH_CUBC_UBLEN_MAX     (0x00ffffff)

/* Channel Block Control Register */

#define XDMACH_CBC_BLEN_MASK        (0x000000fff)       /* Bits 0-11: Channel Block Length */

/* Channel Configuration Register */

#define XDMACH_CC_TYPE              (1 << 0)  /* Bit 0:  Channel Transfer Type */
#define XDMACH_CC_MBSIZE_SHIFT      (1)       /* Bits 1-2: Channel Memory Burst Size */
#define XDMACH_CC_MBSIZE_MASK       (3 << XDMACH_CC_MBSIZE_SHIFT)
#  define XDMACH_CC_MBSIZE(n)       ((uint32_t)(n) << XDMACH_CC_MBSIZE_SHIFT) /* n=0-3 */

#  define XDMACH_CC_MBSIZE_1        (0 << XDMACH_CC_MBSIZE_SHIFT) /* The memory burst size is set to one */
#  define XDMACH_CC_MBSIZE_4        (1 << XDMACH_CC_MBSIZE_SHIFT) /* The memory burst size is set to four */
#  define XDMACH_CC_MBSIZE_8        (2 << XDMACH_CC_MBSIZE_SHIFT) /* The memory burst size is set to eight */
#  define XDMACH_CC_MBSIZE_16       (3 << XDMACH_CC_MBSIZE_SHIFT) /* The memory burst size is set to sixteen */

#define XDMACH_CC_DSYNC             (1 << 4)  /* Bit 4:  Channel Synchronization */
#define XDMACH_CC_PROT              (1 << 5)  /* Bit 5:  Channel Protection */
#define XDMACH_CC_SWREQ             (1 << 6)  /* Bit 6:  Channel Software Request Trigger */
#define XDMACH_CC_MEMSET            (1 << 7)  /* Bit 7:  Channel Fill Block of memory */
#define XDMACH_CC_CSIZE_SHIFT       (8)       /* Bits 8-10: Channel Chunk Size */
#define XDMACH_CC_CSIZE_MASK        (7 << XDMACH_CC_CSIZE_SHIFT)
#  define XDMACH_CC_CSIZE_1         (0 << XDMACH_CC_CSIZE_SHIFT) /* 1 data transferred */
#  define XDMACH_CC_CSIZE_2         (1 << XDMACH_CC_CSIZE_SHIFT) /* 2 data transferred */
#  define XDMACH_CC_CSIZE_4         (2 << XDMACH_CC_CSIZE_SHIFT) /* 4 data transferred */
#  define XDMACH_CC_CSIZE_8         (3 << XDMACH_CC_CSIZE_SHIFT) /* 8 data transferred */
#  define XDMACH_CC_CSIZE_16        (4 << XDMACH_CC_CSIZE_SHIFT) /* 16 data transferred */

#define XDMACH_CC_DWIDTH_SHIFT      (11)      /* Bits 11-12: Channel Data Width */
#define XDMACH_CC_DWIDTH_MASK       (3 << XDMACH_CC_DWIDTH_SHIFT)
#  define XDMACH_CC_DWIDTH_BYTE     (0 << XDMACH_CC_DWIDTH_SHIFT) /* The data size is set to 8 bits */
#  define XDMACH_CC_DWIDTH_HWORD    (1 << XDMACH_CC_DWIDTH_SHIFT) /* The data size is set to 16 bits */
#  define XDMACH_CC_DWIDTH_WORD     (2 << XDMACH_CC_DWIDTH_SHIFT) /* The data size is set to 32 bits */

#define XDMACH_CC_SIF               (1 << 13) /* Bit 13: Channel Source Interface Identifier */
#define XDMACH_CC_DIF               (1 << 14) /* Bit 14: Channel Destination Interface Identifier */
#define XDMACH_CC_SAM_SHIFT         (16)      /* Bits 16-17: Channel Source Addressing Mode */
#define XDMACH_CC_SAM_MASK          (3 << XDMACH_CC_SAM_SHIFT)
#  define XDMACH_CC_SAM_FIXED       (0 << XDMACH_CC_SAM_SHIFT) /* The address remains unchanged */
#  define XDMACH_CC_SAM_INCR        (1 << XDMACH_CC_SAM_SHIFT) /* Address is incremented */
#  define XDMACH_CC_SAM_UBS         (2 << XDMACH_CC_SAM_SHIFT) /* Microblock stride is added */
#  define XDMACH_CC_SAM_UBSDS       (3 << XDMACH_CC_SAM_SHIFT) /* Microblock stride and data stride is added */

#define XDMACH_CC_DAM_SHIFT         (18)      /* Bits 18-19: Channel Destination Addressing Mode */
#define XDMACH_CC_DAM_MASK          (3 << XDMACH_CC_DAM_SHIFT)
#  define XDMACH_CC_DAM_FIXED       (0 << XDMACH_CC_DAM_SHIFT) /* The address remains unchanged */
#  define XDMACH_CC_DAM_INCR        (1 << XDMACH_CC_DAM_SHIFT) /* Address is incremented */
#  define XDMACH_CC_DAM_UBS         (2 << XDMACH_CC_DAM_SHIFT) /* Microblock stride is added */
#  define XDMACH_CC_DAM_UBSDS       (3 << XDMACH_CC_DAM_SHIFT) /* Microblock stride and data stride is added */

#define XDMACH_CC_INITD             (1 << 21) /* Bit 21: Channel Initialization Terminated */
#define XDMACH_CC_RDIP              (1 << 22) /* Bit 22: Read in Progress */
#define XDMACH_CC_WRIP              (1 << 23) /* Bit 23: Write in Progress */
#define XDMACH_CC_PERID_SHIFT       (24)      /* Bits 24-30: Channel Peripheral Identifier */
#define XDMACH_CC_PERID_MASK        (0x7f << XDMACH_CC_PERID_SHIFT)
#  define XDMACH_CC_PERID(n)        ((uint32_t)(n) << XDMACH_CC_PERID_SHIFT)

/* Channel Data Stride Memory Set Pattern */

#define XDMACH_CDSMSP_SDS_MSP_SHIFT (0)     /* Bits 0-15: Channel Source Data stride or Memory Set Pattern */
#define XDMACH_CDSMSP_SDS_MSP_MASK  (0xffff << XDMACH_CDSMSP_SDS_MSP_SHIFT)
#  define XDMACH_CDSMSP_SDS_MSP(n)  ((uint32_t)(n) << XDMACH_CDSMSP_SDS_MSP_SHIFT)
#define XDMACH_CDSMSP_DDS_MSP_SHIFT (16)    /* Bits 16-31: Channel Destination Data Stride or Memory Set Pattern */
#define XDMACH_CDSMSP_DDS_MSP_MASK  (0xffff << XDMACH_CDSMSP_DDS_MSP_SHIFT)
#  define XDMACH_CDSMSP_DDS_MSP(n)  ((uint32_t)(n) << XDMACH_CDSMSP_DDS_MSP_SHIFT)

/* Channel Source Microblock Stride */

#define XDMACH_CSUS_SUBS_MASK       (0x00ffffff)       /* Bits 0-23: Channel Source Microblock Stride */

/* Channel Destination Microblock Stride */

#define XDMACH_CDUS_DUBS_MASK       (0x00ffffff)       /* Bits 0-23: Channel Destination Microblock Stride */

/* XDMA Channel Definitions *************************************************/

#define XDMACH_HSMCI                 0
#define XDMACH_SPI0_TX               1
#define XDMACH_SPI0_RX               2
#define XDMACH_SPI1_TX               3
#define XDMACH_SPI1_RX               4
#define XDMACH_QSPI_TX               5
#define XDMACH_QSPI_RX               6
#define XDMACH_USART0_TX             7
#define XDMACH_USART0_RX             8
#define XDMACH_USART1_TX             9
#define XDMACH_USART1_RX             10
#define XDMACH_USART2_TX             11
#define XDMACH_USART2_RX             12
#define XDMACH_PWM0_TX               13
#define XDMACH_TWIHS0_TX             14
#define XDMACH_TWIHS0_RX             15
#define XDMACH_TWIHS1_TX             16
#define XDMACH_TWIHS1_RX             17
#define XDMACH_TWIHS2_TX             18
#define XDMACH_TWIHS2_RX             19
#define XDMACH_UART0_TX              20
#define XDMACH_UART0_RX              21
#define XDMACH_UART1_TX              22
#define XDMACH_UART1_RX              23
#define XDMACH_UART2_TX              24
#define XDMACH_UART2_RX              25
#define XDMACH_UART3_TX              26
#define XDMACH_UART3_RX              27
#define XDMACH_UART4_TX              28
#define XDMACH_UART4_RX              29
#define XDMACH_DACC_TX               30
#define XDMACH_SSC_TX                32
#define XDMACH_SSC_RX                33
#define XDMACH_PIOA_RX               34
#define XDMACH_AFEC0_RX              35
#define XDMACH_AFEC1_RX              36
#define XDMACH_AES_TX                37
#define XDMACH_AES_RX                38
#define XDMACH_PWM1_TX               39
#define XDMACH_TC0_RX                40
#define XDMACH_TC1_RX                41
#define XDMACH_TC2_RX                42
#define XDMACH_TC3_RX                43

/* Descriptor structure member definitions **********************************/

/* Next Descriptor Address (32-bit address) */

/* Microblock Control */

#define CHNEXT_UBC_UBLEN_SHIFT      (0)       /* Bits 0-23: Microblock Length */
#define CHNEXT_UBC_UBLEN_MASK       (0x00ffffff << CHNEXT_UBC_UBLEN_SHIFT)
#  define CHNEXT_UBC_UBLEN(n)       ((uint32_t)(n) << CHNEXT_UBC_UBLEN_SHIFT)
#define CHNEXT_UBC_NDE              (1 << 24) /* Bit 24: Next Descriptor Enable */
#define CHNEXT_UBC_NSEN             (1 << 25) /* Bit 25: Next Descriptor Source Update */
#define CHNEXT_UBC_NDEN             (1 << 26) /* Bit 26: Next Descriptor Destination Update */
#define CHNEXT_UBC_NVIEW_SHIFT      (27)      /* Bits 27-29: Next Descriptor View */
#define CHNEXT_UBC_NVIEW_MASK       (3 << CHNEXT_UBC_NVIEW_SHIFT)
#  define CHNEXT_UBC_NVIEW_0        (0 << CHNEXT_UBC_NVIEW_SHIFT) /* Next Descriptor View 0 */
#  define CHNEXT_UBC_NVIEW_1        (1 << CHNEXT_UBC_NVIEW_SHIFT) /* Next Descriptor View 1 */
#  define CHNEXT_UBC_NVIEW_2        (2 << CHNEXT_UBC_NVIEW_SHIFT) /* Next Descriptor View 2 */
#  define CHNEXT_UBC_NVIEW_3        (3 << CHNEXT_UBC_NVIEW_SHIFT) /* Next Descriptor View 3 */

/* Source Address (32-bit address) */

/* Destination Address (32-bit address) */

/* Configuration Register */

/* Block Control */

/* Data Stride (32-bit value) */

/* Source Microblock Stride (32-bit value) */

/* Destination Microblock Stride (32-bit value) */

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct chnext_view0_s
{
  uint32_t cnda; /* Next Descriptor Address */
  uint32_t cubc; /* Microblock Control */
  uint32_t cta;  /* Transfer Address */
};

struct chnext_view1_s
{
  uint32_t cnda; /* Next Descriptor Address */
  uint32_t cubc; /* Microblock Control */
  uint32_t csa;  /* Source Address */
  uint32_t cda;  /* Destination Address */
};

struct chnext_view2_s
{
  uint32_t cnda; /* Next Descriptor Address */
  uint32_t cubc; /* Microblock Control */
  uint32_t csa;  /* Source Address */
  uint32_t cda;  /* Destination Address */
  uint32_t cc;   /* Configuration Register */
};

struct chnext_view3_s
{
  uint32_t cnda; /* Next Descriptor Address */
  uint32_t cubc; /* Microblock Control */
  uint32_t csa;  /* Source Address */
  uint32_t cda;  /* Destination Address */
  uint32_t cc;   /* Configuration Register */
  uint32_t cbc;  /* Block Control */
  uint32_t cds;  /* Data Stride */
  uint32_t csus; /* Source Microblock Stride */
  uint32_t cdus; /* Destination Microblock Stride */
};

#endif /* __ARCH_ARM_SRC_SAMV7_HARDWARE_SAM_XDMAC_H */
