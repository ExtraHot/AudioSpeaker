#include"LEDPanel.h"

MODULE_LEDPANEL::MODULE_LEDPANEL(sc_module_name name) : sc_module(name) {
	SC_HAS_PROCESS(MODULE_LEDPANEL);
}

void MODULE_LEDPANEL::sendLED(int vol) {
	ofstream fout("ReceiveVoltage_log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << " MODULE_LEDPANEL sendLED() " << vol << "%"<<endl;
	fout.close();
	LEDSTATUS(vol);
}

void  MODULE_LEDPANEL::LEDSTATUS(int vol)
{
	//ofstream fout("Speaker_Log.txt", ios::out | ios::app);
	//fout << sc_time_stamp().to_string() << ": С контроллера получена команда: " << comand << "\t" << "Выполнение действия - ";
	if (vol >= 80) Led_status[0] = 0;
	if (vol < 80 && vol>=60) Led_status[1] = 0;
	if (vol < 60 && vol>=40) Led_status[2] = 0;
	if (vol < 40 && vol>=20) Led_status[3] = 0;
	if (vol < 20) Led_status[4] = 0;

	ofstream fout("LEDSTATUS_log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << " MODULE_LEDPANEL " << "LEDSTATUS() ";
	for (int i = 0; i < 5; i++) fout<<"LED" << i << "-" << Led_status[i] << " ";
	fout << endl;
	fout.close();

}