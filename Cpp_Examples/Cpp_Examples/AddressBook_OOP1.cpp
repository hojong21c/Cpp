#include "stdafx.h"
#include "UserInterface1.h"
#include "MyList1.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList1 DB;
	CUserInterface1 UI(DB);
	UI.Run();

	return 0;
}