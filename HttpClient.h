//
// Created by josnih on 8/23/2022.
//
#include <cpprest/http_client.h>
#include <string.h>

using namespace std;
using namespace web::http::client;

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H


class HttpClient {
    http_client create_client(const string &url);

public:
    void get(const string &url);

    void post(const string &url, const utf8string &requestBody);
};


#endif //HTTPCLIENT_H
