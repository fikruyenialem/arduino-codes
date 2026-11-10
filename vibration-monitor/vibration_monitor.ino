



void setup() {
  serial.begin(9600);
  wire.begin();
  mpu.initialize();
  pinmode(led, output);
}

void loop() {
  int16_t x, y, z;


  mpu.getacceleration(&x, &y, &z);

  int vibration = abs(x) + abs(y) + abs(z - 16384);

  serial.println(vibration);

  if (vibration > limit) {
    digitalwrite(led, high);
    serial.println("vibration detected");
  } else {
    digitalwrite(led, low);
  }

  delay(100);
}
