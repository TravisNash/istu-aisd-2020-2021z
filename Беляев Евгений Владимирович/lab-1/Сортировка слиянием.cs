using System;
using System.Security.Cryptography.X509Certificates;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BubbleSort
{
    class Program
    {
        //Метод, сортирующий массив целых чисел по возрастанию
        public static void Bubble_Sort(int[] anArray)
        {
            //Основной цикл (количество повторений равно количеству элементов массива)
            for (int i = 0; i < anArray.Length; i++)
            {
                //Вложенный цикл (количество повторений, равно количеству элементов массива минус 1 и минус количество выполненных повторений основного цикла)
                for (int j = 0; j < anArray.Length - 1 - i; j++)
                {
                    //Если элемент массива с индексом j больше следующего за ним элемента
                    if (anArray[j] > anArray[j + 1])
                    {
                        //Меняем местами элемент массива с индексом j и следующий за ним
                        Swap(ref anArray[j], ref anArray[j + 1]);
                    }
                }
            }
            //Выводим элементы массива после всех итерации.
            PrintArray(anArray);
        }

        //Вспомогательный метод, "меняет местами" два элемента
        public static void Swap(ref int FirstArg, ref int SecondArg)
        {
            //Временная (вспомогательная) переменная, хранит значение первого элемента
            int cash = FirstArg;

            //Первый аргумент получил значение второго
            FirstArg = SecondArg;

            //Второй аргумент, получил сохраненное ранее значение первого
            SecondArg = stack;
        }

        //Вспомогательный метод, выводящий на консоль надпись + элементы массива через пробел
        public static void PrintArray(int[] anArray)
        {
            
            //Проделанная работа программы
            Console.WriteLine("Числа отсортированны:");
            //Перебор всех элементов массива
            for (int i = 0; i < anArray.Length; i++)
            {
                //Вывод значения текущего элемента и пробел после него
                Console.Write(anArray[i] + " ");
            }
            //Перевод строки
            Console.WriteLine("\n");
        }

        //Главный метод программы 
        static void Main(string[] args)
        {
            Console.WriteLine("Введите элементы массива через пробел:");
            //Ввод строки с клавиатуры
            string stringElements = Console.ReadLine();
            //Разбивка строки на элементы
            string[] stringArr = stringElements.Split(" ");
            //конвертируем string в int
            int[] someArray = new int[stringArr.Length];
            for (int i = 0; i < someArray.Length; i++)
            {
                someArray[i] = Convert.ToInt32(stringArr[i]);
            }
            //Сортируем его 
            Bubble_Sort(someArray);
        }
    }
}






