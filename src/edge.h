#include "site.h"

#ifndef __Edge__
#define __Edge__

class Site;
struct Edge{
	const Site *site1;
	const Site *site2;
	int name;
};

#endif // #ifndef __Edge__


