// ***************************************************************
//  AppFunctionConfig   version:  1.0   ��  date: 12/09/2007
//  -------------------------------------------------------------
//  �����ܿ��ؽӿڣ�
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
//
// ***************************************************************
#include "LocalIncludeFile.h"

/******************************************************************************************************
*�����豸�Ƿ�����
******************************************************************************************************/
int FunWeight = 1;
int EnabledWeight()
{	
	return FunWeight;
}
/******************************************************************************************************
*��ӡ���Ƿ�����
******************************************************************************************************/
int FunPrinter = 1;
int EnabledPrinter()
{	
	return	FunPrinter;
}
/******************************************************************************************************
*�����Ƿ�����
******************************************************************************************************/
int FunTFI = 1;
int EnabledTFI()
{	
	return FunTFI;
}
/******************************************************************************************************
*�ַ������Ƿ�����
******************************************************************************************************/
int FunVDM = 1;
int EnabledVDM()
{	
	return FunVDM;
}
int FunCICM;
/**
 * �Ƿ�Ϊ��Я�շѻ���ʽ
 * 
 * @return 
 */
int EnabledCICM(void)
{
	return FunCICM;
}

int FunIOBoard;
/**
 * �Ƿ�����IO����ƹ���
 * 
 * @return 
 */
int EnabledIOBoard(void)
{
	return FunIOBoard;
}
int FunIC;
/**
 * �Ƿ�����IC������
 * 
 * @return 
 */
BOOL GetEnableIC(void)
{
	return FunIC;
}

int FunCJIC;
BOOL GetEnableCJIC(void)
{
	return FunCJIC;
}

int FunCallTCS;
/**
 * �Ƿ����� ���м�صĹ��ܡ� 
 * 
 * @return 
 */
BOOL EnabledCallTCS(void)
{
	return  FunCallTCS;
}
int FunVideo = 0;
BOOL EnabledVideo(void)
{
	return  FunVideo;
}
char TFIDLL[20];
char *GetTFIDLL()
{
	return TFIDLL;
}
char PrintDLL[20];
char *GetPrintDLL()
{
	return PrintDLL;
}
int _Display = 640;
int GetDisPlay_Resolution()
{
	return _Display;
}

BOOL FunDoubleLane = FALSE;
BOOL FunControlLane = FALSE;

//����ʽ�շ�ģʽ
BOOL GetFunDoubleLane()
{
	return FunDoubleLane;

}
//����ʽ�շ�ģʽ�п������˻��ĳ�����
BOOL GetFunControlLane()
{
	return FunControlLane;
}
/******************************************************************************************************
*װ�س���������
******************************************************************************************************/
void LoadAppFunction(void)
{	
	echoic("����װ�س���������...");  
	LoadIniFile(APPFUNCTIONFILENAMEFILE);   
	FunCICM = atoi(readItemInIniFile("FunCICM"));   
	FunIOBoard = atoi(readItemInIniFile("FunIOBoard")); 
	FunWeight = atoi(readItemInIniFile("FunWeight"));   
	FunPrinter= atoi(readItemInIniFile("FunPrinter"));  
	FunTFI = atoi(readItemInIniFile("FunTFI")); 
	FunVDM = atoi(readItemInIniFile("FunVDM")); 
	FunIC = atoi(readItemInIniFile("FunIC"));   
	FunCJIC = atoi(readItemInIniFile("FunCJIC"));   
	FunCallTCS = atoi(readItemInIniFile("FunCallTCS")); 
	FunVideo = atoi(readItemInIniFile("FunVideo")); 
	FunDoubleLane = atoi(readItemInIniFile("FunDoubleLane")); 
	FunControlLane = atoi(readItemInIniFile("FunControlLane")); 
	memset(TFIDLL,0x00,20);
	strcpy(TFIDLL,readItemInIniFile("TFIDLL"));
	memset(PrintDLL,0x00,20);
	strcpy(PrintDLL,readItemInIniFile("PrintDLL"));

}

