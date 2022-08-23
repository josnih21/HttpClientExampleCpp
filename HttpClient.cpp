//
// Created by josnih on 8/23/2022.
//

#include "HttpClient.h"
using namespace web::http::client;
using namespace concurrency::streams;

http_client HttpClient::create_client(string url) {
    http_client_config config;
    config.set_validate_certificates(false);
    http_client client(U(url), config);
    return client;
}

string HttpClient::get(string url) {
    http_client client = create_client(url);
    web::http::http_request req(web::http::methods::GET);

    // sync request
    try {
        auto resp = client.request(req).get();
        wcout << resp.status_code() << " : sync request" << endl;
        stringstreambuf buffer;
        resp.body().read_to_end(buffer).get();
        wcout << buffer.collection().c_str() << ": BODY OF THE REQUEST" << endl;
    } catch(web::http::http_exception const &e){
        cout << "UNEXPECTED ERROR " << endl;
    }
}

void HttpClient::post(string url) {
    http_client client = create_client(url);
    web::http::http_request req(web::http::methods::POST);

    auto response = client.request(req).get();
    wcout << "STATUS CODE: " << response.status_code() << endl;
    stringstreambuf buffer;
    response.body().read_to_end(buffer).get();
    wcout << "RESPONSE BODY" <<buffer.collection().c_str() << endl;
}

