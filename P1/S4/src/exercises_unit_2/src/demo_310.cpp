#include <iostream>
using namespace std;
 
class Icetray {
    int crystal;
    int extra_trays;
    string extra1;
    float extra2;
 
public:
    Icetray()
    {
        crystal = 0;
        extra_trays = 0;
        string extra1 = "demo";
        float extra2 = 1.01;

    }
    // Icetray(int crystal)
    // {
    //     // The below line is redundant/repeated
    //     extra_trays = 0;
    //     string extra1 = "demo";
    //     float extra2 = 1.01;
        
       
 
    //     /* Only initialize crystal by passing an argument,
    //        while all the other arguments are
    //        initialized the same way they were,
    //        as in the previous constructor*/
    //     this->crystal = crystal;
    // }
    // ------------------- Instead "Constructor Delegation" --------------
    Icetray(int crystal):Icetray()
    {
        // avoid repetition   
        this->crystal = crystal;
    }
 
    void show()
    {
        cout << extra_trays << '\t' << crystal << '\n';
    }
};
 
int main()
{
    Icetray Orange(3);
    Orange.show();
    return 0;
}
