#include "HttpClient.h"

int main() {
    HttpClient client;
    client.get("https://api.sampleapis.com/beers/ale/1");
    client.post("https://reqbin.com/echo/post/json", "{'hello': 'world'}");
    return 0;
}


