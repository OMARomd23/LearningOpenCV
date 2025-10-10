#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;

int main() {
    std::string path = "Resources/ronaldoAndMessi.jpg";
    std::string asciiRamp = " .`'^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$@█▓▒░"
        ;

    Mat img = imread(path);
    if (img.empty()) {
        std::cerr << "Error: Could not open or find the image." << std::endl;
        return -1;
    }

    int imageWidth = img.cols;   // Use actual image size
    int imageHeight = img.rows;
    double charAspect = 1; // Adjust if output looks too squashed or stretched
    int consoleWidth = 220;
    int consoleHeight = static_cast<int>((imageHeight / (double)imageWidth) * consoleWidth / charAspect);

    double scaleX = (double)imageWidth / consoleWidth;
    double scaleY = (double)imageHeight / (consoleHeight * charAspect);

    // Iterate over each console cell
    for (int y = 0; y < consoleHeight; ++y) {
        for (int x = 0; x < consoleWidth; ++x) {
            int srcX = std::min((int)(x * scaleX), imageWidth - 1);
            int srcY = std::min((int)(y * scaleY), imageHeight - 1);

            Vec3b pixel = img.at<Vec3b>(srcY, srcX); // safe access
            float R = pixel[2];
            float G = pixel[1];
            float B = pixel[0];

            float brightness = 0.2126 * R + 0.7152 * G + 0.0722 * B;
            int index = (int)(brightness * (asciiRamp.size() - 1) / 255.0);
            std::cout << "\033[38;2;" << R << ";" << G << ";" << B << "m"; 
            std::cout << asciiRamp[index];
        }
        std::cout << '\n';
    }
    std::cout << "\033[0m"; // final reset
    return 0;
}
