#ifndef TEST3
#define TEST3
#include "systemc.h"

class SendVol_if : public sc_interface {
public:
	virtual void SendVoltage(int Vol) = 0;
};
#endif // Test3
