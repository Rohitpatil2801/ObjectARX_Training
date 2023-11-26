// Object_intro.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Project1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <tchar.h>
#include "rxregsvc.h"
#include "acutads.h"
#include "accmd.h"
#pragma comment(linker,"/EXPORT:acrxEntryPoint")
#pragma comment(linker,"/EXPORT:acrxGetApiVersion")

#include "rxregsvc.h"
#include "acutads.h"
#include "aced.h"
#include "acdb.h"
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <aced.h>
#include <dbents.h>
#include <dbsymtb.h>
#include <adslib.h>
#include <geassign.h>
#include <dbidmap.h>
#include <dbapserv.h>
#include <acgi.h>
#include "tchar.h"
#include "dbents.h"
#include "acedCmdNF.h"


void CProject1App::MyCommand() {
    acutPrintf(_T("\n Hello in the World of AutoCAD"));
}

extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
    switch (Msg) {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        // below line for registering new command
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CProject1App::MyCommand);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}



// CObjectintroApp

BEGIN_MESSAGE_MAP(CProject1App, CWinApp)
END_MESSAGE_MAP()


// CObjectintroApp construction

CProject1App::CProject1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectintroApp object

CProject1App theApp;


// CObjectintroApp initialization

BOOL CProject1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}