#ifndef TURRETMANUALCOMMUNICATIONMODULE_H
#define TURRETMANUALCOMMUNICATIONMODULE_H

#include "CommunicationModule.h"
#include "..\utility\CompileCondition.h"
#include "..\utility\CommonData.h"

class TurretManualCommunicationModule : public CommunicationModule
{
    public:
	TurretManualCommunicationModule(TypeList ht = HardwareType::TypeList::TURRET, char myAddress = TURRET_ADDRESS);

	~TurretManualCommunicationModule() override;

    protected:
	void write(char* const* data) override;

	void read(char* const* data) override;

    private:
	class DataPackConfig
	{
	    public:
		DataPackConfig() { }

		~DataPackConfig() { }

		void setting(char signal, char order, char sAddress) { _signal = signal; _order = order; _sAddress = sAddress;}

		char _signal;

		char _order;

		char _sAddress;
	};

	bool assemblePacket(char* const* packet, Data* assembleData);

	int createData(DataPackConfig* config, char** serialData);//return serial data size

	bool disAssemblePacket(char* const* packet, DataPackConfig* config, char** serialData, int remainSize, int offset);

	TypeList _ht;
};

#endif
