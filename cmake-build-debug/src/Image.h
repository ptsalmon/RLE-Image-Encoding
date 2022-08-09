#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Header {
    char  idLength;
    char  colorMapType;
    char  dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char  colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char  bitsPerPixel;
    char  imageDescriptor;
};

// Image class declarations
class Image {
public:
    unsigned char* rawPixelData;
    unsigned int size;
    Image() = default;
    Header imageHeader;

    // Declare input/output functions
    void readImageData(string filename);
    void writeImageData(string filename);

    // Declare blend functions
    void multiply(Image img);
    void subtract(Image img);
    void screen(Image img);
    void overlay(Image img);
};