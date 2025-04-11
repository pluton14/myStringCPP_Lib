#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <string>

using std::string;

class my_string {
    char* _string;
    int _size;
    int _capacity;
public:
    static void custom(const char*, const int, char*, const int, const int);

    my_string();
    my_string(const char*);
    my_string(const string&);
    my_string(const char*, int);
    my_string(int, char);
    my_string(const my_string&);

    ~my_string();

    const char* c_str() const;
    char* data() const;
    int length() const noexcept;
    int size() const noexcept;
    bool empty() const;
    int capacity() const noexcept;

    void insert(int, int, char);
    void insert(int, const char*);
    void insert(int, const char*, int);
    void insert(int, const std::string&);
    void insert(int, const std::string&, int);

    my_string& operator=(const my_string&) noexcept;
    my_string& operator=(my_string&&) noexcept;
    my_string& operator+(const my_string&);
    my_string& operator+(const char*);
    my_string& operator+(const string&);
    my_string& operator+=(const char*);
    my_string& operator+=(const string&);
    my_string& operator+=(const my_string&);
    my_string& operator=(const char*);
    my_string& operator=(const string&);
    my_string& operator=(char);

    char& operator[](const int);

    bool operator>(const my_string&);
    bool operator<(const my_string&);
    bool operator>=(const my_string&);
    bool operator<=(const my_string&);
    bool operator!=(const my_string&);
    bool operator==(const my_string&);

    void shrink_to_fit();
    void clear();

    friend std::ostream& operator<<(std::ostream&, const my_string&);
    friend std::istream& operator>>(std::istream&, my_string&);

    void erase(int, int);

    void append(int, char);
    void append(const char*);
    void append(const char*, int, int);
    void append(const string&);
    void append(const string&, int, int);

    void replace(int, int, const char*);
    void replace(int, int, const string&);

    int find(const char*);
    int find(const char*, int);
    int find(const string&);
    int find(const string&, int);

    my_string& substr(int);
    my_string& substr(int, int);
};
#endif
