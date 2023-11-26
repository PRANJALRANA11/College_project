#include <stdio.h>

float calculate_cab_bill(float distance, float within_city_rate, float beyond_city_rate, float outside_city_rate, float outside_city_additional_rate, float min_outside_city_distance, float overnight_charge, float service_tax_rate) {
    float within_city_distance = (distance < 10) ? distance : 10;
    float beyond_city_distance = (distance > 10) ? (distance - 10) : 0;

    float within_city_cost = within_city_distance * within_city_rate;
    float beyond_city_cost = beyond_city_distance * beyond_city_rate;

    float outside_city_cost;
    if (distance >= min_outside_city_distance) {
        float outside_city_distance = (distance - min_outside_city_distance);
        outside_city_cost = (min_outside_city_distance * outside_city_rate) + (outside_city_distance * outside_city_additional_rate);
    } else {
        outside_city_cost = min_outside_city_distance * outside_city_rate;
    }

    float total_cost = within_city_cost + beyond_city_cost + outside_city_cost + overnight_charge;
    float service_tax = total_cost * service_tax_rate;
    float total_bill = total_cost + service_tax;

    printf("Within City Cost: %.2f RS\n", within_city_cost);
    printf("Beyond City Cost: %.2f RS\n", beyond_city_cost);
    printf("Outside City Cost: %.2f RS\n", outside_city_cost);
    printf("Overnight Charge: %.2f RS\n", overnight_charge);
    printf("Subtotal: %.2f RS\n", total_cost);
    printf("Service Tax (2%%): %.2f RS\n", service_tax);
    printf("Total Bill: %.2f RS\n", total_bill);

    return total_bill;
}

int main() {
    float distance = 30;  // You can change this distance as needed
    float within_city_rate = 2;
    float beyond_city_rate = 1;
    float outside_city_rate = 1;
    float outside_city_additional_rate = 0.75;
    float min_outside_city_distance = 50;
    float overnight_charge = 20;
    float service_tax_rate = 0.02;

    float total_bill = calculate_cab_bill(distance, within_city_rate, beyond_city_rate, outside_city_rate, outside_city_additional_rate, min_outside_city_distance, overnight_charge, service_tax_rate);

    return 0;
}
