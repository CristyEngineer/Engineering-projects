// Pin toewijzing
const int variabele_motor_snelheid = 9; // PWM pin voor motor snelheid
const int variabele_richting_1 = 8; // Richting 1
const int variabele_richting_2 = 10; // Richting 2
const int variabele_potmeter = A0; // Potentiometer
const int variabele_knop = 2; // Richtingsknop
const int variabele_LED_PIN = 13; // Status LED
bool richting = true;
int vorigevariabele_knop = LOW;
unsigned long laatsteTijd = 0;
void setup() {
pinMode(variabele_motor_snelheid, OUTPUT);
pinMode(variabele_richting_1, OUTPUT);
pinMode(variabele_richting_2, OUTPUT);
pinMode(variabele_knop, INPUT_PULLUP);
pinMode(variabele_LED_PIN, OUTPUT);
Serial.begin(9600);
}
void loop() {
int variabele_potmeterwaarde = analogRead(variabele_potmeter);
int snelheid = map(variabele_potmeterwaarde, 0, 1023, 0, 255);
int variabele_knopState = digitalRead(variabele_knop);
if (variabele_knopState == LOW && vorigevariabele_knop == HIGH && millis() - laatsteTijd > 200) {
richting = !richting;
laatsteTijd = millis();
}
vorigevariabele_knop = variabele_knopState;
if (richting) {
digitalWrite(variabele_richting_1, HIGH);
digitalWrite(variabele_richting_2, LOW);
} else {
digitalWrite(variabele_richting_1, LOW);
digitalWrite(variabele_richting_2, HIGH);
}
analogWrite(variabele_motor_snelheid, snelheid);
digitalWrite(variabele_LED_PIN, snelheid > 10 ? HIGH : LOW);
Serial.print("Snelheid: ");
Serial.print(snelheid);
Serial.print("\tRichting: ");
Serial.println(richting ? "Vooruit" : "Achteruit");
}
