#include <stdio.h>

int main() {
    float L, D, U;
    float cycles, free_units, billable;
    float F, E, B, S, N;
    float limit1, limit2;

    printf("Mention the connected load in KW\n");
    scanf("%f", &L);
    printf("Mention the billing period (in days)\n");
    scanf("%f", &D);
    printf("Mention the electricity consumption in units\n");
    scanf("%f", &U);

    cycles     = D / 30.0;          /* how many 30-day cycles */
    free_units = 125 * cycles;      /* free units scale with period */

    /* Fixed charge: Rs 80 per kW per 30 days */
    F = 80 * L * cycles;
    printf("The fixed charge generated will be INR %f\n", F);

    /* Energy charge: slabs apply to units AFTER the free units */
    billable = U - free_units;
    if (billable <= 0)
        E = 0;
    else if (billable <= 100)
        E = billable * 4.50;
    else if (billable <= 200)
        E = 100 * 4.50 + (billable - 100) * 5.50;
    else
        E = 100 * 4.50 + 100 * 5.50 + (billable - 200) * 7.00;
    printf("The bill due to unit consumption is INR %f\n", E);

    B = E + F;
    printf("Preliminary bill = INR %f\n", B);

    /* Surcharge limits also scale with the billing period */
    limit1 = 2000 * cycles;
    limit2 = 5000 * cycles;
    if (B <= limit1)
        S = 0;
    else if (B <= limit2)
        S = 0.05 * B;
    else
        S = 0.10 * B;
    N = B + S;

    printf("The surcharge on the preliminary bill is INR %f\n", S);
    printf("The net payable amount is INR %f\n", N);
    return 0;
}