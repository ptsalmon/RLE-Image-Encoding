#include <iostream>
#include <fstream>
#include "Image.h"

using namespace std;

int main() {
    //main program function
    //run through every part

    // Part 1
    cout << "Part 1: Multiply layer1 and pattern1" << endl;
    Image layer1, pattern1;
    layer1.readImageData("input/layer1.tga");
    pattern1.readImageData("input/pattern1.tga");
    layer1.multiply(pattern1);
    layer1.writeImageData("output/part1.tga");

    // Part 2
    cout << "Part 2: Subtract car from layer2" << endl;
    Image layer2, car;
    //get layer2 and car data
    layer2.readImageData("input/layer2.tga");
    car.readImageData("input/car.tga");
    //subtract car from layer2
    layer2.subtract(car);
    layer2.writeImageData("output/part2.tga");

    // Part 3
    cout << "Part 3: Multiply layer1 and pattern2, then Screen with text" << endl;
    Image layer1_p3,pattern2,text;
    //get layer1 and pattern2 data
    layer1_p3.readImageData("input/layer1.tga");
    pattern2.readImageData("input/pattern2.tga");
    //multiply layer1 and pattern2
    layer1_p3.multiply(pattern2);
    text.readImageData("input/text.tga");
    // screen text with layer1_p3
    text.screen(layer1_p3);
    text.writeImageData("output/part3.tga");

    // Part 4
    cout << "Part 4: Multiply layer2 and circles, then subtract result from pattern2" << endl;
    Image circles, layer2_p4,pattern2_p4;
    layer2_p4.readImageData("input/layer2.tga");
    circles.readImageData("input/circles.tga");
    // multiply layer2 and circles
    layer2_p4.multiply(circles);
    pattern2_p4.readImageData("input/pattern2.tga");
    // subtract layer 2 from pattern 2
    pattern2_p4.subtract(layer2_p4);
    pattern2_p4.writeImageData("output/part4.tga");

    // Part 5
    // admittedly this does not work
    // but i'm going to leave it in anyway
    cout << "Part 5: Overlay layer1 and pattern1" << endl;
    Image layer1_p5, pattern1_p5;
    //get data for layer1 and pattern1
    layer1_p5.readImageData("input/layer1.tga");
    pattern1_p5.readImageData("input/pattern1.tga");
    //overlay layer1 and pattern1
    layer1_p5.overlay(pattern1_p5);
    layer1_p5.writeImageData("output/part5.tga");

    // Part 6
    cout << "Part 6: Load car and add 200 to the green channel" << endl;
    Image car_p6;
    car_p6.readImageData("input/car.tga");
    //for loop adds to green channel
    for (int i = 1; i < car_p6.size; i+=3) {
        if (car_p6.rawPixelData[i] + 200 > 255)
            car_p6.rawPixelData[i] = 255;
        else
            car_p6.rawPixelData[i] += 200;
    }
    car_p6.writeImageData("output/part6.tga");

    // Part 7
    cout << "Part 7: Load car and multiply red by 4, blue by 0" << endl;
    Image car_p7;
    car_p7.readImageData("input/car.tga");
    //Multiply red channel by 4 and get rid of blue channel
    for (int i=0; i < car_p7.size; i+=3) {
        car_p7.rawPixelData[i] = 0;
        if (car_p7.rawPixelData[i+2]*4 > 255)
            car_p7.rawPixelData[i+2] = 255;
        else
            car_p7.rawPixelData[i+2] *= 4;
    }
    car_p7.writeImageData("output/part7.tga");

    // Part 8
    cout << "Part 8: Load car and separate each color channel into separate files" << endl;
    Image part8_b, part8_g, part8_r;
    part8_b.readImageData("input/car.tga");
    part8_g.readImageData("input/car.tga");
    part8_r.readImageData("input/car.tga");
    //Set color data for every channel equal to separate color channel data
    for (int i = 0; i < part8_b.size; i+=3) { part8_b.rawPixelData[i+1] = part8_b.rawPixelData[i]; part8_b.rawPixelData[i+2] = part8_b.rawPixelData[i]; }
    for (int i = 0; i < part8_g.size; i+=3) { part8_g.rawPixelData[i] = part8_g.rawPixelData[i+1]; part8_g.rawPixelData[i+2] = part8_g.rawPixelData[i+1]; }
    for (int i = 0; i < part8_r.size; i+=3) { part8_r.rawPixelData[i] = part8_r.rawPixelData[i+2]; part8_r.rawPixelData[i+1] = part8_r.rawPixelData[i+2]; }
    // write imageData to output
    part8_b.writeImageData("output/part8_b.tga");
    part8_g.writeImageData("output/part8_g.tga");
    part8_r.writeImageData("output/part8_r.tga");

    // Part 9
    cout << "Part 9: Load layer_blue, layer_green, layer_red and combine them" << endl;
    Image combined, layer_green, layer_red;
    combined.readImageData("input/layer_blue.tga");
    layer_green.readImageData("input/layer_green.tga");
    layer_red.readImageData("input/layer_red.tga");
    // add green and red channels to original combined image
    for (int i = 0; i < combined.size; i+=3) {
        combined.rawPixelData[i+1] = layer_green.rawPixelData[i+1];
        combined.rawPixelData[i+2] = layer_red.rawPixelData[i+2];
    }

    // Part 10
    cout << "Part 10: Load text2 and flip it 180 degrees" << endl;
    Image text2;
    text2.readImageData("input/text2.tga");
    unsigned char* reversedData = new unsigned char [text2.size];
    for (int i = 0; i < text2.size; i+=3) {
        reversedData[i] = text2.rawPixelData[text2.size-i-3];
        reversedData[i+1] = text2.rawPixelData[text2.size-i-2];
        reversedData[i+2] = text2.rawPixelData[text2.size-i-1];
    }
    for (int i = 0; i < text2.size; i++) {
        text2.rawPixelData[i] = reversedData[i];
    }
    text2.writeImageData("output/part10.tga");

    // extra credit
    cout << "Extra Credit: Combine car, circles, pattern1, and text" << endl;
    Image combo, car_ec, circles_ec, pattern1_ec, text_ec;
    combo.readImageData("input/car.tga");
    car_ec.readImageData("input/car.tga");
    circles_ec.readImageData("input/circles.tga");
    pattern1_ec.readImageData("input/pattern1.tga");
    text_ec.readImageData("input/text.tga");
    combo.imageHeader.width *= 2;
    combo.imageHeader.height *= 2;
    combo.size *= 4;
    unsigned char* tempData = new unsigned char [combo.size];
    // for loop for square one (text.tga)
    for (int i = 0; i < (3*512)*512; i+=(3*512)) {
        for (int j=0; j<3*512;j++){
            tempData[2*i+j] = text_ec.rawPixelData[i+j];
        }
    }
    // for loop for square two (pattern1.tga)
    for (int i = 0; i < (3*512)*512; i+=(3*512)) {
        for (int j=0; j<3*512; j++){
            tempData[2*i+j+3*512] = pattern1_ec.rawPixelData[i+j];
        }
    }
    // for loop for square three (car.tga)
    for (int i = ((3*512)*512); i < 2*((3*512)*512); i+=(3*512)) {
        for (int j=0; j<3*512;j++) {
            tempData[2*i+j] = car_ec.rawPixelData[i+j-((3*512)*512)];
        }
    }
    // for loop for square four (circles.tga)
    for (int i = ((3*512)*512); i < 2*((3*512)*512); i+=(3*512)) {
        for (int j=0; j<3*512; j++){
            tempData[2*i+j+3*512] = circles_ec.rawPixelData[i+j-((3*512)*512)];
        }
    }
    // set pixel data equal to tempData
    combo.rawPixelData = new unsigned char[combo.size];
    for (int i = 0; i < combo.size; i++) {
        combo.rawPixelData[i] = tempData[i];
    }
    //write to output file
    combo.writeImageData("output/extracredit.tga");

    return 0;
}