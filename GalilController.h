#pragma once
#include <string>
namespace WMRA
{
	class GalilController {
	public:
		GalilController(); // sets initialized to false
		~GalilController(); // closes socket communication
		bool initialize(); // Initializes socket communication
		bool isInitialized(); // return initialized
		std::string command(std::string Command); // user command structure, used by MotorController

	private:
		static std::string IP; // IP address of the Galil Controller
		static bool initialized; // Flag that is set when socket communication has been achieved
		static bool setDefaults(); // set defaults
		static bool initializeSocket(std::string IP); // sets up socket communication, sets initialized
		static int commandGalil(char* Command, char* Response, int ResponseSize); // Galil Controller command structure, used by command()
		static client_tcpsocket sock; // The socket class used to communicate with galil controller
	};

}