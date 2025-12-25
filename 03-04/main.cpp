#include <iostream>
#include <memory>

class IShape
{
protected:
    float area_;

public:
    IShape() : area_(0) {}

    virtual void Size() = 0;
    virtual void Draw() = 0;

    virtual ~IShape() {}
};

class Circle : public IShape
{
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    void Size() override
    {
        area_ = radius * radius * 3.14f;
    }

    void Draw() override
    {
        std::cout << "Circle " << area_ << std::endl;
    }
};

class Rectangle : public IShape
{
private:
    float width_;
    float height_;

public:
    Rectangle(float w, float h) : width_(w), height_(h) {}

    void Size() override
    {
        area_ = width_ * height_;
    }

    void Draw() override
    {
        std::cout << "Rectangle " << area_ << std::endl;
    }
};

int main()
{
    std::unique_ptr<IShape> circle = std::make_unique<Circle>(5.0f);
    std::unique_ptr<IShape> rect = std::make_unique<Rectangle>(4.0f, 6.0f);

    circle->Size();
    circle->Draw();

    rect->Size();
    rect->Draw();

    return 0;
}