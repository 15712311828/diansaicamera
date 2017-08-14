#include "angleCal.h"
#include "MPU9150.h"

float angleX=0;
float angleY=0;
float angle_dot_x=0,angle_dot_y=0;//角度和角速度
float PX[2][2] = {{ 1, 0 },
  { 0, 1 }};
float PY[2][2] = {{ 1, 0 },
  { 0, 1 }};
float PdotX[4] ={ 0,0,0,0};
float PdotY[4] ={ 0,0,0,0};
float Q_angle_x=200, Q_gyro_x=0.005; //角度数据置信度,角速度数据置信度
float R_angle_x=300 ,C_0_x = 1; 
//float Q_angle_x=0.0001, Q_gyro_x=0.5; 
//float R_angle_x=0.05 ,C_0_x = 1; 
float Q_angle_y=200, Q_gyro_y=0.005; //角度数据置信度,角速度数据置信度
float R_angle_y=300 ,C_0_y = 1; 
float q_bias_x, angle_err_x, PCt_0_x, PCt_1_x, E_x, K_0_x, K_1_x, t_0_x, t_1_x;
float q_bias_y, angle_err_y, PCt_0_y, PCt_1_y, E_y, K_0_y, K_1_y, t_0_y, t_1_y;
float dt=0.005;

void angleCal(){
  float G_X_S=(float)G_X/18;
  float G_Y_S=(float)G_Y/18;

  angleX+=(G_X_S-q_bias_x) ;//* dt;
  angle_err_x = A_X - angleX;
  PdotX[0]=Q_angle_x - PX[0][1] - PX[1][0];
  PdotX[1]=- PX[1][1];
  PdotX[2]=- PX[1][1];
  PdotX[3]=Q_gyro_x;
  PX[0][0] += PdotX[0] * dt;
  PX[0][1] += PdotX[1] * dt;
  PX[1][0] += PdotX[2] * dt;
  PX[1][1] += PdotX[3] * dt;
  PCt_0_x = C_0_x * PX[0][0];
  PCt_1_x = C_0_x * PX[1][0];
  E_x = R_angle_x + C_0_x * PCt_0_x;
  K_0_x = PCt_0_x / E_x;
  K_1_x = PCt_1_x / E_x;
  t_0_x = PCt_0_x;
  t_1_x = C_0_x * PX[0][1];
  PX[0][0] -= K_0_x * t_0_x;
  PX[0][1] -= K_0_x * t_1_x;
  PX[1][0] -= K_1_x * t_0_x;
  PX[1][1] -= K_1_x * t_1_x;
  angleX += K_0_x * angle_err_x; //最优角度
  q_bias_x += K_1_x * angle_err_x;
  angle_dot_x = G_X_S-q_bias_x;//最优角速度
  
  angleY+=(G_Y_S-q_bias_y) ;//* dt;
  angle_err_y = A_Y - angleY;
  PdotY[0]=Q_angle_y - PY[0][1] - PY[1][0];
  PdotY[1]=- PY[1][1];
  PdotY[2]=- PY[1][1];
  PdotY[3]=Q_gyro_y;
  PY[0][0] += PdotY[0] * dt;
  PY[0][1] += PdotY[1] * dt;
  PY[1][0] += PdotY[2] * dt;
  PY[1][1] += PdotY[3] * dt;
  PCt_0_y = C_0_y * PY[0][0];
  PCt_1_y = C_0_y * PY[1][0];
  E_y = R_angle_y + C_0_y * PCt_0_y;
  K_0_y = PCt_0_y / E_y;
  K_1_y = PCt_1_y / E_y;
  t_0_y = PCt_0_y;
  t_1_y = C_0_y * PY[0][1];
  PY[0][0] -= K_0_y * t_0_y;
  PY[0][1] -= K_0_y * t_1_y;
  PY[1][0] -= K_1_y * t_0_y;
  PY[1][1] -= K_1_y * t_1_y;
  angleY += K_0_y * angle_err_y; //最优角度
  q_bias_y += K_1_y * angle_err_y;
  angle_dot_y = G_Y_S-q_bias_y;//最优角速度
  
}