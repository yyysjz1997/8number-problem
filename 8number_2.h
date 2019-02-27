
// 8number_2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

//CWinApp≈……˙µƒ¿‡
// CMy8number_2App:
// See 8number_2.cpp for the implementation of this class
//

class CMy8number_2App : public CWinApp
{
public:
	CMy8number_2App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy8number_2App theApp;