#pragma once
#include <windows.h>
#include <string>
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>
using namespace std;
#define BUFSIZE 4096


class PipedProcess
{
public:
	PipedProcess(const TCHAR* cmd, const TCHAR* infile);
	~PipedProcess();
private:
	TCHAR * m_cmd;
	HANDLE g_hChildStd_IN_Rd = NULL;
	HANDLE g_hChildStd_IN_Wr = NULL;
	HANDLE g_hChildStd_OUT_Rd = NULL;
	HANDLE g_hChildStd_OUT_Wr = NULL;

	HANDLE g_hInputFile = NULL;
public:
	BOOL run();
private:
	void CreateChildProcess(TCHAR * szCmdline);
	void WriteToPipe();
	void ReadFromPipe();
	void ErrorExit(PTSTR lpszFunction);
	TCHAR * m_inFile;
};

