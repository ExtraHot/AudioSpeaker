#include"Speaker.h"

MODULE_SPEAKER::MODULE_SPEAKER(sc_module_name name) : sc_module(name) {
	SC_HAS_PROCESS(MODULE_SPEAKER);
}

void MODULE_SPEAKER::sendCommand(int command) {
	setlocale(LC_ALL, "Russian");
	AcceptCommand(command);
}

void  MODULE_SPEAKER::AcceptCommand(int comand)
{
	ofstream fout("Speaker_Log.txt", ios::out | ios::app);
	fout << sc_time_stamp().to_string() << " MODULESPEAKER AcceptCommand() " << comand << "\t"<< "Выполнение действия - ";
	
	if (comand % 4 == 0) fout << "Поставлена пауза" << endl;
	if (comand % 4 == 1) fout << "Снята пауза" << endl;
	if (comand % 4 == 2) fout << "Громкость прибавлена" << endl;
	if (comand % 4 == 3) fout << "Громкость убавлена" << endl;
	fout.close();
}
