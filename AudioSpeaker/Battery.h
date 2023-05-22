#include "systemc.h"
#include "SendVol_if.h"
#include <random>

using namespace std;
using namespace sc_core;

class MODULE_BATTERY : public sc_module {
	int volt;
	sc_event voltage_gen;
	int count_enum;
	//random_device rd;

public:
	sc_port<SendVol_if> out_portV;
	explicit MODULE_BATTERY(sc_module_name name);
	void gen_and_send_voltage();
};