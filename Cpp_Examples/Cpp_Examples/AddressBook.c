#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "Address.dat"

//////////////////////////////////////////////////////////////////////////
void ReleaseList();

//////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char szName[32];  //�̸�
	char szPhone[32]; //��ȭ��ȣ

	struct _USERDATA* pNext;
} USERDATA;

// ���� ��� ��� ���� �� ����
USERDATA g_Head = { 0 };

//////////////////////////////////////////////////////////////////////////
// ����Ʈ���� �̸����� Ư�� ��带 �˻��ϴ� �Լ�
USERDATA* FindNode(char* pszName)
{
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// ���� ���� �̵�
		pTmp = pTmp->pNext;
	}

	// ��ġ�ϴ� �����͸� ã�� ���� ���
	return NULL;
}

//////////////////////////////////////////////////////////////////////////
int AddNewNode(char* pszName, char* pszPhone)
{
	USERDATA* pNewUser = NULL;

	// ���� �̸��� �̹� �����ϴ��� Ȯ���Ѵ�.
	if (FindNode(pszName) != NULL)
		return 0;
	
	// �޸𸮸� Ȯ���Ѵ�.
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	// �޸𸮿� ���� �����Ѵ�.
	sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);

}