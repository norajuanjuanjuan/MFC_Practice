
// MFC_Practice.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_PracticeApp:
// See MFC_Practice.cpp for the implementation of this class
//

class CMFC_PracticeApp : public CWinApp
{
public:
	CMFC_PracticeApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnClickAbout();
};

extern CMFC_PracticeApp theApp;