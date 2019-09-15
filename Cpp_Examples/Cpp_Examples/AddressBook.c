#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////
// 주소록이 저장될 데이터 파일
#define DATA_FILE_NAME "Address.dat"

//////////////////////////////////////////////////////////////////////////
void ReleaseList();

//////////////////////////////////////////////////////////////////////////
typedef struct _USERDATA
{
	char szName[32];  //이름
	char szPhone[32]; //전화번호

	struct _USERDATA* pNext;
} USERDATA;

// 더미 헤드 노드 선언 및 정의
USERDATA g_Head = { 0 };

//////////////////////////////////////////////////////////////////////////
// 리스트에서 이름으로 특정 노드를 검색하는 함수
USERDATA* FindNode(char* pszName)
{
	USERDATA* pTmp = g_Head.pNext;
	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		// 다음 노드로 이동
		pTmp = pTmp->pNext;
	}

	// 일치하는 데이터를 찾지 못한 경우
	return NULL;
}

//////////////////////////////////////////////////////////////////////////
int AddNewNode(char* pszName, char* pszPhone)
{
	USERDATA* pNewUser = NULL;

	// 같은 이름이 이미 존재하는지 확인한다.
	if (FindNode(pszName) != NULL)
		return 0;
	
	// 메모리를 확보한다.
	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	// 메모리에 값을 저장한다.
	sprintf_s(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);

}