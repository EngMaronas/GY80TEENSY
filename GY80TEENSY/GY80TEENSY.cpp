// GY-80 IMU Library especially written for use with Teensy 3.6
// Code written by Marcelo Maroñas @ Minerva Rockets (Federal University of Rio de Janeiro Rocketry Team) - February 19, 2018
// Using Adafruit Libraries.
// Contact : marcelomaronas at poli.ufrj.br
// For more codes : github.com/engmaronas

#include <GY80TEENSY.h>

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12346);
L3G gyro;

int GetGyro(IMU_s *imu) {
  gyro.read();

  imu->giroscopio[0] = gyro.g.x;
  imu->giroscopio[1] = gyro.g.y;
  imu->giroscopio[2] = gyro.g.z;
  return 0;
}

int GetAcel(IMU_s *imu) {
  sensors_event_t event; 
  accel.getEvent(&event);

  imu->acelerometro[0] = event.acceleration.x;
  imu->acelerometro[1] = event.acceleration.y;
  imu->acelerometro[2] = event.acceleration.z;
  return 0;
}

int GetMag(IMU_s *imu) {
  sensors_event_t event; 
  mag.getEvent(&event);

  imu->magnetometro[0] = event.magnetic.x;
  imu->magnetometro[1] = event.magnetic.y;
  imu->magnetometro[2] = event.magnetic.z;
  return 0;
}

int GetBMP(IMU_s *imu) {
  sensors_event_t event;
  float temperature;
  float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;

  
  bmp.getEvent(&event);
  bmp.getTemperature(&temperature);

  imu->barometro[0] = event.pressure;
  imu->barometro[1] = bmp.pressureToAltitude(seaLevelPressure, event.pressure);
  imu->barometro[2] = temperature; 
  return 0;
}

void InitAcel() {
  //ADXL45 SETUP
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL345_RANGE_16_G);
  //ADXL45 SETUP END
}

void InitGyro() {
 //L2G4200D Setup
   if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
  //L2G4200D Setup End
}

void InitMag() {
//HMC5884 Setup
   /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while(1);
  }
  //HMC5883 Setup end
}

void InitBMP() {
if(!bmp.begin())
  {
    /* There was a problem detecting the BMP085 ... check your connections */
    Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  //BMP085 SETUP END
}
