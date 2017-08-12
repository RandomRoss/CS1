// makes sure that .h do not share the same header as other .h files 
//this is why #endif is at the end 
#ifndef CRYPTO_HEADER
// defines the header as crypto
#define CRYPTO_HEADER
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>
using namespace std;
// Name:Jared Ross
// Purpose: To demostrate string functions by using basic crytopgraphy  methods
// Creating The Crtpto class 
// the fuctions for the cryoto-sanbox are stored in the crypto.h 
class Crypto {
public:

    void DisplayFile(string filename);
    void EncryptFile(string cipher, string filename_from, string filename_to);
    void DecryptFile(string cipher, string filename_from, string filename_to);
    string EncryptString(string &cipher, string string_to_be_encrypted);
    string DecryptString(string &cipher, string string_to_be_decrypted);
private:

    string original_cipher = "abcdefghijklmnopqrstuvwxyz";
    string cipher_key;
    void RotateCipherKey();
    char substitution_cipher(char char_to_encrypt);
    char reverse_substitution_cipher(char char_to_decrypt);
};
//rotation function
void Crypto::RotateCipherKey()
{
      string new_cipher;
    for (int i = 0; i < cipher_key.length(); i++) {
        if (i == cipher_key.length()-1) {   
            new_cipher.push_back(cipher_key.at(0));
        }
        else {
            new_cipher.push_back(cipher_key.at(i+1));  
        }
    }
    cipher_key = new_cipher;
}

char Crypto::substitution_cipher(char char_to_encrypt) {
    int position = cipher_key.find(char_to_encrypt);
    char_to_encrypt = original_cipher.at(position);
    RotateCipherKey();
    return char_to_encrypt;
}

char Crypto::reverse_substitution_cipher(char char_to_decrypt) {
    int position = original_cipher.find(char_to_decrypt);
    char_to_decrypt = cipher_key.at(position);
    RotateCipherKey();
    return char_to_decrypt;
}
//function displaying files for the file
void Crypto::DisplayFile(string filename) {
    string line;
    ifstream infile(filename);
    //if statement to see if the File is read or not
    // The Program will display "File couldnt  be read"
    if (!infile) {  
        cout << "File could not be Read"<< endl;
        exit( 1 );
    }
    while (infile >> line) {
        cout << line << " ";
    }
    cout << endl;
}

string Crypto::EncryptString(string &cipher, string string_to_be_encrypted) {
    cipher_key = cipher;  
    string encrypted = string_to_be_encrypted;
    //for loop to encrypt text file
    for (int i = 0; i < string_to_be_encrypted.length(); i++) {
        //converting upper case to lower case
        if (isupper(string_to_be_encrypted.at(i))) {   
            encrypted.at(i) = tolower(encrypted.at(i));
        }
        //This if statment will only be ran if all text is lower case letters
        if (islower(encrypted.at(i))) { 
            encrypted.at(i) = substitution_cipher(encrypted.at(i));
        }
    }
    return encrypted;
}

string Crypto::DecryptString(string &cipher, string string_to_be_decrypted) {
    cipher_key = cipher;
    //for loop to decrypt text file 
    string decrypted = string_to_be_decrypted;
    for (int i = 0; i < string_to_be_decrypted.length(); i++) {
        if (islower(decrypted.at(i))) { 
            decrypted.at(i) = reverse_substitution_cipher(decrypted.at(i));
        }
    }
    return decrypted;
}

void Crypto::EncryptFile(string cipher, string filename_from, string filename_to){
    cipher_key = cipher;   
    string line;
    string string_to_be_encrypted;
    ifstream infile(filename_from);
    //If statment checking if the text file is opened
    //The program didnt have a infile then "File could not be read" will be displayed 
    if (!infile) { 
        cout << "File could not be Read"<< endl;
        exit( 1 );
    }
    while (infile >> line) {
        string_to_be_encrypted += line + " ";
    }
    infile.close();
    string encrypted = EncryptString(cipher, string_to_be_encrypted);
    ofstream nfile;
    nfile.open (filename_to);
    nfile << encrypted;
    nfile.close();
}

void Crypto::DecryptFile(string cipher, string filename_from, string filename_to){
    cipher_key = cipher;    
    string line;
    string string_to_be_decrypted;
    ifstream infile(filename_from);
    //if statement checking if the file is opened/loaded 
    //if the file is not opened/loaded then "File could not be read" will be displayed
    if (!infile) { 
        cout << "File could not be Read"<< endl;
        exit( 1 );
    }
    while (infile >> line) {
        string_to_be_decrypted += line + " ";
    }
    infile.close();
    string decrypted = DecryptString(cipher, string_to_be_decrypted);
    ofstream nfile;
    nfile.open (filename_to);
    nfile << decrypted;
    nfile.close();
}
//#endif is to create a .h file and will not work correctly if this is not at the end of the .h file
#endif