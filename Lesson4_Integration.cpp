#include <iostream>
#include <functional>
#include "Integration_Scheme_Interval.h"

void task_number_3()
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

                Com_Methods::Integration_Scheme_Interval Quadrature_Formula(Com_Methods::Integration_Scheme::Gauss5);

                // I с шагом h, h/2, h4, h8 соответственно
                double I_h  = Quadrature_Formula.Calculate_Integral(Begin, End, numSegments, f);
                double I_h2 = Quadrature_Formula.Calculate_Integral(Begin, End, numSegments, f);
                double I_h4 = Quadrature_Formula.Calculate_Integral(Begin, End, numSegments, f);
                double I_h8 = Quadrature_Formula.Calculate_Integral(Begin, End, numSegments, f);

                cout << "I*  - Ih/2  = " << (I_h2 - I_h) / ()

            };

    std::function<double(const double &x)> f1 = [](const double &x) { return 3*x + 5; };
    std::function<double(const double &x)> F1 = [](const double &x) { return 3*x*x/2 + 5*x; };

    std::function<double(const double &x)> f2 = [](const double &x) { return 5*x*x - x + 3; };
    std::function<double(const double &x)> F2 = [](const double &x) { return 5*x*x*x/3 - x*x/2 + 3*x; };

    std::function<double(const double &x)> f3 = [](const double &x) { return x*x*x - 2*x*x; };
    std::function<double(const double &x)> F3 = [](const double &x) { return x*x*x*x/4 - 2*x*x*x/3; };

}

int main()
{
	//подынтегральная функция f(x) = 2x
	std::function<double(const double &P)> f = 	[](const double &P) { return exp(P); };
	//первообразная F(x) = x^2
	std::function<double(const double &P)> F = 	[](const double &P) { return exp(P); };

	//квадратурная формула Гаусс-1
	Com_Methods::Integration_Scheme_Interval Quadrature_Formula(Com_Methods::Integration_Scheme::Gauss5);

	//начало и конец отрезка интегрирования
	double Begin = 0.0;
	double End   = 1.0;

	//число сегментов
	const int Num_Segments = 200;
	
	//точное значение интеграла (ф. Ньютона-Лейбница)
	double I_True = F(End) - F(Begin);


	//численное значение интеграла
	double I = Quadrature_Formula.Calculate_Integral(Begin, End, Num_Segments, f);

	std::cout << std::scientific;
	std::cout << "h            = " << (End - Begin) / Num_Segments << std::endl;
	std::cout << "I            = " << I << std::endl;
	std::cout << "I*           = " << I_True << std::endl;
	std::cout << "I - I*       = " << std::abs(I - I_True) << std::endl;
}