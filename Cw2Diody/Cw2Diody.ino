void setup() {
  pinMode(13, OUTPUT);      // Ustaw pin jako wyście
}
 
void loop() {
  digitalWrite(13, HIGH);   // Ustaw stan wysoki na wyjściu 
  delay(1000);                       // Odczekaj sekundę
  digitalWrite(13, LOW);    // Ustaw stan niski na wyjściu
  delay(1000);                       // Odczekaj sekundę
}
