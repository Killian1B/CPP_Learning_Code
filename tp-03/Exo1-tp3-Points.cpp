#include <vector>

struct AbsolutePoint {
  double x = 0.0, y = 0.0;
};

AbsolutePoint default_origin;

class RelativePoint {
  const AbsolutePoint& _origin;
  AbsolutePoint        _shift;
  
public:
  RelativePoint(const AbsolutePoint shift, const AbsolutePoint& origin = default_origin) :
    _origin { origin },
    _shift { shift }
  {}

  RelativePoint() :
    RelativePoint(default_origin)
  {}


  double get_x() const { return _origin.x + _shift.x; }
  double get_y() const { return _origin.y + _shift.y; }
};

int main()
{
    std::vector<RelativePoint>(3);
    std::vector<AbsolutePoint>(3);
}