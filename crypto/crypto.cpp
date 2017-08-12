#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "crypto.h"
using namespace std;
// Name:Jared Ross
// Purpose: To demostrate string functions by using basic crytopgraphy  methods
//  Rotate the cipher key. Example: abcdef becames bcdefa
//
// Note: Call by reference
void Crypto::RotateCipherKey()
{
}

// Perform a substitution cipher on a single character
// using the specified cipher key
// make sure it is lowercase (switch it if not) and an alpha
// character
// See reference document for implementation details.
// Example: 
// Assume your character is g and your key is 
// zabcdefghijklmnopqrstuvxy
//        ^
// abcdefghijklmnopqrstuvxyz     -- alphabet
// Your cipher character becames h

// Once your cipher charcter is encoded than rotate the cipher key

char Crypto::substitution_cipher(char char_to_encrypt)
{
    return char_to_encrypt;
}


// Perform a "reverse" substitution cipher on a single character
// using the specified cipher key
// See reference document for implementation details.
// You reverse the operation described above

char Crypto::reverse_substitution_cipher(char char_to_decrypt)
{
    return char_to_decrypt;
}

// Encrypt String and return it
// You will use the substitution_cipher() function to encrypt the
// individual characters
//
// Think for loop
string Crypto::EncryptString(string &cipher_key, 
    string string_to_be_encrypted)
{
    string encrypted_string = string_to_be_encrypted;

    return encrypted_string;
}

// Decrypt String and return it
// You will use the reverse_subsitution_cipher() function to 
// decrypt the individual characters
//
string Crypto::DecryptString(string &cipher_key, string string_to_be_decrypted)
{
    string decrypted_string = string_to_be_decrypted;

    return decrypted_string;
}

//
// Need to finish this one
//
// Display file specified by the filname parameter
// See EncryptFile/DecryptFile for details on how to read and
// display a file. Use the ifstream infile section to read a file
// and cout to display it to the screen.
void Crypto::DisplayFile(string filename)
{
}


// Encrypt the specified file using the specified cipher key and
// write the output to a different file
// This function is complete
void Crypto::EncryptFile(string cipher_key, 
    string filename_from, string filename_to)
{
    string input;
    ifstream infile;
    ofstream outfile;

    infile.open (filename_from.c_str());
    outfile.open (filename_to.c_str());

    if(!infile)
    {
        cout << "Can not open input file " + filename_from << endl;
        exit(0);
    }

    if(!outfile)
    {
        cout << "Can not open Output file " + filename_to << endl;
        exit(0);
    }


    while( getline(infile, input))
    {
        outfile << EncryptString(cipher_key,  input) << endl;
    }
    infile.close();
    outfile.close();
}

// Decrypt the specified file using the specified cipher key and
// write the output to a different file
// This function is complete
void Crypto::DecryptFile(string cipher_key, 
    string filename_from, string filename_to)
{
    string input;
    ifstream infile;
    ofstream outfile;

    infile.open (filename_from.c_str());
    outfile.open (filename_to.c_str());

    if(!infile)
    {
        cout << "Can not open input file " + filename_from << endl;
        exit(0);
    }

    if(!outfile)
    {
        cout << "Can not open Output file " + filename_to << endl;
        exit(0);
    }


    while( getline(infile, input))
    {
        outfile << DecryptString(cipher_key,  input) << endl;
    }
    infile.close();
    outfile.close();
}
