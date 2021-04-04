#include <Keypad.h> 

const byte ROWS = 4; //four rows 
const byte COLS = 4; //four columns 
 
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad 
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad 
 
char keys[ROWS][COLS] = { 
  {'1','2','3', '/'}, 
  {'4','5','6', '*'}, 
  {'7','8','9', '-'}, 
  {'C','0','=', '+'} 
}; 
char key;
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 
//keypad 입력 코드


int segmentLEDs[] = {11, 12, 13, 14, 15, 16, 17, 18};
int segmentLEDsNum=8;
int digitForNum[10][8]={
  {0, 0, 0, 0, 0, 0, 1, 1}, //0
  {1, 0, 0, 1, 1, 1, 1, 1}, //1
  {0, 0, 1, 0, 0, 1, 0, 1}, //2
  {0, 0, 0, 0, 1, 1, 0, 1}, //3
  {1, 0, 0, 1, 1, 0, 0, 1}, //4
  {0, 1, 0, 0, 1, 0, 0, 1}, //5
  {0, 1, 0, 0, 0, 0, 0, 1}, //6
  {0, 0, 0, 1, 1, 1, 1, 1}, //7
  {0, 0, 0, 0, 0, 0, 0, 1}, //8
  {0, 0, 0, 0, 1, 0, 0, 1}  //9
};

double firstResult=0; 
double secondResult=0; 
double result=0; //첫 번째 숫자, 연산 부호 후 두 번째 숫자, 결과 
char sign; //연산기호

int input1(){
  while(1){
    key = keypad.getKey();
    if(key >= '0' && key <= '9'){
      firstResult=(firstResult*10)+(key-'0');
      //연산된 값을 7-segment에 표현하는 과정을 진행하지 못함
      
    }
    else if (key=='/') break;
    else if (key=='*') break;
    else if (key=='-') break;
    else if (key=='+') break;
  }
  return firstResult;
  
}
int input2(){
  while (1){
    key = keypad.getKey();
    if(key >= '0' && key <= '9'){
      secondResult=(firstResult*10)+(key-'0');
      //연산된 값을 7-segment에 표현하는 과정을 진행하지 못함
      
    }
    if (key=='/'){
      sign='/';
      break;
    }
    else if (key=='*'){ 
      sign='*';
      break;
    }
    else if (key=='-'){
      sign='-';
      break;
    }
    else if (key=='+'){ 
      sign='+';
      break;
    }
  }
  return secondResult;
}
  

void calculate(){
  switch(sign){
     case '+' :
       result = firstResult + secondResult;
       break;
     case '-' :
       result = firstResult - secondResult;
       break;
     case '*' :
       result = firstResult * secondResult;
       break;
     case '/' :
       result = firstResult / secondResult;
       break;
    }
}
void calculateSign(){
  switch(key){
    key = keypad.getKey();
    case '+':
      sign='+';
      break;
    case '-':
      sign='-';
      break;
    case '*':
      sign='*';
      break;
    case '/':
      sign='/';
      break;  
    }
}

void setup(){ 
  Serial.begin(9600); 
  for (int i=0;i<segmentLEDsNum;i++){
    pinMode(segmentLEDs[i],OUTPUT);
  }
  
} 
   
void loop(){
  key = keypad.getKey();
  input1();
  calculateSign();
  input2();
  calculate();

  if(key == '='){
    
  }
}

  


  
  
