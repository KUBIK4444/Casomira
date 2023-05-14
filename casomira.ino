int TIME = 0; // in miliseconds
int tempTIME = 0;

int S1TIME;
int S2TIME;

void setup() {
  Serial.begin(9600);
  Serial.println("[SETUP] Probiha nastaveni senzoru.");
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  Serial.println("[SETUP] Dokonceno. Vitejte v systemu mereni casu na kolo. Pripojte druhy senzor na pin 8.");


}

void loop() {
  if(analogRead(A0) < 200){
startClock();
  }
}
void startClock(){
  Serial.println("--------------------");
  Serial.println("");
  Serial.println("Casovac kola zapnut.");
  Serial.println("");
  


while(analogRead(A1) > 200){ //Cas prvniho sektoru trati
  tempTIME = tempTIME + 10;
  S1TIME = S1TIME + 10;
  delay(10);
}
Serial.println("Sektor 1 projet."); 

delay(2000);
tempTIME = tempTIME + 2000;
S2TIME = S2TIME + 2000; //Zpozdeni kvuli omezeni bugu

while(analogRead(A0) > 200){
  tempTIME = tempTIME + 10; //Cas druheho sektoru
  S2TIME = S2TIME + 10;
  delay(10);
}
Serial.println("Sektor 2 projet.");

  Serial.println("");
  Serial.print("Cas zmeren. Celkovy cas: ");
  
  int SCS = tempTIME/1000;
  int TRS = tempTIME-(SCS*1000);
  Serial.print(SCS);
  Serial.print(",");
  Serial.print(TRS);
  Serial.println(" s");
  
  Serial.print("Sektor 1: ");

  SCS = S1TIME/1000;
  TRS = S1TIME-(SCS*1000);
  Serial.print(SCS);
  Serial.print(",");
  Serial.print(TRS);
  Serial.println(" s");

  Serial.print("Sektor 2: ");

  SCS = S2TIME/1000;
  TRS = S2TIME-(SCS*1000);
  Serial.print(SCS);
  Serial.print(",");
  Serial.print(TRS);
  Serial.println(" s");

  
  Serial.println("");
  Serial.println("--------------------");
  tempTIME = 0;
  S1TIME = 0;
  S2TIME = 0;
  delay(2000); //Delay proti bugu

}
