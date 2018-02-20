// GY-80 IMU Library especially written for use with Teensy 3.6
// Code written by Marcelo Maro�as @ Minerva Rockets (Federal University of Rio de Janeiro Rocketry Team) - February 19, 2018
// Using Adafruit Libraries.
// Contact : marcelomaronas at poli.ufrj.br
// For more codes : github.com/engmaronas

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_ADXL345_U.h>
#include <L3G.h>
#include <Adafruit_HMC5883_U.h>

typedef struct 
{
  double acelerometro[3]; //Posi��es 1,2,3, respectivamente s�o as Acelera��es em x,y,z
  int magnetometro[3]; //Posi��es 1,2,3, respectivamente s�o as Campos Magn�ticos em x,y,z
  int giroscopio[3]; //Posi��es 1, 2, 3, respectivamente s�o a velocidade angular em x,y,z
  double barometro[3]; //Posi��es 1,2,3 respectivamente s�o Pressao, Altura e Temperatura
}IMU_s; //IMU Structure

//Functions headers
int GetGyro(IMU_s *imu);

int GetAcel(IMU_s *imu);

int GetMag(IMU_s *imu);

int GetBMP(IMU_s *imu);

void InitAcel();

void InitGyro();

void InitMag();

void InitBMP();

//Functions headers