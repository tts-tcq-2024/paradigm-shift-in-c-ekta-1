#include <stdio.h>
#include <assert.h>

// Function to check if battery parameters are within acceptable ranges
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isOk = 1; // Assume everything is ok initially  
    if (temperature < 0 || temperature > 45) {
        printf("Temperature out of range!\n");
        isOk = 0;
    }
    if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
        isOk = 0;
    }
    if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
        isOk = 0;
    }

    return isOk;
}

int main() {
    // Test case 1: All parameters are within acceptable ranges
    assert(batteryIsOk(25, 70, 0.7) == 1);

    // Test case 2: Temperature and SOC are out of range
    assert(batteryIsOk(50, 85, 0) == 0);

    return 0;
}
