#include <stdio.h>
#include <assert.h>


int Range_check(float temperature_value, float soc_value, float chargeRate_value, const char* Error_Log) 
{
    int isTemperatureOk = (temperature_value >= 0 && temperature_value <= 45);
    int isSocOk = (soc_value >= 20 && soc_value <= 80);
    int isChargeRateOk = (chargeRate_value >= 0 && chargeRate_value <= 0.8);
    
    if ( (!isTemperatureOk)||(!isSocOk)||(!isChargeRateOk) )
    {
        
        printf("%s is out of range\n", Error_Log);
        return 0;
    }
    return 1;
}

// Function to check battery parameters
   int batteryIsOk(float temperature, float soc, float chargeRate)
{

   return (Range_check(temperature,15,13, "Temperature") &&
           Range_check(soc, 20, 80, "State of Charge") &&
           Range_check(chargeRate, 0, 0.8, "Charge rate"));
    

}



int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
