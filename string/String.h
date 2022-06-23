#ifndef CPPASSIGNMENT6_STRING_H
#define CPPASSIGNMENT6_STRING_H

#include <iostream>
#include <cstring>
#include <memory>

class String {
private:
    char *m_sequence;
    int m_size = 0;

public:
    String();

    explicit String(const char *character);

    explicit String(const std::string &str);

    String(const String &string);

    String &operator=(const String &string);

    ~String();

    const char *c_str();

    [[nodiscard]] int length() const;

    [[nodiscard]] bool empty() const;

    char &at(int index);

    char &get(int index);

    char &front();

    char &back();

    void append(const String &str);

    void append(const std::string &str);

    void append(const char *str);

    void append(char str);

    String substr(int start, int length);

    String substr(int start);

    bool starts_with(const String &prefix);

    bool ends_with(const String &suffix);

    bool contains(const String &needle);

    int find(const String &needle, int start);

    int find(const String &needle);

    void swap(String str);
};

void swap(String &first, String &second);

String concat(String &first, String &second);


#endif //CPPASSIGNMENT6_STRING_H
