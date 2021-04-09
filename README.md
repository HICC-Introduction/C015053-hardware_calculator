# Hardware - Calculator
## 목표 및 목적
아두이노를 활용해 계산기를 구현한다.
### 문제 분석
* 계산기를 구현하도록 한다.
    * 하드웨어 연결을 통해 계산기를 물리적으로 구성한다.
        * Arduino보드에 빵판과 전선을 활용해 전원, 디스플레이, 키페드를 연결한다.
            * 디스플레이, 키패드 등 의 회로구성을 확인한다.
                * 디스플레이의 논리구조 등 을 고려하여 회로를 구성한다.
                * 키패드의 논리구조 등 을 고려하여 회로를 구성한다. 
    * 소프트웨어 구현을 통해 계산기 내부 로직을 구현한다.
        * 내부 로직이 연산, 입력, 출력을 수행해야한다.
            * 계산기의 연산과정을 코드로 구현한다.
                * 입력받은 숫자와 연산자를 통해 연산한다. 
            * 계산기의 입력과정을 코드로 구현한다.
                * 4자리 이하의 값을 입력받는다.
                * leading-zero는 입력되지 않도록 한다.
            * 계산기의 출력과정을 코드로 구현한다. 
                * 숫자를 입력할 때 입력하는 숫자를 디스플레이에 표현한다.
                    * 숫자를 버튼으로 눌렀을 때 해당 버튼에 해당하는 숫자를 디스플레이에 표현하고 다른 숫자를 입력하면 전의 숫자가 왼쪽으로 이동하고 입력된 숫자가 디스플레이에 표현된다. 
                * 연산자를 입력할 때 기존의 숫자를 표현한다.
                    * 연산자 전까지 입력된 값을 디스플레이에 표현한다.
                        *  
                * =를 입력할 경우 연산 결과를 화면으로 보여준다.
                    *  
                * 계산이 불가능한 모든 경우에 대해서 0000을 화면에 출력한다.
                    *  
                * 0을 출력할 경우 하나의 0만을 출력한다.
                    * 조건문을 활용해 각 자리 숫자의 합이 0일 경우 0이 출력되도록 한다. 
## 개발 사양
### 하드웨어 - 개발
* CPU :	Intel(R) Core(TM) i5-8265U CPU @ 1.60GHz, 1800Mhz, 4 코어, 8 논리 프로세서
* RAM : 20.0GB
* HDD/SSD : 
  디스크 0(C:)

	imation M.2 PCIe 1TB SSD X931B

* GPU : 
	Intel(R) UHD Graphics 620
	NVIDIA GeForce GTX 1650 with Max-Q Design






### 하드웨어 - 부품
|인덱스|역할|모델명|가격|상세|링크|
|---|---|---|---|---|---|
|1|MCU|Arduino ATmega2560 R3 호환보드|8,200원|   |https://smartstore.naver.com/openidea/products/4829015097%7C
|2|파일 업로드|아두이노 시리얼 포트|0원|   |비고: 재고 보유로 인해 구매하지 않음|
|3|회로 연결|빵판|0원|   |비고: 재고 보유로 인해 구매하지 않음|
|4|전원|아두이노 파워 업계열 컨버터 케이블(5v to 12v)|1,700원|   |https://smartstore.naver.com/openidea/products/4846497720?%7C
|5|입출력: 디스플레이|OPEN-YA001-008|800원|세그먼트 FND 0.56인치 4CH 빨강|https://smartstore.naver.com/openidea/products/4983434849%7C
|5|입출력: 키패드|OPEN-TC06-013핀|670원|아두이노 멤브레인 4X4 키패드|https://smartstore.naver.com/openidea/products/4833221581%7C
|총합|   |   |14,670원|   |   |
### 소프트웨어
* OS : [OS 이름	Microsoft Windows 10 Pro 10.0.19042 빌드 19042]
* 개발 스택 : Arduino Mega
* 개발 프로그램 : Arduino IDE / Visual Studio
* 개발 언어 : C/C++
### 코드룰

* 코드 룰
```
    #include <stdio.h>

    #define testPin 1//pin지정
    
    int testVariable=13;//변수명
    
    void testClass(){   //함수명

    }
    void setup(){
        Serial.begin(9600);

    }
    void loop(){
        testClass();
        testVariable=analogRead(testpin);
        printf("loop is working");
        printf("Testpin is %d",testpin)
        }


    }
```


