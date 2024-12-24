#include "main.h"
#include "credentials.h"

Button	Btn1(BTN_1, 80);
Button	Btn2(BTN_2, 80);
Led		LedRed(RED_LED);
Led		LedGrn(GRN_LED);
Led		LedBlu(BLU_LED);
WiFiHandler wifi_handler("esp-leds-player");

void setup() {
	LedRed.set();
	LedGrn.set();
	LedBlu.set();
	console.header(DOUBLE_DASHED, LOG_BLUE, 80, "START INITIALIZATION");
	console.info(MAIN_T, "ESP32 Chip Model: " + String(ESP.getChipModel()));
	console.info(MAIN_T, "ESP32 Flash Size: " + String(ESP.getFlashChipSize()));
	console.info(MAIN_T, "Compile Date: " + String(__DATE__));
	console.info(MAIN_T, "Compile Time: " + String(__TIME__));
	wifi_handler.setCredentials(my_ssid, my_password);
	wifi_handler.onConnect([]{ console.success(MAIN_T, "Wi-Fi connected!"); });
	wifi_handler.onDisconnect([]{ console.warning(MAIN_T, "Wi-Fi disconnected!"); });
	wifi_handler.begin(WIFI_STA);
	console.header(DOUBLE_DASHED, LOG_BLUE, 80, "END INITIALIZATION");
	LedRed.reset();
	LedGrn.reset();
	LedBlu.reset();
}

void loop() {
	Btn1.loop();
	Btn2.loop();
}