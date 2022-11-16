#include "includes.hpp"
#include "hwids.hpp"

namespace auth {

    inline DWORD HWID = 0;

    inline bool access = 0;

    void antidebugger();

    bool IsProcessRunning(const TCHAR* const executableName);

    void hwidCheck();
}
