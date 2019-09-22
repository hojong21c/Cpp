// AddressBook.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include "UserInterface.h"
#include "MyList.h"

int main(int argc, char* argv[])
{
	CMyList list;
	CUserInterface UI(list);
	UI.StartUI();

	return 0;
}
