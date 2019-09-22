// MyList.h: interface for the CMyList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLIST_H__A6CD72C1_0576_49DB_BF4F_B2FCB80C7DEE__INCLUDED_)
#define AFX_MYLIST_H__A6CD72C1_0576_49DB_BF4F_B2FCB80C7DEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SingleLinkedList.h"

class CMyList : public CSingleLinkedList  
{
public:
	virtual void OnInsert(CMyNode *pNode);
	int Insert(char* pszName, char* pszPhone);

	CMyList();
	virtual ~CMyList();

};

#endif // !defined(AFX_MYLIST_H__A6CD72C1_0576_49DB_BF4F_B2FCB80C7DEE__INCLUDED_)
