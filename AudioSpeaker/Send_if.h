#ifndef TEST
#define TEST
#include "systemc.h"

class Send_if : public sc_interface {
public:
	virtual void sendData(std::vector<unsigned char> data) = 0;
}; 
#endif // Test
