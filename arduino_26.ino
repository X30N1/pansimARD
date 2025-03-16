// Sygnalizacja kolejowa
const int cz1 = 2; // D2 na A5
const int cz2 = 3; // D3 na A1
const int czasMigania = 1000;  // Czas w ms. 1s = 1000 ms

// Sygnalizacja drogowa
// Guzik
const int guzik = 13; // D13 na G-J28

// Światła nr.1 (najbliżej syg. kolejowej)
const int sygC = 4; // D4 na A-D37

const int sygZl1_1 = 5; // D5 na A-D39
const int sygZl1_2 = 6; // D6 na A-D41
const int sygZl1_3 = 7; // D7 na A-D42

const int sygZ = 8; // D8 na A-D43

bool zmiana = false; //Zmienna do zmiany świateł
int czasZmiany = 1500; //Ile czasu sygnalizacja świetlna będzie czekać pomiędzy zamianą

void setup() {
  // konfiguracja pinów, skrypt wykonuje się raz na początku:

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

  Serial.print("test boot");
}

void loop() {
  // Kod który wykonuje się cały czas:
  SygnalizacjaDrogowa();

}

void SygnalizacjaDrogowa() {
  // Symulacja sygnalizacji drogowej przełączanej guzikiem TODO
  
  if (digitalRead(guzik) == HIGH) {
    digitalWrite(sygC, LOW);
    digitalWrite(sygZl1_1, LOW);
    digitalWrite(sygZl1_2, LOW);
    digitalWrite(sygZl1_3, HIGH);
    delay(1000);
    digitalWrite(sygZl1_1, HIGH);
    digitalWrite(sygZl1_2, HIGH);
    digitalWrite(sygZl1_3, HIGH);
    digitalWrite(sygZ, HIGH);
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