#ifndef UTIL_LIB
#define UTIL_LIB
#include <string>
class SampleClass
{

  public:
    int value;
    std::string name;
    SampleClass(int value, std::string name);
};

char *getMessage();

#endif // !UTIL_LIB
