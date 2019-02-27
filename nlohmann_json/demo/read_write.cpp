#include <iostream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

int main()
{
	//read json
	string updateInfo = "{\"UpdateInfo\":[{\"url\":\"aaaa.ipa\",\"platform\":\"ios\"}]}";
	json doc;
    doc = json::parse(updateInfo);

	auto &dataArray = doc["UpdateInfo"];

	if (dataArray.is_array())
	{
        for (auto &object : dataArray)
        {
			string url = object["url"].get<string>();
			string platform = object["platform"].get<string>();
        }
	}

	//write json
	json document;

    json array;

	for (int i = 0; i < 10; i++)
	{
        json object = {
                {"id", i},
                {"name", "test"},
                {"version", 1.01},
                {"vip", true}
                };

//        object = i;
		array.push_back(object);
	}

    document = {
            {"title", "PLAYER INFO"},
            {"players", array}
            };

	printf("out: \n%s\n", document.dump(4).c_str());

    return 0;
}
