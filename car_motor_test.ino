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
// #define MOTOR_RIGHT_3 4  //Right Motor MB1
// #define MOTOR_RIGHT_4 2  //Left Motor MB2
// #define MOTOR_RIGHT_ENABLED 3 //Left Motor Enable Pin EB
// // moto A cable colors: blue(pin 5), violet(pin 7), white(pin 6)
// #define MOTOR_LEFT_1 7  //Right Motor MA1
// #define MOTOR_LEFT_2 5  //Right Motor MA2
// #define MOTOR_LEFT_ENABLED 6  //Right Motor Enable Pin EA

// LMRIOS ArduinoMega Config
// motor A cable colors: grey(pin 2), violet(pin 24), blue(pin 25)
#define MOTOR_LEFT_1 24  //Left Motor IN1
#define MOTOR_LEFT_2 25  //Left Motor IN2
#define MOTOR_LEFT_ENABLED 2  //Left Motor ENA
// motor B cable colors: green(pin 26), yellow(pin 27), orange(pin 3)
#define MOTOR_RIGHT_3 26  //Right Motor IN1
#define MOTOR_RIGHT_4 27  //Right Motor IN2
#define MOTOR_RIGHT_ENABLED 3 //Left Motor ENB




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

  averiguar_vel_minima();
  /*
  22:27:30.868 -> going forward: LEFT slow: 128 - RIGHT slow: 128
  22:27:33.871 -> Stop
  22:27:34.874 -> going forward: LEFT slow: 120 - RIGHT slow: 120
  22:27:37.912 -> Stop
  22:27:38.872 -> going forward: LEFT slow: 112 - RIGHT slow: 112
  22:27:41.916 -> Stop
  22:27:42.885 -> going forward: LEFT slow: 104 - RIGHT slow: 104
  22:27:45.919 -> Stop
  22:27:46.893 -> going forward: LEFT slow: 96 - RIGHT slow: 96
  22:27:49.883 -> Stop
  22:27:50.883 -> going forward: LEFT slow: 88 - RIGHT slow: 88
  22:27:53.908 -> Stop
  22:27:54.906 -> going forward: LEFT slow: 80 - RIGHT slow: 80 - fue el minimo que registre para ambos motores
  22:27:57.905 -> Stop
  22:27:58.893 -> going forward: LEFT slow: 72 - RIGHT slow: 72 - Solo se movia Motor Izquierdo
  22:28:01.884 -> Stop
  */
  while(1)
  {
  Serial.println("While LOOP 1...");
  delay(15000);
  }  
  check_motor_connections_speed();
}

void averiguar_vel_minima() {
  //int speed_slow = 128;    
  int speed_slow = 88;    
  
  int cantidad_de_repeticiones = 10;
  int valor_minimo = 50;
  for (int i = 0; i < cantidad_de_repeticiones; i++) {
    Serial.print("going forward: LEFT slow: ");
    Serial.print(speed_slow);
    Serial.print(" - RIGHT slow: ");
    Serial.println(speed_slow);
    motor_left_forward(speed_slow);
    motor_right_forward(speed_slow);
    delay(3000);
    Serial.println("Stop");
    motor_left_stop();  
    motor_right_stop();
    delay(1000);
    
    speed_slow -= 8; // Decrementa speed_slow en 8
    
    // Opcional: puedes agregar una condición para evitar que speed_slow sea menor que un valor mínimo
    if (speed_slow < valor_minimo) {
      speed_slow = valor_minimo;
    }
  }
}

void check_motor_connections_speed() {
  int speed_slow = 128;    
  int speed_fast =  speed_slow + 32;

  Serial.print("going forward: LEFT slow: ");
  Serial.print(speed_slow);
  Serial.print(" - RIGHT fast: ");
  Serial.println(speed_fast);

    motor_left_forward(speed_slow);
    motor_right_forward(speed_fast);
    delay(3000);
  Serial.println("Stop");
    motor_left_stop();  
    motor_right_stop();
    delay(1000);
  
    
  Serial.print("going forward: LEFT fast: ");
  Serial.print(speed_fast);
  Serial.print(" - RIGHT slow: ");
  Serial.println(speed_slow);
  
    motor_left_forward(speed_fast);
    motor_right_forward(speed_slow);
    delay(3000);
  Serial.println("Stop");
    motor_left_stop();  
    motor_right_stop();
    delay(1000);
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
