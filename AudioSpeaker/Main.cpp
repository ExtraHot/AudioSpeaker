#include <systemc.h>
#include <iostream>
#include "BluetoothData.h"
#include "Controller.h"
#include "Speaker.h"
#include "Battery.h"
#include "LEDPanel.h"


using namespace sc_core;
using namespace std;

int sc_main(int argc, char* argv[]) {

	srand(time(NULL));
	MODULE_Blutooth bluetooth("Bluetooth");
	MODULE_CONTROLLER controller("control");
	MODULE_SPEAKER speaker("speaker");
	MODULE_BATTERY battery("battery");
	MODULE_LEDPANEL LED("LED");
	
	bluetooth.out_port.bind(controller);
	battery.out_portV.bind(controller);
	controller.out_port2.bind(speaker);
	controller.out_port3.bind(LED);

	sc_start(0.2, SC_SEC);

	return 0;
}