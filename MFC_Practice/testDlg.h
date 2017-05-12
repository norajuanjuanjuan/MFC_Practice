#pragma once
class testDlg
{
public:
	testDlg(void);
	~testDlg(void);
};

#pragma once


// testDlg

class testDlg : public CWnd
{
	DECLARE_DYNAMIC(testDlg)

public:
	testDlg();
	virtual ~testDlg();

protected:
	DECLARE_MESSAGE_MAP()
};


