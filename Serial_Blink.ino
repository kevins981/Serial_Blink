int rate = 100;
const int LED = 13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    char input = Serial.read();

    if (isDigit(input)){

      rate = input - '0';
      rate *= 100;
      Serial.print("the amount of delay is :"); Serial.println(rate);
    }
    else {
      Serial.println("input is not a number");
    }
  }

  blink();
}

void blink(){
  digitalWrite(LED, HIGH);
  delay(rate);
  digitalWrite(LED, LOW);
  delay(rate);
}

