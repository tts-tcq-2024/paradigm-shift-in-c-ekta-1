#include <stdio.h>
#include <assert.h>

// Function to check if battery parameters are within acceptable ranges

int Range_check(float Value,float max_value,float min_value, const char* Error_Log) 
{
int isOk = 1; // Assume everything is ok initially
    
    // Combine all conditions into a single logical expression
    if (Value < min_value || Value > max_value)
    {
        printf("%s is out of range\n", Error_Log);
        return 0;
    }
   return isOk;
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    return (Range_check(temperature, 0, 45, "Temperature") &&
            Range_check(soc, 20, 80, "State of Charge") &&
            Range_check(chargeRate, 0, 0.8, "Charge rate"));
}



int main() {
    // Test case 1: All parameters are within acceptable ranges
    assert(batteryIsOk(25, 70, 0.7) == 1);

    // Test case 2: Temperature and SOC are out of range
    assert(batteryIsOk(50, 85, 0) == 0);

    return 0;
}
