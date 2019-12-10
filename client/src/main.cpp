﻿#include "StdInc.h"
#include "main.h"
#include "COption.h"

int main(int argc, char** argv)
{
	COption* pOption = new COption();
	assert(pOption);

	if (!pOption->ParseOptions(argc, argv))
	{
		return 0;
	}

	CClient* pClient = new CClient(pOption->GetServerAddress(), pOption->GetServerPort());
	assert(pClient);

	if (pClient->TryConnect())
	{
		pClient->Run();

		pClient->Disconnect();
	}

	delete pOption;
	delete pClient;

	return 0;
}