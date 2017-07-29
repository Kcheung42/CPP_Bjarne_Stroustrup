#ifndef MAIN_H
#define MAIN_H

struct Vector{
	int sz;
	double *elem;
};

class Vector_2
{
	public:
		Vector_2(int s);
		double &operator[](int i);
		int size();
	private:
		double *elem;
		int sz;
};
#endif
