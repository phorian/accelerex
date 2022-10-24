#include <stdio.h>
#include <curl/curl.h>

int main(void)
{

    CURL *curl;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();

    if (curl){
        struct curl_slist *headers=NULL;
        char *data="name=Opeyemi&project=accelerexInt";

        //initialize struct that will hold the request header
        headers = curl_slist_append(headers, "x-source-code: test");
        headers = curl_slist_append(headers, "x-client-id: test");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        //set URL for POST
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_URL, "https://accelerexportal.app:8084/anp/api/v3/linuxpostest/login");

        //set login details
        curl_easy_setopt(curl, CURLOPT_USERPWD, "test:test");

        //Post the HTTP request and store response in 'response' variable
        response = curl_easy_perform(curl);

        //error check
        if(response != CURLE_OK){
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(response));
        }

    //cleanup
    curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}
