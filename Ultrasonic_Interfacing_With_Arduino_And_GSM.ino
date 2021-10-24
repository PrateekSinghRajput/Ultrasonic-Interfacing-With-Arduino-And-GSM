//Prateek
//www.prateeks.in

int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}

void loop()
{

  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.println(distance);
  if (distance <= 20 && distance >= 0) {
    // Buzz
    digitalWrite(buzzPin, HIGH);
    delay(1000); //Give enough time for GSM to register on Network
    SendSMS();
  } else {

    digitalWrite(buzzPin, LOW);
  }
  delay(60);
}
void SendSMS()
{
  Serial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(1000);
  Serial.println("AT+CMGS=\"+919975617490\"\r"); //Change to destination phone number
  delay(1000);
  Serial.println("Sensor Detect Movement Plz Check");//the content of the message
  delay(200);
  Serial.println((char)26); //the stopping character Ctrl+Z
  delay(1000);
}
