String in_string;

enum {
  _type, _press,_releaseall,_movemouse,_functionkey,_mousebutton

  }todo;

char k;
int f_index, s_index ;
int mouse_X, mouse_Y,mouse_S ;  
unsigned long mouse_last_move;
int no_of_delimiter=0;
void run_test_code()

{
    Serial.println("Sending 'Hello world'");
    Keyboard.println("Hello World");

    delay(1000);
    Serial.println("Sending Enter key...");
    Keyboard.write(KEY_RETURN);

    delay(1000);
  /*
    Serial.println("Sending Play/Pause media key...");
    Keyboard.write(KEY_MEDIA_PLAY_PAUSE);
*/
    delay(1000);
/*
    Serial.println("Sending Ctrl+Alt+Delete...");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_DELETE);
    delay(100);
    Keyboard.releaseAll();
*/
    unsigned long startTime;

    Serial.println("Move mouse pointer up");
    startTime = millis();
    while(millis()<startTime+1000) {
      Mouse.move(0,-1);
      delay(5);
    }
    Serial.println("Move mouse pointer left");
    startTime = millis();
    while(millis()<startTime+1000) {
      Mouse.move(-1,0);
      delay(5);
    }

    Serial.println("Move mouse pointer down");
    startTime = millis();
    while(millis()<startTime+1000) {
      Mouse.move(0,1);
      delay(5);
    }

    Serial.println("Move mouse pointer right");
    startTime = millis();
    while(millis()<startTime+1000) {
      Mouse.move(1,0);
      delay(5);
    }
    
    Serial.println("Scroll Down");
    Mouse.move(0,0,-1);

    Serial.println("Left click");
    Mouse.click(MOUSE_LEFT);
    delay(500);

    Serial.println("Right click");
    Mouse.click(MOUSE_RIGHT);
    delay(500);
/*
    Serial.println("Scroll wheel click");
    Mouse.click(MOUSE_MIDDLE);
    delay(500);

    Serial.println("Back button click");
    Mouse.click(MOUSE_BACK);
    delay(500);

    Serial.println("Forward button click");
    Mouse.click(MOUSE_FORWARD);
    delay(500);

    Serial.println("Click left+right mouse button at the same time");
    Mouse.click(MOUSE_LEFT | MOUSE_RIGHT);
    delay(500);

    Serial.println("Click left+right mouse button and scroll wheel at the same time");
    Mouse.click(MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE);
    delay(500);

*/
  }
