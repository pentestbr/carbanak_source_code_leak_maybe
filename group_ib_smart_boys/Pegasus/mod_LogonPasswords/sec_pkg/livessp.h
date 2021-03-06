/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence    : http://creativecommons.org/licenses/by-nc-sa/3.0/
	This file  : http://creativecommons.org/licenses/by/3.0/
*/
#pragma once
#include "..\LogonPasswords.h"


	typedef struct _KIWI_LIVESSP_PRIMARY_CREDENTIAL
	{
		DWORD isSupp;	// 88h
		DWORD unk0;
		KIWI_GENERIC_PRIMARY_CREDENTIAL credentials;
	} KIWI_LIVESSP_PRIMARY_CREDENTIAL, *PKIWI_LIVESSP_PRIMARY_CREDENTIAL;

	typedef struct _KIWI_LIVESSP_LIST_ENTRY
	{
		struct _KIWI_LIVESSP_LIST_ENTRY *Flink;
		struct _KIWI_LIVESSP_LIST_ENTRY *Blink;
		PVOID	unk0;	// 1
		PVOID	unk1;	// 0FFFFFFFFh
		PVOID	unk2;	// 0FFFFFFFFh
		PVOID	unk3;	// 0
		DWORD	unk4;	// 0
		DWORD	unk5;	// 0
		PVOID	unk6;	// 20007D0h
		LUID	LocallyUniqueIdentifier;
		LSA_UNICODE_STRING UserName;
		PVOID	unk7;	// 2000010Dh
		PKIWI_LIVESSP_PRIMARY_CREDENTIAL suppCreds;
	} KIWI_LIVESSP_LIST_ENTRY, *PKIWI_LIVESSP_LIST_ENTRY;

	
	
	VOID lssp_InitGlobals();
	bool searchLiveGlobalLogonSessionList(LP_MODULE_CONTEXT *pContext);
	bool WINAPI getLiveSSPLogonData(LP_MODULE_CONTEXT *pContext, __in PLUID logId);
