#ifndef DESCODER_H
#define DESCODER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DESCoder
{
public:
    DESCoder(vector<unsigned char> key);
    vector<unsigned char> encode(vector<unsigned char> data);
    vector<unsigned char> decode(vector<unsigned char> data);
    ~DESCoder();
private:
    vector<unsigned char> _process(vector<unsigned char> data, bool encode);
    vector<unsigned char> _dataBits;
    vector<vector<unsigned char> > _keys;

    vector<unsigned char> _left;
    vector<unsigned char> _right;

    void _IP();
    void _inverseIP();

    void _generateKeys(vector<unsigned char> key64);
    vector<unsigned char> _shiftKeyLeft(vector<unsigned char> key56, int numShifts);

    void _makeDesStep(vector<unsigned char> iKey);

    vector<unsigned char> _expansion();

    vector<unsigned char> _substitution(vector<unsigned char> right48);

    vector<unsigned char> _permutation(vector<unsigned char> right32);

    vector<unsigned char> _byteToBits(unsigned char byte);

    vector<unsigned char> _bytesArrayToBits(vector<unsigned char> bytes);

    unsigned char _bitsToByte(vector<unsigned char> bits);

    vector<unsigned char> _bitesArrayToBytes(vector<unsigned char> bites);
};

#endif // DES_H
