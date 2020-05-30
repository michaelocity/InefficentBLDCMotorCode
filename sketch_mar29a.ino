/*
 * mosfet gete terminals are marked as 
 * Captial Letter+channel type
 * ex: An = The n-channel mosfet of channel A
 */
int An = 2;
int Ap = 3;
int Bn = 4;
int Bp = 5;
int Cn = 6;
int Cp = 7;

//i know its phase but i spelled it wrong to seem cool
int fase = 0;

//for pot
int IN=A3;

//initally runs only once
void setup() {
  pinMode(IN,INPUT);
  
  pinMode(An, OUTPUT);
  pinMode(Ap, OUTPUT);
  pinMode(Bn, OUTPUT);
  pinMode(Bp, OUTPUT);
  pinMode(Cn, OUTPUT);
  pinMode(Cp, OUTPUT);

  //set the n channel mosfets for phase 0
  digitalWrite(An,LOW);
  digitalWrite(Bn,LOW);
  digitalWrite(Cn,HIGH);

  
  //set the p channel mosfets for phase 0
  digitalWrite(Ap,HIGH);
  digitalWrite(Bp,LOW);
  digitalWrite(Cp,HIGH);
}
//runs multiple times
void loop() {
  incrementPhase();
  updateMosfets();
  delay(map(analogRead(IN),0,1024,1,100));
}
//increments the phases of the the 3 phase motor
void incrementPhase()
{
  fase++;//increments the phase
  fase%=6;//if the phase is >5 then set it to 0
  // the mod operator is a short way to have this loop through all
  // six stages (0,1,2,3,4,5)
}

//this actaully controlls the mosfet cycles
void updateMosfets()
{
  switch(fase)
  {
    case 0:
      digitalWrite(An,LOW);
      digitalWrite(Cn,HIGH);
      break;
    case 1:
      digitalWrite(Ap,LOW);
      digitalWrite(Bp,HIGH);
      break;
    case 2:
      digitalWrite(Bn,HIGH);
      digitalWrite(Cn,LOW);
      break;
    case 3:
      digitalWrite(Ap,HIGH);
      digitalWrite(Cp,LOW);
      break;
    case 4:
      digitalWrite(An,HIGH);
      digitalWrite(Bn,LOW);
      break;
    case 5:
      digitalWrite(Cp,HIGH);
      digitalWrite(Bp,LOW);
      break;
    
  }
}
