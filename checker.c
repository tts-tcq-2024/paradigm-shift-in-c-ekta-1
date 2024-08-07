#include <stdio.h>
#include <assert.h>


// Function to check battery parameters
   int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isTemperatureOk = (temperature >= 0 && temperature <= 45);
    int isSocOk = (soc >= 20 && soc <= 80);
    int isChargeRateOk = (chargeRate >= 0 && chargeRate <= 0.8);

    // Output error messages based on which conditions are not met
    if (!isTemperatureOk) {
        printf("Temperature out of range! (Value: %.2f)\n", temperature);
    }
    if (!isSocOk) {
        printf("State of Charge out of range! (Value: %.2f)\n", soc);
    }
    if (!isChargeRateOk) {
        printf("Charge Rate out of range! (Value: %.2f)\n", chargeRate);
    }

    // Return 1 if all conditions are met, 0 otherwise
    return isTemperatureOk && isSocOk && isChargeRateOk;
}



int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}


