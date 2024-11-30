#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>
#include <iostream>
#include <strstream>

int main(int argc, char **argv)
{
    curlpp::Easy request;
    curlpp::options::Url url("https://example.com");
    request.setOpt(url);

    std::strstream os;
    curlpp::options::WriteStream writeStream(&os);
    request.setOpt(writeStream);
    request.perform();

    std::string data;

    os >> std::cout.rdbuf();

    return 0;
}
