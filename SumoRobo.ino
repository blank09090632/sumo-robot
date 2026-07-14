// L298N
#define ENA 5
#define IN1 8
#define IN2 9
#define ENB 6
#define IN3 10
#define IN4 11

// HC-SR04
#define TRIG 12
#define ECHO 13

// TCRT5000
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1

//----------------------------

int speedAttack = 255;
int speedSearch = 180;

int lineThreshold = 500;

long duration;
float distance;

//============================
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  Serial.begin(9600);
}

//============================
void loop()
{
  int leftValue = analogRead(LEFT_SENSOR);
  int rightValue = analogRead(RIGHT_SENSOR);

  
  if (leftValue > lineThreshold || rightValue > lineThreshold)
  {
    avoidLine(leftValue, rightValue);
    return;
  }

  distance = getDistance();

  Serial.println(distance);

  
  if (distance > 0 && distance < 50)
  {
    forward(speedAttack);
  }
  else
  {
    searchEnemy();
  }

  delay(20);
}

//============================
float getDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH, 30000);

  if(duration == 0)
    return 999;

  return duration * 0.0343 / 2;
}

//============================
void forward(int spd)
{
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//============================
void backward(int spd)
{
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//============================
void left(int spd)
{
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

//============================
void right(int spd)
{
  analogWrite(ENA, spd);
  analogWrite(ENB, spd);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

//============================
void stopMotor()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

//============================
void searchEnemy()
{
  
  left(speedSearch);
}

//============================
void avoidLine(int leftValue, int rightValue)
{
  
  backward(220);
  delay(300);

  
  if(leftValue > lineThreshold)
  {
    right(220);
    delay(350);
  }

  
  else if(rightValue > lineThreshold)
  {
    left(220);
    delay(350);
  }

  
  else
  {
    right(220);
    delay(450);
  }

  stopMotor();
}
