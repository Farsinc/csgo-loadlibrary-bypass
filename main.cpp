#include <Windows.h>

HWND hwnd = 0;
DWORD procid;
HANDLE hProcess;

int main()
{
	hwnd = FindWindowA(NULL, "Counter-Strike: Global Offensive - Direct3D 9");
	if (hwnd != 0)
	{
		GetWindowThreadProcessId(hwnd, &procid);
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procid);
		LPVOID ntOpenFile = GetProcAddress(LoadLibraryW(L"ntdll"), "NtOpenFile");
		if (ntOpenFile) {
			char originalBytes[5];
			memcpy(originalBytes, ntOpenFile, 5);
			WriteProcessMemory(hProcess, ntOpenFile, originalBytes, 5, NULL);
		}
		system("pause");
	}
}
