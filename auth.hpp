#include "includes.hpp"
#include "hwids.hpp"

inline bool IsProcessRunning(const TCHAR* const executableName) {
	PROCESSENTRY32 a;
	a.dwSize = sizeof(PROCESSENTRY32);

	const auto b = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (!Process32First(b, &a)) {
		CloseHandle(b);
		return false;
	}

	do {
		if (!_tcsicmp(a.szExeFile, executableName)) {
			CloseHandle(b);
			return true;
		}
	} while (Process32Next(b, &a));

	CloseHandle(b);
	return false;
}

namespace auth {

	DWORD HWID = 0;

	bool access = 0;

	void antidebugger() { // super basic
		if ((IsProcessRunning(L"PETools.exe") ||
			IsProcessRunning(L"HxD.exe") ||
			IsProcessRunning(L"ResourceHacker.exe") ||
			IsProcessRunning(L"ProcessHacker.exe") ||
			IsProcessRunning(L"idaq32.exe") ||
			IsProcessRunning(L"httpdebugger.exe") ||
			IsProcessRunning(L"Fiddler Everywhere.exe") ||
			IsProcessRunning(L"ollydbg.exe") ||
			IsProcessRunning(L"tcpview.exe") ||
			IsProcessRunning(L"autoruns.exe") ||
			IsProcessRunning(L"autorunsc.exe") ||
			IsProcessRunning(L"filemon.exe") ||
			IsProcessRunning(L"procmon.exe") ||
			IsProcessRunning(L"idag.exe") ||
			IsProcessRunning(L"hookshark.exe") ||
			IsProcessRunning(L"peid.exe") ||
			IsProcessRunning(L"lordpe.exe") ||
			IsProcessRunning(L"regmon.exe") ||
			IsProcessRunning(L"idaq.exe") ||
			IsProcessRunning(L"idaq64.exe") ||
			IsProcessRunning(L"ImmunityDebugger.exe") ||
			IsProcessRunning(L"Wireshark.exe") ||
			IsProcessRunning(L"dumpcap.exe") ||
			IsProcessRunning(L"HookExplorer.exe") ||
			IsProcessRunning(L"LordPE.exe") ||
			IsProcessRunning(L"SysInspector.exe") ||
			IsProcessRunning(L"proc_analyzer.exe") ||
			IsProcessRunning(L"sysAnalyzer.exe") ||
			IsProcessRunning(L"sniff_hit.exe") ||
			IsProcessRunning(L"joeboxcontrol.exe") ||
			IsProcessRunning(L"joeboxserver.exe") ||
			IsProcessRunning(L"ida.exe") ||
			IsProcessRunning(L"HTTPDebuggerSvc.exe") ||
			IsProcessRunning(L"cheatengine-x86_64-SSE4-AVX2.exe") ||
			IsProcessRunning(L"cheatengine-i386.exe") ||
			IsProcessRunning(L"cheatengine-x86_64.exe") ||
			IsProcessRunning(L"windowrenamer.exe")))
		{
			ShowWindow(GetConsoleWindow(), SW_HIDE);
			MessageBox(NULL, L"nice try lol", L":)", MB_ICONERROR); /* you might want to remove this line since it technically keeps the program open and unprotected while the message box is running, leaving it vulnerable. */
			exit(0);
		}
	}

	void networkCheck() {
		char url[256];
		strcat(url, "https://1.1.1.1");
		bool isconnect = InternetCheckConnectionA(url, FLAG_ICC_FORCE_CONNECTION, 0);
		if (isconnect) { }
		else {
			ShowWindow(GetConsoleWindow(), SW_HIDE);
			MessageBox(NULL, L"No Internet Connection.", L"HWID Authentication Application", MB_ICONERROR);
			exit(0);
		}
	}

	void hwidCheck() {
		if (GetVolumeInformation(_T("C:\\"), 0, 0, &HWID, 0, 0, 0, 0))
			if (HWID == your_username) { bool access = true; }
			else if (HWID == example) { bool access = true; }
			else if (HWID == example2) { bool access = true; }
			else { std::cout << "Your HWID: " << HWID;
			while (true) { auth::antidebugger(); }
		}
	}
}