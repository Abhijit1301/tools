
#include <iostream>

double getTotalTaxInOldTaxRegime(double sal) {
    
}

double getTotalTaxInNewTaxRegime(double sal) {
    unsigned int rebate = 50000;
    unsigned int slabRange = 300000;
    if (sal > rebate) sal -= rebate;
    unsigned short taxPercent = 0;
    unsigned short slabCount = 6;
    double totalTax = 0;
    while (slabCount--) {
        double taxableAmount = slabRange;
        if (sal < slabRange || taxPercent == 30) taxableAmount = sal;

        sal -= taxableAmount;
        totalTax += (taxableAmount * taxPercent)/100;
        std::cout << "tax for taxpercent: " << taxPercent << " is: " << (taxableAmount * taxPercent)/100 << std::endl;
        if (taxPercent == 20) taxPercent = 30;
        else taxPercent += 5;
        
    }
    double healthAndEducationCess = totalTax * 0.04;
    return totalTax + healthAndEducationCess;
}
int main()
{
    printf("Hello World\n");
    unsigned int pay = 28;
    
    pay *= 100000;
    double basicPay = pay/2;
    double epf = basicPay*0.12;
    std::cout << "Annual contribution to employee provident fund: " << epf << " monthly: " << epf/12 << std::endl;
    double totalTax = getTotalTaxInNewTaxRegime(pay);
    std::cout << "total tax as per new tax regime: " << (unsigned int)totalTax << std::endl;
    double salPostTax = pay - totalTax;
    std::cout << "Annual salary post taxation: " << (unsigned int)salPostTax << " monthly: " << salPostTax/12 << std::endl;
    double salPostDeductions = salPostTax - epf;
    std::cout << "Annual salary post deductions: " << (unsigned int)salPostDeductions << " monthly: " << salPostDeductions/12 << std::endl;
    return 0;
}
