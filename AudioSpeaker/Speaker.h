#include "SendCom_if.h"
#include <systemc.h>

class MODULE_SPEAKER : public sc_module, public SendCom_if {
public:
	explicit MODULE_SPEAKER(sc_module_name name);
	void sendCommand(int command) override;
	void AcceptCommand(int comand);
};
