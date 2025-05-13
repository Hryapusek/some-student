#include <iostream>
#include <tuple>
#include <iterator>
#include <vector>
#include <functional>

template <class T>
void print_element(const T& array);

template <>
void print_element< std::vector<int> >(const std::vector<int>& array);

template <class Iterator>
void print_element(Iterator it1, Iterator it2);

template <class Iterator, class T>
Iterator find_element(Iterator it_first, Iterator it_second, const T& data);

template <class Iterator, class T>
std::vector<Iterator> find_elements(Iterator it_first, Iterator it_second, const T& data);

template <class Iterator, class T>
std::vector<Iterator> _find_elements(Iterator it_first, Iterator it_second, const T& data);
// pred(val) -> true, false

template <class Iterator, class Pred>
Iterator _find_if (Iterator it_bgn, Iterator it_end, Pred pred);
// pred(*it) -> {true, false}
// auto l = [](int x){ return x % 2; };
// l(3) -> false
// Функциональные объекты:
// Функция
// Лямба
// Структура с оператором ()

int main (int argc, char** argv)
{
  std::ignore = argc;
  std::ignore = argv;

  // int a[] {10,20,30,40,50,60};
  std::vector<int> a {60,50,40,33,20,10};
  print_element(a);

  std::vector<int>::reverse_iterator rit_first = a.rbegin();
  std::vector<int>::reverse_iterator rit_second = a.rend();
  print_element(rit_first, rit_second);

  std::vector<int>::iterator it_first = a.begin();
  std::vector<int>::iterator it_second = a.end();
  constexpr int expected_data = 20;
  std::vector<int>::iterator it_out = find_element(it_first, it_second, expected_data);
  if (it_out != it_second)
  {
    std::cout << "Found data \""  << *it_out << "\" at element # " << std::distance(it_first, it_out) << "\n";
  }
  else
  {
    std::cout << "Data \"" << expected_data << "\" not found." << std::endl;
  }

  std::function<bool(int)> predic = [](int x_in) -> bool { return ((x_in % 2) != 0); };
  std::vector<int>::iterator it_out1 = _find_if(it_first, it_second, predic);
  if (it_out1 != it_second)
  {
    std::cout << "Found data \""  << *it_out1 << "\" at element # " << std::distance(it_first, it_out1);
  }
  else
  {
    std::cout << "Odd number not found." << std::endl;
  }
  
  // auto a = ...
  // a()
  // std::function - что то у чего есть оператор ()
  struct IsEvenIndexFunctor {
    size_t i = 0;
    bool operator()(int) {
      return (i++ % 2) == 0;
    }
  };
  IsEvenIndexFunctor predic2;
  bool res = predic2(2);
  std::function<bool(int)> is_even_index = [i = 0ull](int _) mutable -> bool { return ((i++ % 2) == 0); };
  // _find_if(it_first, it_second, predic);

  return 0;
}


template <class Iterator, class Pred>
Iterator _find_if (Iterator it_first, Iterator it_second, Pred pred)
{
  std::cout << "IF Search odd element\n";
  while (it_first != it_second)
  {
    if (pred(*it_first) == true)
    {
      return it_first;
    }
    it_first++;
  }
  return it_second;
}

// namespace std {
//   auto begin(container) {
//     if (.begin())
//     {
//       return container.begin
//     } else if (container is pointer) {
//       return container[0];
//     }
//   }
// }

/*
  Напечатать элементы массива используя итераторы
*/
// T = int *&
template <class T>
void print_element(const T& array)
{
  // standard template library
  // begin()
  // end()
  // std
  std::cout << "General version \n";
  auto it = std::begin(array);
  // int i = 0;
  // < -> !=
  while ( it != std::end(array) )
  {
    // Random access iterator
    // (right - left) / sizeof(T)

    // Bidirectional iterator

    std::cout << "element # " << std::distance(std::begin(array), it) << " = " << *it << "\n";
    std::advance(it, 1);
    // it++;
  }
  std:: cout << std::endl;

  // int a;
  // vector<int> v {0,1,2,3,4,5,6,7,8,9};
  // int i = v[3];
  // int& operator[]
  // int i = &v + 3; // INCORRECT!
  // Отличие begin():
  // int array1[10];
  // array1.begin(); // Error! array1 is just pointer
  // std::begin(array1);
  // array.begin()
}

template <>
void print_element< std::vector<int> >(const std::vector<int>& array)
{
  std::cout << "Vector version\n";
  auto it = std::begin(array);
  while ( it != std::end(array) )
  {
    std::cout << "element # " << std::distance(std::begin(array), it) << " = " << *it << "\n";
    it++;
  }
  std:: cout << std::endl;
}

/*
enum Register
{
  temperature,
  speed
}

template <Register reg>
class ReadRegisterResponse;

template <>
class ReadRegisterResponse<if reg == temperature>
{
  ReadRegisterResponse(Register reg)
  {
    if (reg == temp)
    {
      int16...
    } else if (reg == speed) {
      int32...
    }
  }

  int16
}

template <>
class ReadRegisterResponse<if reg == speed>
{
  int32
}

01


*/

// template <>
// void print_element< if T == std::list >(const std::vector<int>& array)
// {
//   std::cout << "Vector version";
//   auto it = std::begin(array);
//   while ( it != std::end(array) )
//   {
//     std::cout << "element # " << std::distance(std::begin(array), it) << " = " << *it << "\n";
//     it++;
//   }
//   std:: cout << std::endl;
// }

// Передаем интервал (два итератора)
template <class Iterator>
void print_element( Iterator it_first, Iterator it_second)
{
  std::cout << "Two Iterators\n";
  while (it_first != it_second)
  {
    std::cout << "element # " << std::distance(it_first, it_second) << " = " << *it_first << "\n";
    it_first++;
  }
  
}
// 1 1 2 3 5 8 13
/*
  Найти элемент с помощью итераторов
*/
template <class Iterator, class T>
Iterator find_element(Iterator it_first, Iterator it_second, const T& data)
{
  std::cout << "Search element\n";
  while (it_first != it_second)
  {
    if (*it_first == data)
    {
      return it_first;
    }
      it_first++;
  }
  return it_second;
}

/*
  Написать функцию суммирования элементов
*/

/*
  Удалить все четные элементы вектора
*/

/*
  Создать функцию которая будет разворачивать вектор
*/
