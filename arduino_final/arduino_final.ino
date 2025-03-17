// Sygnalizacja kolejowa
const int cz1 = 2; // D2 na A5
const int cz2 = 3; // D3 na A1
const int czasMigania = 1000;  // Czas w ms. 1s = 1000 ms

// Sygnalizacja drogowa
// Guzik
const int guzik = 1; // D13 na G-J28

// Światła nr.1 (najbliżej syg. kolejowej)
const int sygC = 4; // D4 na A-D37

const int sygZl1_1 = 5; // D5 na A-D39
const int sygZl1_2 = 6; // D6 na A-D41
const int sygZl1_3 = 7; // D7 na A-D42

const int sygZ = 8; // D8 na A-D43

/// Światła nr.2 (dalej od syg. kolejowej)
const int sygC2 = 12; // D12 na A-D38

const int sygZl2_1 = 9; // D9 na A-D52
const int sygZl2_2 = 10; // D10 na A-D54
const int sygZl2_3 = 11; // D11 na A-D55

const int sygZ2 = 13; // D13 na A-D56

// Zmienne funkcji
bool zmiana = false; //Zmienna do zmiany świateł
int czasZmiany = 1500; //Ile czasu sygnalizacja świetlna będzie czekać pomiędzy zamianą

void setup() {
  // Konfiguracja pinów, skrypt wykonuje się raz na początku:

  // Sygnalizacja Kolejowa
  pinMode(cz1, OUTPUT);
  pinMode(cz2, OUTPUT);

  // Sygnalizacja drogowa
  pinMode(guzik, INPUT);
  pinMode(sygC, OUTPUT);
  pinMode(sygZl1_1, OUTPUT);
  pinMode(sygZl1_2, OUTPUT);
  pinMode(sygZl1_3, OUTPUT);
  pinMode(sygZ, OUTPUT);

  // Sygnalizacja drogowa nr.2
  pinMode(sygC2, OUTPUT);
  pinMode(sygZl2_1, OUTPUT);
  pinMode(sygZl2_2, OUTPUT);
  pinMode(sygZl2_3, OUTPUT);
  pinMode(sygZ2, OUTPUT);

  // Miejsce na wstawienie funkcji stałych
  sygnalizacjaSetup();
}

void loop() {
  // Kod który wykonuje się cały czas:
  sygnalizacjaDrogowa();
}

void sygnalizacjaSetup() {
  // Funkcja do ustawienia sygnalizacji drogowej, należy używać w void setup()
  digitalWrite(sygC, HIGH);
  digitalWrite(sygZl1_1, HIGH);
  digitalWrite(sygZl1_2, HIGH);
  digitalWrite(sygZl1_3, HIGH);
  digitalWrite(sygZ, LOW);

  digitalWrite(sygC2, LOW);
  digitalWrite(sygZl2_1, HIGH);
  digitalWrite(sygZl2_2, HIGH);
  digitalWrite(sygZl2_3, HIGH);
  digitalWrite(sygZ2, HIGH);
}

void sygnalizacjaDrogowa() {
  // Symulacja sygnalizacji drogowej przełączanej guzikiem, należy używać z sygnalizacjaSetup na void setup() 
  if (digitalRead(guzik) == HIGH && zmiana == false) {

    digitalWrite(sygC, LOW);
    digitalWrite(sygZl1_1, LOW);
    digitalWrite(sygZl1_2, LOW);
    digitalWrite(sygZl1_3, HIGH);

    digitalWrite(sygZ2, LOW);
    digitalWrite(sygZl2_1, LOW);
    digitalWrite(sygZl2_2, LOW);
    digitalWrite(sygZl2_3, HIGH);

    delay(czasZmiany);
    
    digitalWrite(sygZl1_1, HIGH);
    digitalWrite(sygZl1_2, HIGH);
    digitalWrite(sygZ, HIGH);
    
    digitalWrite(sygZl2_1, HIGH);
    digitalWrite(sygZl2_2, HIGH);
    digitalWrite(sygC2, HIGH);

    zmiana = true;
    delay(1000);

  } else if (digitalRead(guzik) == HIGH && zmiana == true) {
    
    digitalWrite(sygZ, LOW);
    digitalWrite(sygZl1_1, LOW);
    digitalWrite(sygZl1_2, LOW);
    digitalWrite(sygZl1_3, HIGH);

    digitalWrite(sygC2, LOW);
    digitalWrite(sygZl2_1, LOW);
    digitalWrite(sygZl2_2, LOW);
    digitalWrite(sygZl2_3, HIGH);

    delay(czasZmiany);

    digitalWrite(sygC, HIGH);
    digitalWrite(sygZl1_1, HIGH);
    digitalWrite(sygZl1_2, HIGH);
    digitalWrite(sygC, HIGH);

    digitalWrite(sygZl2_1, HIGH);
    digitalWrite(sygZl2_2, HIGH);
    digitalWrite(sygZ2, HIGH);

    zmiana = false;
    delay(1000);
  }
}

void sygnalizacjaKolejowa() {
  // Skrypt do migania dwóch czerwonych świateł

  digitalWrite(cz1, LOW);
  digitalWrite(cz2, HIGH);

  delay(czasMigania);

  digitalWrite(cz1, HIGH);
  digitalWrite(cz2, LOW);

  delay(czasMigania);
}

void testRGB(int r, int g, int b) {
  // Skrypt do testowania diody RGB, skala 0-255 PWM. Należy używać w void setup()
  // testRGB WYKLUCZA użycie sygnalizacji drogowej

  analogWrite(9, 255 - r);
  analogWrite(10, 255 - g);
  analogWrite(11, 255 - b);
}
