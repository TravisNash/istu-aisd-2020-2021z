using System;
using System.Security.Cryptography.X509Certificates;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MergeSort
{
    class Program
    {
        //Преобразование массива string в массив int
        public static int[] TransformArray(string[] anArray)
        {
            int[] Arr = new int[anArray.Length];
            for (int i = 0; i < anArray.Length; i++)
            {
                Arr[i] = Convert.ToInt32(anArray[i]);
            }
            return Arr;
        }
        //Вспомогательный метод, разбивающий на левую и правую часть
        public static int[] Sort(int[] anArray)
        {
            if (anArray.Length > 1)
            {
                int[] left = new int[anArray.Length / 2];
                int[] right = new int[anArray.Length - left.Length];
                for (int i = 0; i < left.Length; i++)
                {
                    left[i] = anArray[i];
                }
                for (int i = 0; i < right.Length; i++)
                {
                    right[i] = anArray[left.Length + i];
                }
                if (left.Length > 1)
                    left = Sort(left);
                if (right.Length > 1)
                    right = Sort(right);
                //вызов метода слияние
                anArray = MergeSort(left, right);
            }
            return anArray;
        }
        //Вспомогательный метод, производящий слияние 2 частей
        public static int[] MergeSort(int[] left, int[] right)
        {
            int[] anArray = new int[left.Length + right.Length];
            int i = 0;
            int lft = 0;
            int rght = 0;
            for (; i < anArray.Length; i++)
            {
                if (rght >= right.Length)
                {
                    anArray[i] = left[lft];
                    lft++;
                }
                else if (lft < left.Length && left[lft] < right[rght])
                {
                    anArray[i] = left[lft];
                    lft++;
                }
                else
                {
                    anArray[i] = right[rght];
                    rght++;
                }
            }
            return anArray;
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
        }
        static void Main()
        {
            Console.WriteLine("Введите элементы массива через пробел: ");
            //Ввод строки с клавиатуры
            string someArr = Console.ReadLine();
            //Разбивка строки на элементы
            string[] strArr = someArr.Split(' ');
            //конвертируем string в int
            int[] array = TransformArray(strArr);
            //Сортируем его и выводим результат на экран
            PrintArray(Sort(array));
        }
    }
}







