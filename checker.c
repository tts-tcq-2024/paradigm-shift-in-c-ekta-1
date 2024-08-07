#include <stdio.h>
#include <assert.h>


// Function to check if a parameter is within the acceptable range
int Range_check(float value, float min_value, float max_value, const char* paramName) {
    int Check = (value >= min_value && value <= max_value);
    if (!Check) {
        printf("%s is out of range (Value: %.2f)\n", paramName, value);
    }
    return Check;
}

// Function to check battery parameters
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempOk = Range_check(temperature, 0, 45, "Temperature");
    int socOk = Range_check(soc, 20, 80, "State of Charge");
    int chargeRateOk = Range_check(chargeRate, 0, 0.8, "Charge Rate");

    return tempOk && socOk && chargeRateOk;
}



int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
