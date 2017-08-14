#ifndef _MYUART_H_
#define _MYUART_H_

#include "common.h"
#include "dma.h"
#include "imageHandler.h"

#define UART_DataPortAddr (void*)&UART4->D
#define UART_SendDMATriggerSource UART4_TRAN_DMAREQ
#define UART_INSTANCE HW_UART3

#define my_uart UART3_RX_PC16_TX_PC17 
#define my_uart_instance HW_UART3 
#define my_baudrate 115200

class Uart{
public:
  Uart();
  void sendByte(uint8_t ch);
  void sendBytes(uint8_t * ch,uint16_t size);
  void addWare(uint16_t value,int chl);
  void sendWare();
  void sendImage(uint8_t * Image,int size);
private:
  uint16_t ware[8];
  uint8_t _instance;
};

static void UART_RX_ISR(uint16_t byteReceived);




#endif   //_MYUART_H_