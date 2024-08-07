#include <stdio.h>
#include <assert.h>

int check_range(float value, float min_value, float max_value, const char* error_message)
{
    if (value < min_value || value > max_value)
    {
        printf("%s is out of range\n", error_message);
        return 0;
    }
    return 1;
}
 
int battery_is_ok(float temperature, float soc, float charge_rate)
{
    return (check_range(temperature, 0, 45, "Temperature") &&
            check_range(soc, 20, 80, "State of Charge") &&
            check_range(charge_rate, 0, 0.8, "Charge rate"));
}

int main() 
{
  assert(battery_is_ok(25, 70, 0.7));
  assert(!battery_is_ok(50, 85, 0));
  return 0;
}
