// ***************************************************************
//  UserContext   version:  1.0   ��  date: 5/05/2008
//  -------------------------------------------------------------
//  �������ӹ�����Ϣ����������
//  -------------------------------------------------------------
//  Copyright (C) 2008 - All Rights Reserved
// ***************************************************************
#include "LocalIncludeFile.h"
/*******************************************************************************/
 //��������
/*******************************************************************************/
volatile BOOL G_Urgent_Car_Team_Enabled = F;
void SetG_Urgent_Car_Team_Enabled(BOOL  value)
{	
    G_Urgent_Car_Team_Enabled=value;
}

int GetG_Urgent_Car_Team_Enabled(void)
{	
    return G_Urgent_Car_Team_Enabled;
}

/*******************************************************************************/
////��ͨ���ӹ�������
/*******************************************************************************/
volatile int G_Car_Pass_Count=0;

void AddG_Car_Pass_Count(void)
{	
    ++G_Car_Pass_Count;
}

void DesG_Car_Pass_Count(void)
{	
    G_Car_Pass_Count--;
}


void SetG_Car_Pass_Count(int value)
{	
    G_Car_Pass_Count=value;
}

int GetG_Car_Pass_Count(void)
{	
    return G_Car_Pass_Count;
}

/*******************************************************************************/
////����ͨ���ĳ���������
/*******************************************************************************/
volatile int G_Car_Passed_Count=0;

void AddG_Car_Passed_Count(void)
{	
    ++G_Car_Passed_Count;
}

void SetG_Car_Passed_Count(int value)
{	
    G_Car_Passed_Count=value;
}


int GetG_Car_Passed_Count(void)
{	
    return G_Car_Passed_Count;
}

/*******************************************************************************/
////����ʾ�б�����ʾ������б���
/*******************************************************************************/
volatile int G_Max_Show_Car_Pass_Count=7;
void SetG_Max_Show_Car_Pass_Count(int value)
{	
    G_Max_Show_Car_Pass_Count=value;
}
/*****************************************/
int GetG_Max_Show_Car_Pass_Count(void)
{	
    return G_Max_Show_Car_Pass_Count;
}

/*******************************************************************************/
////��ǰ��ʾ�����Ŀ�ʼ����
/*******************************************************************************/
volatile int G_Show_Car_Tem_Index=0;
void SetG_Show_Car_Tem_Index(int value)
{	
    G_Show_Car_Tem_Index=value;
}

void AddG_Show_Car_Tem_Index(void)
{	
    ++G_Show_Car_Tem_Index;
}

void DesG_Show_Car_Tem_Index(void)
{	
    G_Show_Car_Tem_Index--;
}


int GetG_Show_Car_Tem_Index(void)
{	
    return G_Show_Car_Tem_Index;
}

/*******************************************************************************/
//���Ǹ�״̬Υ�� Υ�´�������Զ����ص����״̬
/*******************************************************************************/
volatile int G_weiZhangState=0;

void SetG_weiZhangState(int  value)
{	
    G_weiZhangState=value;
}

int GetG_weiZhangState(void)
{	
    return G_weiZhangState;
}

/*******************************************************************************
//Υ������
0-	����
1-	Υ��
2-	����
3-	�󱨾�
4-   Ϊ�˷���SendMsgInfo��Ϣ�ķ��㣬����Ϣʱ����Ӧ���ַ�
******************************************************************************/
volatile int G_weiZhangType;

void SetG_weiZhangType(int  value)
{	
     G_weiZhangType=value;
}

int GetG_weiZhangType(void)
{	
    return  G_weiZhangType;
}

/*******************************************************************************/
//ģ������
/*******************************************************************************/
volatile int G_simulateType=0;
void SetG_simulateType(int  value)
{	
     G_simulateType=value;
}

int GetG_simulateType(void)
{	
    return  G_simulateType;
}

/*******************************************************************************/
//�������ƶ��ģ����� ģ�������ֻ���ش�Ʊ�ݿ���������
/*******************************************************************************/
volatile BOOL G_simulateEnabled = T;
void SetG_simulateEnabled(BOOL value)
{	
     G_simulateEnabled=value;
}

int GetG_simulateEnabled(void)
{	
    return  G_simulateEnabled;
}

/*******************************************************************************/
//��ʶ���Ǹ�����״̬���е�ģ����� ��ͬ�Ĺ���״̬����ģ����ɺ󽫻ص�ʲô״̬
/*******************************************************************************/
volatile int G_simulateWorkState=0;
void SetG_simulateWorkState(int value)
{	
     G_simulateWorkState=value;
}

int GetG_simulateWorkState(void)
{	
    return  G_simulateWorkState;
}

/*******************************************************************************/
//�Ƿ�����ش�Ʊ�� ��ֻ���շѳ�����ѳ������ش�Ʊ�ݣ�
/*******************************************************************************/
volatile BOOL G_billRePrintEnabled;
void SetG_billRePrintEnabled(BOOL  value)
{	
     G_billRePrintEnabled=value;
}

int GetG_billRePrintEnabled(void)
{	
    return  G_billRePrintEnabled;
}

/*******************************************************************************/
 //�ش�Ʊ�ݴ���
/*******************************************************************************/
volatile int G_reprintbillnum=0;
void SetG_reprintbillnum(int value)
{	
     G_reprintbillnum=value;
}
void AddG_reprintbillnum(void)
{	
    G_reprintbillnum++;
}
int GetG_reprintbillnum(void)
{	
    return  G_reprintbillnum;
}

/*******************************************************************************/
//Ʊ�ݺŲ�һ�µ�ʱ��
/*******************************************************************************/
void SetbillNumber_str(char * value)
{	
    SetbillCount( atoi(value));	
	writeBillNumber();	
}
char tempbillNumber_str[9];
char * GetbillNumber_str(void)
{	
    memset(tempbillNumber_str,'0',sizeof(tempbillNumber_str));	
    tempbillNumber_str[8]=0x00;
    sprintf(tempbillNumber_str,"%3.3s%05d",GetLanConfigLaneNo(),GetbillCount());	
    return tempbillNumber_str;
}
/*******************************************************************************/

/*******************************************************************************/
volatile BOOL G_Loop_Enable = T;
void SetG_Loop_Enable(BOOL  value)
{	
     G_Loop_Enable=value;
}

int GetG_Loop_Enable(void)
{	
    return  G_Loop_Enable;
}

/*******************************************************************************/
//���ӱ�ʾ�ڲ�����Ϣʱ�õ�
/*******************************************************************************/

int carTem = 0;
void SetcarTem(int value)
{	
     carTem=value;
}

int GetcarTem(void)
{	
    return carTem;
}

/*******************************************************************************/
////���ڽ��г��Ӵ���
/*******************************************************************************/

volatile BOOL  G_Car_Team_Enabled=F;
void SetG_Car_Team_Enabled(BOOL value)
{	
     G_Car_Team_Enabled=value;
}

int GetG_Car_Team_Enabled(void)
{	
    return  G_Car_Team_Enabled;
}

/*******************************************************************************/
//���ƺ�
/*******************************************************************************/
char G_CarNumber[9] ;
void  SETG_CarNumber_end(int value)
{	
    G_CarNumber[value] = '\0';
}

void  InitG_CarNumber(void)
{	
        memset(G_CarNumber, '\0', 9);	
}
void SetG_CarNumber(char *value)
{	
    strncpy(G_CarNumber,value,sizeof(G_CarNumber));	
}

char *GetG_CarNumber(void)
{	
    return G_CarNumber;
}
/*******************************************************************************/
//
/*******************************************************************************/
int G_BeforWzWorkstation = -1;
void SetG_BeforWzWorkstation(int value)
{	
     G_BeforWzWorkstation=value;
}

int GetG_BeforWzWorkstation(void)
{	
    return G_BeforWzWorkstation;
}

/*******************************************************************************/
//
/*******************************************************************************/
int G_BeforWzLaneState = -1;
void SetG_BeforWzLaneState(int value)
{	
     G_BeforWzLaneState=value;
}

int GetG_BeforWzLaneState(void)
{	
    return G_BeforWzLaneState;
}

/*******************************************************************************
*Ʊ�ݴ�ӡ��־
*0 ��Ҫ
*1ֻһ�ξ���ȷ��ӡ���վ�
2 ������˺Ʊ
3 �ش�Ĵ���(16����)
4-   Ϊ�˷���SendMsgInfo��Ϣ�ķ��㣬����Ϣʱ����Ӧ���ַ�
*******************************************************************************/
int G_BillPrintFlag = -1;
void SetG_BillPrintFlag(int value)
{	
     G_BillPrintFlag=value;
}

int GetG_BillPrintFlag(void)
{	
    return G_BillPrintFlag;
}

/*******************************************************************************/
// Ƿ���
/*******************************************************************************/
char G_ArrearageNumber[20];

void  InitG_ArrearageNumber(void)
{	
    memset(G_ArrearageNumber,'\0',20);	
}

void  SETG_ArrearageNumber_end(int value)
{	
     G_ArrearageNumber[value-1]='\0';
}

void SetG_ArrearageNumber(char *value)
{	
    strncpy(G_ArrearageNumber,value,sizeof(G_ArrearageNumber));	
}

char *GetG_ArrearageNumber(void)
{	
    return G_ArrearageNumber;
}
/*******************************************************************************/
//Ƿ���
/*******************************************************************************/

int G_ArrearageCharge=0;
void SetG_ArrearageCharge(int value)
{	
     G_ArrearageCharge=value;
}

int GetG_ArrearageCharge(void)
{	
    return G_ArrearageCharge;
}

/*******************************************************************************/
//Ƿ���
/*******************************************************************************/
char G_ArrearageChargeChar[20];

void  SETG_ArrearageChargeChar_end(int value)
{	
     G_ArrearageChargeChar[value-1]='\0';
}


void InitG_ArrearageChargeChar(void)
{	
    memset(G_ArrearageChargeChar,'\0',20);	
}

void SetG_ArrearageChargeChar(char *value)
{	
    strncpy(G_ArrearageChargeChar,value,sizeof(G_ArrearageChargeChar));	
}

char *GetG_ArrearageChargeChar(void)
{	
    return G_ArrearageChargeChar;
}
/*******************************************************************************/
//�Ƿ��м�������ͨ���ӵ���������
/*******************************************************************************/
BOOL inCarTeamOtherCar =F;
void SetinCarTeamOtherCar(BOOL   value)
{	
    inCarTeamOtherCar=value;
}
BOOL GetinCarTeamOtherCar(void)
{	
    return inCarTeamOtherCar;
}
/*******************************************************************************/
//��ǰ�����ĳ���
/*******************************************************************************/
char G_Current_Handl_Car_Type[4];
void InitG_Current_Handl_Car_Type()
{	
	memset(G_Current_Handl_Car_Type,' ',4);	
    I_DEV_VDM_CarType(" ");	
}
void SetG_Current_Handl_Car_Type(char *value)
{	
    strncpy(G_Current_Handl_Car_Type,value,sizeof(G_Current_Handl_Car_Type));	
    I_DEV_VDM_CarType(value);	
}

char *GetG_Current_Handl_Car_Type(void)
{	
    return G_Current_Handl_Car_Type;
}
int Get_Current_Car_Type_Index(void)
{	
	int ret = -1;
	ret=atoi(GetG_Current_Handl_Car_Type())-1;
	return ret;
}
/*******************************************************************************/
////��ǰ�����ĳ���
/*******************************************************************************/
char G_Current_Handl_Car_Kind[9];
int G_Current_Handl_Car_Kind_int =0;
void InitG_Current_Handl_Car_Kind()
{	
	memset(G_Current_Handl_Car_Kind,' ',9);	
    G_Current_Handl_Car_Kind_int=-2;
   I_DEV_VDM_CarKind(G_Current_Handl_Car_Kind_int);	
}
void SetG_Current_Handl_Car_Kind(char *value)
{	
    strncpy(G_Current_Handl_Car_Kind,value,sizeof(G_Current_Handl_Car_Kind));	
}

char *GetG_Current_Handl_Car_Kind(void)
{	
    return G_Current_Handl_Car_Kind;
}

void SetG_Current_Handl_Car_Kind_INT(int value)
{	
  G_Current_Handl_Car_Kind_int=value;
}

int GetG_Current_Handl_Car_Kind_INT(void)
{	
    return G_Current_Handl_Car_Kind_int;
}

/*******************************************************************************/
////��ǰ�������Ľ��
/*******************************************************************************/
volatile float G_Current_Handl_Charge=0;
void SetG_Current_Handl_Charge(float value)
{	
    G_Current_Handl_Charge=value;
	I_DEV_VDM_Cash((int)value);
}
float GetG_Current_Handl_Charge(void)
{	
    return G_Current_Handl_Charge;
}
float Get_G_Current_Actual_pay(void)
{	
	return G_Current_Handl_Charge;
}
volatile float G_Current_Toll_Fare=0;
float Get_G_Current_Toll_Fare(void)
{	
	return G_Current_Toll_Fare;
}
void Set_G_Current_Toll_Fare(float value)
{	
	G_Current_Toll_Fare=value;
	echoic("Get_G_Current_Actual_pay <%f>Get_G_Current_Toll_Fare<%f><%f><%f>",Get_G_Current_Actual_pay(),value,G_Current_Toll_Fare,Get_G_Current_Toll_Fare());
}






char tempCharge[12];
char * GetG_Current_Handl_Charge_str()
{	

	if(0==(int)G_Current_Handl_Charge)
	{	
		memset(tempCharge,' ',12);	
		return tempCharge;
	}
	else
	{	
		memset(tempCharge,' ',12);	
		sprintf(tempCharge,"%d",(int)G_Current_Handl_Charge);	
		return tempCharge;
	}
}
/*******************************************************************************/
////��ǰ���ӵ��ܽ��
/*******************************************************************************/

int G_Current_Car_Team_Charge_Total=0;
void SetG_Current_Car_Team_Charge_Total(int value)
{	
    G_Current_Car_Team_Charge_Total=value;
}

int GetG_Current_Car_Team_Charge_Total(void)
{	
    return G_Current_Car_Team_Charge_Total;
}

/*******************************************************************************/
////��ʾ�����ӳ�����Ϣ
/*******************************************************************************/
char G_Show_Handl_Car_Information[300];
void SetG_Show_Handl_Car_Information(char *value)
{	
    strncpy(G_Show_Handl_Car_Information,value,sizeof(G_Show_Handl_Car_Information));	
}

void InitG_Show_Handl_Car_Information(void)
{	
     memset(G_Show_Handl_Car_Information, '\0', 300);	
}

void strcatG_Show_Handl_Car_Information(char * value)
{	
        strcat(G_Show_Handl_Car_Information, value);	
}


char *GetG_Show_Handl_Car_Information(void)
{	
    return G_Show_Handl_Car_Information;
}
/*******************************************************************************/
////����
/*******************************************************************************/
char G_Car_Type[9];

void InitG_Car_Type(void)
{	
    memset(G_Car_Type, '\0', 9);	
}

void SETG_Car_Type_end(int value)
{	
        G_Car_Type[value] = '\0';
}


void SetG_Car_Type(char* value)
{	
    strncpy(G_Car_Type,value,sizeof(G_Car_Type));	
}
char  *GetG_Car_Type(void)
{	
    return G_Car_Type;
}


/**
 * ���ͼ�غ���
 */
void SendTcoWaingMsg(char *Msg)
{
	char title[80];
	char context[80];
	char path [80];
	memset(title,0x00,strlen(title));
	memset(context,0x00,strlen(context));
	memset(path,0x00,strlen(path));
	if (EnabledCallTCS()==F)
	{
		return;
	}
	if (0== 1 && GetDevCStatePlazaServerState())
	{
		return;
	}
	InitMsgTCO();   
	GetMsgTCO()->MsgType =MSGTCO_CMD_TCOWAING ;
	sprintf(title,"%s%-60s","��ʾ",SUBSTRING(GetMsgHead()->LaneNo));
	strncpy(GetMsgTCO()->MsgTitle,title,sizeof(GetMsgTCO()->MsgTitle));
	sprintf(context,"%-60s",Msg);
	strncpy(GetMsgTCO()->MsgContext,context,sizeof(GetMsgTCO()->MsgContext));
	sprintf(path,"%-60s",BuildTCOImage(MSGTCO_CMD_TCOWAING,Msg));
	strncpy(GetMsgTCO()->MsgImagePath,path,sizeof(GetMsgTCO()->MsgImagePath));
	SendMessageToQueue(ID_TCOMSG ); 
	echoic("��Ϣ%s \nͼƬ��ַ%s",Msg,SUBSTRING(GetMsgTCO()->MsgImagePath));
}
char _YCQK[100];
void InitYCQK(void)
{
	memset(_YCQK,0x00,100);
}
void AddYCQK(char * tmp)
{
	int l=0;
	if (tmp==NULL || strlen(tmp)>32)
	{
		return;
	}
	if (strlen(_YCQK)>0)
	{
		l =strlen(_YCQK)+strlen(tmp);
		echoic("LLLLLLLLLLLLLLL=%d   :::%s",l,_YCQK);
		if (l<=31)
		{
			sprintf(_YCQK,"%s/%s",_YCQK,tmp);
			_YCQK[33]=0;
		}
	}
	else
	{
		sprintf(_YCQK,"%s",tmp);
	}
}
char * GetYCQK(void)
{
	strncpy(_YCQK,_YCQK,32);
	return _YCQK;
}
struct Information_Node * Create_InforNode()
{
	struct Information_Node * Node;
	Node = (struct Information_Node * ) malloc (INFORMATION_NODE_LEN); 
	Node->Next = NULL;
	Node->Back = NULL;
	strcpy(Node->Car_Type , GetG_Car_Type());  
	strcpy(Node->Car_Kind, Getg_CurrentCarKindExplain());  
	strcpy(Node->Car_Team,GetG_Car_Team_Enabled() ? "����:":"");   
	Node->Charge = GetG_Current_Handl_Charge();    
	return Node;
}
void FreeG_Head_Information_Node()
{
	struct Information_Node * Node;
	Node = G_Head_Information_Node->Next ;
	while (G_Head_Information_Node != Node)
	{
		G_Head_Information_Node->Next = Node->Next;
		free(Node); 
		Node = G_Head_Information_Node->Next;
	}

}

void Add_Handl_Car_Information(int Index)
{	
    char StrTemp[9];
    int i = 0;
   struct  Information_Node *P, *P1;
    P = Create_InforNode();	

    AddG_Car_Pass_Count();	
    //AddExitESMsgTotal_MotorCade();	
    if (GetG_Car_Pass_Count() > GetG_Max_Show_Car_Pass_Count())
    {	
        SetG_Show_Car_Tem_Index(GetG_Car_Pass_Count() -GetG_Max_Show_Car_Pass_Count());	
    }
    memset(StrTemp, '\0', 9);	
    if(GetG_Car_Team_Enabled())
    {	
        if (GetG_Car_Pass_Count()<10)
        {	
            sprintf(StrTemp,"��0%d��",GetG_Car_Pass_Count());	
        }
        else
        {	
            sprintf(StrTemp,"��%d��",GetG_Car_Pass_Count());	
        }
    }
    else
    {	
        strcpy(StrTemp,"�ǳ���");	
    }
    strcpy(P->Car_Team,StrTemp);	
    P1 = G_Head_Information_Node;
    if (Index==0)
    {	
        if(GetG_Car_Team_Enabled())
        {	
            //���ǳ��ӵ�ʱ����ں���
            P->Back= P1->Back;
            P1->Back->Next= P;
            P->Next = P1;
            P1->Back = P;
        }
        else
        {	
            //���ǵ�ʱ����ں���
            P->Next= P1->Next;
            P1->Next->Back= P;
            P->Back = P1;
            P1->Next = P;


        }

    }
    else
    {	
        for (i=0;i<Index;i++)
        {	
            P1 = P1->Next;
        }
        P->Next= P1->Next;
        P1->Next->Back= P;
        P->Back = P1;
        P1->Next = P;
    }



}

void Reduce_Handl_Car_Information()
{	
    struct Information_Node *P;
    char Strtemp[9];
    int Count =0;
    AddG_Car_Passed_Count();	
    //AddMsgtotal_official();	
    P = G_Head_Information_Node->Next ;

    while(P !=G_Head_Information_Node)
    {	
        Count ++;
        if (Count ==GetG_Car_Passed_Count())
        {	
            memset(Strtemp, '\0', 9);	
            sprintf(Strtemp,"*%s",P->Car_Team);	
            strcpy(P->Car_Team,Strtemp);	
            break;
        }
        P = P->Next;
    }
}
void Delete_Handl_Car_Information(int index)
{	
    struct Information_Node *P;
    P = G_Head_Information_Node->Back;
    if (P==G_Head_Information_Node)
    {	
        //Set_WorkStation_05_Start_Car_Team();	
    }
    else
    {	
        if (-1==index)
        {	
            DesG_Car_Pass_Count();	
            G_Head_Information_Node->Back = P->Back;
            P->Back->Next = G_Head_Information_Node;
            free(P);	
            //Show_Handl_Car_Information("��ʾ����ͨ�����б�\n");	

        }
        else
        {	
            int i;
            P=G_Head_Information_Node;
            for(i=0;i<=index;i++)
            {	
                P=P->Next;
            }
            P->Back->Next=P->Next;
            P->Next->Back = P->Back;
            free(P);	
        }
    }
}




