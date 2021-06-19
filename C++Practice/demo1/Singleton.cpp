#include "Singleton.h"
Singleton* Singleton::This = NULL;
const Singleton* Singleton::getInstance() {
	if (!This)
	{
		This = new Singleton;
	}
	return This;
}
