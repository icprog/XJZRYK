// ***************************************************************
//  systemContext   version:  1.0   ��  date: 12/11/2007
//  -------------------------------------------------------------
//  ϵͳ��������Ϣ��
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
//
// ***************************************************************

#include "LocalIncludeFile.h"
 int YuPengState=0;
void SetYuPengState(int inputYuPengState)
{	
	YuPengState=inputYuPengState;
}
int GetYuPengState(void )
{	
	return YuPengState;
}
 
//ȫ�������
volatile int g_TranNo=0;
//������������Ϣ�����־
volatile int g_nHelpTimer = 0;
volatile int SynOn=0;//ͬ������
volatile int wzCarType = 0;
volatile int YaxianquanNum=0;
 
 int g_bWeiZhangCount = 0;
 void Setg_bWeiZhangCount(int inputg_bWeiZhangCount)
 {	
	 g_bWeiZhangCount=inputg_bWeiZhangCount;
 }
 int Getg_bWeiZhangCount(void)
 {	
	 return g_bWeiZhangCount;
 } 
int billCount =0;
void SetbillCount(int inputbillCount)
{	
	billCount=inputbillCount;
}
int GetbillCount(void)
{	
	return billCount;
}
 
 
/**************************************************************
��ǣ�Ϊͳ���ϳ���ʱ��������Ŷ�����
�����ˣ�����ΰ
�������ڣ�2008-07-09
***************************************************************/
int subTransNo;
void InitSubTransNo(void)
{	
	subTransNo=0;
}
void AddSubTransNo(void)
{	
	subTransNo++;
}
int GetSubTransNo(void)
{	
	return subTransNo;
}
 
 
 
 
int G_Lane_carTypeCount ;	//������������ �ڶ����ñ��ʱ��õ���
 
int g_tuocheNum;
void Initg_tuocheNum(void)
{	
	g_tuocheNum=0;
}
void Addg_tuocheNum(void)
{	
	g_tuocheNum++;
}
int Getg_tuocheNum(void)
{	
	return g_tuocheNum;
}
/******************************************************************************************************
*������״̬���
******************************************************************************************************/
volatile int WorkState = 1;
/****************
* ���õ�ǰ״ֵ̬
****************/
void SetWorkState(int value)
{	
	WorkState=value;
}
/******************************
* ��ù���״ֵ̬��ù���״ֵ̬
******************************/
int GetWorkState(void)
{	
	return WorkState;
}
/******************************************************************************************************
*��ʾ��Ϣ����
******************************************************************************************************/
static char MsgTitle[50];
char * GetMsgTitle(void)
{	
	return MsgTitle;
}
/******************************************************************************************************
*��ʾ��Ϣ����
******************************************************************************************************/
static  char MsgContext[200];
char *GetMsgContext(void)
{	
	return MsgContext;
}

/******************************************************************************************************
*��ǰ������
******************************************************************************************************/
int CurrentWorkPassCarCount = 0;
int GetCurrentWorkPassCarCount(void)
{	
	return CurrentWorkPassCarCount;
}
void SetCurrentWorkPassCarCount(int InputCurrentWorkPassCarCount)
{	
	CurrentWorkPassCarCount = InputCurrentWorkPassCarCount;
}
int AddCurrentWorkPassCarCount(void)
{	
	++CurrentWorkPassCarCount;
	return CurrentWorkPassCarCount;

}
/******************************************************************************************************
*����Υ�³�����
******************************************************************************************************/
char tempExit[2];
void SendMessageWzCar(int wzCarType)
{	
	char tempTran[4];
	memset(tempTran,0x00,4);	
	SetG_weiZhangType(1);	
	SetExitVIMsgExitType(wzCarType);	
	sprintf(tempExit,"%d",wzCarType);	
	SetExitTRMsgExitType(tempExit[0]);	
	SetExitTRMsgMethod_Pay(MP_NotPay);	
	SetExitTRMsgViolation('1');	
	SetExitTRMsgExitClass('0');	
	SetExitTRMsgTollFare(0);	
	g_TranNo++;
	sprintf(tempTran,"%04d",g_TranNo);	
	SetExitTRMsgtranNo(tempTran);	
	SendMsgInfo("Υ����Ϣ", "","����");	
	SetG_weiZhangType(0);	
	SetExitTRMsgEntryLane(GetCarNember());
	SendMessageToQueue(ID_MSGEXITTR);	
	SendMessageToQueue(ID_MSGEXITVI);	
	InitMsgExitTR();	


}
/******************************************************************************************************
*�õ�������
******************************************************************************************************/
int CountCar=0;

int GetNewCarCount(void)
{	

	return ++CountCar ;
}
void ReSetCarCount(void)
{	
	CountCar=0;
}

/******************************************************************************************************
*�ϰ�ʱ��
******************************************************************************************************/
char OnJobDateTime[14];
void InitOnJobDateTime()
{	
	memset(OnJobDateTime,' ',14);	
}
char *GetOnJobDateTime(void)
{	
    return OnJobDateTime;
}
void SetOnJobDateTime(char *jbtimetime)
{	
    strncpy(OnJobDateTime, jbtimetime,14);	
}
/******************************************************************************************************
*��κ�
******************************************************************************************************/
char SystemContextSihtNo;
void SetSystemContextSihtNo(char InputSystemContextSihtNo)
{	
	SystemContextSihtNo = InputSystemContextSihtNo;
}
char GetSystemContextSihtNo()
{	
	return SystemContextSihtNo;
}
/******************************************************************************************************
* ʹ�ô�ֵ��
******************************************************************************************************/
int SystemContextIsSVC = 0;
void InitSystemContextIsSVC()
{	
	SystemContextIsSVC = 0;
}
int GetSystemContextIsSVC()
{	
	return SystemContextIsSVC;
}
void SetSystemContextIsSVC()
{	
	SystemContextIsSVC = 1;
}
///**************************************************************
//����
//***************************************************************/
int carTypeIndex=-2;
void Setg_CurrentCartypeIndex(int value)
{	
	carTypeIndex=value;
}
int Get_CurrentCartypeIndex()
{	
	return carTypeIndex;
}

///**************************************************************
//����
//***************************************************************/
int carKindIndex=-2;
void Setg_CurrentCarKindIndex(int value)
{	
	carKindIndex=value;
	I_DEV_VDM_CarKind(carKindIndex);	

}
int Getg_CurrentCarKindIndex()
{	
	return carKindIndex;
}
 
int DiscountRate=0;
void Setg_DiscountRate(float tollFare,float actualFare)
{	
	DiscountRate=(int)((actualFare/tollFare)*100);	
}
int Getg_DiscountRate(void)
{	
	return DiscountRate;
}
///**************************************************************
//
//***************************************************************/

/**************************************************************
�����ϰ�ʱ��
***************************************************************/
long GetEixtEsWorkTime(char * Bs_time,char * EixtEstime)
{	
	struct tm Bstime,Estime;
	long start,end,retSec;
	char BsYear[5],BsMonth[3],BsDay[3],BsHour[3],BsMini[3],BsSec[3];
	char EsYear[5],EsMonth[3],EsDay[3],EsHour[3],EsMini[3],EsSec[3];
	memset(BsYear,0x00,sizeof(BsYear));	
	memset(BsMonth,0x00,sizeof(BsMonth));	
	memset(BsDay,0x00,sizeof(BsDay));	
	memset(BsHour,0x00,sizeof(BsHour));	
	memset(BsMini,0x00,sizeof(BsMini));	
	memset(BsSec,0x00,sizeof(BsSec));	

	memset(EsYear,0x00,sizeof(EsYear));	
	memset(EsMonth,0x00,sizeof(EsMonth));	
	memset(EsDay,0x00,sizeof(EsDay));	
	memset(EsHour,0x00,sizeof(EsHour));	
	memset(EsMini,0x00,sizeof(EsMini));	
	memset(EsSec,0x00,sizeof(EsSec));	
	memset(&Bstime,0,sizeof(Bstime));	
	memset(&Estime,0,sizeof(Estime));	
	strncpy(BsYear,Bs_time,4);	
	strncpy(BsMonth,Bs_time+4,2);	
	strncpy(BsDay,Bs_time+6,2);	
	strncpy(BsHour,Bs_time+8,2);	
	strncpy(BsMini,Bs_time+10,2);	
	strncpy(BsSec,Bs_time+12,2);	

	strncpy(EsYear,EixtEstime,4);	
	strncpy(EsMonth,EixtEstime+4,2);	
	strncpy(EsDay,EixtEstime+6,2);	
	strncpy(EsHour,EixtEstime+8,2);	
	strncpy(EsMini,EixtEstime+10,2);	
	strncpy(EsSec,EixtEstime+12,2);	

	Bstime.tm_year=atoi(BsYear)-1900;
	Bstime.tm_mon=atoi(BsMonth)-1;
	Bstime.tm_mday=atoi(BsDay);	
	Bstime.tm_hour=atoi(BsHour);	
	Bstime.tm_min=atoi(BsMini);	
	Bstime.tm_sec=atoi(BsSec);	

	Estime.tm_year=atoi(EsYear)-1900;
	Estime.tm_mon=atoi(EsMonth)-1;
	Estime.tm_mday=atoi(EsDay);	
	Estime.tm_hour=atoi(EsHour);	
	Estime.tm_min=atoi(EsMini);	
	Estime.tm_sec=atoi(EsSec);	

	start=mktime(&Bstime);	
	end=mktime(&Estime);	
	retSec=end-start;

	return retSec;
}
/******************************************************************
�������ƣ�      void LoginSuccess(char * userType)
���ã�          ��¼�ɹ�����Ҫ���Ĺ�����
������          char * userType  �շ�Ա����
����ֵ��        ��
�������ڣ�      2008.5
������:         ����ΰ
����޸�����:   2008.5
����޸���:     ����ΰ
******************************************************************/
void LoginSuccess()
{	
		char tempBillNumber[9];
		tempBillNumber[8]=0x00;
		g_TranNo=1;


		Setg_workStatus(WORKSTAUS_NORMAL);	
        SetOnJobDateTime(GetMsgHead()->YYYYMMDDHHMMSS);	
        SetExitBSMsgcollectortype(GetG_collectType());	
		sprintf(tempBillNumber,"%08d",GetbillCount()+1);	
		SetExitBSMsgWorkStatus(Getg_workStatus());	
		SetExitBSMsgBeginSTicketNo(tempBillNumber);	
		SetExitESMsgBS_TicketNo(tempBillNumber);	
		SendMessageToQueue(ID_MSGEXITBS);	        
		SetG_weiZhangType(4);	
        SendMsgInfo("�ϰ���Ϣ", "","��ʼ�ϰ�");	
		SendLaneInfo("��¼�ɹ�");	


		UI_ShowLoginTime(FALSE);
		memset(MsgHour->tmGreen,'0',sizeof(MsgHour->tmGreen));
		SendLaneInfo_default();
		UI_Set_From_Title(); 
		SendMsgInfo("��¼��Ϣ","","��¼�ɹ�");

		OpenMoneyBox();
}
/******************************************************************
�������ƣ�      void LoginOutSuccess()
���ã�          �°�ȷ�Ϻ���Ҫ���Ĺ�����
������          ��
����ֵ��        ��
�������ڣ�      2008.5
������:         ����ΰ
����޸�����:   2008.5
����޸���:     ����ΰ
******************************************************************/
void LoginOutSuccess()
{	
	SendMessageToQueue(ID_MSGEXITES);	
	InitMsgExitES();	
	InitUserNumAndNameAndOnJobDateTime();	
	Setg_workStatus(WORKSTAUS_XIABAN);	
	SendLaneInfo("�ȴ��ϰ�");	
	Setg_bYuPengOpened(F);	
	OpenMoneyBox();
	SetG_weiZhangType(4);
	SendMsgInfo("�°���Ϣ","","�����°�״̬");	
}
/************************************************************************
�������ƣ�      void BeforeOfTransDo(void)
���ã�          ���׿�ʼǰһЩ��ʼ��������
������          ��
����ֵ��        ��
�������ڣ�      2008.07
������:         ����ΰ
����޸�����:   2008.07
����޸���:     ����ΰ
*************************************************************************/
void BeforeOfTransDo()
{	
 
	Setg_DisputeType(0);	
	SetG_Current_Handl_Charge(0.0);	
	InitMsgExitTR();
	InitCarNember();
	SetG_reprintbillnum(0);	
	InitSubTransNo();	
	Initg_tuocheNum();	
	InitG_AbateNumber();
}
/************************************************************************
�������ƣ�      void AfterOfTransDo(void)
���ã�          ���׽�����һЩ��ʼ��������
������          ��
����ֵ��        ��
�������ڣ�      2008.07
������:         ����ΰ
����޸�����:   2008.07
����޸���:     ����ΰ
*************************************************************************/
void AfterOfTransDo(int value,BOOL urgen)
{	
	float tempTollFare;
	char tempTranNo[5];
	int carTypeIndex,carKindIndex;
	memset(tempTranNo,0x00,sizeof(tempTranNo));	
	SetExitTRMsgEntryLane(GetCarNember());
	if(urgen)
	{	
		tempTollFare=GetFareValue(2);	
		carTypeIndex=-1;
		carKindIndex=4;
	}
	else
	{	
		tempTollFare=GetFareValue(Get_CurrentCartypeIndex());	
		carTypeIndex=Get_CurrentCartypeIndex();	
		carKindIndex=Getg_CurrentCarKindIndex();	
	}
    if(WORKSTAUS_NORMAL==Getg_workStatus())
    {	
		Set_AllKindData(carTypeIndex,carKindIndex,tempTollFare);	
		if(0!=Getg_DisputeType())
		{	
			SetExitTRMsgMethod_Pay(MP_NotPay);	
		}
	
		sprintf(tempTranNo,"%04d",g_TranNo);	
		SetExitTRMsgtranNo(tempTranNo);	
		//������ĳ��͡����ֵ�ʱ�������
		if(0==Getg_DisputeType())
		{	
			g_TranNo++;
			SetExitESData(carTypeIndex,carKindIndex,tempTollFare);	
		}
		if(value)
		{	
			SetEixtHTData(carTypeIndex,carKindIndex,tempTollFare);	
		}
    }
    else
    {	
		Set_AllKindData(carTypeIndex,carKindIndex,tempTollFare);	
		SetExitESData(carTypeIndex,carKindIndex,tempTollFare);	
    }
 	SetICExitTRPayMethod();
	SendMessageToQueue(ID_MSGEXITTR);	
	
}
/************************************************************************
�������ƣ�      void AfterOfTransDo(void)
���ã�         ���׹����д����ϳ���ʱ��
������          ��
����ֵ��        ��
�������ڣ�      2008.07
������:         ����ΰ
����޸�����:   2008.07
����޸���:     ����ΰ
*************************************************************************/
void TransDoTuoche(void)
{	
	float tempTollFare;
	char tempTranNo[5];
	int carTypeIndex,carKindIndex;
	memset(tempTranNo,0x00,sizeof(tempTranNo));	
	tempTollFare=GetFareValue(Get_CurrentCartypeIndex());	
	carTypeIndex=Get_CurrentCartypeIndex();	
	carKindIndex=Getg_CurrentCarKindIndex();	
    if('1'==Getg_workStatus())
    {	
		Set_AllKindData(carTypeIndex,carKindIndex,tempTollFare);	
		if(0==Getg_DisputeType())
		{	
			g_TranNo++;
			SetExitESData(carTypeIndex,carKindIndex,tempTollFare);	
		}
		sprintf(tempTranNo,"%04d",g_TranNo);	
		SetExitTRMsgtranNo(tempTranNo);	
		SetEixtHTData(carTypeIndex,carKindIndex,tempTollFare);	
    }
    else
    {	
		Set_AllKindData(carTypeIndex,carKindIndex,tempTollFare);	
		SetExitESData(carTypeIndex,carKindIndex,tempTollFare);	
    }
	SetICExitTRPayMethod();
	SetExitTRMsgEntryLane(GetCarNember());
	SendMessageToQueue(ID_MSGEXITTR);	
 
	Setg_DisputeType(0);	
	SetG_Current_Handl_Charge(0.0);		
	SetG_reprintbillnum(0);	
}
///**************************************************************
//TR������������
//***************************************************************/
int DisputeType=0;
void Setg_DisputeType(int value)
{	
	DisputeType=value;
}
int Getg_DisputeType(void)
{	
	return DisputeType;
}

///*************e*************************************************
//
//***************************************************************/
int Violation=0;
void Setg_Violation(int value)
{	
	Violation=value;
}
int Getg_Violation()
{	
	return Violation;
}
//������ǰ״̬
//***************************************************************/
int CurrentLaneState;
void Setg_CurrentLaneState(int value)
{	
	CurrentLaneState=value;
}
int Getg_CurrentLaneState(void)
{	
	return CurrentLaneState;
}
/**********************************************************
��ʼ�����֡����͡��շѶ
**********************************************************/
void InitUserNumAndNameAndOnJobDateTime()
{	
	InitOnJobDateTime();	
	InitG_Number();	
	Initg_szName();	
}
void InitCarTypeKindCharge()
{	
	SetG_Current_Handl_Charge(0);	
	InitG_Current_Handl_Car_Type();	
	InitG_Current_Handl_Car_Kind();	
}
char carKindExplain[20];
void Setg_CurrentCarKindExplain(char * value)
{	
	memset(carKindExplain,0x00,20);	
	strncpy(carKindExplain,value,8);	
}
char * Getg_CurrentCarKindExplain(void)
{	
	return carKindExplain;
}
char carTypeStand[20];
void Setg_CurrentCarTypeStand(int value)
{	
	switch(value)
	{	
		case 1:
			strncpy(carTypeStand,"һ�ͳ�",sizeof("һ�ͳ�"));	
			break;
		case 2:
			strncpy(carTypeStand,"���ͳ�",sizeof("һ�ͳ�"));	
			break;
		case 3:
			strncpy(carTypeStand,"���ͳ�",sizeof("һ�ͳ�"));	
			break;
		case 4:
			strncpy(carTypeStand,"���ͳ�",sizeof("һ�ͳ�"));	
			break;
		case 5:
			strncpy(carTypeStand,"���ͳ�",sizeof("һ�ͳ�"));	
			break;
		default:
			strncpy(carTypeStand," ",sizeof(" "));	
			break;
	}
}
char * Getg_CurrentCarTypeStand(void)
{	
	return carTypeStand;
}
void SetBillNumber(void)
{	
	char tempBillNumber[9];
	memset(tempBillNumber,'0',sizeof(tempBillNumber));	
	tempBillNumber[8]=0x00;
	sprintf(tempBillNumber,"%08d",GetbillCount());	
	if(0==Getg_DisputeType())
	{	
		SetExitTRMsgReceiptNo(tempBillNumber);	
	}
}
void SetEixtTRInfo(int carTypeIndex,int carKindIndex,float TollFare)
{	
	char tempCarTypeIndex[2];
	char tempCarKindIndex[2];
	memset(tempCarTypeIndex,0x00,sizeof(tempCarTypeIndex));	
	memset(tempCarKindIndex,0x00,sizeof(tempCarKindIndex));	
	sprintf(tempCarTypeIndex,"%d",carTypeIndex+1);	
	sprintf(tempCarKindIndex,"%c",GetCarKindChar(carKindIndex));	
	SetExitTRMsgExitClass(tempCarKindIndex[0]);	
	SetExitTRMsgExitType(tempCarTypeIndex[0]);	
	SetG_Current_Handl_Car_Kind_INT(atoi(tempCarKindIndex));	
	//echoic("tempCarKindIndex  %s carKindIndex %d  GetCarKindChar %c ",tempCarKindIndex,carKindIndex,GetCarKindChar(carKindIndex));
	if(0==(int)GetG_Current_Handl_Charge())
	{	
		SetExitTRMsgReceipt('0');	
	}
	else
	{	
		if(0==Getg_DisputeType())
		{	
			SetExitTRMsgReceipt('R');
			AddExitESMsgTotal_Receipt();
		}
		else
		{	
			SetExitTRMsgReceipt('0');	
		}
	}
	if(0==Getg_DisputeType())
	{	
		SetExitTRMsgActual_pay((int)GetG_Current_Handl_Charge());	
	}
	SetExitTRMsgTollFare((int)TollFare);	
}
/***************************************************************************************
�������ƣ�      void Set_AllKindData(int carTypeIndex,int carKindIndex,float charge)
���ã�          �趨�������ݱ����ݡ�
������          int carTypeIndex,int carKindIndex,float charge
����ֵ��        ��
�������ڣ�      2008.07
������:         ����ΰ
����޸�����:   2009.2.12  
����޸���:     �����
***************************************************************************************/
void Set_AllKindData(int carTypeIndex,int carKindIndex,float TollFare)
{   
	SetEixtTRInfo(carTypeIndex,carKindIndex,TollFare);
	SetExitTRMsgMethod_Pay(GetCarKindCharge(carKindIndex));
	
	
	//echoic("GetBillFlagbyIndex(carKindIndex=%d) =%d ", carKindIndex,GetBillFlagbyIndex(carKindIndex));
	if (	GetBillFlagbyIndex(carKindIndex))
	{
			SetBillNumber();
	}
	SetExitTRMsgDiscountRate(Getg_DiscountRate());
	SetExitTRMsgServiceCard(GetG_AbateNumber());
}
