#ifndef TEST4
#define TEST4
#include "systemc.h"

class SendVolToLED_if : public sc_interface {
public:
	virtual void sendLED(int vol) = 0;
};
#endif // Test4
