#include "stdafx.h"
#include "UserInterface3.h"
#include "MyList3.h"
#include "UserData3.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList3 DB(new CUserData3("Dummy", "Head"));
	CUserInterface3 UI(DB);
	UI.Run();

	return 0;
}