#include <afxinet.h>

/************************************************************************/
/* 获取本机IP，局域网内的IP                                              */
/************************************************************************/
char szHostName[256];
ZeroMemory(szHostName, 256);
CString ip;
if (gethostname(szHostName, sizeof(szHostName)) == 0)
{
    hostent *hostinfo = gethostbyname(szHostName);
    if (hostinfo != NULL)
    {
        ip = inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list);
    }
}
CString szServerIp = ip;
CStatic *staIpAddress;
staIpAddress = (CStatic *)GetDlgItem(IDC_IPADDRESS);
staIpAddress->SetWindowText(szServerIp);
/************************************************************************/
/* 获取公网IP                                                           */
/************************************************************************/
CString strSource;
CString Address;
CInternetSession ipSession(NULL,0);
CHttpFile* myHttpFile = NULL;

Address = "http://ip.dnsexit.com/";
myHttpFile = (CHttpFile*)ipSession.OpenURL(Address);

myHttpFile->ReadString(strSource);
#ifdef _DEBUG
AfxMessageBox(strSource);
#endif

CStatic *staPubIpAddress;
staPubIpAddress = (CStatic*)GetDlgItem(IDC_IPADDRESS2);
staPubIpAddress->SetWindowText(strSource);