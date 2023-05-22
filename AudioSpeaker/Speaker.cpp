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
	fout << sc_time_stamp().to_string() << " MODULESPEAKER AcceptCommand() " << comand << "\t"<< "���������� �������� - ";
	
	if (comand % 4 == 0) fout << "���������� �����" << endl;
	if (comand % 4 == 1) fout << "����� �����" << endl;
	if (comand % 4 == 2) fout << "��������� ����������" << endl;
	if (comand % 4 == 3) fout << "��������� ��������" << endl;
	fout.close();
}
