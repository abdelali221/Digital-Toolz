#include <ArduinoVT.h>
Term Term;

int tableoffsetX = 16;
int tableoffsetY = 5;
int PINSTATE[] = {0, 0, 0, 0, 1, 1, 1, 1};
int PINTYPE[] = {1, 1, 1, 1, 1, 1, 1, 1};

void setup() {
  Serial.begin(38400);
  Term.Clear();
  Serial.print("Digital-Toolz\nBy Abdelali221");
  delay(2000);
  CurrentStatus();
  ChangePinType();
  WriteToPins();
  DrawTable();
}

void loop() {
  if (Serial.available()) {
    char chr = Serial.read();
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

      case 'H':
        for (int i=0;i<8;i++) {
          PINSTATE[i] = 1;
        }
      break;

      case 'L':
        for (int i=0;i<8;i++) {
          PINSTATE[i] = 0;
        }
      break;
    }
    CurrentStatus();
    WriteToPins();
  }
  
}

void DrawTable() {
  for (int x=9;x<29;x++) {
    for (int y=4;y<14;y++) {
      Term.SetCursPos(x + tableoffsetX, y + tableoffsetY);
      if (x == 9  || x == 28 || x == 20) {
        Serial.print("|");
      } else if (x > 9 && (y == 4 || y == 13)) {
        Serial.print("-");
      }      
    }
  }

  for (int i=0;i<8;i++) {
    Term.SetCursPos(5 + tableoffsetX, 5 + i + tableoffsetY);
    Serial.print("D");
    Serial.print(i + 2);
  }
  Term.SetCursPos(11 + tableoffsetX, 3 + tableoffsetY);
  Serial.print("STATUS");
  Term.SetCursPos(22 + tableoffsetX, 3 + tableoffsetY);
  Serial.write("TYPE");
}

void CurrentStatus() {
  for (int i=0;i<8;i++) {
    Term.SetCursPos(12 + tableoffsetX, 5 + i + tableoffsetY);
    if (PINSTATE[i]  == 0) {
      Serial.print("LOW ");
    } else {
      Serial.print("HIGH");
    }
  }  
}

void ChangePinType() {
  for (int i=0;i<8;i++) {
    Term.SetCursPos(22 + tableoffsetX, 5 + i + tableoffsetY);
    if (PINTYPE[i] == 0) {
      Serial.print("READ ");
    } else {
      Serial.print("WRITE");
    }
  }
}

void WriteToPins() {
  for (int i=0;i<8;i++) {
    if (PINTYPE[i] == 0) {
      pinMode(i+2, INPUT);
    } else {
      pinMode(i+2, OUTPUT);
      digitalWrite(i+2, PINSTATE[i]);
    }
  }
}
