#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//including the crypto.h file that was created and needed
#include "crypto.h"
using namespace std;
// Name:Jared Ross
// Purpose: To demostrate string functions by using basic crytopgraphy  methods
int main()
{
    Crypto Cipher1;
    Crypto Cipher2;
    string cipher_key = "qwertyuiopasdfghjklzxcvbnm";
    string cipher_key2 = "wertyuiopasdgfhjqklzxcvbnm";

    Cipher1.EncryptFile(cipher_key, "test.txt", "test-encrypted.txt");
    Cipher1.DecryptFile(cipher_key, "test-encrypted.txt", "test-encrypt-decrypt-test.txt");
    Cipher1.DisplayFile("test.txt");
    Cipher1.DisplayFile("test-encrypted.txt");
    Cipher1.DisplayFile("test-encrypt-decrypt-test.txt");

    string cipher_key3 = cipher_key2;
    cout << "Encrypted String: " << Cipher2.EncryptString(cipher_key3, "C++ Programming Is Fun") << endl;

    cipher_key3 = cipher_key2;
    string cipher_key4 = cipher_key2;

    cout << "Decrypted String: " << Cipher2.DecryptString(cipher_key2, Cipher2.EncryptString(cipher_key3,"C++ Programming Is Fun") ) << endl;

    return 0;
}