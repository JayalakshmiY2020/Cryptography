#include <iostream>
#include <string>
#include <cctype>
std::string affine_encrypt(const std::string& plain_text, int a, int b) {
    std::string encrypted_text = "";
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char c : plain_text) {
        if (std::isalpha(c)) {
            char upper_c = std::toupper(c);
            int index = alphabet.find(upper_c);
            int encrypted_index = (a * index + b) % 26;
            char encrypted_char = alphabet[encrypted_index];
            encrypted_text += encrypted_char;
        } else {
            encrypted_text += c;
        }
    }
    return encrypted_text;
}
std::string affine_decrypt(const std::string& cipher_text, int a, int b) {
    std::string decrypted_text = "";
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a_inverse = 0;
    
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inverse = i;
            break;
        }
    }
    for (char c : cipher_text) {
        if (std::isalpha(c)) {
            char upper_c = std::toupper(c);
            int index = alphabet.find(upper_c);
            int decrypted_index = (a_inverse * (index - b + 26)) % 26;
            char decrypted_char = alphabet[decrypted_index];
            decrypted_text += decrypted_char;
        } else {
            decrypted_text += c;
        }
    }
    return decrypted_text;
}
int main() {
    std::string plain_text;
    int a, b;
    std::cout << "Enter the plain text: ";
    std::getline(std::cin, plain_text);
    std::cout << "Enter the multiplicative value: ";
    std::cin >> a;
    std::cout << "Enter the additive value: ";
    std::cin >> b;
    std::string encrypted_text = affine_encrypt(plain_text, a, b);
    std::cout << "Encrypted text: " << encrypted_text << std::endl;
    std::string decrypted_text = affine_decrypt(encrypted_text, a, b);
    std::cout << "Decrypted text: " << decrypted_text << std::endl;
    return 0;
}
