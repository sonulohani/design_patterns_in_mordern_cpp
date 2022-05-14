#include <iostream>

using namespace std;

template<typename T>
class BaseImage
{
public:
    void Draw()
    {
        static_cast<T*>(this)->Draw();
    }
};

class PngImage : public BaseImage<PngImage>
{
public:
    void Draw()
    {
        std::cout << "PngImage Called\n";
    }
};

class JpegImage : public BaseImage<JpegImage>
{
public:
    void Draw()
    {
        std::cout << "JPEGImage Called\n";
    }
};

int main()
{
    BaseImage<PngImage> png_image;
    png_image.Draw();

    BaseImage<JpegImage> jpeg_image;
    jpeg_image.Draw();

    return 0;
}
