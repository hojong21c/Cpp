// UserInterface.h: interface for the CUserInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERINTERFACE_H__3190A7BB_F940_4B66_97BC_9DAF8BA98425__INCLUDED_)
#define AFX_USERINTERFACE_H__3190A7BB_F940_4B66_97BC_9DAF8BA98425__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SingleLinkedList.h"

class CUserInterface  
{
public:
	void GetNewData();
	int PrintUI();
	void StartUI();

	CUserInterface(CSingleLinkedList &list);
	virtual ~CUserInterface();
	
protected:
	CSingleLinkedList &m_List;
};

#endif // !defined(AFX_USERINTERFACE_H__3190A7BB_F940_4B66_97BC_9DAF8BA98425__INCLUDED_)
