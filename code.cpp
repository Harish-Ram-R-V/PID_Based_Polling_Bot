// Pins
#define ENA 9
#define ENB 10
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 11

// Motor A encoder channel A
#define ENCA1 2    
// Motor A encoder channel B
#define ENCA2 3    
// Motor B encoder channel A
#define ENCB1 4    
// Motor B encoder channel B
#define ENCB2 5    

volatile long int posA = 0;
volatile long int posB = 0;

int lastStateA = LOW;
int lastStateB = LOW;

long int targetA = 500;
long int targetB = 500;

// PID variables
float kp = 1.5, ki = 0, kd = 0.5;
float prevErrorA = 0, prevErrorB = 0;
float integralA = 0, integralB = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);

  pinMode(ENCA1, INPUT); pinMode(ENCA2, INPUT);
  pinMode(ENCB1, INPUT); pinMode(ENCB2, INPUT);

  lastStateA = digitalRead(ENCA1);
  lastStateB = digitalRead(ENCB1);
}

void loop()
{
  updateEncoderA();
  updateEncoderB();

  float errorA = targetA - posA;
  float errorB = targetB - posB;

  integralA += errorA;
  integralB += errorB;

  float derivativeA = errorA - prevErrorA;
  float derivativeB = errorB - prevErrorB;

  float outputA = kp * errorA + ki * integralA + kd * derivativeA;
  float outputB = kp * errorB + ki * integralB + kd * derivativeB;

  prevErrorA = errorA;
  prevErrorB = errorB;

  moveMotor(outputA, outputB);

  Serial.print("Pos A: "); Serial.print(posA);
  Serial.print(" | Pos B: "); Serial.println(posB);

  delay(10);
}

void updateEncoderA()
{
  int A = digitalRead(ENCA1);
  int B = digitalRead(ENCA2);

  if (A != lastStateA) {
    if (A == B)
      posA++;
    else
      posA--;
    lastStateA = A;
  }
}

void updateEncoderB()
{
  int A = digitalRead(ENCB1);
  int B = digitalRead(ENCB2);

  if (A != lastStateB) {
    if (A == B)
      posB++;
    else
      posB--;
    lastStateB = A;
  }
}

void moveMotor(float speedA, float speedB)
{
  setMotor(ENA, IN1, IN2, speedA);
  setMotor(ENB, IN3, IN4, speedB);
}

void setMotor(int en, int in1, int in2, float speed)
{
  bool dir = speed >= 0;
  int pwm = constrain(abs(speed), 0, 255);
  digitalWrite(in1, dir);
  digitalWrite(in2, !dir);
  analogWrite(en, pwm);
}
