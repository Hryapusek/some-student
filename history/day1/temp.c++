

class Point {
  public:
    Point(double x = 0, double y = 0);

    // Point p4 = p2;
    // Конструктор копирования
    Point(Point const& other) = default;

    // эта функция может быть вызвана 
    // ТОЛЬКО относительно конкретного объекта точки
    float distance(Point other);

    // Не относительно объекта
    static float distanceStatic(Point p1, Point p2);

    double getX();
    double getY();

    void setX(double newX);
    void setY(double newY);

  private:
    // Свойства точки
    double x;
    double y;
};


/// CPP
void Point::setX(double newX)
{
  x = newX;
}

void Point::setY(double newY)
{
  y = newY;
}


Point::Point(double x, double y)
{
  this->x = x;
  this->y = y;//
}


double Point::getX()
{
  return x;
}

double Point::getY()
{
  return y;
}

class Point2 {};

int main()
{
  Point p1, p2;
  int a = sizeof(Point);
  Point p3(0, 2);
  Point2 p21;
  p1.getX();
  p1.distance(p2);

  Point p4 = p2;

  p1.distanceStatic(p1, p2);
  Point::distanceStatic(p1, p2);
}
