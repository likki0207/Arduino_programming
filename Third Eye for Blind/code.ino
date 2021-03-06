const int signalPin = 12;
  int vib = 5; //Vibration Motor to PIN 5   
  void setup(){   
    Serial.begin(9600);   
    pinMode(vib, OUTPUT);   
  }   
  void loop(){   
    long ping_duration, cm;   
    //Send a low in the beginning, signalPin(in output mode) acts as a trigPin
    pinMode(signalPin, OUTPUT);
    digitalWrite(signalPin, LOW);   
    delayMicroseconds(2);   
    //Send a ping
    digitalWrite(signalPin, HIGH);   
    delayMicroseconds(5);   
    digitalWrite(signalPin, LOW);
    //Receive the ping, signlPin(in INPUT mode) acts as a echoPin
    pinMode(signalPin, INPUT);   
    ping_duration = pulseIn(signalPin, HIGH);   
    //Convert microseconds to Centimeters
    cm = ping_duration / 29 / 2;
    if(cm<=60 && cm>0){   
      int mapthedistance= map(cm, 1, 100, 20, 2000);   
      digitalWrite(vib, HIGH);   
      delay(2000);      
      digitalWrite(vib, LOW);   
      delay(mapthedistance); //To give varying delays based on the distance
    }
    Serial.print(cm);    
    Serial.println("cm"); 
    delay(100);   
    }   
