
// SIB_EDGE_MODELDlg.h : header file
//

#pragma once


// CSIB_EDGE_MODELDlg dialog
class CSIB_EDGE_MODELDlg : public CDialogEx
{
// Construction
public:
	CSIB_EDGE_MODELDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIB_EDGE_MODEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double m_bidprice_leg1;
	double m_askprice_leg1;
	double m_width_leg1;
	int m_bidexch_leg1;
	UINT m_bidsize_leg1;
	int m_askexch_leg1;
	UINT m_asksize_leg1;
	int m_days2ex_leg1;
	int m_ratio_leg1;
	double m_SIBreg_leg1;
	double m_SIBround_leg1;

	double m_bidprice_leg2;
	double m_askprice_leg2;
	double m_width_leg2;
	int m_bidexch_leg2;
	UINT m_bidsize_leg2;
	int m_askexch_leg2;
	UINT m_asksize_leg2;
	int m_days2ex_leg2;
	int m_ratio_leg2;
	double m_SIBreg_leg2;
	double m_SIBround_leg2;

	double m_bidprice_leg3;
	double m_askprice_leg3;
	double m_width_leg3;
	int m_bidexch_leg3;
	UINT m_bidsize_leg3;
	int m_askexch_leg3;
	UINT m_asksize_leg3;
	int m_days2ex_leg3;
	int m_ratio_leg3;
	double m_SIBreg_leg3;
	double m_SIBround_leg3;

	double m_bidprice_leg4;
	double m_askprice_leg4;
	double m_width_leg4;
	int m_bidexch_leg4;
	UINT m_bidsize_leg4;
	int m_askexch_leg4;
	UINT m_asksize_leg4;
	int m_days2ex_leg4;
	int m_ratio_leg4;
	double m_SIBreg_leg4;
	double m_SIBround_leg4;

	afx_msg void OnBnClickedButton1();
	double m_spreadprice;
	double m_market_spreadprice;

	double m_edge_leg1;
	double m_edge_leg2;
	double m_edge_leg3;
	double m_edge_leg4;
	double m_probedist_leg1;
	double m_probedist_leg2;
	double m_probedist_leg3;
	double m_probedist_leg4;
	
	double m_SIB_total;
	double m_spread_marketedge;
	double m_proberisk_leg1;
	double m_proberisk_leg2;
	double m_proberisk_leg3;
	double m_proberisk_leg4;
};
