#include "../global/include/LocalIncludeFile.h"
void Set_WorkStation(int Index)
{
	SetWorkState(Index);    
	UI_Set_From_Title();
}
void Set_WorkStation_00_Wait_Begin_Work()
{   
	UI_Show_Info("��ʾ��\n�ϰ��밴���ϰࡿ����");
	UI_SetFromColor(F);
	UI_ShowLoginTime(T);    
	UI_ShowOperatorInfo( "","");  
	UI_Set_From_Title(); 
	Setg_bReLogin(F);   
	SetCloseDev();  
	Set_WorkStation(0); 
	Setg_CurrentLaneState(10);  
	SendLaneInfo_default(); 
}

void Set_WorkStation_01_Handl_Input_Number()
{   
	UI_Show_Info("��ʾ��\n������6λ�ϰ๤�ţ�\n����ȷ�ϡ���ȷ�ϣ�\n����ȡ������ȡ����");
	UI_Draw_Login_UserNmber( "����");  
	UI_Show_UserNumber_Text("");  
	UI_Show_Login_UserPwd(""); 
	InitInput_Number_Count();
	SetInputLen( 0);
	InitG_Number();
	Set_WorkStation(1);
	Setg_CurrentLaneState(0);
}
void Set_WorkStation_02_Handl_Input_Password()
{   
	char temp[200];
	memset(temp,'\0',200);  
	sprintf(temp,"��ʾ��\n%s��%s��\n������4-6λ���룬\n����ȷ�ϡ���ȷ�ϣ�\n����ȡ������ȡ����", GetG_collectTypeStr(),trim(Getg_szName()));   
	UI_Draw_Login_UserPwd( "����");  
	UI_Show_Login_UserPwd("");  
	InitInput_Number_Count();   
	InitInput_Password_Count( );    
	SetInputLen(0); 
	IntiG_Password();

	UI_Show_Info(temp); 

	Set_WorkStation(2); 
	Setg_CurrentLaneState(0);   

}

/**
 * ����3״̬����չ״̬�������ʼ����ʱ ����״̬ǰ�ĳ�ʼ�������� 
 * 
 * @param left
 * @param right
 */
void Set_WorkStation_03_Main_Work_extracted1(char * left, char * right)
{
	char temp[30];
	memset(temp,0x00,30);
	BeforeOfTransDo();
	UI_ClearCarKind(); 
	UI_ClearCarType(); 
	UI_ClearCarMoney();    
	LedClare(F);   
	UI_ShowOperatorInfo(left,right);
	if (Getg_Ring())
	{
		SetRing(F); 
	}
	SetG_Urgent_Car_Team_Enabled(F);    
	Setg_bReLogin( T);  
	SetInputLen(0); 
	SetsecondLogin( T); 
	InitG_Car_Type();   

}

/**
 * �˷���Ϊ 3״̬ �ĳ�ʼ����չ������ ���� ����״̬���ͨ�ò����� 
 */
void Set_WorkStation_03_Main_Work_extracted2(void)
{
	Setg_CurrentLaneState(1);   
	SetRingVoide(F);    
	InitCardContext();
	SendLaneInfo_default();
}
void Set_WorkStation_03_Main_Work2(char *left,char *right)
{   
	Set_WorkStation_03_Main_Work_extracted1(left, right);
	UI_Show_Info("��ʾ��\n��������ơ���������ƣ�\n�򰴡��°ࡿ���°ࡣ");
	Set_WorkStation(49);    
	Set_WorkStation_03_Main_Work_extracted2();
}
void Set_WorkStation_03_Main_Work3(char *left,char *right)
{   
	Set_WorkStation_03_Main_Work_extracted1(left, right);
	UI_Show_Info("��ʾ��\n�������֡������복�͡�");
	Set_WorkStation(51);    
	Set_WorkStation_03_Main_Work_extracted2();
}
void Set_WorkStation_03_Main_Work(char *left,char *right)
{   	
	LedClare(F);
	Set_WorkStation_03_Main_Work_extracted1(left, right);
	UI_Show_Info((0==Getg_bYuPeng()) ? "��ʾ��\n�������������\n�����°ࡿ���°࣬\n��������ơ���������ơ�":
		"��ʾ��\n�������֡������복�ͣ�\n���������������������");
	Set_WorkStation(3); 
	Set_WorkStation_03_Main_Work_extracted2();
	UI_Clear_Login_And_Input();
}

void Set_WorkStation_04_General_Validate_Car_Type_And_First_OK()
{   
	UI_ShowOperatorInfo("�����շ�","��ȷ�ϳ���");	
	UI_Show_Info("��ʾ��\n����ȷ�ϡ��������շѳ�\n�����Żݡ��������Żݳ�\n������Ʊ����������Ʊ��\n�������񡿼�������\n�������������������\n����ȡ������ȡ����");	
	Set_WorkStation(4);
	Setg_CurrentLaneState(11);
}
void Set_WorkStation_204_FreeCar()
{   
	InitG_AbateNumber();
	UI_ShowOperatorInfo("���복�ƺţ�","");	
	UI_Show_Info("��ʾ��\n�������֡����복�ƺź�3λ��\n����󰴡�ȷ�ϡ���ȷ��,\n����ȡ�������������롣");	
	Set_WorkStation(204);
}
void Set_WorkStation_06_Closed_Road()
{   
	UI_ClearCarKind(); 
	UI_ClearCarType(); 
	UI_ClearCarMoney(); 
	UI_ShowOperatorInfo("�����ѷ��","�ȴ�����");
	SetYuPeng(F);	
	UI_Show_Info("��ʾ��\n����������ʱ�ر�״̬��\n�������������򿪳�����");
	Set_WorkStation(6); 
	Setg_CurrentLaneState(2);   
}

void Set_WorkStation_07_General_Second_OK(char *left,char *rihgt)
{   
	char charge[10];
	char temp[200];
	char tmpxxx[100];
	char *carnumber = GetCarNember();
	memset(tmpxxx,0x00,100);
	UI_ShowOperatorInfo(left,rihgt);
	InitG_SaveBeforTipOne();
	InitG_SaveBeforTipTwo();
	SetG_SaveBeforTipOne(left);
	SetG_SaveBeforTipTwo(rihgt);	
	UI_Show_Info("7״̬����Ӧλ��");
	Set_WorkStation(7);
	Setg_CurrentLaneState(12);
	SendLaneInfo(left);
	memset(charge,'\0',10); 
	sprintf(charge,"%1.0f",GetG_Current_Handl_Charge());    
	memset(temp,'\0',200);  
	if (GetEnableIC())
	{
		sprintf(tmpxxx,"�ֿ�������ˢ��\n");
	}
	if(' '!=carnumber[0])
	{
		sprintf(tmpxxx,"���ƺţ�%s,\n",carnumber);
	}
	if (0==GetG_IsTuoche())
	{
		sprintf(temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ ��\n%s����ȷ�ϡ���̧�˷��У�\n����Ƿ�������Ƿ�\n����ģ�⡿�������ϳ�ģ�⡢���ĳ��͡����֡�",Getg_CurrentCarKindExplain(),charge,tmpxxx);    
		UI_Show_Info(temp);    
	}
	else
	{
		sprintf(temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ ��\n%s����ȷ�ϡ���ȷ��,\n����ģ�⡿�����ĳ��͡����֡�",Getg_CurrentCarKindExplain(),charge,tmpxxx);   
		UI_Show_Info(temp);    
	}

}

void Set_WorkStation_09_Handl_Urgent_Car_Team()
{   	
	UI_ShowOperatorInfo("��������","��������");	
	UI_Show_Info("��ʾ��\n����ȷ�ϡ���̧�˷��У�\n����ȡ������ȡ����");
	Set_WorkStation(9); 
	Setg_CurrentLaneState(14);  
}
void Set_WorkStation_10_Up_Parapet_Pass()
{   
	SetPassCar();
	UI_ShowOperatorInfo("�����շ�","��������ͨ����");	
	UI_Show_Info("��ʾ��\n��������ͨ����\n����ģ�⡿����ģ�������");
	Set_WorkStation(10);    
	SetroadCridState('4');   
	Setg_CurrentLaneState(4);   
	UI_Clear_Login_And_Input();
}
void Set_WorkStation_13_Urgent_Car_Team_Passing()
{   
	SetPassCar();   
	//SetLanGan(T);	
	SetInputLen(0); 
	SetG_Urgent_Car_Team_Enabled(T);    
	SetG_Car_Pass_Count(0); 
	InitG_Car_Type();   
	UI_ClearCarKind(); 
	UI_ClearCarType(); 
	UI_ClearCarMoney();    
	UI_ShowOperatorInfo("��������","����ͨ��");	
	UI_Show_Info("��ʾ��\n������������ͨ����\n���ȷ�ϳ����Ѿ�ͨ����\n��������������������Ĳ���");
	Set_WorkStation(13);    
	Setg_CurrentLaneState(16);  
}


void Set_WorkStation_16_Handl_Urgent_Car_Team_End()
{   
	UI_ShowOperatorInfo("������������","��ȷ�ϻ�ȡ��");	
	UI_Show_Info("��ʾ��\n����ȷ�ϡ���ȷ�Ͻ�����\n����ȡ������ȡ��������");
	Set_WorkStation(16);    
	Setg_CurrentLaneState(16);  
}

void Set_WorkStation_20_EndWorkOk()
{   
	UI_ShowOperatorInfo("�°����","��ȷ��");	
	UI_Show_Info("��ʾ��\n����ȷ�ϡ���ȷ�ϣ�\n����ȡ���������ء�");
	Set_WorkStation(20);    
	Setg_CurrentLaneState(17);  
	SendMsgInfo("׼���°�","","�ȴ�ȷ���°�");	//qq
	SendLaneInfo("׼���°�");
}

void Set_WorkStation_49_WeiZhang(void)
{   
	if (!Getg_bWeiZhang())
	{
		CaptureImg(IMG_SECOND);
		SetG_CurrentInfoTemp(GetG_CurrentInfo());   
		SetG_BeforWzWorkstation(GetWorkState());    
		Setg_bWeiZhang(TRUE);   
		SetG_weiZhangState(0);  
		UI_Show_Info("��ʾ: ��ѡ����Ȧ����ԭ��\n1. ����\n2. ����\n3. �󱨾�"); 
		SetG_BeforWzLaneState(Getg_CurrentLaneState()); 
		Setg_CurrentLaneState(7);   
	}
}
void Set_WorkStation_59_WeiZhangHandl(char *weiZhangType)
{   
	char tempInfo[150];
	Setg_bWeiZhang( TRUE);  
	SetG_weiZhangState(1);  
	sprintf(tempInfo,"��ʾ��Υ�����ͣ�%s\n����ȷ�ϡ���ȷ��\n����ȡ����ȡ����%c",weiZhangType,'\0'); 
	UI_Show_Info(tempInfo); 
	Setg_CurrentLaneState(7); 
}

void Set_WorkStation_23_Abate(char *Type)
{  	
	if (2<strlen(Type))
	{		   
		if (0==strcmp(Type,"�Żݿ���"))
		{
			Setg_AbateType(0);  
		}
		else
		{
			Setg_AbateType(1);  
		}
	}
	UI_Draw_Input_Text(Type); 
	UI_Show_Input_Text("");  
	SetInputLen(0); 
	InitG_AbateNumber(); 
	UI_Show_Info("��ʾ��\n�������֡������뿨�ţ�\n����ȡ������ȡ����\n����ȷ�ϡ�������");
	Set_WorkStation(23);    
	Setg_CurrentLaneState(9);   
	SetRingVoide(T);    
}

void Set_WorkStation_30_SelectWorkMod()
{   
	UI_ShowOperatorInfo( "","");	
	UI_Show_Info("��ʾ��\n��ѡ����ģʽ��\n1��ģ���շ�\n2���豸���\n3���������� \n4���ػ�\n5���ر��շ����\n6�������������\n7���޸ĳ�������\n����ȡ�������˳���½");
	Set_WorkStation(30);    
	Setg_CurrentLaneState(30);  
	SetYuPeng(F);   
	SetJiaoTong(F); 
	SetLanGan(F);   
	SetRing(F); 
	SendLaneInfo_default(); 
}
void Set_WorkStation_31_SelectCheckDev()
{   	
	UI_ShowOperatorInfo("�豸���","��ѡ���豸");
	UI_Show_Info("��ʾ��\n1:������˻�\n2:���ͨ�е�\n3:��������\n4:����ӡ��\n5:����շѼ���\n6:�������ʾ��\n7:��ⱨ����\n8:����ַ�����;��ȡ��������");
	Set_WorkStation(31);    
	Setg_CurrentLaneState(18);  
}
void Set_WorkStation_32_CheckBar()
{   
	UI_ShowOperatorInfo("�豸���","����");	
	UI_Show_Info("��ʾ��\n���˼����ѡ��\n1��̧�˼��\n2����˼��\n����ȡ������ȡ����");
	Set_WorkStation(32);    
	Setg_CurrentLaneState(19);  
}
void Set_WorkStation_33_CheckPassLight()
{   
	UI_ShowOperatorInfo("�豸���","ͨ�е�");	
	UI_Show_Info("��ʾ��\nͨ�еƼ����ѡ��\n1����Ƽ��\n2���̵Ƽ��\n����ȡ������ȡ����");
	Set_WorkStation(33);    
	Setg_CurrentLaneState(20);  
}
void Set_WorkStation_34_CheckSkyLight()
{   
	UI_ShowOperatorInfo("�豸���","�����");	
	UI_Show_Info("��ʾ��\n����Ƽ����ѡ��\n1����Ƽ��\n2���̵Ƽ��\n����ȡ������ȡ����");
	Set_WorkStation(34);    
	Setg_CurrentLaneState(21);  
}
void Set_WorkStation_35_SelectCheckResult()
{    
	UI_ShowOperatorInfo("�豸���","�����");
	UI_Show_Info("��ʾ��\n�豸��Ӧ��ȷ\n    �򰴡�ȷ�ϡ������ء�\n    �豸��Ӧ����,\n    �򰴡�ȡ���������أ�\n    ������豸�����¼�⡣");
	Set_WorkStation(35);    
	Setg_CurrentLaneState(26);  
}

void Set_WorkStation_36_CheckPrinterResult()
{   
	UI_ShowOperatorInfo( "��ӡ�����","�����");
	UI_Show_Info("��ʾ��\n��ӡ�����Ʊ��������\n   �򰴡�ȷ�ϡ������أ�\n   ��ӡ��Ʊ�ݴ����δ��ӡ,\n   �򰴡�ȡ���������أ�\n   ������豸�����¼�⡣");
	Set_WorkStation(36);    
	Setg_CurrentLaneState(22);  
}

void Set_WorkStation_37_CheckKeyBord()
{  
	UI_ShowOperatorInfo( "���̼��","���ڼ��");	
	UI_Show_Info("��ʾ��\n�밴���̽��а������\n    ����ȡ������������һ����");
	Set_WorkStation(37);    
	Setg_CurrentLaneState(23);  
}
void Set_WorkStation_38_CheckKeyBordResult()
{
	UI_ShowOperatorInfo( "���̼��","�����"); 
	UI_Show_Info("��ʾ��\n��ȡ���������������\n    ����ȫ�����������\n    ����1�������ء�\n    ����������\n    ����2�������أ�\n    ����ȷ�ϡ����������ԡ�");
	Set_WorkStation(38);    
	Setg_CurrentLaneState(27);  
}

void Set_WorkStation_39_CheckRing()
{ 
	UI_ShowOperatorInfo( "�豸���","������");  	
	UI_Show_Info("��ʾ��\n�����������ѡ��\n1���������\n2���رձ������\n����ȡ������ȡ����");
	Set_WorkStation(39);    
	Setg_CurrentLaneState(25);
}

void Set_WorkStation_40_InPutWzCarType()
{   
	UI_Show_Info("��ʾ�������봳��������\n  1��һ�ͳ�\n  2�����ͳ�\n  3�����ͳ�\n  4�����ͳ�\n  5�����ͳ�\n  6����������\n  ����ȡ���������ء�");
	Set_WorkStation(40);    
	Setg_CurrentLaneState(28);  
}

void Set_WorkStation_41_WzOK(char *CarType)
{   
	char temp[200];
	memset(temp,'\0',200);  
	sprintf(temp,"��ʾ��\n���������ͣ�%s\n����ȷ�ϡ���ȷ�ϣ�\n����ȡ���������ء�",CarType);    
	Setg_CurrentLaneState(29);  
	UI_Show_Info(temp);    
}

void Set_WorkStation_42_HandArrearageNumber(int BefWorkStation)
{   
	char * Info = "��ʾ��\n�밴���ּ�����1��%dλ��Ƿ���\n����ȷ�ϡ���ȷ�ϣ�\n����ȡ���������ء�";
	char temp[200];
	UI_Draw_Input_Text( "Ƿ���");  
	UI_Show_Input_Text("");  
	InitG_ArrearageNumber();  	
	UI_Show_Info(Info);
	Set_WorkStation(42);    
	memset(temp,'\0',200);  
	sprintf(temp,Info, atoi(sys_ini.MaxArrearageNumber));   
	UI_Show_Info(temp);    
	SetG_BeforWzWorkstation(BefWorkStation); 
	SetWorkState( 42);  
}
void Set_WorkStation_43_HandArrearageCharge()
{   
	char temp[200];
	char tempNumber[50];
	char * Info =/* 43 */"��ʾ��\nǷ��ţ�%s\n�밴�����֡�������Ƿ����\n����ȷ�ϡ���ȷ�ϣ�\n����ȡ���������ء�";
	UI_Draw_Input_Text( "Ƿ����");  
	UI_Show_Input_Text("");  
	memset(tempNumber,'0',50);  
	InitG_ArrearageChargeChar();    
	strcpy(tempNumber + atoi(sys_ini.MaxArrearageNumber) - strlen(GetG_ArrearageNumber()),GetG_ArrearageNumber());  
	memset(temp,'\0',200);  
	sprintf(temp,Info /*promptInformation[43]*/,tempNumber); 
	UI_Show_Info(temp);    
	SetWorkState ( 43); 
}


void SetWorkSationEndWz()
{   
	SetWorkState   (GetG_BeforWzWorkstation() );    
	Setg_bWeiZhang( F); 
	SetG_weiZhangState(-1); 
	UI_Show_Info(GetG_CurrentInfoTemp());  
	SetRing(F); 
	Setg_CurrentLaneState(GetG_BeforWzLaneState()); 
	if (7==GetWorkState())
	{
		Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");    
	}
	Setg_bWeiZhangCount(0); 
}
void Set_WorkStation_44_TestLed(void)
{   
	UI_ShowOperatorInfo( "�豸���","�����ʾ��");  

	Setg_CurrentLaneState(31);  
}

void Set_WorkStation_45_SimulateOnceOk()
{   
	UI_ShowMenu("ģ��˵�","��ʾ��\n��ѡ��ģ�����ͣ�%s","1�����ĳ���\n2�����ĳ���\n3���ϳ�ģ��");
	Set_WorkStation(45);    
	Setg_CurrentLaneState(8);   
}
/*****************************************************
�����ϳ�ģ��󣬲����ٽ����ϳ�ģ��ʱ�����״̬��
By:����ΰ
******************************************************/
void Set_WorkStation_53_SimulateOnceOkTuoche()
{   
	UI_ShowMenu("ģ��˵�","��ʾ��\n��ѡ��ģ�����ͣ�%s","1�����ĳ���\n2�����ĳ���");
	Set_WorkStation(53);    
	Setg_CurrentLaneState(8);   
}
void Set_WorkStation_46_SimulateTwoOk()
{   
	UI_ShowMenu("ģ��˵�","��ʾ��\n��ѡ��ģ�����ͣ�%s","1������ģ��\n2���ش�Ʊ��");
	Set_WorkStation(46);    
	Setg_CurrentLaneState(8);   
}

void Set_WorkStation_47_FavourCardOK(char *left,char *rihgt,char *startData,char *endData)
{   
	char Temp[250];
	char charge[10];
	//char * Info =/* 47 */"��ʾ��\n���֣�%s �շѣ�%s Ԫ��\n��Ч����%s\nʧЧ����%s\n����ȷ�ϡ���ȷ��\n����ģ�⡿�������ϳ�ģ�⡢���ĳ��͡����֡���";
	UI_ShowOperatorInfo( left,rihgt);    
	InitG_SaveBeforTipOne();    
	InitG_SaveBeforTipTwo();    
	SetG_SaveBeforTipOne(left);  
	SetG_SaveBeforTipTwo(rihgt);    
	memset(Temp,0x00,250);  
	memset(charge,'\0',10); 
	sprintf(charge,"%1.0f",GetG_Current_Handl_Charge());    
	if (0==GetG_IsTuoche())
	{
		if(GetG_IsIC())
		{
			sprintf(Temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ��\n���ƺ��룺%s��\n��Ч����:%s,ʧЧ����%s\n����ȷ�ϡ���ȷ��\n����ģ�⡿�������ϳ�ģ�⡢���ĳ��͡����֡�",Getg_CurrentCarKindExplain(),charge,ICCard_GetCard()->Plate,startData,endData);  
		}
		else
		{
			sprintf(Temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ��\n���ƺ��룺%s��\n��Ч����%s\nʧЧ����%s\n����ȷ�ϡ���ȷ��\n����ģ�⡿�����ĳ��͡����֡�" /*promptInformation[47]*/,Getg_CurrentCarKindExplain(),charge,Get_YPK_CarNo(),startData,endData); 
		}
	}
	else
	{
		if(GetG_IsIC())
		{
			sprintf(Temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ��\n���ƺ��룺%s��\n��Ч����:%s,ʧЧ����%s\n����ȷ�ϡ���ȷ��\n����ģ�⡿�����ĳ��͡����֡�",Getg_CurrentCarKindExplain(),charge,ICCard_GetCard()->Plate,startData,endData);  
		}
		else 
		{
			sprintf(Temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ��\n���ƺ��룺%s��\n��Ч����%s\nʧЧ����%s\n����ȷ�ϡ���ȷ��\n����ģ�⡿�����ĳ��͡����֡�",Getg_CurrentCarKindExplain(),charge,Get_YPK_CarNo(),startData,endData);   
		}
	}
	UI_Show_Info(Temp);
	
	//UI_Show_Info(Info);
	SetWorkState(47);   
	Setg_CurrentLaneState(12);  
}
void Set_WorkStation_48_VK_OK()
{   
	char * Info =/* 48 */"��ʾ��\n����������ȷ\n�밴��ȷ�ϡ���ȷ�ϡ�";
	UI_Show_Info(Info);
	Set_WorkStation(48);    
	Setg_CurrentLaneState(0);   
}
void Set_WorkStation_52_VKABATE_OK()
{   
	UI_Show_Info("��ʾ��\n����ȷ�ϡ���ȷ�Ͽ���,\n����ȡ������ȡ�������뿨�š�");
	Set_WorkStation(52);    
	Setg_CurrentLaneState(12);  
}
void Set_WorkStation_52_ICVKABATE_OK()
{   
	Set_WorkStation(52);    
	Setg_CurrentLaneState(12);  
	WorkStation_52_Abate_OK(VK_RETURN);
}
void  Set_WorkStation_50_DataExporter(void)
{   
	UI_Show_Info("��ʾ��\n�������֡������복�͡�");
	Set_WorkStation(50);   
	UI_Show_Info("��ʾ��\n�뽫���Ŀ��ƶ��洢�豸����USB�ڡ�ȷ���豸����������\n����ȷ�ϡ�����ʼ������\n����ȡ�������˳��˲�����");    
}

void Set_WorkStation_56_CheckCharFold()
{   
	UI_ShowOperatorInfo( "�豸���","�ַ�����");	
	UI_Show_Info("��ʾ��\n���ڽ����ַ����Ӽ�⡭��	\n    ����ȡ���������ز��Խ���\n    ����ȷ�ϡ����鿴�������");
	Set_WorkStation(56);    
	Setg_CurrentLaneState(56);  
}

void Set_WorkStation_57_CheckCharFoldResult()
{   
	UI_ShowOperatorInfo( "�ַ����Ӽ��","�����");  	
	UI_Show_Info("��ʾ��\n����ȷ�ϡ������ء�");
	Set_WorkStation(57);    
	Setg_CurrentLaneState(57);  
}
void Set_WorkStation_60_ConfirmPayBy_MonthCard(void)
{
	Set_WorkStation(60);
}
void Set_WorkStation_61_ConfirmPayBy_SVCCard(void)
{
	Set_WorkStation(61);
}

void Set_WorkStation_62_ConfirmPayBy_OfficialCard(void)
{
	Set_WorkStation(62);
}
void Set_WorkStation_63_IC_Moni_SVC(void)
{
	Set_WorkStation(63);
	UI_Show_Info("��ʾ��\nѡ��ģ�����ͣ�\n1���ϳ�ģ��\n����ȡ���������ء�");
}
void Set_WorkStation_64_IC_Moni_Month(void)
{
	Set_WorkStation(64);
	UI_Show_Info("��ʾ��\nѡ��ģ�����ͣ�\n1���ϳ�ģ��\n����ȡ���������ء�");
}
void Set_WorkStation_65_IC_Moni_Official(void)
{
	Set_WorkStation(65);
	UI_Show_Info("��ʾ��\nѡ��ģ�����ͣ�\n1���ϳ�ģ��\n����ȡ���������ء�");
}

void Set_WorkStation_66_InputCarNo(char *left)
{   
	char charge[10];
	char temp[200];
	UI_Draw_Input_Text( left);	
	UI_Show_Input_Text("");
	Set_WorkStation(66);
	Setg_CurrentLaneState(12);	
	SendLaneInfo(left);
	memset(charge,'\0',10); 
	sprintf(charge,"%1.0f",GetG_Current_Handl_Charge());    
	memset(temp,'\0',200);  	
	sprintf(temp,"��ʾ��\n���֣�%s �շѣ�%s Ԫ��\n�������֡����복�ƺź�3λ��\n����󰴡�ȷ�ϡ���ȷ��,\n����ȡ�������������롣",Getg_CurrentCarKindExplain(),charge);    
	UI_Show_Info(temp);  

}
