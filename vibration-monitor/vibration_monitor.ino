

mpu6050 mpu;

int led = 8;
int limit = 15000;

void setup() {
  serial.begin(9600);
  wire.begin();
  mpu.initialize();
  pinmode(led, output);
}

void loop() {
  int16_t x, y, z;


