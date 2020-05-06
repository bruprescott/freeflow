/* cpu.h */

#ifndef _DEF_INC_CPU
#define _DEF_INC_CPU

#include <stdint.h>

#define CLOCK_RATE_MHZ  80
#define CLOCK_RATE      (CLOCK_RATE_MHZ * 1000000)

// Flash memory start/size
#define FLASH_START        0x08000000
#define FLASH_SIZE         0x00020000
#define FLASH_PAGE_LEN     0x00000800

#define MAIN_FW_START      0x08004000
#define MAIN_FW_END        0x08018000

// Interrupt vectors.  These are the offset of the interrupt in the 
// vector table divided by 4
// The interrupt vector table can be found in the reference manual 
// in the section on the NVIC (12)
#define INT_VECT_DMA1_6    0x80/4
#define INT_VECT_TMR15     0xA0/4
#define INT_VECT_TMR16     0xA4/4
#define INT_VECT_SPI1      0xCC/4
#define INT_VECT_UART1     0xD4/4
#define INT_VECT_I2C1      0xBC/4

typedef volatile uint64_t LREG;
typedef volatile uint32_t REG;
typedef volatile uint16_t SREG;
typedef volatile uint8_t  BREG;

// Reset & clock controller
#define RCC_BASE                    0x40021000
typedef struct
{
   REG clkCtrl;                  // 0x00 clock control register (RCC_CR)
   REG clkCal;                   // 0x04 Internal clock sources calibration register (RCC_ICSCR)
   REG clkCfg;                   // 0x08 clock configuration register (RCC_CFGR)
   REG pllCfg;                   // 0x0C PLL configuration register (RCC_PLLCFGR)
   REG pllSaiCfg;                // 0x10 PLLSAI1 configuration register (RCC_PLLSAI1CFGR)
   REG rsvd1;
   REG clkIntEna;                // 0x18 Clock interrupt enable register ( RCC_CIER) 
   REG clkIntFlg;                // 0x1C Clock interrupt flag register ( RCC_CIFR)
   REG clkIntClr;                // 0x20 Clock interrupt clear register ( RCC_CICR)
   REG rsvd2;
   REG periphReset[8];           // 0x28 peripheral reset registers
   REG periphClkEna[8];          // 0x48 peripheral clock registers
   REG sleepClkEna[8];           // 0x68 Clock enable in sleep
   REG indClkCfg;                // 0x88 Peripherals independent clock configuration register (RCC_CCIPR)
   REG rsvd3;
   REG backup;                   // 0x90 Backup domain control register (RCC_BDCR)
   REG status;                   // 0x94 control & status register (RCC_CSR)
   REG recovery;                 // 0x98 Clock recovery RC register (RCC_CRRCR)
   REG indClkCfg2;               // 0x9C Peripherals independent clock configuration register (RCC_CCIPR2)
} RCC_Regs;

// Clock recovery system
#define CRS_BASE                    0x40006000
typedef struct
{
   REG ctrl;
   REG config;
   REG status;
   REG intClr;
} CRS_Regs;

// Interrupt controller
#define NVIC_BASE                   0xE000E100
typedef struct
{
   REG  setEna[32];
   REG  clrEna[32];
   REG  setPend[32];
   REG  clrPend[32];
   REG  active[64];
   BREG priority[1024];
} IntCtrl_Regs;

// System control registers
#define SYSCTL_BASE                 0xE000E000
typedef struct
{
   REG rsvd0;                    // 0xE000E000
   REG intType;                  // 0xE000E004
   REG auxCtrl;                  // 0xE000E008
   REG rsvd1;                    // 0xE000E00C
   REG systick[3];               // 0xE000E010
   REG rsvd2[57];
   REG nvic[768];                // 0xE000E100
   REG cpuid;                    // 0xE000ED00
   REG intCtrl;                  // 0xE000ED04
   REG vtable;                   // 0xE000ED08
   REG apInt;                    // 0xE000ED0C
   REG sysCtrl;                  // 0xE000ED10
   REG cfgCtrl;                  // 0xE000ED14
   REG sysPri[3];                // 0xE000ED18
   REG sysHdnCtrl;               // 0xE000ED24
   REG faultStat;                // 0xE000ED28
   REG hardFaultStat;            // 0xE000ED2C
   REG rsvd3;
   REG mmFaultAddr;              // 0xE000ED34
   REG faultAddr;                // 0xE000ED38
   REG rsvd4[19];
   REG cpac;                     // 0xE000ED88
} SysCtrl_Reg;

// Power controller
#define POWER_BASE                  0x40007000
typedef struct
{
   REG ctrl[4];
   REG status[2];
   REG statClr;
   struct
   {
      REG up;
      REG dn;
   } pull[6];
} PwrCtrl_Reg;

// Digital I/O
#define DIGIO_A_BASE                0x48000000
#define DIGIO_B_BASE                0x48000400
#define DIGIO_C_BASE                0x48000800
typedef struct
{
   REG  mode;
   REG  outType;
   REG  outSpeed;
   REG  pullUpDn;
   REG  inDat;
   REG  outDat;
   SREG set;
   SREG clr;
   REG  lock;
   REG  alt[2];
   REG  reset;
} GPIO_Regs;

#define UART1_BASE                  0x40013800
#define UART2_BASE                  0x40004400
#define UART3_BASE                  0x40004800
#define UART4_BASE                  0x40004C00
typedef struct
{
   REG ctrl[3];
   REG baud;
   REG guard;
   REG timeout;
   REG request;
   REG status;
   REG intClear;
   REG rxDat;
   REG txDat;
} UART_Regs;

#define ADC_BASE                   0X50040000
typedef struct
{
   // A/D specific registers (0x100 total length)
   struct
   {
      REG stat;                  // 0x00 - interrupt and status register (ADC_ISR)
      REG intEna;                // 0x04 - interrupt enable register (ADC_IER)
      REG ctrl;                  // 0x08 - control register (ADC_CR)
      REG cfg[2];                // 0x0C - configuration registers
      REG samp[2];               // 0x14 - sampling time registers
      REG rsvd1;
      REG wdog[3];               // 0x20 - watchdog threshold registers
      REG rsvd2;
      REG seq[4];                // 0x30 - Regular sequence registers
      REG data;                  // 0x40 - Regular data register
      REG rsvd3[2];
      REG iSeq;                  // 0x4C - Injected sequence regiseter
      REG rsvd4[4];
      REG offset[4];             // 0x60 - Offset registers
      REG rsvd5[4];
      REG iData[4];              // 0x80 - Injected channel data
      REG rsvd6[4];
      REG wdCfg[2];              // 0xA0 - Watchdog config
      REG rsvd7[2];
      REG diffSel;               // 0xB0 - Differential mode selection
      REG cal;                   // 0xB4 - Calibration factors
      REG rsvd8[18];
   } adc[2];

   // A/D common registers
   REG comStat;                  // 0x300 - Common status
   REG rsvd9;
   REG comCtrl;                  // 0x304 - Common control
   REG comData;                  // 0x308 - Common data
} ADC_Regs;

#define OPAMP_BASE                  0X40007800
typedef struct
{
   REG ctr;                     // 0x00 - Control / status
   REG trim;                    // 0x04 - Offset trim (normal mode)
   REG trimLP;                  // 0x08 - Offset trim (low power mode)
} OpAmpRegs;

#define TIMER1_BASE                 0x40012C00
#define TIMER2_BASE                 0x40000000
#define TIMER3_BASE                 0x40000400
#define TIMER6_BASE                 0x40001000
#define TIMER7_BASE                 0x40001400
#define TIMER15_BASE                0x40014000
#define TIMER16_BASE                0x40014400
typedef struct
{
   REG ctrl[2];
   REG slaveCtrl;
   REG intEna;
   REG status;
   REG event;
   REG ccMode[2];
   REG ccEnable;
   REG counter;
   REG prescale;
   REG reload;
   REG repeat;
   REG compare[4];
   REG deadTime;
   REG dmaCtrl;
   REG dmaAddr;
   REG opt1;
   REG ccMode3;
   REG compare5;
   REG compare6;
   REG opt2;
   REG opt3;
} TimerRegs;

#define FLASH_BASE                 0x40022000
typedef struct
{
   REG access;
   REG pdKey;
   REG key;
   REG optKey;
   REG status;
   REG ctrl;
   REG ecc;
   REG rsvd1;
   REG option;
   REG pcropStart;
   REG pcropEnd;
   REG wrpA;
   REG wrpB;
} FlashReg;

#define DMA1_BASE                  0x40020000
#define DMA2_BASE                  0x40020400
typedef struct
{
   REG intStat;
   REG intClr;
   struct
   {
      REG config;
      REG count;
      REG pAddr;
      REG mAddr;
      REG rsvd;
   } channel[7];
   REG rsvd[5];
   REG chanSel;
} DMA_Reg;

#define SPI1_BASE                  0x40013000
#define SPI2_BASE                  0x40003800
#define SPI3_BASE                  0x40003C00
typedef struct
{
   REG ctrl[2];
   REG status;
   REG data;
   REG crcPoly;
   REG rxCRC;
   REG txCRC;
} SPI_Regs;

#define I2C1_BASE                  0x40005400
#define I2C2_BASE                  0x40005800
#define I2C3_BASE                  0x40005c00
#define I2C4_BASE                  0x40008400
typedef struct
{
   REG ctrl[2];
   REG addr[2];
   REG timing;
   REG timeout;
   REG status;
   REG intClr;
   REG pec;
   REG rxData;
   REG txData;
} I2C_Regs;

#define CRC_BASE                   0x40023000
typedef struct
{
   REG data;
   REG scratch;
   REG ctrl;
   REG rsvd;
   REG init;
   REG poly;
} CRC_Regs;

#define USBFS_BASE                 0x40006800
typedef struct
{
   REG endpoint[8];                // 0x00 - USB endpoint n register (USB_EPnR)
   REG rsvd[8];
   REG ctrl;                       // 0x40 - USB control register (USB_CNTR)
   REG status;                     // 0x44 - USB interrupt status register (USB_ISTR)
   REG frame;                      // 0x48 - USB frame number register (USB_FNR)
   REG addr;                       // 0x4C - USB device address (USB_DADDR)
   REG btable;                     // 0x50 - Buffer table address (USB_BTABLE)
   REG lpm;                        // 0x54 - LPM control and status register (USB_LPMCSR)
   REG battery;                    // 0x58 - Battery charging detector (USB_BCDR)
} USB_Regs;

#define USB_SRAM_BASE              0x40006C00
typedef struct
{
   SREG txAddr;                    // 0x00 - Transmission buffer address n (USB_ADDRn_TX)
   SREG txCount;                   // 0x02 - Transmission byte count n (USB_COUNTn_TX)
   SREG rxAddr;                    // 0x04 - Reception buffer address n (USB_ADDRn_RX)
   SREG rxCount;                   // 0x06 - Reception byte count n (USB_COUNTn_RX)
} USB_TblEntry;

// inline functions
#define GPIO_MODE_INPUT    0
#define GPIO_MODE_OUTPUT   1
#define GPIO_MODE_ALT      2
#define GPIO_MODE_ANALOG   3
static inline void GPIO_PinMode( uint32_t bank, int pin, int mode )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;
   gpio->mode &= ~(3 << (pin*2));
   gpio->mode |= (mode << (pin*2));
}

#define GPIO_OUTTYPE_PUSHPULL   0
#define GPIO_OUTTYPE_OPENDRIAN  1
static inline void GPIO_OutType( uint32_t bank, int pin, int drain )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;
   if( drain )
      gpio->outType |=   1<<pin;
   else
      gpio->outType &= ~(1<<pin);
}

static inline void GPIO_PinAltFunc( uint32_t bank, int pin, int func )
{
   GPIO_PinMode( bank, pin, GPIO_MODE_ALT );

   GPIO_Regs *gpio = (GPIO_Regs *)bank;
   int x = (pin<8) ? 0 : 1;
   gpio->alt[x] |= (func << ((pin&7)*4));
}

static inline void GPIO_SetPin( uint32_t bank, int pin )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;
   gpio->set = (1<<pin);
}

static inline void GPIO_ClrPin( uint32_t bank, int pin )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;
   gpio->clr = (1<<pin);
}

static inline int GPIO_GetPin( uint32_t bank, int pin )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;
   return (gpio->inDat & (1<<pin)) ? 1 : 0;
}

static inline void GPIO_TglPin( uint32_t bank, int pin )
{
   if( GPIO_GetPin( bank, pin ) )
      GPIO_ClrPin( bank, pin );
   else
      GPIO_SetPin( bank, pin );
}

static inline void GPIO_Output( uint32_t bank, int pin, int state )
{
   if( state ) GPIO_SetPin( bank, pin );
   else        GPIO_ClrPin( bank, pin );
   GPIO_PinMode( bank, pin, GPIO_MODE_OUTPUT );
   GPIO_OutType( bank, pin, GPIO_OUTTYPE_PUSHPULL );
}

static inline void GPIO_PullUp( uint32_t bank, int pin )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;

   uint32_t x = gpio->pullUpDn & ~(3<<(2*pin));
   x |= 1 << (2*pin);
   gpio->pullUpDn = x;
}

static inline void GPIO_PullDn( uint32_t bank, int pin )
{
   GPIO_Regs *gpio = (GPIO_Regs *)bank;

   uint32_t x = gpio->pullUpDn & ~(3<<(2*pin));
   x |= 2 << (2*pin);
   gpio->pullUpDn = x;
}


// Prototypes
void CPU_Init( void );
void EnableInterrupt( int id, int pri );
void Reset( void );
void SwapMode( void );
int CheckSwap( void );

#endif
