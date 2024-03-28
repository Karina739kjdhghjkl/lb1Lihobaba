#include <iostream> 
#include <windows.h> 

using namespace std; 

class Trinomial { 
private:
    int term1, term2, term3; 
public:
    Trinomial() {
        term1 = 0; 
        term2 = 0; 
        term3 = 0; 
    }
    Trinomial(int term1, int term2, int term3) { 
        this->term1 = term1; 
        this->term2 = term2; 
        this->term3 = term3; 
    }
    Trinomial(Trinomial& other) {
        term1 = other.term1; 
        term2 = other.term2; 
        term3 = other.term3; 
    }
    Trinomial(Trinomial&& other) { 
        term1 = other.term1;
        term2 = other.term2; 
        term3 = other.term3; 
    }
    Trinomial Sum(Trinomial& b) { 
        Trinomial result;
        result.term1 = term1 + b.term1; 
        result.term2 = term2 + b.term2; 
        result.term3 = term3 + b.term3; 
        return result;
    }
    Trinomial Sub(Trinomial& b) { 
        Trinomial result; 
        result.term1 = term1 - b.term1;
        result.term2 = term2 - b.term2;
        result.term3 = term3 - b.term3;
        return result; 
    }
    bool Equal(Trinomial& other) {
        if (term1 == other.term1 && term2 == other.term2 && term3 ==
            other.term3) return true;
        else false; 
    }
    Trinomial SumWithFloat(float n) { 
        Trinomial result;
        result.term1 = term1;
        result.term2 = term2; 
        result.term3 = term3 + n;
        return result; 
    }
    Trinomial MultipleWithFloat(float n) { 
        Trinomial result; 
        result.term1 = term1 * n; 
        result.term2 = term2 * n; 
        result.term3 = term3 * n;
        return result;
    }
    int Calculating(int x) { 
        int result; 
        result = x * term1 * term1 + x * term2 + term3; 
        return result;
    }
    void Input() { 
        cout << "Введите первый коэффициент: "; 
        cin >> term1;
        cout << "Введите второй коэффициент: ";
        cin >> term2; 
        cout << "Введите третий коэффициент: ";
        cin >> term3;
    }
    void Print() { // Метод для вывода тричлена
        if (term2 > 0 && term3 > 0 && term1 != 1 && term2 != 1) cout << term1
            << "x^2 + " << term2 << "x + " << term3 << endl;
        else if (term2 < 0 && term3 > 0 && term1 != 1) cout << term1 << "x^2 - "
            << -term2 << "x + " << term3 << endl;
        else if (term3 < 0 && term2 > 0 && term2 != 1) cout << term1 << "x^2 + "

            << term2 << "x - " << -term3 << endl; 
        else if (term2 < 0 && term3 < 0 && term1 != 1) cout << term1 << "x^2 - "
            << -term2 << "x - " << -term3 << endl; 
        else if (term1 == 1 && term2 != 1) cout << "x^2 + " << term2 << "x + "
            << term3 << endl;
        else if (term2 == 1 && term1 != 1) cout << term1 << "x^2 + " << "x + "
            << term3 << endl;
        else if (term1 == 1 && term2 == 1) cout << "x^2 + " << "x + " << term3
            << endl;
        else abort();
    }
};
int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    Trinomial a(2, 3, 4); 
    Trinomial b(1, -2, 1); 

    Trinomial c = a.Sum(b);
    cout << "Сумма a + b: ";
    c.Print(); 

    Trinomial d = a.Sub(b); 
    cout << "Разность a - b: ";
    d.Print(); 

    if (a.Equal(b)) {
        cout << "a и b равны" << endl;
    }
    else {
        cout << "a и b не равны" << endl;
    }

    Trinomial e = a.SumWithFloat(5.5);
    cout << "a + 5.5: ";
    e.Print(); 
    Trinomial f = a.MultipleWithFloat(2); 
    cout << "2 * a: ";
    f.Print(); 

    int x;
    cout << "Введите x: ";
    cin >> x; 
    int result = a.Calculating(x);
    cout << "Значение a при x = " << x << " : " << result << endl; 

    return 0;
}
