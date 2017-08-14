/*hdr
**	FILE NAME:	MPU9150.h
**
**	AUTHOR:		Devlin Jia
**
**	DATE:		10-4-2015
**
**	FILE DESCRIPTION:
**				
**
**	FUNCTIONS:
**
**	NOTES:
**	
*/
#include "common.h"
#include "IIC.h"
#include "MPU9150.h"


#define MPU6050_WR(reg,value)         I2CwriteByte(MPU6050_ADDRESS,reg,value)  //MPU6050 写寄存器

int16_t G_X,G_Y,G_Z,A_X,A_Y,A_Z;

/*!
*  @brief      MPU9150_init
*  @since      v5.0
*  Sample usage:      MPU9150_init();  
*/

int MPU9150_init(void)
{
  I2C_init();
  int loop=10;
  while(loop--){
    while( 0 == I2CwriteByte(MPU6050_Addr,PWR_MGMT_1, 0x00)) 
    {
      //DEBUG_PRINTF("\n警告:I2C写数据错误");
      //return 0 ;
    }
    while( 0 ==   I2CwriteByte(MPU6050_Addr,SMPLRT_DIV, 0x07))
    {
      //DEBUG_PRINTF("\n警告:I2C写数据错误");
      //return 0 ;
    }
    while( 0 == I2CwriteByte(MPU6050_Addr,CONFIG, 0x06)) 
    {
      //DEBUG_PRINTF("\n警告:I2C写数据错误");
      //return 0 ;
    }
    while( 0 == I2CwriteByte(MPU6050_Addr,GYRO_CONFIG, 0x18)) 
    {
      //DEBUG_PRINTF("\n警告:I2C写数据错误");
      //return 0 ;
    }
    
    while( 0 == I2CwriteByte(MPU6050_Addr,ACCEL_CONFIG, 0x01)) 
    {
      //DEBUG_PRINTF("\n警告:I2C写数据错误");
      //return 0 ;
    }
  }
  return 1;
}

//int16_t MPU6050_GetDoubleData(uint8_t Addr)
//{
//  uint16_t MPU6050_data=0x0000;
//  uint8_t temp_data1 = 0x00;
//  uint8_t temp_data2 = 0x00;
// // MPU6050_RD( Addr,&temp_data1);
//  I2CreadByte(MPU6050_ADDRESS,Addr,&temp_data1); 
//  //MPU6050_data=(uint16_t)((MPU6050_data<<8)&0xff00);
//  //MPU6050_RD( Addr+1,&temp_data2);
//  I2CreadByte(MPU6050_ADDRESS,Addr,&temp_data2) ;
//  MPU6050_data = temp_data1 + temp_data2;
//  
//  return (int16_t)MPU6050_data;//合成数据，为有符号整形数
//}

//******?áè?MPU6050êy?Y****************************************

int16_t mpu6050_GYRO_X_data()
{
  uint8_t G_T_X1 = 0, G_T_X2 = 0;
  I2CreadByte(MPU6050_Addr,GYRO_XOUT_L,&G_T_X1);
  I2CreadByte(MPU6050_Addr,GYRO_XOUT_H,&G_T_X2);
  return (G_T_X2<<8)|G_T_X1;
}
int16_t mpu6050_GYRO_Y_data()
{
  uint8_t G_T_Y1 = 0, G_T_Y2 = 0;
  I2CreadByte(MPU6050_Addr,GYRO_YOUT_L,&G_T_Y1);
  I2CreadByte(MPU6050_Addr,GYRO_YOUT_H,&G_T_Y2);
  return(G_T_Y2<<8)|G_T_Y1;
}
int16_t mpu6050_GYRO_Z_data()
{
  uint8_t G_T_Z1 = 0, G_T_Z2 = 0;
  I2CreadByte(MPU6050_Addr,GYRO_ZOUT_L,&G_T_Z1) ;
  I2CreadByte(MPU6050_Addr,GYRO_ZOUT_H,&G_T_Z2) ;
  return(G_T_Z2<<8)|G_T_Z1; 
}
int16_t mpu6050_ACCEL_X_data()
{
  uint8_t A_T_X1 = 0, A_T_X2 = 0;
  I2CreadByte(MPU6050_Addr,ACCEL_XOUT_L,&A_T_X1) ;
  I2CreadByte(MPU6050_Addr,ACCEL_XOUT_H,&A_T_X2) ;
  return(A_T_X2<<8)|A_T_X1;

}
int16_t mpu6050_ACCEL_Y_data()
{
  uint8_t A_T_Y1 = 0, A_T_Y2 = 0;
  I2CreadByte(MPU6050_Addr,ACCEL_YOUT_L,&A_T_Y1) ;
  I2CreadByte(MPU6050_Addr,ACCEL_YOUT_H,&A_T_Y2) ;
  return(A_T_Y2<<8)|A_T_Y1;

}
int16_t mpu6050_ACCEL_Z_data()
{
  uint8_t A_T_Z1 = 0, A_T_Z2 = 0;
  I2CreadByte(MPU6050_Addr,ACCEL_ZOUT_L,&A_T_Z1) ;
  I2CreadByte(MPU6050_Addr,ACCEL_ZOUT_H,&A_T_Z2) ;
  return(A_T_Z2<<8)|A_T_Z1;
}

void READ_MPU6050(void)
{
  /*陀螺仪读数*/
 
  G_X =	-mpu6050_GYRO_X_data();
	
  G_Y = mpu6050_GYRO_Y_data();
  
  G_Z = mpu6050_GYRO_Z_data();
  
  /*加速度计读数*/
  
  A_Y = mpu6050_ACCEL_X_data(); 						   
  
  A_X = mpu6050_ACCEL_Y_data(); 
  
  A_Z = mpu6050_ACCEL_Z_data(); 
}

