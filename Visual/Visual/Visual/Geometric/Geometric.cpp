
#include "../Geometric/Geometric.h"

namespace Geo
{
	void CTMFORPOINT::Transform(double &x, double &y)
	{
		x = x*matrix[0] + y*matrix[1] + matrix[2];
		y = x*matrix[3] + y*matrix[4] + matrix[5];
	}
}