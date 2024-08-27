#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class RESTConfigData {
private:
    json data;

    RESTConfigData() {
        // Read JSON file and store data
        std::ifstream file("data.json");
        if (file.is_open()) {
            file >> data;
            file.close();
        } else {
            std::cerr << "Failed to open JSON file." << std::endl;
        }
    }

public:
    static RESTConfigData& getInstance() {
        static RESTConfigData instance;
        return instance;
    }

    json getData() const {
        return data;
    }
    json getEndpointData(const int id) const {
        json getEndpointData(const int id) const {
            json data = getData();
            for (const auto& endpoint : data["Endpoints"]) {
                if (endpoint["id"] == id) {
                    return endpoint;
                }
            }
            return json();
        }
        
    }
};

class RESTClient {
public:
    void processData() {
        RESTConfigData& RESTConfigData = RESTConfigData::getInstance();
        json endpointData = RESTConfigData.getEndpointData(1);
        // Process the data
    }
};



int main() {
    RESTClient restClient;
    restClient.processData();

    return 0;
}