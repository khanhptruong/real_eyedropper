const int srclk = 2;
const int rclk = 3;
const int ser = 4;
const int digit[] = { 5, 6, 7, 8, 9, 10, 11, 12 };
const int button = 13;
const byte segCode[] = {
  B00010000, //blank
  B10010010, //#
  B11111100, //0
  B01100000, //1
  B11011010,
  B11110010,
  B01100110,
  B10110110, //5
  B10111110,
  B11100000,
  B11111110,
  B11100110, //9
  B11101110, //A
  B00111110,
  B10011100,
  B01111010,
  B10011110,
  B10001110, //F
  B00000000  //clear
};

String color = "#abcdef";
bool lastBtnState = LOW;
bool currentBtnState = LOW;
bool colorReceived = false;

void setup() {
  pinMode(srclk, OUTPUT);
  pinMode(rclk, OUTPUT);
  pinMode(ser, OUTPUT);
  for(int i = 0; i < 8; i++){ pinMode(digit[i], OUTPUT); }
  pinMode(button, INPUT);

  digitalWrite(srclk, LOW);
  digitalWrite(rclk, LOW);
  digitalWrite(ser, LOW);
  for(int i = 0; i < 8; i++){ digitalWrite(digit[i], HIGH); }

  Serial.begin(9600);
}

void loop() {
  //check button status
  if(readRisingEdge(button) == true){
    //send go code to pi
    Serial.println("GET_COLOR");
    //receive color from pi
    colorReceived = false;
    while(colorReceived == false){
      if (Serial.available() > 0) {
        color = Serial.readStringUntil('\n');
        //Serial.print("You sent me: ");
        //Serial.println(data);
        colorReceived = true;
      }
    }
    displayColor(color);
  }else{
    //output current color
    displayColor(color);
  }
}

int asciiToIndex(int ascii){
  if(ascii == 0){
    return 0;
  }else if(ascii == 35){
    return 1;
  }else if(ascii >= 48 && ascii <= 57){
    return ascii - 46;
  }else if(ascii >= 97 && ascii <= 102){
    return ascii - 85;
  }else if(ascii == 33){ //! is clear
    return 18;
  }else{
    return 0;
  }
}

void displaySeg(char c){
  int ascii = c;
  int index = asciiToIndex(ascii);
  byte dispCode = segCode[index];
  byte scratch = dispCode;

  //iterate over 7 segements
  for(int i = 0; i < 8; i++){
    scratch = dispCode & B10000000;
    dispCode = dispCode << 1;
    if(scratch == B10000000){
      digitalWrite(ser, HIGH);
    }else{
      digitalWrite(ser, LOW);
    }
    //pulse clock
    digitalWrite(srclk, HIGH);
    digitalWrite(srclk, LOW);
  }
  //pulse clock
  digitalWrite(rclk, HIGH);
  digitalWrite(rclk, LOW);
}

void displayColor(String color){
  for(int i = 0; i < 8; i++){
    //deactivate last digit so that only 1 digit active at a time
    displaySeg('!'); //! is clear
    if(i == 0){
      digitalWrite(digit[7], HIGH);
    }else{
      digitalWrite(digit[i - 1], HIGH);
    }
    digitalWrite(digit[i], LOW);
    displaySeg(color[i]);
    delay(2);
  }
}

bool readRisingEdge(int btn){
  currentBtnState = digitalRead(btn);
  if(currentBtnState == HIGH && lastBtnState == LOW){
    lastBtnState = currentBtnState;
    return true;
  }else{
    lastBtnState = currentBtnState;
    return false;
  }
}

