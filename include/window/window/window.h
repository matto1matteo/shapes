#include "shapes/shapes.h"
#include <istream>
#include <string>
#include <vector>

class Window
{
public:
    Window() = default;
    Window(Window &&) = default;
    Window(const Window &) = default;
    Window &operator=(Window &&) = default;
    Window &operator=(const Window &) = default;
    ~Window() = default;

    static Window FromConfigFile(std::string config_file);
    static Window FromStream(std::istream & input);

    // Accessors
    const int GetWidth() const { return m_Width; }
    const int GetHeigth() const { return m_Height; }

    void SetFont(std::string font);

private:
    int m_Width;
    int m_Height;
    std::vector<Shape *> m_Shapes;
    std::string m_Font;
};

