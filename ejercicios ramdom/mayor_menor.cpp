#include <iostream>



int main(){
    int num1,num2;
    std::cout<<"ingrese el primer numero: ";
    std::cin>>num1;
    std::cout<<"ingrese el segundo numero:";
    std::cin>>num2;
    if (num1>num2){
        std::cout<<num1<<"es mayor que "<<num2;
    }else {
        std::cout<<num2<<"es mayor que "<<num2;
    }
    return 0;
}