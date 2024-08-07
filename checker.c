#include <stdio.h>
#include <assert.h>

// Function to check if battery parameters are within acceptable ranges

int batteryIsOk(float max_value,float min_value const char* error_message) 
{
int isOk = 1; // Assume everything is ok initially
    
    // Combine all conditions into a single logical expression
    if (temperature < max_value || temperature > max_value || soc < max_value || soc > max_value || chargeRate > max_value) 
    {     
        printf("%s is out of range\n", error_message);
        return 0;
    }
    return isOk;
    return (check_range(temperature, 0, 45, "Temperature") &&
            check_range(soc, 20, 80, "State of Charge") &&
            check_range(charge_rate, 0, 0.8, "Charge rate"));
}

int main() {
    // Test case 1: All parameters are within acceptable ranges
    assert(batteryIsOk(25, 70, 0.7) == 1);

    // Test case 2: Temperature and SOC are out of range
    assert(batteryIsOk(50, 85, 0) == 0);

    return 0;
}
