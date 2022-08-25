#include "HttpClient.h"

using namespace web::http::client;
using namespace concurrency::streams;

http_client HttpClient::create_client(const string &url) {
    http_client_config config;
    config.set_validate_certificates(false);
    http_client client(U(url), config);
    return client;
}

void HttpClient::get(const string &url) {
    http_client client = create_client(url);
    web::http::http_request req(web::http::methods::GET);
    client.request(req)
    .then([](const web::http::http_response& response){
        if(response.status_code() != web::http::status_codes::OK){
            throw runtime_error("Returned " + to_string(response.status_code()));
        }
        //This is a way to extract the response body of the request, handle it as you wish :)
        cout << response.extract_string().get() << endl;
    }).wait();
}

void HttpClient::post(const string &url, const utf8string &requestBody) {
    http_client client = create_client(url);
    web::http::http_request req(web::http::methods::POST);
    req.set_body(requestBody);
    client.request(req)
    .then([](const web::http::http_response& response){
        if(response.status_code() != web::http::status_codes::OK){
            throw runtime_error("Returned " + to_string(response.status_code()));
        }
        cout << response.extract_string().get() << endl;
    }).wait();
}