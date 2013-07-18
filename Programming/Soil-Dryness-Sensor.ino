int soilDryness;

//Do some research to find these out for your soil : )

int wet = 300;
int dry = 500;



void setup()
{
 Serial.begin(9600);   
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}


void loop()
{
 soilDryness = analogRead(A0); 
 
 Serial.println(soilDryness);
 
 //check the soil dryness -- larger numbers mean it is more dry
 //as soilDryness increases, we give increasingly urgent messages.
 if (soilDryness < wet)
 {
  Serial.println("I'm good! Plenty 'o' water here!"); 
  digitalWrite(13,LOW);
 }
 else if (soilDryness > wet && soilDryness < dry)
 {
  Serial.println("Could use a sip, nothing urgent though.");
  digitalWrite(13,HIGH);
  delay(200);
  digitalWrite(13,LOW);
  delay(800);
 }
 else if (soilDryness > dry)
 {
  Serial.println("WATER ME!");
   digitalWrite(13,HIGH);
   delay(200);
   digitalWrite(13,LOW);
   delay(100); 
 }
 
 delay(100); 
}
