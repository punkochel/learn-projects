#include <cstdio>

class GraphObject {
protected:
    double x, y;
    int color;
public:
    GraphObject(double ax, double ay, int acolor)
        : x(ax), y(ay), color(acolor) {};
    virtual ~GraphObject() {};
    virtual void Show() = 0;
    virtual void Hide() = 0;
    void Move(double ax, double ay);
};

class Pixel : public GraphObject {
public:
    Pixel(double x, double y, int color)
        : GraphObject(x, y, color) {};
    virtual ~Pixel() {}
    virtual void Show();
    virtual void Hide();
};

class Circle : public GraphObject {
    double radius;
public:
    Circle(double x, double y, int color, double aradius)
        : GraphObject(x, y, color), radius(aradius) {};
    virtual ~Circle() {}
    virtual void Show();
    virtual void Hide();
};

void GraphObject::Move(double ax, double ay)
{
    Hide();
    x = ax;
    y = ay;
    Show();
}

void Pixel::Show()
{
    printf("[Pixel Show] x = %.2f, y = %.2f, color = %d\n", x, y, color);
}

void Pixel::Hide()
{
    printf("[Pixel Hide] x = %.2f, y = %.2f, color = %d\n", x, y, color);
}

void Circle::Show()
{
    printf("[Circle Show] x = %.2f, y = %.2f, radius = %.2f, color = %d\n",
        x, y, radius, color);
}

void Circle::Hide()
{
    printf("[Circle Hide] x = %.2f, y = %.2f, radius = %.2f, color = %d\n",
        x, y, radius, color);
}

int main()
{
    Pixel px(0.0, 0.0, 255);
    Circle cr(0.0, 0.0, 128, 10.0);
    px.Move(5.0, 7.0);
    cr.Move(30.0, 50.0);
    return 0;
}
