#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

void calcSum(int a, int b) {                                        //laskee ja tuolstaa summan,  ei palautusta
    cout << "Summa: " << (a + b) << endl;
}

void calcDiv(int a, int b) {                                       //laskee ja tulsotaa osamäärä, ei palautusta
     if (b == 0) {
        cout << "Virhe: Jakaja ei saa olla nolla!" << endl;
 } else {
        cout << fixed << setprecision(2);
        cout << "Osamäärä: " << (float)a / b << endl;
}
}

int retSum(int a, int b) {                                         //palautetaan summan, ei tulosta
    return a + b;
}

float retDiv(int a, int b) {                                       //palautetaan osamäärä kahden desimaalin tarkkuudella tai heittää poikkeuksen (error)
    if (b == 0) {
        throw std::runtime_error("jakaja ei saa olla nolla!");
    }
    return (float)a / b;
}

int main() {
    int a, b;
    float result;

    cout << "Anna ensimmäinen kokonaisluku (a): ";                  //kysytöön luvut
    cin >> a;
    cout << "Anna toinen kokonaisluku (b): ";
    cin >> b;

    calcSum(a, b);
    calcDiv(a, b);

    int sumResult = retSum(a, b);
    cout << a << " + " << b << " = " << sumResult << endl;          //tulostetaan kutsumalla retSum

    try {
        result = retDiv(a, b);
        cout << fixed << setprecision(2);                          //try catch onnistuu tai error
        cout << a << " / " << b << " = " << result << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;                                                      //-LH-
}
