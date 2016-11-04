int delayTime = 100;

char morseCode[] = {".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.. "};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //initial 5s pause
  delay(50 * delayTime);
  
    for (int characterIterator = 0; characterIterator < sizeof(morseCode); characterIterator++) 
		{
			switch(morseCode[characterIterator])
				{
					case '.': shortBlink(); break;
					case '-': longBlink(); break;
					case ' ': pause(); break;
					default: debug(); break;
				}
			delay(delayTime);
		} 
		
}




/** outputs '.' **/
void shortBlink(void) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delayTime);
  digitalWrite(LED_BUILTIN, LOW);
}

/** outputs '-' **/
void longBlink(void) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(4 * delayTime);
  digitalWrite(LED_BUILTIN, LOW);
}

/** outputs ' ' **/
void pause(void) {
  delay(2 * delayTime);
}

/** 1 second pause followed by 3 flashes followed by another 1 second pause indicate a non-morse code character**/
void debug(void)
	{
		delay(1);
		
		digitalWrite(LED_BUILTIN, HIGH);
		delay(delayTime);
		digitalWrite(LED_BUILTIN, LOW);
		
		digitalWrite(LED_BUILTIN, HIGH);	
		delay(delayTime);
		digitalWrite(LED_BUILTIN, LOW);
		
		digitalWrite(LED_BUILTIN, HIGH);
		delay(delayTime);
		digitalWrite(LED_BUILTIN, LOW);
		
		delay(1);
	}
		
