#include <iostream>
#include <random>
#include <string>
uint16_t custom_hash(const std::string& message) {
    std::hash<std::string> hasher;
    std::mt19937 rng(hasher(message));
    std::uniform_int_distribution<uint16_t> dist(0, 65535);  // Range: 0 to 2^16 - 1
    return dist(rng);
}
int main() {
    std::string message;
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);
    uint16_t hash_value = custom_hash(message);
    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Hash value: " << hash_value << std::endl;
    // Simulate receiver computing the hash again
    std::string received_message;
    std::cout << "Enter the received message: ";
    std::getline(std::cin, received_message);
    uint16_t received_hash_value = custom_hash(received_message);
    std::cout << "Received Message: " << received_message << std::endl;
    std::cout << "Received Hash value: " << received_hash_value << std::endl;
    // Verify integrity
    if (received_hash_value == hash_value) {
        std::cout << "Integrity: The message has not been modified." << std::endl;
    } else {
        std::cout << "Integrity: The message has been modified." << std::endl;
    }
    return 0;
}
