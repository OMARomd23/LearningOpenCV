/*
===============================================================================
    ASCII Art Generator - C++ + OpenCV
    -----------------------------------
    Author  : Saad Rabia
    Version : 1.0
    License : MIT
    Date    : 2025

    Description:
    ------------
    This program converts any image into a colored ASCII art representation 
    directly displayed in the terminal. It uses OpenCV to process image pixels 
    and ANSI escape codes to colorize characters according to the original 
    pixel RGB values.

    Requirements:
    -------------
    - OpenCV 4.x or later
    - Terminal supporting 24-bit ANSI colors
    - C++17 compiler

    Example usage:
    --------------
    > g++ -std=c++17 main.cpp -o ascii -lopencv_core -lopencv_imgproc -lopencv_imgcodecs
    > ./ascii
===============================================================================
*/

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;

int main() {
    // Path to the image (adjust to your setup)
    std::string path = "Resources/ronaldoAndMessi.jpg";

    // ASCII ramp sorted from brightest (left) to darkest (right)
    // More characters = higher detail in brightness representation
    std::string asciiRamp = 
        " .`'^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$@█▓▒░";

    // Load image using OpenCV
    Mat img = imread(path);
    if (img.empty()) {
        std::cerr << "Error: Could not open or find the image." << std::endl;
        return -1;
    }

    // Get original image dimensions
    int imageWidth = img.cols;
    int imageHeight = img.rows;

    // Character aspect ratio (fine-tune this if the output looks stretched)
    double charAspect = 1.0;

    // Set desired output width (number of characters per line)
    int consoleWidth = 220;

    // Automatically calculate height based on image aspect ratio
    int consoleHeight = static_cast<int>(
        (imageHeight / static_cast<double>(imageWidth)) * consoleWidth / charAspect
    );

    // Compute scaling factors between image pixels and console cells
    double scaleX = static_cast<double>(imageWidth) / consoleWidth;
    double scaleY = static_cast<double>(imageHeight) / (consoleHeight * charAspect);

    // Loop through each row (Y axis)
    for (int y = 0; y < consoleHeight; ++y) {
        // Loop through each column (X axis)
        for (int x = 0; x < consoleWidth; ++x) {
            
            // Map console coordinates to image coordinates (with safety bounds)
            int srcX = std::min(static_cast<int>(x * scaleX), imageWidth - 1);
            int srcY = std::min(static_cast<int>(y * scaleY), imageHeight - 1);

            // Access pixel color (BGR order in OpenCV)
            Vec3b pixel = img.at<Vec3b>(srcY, srcX);
            float R = pixel[2];
            float G = pixel[1];
            float B = pixel[0];

            // Compute perceived brightness (using Rec.709 luminance formula)
            float brightness = 0.2126f * R + 0.7152f * G + 0.0722f * B;

            // Map brightness (0–255) to ASCII ramp index
            int index = static_cast<int>(brightness * (asciiRamp.size() - 1) / 255.0f);

            // Print ASCII character with the pixel's original RGB color
            std::cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";
            std::cout << asciiRamp[index];
        }

        // New line after each console row
        std::cout << '\n';
    }

    // Reset color formatting at the end
    std::cout << "\033[0m";

    return 0;
}
