// MyNode.h: interface for the CMyNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYNODE_H__428B6532_7CDF_4BFE_A22A_0DE83546C30B__INCLUDED_)
#define AFX_MYNODE_H__428B6532_7CDF_4BFE_A22A_0DE83546C30B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyNode  
{
public:
	virtual void PrintData();
	virtual char* GetPriKey();

	CMyNode();
	virtual ~CMyNode();

	CMyNode	*m_pNext;

protected:
	char	*m_pszPriKey;
};

#endif // !defined(AFX_MYNODE_H__428B6532_7CDF_4BFE_A22A_0DE83546C30B__INCLUDED_)
