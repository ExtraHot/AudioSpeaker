#include "Battery.h"

MODULE_BATTERY::MODULE_BATTERY(sc_module_name name) :
	sc_module(name),
	count_enum(100) {
	SC_HAS_PROCESS(MODULE_BATTERY);
	SC_METHOD(gen_and_send_voltage);
	sensitive << voltage_gen;
}

void MODULE_BATTERY::gen_and_send_voltage() {
	volt = count_enum;
	--count_enum;
	ofstream fout("GenerateVoltage_log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << " MODULE_BATTERY gen_and_send_voltage() " << volt <<"%"<<endl;
	fout.close();
	out_portV->SendVoltage(volt);
	voltage_gen.notify(2, SC_MS);
}