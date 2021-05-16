#include <iostream>
#include <functional>
#include "Integration_Scheme_Interval.h"

void fd_task_number_3_4()
{
    using namespace std;
    // f - функция, F - первообразная
    std::function<void(const int &numSegments, const std::function<double(const double &x)>&f,
                                               const std::function<double(const double &x)>&F)> calculate =
            [](const int &numSegments, const std::function<double(const double &x)>&f,
                                       const std::function<double(const double &x)>&F)
            {
                double Begin = 0.0;
                double End   = 1.0;

                double I_True = F(End) - F(Begin);

                Com_Methods::Integration_Scheme_Interval Quadrature_Formula(Com_Methods::Integration_Scheme::Gauss1);

                // I с шагом h, h/2, h4, h8 соответственно
                auto h_vector = vector<int> {numSegments, numSegments*2, numSegments*4, numSegments*8 };

                double I_h  = Quadrature_Formula.Calculate_Integral(Begin, End, h_vector[0], f);
                double I_h2 = Quadrature_Formula.Calculate_Integral(Begin, End, h_vector[1], f);
                double I_h4 = Quadrature_Formula.Calculate_Integral(Begin, End, h_vector[2], f);
                double I_h8 = Quadrature_Formula.Calculate_Integral(Begin, End, h_vector[3], f);

                auto I_v = vector<double> {I_h, I_h2, I_h4, I_h8};

                for (int i = 0; i < 3; i++)
                {
                    double I_ch = I_v[i];
                    double I_ch2 = I_v[i+1];

                    double k = log2(1 + (I_ch2 - (I_ch)) / (I_True - I_ch2));
                    double I_Runge = (I_ch2 - I_ch) / (pow(2.0, k) - 1);
                    double I_Richardson = I_ch2 + I_Runge;

                    cout << "For h = " << h_vector[i] << endl;
                    cout << "I*            = " << scientific << I_True << endl;
                    cout << "Ih            = " << scientific << I_ch << endl;
                    cout << "Ih2           = " << scientific << I_ch2 << endl;
                    cout << "I* - Ih       = " << scientific << I_True - I_ch << endl;
                    cout << "dIh / dIh/2   = " << scientific << (I_True - I_ch) / (I_True - I_ch2) << endl;
                    cout << "I Runge       = " << scientific << I_Runge << endl;
                    cout << "I Richardson  = " << scientific << I_Richardson << endl;
                    cout << "dI Richardson = " << scientific << I_True - I_Richardson << endl << endl;

                }


            };

    // задание 3

//    std::function<double(const double &x)> f1 = [](const double &x) { return 3; };
//    std::function<double(const double &x)> F1 = [](const double &x) { return 3*x; };
//
//    std::function<double(const double &x)> f2 = [](const double &x) { return 5 - x; };
//    std::function<double(const double &x)> F2 = [](const double &x) { return 5*x - x/2; };
//
//    std::function<double(const double &x)> f3 = [](const double &x) { return -2*x*x + 2*x; };
//    std::function<double(const double &x)> F3 = [](const double &x) { return -2.0/3*x*x*x + x*x; };
//    cout << "3" << endl;
//    calculate(100, f1, F1);
//    cout << "5-x" << endl;
//    calculate(100, f2, F2);
//    cout << "-2x^2 + 2x" << endl;
//    calculate(100, f3, F3);

    // задание 4

    std::function<double(const double &x)> f = [](const double &x) { return x*sin(10000*x); };
    std::function<double(const double &x)> F = [](const double &x) { return - (x*cos(10000*x)) / 10000 + sin(10000*x) / 100000000; };
    calculate(10000, f, F);


}

int main()
{
//	//подынтегральная функция f(x) = 2x
//	std::function<double(const double &P)> f = 	[](const double &P) { return exp(P); };
//	//первообразная F(x) = x^2
//	std::function<double(const double &P)> F = 	[](const double &P) { return exp(P); };
//
//	//квадратурная формула Гаусс-1
//	Com_Methods::Integration_Scheme_Interval Quadrature_Formula(Com_Methods::Integration_Scheme::Gauss5);
//
//	//начало и конец отрезка интегрирования
//	double Begin = 0.0;
//	double End   = 1.0;
//
//	//число сегментов
//	const int Num_Segments = 200;
//
//	//точное значение интеграла (ф. Ньютона-Лейбница)
//	double I_True = F(End) - F(Begin);
//
//
//	//численное значение интеграла
//	double I = Quadrature_Formula.Calculate_Integral(Begin, End, Num_Segments, f);
//
//	std::cout << std::scientific;
//	std::cout << "h            = " << (End - Begin) / Num_Segments << std::endl;
//	std::cout << "I            = " << I << std::endl;
//	std::cout << "I*           = " << I_True << std::endl;
//	std::cout << "I - I*       = " << std::abs(I - I_True) << std::endl;
    fd_task_number_3_4();


}