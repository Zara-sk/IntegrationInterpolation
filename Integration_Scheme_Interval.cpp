#include "Integration_Scheme_Interval.h"

namespace Com_Methods
{
	//конструктор: на вход подаётся тип квадратурной формулы
	Integration_Scheme_Interval::Integration_Scheme_Interval(Integration_Scheme_Type Type)
	{
		//заполнение массивов точек и весов интегрирования
		switch (Type)
		{
			//схема метода Гаусс-1
			case Gauss1:
			{
				Weights = { 2 };
				Nodes   = { 0 };
				break;
			}
		    case Gauss2:
            {
                Weights = { 1, 1 };
                Nodes   = { 1.0 / sqrt(3.0), -1.0 / sqrt(3.0) };
                break;
            }
            case Gauss3:
            {
                Weights = { 8.0/9, 5.0/9, 5.0/9};
                Nodes   = { 0, sqrt(3.0 / 5.0), -sqrt(3.0 / 5.0) };
                break;
            }
            case Gauss4:
            {
                Weights = { (18 + sqrt(30.0)) / 36, (18 + sqrt(30.0)) / 36,
                            (18 - sqrt(30.0)) / 36, (18 - sqrt(30.0)) / 36 };
                Nodes   = { sqrt((3.0 - 2*sqrt(6.0/5)) / 7), -sqrt((3.0 - 2*sqrt(6.0/5)) / 7),
                            sqrt((3.0 + 2*sqrt(6.0/5)) / 7), -sqrt((3.0 + 2*sqrt(6.0/5)) / 7),};
                break;
            }
            case Gauss5:
            {
                Weights = { 128.0 / 225, (322 + 13*sqrt(70.0)) / 900, (322 + 13*sqrt(70.0)) / 900,
                                         (322 - 13*sqrt(70.0)) / 900, (322 - 13*sqrt(70.0)) / 900 };
                Nodes   = { 0 , (1.0 / 3) * sqrt(5.0 - 2*sqrt(10.0 / 7)),
                               -(1.0 / 3) * sqrt(5.0 - 2*sqrt(10.0 / 7)),
                                (1.0 / 3) * sqrt(5.0 + 2*sqrt(10.0 / 7)),
                               -(1.0 / 3) * sqrt(5.0 + 2*sqrt(10.0 / 7))};
                break;
            }
            case Trapezium:
            {
                Weights = { 1,  1 };
                Nodes   = { 1, -1 };
                break;
            }
            case Parabolas:
            {
                Weights = { 4.0 / 3, 1.0 / 3, 1.0 / 3 };
                Nodes   = { 0 , 1, -1};
                break;
            }

		}
	}

	//метод для вычисления определённого интеграла: 
	//Begin и End - начало и конец отрезка 
	//Num_Segments - число сегментов
	//Func - подынтегральная функция
	double Integration_Scheme_Interval:: Calculate_Integral(
								         const double &Begin,
								         const double &End,
								         int Number_Segments,
								         const std::function<double(const double &P)>&Func) const
	{
		//результат (квадратурная сумма)
		double Result = 0.0;
		//начальная точка сегмента
		double X0;
		//шаг на отрезке
		double h = (End - Begin) / Number_Segments;
		//сумма по всем сегментам разбиения
		for (int i = 0; i < Number_Segments; i++)
		{
			//начальная точка сегмента
			X0 = Begin + i * h;
			//сумма по узлам интегрирования
			for (int Integ_Point = 0; Integ_Point < Nodes.size(); Integ_Point++)
			{
				//переход с мастер-элемента [-1, 1]
				double P = X0 + (1 + Nodes[Integ_Point]) * h / 2.0;
				Result += Weights[Integ_Point] * Func(P);
			}
		}
		//формируем результат с учётом якобиана на отрезке [-1, 1]
		return Result * (h / 2.0);
	}
}
