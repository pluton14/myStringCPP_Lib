#define _CRT_SECURE_NO_WARNINGS
#include "my_string.h"
#include <cstring>

void my_string::custom(const char* first, const int first_index, char* result, const int result_index, const int count) {
    int cnt = 0;
    while (cnt < count) {
        result[result_index + cnt] = first[first_index + cnt];
        cnt++;
    }
}

my_string::my_string() {
    _string = new char[1];
    _size = 0;
    _capacity = 1;
    _string[0] = '\0';
}

my_string::my_string(const char* chars) {
    const size_t size = strlen(chars);
    _string = new char[size + 1];
    _size = size;
    _capacity = size + 1;
    custom(chars, 0, _string, 0, _size);
    _string[_size] = '\0';
}

my_string::my_string(const string& chars) {
    const size_t size = chars.size();
    _string = new char[size + 1];
    _size = size;
    _capacity = size + 1;
    strcpy(_string, chars.c_str());
    _string[_size] = '\0';
}

my_string::my_string(const char* chars, const int count) {
    _string = new char[count + 1];
    _size = count;
    _capacity = count + 1;
    custom(chars, 0, _string, 0, count);
    _string[count] = '\0';
}

my_string::my_string(const int len, const char ch) {
    _size = len;
    _capacity = len + 1;
    _string = new char[len + 1];
    for (int i = 0; i < len; i++) {
        _string[i] = ch;
    }
    _string[len] = '\0';
}

my_string::my_string(const my_string& str) {
    _size = str.size();
    _capacity = str.capacity();
    _string = new char[_capacity];
    custom(str._string, 0, _string, 0, _size);
    _string[_size] = '\0';
}

my_string::~my_string() {
    delete this->_string;
    this->_string = nullptr;
    this->_size = 0;
    this->_capacity = 0;
}

my_string& my_string::operator=(const my_string& my_string_old) noexcept {
    int size = my_string_old.size();
    auto now = new char[_capacity];
    custom(my_string_old._string, 0, now, 0, size);
    now[size] = '\0';
    this->_size = size;
    this->_string = now;
    return *this;
}

my_string& my_string::operator=(my_string&& second_my_string) noexcept {
    _string = second_my_string._string;
    _size = second_my_string._size;
    _capacity = second_my_string._capacity;
    second_my_string._string = new char[1];
    second_my_string._size = 0;
    second_my_string._capacity = 1;
    second_my_string._string[0] = '\0';
    return *this;
}

my_string& my_string::operator+(const my_string& second_string) {
    //auto now = my_string(*this);
    //now += second_string;
    return operator+(second_string._string);
    //return now;
}

my_string& my_string::operator+(const char* second_string) {
    my_string* now = new my_string(this->_string);
    (*now).append(second_string);
    return(*now);
    //return *this + my_string(second_string);
}

my_string& my_string::operator+(const string& second_string) {
    return operator+(second_string.c_str());
}

my_string& my_string::operator+=(const my_string& second_string) {
    const size_t size_of_chars = second_string.size();
    const size_t capacity = second_string.capacity();
    const auto now = new char[capacity + _capacity - 1];
    custom(_string, 0, now, 0, _size);
    custom(second_string._string, 0, now, this->_size, size_of_chars);
    now[size_of_chars + _size] = '\0';
    this->_string = now;
    this->_size += size_of_chars;
    //this->_capacity += capacity - 1;
    return *this;
}

my_string& my_string::operator+=(const char* second_string) {
    return *this += my_string(second_string);
}
my_string& my_string::operator+=(const string& second_string) {
    const auto now = second_string.c_str();
    return *this += now;
}

my_string& my_string::operator=(const char* second_string) {
    *this = my_string(second_string);
    return *this;
}
my_string& my_string::operator=(const string& second_string) {
    *this = my_string(second_string);
    return *this;
}
my_string& my_string::operator=(const char ch) {
    this->_size = 1;
    this->_capacity = 2;
    this->_string = new char[2];
    this->_string[0] = ch;
    this->_string[1] = '\0';
    return *this;
}

char& my_string::operator[](const int index) {
    return this->_string[index];
}

bool my_string::operator>(const my_string& second_string) {
    int result = strcmp(this->_string, second_string._string);
    if (result > 0) {
        return true;
    }
    else {
        return false;
    }
}

bool my_string::operator<(const my_string& second_string) {
    return strcmp(this->_string, second_string._string) < 0;
}

bool my_string::operator>=(const my_string& second_string){
    if (this >= &second_string) {
        return true;
    }
    else {
        return false;
    }
}

bool my_string::operator<=(const my_string& second_string){
    for (size_t i = 0; i < this->_size; i++)
    {
        if (this->_string[i] < second_string._string[i])
        {
            return true;
        }
        else if (this->_string[i] > second_string._string[i])
        {
            return false;
        }
    }
    return true;
}


bool my_string::operator==(const my_string& second_string) {
    return strcmp(this->_string, second_string._string) == 0;
}

bool my_string::operator!=(const my_string& second_string) {
    return strcmp(this->_string, second_string._string) != 0;
}

const char* my_string::c_str() const {
    return this->_string;
}

char* my_string::data() const {
    return this->_string;
}

int my_string::length() const noexcept {
    return _size;
}

int my_string::size() const noexcept {
    return _size;
}

bool my_string::empty() const {
    return _size == 0;
}

int my_string::capacity() const noexcept {
    return _capacity;
}

void my_string::shrink_to_fit() {
    _capacity = _size + 1;
}

void my_string::clear() {
    for (int i = 0; i < this->_capacity; i++)
    {
        this->_string[i] = '\0';
    }
    this->_size = 0;
}

std::ostream& operator<<(std::ostream& os, const my_string& str) {
    return os << str._string;
}

std::istream& operator>>(std::istream& os, my_string& str) {
    str.clear();
    for (int cnt = os.get(); cnt != '\n' && cnt != -1; cnt = os.get()) {
        str.append(1, cnt);
        if (os.eof()) break;
    }
    return os;
    //return os >> str._size >> str._capacity;
}

void my_string::insert(const int index, const int count, const char ch) {
    const auto now = new char[count + 1];
    for (int i = 0; i < count; i++)
        now[i] = ch;
    now[count] = '\0';
    insert(index, now);
}

void my_string::insert(const int index, const char* chars) {
    const int size = strlen(chars);
    const int capacity = size;
    int res_capacity = 0;
    if (_capacity < _size + size + 1)
        res_capacity = _capacity + capacity + 1;
    else
        res_capacity = _capacity;
    const auto now = new char[res_capacity];
    custom(_string, 0, now, 0, index);
    custom(chars, 0, now, index, size);
    custom(_string, index, now, index + size, _size - index);
    now[_size + size] = '\0';
    this->_string = now;
    this->_size += size;
    this->_capacity = res_capacity;
}

void my_string::insert(const int index, const char* chars, const int count) {
    const auto now = new char[count + 1];
    custom(chars, 0, now, 0, count);
    now[count] = '\0';
    insert(index, now);
}

void my_string::insert(const int index, const std::string& chars) {
    const char* now = chars.c_str();
    insert(index, now);
}

void my_string::insert(const int index, const std::string& chars, const int count) {
    const auto now = new char[count];
    const auto temp_1 = chars.c_str();
    custom(temp_1, 0, now, 0, count);
    insert(index, now);
}

void my_string::erase(const int index, const int count) {
    if (index + count > _size || index < 0 || index >= _size || count < 0 || count > _size) {
        throw new std::out_of_range("my_string::erase");
    }
    const auto now = new char[_size];
    custom(_string, 0, now, 0, index);
    custom(_string, index + count, now, index, _size - count - index);
    now[_size - count] = '\0';
    _string = now;
    _size -= count;
}

void my_string::append(const int count, const char ch) {
    /*const auto now = new char[count + 1];
    for (int i = 0; i < count; i++)
        now[i] = ch;
    now[count] = '\0';
    append(now);*/
    this->insert(this->_size, count, ch);
}

void my_string::append(const char* chars) {
    /*const size_t size = strlen(chars);
    const size_t capacity = size;
    const auto now = new char[capacity + _capacity];
    custom(_string, 0, now, 0, _size);
    custom(chars, 0, now, _size, size);
    now[_size + size] = '\0';
    this->_string = now;
    this->_size += size;*/
    //this->_capacity += capacity;
    //this->insert(this->_size, chars);
    this->insert(this->_size, chars);
}

void my_string::append(const char* chars, const int index, const int count) {
    char* now = new char[count + 1];
    strncpy(now, chars + index, count);
    now[count] = '\0';
    this->insert(this->_size, now);
    delete[] now;
}

void my_string::append(const string& chars) {
    this->insert(this->_size, chars);
}

void my_string::append(const string& chars, const int index, const int count) {
    this->append(chars.c_str(), index, count);
}

void my_string::replace(const int index, const int count, const char* chars) {
    if (index <= this->_capacity)
    {
        this->erase(index, count);
        this->insert(index, chars);
    }
}

void my_string::replace(const int index, const int count, const string& chars) {
    replace(index, count, chars.c_str());
}

my_string& my_string::substr(const int index){
    return substr(index, _size - index);
}

my_string& my_string::substr(const int index, const int count){
    char* tmp_str = new char[count + 1];
    strncpy(tmp_str, (this->_string + index), count);
    tmp_str[count] = '\0';
    my_string* now = new my_string(tmp_str);
    delete[] tmp_str;
    return *now;
}

int my_string::find(const char* chars) {
    for (int i = 0; i < this->_size; i++)
        for (int j = 0; j < strlen(chars); j++) {
            if (this->_string[i + j] != chars[j])
                break;
            if (j == strlen(chars) - 1)
                return i;
        }
    return _size;
}

int my_string::find(const char* chars, const int index) {
    return index + substr(index).find(chars);
}

int my_string::find(const string& chars) {
    return find(chars.c_str());
}

int my_string::find(const string& chars, const int index) {
    return find(chars.c_str(), index);
}
