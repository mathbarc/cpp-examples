#include <cstring>
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/urlapi.h>
#include <iostream>

struct request_response
{
    char *response;
    size_t size;
    CURLcode status_code;
};

size_t write_content_to_custom_structure(void *buffer, size_t size, size_t nmemb, void *clientp)
{
    size_t realsize = size * nmemb;
    struct request_response *mem = (struct request_response *)clientp;

    char *ptr = (char *)realloc(mem->response, mem->size + realsize + 1);
    if(!ptr)
        return 0;

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), buffer, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}

request_response get(char *url)
{
    CURL *curl;
    request_response chunk = {0};

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_content_to_custom_structure);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
        chunk.status_code = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return chunk;
}

request_response post(char *url, char *body)
{
    CURL *curl;
    request_response chunk = {0};

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_content_to_custom_structure);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &chunk);
        chunk.status_code = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    return chunk;
}

int main(int argc, char **argv)
{
    request_response res = get("https://example.com");
    std::cout << res.response << std::endl;
    return 0;
}
