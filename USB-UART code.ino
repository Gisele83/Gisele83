#include <PZEM004Tv30.h>
#include <SoftwareSerial.h>

/* Use software serial for the PZEM
 * Pin 11 Rx (Connects to the Tx pin on the PZEM)
 * Pin 12 Tx (Connects to the Rx pin on the PZEM)
*/

SoftwareSerial pzemSWSerial(11, 12);
PZEM004Tv30 pzem;

void setup() {
  Serial.begin(9600);
  
  pzem = PZEM004Tv30(pzemSWSerial);
  //Serial.println("CLEARDATA");  // on efface les données déjà présentes, s'il y a lieu
  Serial.println("Voltage,Current, Power, factor,"); // titre des colonnes, dans Excel
  
}
void loop() {
         
    //Serial.print("Custom Address:");
    //Serial.println(pzem.readAddress(), HEX);

    // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();
    /*char Label[]={"fluorescent lamp, fan_50W,portable air_conditioner1, portable air_conditioner2, portable air_conditioner3, reversing flasher,halogen lamp, laptop_Dell_P85F,fluorescent_lamp+fan,laptop+air_conditioner"};
    int size_Label=sizeof(Label)/sizeof(int);
    int i;*/
    //Serial.print("Voltage; Current; Power ");
    // test de validité de la donnée
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {
    //for(int i=0; i<size_Label; i++)
        // impression de la valeur sur le port serie
        //Serial.print("DATA,TIME,");
        

        
        Serial.print(String(voltage)+","+String(current)+","+String(power) +","+String(pf));
        Serial.print(",");    
        
       //Serial.print(Label[i]);
       // Serial.print(" , ");
        /* strt here
        Serial.print(" , ");
        Serial.print("Current:");    Serial.print(String(current));  
        Serial.println("A");
        Serial.print(" , ");
        Serial.print("Power:");     Serial.print(String(power));  Serial.println("W:");
        Serial.print(" , ");*///ehnd here
        //Serial.print(energy,3);     //Serial.println("kWh");
        // Serial.print(" , ");
        //Serial.print(frequency, 1); Serial.println("Hz");
        //Serial.print("PF:");  Serial.print(pf);  

    }

    Serial.println();
    delay(2000);
}
