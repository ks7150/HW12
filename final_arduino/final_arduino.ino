int v2 = 2;
int v3 = 3;
int v4 = 4;

void sendData() {
  StaticJsonDocument<128> resJson;
  JsonObject data = resJson.createNestedObject("data");

  data["v2"] = v2;
  data["v3"] = v3;
  data["v4"] = v4;

  String resTxt = "";
  serializeJson(resJson, resTxt);

  Serial.println(resTxt);
}

void setup() {
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
Serial.begin(9600);

}

void loop() {
  v2 = digitalRead (2);
  v3 =  digitalRead (3);
  v4 =  digitalRead (4);
 Serial.println (String (v2) + " " + (v3) + " " + (v4) + " ");
  delay(10);


   if (Serial.available() > 0) {
    int byteIn = Serial.read();
    if (byteIn == 0xAB) {
      Serial.flush();
      sendData();
    }
  }
}


