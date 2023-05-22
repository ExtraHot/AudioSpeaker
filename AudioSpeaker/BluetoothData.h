#include "systemc.h"
#include "Send_if.h"
#include <random>
#include <fstream>

using namespace std;
using namespace sc_core;

class MODULE_Blutooth : public sc_module {
	vector<unsigned char> data;
	sc_event e_gen;
	int count_enum;
	random_device rd;
	
public:
	sc_port<Send_if> out_port;
	explicit MODULE_Blutooth(sc_module_name name);
	void gen_and_send_data();
};