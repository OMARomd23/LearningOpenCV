# 🎨 ASCII Art Generator (C++ + OpenCV)

This project converts any image into **colored ASCII art** directly viewable in your terminal.  
It uses OpenCV for image processing and ANSI escape codes to colorize each ASCII character based on the original pixel colors.

---

## 🚀 Features
- 🖼 Converts any image into ASCII characters
- 🌈 Supports **true RGB colors** in the terminal
- ⚙️ Automatically scales the image to fit your console
- 🧮 Brightness-based ASCII mapping for accurate results
- 🧠 Easy to customize: you can change the ASCII ramp, size, or scaling

---

## 🧰 Requirements

Make sure you have:
- **C++17 or later**
- **OpenCV 4.x** installed
- A terminal that supports **ANSI 24-bit colors**

---

## 🛠️ Installation

### 1. Clone the repository:
```bash
git clone https://github.com/YOUR_USERNAME/ascii-art-generator.git
cd ascii-art-generator
```

### 2. Build the project:
If you’re using **g++**:
```bash
g++ -std=c++17 main.cpp -o ascii -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui
```

If you’re using **CMake**, create a `CMakeLists.txt`:
```cmake
cmake_minimum_required(VERSION 3.10)
project(AsciiArt)
find_package(OpenCV REQUIRED)
add_executable(AsciiArt main.cpp)
target_link_libraries(AsciiArt ${OpenCV_LIBS})
```
Then:
```bash
mkdir build && cd build
cmake ..
make
```

---

## 🖼️ Usage
Place your image in the `Resources` folder (or adjust the path in code):
```cpp
std::string path = "Resources/ronaldoAndMessi.jpg";//here you can put the image path
```

Then run:
```bash
./ascii
```

You’ll see a beautiful ASCII representation of your image in the console 🌈

---

## ⚙️ Customization

You can tweak the ASCII ramp for more or less brightness sensitivity:
```cpp
std::string asciiRamp = " .`'^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$@█▓▒░";
```

You can also change output size:
```cpp
int consoleWidth = 100; // wider output
```

---

## 🧑‍💻 Example Output
<img width="474" height="813" alt="Screenshot 2025-10-10 162439" src="https://github.com/user-attachments/assets/fe787da5-2a51-464c-a046-3e24caaf74d8" />



## 🧩 Future Improvements
- Add **auto-detection** for terminal width/height
- Add **grayscale preview** mode
- Add **video-to-ASCII** conversion

---

## 📜 License
This project is open-source under the **MIT License**.

---

## 💡 Author
**Saad Rabia**  
Passionate about C++, graphics, and visual computing.
