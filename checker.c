#include <stdio.h>
#include <assert.h>


// Function to check battery parameters
   int Range_Check(float temperature, float soc, float chargeRate, const char* Error_Log)
{
    int isTemperatureOk = (temperature >= 0 && temperature <= 45);
    int isSocOk = (soc >= 20 && soc <= 80);
    int isChargeRateOk = (chargeRate >= 0 && chargeRate <= 0.8);
   
    // Output error messages based on which conditions are not met
    if ( (!isTemperatureOk) ||(!isSocOk)||(!isChargeRateOk) )
    {
        printf("%s is out of range\n", Error_Log);
        return 0;
    }
   return 1;   
}

// Pure function to check battery status
int batteryIsOk(float temperature, float stateOfCharge, float chargeRate) {
    return (Range_Check(temperature,"Temperature") &&
           Range_Check(stateOfCharge,"State of Charge") &&
           Range_Check(chargeRate),"Charge rate");
}



int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}


