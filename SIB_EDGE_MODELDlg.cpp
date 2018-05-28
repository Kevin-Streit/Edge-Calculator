
// SIB_EDGE_MODELDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SIB_EDGE_MODEL.h"
#include "SIB_EDGE_MODELDlg.h"
#include "afxdialogex.h"
#include <cmath>
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const double BTC_width = 0.28374;
const double BTC_bidexch = -0.000924;
const double BTC_bidsize = -0.0000002;
const double BTC_askexch = 0.00126;
const double BTC_asksize = 0.0000007;
const double BTC_days2ex = -0.000009;
const double BTC_intercept =0.00401;

const double STC_width = 0.37281;
const double STC_bidexch = 0.00102;
const double STC_bidsize = 0.0000002;
const double STC_askexch = -0.00124;
const double STC_asksize = 0.0000005;
const double STC_days2ex = -0.00005;
const double STC_intercept = 0.00324;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSIB_EDGE_MODELDlg dialog



CSIB_EDGE_MODELDlg::CSIB_EDGE_MODELDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSIB_EDGE_MODELDlg::IDD, pParent)
	, m_bidprice_leg1(6.20), m_bidprice_leg2(1.94), m_bidprice_leg3(0), m_bidprice_leg4(0)
	, m_askprice_leg1(6.45), m_askprice_leg2(2.02), m_askprice_leg3(0), m_askprice_leg4(0)
	, m_width_leg1(0.00) , m_width_leg2(0.00) , m_width_leg3(0.00) , m_width_leg4(0.00)
	, m_bidexch_leg1(3) , m_bidexch_leg2(1) , m_bidexch_leg3(0) , m_bidexch_leg4(0)
	, m_bidsize_leg1(7) , m_bidsize_leg2(1) , m_bidsize_leg3(0) , m_bidsize_leg4(0)
	, m_askexch_leg1(14) , m_askexch_leg2(3) , m_askexch_leg3(14) , m_askexch_leg4(14)
	, m_asksize_leg1(300) , m_asksize_leg2(7) , m_asksize_leg3(0) , m_asksize_leg4(0)
	, m_days2ex_leg1(60) , m_days2ex_leg2(60) , m_days2ex_leg3(00) , m_days2ex_leg4(00)
	, m_ratio_leg1(1) , m_ratio_leg2(-2) , m_ratio_leg3(0) , m_ratio_leg4(0)
	, m_SIBreg_leg1(0) , m_SIBreg_leg2(0) , m_SIBreg_leg3(0) , m_SIBreg_leg4(0)
	, m_SIBround_leg1(0) , m_SIBround_leg2(0) , m_SIBround_leg3(0) , m_SIBround_leg4(0)
	, m_spreadprice(2.55)
	, m_market_spreadprice(0)
	, m_edge_leg1(0)
	, m_edge_leg2(0)
	, m_edge_leg3(0)
	, m_edge_leg4(0)
	, m_probedist_leg1(0)
	, m_probedist_leg2(0)
	, m_probedist_leg3(0)
	, m_probedist_leg4(0)
	
	, m_SIB_total(0)
	, m_spread_marketedge(0)
	, m_proberisk_leg1(0)
	, m_proberisk_leg2(0)
	, m_proberisk_leg3(0)
	, m_proberisk_leg4(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSIB_EDGE_MODELDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, BID_PRICE_LEG1, m_bidprice_leg1); DDX_Text(pDX, BID_PRICE_LEG2, m_bidprice_leg2); DDX_Text(pDX, BID_PRICE_LEG3, m_bidprice_leg3); DDX_Text(pDX, BID_PRICE_LEG4, m_bidprice_leg4);
	DDX_Text(pDX, ASK_PRICE_LEG1, m_askprice_leg1); DDX_Text(pDX, ASK_PRICE_LEG2, m_askprice_leg2); DDX_Text(pDX, ASK_PRICE_LEG3, m_askprice_leg3); DDX_Text(pDX, ASK_PRICE_LEG4, m_askprice_leg4);
	DDX_Text(pDX, WIDTH_LEG1, m_width_leg1); DDX_Text(pDX, WIDTH_LEG2, m_width_leg2); DDX_Text(pDX, WIDTH_LEG3, m_width_leg3); DDX_Text(pDX, WIDTH_LEG4, m_width_leg4);
	DDX_Text(pDX, BID_EXCH_LEG1, m_bidexch_leg1); DDX_Text(pDX, BID_EXCH_LEG2, m_bidexch_leg2); DDX_Text(pDX, BID_EXCH_LEG3, m_bidexch_leg3); DDX_Text(pDX, BID_EXCH_LEG4, m_bidexch_leg4);
	DDV_MinMaxInt(pDX, m_bidexch_leg1, 0, 20); DDV_MinMaxInt(pDX, m_bidexch_leg2, 0, 20); DDV_MinMaxInt(pDX, m_bidexch_leg3, 0, 20); DDV_MinMaxInt(pDX, m_bidexch_leg4, 0, 20);
	DDX_Text(pDX, BID_SIZE_LEG1, m_bidsize_leg1); DDX_Text(pDX, BID_SIZE_LEG2, m_bidsize_leg2); DDX_Text(pDX, BID_SIZE_LEG3, m_bidsize_leg3); DDX_Text(pDX, BID_SIZE_LEG4, m_bidsize_leg4);
	DDX_Text(pDX, ASK_EXCH_LEG1, m_askexch_leg1); DDX_Text(pDX, ASK_EXCH_LEG2, m_askexch_leg2); DDX_Text(pDX, ASK_EXCH_LEG3, m_askexch_leg3); DDX_Text(pDX, ASK_EXCH_LEG4, m_askexch_leg4);
	DDX_Text(pDX, ASK_SIZE_LEG1, m_asksize_leg1); DDX_Text(pDX, ASK_SIZE_LEG2, m_asksize_leg2); DDX_Text(pDX, ASK_SIZE_LEG3, m_asksize_leg3); DDX_Text(pDX, ASK_SIZE_LEG4, m_asksize_leg4);
	DDX_Text(pDX, DAYS2EX_LEG1, m_days2ex_leg1); DDX_Text(pDX, DAYS2EX_LEG2, m_days2ex_leg2); DDX_Text(pDX, DAYS2EX_LEG3, m_days2ex_leg3); DDX_Text(pDX, DAYS2EX_LEG4, m_days2ex_leg4);
	DDX_Text(pDX, RATIO_LEG1, m_ratio_leg1); DDX_Text(pDX, RATIO_LEG2, m_ratio_leg2); DDX_Text(pDX, RATIO_LEG3, m_ratio_leg3); DDX_Text(pDX, RATIO_LEG4, m_ratio_leg4);
	DDX_Text(pDX, SIBREG_LEG1, m_SIBreg_leg1); DDX_Text(pDX, SIBREG_LEG2, m_SIBreg_leg2); DDX_Text(pDX, SIBREG_LEG3, m_SIBreg_leg3); DDX_Text(pDX, SIBREG_LEG4, m_SIBreg_leg4);
	DDX_Text(pDX, SIBROUND_LEG1, m_SIBround_leg1); DDX_Text(pDX, SIBROUND_LEG2, m_SIBround_leg2); DDX_Text(pDX, SIBROUND_LEG3, m_SIBround_leg3); DDX_Text(pDX, SIBROUND_LEG4, m_SIBround_leg4);
	DDX_Text(pDX, IDC_SPREADPRICE, m_spreadprice);
	DDX_Text(pDX, IDC_SPREADMARKETPRICE, m_market_spreadprice);
	DDX_Text(pDX, SIBEDGE_LEG1, m_edge_leg1);
	DDX_Text(pDX, SIBEDGE_LEG2, m_edge_leg2);
	DDX_Text(pDX, SIBEDGE_LEG3, m_edge_leg3);
	DDX_Text(pDX, SIBEDGE_LEG4, m_edge_leg4);
	DDX_Text(pDX, PROBEDIST_LEG1, m_probedist_leg1);
	DDX_Text(pDX, PROBEDIST_LEG2, m_probedist_leg2);
	DDX_Text(pDX, PROBEDIST_LEG3, m_probedist_leg3);
	DDX_Text(pDX, PROBEDIST_LEG4, m_probedist_leg4);

	DDX_Text(pDX, IDC_SIB_TOTAL, m_SIB_total);
	DDX_Text(pDX, IDC_SPREAD_MARKETEDGE, m_spread_marketedge);
	DDX_Text(pDX, PROBERISK_LEG1, m_proberisk_leg1);
	DDX_Text(pDX, PROBERISK_LEG2, m_proberisk_leg2);
	DDX_Text(pDX, PROBERISK_LEG3, m_proberisk_leg3);
	DDX_Text(pDX, PROBERISK_LEG4, m_proberisk_leg4);
}

BEGIN_MESSAGE_MAP(CSIB_EDGE_MODELDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSIB_EDGE_MODELDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSIB_EDGE_MODELDlg message handlers

BOOL CSIB_EDGE_MODELDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSIB_EDGE_MODELDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSIB_EDGE_MODELDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSIB_EDGE_MODELDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/////ROUND_DOWN_PENNY_FUNCTION 2 decimals
double RoundDownPenny2Unit(double num)
{
	int dub2int=0;
	double back2dub=0;
	double multiple = 5;
	int multiple_units = 0;
	int units_to_int_price = 0;

	if(num<3)
	{
		dub2int= num*100;
		back2dub = dub2int;
		return back2dub/100;
	}
	else if( num>3) //need to round increments of 5 here.
	{
		dub2int= num*100;
		multiple_units = dub2int/multiple;  //this should cut off any decimal untis
		units_to_int_price = multiple_units*multiple;
		back2dub = units_to_int_price;
		return back2dub/100;
	}
}

/////ROUND_UP_PENNY_FUNCTION 2 decimals
double RoundUpPenny2Unit(double num)
{
	int dub2int=0;
	double back2dub=0;
	double multiple = 5;
	
	int multiple_units = 0;
	int units_to_int_price = 0;

	if(num<3)
	{
		dub2int= num*100;
		back2dub = dub2int +1; //adding to the int to round up
		return back2dub/100; //bring is back to 2 decimals
	}
	else if( num>3) //need to round increments of 5 here.
	{
		dub2int= num*100;
		multiple_units = dub2int/multiple;  //this should cut off any decimal untis
		units_to_int_price = (multiple_units+1)*multiple; //add one more unit
		back2dub = units_to_int_price;
		return back2dub/100;
	}



}


void CSIB_EDGE_MODELDlg::OnBnClickedButton1()
{

	/*, m_bidprice_leg1(0.42)
	, m_askprice_leg1(0.47)
	, m_width_leg1(0.05)
	, m_bidexch_leg1(0)
	, m_bidsize_leg1(0)
	, m_askexch_leg1(0)
	, m_asksize_leg1(0)
	, m_days2ex_leg1(0)
	, m_ratio_leg1(0)
	, m_SIBreg_leg1(0)
	, m_SIBround_leg1(0)*/
	// TODO: Add your control notification handler code here

	double probe_price_from_bid =0;
	double probe_price_from_ask =0;

	UpdateData();
	//////////////////
	/////LEG 1///////
	/////////////////
	m_width_leg1 = m_askprice_leg1-m_bidprice_leg1;

	if( m_ratio_leg1 >0) //spread ratio is positive means we will get short the option, so need to buy to close
	{
		probe_price_from_ask = (m_width_leg1*BTC_width)+(m_bidexch_leg1*BTC_bidexch)+(m_bidsize_leg1*BTC_bidsize)
			+(m_askexch_leg1*BTC_askexch)+(m_asksize_leg1*BTC_asksize)+(m_days2ex_leg1*BTC_days2ex)+BTC_intercept;
	}
	else if( m_ratio_leg1 <0) //spread ratio is negative means we will get long the option, so need to sell to close
	{
		probe_price_from_bid = (m_width_leg1*STC_width)+(m_bidexch_leg1*STC_bidexch)+(m_bidsize_leg1*STC_bidsize)
			+(m_askexch_leg1*STC_askexch)+(m_asksize_leg1*STC_asksize)+(m_days2ex_leg1*STC_days2ex)+STC_intercept;
	}
	else
	{
		probe_price_from_bid =0;
		probe_price_from_ask =0;
	}

	if( m_ratio_leg1 >0)
	{
		m_SIBreg_leg1=m_askprice_leg1-probe_price_from_ask;
		m_SIBround_leg1 = RoundUpPenny2Unit(m_SIBreg_leg1);

	}
	else if( m_ratio_leg1 <0)
	{
		m_SIBreg_leg1=m_bidprice_leg1+probe_price_from_bid;
		m_SIBround_leg1 = RoundDownPenny2Unit(m_SIBreg_leg1);
	}
	else
	{
		m_SIBreg_leg1=0;
		m_SIBround_leg1=0;
	}
	
	//////////////////
	/////LEG 2///////
	/////////////////
	m_width_leg2 = m_askprice_leg2-m_bidprice_leg2;

	if( m_ratio_leg2 >0) //spread ratio is positive means we will get short the option, so need to buy to close
	{
		probe_price_from_ask = (m_width_leg2*BTC_width)+(m_bidexch_leg2*BTC_bidexch)+(m_bidsize_leg2*BTC_bidsize)
			+(m_askexch_leg2*BTC_askexch)+(m_asksize_leg2*BTC_asksize)+(m_days2ex_leg2*BTC_days2ex)+BTC_intercept;
	}
	else if( m_ratio_leg2 <0) //spread ratio is negative means we will get long the option, so need to sell to close
	{
		probe_price_from_bid = (m_width_leg2*STC_width)+(m_bidexch_leg2*STC_bidexch)+(m_bidsize_leg2*STC_bidsize)
			+(m_askexch_leg2*STC_askexch)+(m_asksize_leg2*STC_asksize)+(m_days2ex_leg2*STC_days2ex)+STC_intercept;
	}
	else
	{
		probe_price_from_bid =0;
		probe_price_from_ask =0;
	}

	if( m_ratio_leg2 >0)
	{
		m_SIBreg_leg2=m_askprice_leg2-probe_price_from_ask;
		m_SIBround_leg2 = RoundUpPenny2Unit(m_SIBreg_leg2);

	}
	else if( m_ratio_leg2 <0)
	{
		m_SIBreg_leg2=m_bidprice_leg2+probe_price_from_bid;
		m_SIBround_leg2 = RoundDownPenny2Unit(m_SIBreg_leg2);
	}
	else
	{
		m_SIBreg_leg2=0;
		m_SIBround_leg2=0;
	}
	//////////////////
	/////LEG 3///////
	/////////////////
	m_width_leg3 = m_askprice_leg3-m_bidprice_leg3;

	if( m_ratio_leg3 >0) //spread ratio is positive means we will get short the option, so need to buy to close
	{
		probe_price_from_ask = (m_width_leg3*BTC_width)+(m_bidexch_leg3*BTC_bidexch)+(m_bidsize_leg3*BTC_bidsize)
			+(m_askexch_leg3*BTC_askexch)+(m_asksize_leg3*BTC_asksize)+(m_days2ex_leg3*BTC_days2ex)+BTC_intercept;
	}
	else if( m_ratio_leg3 <0) //spread ratio is negative means we will get long the option, so need to sell to close
	{
		probe_price_from_bid = (m_width_leg3*STC_width)+(m_bidexch_leg3*STC_bidexch)+(m_bidsize_leg3*STC_bidsize)
			+(m_askexch_leg3*STC_askexch)+(m_asksize_leg3*STC_asksize)+(m_days2ex_leg3*STC_days2ex)+STC_intercept;
	}
	else
	{
		probe_price_from_bid =0;
		probe_price_from_ask =0;
	}

	if( m_ratio_leg3 >0)
	{
		m_SIBreg_leg3=m_askprice_leg3-probe_price_from_ask;
		m_SIBround_leg3 = RoundUpPenny2Unit(m_SIBreg_leg3);

	}
	else if( m_ratio_leg3 <0)
	{
		m_SIBreg_leg3=m_bidprice_leg3+probe_price_from_bid;
		m_SIBround_leg3 = RoundDownPenny2Unit(m_SIBreg_leg3);
	}
	else
	{
		m_SIBreg_leg3=0;
		m_SIBround_leg3 = 0;
	}
	//////////////////
	/////LEG 4///////
	/////////////////
	m_width_leg4 = m_askprice_leg4-m_bidprice_leg4;

	if( m_ratio_leg4 >0) //spread ratio is positive means we will get short the option, so need to buy to close
	{
		probe_price_from_ask = (m_width_leg4*BTC_width)+(m_bidexch_leg4*BTC_bidexch)+(m_bidsize_leg4*BTC_bidsize)
			+(m_askexch_leg4*BTC_askexch)+(m_asksize_leg4*BTC_asksize)+(m_days2ex_leg4*BTC_days2ex)+BTC_intercept;
	}
	else if( m_ratio_leg4 <0) //spread ratio is negative means we will get long the option, so need to sell to close
	{
		probe_price_from_bid = (m_width_leg4*STC_width)+(m_bidexch_leg4*STC_bidexch)+(m_bidsize_leg4*STC_bidsize)
			+(m_askexch_leg4*STC_askexch)+(m_asksize_leg4*STC_asksize)+(m_days2ex_leg4*STC_days2ex)+STC_intercept;
	}
	else
	{
		probe_price_from_bid =0;
		probe_price_from_ask =0;
	}

	if( m_ratio_leg4 >0)
	{
		m_SIBreg_leg4=m_askprice_leg4-probe_price_from_ask;
		m_SIBround_leg4 = RoundUpPenny2Unit(m_SIBreg_leg4);

	}
	else if( m_ratio_leg4 <0)
	{
		m_SIBreg_leg4=m_bidprice_leg4+probe_price_from_bid;
		m_SIBround_leg4 = RoundDownPenny2Unit(m_SIBreg_leg4);
	}
	else
	{
		m_SIBreg_leg4=0;
		m_SIBround_leg4 =0;
	}

	///////////////////////////////
	///GET SPREAD MARKET PRICE ////
	///////////////////////////////
	double leg1marketprice=0;
	double leg2marketprice=0;
	double leg3marketprice=0;
	double leg4marketprice=0;

	if(m_ratio_leg1 > 0) //If the leg ratio is positive use ask price otherwise you bid price
	{
		leg1marketprice = m_askprice_leg1*(m_ratio_leg1);
	}
	else if(m_ratio_leg1 < 0)
	{
		leg1marketprice = m_bidprice_leg1*(m_ratio_leg1);
	}
	else
	{
		leg1marketprice=0;
	}
	//LEG2
	if(m_ratio_leg2 > 0)
	{
		leg2marketprice = m_askprice_leg2*(m_ratio_leg2);
	}
	else if(m_ratio_leg2 < 0)
	{
		leg2marketprice = m_bidprice_leg2*(m_ratio_leg2);
	}
	else
	{
		leg2marketprice=0;
	}
	///LEG3
	if(m_ratio_leg3 > 0)
	{
		leg3marketprice = m_askprice_leg3*(m_ratio_leg3);
	}
	else if(m_ratio_leg3 < 0)
	{
		leg3marketprice = m_bidprice_leg3*(m_ratio_leg3);
	}
	else
	{
		leg3marketprice=0;
	}
	///LEG 4
	if(m_ratio_leg4 > 0)
	{
		leg4marketprice = m_askprice_leg4*(m_ratio_leg4);
	}
	else if(m_ratio_leg4 < 0)
	{
		leg4marketprice = m_bidprice_leg4*(m_ratio_leg4);
	}
	else
	{
		leg4marketprice=0;
	}

	m_market_spreadprice = leg1marketprice+leg2marketprice+leg3marketprice+leg4marketprice;

	///////////////////
	/////CALC TPP//////
	///////////////////
	double width_total=0;
	double edge_per_leg = 0;
	int total_legs = 0;
	double leg1TPP=0;
	double leg2TPP=0;
	double leg3TPP=0;
	double leg4TPP=0;
	double reverted_spread_price=0;

	width_total = (m_askprice_leg1-m_bidprice_leg1)*abs(m_ratio_leg1)+
		(m_askprice_leg2-m_bidprice_leg2)*abs(m_ratio_leg2)+
		(m_askprice_leg3-m_bidprice_leg3)*abs(m_ratio_leg3)+
		(m_askprice_leg4-m_bidprice_leg4)*abs(m_ratio_leg4);

	//abs value of addition of legs = total legs
	total_legs = abs(m_ratio_leg1)+abs(m_ratio_leg2)+abs(m_ratio_leg3)+abs(m_ratio_leg4);

	edge_per_leg = width_total/total_legs;

	//if ratio is positive we will get short so theo price we are buying is egde per leg + bid.
	//Leg1TPP
	if (m_ratio_leg1 > 0)
	{
		leg1TPP = m_bidprice_leg1+edge_per_leg;
		m_edge_leg1 = (leg1TPP-m_SIBround_leg1)*abs(m_ratio_leg1);  
		m_probedist_leg1 = m_askprice_leg1-m_SIBround_leg1;
		m_proberisk_leg1 = m_SIBround_leg1-m_bidprice_leg1;

		
	}
	else if(m_ratio_leg1 < 0)
	{
		leg1TPP = m_askprice_leg1-edge_per_leg;
		m_edge_leg1 = (m_SIBround_leg1-leg1TPP)*abs(m_ratio_leg1);
		m_probedist_leg1 = m_SIBround_leg1-m_bidprice_leg1;
		m_proberisk_leg1 = m_askprice_leg1-m_SIBround_leg1;
	}
	else
	{
		leg1TPP =0;
		m_edge_leg1=0;
		m_probedist_leg1 =0;
		m_proberisk_leg1 =0;
	}
	//Leg2TPP
	if (m_ratio_leg2 > 0)
	{
		leg2TPP = m_bidprice_leg2+edge_per_leg;
		m_edge_leg2 = (leg2TPP-m_SIBround_leg2)*abs(m_ratio_leg2);
		m_probedist_leg2 = m_askprice_leg2-m_SIBround_leg2;
		m_proberisk_leg2 = m_SIBround_leg2-m_bidprice_leg2;
		
	}
	else if(m_ratio_leg2 < 0)
	{
		leg2TPP = m_askprice_leg2-edge_per_leg;
		m_edge_leg2 = (m_SIBround_leg2-leg2TPP)*abs(m_ratio_leg2);
		m_probedist_leg2 = m_SIBround_leg2-m_bidprice_leg2;
		m_proberisk_leg2 = m_askprice_leg2-m_SIBround_leg2;
	}
	else
	{
		leg2TPP =0;
		m_edge_leg2=0;
		m_probedist_leg2 =0;
		m_proberisk_leg2 = 0;
	}
	//Leg3TPP
	if (m_ratio_leg3 > 0)
	{
		leg3TPP = m_bidprice_leg3+edge_per_leg;
		m_edge_leg3 = (leg3TPP-m_SIBround_leg3)*abs(m_ratio_leg3);
		m_probedist_leg3 = m_askprice_leg3-m_SIBround_leg3;
		m_proberisk_leg3 = m_SIBround_leg1-m_bidprice_leg3;
		
		
	}
	else if(m_ratio_leg3 < 0)
	{
		leg3TPP = m_askprice_leg3-edge_per_leg;
		m_edge_leg3 = (m_SIBround_leg3-leg3TPP)*abs(m_ratio_leg3);
		m_probedist_leg3 = m_SIBround_leg1-m_bidprice_leg3;
		m_proberisk_leg3 = m_askprice_leg3-m_SIBround_leg3;
		
	}
	else
	{
		leg3TPP =0;
		m_edge_leg3=0;
		m_probedist_leg3 =0;
		m_proberisk_leg3 =0;
	}
	//Leg4TPP
	if (m_ratio_leg4 > 0)
	{
		leg4TPP = m_bidprice_leg4+edge_per_leg;
		m_edge_leg4 = (leg4TPP-m_SIBround_leg4)*abs(m_ratio_leg4);
		m_probedist_leg4 = m_askprice_leg4-m_SIBround_leg4;
		m_proberisk_leg4 = m_SIBround_leg1-m_bidprice_leg4;
		
	}
	else if(m_ratio_leg4 < 0)
	{
		leg4TPP = m_askprice_leg4-edge_per_leg;
		m_edge_leg4 = (m_SIBround_leg4-leg4TPP)*abs(m_ratio_leg4);
		m_probedist_leg4 = m_SIBround_leg1-m_bidprice_leg4;
		m_proberisk_leg4 = m_askprice_leg4-m_SIBround_leg4;
	}
	else
	{
		leg4TPP =0;
		m_edge_leg4=0;
		m_probedist_leg4 =0;
		m_proberisk_leg4 =0;
	}

	m_SIB_total = m_edge_leg1+m_edge_leg2+m_edge_leg3+m_edge_leg4;
	m_spread_marketedge = m_spreadprice-m_market_spreadprice;
	reverted_spread_price = (leg1TPP*m_ratio_leg1)+(leg2TPP*m_ratio_leg2)+(leg3TPP*m_ratio_leg3)+(leg4TPP*m_ratio_leg4);


	/////////////////////////////
	////GETTING EDGE PER LEG////
	/////////////////////////////


	

	UpdateData(FALSE);
}
