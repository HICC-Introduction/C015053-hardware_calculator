//1.첫 번째 숫자 입력, 2. 연산기호 선택, 3.숫자 입력, 4.= 단계로 계산
//이후 C버튼을 통해 reset하고 다시 위의 과정 반복

#include <Keypad.h> 
#include <SevSeg.h>

SevSeg sevseg;   //7-segment


void(* resetFunc) (void) = 0; //계산기 초기화 함수



const byte ROWS = 4; //four rows 
const byte COLS = 4; //four columns 
 
byte rowPins[ROWS] = {29, 28, 27, 26}; //connect to the row pinouts of the keypad 
byte colPins[COLS] = {25, 24, 23, 22}; //connect to the column pinouts of the keypad 
 
char keys[ROWS][COLS] = { 
  {'1','2','3', '/'}, 
  {'4','5','6', '*'}, 
  {'7','8','9', '-'}, 
  {'C','0','=', '+'} 
}; 
char key, key2; //input1, 2에서 사용되는 key변수

 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 
//keypad 입력 코드






double firstResult=0; 
double secondResult=0; 
double result=0; //첫 번째 숫자, 연산 부호 후 두 번째 숫자, 결과 
char sign; //연산기호

int input1(){
  Serial.println("input1 start");
  while(1){
    key = keypad.getKey();
    if(key == 'C'){
    Serial.println("C");
    delay(10);
    resetFunc();
    }
    if(key >= '0' && key <= '9'){
      firstResult=(firstResult*10)+(key-'0');
      delay(10);
      sevseg.setNumber(firstResult, 0);//???
      sevseg.refreshDisplay();
      Serial.println(firstResult);
    }
    else if (key=='/') break;
    else if (key=='*') break;
    else if (key=='-') break;
    else if (key=='+') break;
    
  }
  Serial.println(firstResult);
  return firstResult;
  
}
int input2(){
  Serial.println("input2 start");
  while (1){
    key2 = keypad.getKey();
    if(key2 == 'C'){
    Serial.println("C");
    resetFunc();
    }
    if(key2 >= '0' && key2 <= '9'){
      secondResult=(secondResult*10)+(key2-'0');
      //연산된 값을 7-segment에 표현하는 과정을 진행하지 못함
      Serial.println(key2);
    }
    if (key2=='/'){
      sign='/';
      break;
    }
    else if (key2=='*'){ 
      sign='*';
      break;
    }
    else if (key2=='-'){
      sign='-';
      break;
    }
    else if (key2=='+'){ 
      sign='+';
      break;
    }
    else if (key2=='='){ 
      break;
    }
    
  }
  return secondResult;
}
  

void calculate(){
  switch(sign){
     case '+' :
       result = firstResult + secondResult;
       Serial.println(result);
       break;
     case '-' :
       result = firstResult - secondResult;
       Serial.println(result);
       break;
     case '*' :
       result = firstResult * secondResult;
       Serial.println(result);
       break;
     case '/' :
       result = firstResult / secondResult;
       Serial.println(result);
       break;
    }
}
void calculateSign(){
  switch(key){
    key = keypad.getKey();
    case '+':
      sign='+';
      Serial.println("calculateSign+");
      break;
    case '-':
      sign='-';
      Serial.println("calculateSign-");
      break;
    case '*':
      sign='*';
      Serial.println("calculateSign*");
      break;
    case '/':
      sign='/';
      Serial.println("calculateSign/");
      break;  
    }
}


  


void setup(){ 
  Serial.begin(9600); 
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool leadingZeros = false; //leading zero x
  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_CATHODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(100);
}
  



   
void loop(){
  
  
  key = keypad.getKey();
  input1();
  sevseg.setNumber(firstResult, 0);
  calculateSign();
  input2();
  calculate();

  if(key == '='){
    Serial.println("=");//????
    delay(10);
    Serial.println(result);
    delay(10);
    sevseg.setNumber(result, 0);
    
  }
  
  sevseg.refreshDisplay();
  
}



  
  
