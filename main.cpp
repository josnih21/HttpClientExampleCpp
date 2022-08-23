#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "HttpClient.h"

int main() {
    HttpClient client;
    client.get("https://pokeapi.co/api/v2/pokemon/ditto");
}


