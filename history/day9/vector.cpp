#include <charconv>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Book {
    std::string title;
    int year;
    double price;
};

class BookManager {
private:
    std::vector<Book> m_books;

public:

    // ===== 1. ADD BOOKS =====
    void AddBook(const std::string& title, int year, double price) {
        // Book b1 {title, year, price};
        // this->m_books.push_back(std::move(b1));
        this->m_books.emplace_back(title, year, price);
    }

    // ===== 2. REMOVE BOOKS =====
    bool RemoveBookByTitle(const std::string& title) {
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
        auto is_even = [&title](Book x) { return (x.title == title); };
        auto found = std::find_if(this->m_books.begin(), this->m_books.end(), is_even);
    }

    // ===== 3. ITERATION & SEARCH =====
    void PrintAllBooks() const {
    }

    // ===== 4. SORTING =====
    void SortByYear() {
    }

    // ===== 5. CAPACITY MANAGEMENT =====
    void OptimizeStorage() {
    }

    // ===== 6. BULK OPERATIONS =====
    void AddBooksFromOther(const BookManager& other) {
    }

    // ===== 7. ALGORITHMS =====
    int CountBooksAfterYear(int year) const {
    }
};

int main() {
    BookManager manager;

    // Test AddBook
    manager.AddBook("The C++ Programming Language", 2013, 45.99);
    manager.AddBook("Effective Modern C++", 2014, 39.99);
    manager.AddBook("Clean Code", 2008, 35.50);

    // Test Remove
    manager.RemoveBookByTitle("Clean Code");

    // Test Sort
    manager.SortByYear();
    manager.PrintAllBooks();

    // Test Bulk Operations
    BookManager other;
    other.AddBook("Design Patterns", 1994, 49.99);
    manager.AddBooksFromOther(other);

    // Test Algorithm
    std::cout << "Books after 2000: " << manager.CountBooksAfterYear(2000) << "\n";

    return 0;
}