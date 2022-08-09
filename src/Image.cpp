#include "Image.h"
#include <fstream>
#include <iostream>

using namespace std;

//Image blending functions

//Multiply function
//Variable names in accordance
//with formulas obtained from:
//https://en.wikipedia.org/wiki/Blend_modes
void Image::multiply(Image img) {
    for (int i = 0; i < size; i++){
        float a = rawPixelData[i]/255.0;
        float b = img.rawPixelData[i]/255.0;
        float ab = (a*b)*255.0+0.5f;
        if (ab > 255.0)
            ab = 255.0;
        else if (ab < 0)
            ab = 0;
        rawPixelData[i] = (unsigned char)ab;
    }
}

//Subtract function
void Image::subtract(Image img) {
    for (int i = 0; i < size; i++) {
        float subColor = (int)img.rawPixelData[i] - (int)rawPixelData[i] + 0.5f;
        if (subColor < 0) subColor = 0;
        rawPixelData[i] = (unsigned char)subColor;
    }
}

//Screen function
//Variable names in accordance
//with formulas obtained from:
//https://en.wikipedia.org/wiki/Blend_modes
void Image::screen(Image img) {
    for (int i = 0; i < size; i++) {
        float a = rawPixelData[i]/255.0;
        float b = img.rawPixelData[i]/255.0;
        float screenValue = 1 - (1-a)*(1-b);
        screenValue *= 255.0;
        screenValue += 0.5f;
        if (screenValue > 255)
            screenValue = 255;
        else if (screenValue < 0)
            screenValue = 0;
        rawPixelData[i] = (unsigned char)screenValue;
    }
}


//Overlay function
//Variable names in accordance
//with formulas obtained from:
//https://en.wikipedia.org/wiki/Blend_modes
void Image::overlay(Image img) {
    for (int i = 0; i < size; i++) {
        float a = ((float)rawPixelData[i]);
        float b = ((float)img.rawPixelData[i]);
        if (a < 127) {
            float product = (2*a*b);
            if (product/255.0 > 255)
                rawPixelData[i] = (unsigned char)255;
            else if (product < 0)
                rawPixelData[i] = (unsigned char)0;
            else
                rawPixelData[i] = (unsigned char)(product/255.0+0.5f);
        } else {
            float screenValue = 1 - 2*(1-a/255)*(1-b/255);
            if (screenValue > 1)
                rawPixelData[i] = (unsigned char)255;
            else if (screenValue < 0)
                rawPixelData[i] = (unsigned char)0;
            else
                rawPixelData[i] = (unsigned char)(screenValue*255.0+0.5f);
        }
    }
}

void Image::readImageData(string filename) {
    ifstream inputStream(filename);
    streampos begin, end;
    begin = inputStream.tellg();
    inputStream.seekg(0,ios::end);
    end = inputStream.tellg();
    size = (end-begin)-18;
    inputStream.seekg(0);
    inputStream.read(&imageHeader.idLength, 1);
    inputStream.seekg(1);
    inputStream.read(&imageHeader.colorMapType, 1);
    inputStream.seekg(2);
    inputStream.read(&imageHeader.dataTypeCode, 1);
    inputStream.seekg(3);
    inputStream.read((char*)&imageHeader.colorMapOrigin, 2);
    inputStream.seekg(5);
    inputStream.read((char*)&imageHeader.colorMapLength, 2);
    inputStream.seekg(7);
    inputStream.read(&imageHeader.colorMapDepth, 1);
    inputStream.seekg(8);
    inputStream.read((char*)&imageHeader.xOrigin, 2);
    inputStream.seekg(10);
    inputStream.read((char*)&imageHeader.yOrigin, 2);
    inputStream.seekg(12);
    inputStream.read((char*)&imageHeader.width, 2);
    inputStream.seekg(14);
    inputStream.read((char*)&imageHeader.height, 2);
    inputStream.seekg(16);
    inputStream.read(&imageHeader.bitsPerPixel, 1);
    inputStream.seekg(17);
    inputStream.read(&imageHeader.imageDescriptor, 1);
    inputStream.seekg(18);

    rawPixelData = new unsigned char [size];
    inputStream.read((char*)rawPixelData, size);
}

//Write image function
//writes image data to .tga file
void Image::writeImageData(string filename) {
    ofstream outputStream;

    // write image header
    outputStream.open(filename,ios_base::binary);
    outputStream.write(&imageHeader.idLength, 1);
    outputStream.write(&imageHeader.colorMapType, 1);
    outputStream.write(&imageHeader.dataTypeCode, 1);
    outputStream.write((char*)&imageHeader.colorMapOrigin, 2);
    outputStream.write((char*)&imageHeader.colorMapLength, 2);
    outputStream.write(&imageHeader.colorMapDepth, 1);
    outputStream.write((char*)&imageHeader.xOrigin, 2);
    outputStream.write((char*)&imageHeader.yOrigin, 2);
    outputStream.write((char*)&imageHeader.width, 2);
    outputStream.write((char*)&imageHeader.height, 2);
    outputStream.write(&imageHeader.bitsPerPixel, 1);
    outputStream.write(&imageHeader.imageDescriptor, 1);

    //write image pixel data
    outputStream.write((char*)rawPixelData,size);
}