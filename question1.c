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
        char *data = "{ \"userReference\" : \"test\", \"terminalId\" : \"0000\", \"password\" : \"test\", \"deviceId\" : \"111111\"}";

        //initialize struct that will hold the request header
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers, "Content-Type:application/json");
        headers = curl_slist_append(headers, "x-source-code: test");
        headers = curl_slist_append(headers, "x-client-id: test");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_slist_free_all(headers);

        //set URL for POST
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_URL, "https://ng-anl-sandbox-app.accelerexholdings.com/anp/api/v3/linuxpostest/login");

        //set login details
        curl_easy_setopt(curl, CURLOPT_USERPWD, "username:password");

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
