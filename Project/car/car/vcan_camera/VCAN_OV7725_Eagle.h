#ifndef _VCAN_OV7725_EAGLE_H_
#define _VCAN_OV7725_EAGLE_H_

#include "VCAN_OV7725_REG.h"

#if ( USE_CAMERA == CAMERA_OV7725_EAGLE )
//配置摄像头的特性
#define CAMERA_USE_HREF     0               //是否使用 行中断 (0 为 不使用，1为使用)
#define CAMERA_COLOR        0               //摄像头输出颜色 ， 0 为 黑白二值化图像 ，1 为 灰度 图像 ，2 为 RGB565 图像
#define CAMERA_POWER        0               //摄像头 电源选择， 0 为 3.3V ,1 为 5V

//配置摄像头顶层接口
#define camera_init(imgaddr)    ov7725_eagle_init(imgaddr)
#define camera_get_img()        ov7725_eagle_get_img()

//#define camera_vsync()          ov7725_eagle_vsync()
//#define camera_href()           //ov7725_eagle_href()
#define camera_dma()            ov7725_eagle_dma()

//配置 摄像头 参数
#define CAMERA_DMA_CH       OV7725_EAGLE_DMA_CH         //定义摄像头的DMA采集通道
#define CAMERA_W            OV7725_EAGLE_W              //定义摄像头图像宽度
#define CAMERA_H            OV7725_EAGLE_H              //定义摄像头图像高度
#define W CAMERA_W
#define H CAMERA_H

#define white 255
#define black 0

#define CAMERA_SIZE         OV7725_EAGLE_SIZE           //图像占用空间大小
#define CAMERA_DMA_NUM      OV7725_EAGLE_DMA_NUM        //DMA采集次数

#endif  //#if ( USE_CAMERA == CAMERA_OV7725_EAGLE )


//配置摄像头 属性
#define OV7725_EAGLE_DMA_CH       HW_DMA_CH0                               //定义摄像头的DMA采集通道
#define OV7725_EAGLE_W            160                                    //定义摄像头图像宽度
#define OV7725_EAGLE_H            120                                    //定义摄像头图像高度
#define OV7725_EAGLE_SIZE         (OV7725_EAGLE_W * OV7725_EAGLE_H/8 )  //图像占用空间大小
#define OV7725_EAGLE_DMA_NUM      (OV7725_EAGLE_SIZE )                  //DMA采集次数


#define BOARD_OV7725_PCLK_PORT      HW_GPIOB
#define BOARD_OV7725_PCLK_PIN       (0)
#define BOARD_OV7725_VSYNC_PORT     HW_GPIOA
#define BOARD_OV7725_VSYNC_PIN      (15)
#define BOARD_OV7725_HREF_PORT      HW_GPIOC
#define BOARD_OV7725_HREF_PIN       (8)
#define BOARD_OV7725_DATA_PORT      HW_GPIOC

/*返回数组元素的个数*/  
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( ((a)[0]) ) ) 


extern  uint8_t   ov7725_eagle_init(uint8_t *imgaddr);
extern  void    ov7725_eagle_get_img(void);

extern  void    ov7725_eagle_vsync(uint32_t index);
extern  void    ov7725_eagle_dma(void);


#endif  //_VCAN_OV7725_EAGLE_H_


