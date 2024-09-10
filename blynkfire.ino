#define BLYNK_TEMPLATE_ID "TMPL3jC7OjqZy"
#define BLYNK_TEMPLATE_NAME "Fire detection"
#define BLYNK_AUTH_TOKEN "DJou2vuB6Fnxz3JzOy7sAVxA9c0a4_Wo"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Payal";  // type your wifi name
char pass[] = "jaishreekrishna";  // type your wifi password
 

BlynkTimer timer;
int flag=0; 
void sendSensor(){ 
   int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==0 && flag==0) {
    Serial.println("Fire in the House");  
    Blynk.email("payalmakwana.122820@marwadiuniversity.ac.in", "Alert", "Fire Detected!");
    Blynk.logEvent("fire_alert","Fire Detected");
    
    flag=1;
  }
  else if (isButtonPressed==1)
  {
    flag=0;
    
  }


 
}

void setup(){
  pinMode(D1, INPUT);
 
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(5000L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
