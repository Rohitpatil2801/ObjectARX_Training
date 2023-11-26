// Project1.h : main header file for the Project1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"	
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>


// CProject1App
// See Project1.cpp for the implementation of this class
//

class CProject1App : public CWinApp
{
public:
	CProject1App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void MyCommand();

	DECLARE_MESSAGE_MAP()
};
