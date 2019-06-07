#include "stdafx.h"

/*
	인터페이스 다중 상속
	- 보통 순수 가상 클래스로 선언하는 경우가 많다.
	- 자식클래스에서 부모클래스가 선언한 순수 가상 함수들을 모두 재정의 해야한다.
*/
class CMyUSB
{
public:
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial
{
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
public:
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CMyDevice dev;

	return 0;
}