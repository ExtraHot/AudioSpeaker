#ifndef TEST2
#define TEST2
#include "systemc.h"

class SendCom_if : public sc_interface {
public:
	virtual void sendCommand(int command) = 0;
};
#endif // Test2