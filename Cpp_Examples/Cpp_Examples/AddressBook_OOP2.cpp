#include "stdafx.h"
#include "UserInterface2.h"
#include "MyList2.h"
#include "UserData2.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList2 DB(new CUserData2);
	CUserInterface2 UI(DB);
	UI.Run();

	return 0;
}