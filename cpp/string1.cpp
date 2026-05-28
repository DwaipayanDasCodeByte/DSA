#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    cout << "C is alphanumeric : " << isalnum('C') << endl;
    cout << "^ is alphanumeric : " << isalnum('^') << endl;
    cout << endl;
    char x{'*'};
    if (isalnum(x))
    {
        cout << x << " is alphanumeric" << endl;
    }
    else
    {
        cout << x << " is not alphanumeric" << endl;
    }

    cout << endl;
    cout << "is alphabetic : " << isalpha('C') << endl;
    cout << "is alphabetic : " << isalpha('$') << endl;
    cout << "is alphabetic : " << isalpha('b') << endl;

    std::cout << std::endl;
    std::cout << "std::isblank : " << std::endl;
    char message[]{"Hello there. How are you doing? The sun is shining."};
    std::cout << "message : " << message << std::endl;

    // Find and print blank index
    size_t blank_count{};
    for (size_t i{0}; i < sizeof(message); ++i)
    {
        // std::cout << "Value : " << message[i] << std::endl;
        if (isblank(message[i]))
        {
            cout << "Found a blank character at index : [" << i << "]" << endl;
            ++blank_count;
        }
    }
    cout << "In total we found " << blank_count << " blank characters." << endl;

    std::cout << "std::islower and std::isupper : " << std::endl;

    std::cout << std::endl;
    char thought[]{"The C++ Programming Language is one of the most used on the Planet"};
    size_t lowercase_count{};
    size_t upppercase_count{};

    // Print original string for ease of comparison on the terminal
    std::cout << "Original string  : " << thought << std::endl;

    for (auto character : thought)
    {
        if (std::islower(character))
        {
            std::cout << " " << character;
            ++lowercase_count;
        }
        if (std::isupper(character))
        {
            ++upppercase_count;
        }
    }
    std::cout << std::endl;
    std::cout << "Found " << lowercase_count << " lowercase characters and "
              << upppercase_count << " uppercase characters." << std::endl;

    std::cout << std::endl;
    std::cout << "std::isdigit : " << std::endl;

    char statement[]{"Mr Hamilton owns 221 cows. That's a lot of cows! The kid exclamed."};
    std::cout << "statement : " << statement << std::endl;

    size_t digit_count{};

    for (auto character : statement)
    {
        if (std::isdigit(character))
        {
            std::cout << "Found digit : " << character << std::endl;
            ++digit_count;
        }
    }
    std::cout << "Found " << digit_count << " digits in the statement string" << std::endl;

    // Turning a character to lowercase using the std::tolower() function
    std::cout << std::endl;
    std::cout << "std::tolwer and std::toupper: " << std::endl;
    char original_str[]{"Home. The feeling of belonging"};
    char dest_str[sizeof(original_str)];

    // Turn this to uppercase. Change the array in place
    for (size_t i{}; i < sizeof(original_str); ++i)
    {
        dest_str[i] = std::toupper(original_str[i]);
    }

    std::cout << "Original string : " << original_str << std::endl;
    std::cout << "Uppercase string : " << dest_str << std::endl;

    // Turn this to lowercase. Change the array in place
    for (size_t i{}; i < sizeof(original_str); ++i)
    {
        dest_str[i] = std::tolower(original_str[i]);
    }

    std::cout << "Lowercase string : " << dest_str << std::endl;

    return 0;
}