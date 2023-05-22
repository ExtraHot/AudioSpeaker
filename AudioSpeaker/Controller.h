#include "Send_if.h"
#include "SendCom_if.h"
#include "SendVol_if.h"
#include "SendVolToLED_if.h"
#include <systemc.h>

class MODULE_CONTROLLER : public sc_module, public Send_if,public SendVol_if {
	int CommandSum;
public:

	sc_port<SendCom_if> out_port2;
	sc_port<SendVolToLED_if> out_port3;
	explicit MODULE_CONTROLLER(sc_module_name name);
	void sendData(std::vector<unsigned char> data) override;
	void CreateCommand(std::vector<unsigned char> data);
	void SendVoltage(int Vol) override;
};