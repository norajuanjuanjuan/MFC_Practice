
// MFC_PracticeDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include  <cmath>
#include <ctime>
#include <string>
//#include <TChar.h>

// CMFC_PracticeDlg dialog
class CMFC_PracticeDlg : public CDialogEx
{
// Construction
public:
	CMFC_PracticeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_PRACTICE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
private:
	CString txt_DBName;
	CString txt_ServerName;
	void PrintDataTypeLength();
	void TestMathMethods();
	void RandomNumberMethod();
	void TimeAndDate();
	afx_msg void OnClickedBtnconnect();
	CString m_DBName_Value;
	CString m_ServerName_Value;
	enum  Color
	{
     red,green=5,blue
	} m_Color;
public:
	CEdit m_DBName;
	CEdit m_ServerName;
	afx_msg void OnOpen();
	afx_msg void OnAssert();
	afx_msg void OnTest();
	afx_msg void OnBnClickedCstring();
	afx_msg void OnBnClickedFilefind();
	afx_msg void OnBnClickedCfiledialog();
	afx_msg void OnBnClickedCstringarray();
};
