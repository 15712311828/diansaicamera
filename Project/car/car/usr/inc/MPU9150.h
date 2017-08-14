/*hdr
**
**
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

#ifndef _MPU9150_H_
#define _MPU9150_H_


// ?����?MPU6050?��2?��??��
//****************************************
#define	SMPLRT_DIV		0x19	//����?Y��?2��?��?����?��?D��?�̡�o0x07(125Hz)
#define	CONFIG			0x1A	//�̨�����??2��?��?����?��?D��?�̡�o0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//����?Y��?��??��?��2a��?��??���?��?D��?�̡�o0x18(2?��??����?2000deg/s)
#define	ACCEL_CONFIG	0x1C	//?��?��??��??��?��2a��?��??��?��??����??2��?��?����?��?D��?�̡�o0x01(2?��??����?2G��?5Hz)
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42

#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48

#define	PWR_MGMT_1		0x6B	//��??��1��������?��?D��?�̡�o0x00(?y3��??��?)
#define	WHO_AM_I		0x75	//IIC��??��??��??��(??��?��y?��0x68��????��)


//****************************
 
#define	MPU6050_Addr   0xD0	  //?����??��?t?��IIC����???D��?�䨮��??��,?��?YALT  ADDRESS��??����y??2?��?DT??
extern int MPU9150_init(void);
extern unsigned char TX_DATA[4];  	 //??��??Y?o��???				 //IIC��?��?
extern int16_t G_X,G_Y,G_Z,A_X,A_Y,A_Z;		 //X,Y,Z?����????��
extern void READ_MPU6050(void);
extern int16_t mpu6050_ACCEL_X_data();
extern int16_t mpu6050_ACCEL_Y_data();
extern int16_t mpu6050_ACCEL_Z_data();

extern int16_t mpu6050_GYRO_X_data();
extern int16_t mpu6050_GYRO_Y_data();
extern int16_t mpu6050_GYRO_Z_data();


#endif  