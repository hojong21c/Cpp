// UserData.h: interface for the CUserData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERDATA_H__42E9C5AE_F093_4DD8_BB06_0BFA01D87E85__INCLUDED_)
#define AFX_USERDATA_H__42E9C5AE_F093_4DD8_BB06_0BFA01D87E85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyNode.h"
#include "MyString.h"

class CUserData : public CMyNode
{
public:
	virtual char* GetPriKey();
	virtual void PrintData();

	char* GetPhone();
	void SetPhone(char *pszPhone);
	char* GetName();
	void SetName(char* pszName);

	CUserData();
	virtual ~CUserData();

protected:
	CMyString	m_strName;
	CMyString	m_strPhone;
};

#endif // !defined(AFX_USERDATA_H__42E9C5AE_F093_4DD8_BB06_0BFA01D87E85__INCLUDED_)
