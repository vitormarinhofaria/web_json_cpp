#include "emscripten.h"
#include "emscripten/fetch.h"

#include "json.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace nlohmann;

void suc(emscripten_fetch_t *fetch)
{
    std::stringstream str;
    for (int i = 0; i < fetch->numBytes; i++)
    {
        str << fetch->data[i];
    }

    json name = json::parse(str.str());
    std::cout << name["nome"] << std::endl;
}
void fail(emscripten_fetch_t *ft)
{
    std::cout << "ERROR: " << ft->status << std::endl;
}

int main()
{
    emscripten_fetch_attr_t attrib;
    emscripten_fetch_attr_init(&attrib);
    strcpy(attrib.requestMethod, "POST");
    attrib.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
    static const char* headers[] = {"Access-Control-Allow-Origin", "*", "Content-Type", "application/json", 0};
    attrib.requestHeaders = headers;

    json reqJson = json::parse(R"({"nome": "vitor"})");
    std::string reqString = reqJson.dump();
    const char* reqData = reqString.c_str();
    attrib.requestData = reqData;
    std::cout << reqData << std::endl;
    attrib.requestDataSize = strlen(reqData);

    attrib.onsuccess = suc;
    attrib.onerror = fail;
    emscripten_fetch(&attrib, "http://localhost:5001");
    
    std::cout << "Hello munnnndo!!" << std::endl;
}