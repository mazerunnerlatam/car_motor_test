// https://github.com/himanshus2847/Line-Follower-Robot-using-5-Channel-IR/blob/master/Line_follower_5_channel/Line_follower_5_channel.ino
// https://www.youtube.com/watch?v=1uM9K6CzXtI
//
// Original
// #define MOTOR_RIGHT_3 7  //Left Motor MB1
// #define MOTOR_RIGHT_4 5  //Left Motor MB2
// #define mle 6 //Left Motor Enable Pin EB
// #define MOTOR_LEFT_1 4  //Right Motor MA1
// #define MOTOR_LEFT_2 2  //Right Motor MA2
// #define MOTOR_LEFT_ENABLED 3  //Right Motor Enable Pin EA

// LMRIOS I change de motors Left is Right and Right is Left because all the logic was mixed
// motor B cable colors: orange(pin 3), yellow(pin 2), green(pin 4)
#define MOTOR_RIGHT_3 4  //Right Motor MB1
#define MOTOR_RIGHT_4 2  //Left Motor MB2
#define MOTOR_RIGHT_ENABLED 3 //Left Motor Enable Pin EB
// moto A cable colors: blue(pin 5), violet(pin 7), white(pin 6)
#define MOTOR_LEFT_1 7  //Right Motor MA1
#define MOTOR_LEFT_2 5  //Right Motor MA2
#define MOTOR_LEFT_ENABLED 6  //Right Motor Enable Pin EA

//*************************************************//

void setup() {
  pinMode(MOTOR_LEFT_1, OUTPUT);
  pinMode(MOTOR_LEFT_2, OUTPUT);
  pinMode(MOTOR_RIGHT_3, OUTPUT);
  pinMode(MOTOR_RIGHT_4, OUTPUT);
  pinMode(MOTOR_LEFT_ENABLED, OUTPUT);
  pinMode(MOTOR_RIGHT_ENABLED, OUTPUT);

  Serial.begin(9600); // open the serial port at 9600 bps:
  String msg="Car is about to start";
  Serial.println(msg);
  
  pinMode(LED_BUILTIN, OUTPUT);


  Serial.println("READY");
  delay(1500);


}
void loop() {
  int speed_fast = 255;
  int speed_slow = 86;    
    
  Serial.println("going forward with full speed ");

    motor_left_forward(speed_slow);
    motor_right_forward(speed_fast);
    delay(3000);
    motor_left_stop();  
    motor_right_stop();
    delay(3000);
    motor_left_forward(speed_fast);
    motor_right_forward(speed_slow);
    delay(3000);
    motor_left_stop();  
    motor_right_stop();
    delay(3000);
}

void motor_left_forward(int speed) {
  analogWrite(MOTOR_LEFT_ENABLED, speed);
  digitalWrite(MOTOR_LEFT_1, HIGH);
  digitalWrite(MOTOR_LEFT_2, LOW);
}

void motor_right_forward(int speed) {
  analogWrite(MOTOR_RIGHT_ENABLED, speed);
  digitalWrite(MOTOR_RIGHT_3, HIGH);
  digitalWrite(MOTOR_RIGHT_4, LOW);
}

void motor_left_stop() {
  analogWrite(MOTOR_LEFT_ENABLED, 0);
  digitalWrite(MOTOR_LEFT_1, LOW);
  digitalWrite(MOTOR_LEFT_2, LOW);
}

void motor_right_stop() {
  analogWrite(MOTOR_RIGHT_ENABLED, 0);
  digitalWrite(MOTOR_RIGHT_3, LOW);
  digitalWrite(MOTOR_RIGHT_4, LOW);
}
