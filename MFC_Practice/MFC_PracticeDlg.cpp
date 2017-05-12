
// MFC_PracticeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Practice.h"
#include "MFC_PracticeDlg.h"
#include "afxdialogex.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_testDlg };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// CMFC_PracticeDlg dialog



CMFC_PracticeDlg::CMFC_PracticeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_PracticeDlg::IDD, pParent)
	, txt_DBName(_T(""))
	, txt_ServerName(_T(""))
	, m_DBName_Value(_T(""))
	, m_ServerName_Value(_T(""))
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_PracticeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_DBName);
	DDX_Control(pDX, IDC_EDIT4, m_ServerName);
	DDX_Text(pDX, IDC_EDIT3, m_DBName_Value);
	DDX_Text(pDX, IDC_EDIT4, m_ServerName_Value);
}

BEGIN_MESSAGE_MAP(CMFC_PracticeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnConnect, &CMFC_PracticeDlg::OnClickedBtnconnect)
	//ON_COMMAND(ID_OPEN, &CMFC_PracticeDlg::OnOpen)
	//ON_COMMAND(ID_Assert, &CMFC_PracticeDlg::OnAssert)
	ON_COMMAND(ID_Test, &CMFC_PracticeDlg::OnTest)
	ON_BN_CLICKED(IDC_CString, &CMFC_PracticeDlg::OnBnClickedCstring)
	ON_BN_CLICKED(IDC_FileFind, &CMFC_PracticeDlg::OnBnClickedFilefind)
	ON_BN_CLICKED(IDC_CFileDialog, &CMFC_PracticeDlg::OnBnClickedCfiledialog)
	ON_BN_CLICKED(IDC_CStringArray, &CMFC_PracticeDlg::OnBnClickedCstringarray)
END_MESSAGE_MAP()


// CMFC_PracticeDlg message handlers

BOOL CMFC_PracticeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CMenu* pSysMenu=GetSystemMenu(FALSE);
	if(pSysMenu!=NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadStringA(IDS_AboutTestDlg);
		if(!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenuA(MF_SEPARATOR);
			pSysMenu->AppendMenuA(MF_STRING,IDM_AboutTestDlg,strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_DBName.SetWindowTextA("AutoTester");
	m_ServerName.SetWindowTextA("C1-GIS-NORA-NB");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_PracticeDlg::OnPaint()
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
HCURSOR CMFC_PracticeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_PracticeDlg::OnClickedBtnconnect()
{
	// TODO: Add your control notification handler code here
	CoInitialize(NULL);
	m_DBName.GetWindowTextA(m_DBName_Value);
	m_ServerName.GetWindowTextA(m_ServerName_Value);
	_bstr_t strConn=
		CString("Provider=SQLOLEDB;Integrated Security=SSPI;Data Source="
		+m_ServerName_Value)+CString(";Initial Catalog="+m_DBName_Value+";");
	_ConnectionPtr m_pConnection;
	m_pConnection.CreateInstance( __uuidof(Connection) );
	HRESULT hr=
	m_pConnection->Open( strConn, "", "", adConnectUnspecified );
	m_pConnection->CommandTimeout = 0;
	if(SUCCEEDED(m_pConnection))
	MessageBoxA("DB连接成功");
	/*PrintDataTypeLength();
	TestMathMethods();*/
	//RandomNumberMethod();
	TimeAndDate();
}

void CMFC_PracticeDlg::PrintDataTypeLength()
{
	MessageBoxA("Size of wchar_t :"+(_bstr_t)sizeof(wchar_t)
		+"\n"+"Size of double :"+(_bstr_t)sizeof(double));
	m_Color=blue;
	MessageBoxA("My Color is :"+(_bstr_t)m_Color);
}

void CMFC_PracticeDlg::TestMathMethods()
{
	double x=15.88;
	double y=8.00;
	MessageBoxA((_bstr_t)hypot(x,y));
	MessageBoxA((_bstr_t)sqrt(pow(x,2)+pow(y,2)));
	MessageBoxA((_bstr_t)floor(x));
}

void CMFC_PracticeDlg::RandomNumberMethod()
{
	int i,j;
	_bstr_t output="";

	srand((unsigned)time(NULL));
	//srand((unsigned)8);

	for(i=0;i<10;i++)
	{
		j=rand()%11;
		if(i!=9)
		output+=(_bstr_t)j+",";
		else
		{
			output+=(_bstr_t)j;
		}
	}

	j=rand()%101;
	/*float m=(float)j*0.01;*/
	float m=(float)j/101;

	MessageBoxA(output);
	MessageBoxA("0"+(_bstr_t)m);
}

void CMFC_PracticeDlg::TimeAndDate()
{
	clock_t start_t,end_t,total_t;
	start_t=clock();
	time_t now=time(0);
	//MessageBoxA((_bstr_t)(now/3600));
	char* dt=ctime(&now);
	MessageBoxA("本地日期和时间："+(_bstr_t )dt);
	// 把 now 转换为 tm 结构
	tm *gmtm=gmtime(&now);
	dt=asctime(gmtm);
	MessageBoxA("UTC 日期和时间："+(_bstr_t )dt);

	/*time_t seconds;
	seconds =time(NULL);
	MessageBoxA("自1970-01-01 起的小时数="+(_bstr_t)(seconds/3600));*/

	time_t curtime;
	time(&curtime);
	MessageBoxA((_bstr_t)ctime(&curtime));

	time_t rawtime;
	tm *info;
	time(&rawtime);
	info=localtime(&rawtime);
	MessageBoxA((_bstr_t)info->tm_hour);

	end_t=clock();
	MessageBoxA("CPU占用总时间(秒)："+(_bstr_t)((end_t-start_t)/CLOCKS_PER_SEC));
}



void CMFC_PracticeDlg::OnOpen()
{
	// TODO: Add your command handler code here
	CDialog* dlg = new CDialog;
    dlg->Create(MAKEINTRESOURCE(IDD_testDlg));
    dlg->ShowWindow(1);
}


void CMFC_PracticeDlg::OnAssert()
{
	// TODO: Add your command handler code here
	int n=30;
	ASSERT(n<40);
}

void CMFC_PracticeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if((nID&0xFFF0)==IDM_AboutTestDlg)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID,lParam);
	}
}


void CMFC_PracticeDlg::OnTest()
{
	// TODO: Add your command handler code here
	AfxMessageBox("It's me!");
}


void CMFC_PracticeDlg::OnBnClickedCstring()
{
	// TODO: Add your control notification handler code here
    //CString和string的转换
	string s="nora";
	CString cstr(s.c_str());
	s=cstr.GetBuffer(0);
	cstr.Format("%s",s.c_str());
	cstr.Format("%s",s.data());
	s=LPCTSTR(cstr);

	int i=123;
	CString cstr_2;
	cstr_2.Format("%d",i);
	i=atoi(cstr_2);

	char szString[100];
	strcpy(szString,"test");

	wchar_t w_szString[100];
	wcscpy(w_szString,L"test_w");

	TCHAR t_szString[100];
	_tcscpy(t_szString,_TEXT("test_T"));
}


void CMFC_PracticeDlg::OnBnClickedFilefind()
{
	// TODO: Add your control notification handler code here
	CFileFind finder;
	bool working=finder.FindFile(_T("*.*"));
	while (working)
	{
			working=finder.FindNextFile();
			MessageBox((LPCTSTR)finder.GetFileName());
	}
}


void CMFC_PracticeDlg::OnBnClickedCfiledialog()
{
	// TODO: Add your control notification handler code here
	CString filter;
	filter="文本文档(*.txt)|*.txt||";

	CFileDialog dlg_save(FALSE,NULL,NULL,OFN_HIDEREADONLY,filter);
	if(dlg_save.DoModal()==IDOK)
	{
		CString strPath;
		strPath=dlg_save.GetPathName();

		CFile mFile;
		mFile.Open(strPath,CFile::modeCreate|CFile::modeWrite);
		CArchive ar(&mFile,CArchive::store);
		ar.WriteString("我是Nora啊\r\n我叫刘娟\r\n来自湖南");
		ar.Close();
		mFile.Close();
	}

	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,filter);
	//设置为TRUE为打开文件对话框
	//保存文件对话框，只需要修改CFileDialog的构造方法的第一个参数为FALSE就行了。
	if(dlg.DoModal()==IDOK)
	{
		CString strPath;
		strPath=dlg.GetPathName();

		CFile mFile;
		if(mFile.Open(strPath,CFile::modeRead)==0)//以read方式打开
			return;
		char buf[512];
		CString str_txt;
		CString str_txt2;
		CString str_txt3;
		CArchive ar(&mFile,CArchive::load,512,buf);//模式load就是read
		//ar >> str_txt;//二进制读取，如果是文本，读取会出问题，第一个字符会乱码，有时候还会文件指针越界
		ar.ReadString(str_txt);//读取数据并保存到str_txt数组中
		ar.ReadString(str_txt2);
		ar.ReadString(str_txt3);
		//ar.Flush();//清理缓冲区，写入本地
		ar.Close();
		mFile.Close();

		MessageBox(strPath);
		MessageBox(str_txt+"\r\n"+str_txt2+"\r\n"+str_txt3);
	}
}


void CMFC_PracticeDlg::OnBnClickedCstringarray()
{
	// TODO: Add your control notification handler code here
	CString temp("a|b|c|d|e");
	CStringArray road;
	int s0=temp.ReverseFind('|');
	road.Add(temp.Mid(s0+1));
	while(s0>0)
	{
		temp=temp.Mid(0,s0);
		s0=temp.ReverseFind('|');
		road.Add(temp.Mid(s0+1));
	}
	int n=road.GetSize();
		CString s;
	for(int i=0;i<n;i++)
	{
		s+=road[i]+"\r\n";
	}
	MessageBox(s);
}
