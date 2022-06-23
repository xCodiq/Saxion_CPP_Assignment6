#include "String.h"
#include <exception>
#include <sstream>

String::String() : m_size(0), m_sequence(new char()) {
}

String::String(const char *character) : m_size(strlen(character)), m_sequence(new char()) {
    std::strcpy(this->m_sequence, character);
}

String::String(const std::string &str) : m_size(str.length()), m_sequence(new char()) {
    std::strcpy(this->m_sequence, str.data());
}

String::String(const String &string) : m_size(string.m_size), m_sequence(new char()) {
    std::strcpy(this->m_sequence, string.m_sequence);
}

String &String::operator=(const String &string) {
    if (&string == this) return *this;

    strcpy(this->m_sequence, string.m_sequence);
    this->m_size = string.m_size;

    return *this;
}

String::~String() {
    delete this->m_sequence;
    this->m_size = 0;
}

const char *String::c_str() {
    return this->m_sequence;
}

int String::length() const {
    return this->m_size;
}

bool String::empty() const {
    return this->m_size == 0;
}

char &String::at(int index) {
    if (index < this->length() || index > this->length())
        throw std::invalid_argument("Index cannot be lower or higher then the current size");

    return this->m_sequence[index];
}

char &String::get(int index) {
    return this->m_sequence[index];
}

char &String::front() {
    return get(0);
}

char &String::back() {
    return get(this->m_size - 1);
}

void String::append(const String &str) {
    this->m_size += str.m_size;
    strcat(this->m_sequence, str.m_sequence);
}

void String::append(const std::string &str) {
    this->m_size += str.length();
    strcat(this->m_sequence, str.data());
}

void String::append(const char *str) {
    this->m_size += strlen(str);
}

void String::append(char str) {
    std::stringstream ss;

    ss << str;
    this->m_size++;

    std::strcat(this->m_sequence, ss.str().data());
}

String String::substr(int start, int length) {
    String result_str{};
    std::copy(&this->m_sequence[start], &this->m_sequence[length], result_str.m_sequence);
    result_str.m_size = length;
    return result_str;
}

String String::substr(int start) {
    return substr(start, this->m_size);
}

bool String::starts_with(const String &prefix) {
    int prefix_size = prefix.m_size;

    for (int i = 0; i < prefix_size; ++i) {
        if (this->m_sequence[i] != prefix.m_sequence[i]) return false;
    }

    return true;
}

bool String::ends_with(const String &suffix) {
    int suffix_size = suffix.m_size;

    for (int i = this->m_size - 1; i >= suffix_size; --i) {
        if (this->m_sequence[i] != suffix.m_sequence[i]) return false;
    }

    return true;
}

bool String::contains(const String &needle) {
    return strstr(this->m_sequence, needle.m_sequence);
}

int String::find(const String &needle, int start) {
    if (needle.empty() || start < 0) return -1;

    int correct_searches = 0;
    for (int i = start; i < this->m_size; i++) {
        if (this->m_sequence[i] == needle.m_sequence[correct_searches]) {
            correct_searches++;
        } else {
            correct_searches = 0;
            continue;
        }

        if (correct_searches == needle.m_size) return i - correct_searches + 1;
    }

    return -1;
}

int String::find(const String &needle) {
    return this->find(needle, 0);
}

void String::swap(String str) {
    std::swap(this->m_sequence, str.m_sequence);
    std::swap(this->m_size, str.m_size);
}

void swap(String &first, String &second) {
    String temp = first;

    first.swap(second);
    second.swap(temp);

    delete temp.c_str();
}

String concat(String &first, String &second) {
    String result{first};
    result.append(second);
    return result;
}
