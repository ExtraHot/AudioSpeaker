
#include "BluetoothData.h"

MODULE_Blutooth::MODULE_Blutooth(sc_module_name name) :
	sc_module(name),
	count_enum(0) {
	data.resize(10);
	SC_HAS_PROCESS(MODULE_Blutooth);
	SC_METHOD(gen_and_send_data);
	sensitive << e_gen;
}

void MODULE_Blutooth::gen_and_send_data() {
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 255);

	for (auto& byte : data) {
		int randomNum = dist(gen);
		byte = randomNum;
	}

	ofstream fout("GenBluetooth_log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << " MODULE_Blutooth gen_and_send_data() ";
	for (auto& byte : data) {
		fout << static_cast<int>(byte) << " ";
	}

	fout.close();
	++count_enum;
	out_port->sendData(data);
	e_gen.notify(2, SC_MS);
}