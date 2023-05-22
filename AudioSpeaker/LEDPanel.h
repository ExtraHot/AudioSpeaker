#include "SendVolToLED_if.h"
#include <systemc.h>
#include <iostream>

class MODULE_LEDPANEL : public sc_module, public SendVolToLED_if{
private:
	bool Led_status[5] = {1,1,1,1,1};
public:
	explicit MODULE_LEDPANEL(sc_module_name name);
	void sendLED(int vol) override;
	void LEDSTATUS(int vol);
};
