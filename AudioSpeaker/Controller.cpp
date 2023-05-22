#include"Controller.h"
#include <numeric>
#include <fstream>

MODULE_CONTROLLER::MODULE_CONTROLLER(sc_module_name name) : sc_module(name) {
	SC_HAS_PROCESS(MODULE_CONTROLLER);

}

void MODULE_CONTROLLER::sendData(std::vector<unsigned char> data) {

	ofstream fout("ControllerData_log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << ": MODULE_CONTROLLER \t" << "SendData() ";
	for (auto& byte : data) {
		fout << static_cast<int>(byte) << " ";
	}
	fout << std::endl;
	fout.close();

	CreateCommand(data);
}

void MODULE_CONTROLLER::CreateCommand(std::vector<unsigned char> data)
{
	for (auto& byte : data) {
		if (byte < 63) byte = 0;
		if (byte < 126 && byte > 62) byte = 1;
		if (byte < 190 && byte >125) byte = 2;
		if (byte < 255 && byte > 189) byte = 3;
	}
	CommandSum = std::accumulate(data.begin(), data.end(),
		decltype(data)::value_type(0));
	out_port2->sendCommand(CommandSum);

	ofstream fout("CreateCommand_log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << ": MODULE_CONTOLLER \t" << "Create_command() ";
	for (auto& byte : data) {
		fout << static_cast<int>(byte) << " ";
	}
	fout << std::endl;
	fout.close();
}

void MODULE_CONTROLLER::SendVoltage(int vol) {
	//cout << sc_time_stamp().to_string() << " Текущий заряд: " << vol <<" %" << endl;
	out_port3->sendLED(vol);
}
