// GY-80 IMU Library especially written for use with Teensy 3.6
// Code written by Marcelo Maroñas @ Minerva Rockets (Federal University of Rio de Janeiro Rocketry Team) - February 19, 2018
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
  double acelerometro[3]; //Posições 1,2,3, respectivamente são as Acelerações em x,y,z
  int magnetometro[3]; //Posições 1,2,3, respectivamente são as Campos Magnéticos em x,y,z
  int giroscopio[3]; //Posições 1, 2, 3, respectivamente são a velocidade angular em x,y,z
  double barometro[3]; //Posições 1,2,3 respectivamente são Pressao, Altura e Temperatura
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