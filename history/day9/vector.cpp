#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

struct Book
{
  std::string title;
  int year;
  double price;

  Book()
    : title {""}
    , year {0}
    , price {0}
  {}

  // std::string title;
  // Book(title);
  // Book("Some book");
  Book(std::string title, int year, double price)
  {
    this->title = std::move(title);
    this->year = year;
    this->price = price;
  }

};

class BookManager
{
 private:
  std::vector<Book> m_books;
  ///
  ///
  ///

 public:
  // ===== 1. ADD BOOKS =====
  void AddBook(std::string const& title, int year, double price)
  {
    // Book b1 {title, year, price};
    // this->m_books.push_back(std::move(b1));
    this->m_books.emplace_back(title, year, price);
  }

  // ===== 2. REMOVE BOOKS =====
  bool RemoveBookByTitle(std::string const& title)
  {
    // std::vector<Book>::iterator it = this->m_books.begin();
    // // for (const Book& x : this->m_books)
    // for (; it != this->m_books.end(); it++)
    // {
    //     if (it->title == title)
    //     {
    //         this->m_books.erase(it);
    //         return true;
    //     }
    // }
    // return false;
    auto is_even = [&title](Book const& x) { return (x.title == title); };
    auto found_it = std::find_if(this->m_books.cbegin(), this->m_books.cend(), is_even);
    if(found_it != this->m_books.end()) {
      this->m_books.erase(found_it);
      return true;
    }
    return false;
  }

  // ===== 3. ITERATION & SEARCH =====
  void PrintAllBooks() const
  {
    // const std::vector<Book>::iterator it = this->m_books.begin(); // нельзя двигать итератор (int * const a = malloc...)
    std::vector<Book>::const_iterator it = this->m_books.cbegin();  // (const int *  a = malloc...)

    // while (it != this->m_books.end())
    for(; it < this->m_books.end(); it++) {
      std::cout << "Title: " << it->title << " Year: " << it->year << " Price: " << it->price
                << "\n";
      // it++;
    }
    std::cout << std::endl;
  }

  // ===== 4. SORTING =====
  void SortByYear()
  {
    // 5 5
    // comp(5, 5) -> false
    // 5 <-> 5
    // comp(5, 5) -> false
    // elements equal
    std::sort(
      this->m_books.begin(),
      this->m_books.end(),
      [](Book const& a, Book const& b) -> bool { return a.year < b.year; }
    );
  }

  // ===== 5. CAPACITY MANAGEMENT =====
  void OptimizeStorage() { this->m_books.shrink_to_fit(); }

  enum class AddBooksStrategy {
    DefaultForLoop,
    StandardAlgorithm,
    VectorInsert
  };

  // ===== 6. BULK OPERATIONS =====
  void AddBooksFromOther(BookManager const& other, AddBooksStrategy var)
  {
    // size_t num_books = other.m_books.size();
    for(auto const& x : other.m_books) {
      this->m_books.push_back(x);
    }

    // resize(); // size
    // reserve(); // capacity
    size_t num_books = other.m_books.size();
    this->m_books.reserve(num_books);
    std::copy(other.m_books.begin(), other.m_books.end(), std::back_inserter(this->m_books));

    // ------------ Most effective ------------ (std::move_iterator?)
    this->m_books.insert(this->m_books.end(), other.m_books.begin(), other.m_books.end());

    // ------------ Bad? ------------

    auto old_end = this->m_books.end();
    size_t size_to_add = other.m_books.size();
    this->m_books.reserve(this->m_books.size() + size_to_add);  // All iterators gets invalidated
    std::copy_n(other.m_books.begin(), other.m_books.size(), old_end);
  }

  // ===== 7. ALGORITHMS =====
  unsigned int CountBooksAfterYear(int year) const
  {
    unsigned int count {0};
    for(auto const& x : this->m_books) {
      if(x.year > year)
        count++;
    }
    return count;

    return std::count_if(this->m_books.begin(), this->m_books.end(), [year](Book x) {
      return (x.year > year) * true;
    });
  }

  private:
  
};

int main()
{
  BookManager manager;

  // Test AddBook
  manager.AddBook("The C++ Programming Language", 2'013, 45.99);
  manager.AddBook("Effective Modern C++", 2'014, 39.99);
  manager.AddBook("Clean Code", 2'008, 35.50);

  // Test Remove
  manager.RemoveBookByTitle("Clean Code");

  // Test Sort
  manager.SortByYear();
  manager.PrintAllBooks();

  // Test Bulk Operations
  BookManager other;
  other.AddBook("Design Patterns", 1'994, 49.99);
  manager.AddBooksFromOther(other);

  // Test Algorithm
  std::cout << "Books after 2000: " << manager.CountBooksAfterYear(2'000) << "\n";

  return 0;
}
