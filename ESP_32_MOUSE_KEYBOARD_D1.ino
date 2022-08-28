

/*INSTRUCTIONS all the commands should be followed by a NL&CR 
 
   TO MOVE MOUSE [M]
   M:X:Y:STEP , STEP IS GIVEN IN MILLISECONDS(delay between each  move)   EG M:20:200:100

   TO TYPE [T]
   TFROM HERE THE DEVICE WILL TYPE , eg : TXXXXXXXX

   TO RELEASE PRESSED BUTTONS [R] 

   TO PRESS AND HOLD BUTTONS [P] USE [R] to release
    PK_L_C // press KEY_LEFT_CONTROL ,
    PK_L_C  //KEY_LEFT_CTRL
    PK_L_A  //KEY_LEFT_ALT
    PK_D    //KEY_DELETE
    PK_L_S  //KEY_LEFT_SHIFT

    MOUSE CLICK [C]
    CL // left click
    CR //right click
    CM // middle click

    SPECIAL KEY [S] //
    SKR //KEY_RERUN 
 
*/
#include "BleCombo.h"
#include "addons.h"

//#define debug_serial

#ifdef  debug_serial
#define dprint(X) Serial.print(X)
#define dprintln(X) Serial.println(X)
#else
#define dprint(X)
#define dprintln(X)
#endif

void setup() {
  Serial.begin(115200);
  Serial.println("Starting work!");
  Keyboard.begin();
  Mouse.begin();
}

void loop() {
  if (Keyboard.isConnected()) {

    //  run_test_code();


    if (Serial.available() > 0)
    {
      in_string = Serial.readStringUntil('\n');
      k = in_string.charAt(0);
      in_string = in_string.substring(1);
      in_string.trim();
      dprintln("INSTRING: \t" + in_string);


      if (k == 'T')
      {
        dprintln("TYPE FUNCTION");
        Serial.println("TYPING\t" + in_string);
        Keyboard.print(in_string);
        todo = _type;
      }
      else if (k == 'S')
      {
        dprintln("SPECIAL FUNCTION");
         Serial.println("SPECIAL KEY");
     if ( in_string == "KR")
          Keyboard.write(KEY_RETURN);
else 
Serial.println("INPUT ERROR \nNO MATCH FOUND FOR THE KEY  ");

      }
      else if (k == 'P')
      {
        dprintln("PRESS FUNCTION");
         Serial.println("PRESS AND HOLD");
        todo = _press;
        if ( in_string == "K_L_C") Keyboard.press(KEY_LEFT_CTRL);
        else if ( in_string == "K_L_A") Keyboard.press(KEY_LEFT_ALT);
        else if ( in_string == "K_D") Keyboard.press(KEY_DELETE);
        else if ( in_string == "K_L_S") Keyboard.press( KEY_LEFT_SHIFT);
else 
Serial.println("INPUT ERROR \nNO MATCH FOUND FOR THE KEY  ");

      }
      else if (k == 'R')
      {
         Serial.println("RELEASE ALL");
        dprintln("RELEASE ALL");
        Keyboard.releaseAll();
      }
      else if (k == 'C')
      {
         Serial.println("MOUSE CLICK\t "+in_string);
        if ( in_string == "L") Mouse.click(MOUSE_LEFT);
        else if ( in_string == "R")  Mouse.click(MOUSE_RIGHT);
        else if ( in_string == "M")Mouse.click(MOUSE_MIDDLE);
      else 
      Serial.println("INPUT ERROR");
      }

     else if (k == 'M')
      {
         
        in_string = in_string.substring(1);
        no_of_delimiter=0;
        f_index = 0;
        s_index = 0;
        for (int i = 0; i < in_string.length(); i++)
        { 
          if (in_string.charAt(i) == ':')
            no_of_delimiter++;
      
        }
        if(no_of_delimiter==2)
        {
        dprintln("MOUSE MOVE STRING " + in_string );
             
        f_index = in_string.indexOf(':');
        s_index = in_string.indexOf(':', f_index + 1);

          mouse_X = in_string.substring(0, f_index).toInt();
          mouse_Y = in_string.substring(f_index + 1, s_index).toInt();
          mouse_S = in_string.substring(s_index + 1).toInt();
          mouse_S = abs(mouse_S);
          Serial.println( "MOVING MOUSE \n MOUSE X\t" + String(mouse_X) + "\tMOUSE_Y" + String(mouse_X) + "\tMOUSE_S\t" + String(mouse_S));

        }
        else
        Serial.println( "INNPUT ERROR \n USE M:X:Y:STEP for Mouse INPUT ");

        todo = _movemouse;


      }
else
Serial.println("INPUT NOT IN REQUIRED FORMAT ");
      in_string = "";
    }

    if (mouse_X != 0 || mouse_Y != 0 )

    {
      if (millis() - mouse_last_move > mouse_S)
      {
        //dprintln("mouse move");
        //Serial.println( "MOUSE X\t" + String(mouse_X) + "\tMOUSE_Y" + String(mouse_X) + "\tMOUSE_S\t" + String(mouse_S));
        mouse_last_move = millis();
        int x = 0;
        int y = 0;

        x = mouse_X > 0 ? 1 : x;
        x = mouse_X < 0 ? -1 : x;

        y = mouse_Y > 0 ? 1 : y;
        y = mouse_Y < 0 ? -1 : y;

        Mouse.move(x, y);

        if ( mouse_X != 0)
        {
          mouse_X = mouse_X > 0 ? mouse_X - 1 : mouse_X;
          mouse_X = mouse_X < 0 ? mouse_X + 1 : mouse_X;
        }
        if ( mouse_Y != 0)
        {
          mouse_Y = mouse_Y > 0 ? mouse_Y - 1 : mouse_Y;
          mouse_Y = mouse_Y < 0 ? mouse_Y + 1 : mouse_Y;
        }

      }
    }


  }
} //loop
