#include<stdio.h>
int main(){
    float B,F,U,S_1,S_2,S_3,S_4,D,L,S,N;
    printf("Mention the connected load in KW\n");
    scanf("%f",&L);
    printf("Mention the billing period\n");
    scanf("%f",&D);
    printf("Mention the electricity consumption in units\n");
    scanf("%f",&U);
F= (8.0/3.0)*L*D;
printf("The fixed charge generated will be INR %f\n",F);
if(U<125 || U==125){
    S_1=0;
    B=S_1+F;
    printf("The bill due to unit consumption is INR %f\n",S_1);
    printf("Preliminary bill =%f\n",B);}
else if (U>125 && U<=225){
    S_2= (U-125)*4.50;
    B=S_2+F;
     printf("The bill due to unit consumption is INR %f\n",S_2);
     printf("Preliminary bill =INR %f\n",B);
}
else if (U>225 && U<=325){
    S_3=100*4.50+(U-225)*5.50;
    B=S_3 +F;
     printf("The bill due to unit consumption is INR %f\n",S_3);
     printf("Preliminary bill =INR %f\n",B);
}
else if (U>325){
    S_4=100*4.50 + 100*5.50 + (U-325)*7.50;
    B=S_4+F;
     printf("The bill due to unit consumption is INR %f\n",S_4); 
     printf("Preliminary bill =INR %f\n",B);

}
if (B<2000 || B==2000){
    printf("The surcharge on the preliminary bill is INR 0");
    printf("The net payable amount is INR %f\n",B);
}
else if (B>2000 && B<=5000){
S= (0.05)*B;
N= B +S;
printf("The surcharge on the preliminary bill is INR %f\n",S);
printf("The net payable amount is INR %f\n",N);}
else if (B>5000){
    S=0.1*B;
    N= B+S;
    printf("The surcharge on the preliminary bill is INR %f\n",S);
    printf("The net payable amount is INR %f\n",N);
}
return 0;



}