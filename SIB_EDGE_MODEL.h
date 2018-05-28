
// SIB_EDGE_MODEL.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSIB_EDGE_MODELApp:
// See SIB_EDGE_MODEL.cpp for the implementation of this class
//

class CSIB_EDGE_MODELApp : public CWinApp
{
public:
	CSIB_EDGE_MODELApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSIB_EDGE_MODELApp theApp;