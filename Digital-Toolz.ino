#include <ArduinoVT.h>
Term Term;

#define tableoffsetX 2
#define tableoffsetY 8
#define togglepin 13

uint8_t PINSTATE[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
uint8_t PINTYPE[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
uint8_t ANSPINSTATE[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(115200);
  Term.Clear();
  Serial.print("Digital-Toolz\nBy Abdelali221");
  delay(2000);
  CurrentStatus(true);
  PinType();
  WriteToPins();
  DrawTable();
}

void loop() {
  if (Serial.available()) {
    char chr = Serial.read();
    if (chr == 10 || chr == 13) {
      ChangeMode();
    }
    switch (chr) {
      case '1':
        if (PINSTATE[0] == 0) {
          PINSTATE[0] = 1;
        } else {
          PINSTATE[0] = 0;
        }
      break;
      
      case '2':
        if (PINSTATE[1] == 0) {
          PINSTATE[1] = 1;
        } else {
          PINSTATE[1] = 0;
        }
      break;

      case '3':
        if (PINSTATE[2] == 0) {
          PINSTATE[2] = 1;
        } else {
          PINSTATE[2] = 0;
        }
      break;

      case '4':
        if (PINSTATE[3] == 0) {
          PINSTATE[3] = 1;
        } else {
          PINSTATE[3] = 0;
        }
      break;

      case '5':
        if (PINSTATE[4] == 0) {
          PINSTATE[4] = 1;
        } else {
          PINSTATE[4] = 0;
        }
      break;

      case '6':
        if (PINSTATE[5] == 0) {
          PINSTATE[5] = 1;
        } else {
          PINSTATE[5] = 0;
        }
      break;

      case '7':
        if (PINSTATE[6] == 0) {
          PINSTATE[6] = 1;
        } else {
          PINSTATE[6] = 0;
        }
      break;

      case '8':
        if (PINSTATE[7] == 0) {
          PINSTATE[7] = 1;
        } else {
          PINSTATE[7] = 0;
        }
      break;

      case '9':
        if (PINSTATE[8] == 0) {
          PINSTATE[8] = 1;
        } else {
          PINSTATE[8] = 0;
        }
      break;

      case '0':
        if (PINSTATE[9] == 0) {
          PINSTATE[9] = 1;
        } else {
          PINSTATE[9] = 0;
        }
      break;

      case 'A':
        if (PINSTATE[10] == 0) {
          PINSTATE[10] = 1;
        } else {
          PINSTATE[10] = 0;
        }
      break;

      case 'Z':
        if (PINSTATE[11] == 0) {
          PINSTATE[11] = 1;
        } else {
          PINSTATE[11] = 0;
        }
      break;

      case 'H':
        for (int i=0;i<12;i++) {
          if (PINTYPE[i] == 1) {
            PINSTATE[i] = 1;
          }
        }
      break;

      case 'L':
        for (int i=0;i<12;i++) {
          if (PINTYPE[i] == 1) {
            PINSTATE[i] = 0;
          }
        }
      break;

      case 'T':
        if (PINTYPE[togglepin - 2] == 1) {
          PINSTATE[togglepin - 2] = 0;
          CurrentStatus(false);
          delay(50);
          PINSTATE[togglepin - 2] = 1;
          CurrentStatus(false);
          delay(50);
          PINSTATE[togglepin - 2] = 0;
          CurrentStatus(false);
        }
      break;
    }
    CurrentStatus(false);
  }
  for (int i=0;i<12;i++) {
    if (PINTYPE[i] == 0) {
      CurrentStatus(false);
      WriteToPins();
    }
  }
}

void ChangeMode() {
  Term.SetCursPos(20 + tableoffsetX, 10 + tableoffsetY);
  Serial.print("Pin Mode Toggled!");
  while (1) {
    if (Serial.available()) {
      char chr = Serial.read();
      if (chr == 10 || chr == 13) {
        Term.SetCursPos(20 + tableoffsetX, 10 + tableoffsetY);
        Serial.print("                 ");
        return;
      }
      switch (chr) {
        case '1':
          if (PINTYPE[0] == 0) {
            PINTYPE[0] = 1;
          } else {
            PINTYPE[0] = 0;
          }
        break;

        case '2':
          if (PINTYPE[1] == 0) {
            PINTYPE[1] = 1;
          } else {
            PINTYPE[1] = 0;
          }
        break;

        case '3':
          if (PINTYPE[2] == 0) {
            PINTYPE[2] = 1;
          } else {
            PINTYPE[2] = 0;
          }
        break;

        case '4':
          if (PINTYPE[3] == 0) {
            PINTYPE[3] = 1;
          } else {
            PINTYPE[3] = 0;
          }
        break;

        case '5':
          if (PINTYPE[4] == 0) {
            PINTYPE[4] = 1;
          } else {
            PINTYPE[4] = 0;
          }
        break;

        case '6':
          if (PINTYPE[5] == 0) {
            PINTYPE[5] = 1;
          } else {
            PINTYPE[5] = 0;
          }
        break;

        case '7':
          if (PINTYPE[6] == 0) {
            PINTYPE[6] = 1;
          } else {
            PINTYPE[6] = 0;
          }
        break;

        case '8':
          if (PINTYPE[7] == 0) {
            PINTYPE[7] = 1;
          } else {
            PINTYPE[7] = 0;
          }
        break;

        case '9':
          if (PINTYPE[8] == 0) {
            PINTYPE[8] = 1;
          } else {
            PINTYPE[8] = 0;
          }
        break;

        case '0':
          if (PINTYPE[9] == 0) {
            PINTYPE[9] = 1;
          } else {
            PINTYPE[9] = 0;
          }
        break;

        case 'A':
          if (PINTYPE[10] == 0) {
            PINTYPE[10] = 1;
          } else {
            PINTYPE[10] = 0;
          }
        break;

        case 'Z':
          if (PINTYPE[11] == 0) {
            PINTYPE[11] = 1;
          } else {
            PINTYPE[11] = 0;
          }
        break;

        case 'W':
          for (int i=0;i<12;i++) {
            PINTYPE[i] = 1;
          }
        break;

        case 'R':
          for (int i=0;i<12;i++) {
            PINTYPE[i] = 0;
          }
        break;
      }
      PinType();
      WriteToPins();
    }
  }
}

void DrawTable() {
  for (int x=0;x<85;x++) {
    for (int y=2;y<7;y++) {
      if ((x + 7) % 7 == 0) {
        Term.SetCursPos(9 + x + tableoffsetX, y + tableoffsetY);
        Serial.print("|");
      } else if (y == 2 || y == 4 || y == 6) {
        Term.SetCursPos(9 + x + tableoffsetX, y + tableoffsetY);
        Serial.print("-");
      }      
    }
  }

  for (int i=0;i<84;i = i + 7) {
    Term.SetCursPos(11 + i + tableoffsetX, 1 + tableoffsetY);
    Serial.print("D");
    Serial.print((i/7) + 2);
  }
  Term.SetCursPos(2 + tableoffsetX, 3 + tableoffsetY);
  Serial.print("STATUS");
  Term.SetCursPos(3 + tableoffsetX, 5 + tableoffsetY);
  Serial.write("TYPE");
  Term.SetCursPos((togglepin * 7) - 1 + tableoffsetX, 7 + tableoffsetY);
  Serial.print("X"); 
}

void CurrentStatus(bool INIT) {
  for (int i=0;i<84;i = i + 7) {
    if (PINSTATE[i/7] != ANSPINSTATE[i/7] || INIT) {
      WriteToPins();
      Term.SetCursPos(11 + i + tableoffsetX, 3 + tableoffsetY);
      ANSPINSTATE[i/7] = PINSTATE[i/7];
      if (PINSTATE[i/7]  == 0) {
        Serial.print("LOW ");
      } else {
        Serial.print("HIGH");
      }
    }
  }  
}

void PinType() {
  for (int i=0;i<84;i = i + 7) {
    Term.SetCursPos(10 + i + tableoffsetX, 5 + tableoffsetY);
    if (PINTYPE[i/7] == 0) {
      Serial.print("INPUT ");
    } else if (PINTYPE[i/7] == 1) {
      Serial.print("OUTPUT");
    }
  }
}

void WriteToPins() {
  for (int i=0;i<12;i++) {
    if (PINTYPE[i] == 0) {
      pinMode(i+2, INPUT);
      PINSTATE[i] = digitalRead(i+2);
    } else {
      pinMode(i+2, OUTPUT);
      digitalWrite(i+2, PINSTATE[i]);
    }
  }
}