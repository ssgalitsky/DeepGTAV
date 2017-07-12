/*
	THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
				http://dev-c.com			
			(C) Alexander Blade 2015
*/

#include "lib/script.h"
#include "lib/main.h"
#include "Scenario.h"

#include <fstream>

bool running = false;

void start_run(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow) {
	if (running || key != VK_SPACE) return;

	running = true;
}

void ScriptMain() {
	while (true){
		if (!running){
			WAIT(0);
			continue;
		}

		std::ofstream stream;
		stream.open("C:\\Users\\wuhuikai\\Documents\\message.txt");
		{
			Scenario scenario;
			scenario.start();
			for (int i = 0; i < 100; i++){
				scenario.run();
				// Message
				StringBuffer message = scenario.generateMessage();
				const char* chmessage = message.GetString();
				stream << chmessage << std::endl;
				// Image
				/*std::ofstream im_stream("image.bin", std::ios::out | std::ios::binary);
				im_stream.write(buffer, 100);*/
			}
			scenario.stop();
		}
		stream.close();

		running = false;
	}
}