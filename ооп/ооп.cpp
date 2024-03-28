#include <iostream> 
#include <windows.h> 

using namespace std; 

class Trinomial { // Объявление класса Trinomial
private:
    int term1, term2, term3; // Объявление трех целочисленных переменных
public:
    Trinomial() { // Конструктор по умолчанию
        term1 = 0; // Инициализация term1 нулем
        term2 = 0; // Инициализация term2 нулем
        term3 = 0; // Инициализация term3 нулем
    }
    Trinomial(int term1, int term2, int term3) { // Конструктор с параметрами
        this->term1 = term1; // Присваивание значения term1
        this->term2 = term2; // Присваивание значения term2
        this->term3 = term3; // Присваивание значения term3
    }
    Trinomial(Trinomial& other) { // Конструктор копирования
        term1 = other.term1; // Копирование значения term1
        term2 = other.term2; // Копирование значения term2
        term3 = other.term3; // Копирование значения term3
    }
    Trinomial(Trinomial&& other) { // Конструктор перемещения
        term1 = other.term1; // Перемещение значения term1
        term2 = other.term2; // Перемещение значения term2
        term3 = other.term3; // Перемещение значения term3
    }
    Trinomial Sum(Trinomial& b) { // Метод для сложения двух тричленов
        Trinomial result; // Создание нового объекта result
        result.term1 = term1 + b.term1; // Сложение term1 с b.term1
        result.term2 = term2 + b.term2; // Сложение term2 с b.term2
        result.term3 = term3 + b.term3; // Сложение term3 с b.term3
        return result; // Возвращение результата
    }
    Trinomial Sub(Trinomial& b) { // Метод для вычитания двух тричленов
        Trinomial result; // Создание нового объекта result
        result.term1 = term1 - b.term1; // Вычитание b.term1 из term1
        result.term2 = term2 - b.term2; // Вычитание b.term2 из term2
        result.term3 = term3 - b.term3; // Вычитание b.term3 из term3
        return result; // Возвращение результата
    }
    bool Equal(Trinomial& other) { // Метод для сравнения двух тричленов
        if (term1 == other.term1 && term2 == other.term2 && term3 ==
            other.term3) return true; // Если все термы равны, возвращаем true
        else false; // Иначе возвращаем false
    }
    Trinomial SumWithFloat(float n) { // Метод для сложения тричлена с вещественным числом
        Trinomial result; // Создание нового объекта result
        result.term1 = term1; // Копирование term1
        result.term2 = term2; // Копирование term2
        result.term3 = term3 + n; // Сложение term3 с n
        return result; // Возвращение результата
    }
    Trinomial MultipleWithFloat(float n) { // Метод для умножения тричлена на вещественное число
        Trinomial result; // Создание нового объекта result
        result.term1 = term1 * n; // Умножение term1 на n
        result.term2 = term2 * n; // Умножение term2 на n
        result.term3 = term3 * n; // Умножение term3 на n
        return result; // Возвращение результата
    }
    int Calculating(int x) { // Метод для вычисления значения тричлена при заданном x
        int result; // Объявление переменной result
        result = x * term1 * term1 + x * term2 + term3; // Вычисление значения тричлена
        return result; // Возвращение результата
    }
    void Input() { // Метод для ввода коэффициентов тричлена
        cout << "Введите первый коэффициент: "; // Вывод сообщения
        cin >> term1; // Ввод term1
        cout << "Введите второй коэффициент: "; // Вывод сообщения
        cin >> term2; // Ввод term2
        cout << "Введите третий коэффициент: "; // Вывод сообщения
        cin >> term3; // Ввод term3
    }
    void Print() { // Метод для вывода тричлена
        if (term2 > 0 && term3 > 0 && term1 != 1 && term2 != 1) cout << term1
            << "x^2 + " << term2 << "x + " << term3 << endl; // Вывод тричлена, если term2 и term3 больше нуля, а term1 и term2 не равны 1
        else if (term2 < 0 && term3 > 0 && term1 != 1) cout << term1 << "x^2 - "
            << -term2 << "x + " << term3 << endl; // Вывод тричлена, если term2 меньше нуля, term3 больше нуля, а term1 не равен 1
        else if (term3 < 0 && term2 > 0 && term2 != 1) cout << term1 << "x^2 + "

            << term2 << "x - " << -term3 << endl; // Вывод тричлена, если term3 меньше нуля, term2 больше нуля, а term2 не равен 1
        else if (term2 < 0 && term3 < 0 && term1 != 1) cout << term1 << "x^2 - "
            << -term2 << "x - " << -term3 << endl; // Вывод тричлена, если term2 и term3 меньше нуля, а term1 не равен 1
        else if (term1 == 1 && term2 != 1) cout << "x^2 + " << term2 << "x + "
            << term3 << endl; // Вывод тричлена, если term1 равен 1, а term2 не равен 1
        else if (term2 == 1 && term1 != 1) cout << term1 << "x^2 + " << "x + "
            << term3 << endl; // Вывод тричлена, если term2 равен 1, а term1 не равен 1
        else if (term1 == 1 && term2 == 1) cout << "x^2 + " << "x + " << term3
            << endl; // Вывод тричлена, если term1 и term2 равны 1
        else abort(); // Если ни одно из условий не выполняется, вызывается функция abort(), которая прерывает выполнение программы
    }
};
int main() {
    SetConsoleCP(1251); // Встановлення кодування для введення тексту в консоль (Windows)
    SetConsoleOutputCP(1251); // Встановлення кодування для виведення тексту в консоль (Windows)

    Trinomial a(2, 3, 4); // Створення об'єкта a класу Trinomial з коефіцієнтами 2, 3, 4
    Trinomial b(1, -2, 1); // Створення об'єкта b класу Trinomial з коефіцієнтами 1, -2, 1

    Trinomial c = a.Sum(b); // Обчислення суми об'єктів a та b
    cout << "Сумма a + b: ";
    c.Print(); // Виведення суми

    Trinomial d = a.Sub(b); // Обчислення різниці об'єктів a та b
    cout << "Разность a - b: ";
    d.Print(); // Виведення різниці

    if (a.Equal(b)) { // Перевірка на рівність об'єктів a та b
        cout << "a и b равны" << endl;
    }
    else {
        cout << "a и b не равны" << endl;
    }

    Trinomial e = a.SumWithFloat(5.5); // Додавання до кожного коефіцієнта об'єкта a деякого дійсного числа
    cout << "a + 5.5: ";
    e.Print(); // Виведення результату

    Trinomial f = a.MultipleWithFloat(2); // Множення кожного коефіцієнта об'єкта a на деяке дійсне число
    cout << "2 * a: ";
    f.Print(); // Виведення результату

    int x;
    cout << "Введите x: ";
    cin >> x; 
    int result = a.Calculating(x); // Обчислення значення тричлена для введеного x
    cout << "Значение a при x = " << x << " : " << result << endl; // Виведення результату 

    return 0;
}
