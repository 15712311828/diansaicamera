#include "myUart.h"
#include "uart.h"
#include "string.h"
#include "common.h"


Uart::Uart(){
  DelayInit();
  
  _instance = UART_QuickInit(my_uart , my_baudrate);
  UART_CallbackRxInstall(my_uart_instance, UART_RX_ISR);
  UART_ITDMAConfig(my_uart_instance, kUART_IT_Rx, true);
 

  /*
  UART_ITDMAConfig(UART_INSTANCE, kUART_DMA_Tx, true);
  
  DMA_InitTypeDef DMA_InitStruct1 = {0};
  DMA_InitStruct1.chl = HW_DMA_CH1;
  DMA_InitStruct1.chlTriggerSource = UART_SendDMATriggerSource;
  DMA_InitStruct1.triggerSourceMode = kDMA_TriggerSource_Normal;
  DMA_InitStruct1.minorLoopByteCnt = 1;
  DMA_InitStruct1.majorLoopCnt = 0;
    
  DMA_InitStruct1.sAddr = NULL;
  DMA_InitStruct1.sLastAddrAdj = 0; 
  DMA_InitStruct1.sAddrOffset = 1;
  DMA_InitStruct1.sDataWidth = kDMA_DataWidthBit_8;
  DMA_InitStruct1.sMod = kDMA_ModuloDisable;
    
  DMA_InitStruct1.dAddr = (uint32_t)UART_DataPortAddr; 
  DMA_InitStruct1.dLastAddrAdj = 0;
  DMA_InitStruct1.dAddrOffset = 0;
  DMA_InitStruct1.dDataWidth = kDMA_DataWidthBit_8;
  DMA_InitStruct1.dMod = kDMA_ModuloDisable;
  DMA_Init(&DMA_InitStruct1);
  */
}

void Uart::sendByte(uint8_t ch){
  UART_WriteByte(_instance,  ch);
}

void Uart::sendBytes(uint8_t * ch,uint16_t size){
  for(int i=0;i<size;i++){
    sendByte(ch[i]);
  }
}

void Uart::addWare(uint16_t value,int chl){
  ware[chl]=value;
}

void Uart::sendImage(uint8_t * Image,int size){
#define CMD_IMAGE 1
  uint8_t cmdf[2] = {CMD_IMAGE, ~CMD_IMAGE};
  uint8_t cmdr[2] = {~CMD_IMAGE, CMD_IMAGE};
  sendBytes(cmdf,2);
  sendBytes(Image,size);
  sendBytes(cmdr,2);
}

void Uart::sendWare(){
#define CMD_WARE     3
  uint8_t cmdf[2] = {CMD_WARE, ~CMD_WARE};
  uint8_t cmdr[2] = {~CMD_WARE, CMD_WARE};
  sendBytes(cmdf,2);
  sendBytes((uint8_t *)ware,16);
  sendBytes(cmdr,2);
}

void UART_RX_ISR(uint16_t byteReceived){
  static uint16_t buff[7];
  static int pos=0;
  static int available=0;
  buff[pos]=byteReceived;
  pos++;
  if(pos>=7)
    pos=0;
  if(byteReceived=='\n'&&available!=6){
    available=0;
  }
  else if(byteReceived=='\n'&&available==6){
    available=0;
    int x=0;
    int y=0;
    for(int i=0;i<3;i++){
      if(buff[(i+pos)%7]>9)
        return;
      x=10*x+buff[(i+pos)%7];
    }
    for(int i=0;i<3;i++){
      if(buff[(i+pos+3)%7]>9)
        return;
      y=10*y+buff[(i+pos+3)%7];
    }
    ball=Point(x,y);
  }
  else{
    available++;
  }
}