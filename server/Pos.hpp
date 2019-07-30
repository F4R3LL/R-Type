#ifndef POS
# define POS

class Pos
{
	public:
		Pos(float sx = 0, float sy = 0) : x(sx), y(sy) {}
		Pos(const Pos & other) : x(other.x), y(other.y) {}

		~Pos() {};
		Pos getPos()const;
		const Pos &   operator=(const Pos & other);
		const Pos &   operator+(const Pos & other);
		const Pos &   operator-(const Pos & other);
		

	float x;
	float y;
};

#endif
