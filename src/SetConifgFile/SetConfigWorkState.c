#include "LocalIncludeFile.h"
#include <assert.h>

char *GetNetNoConfig(void);
static char *GetPlazaNoConfig(void);
static int ChangCodeInt(int nKey)
{
	if (nKey == 11)
	{
		nKey = 0;
	}
	else
	{
		nKey -=1;
	}
	return nKey;
}
static int ChangCodeChar(int nKey)
{
	switch (nKey)
	{
	case VK_0:

		nKey = 48;
		break;
	case VK_UP:
		nKey = 'U';
		break;
	case VK_DOWN:
		nKey = 'D';
		break;
	case VK_LEFT:
		nKey = 'E';
		break;
	case VK_RIGHT:
		nKey = 'X';
		break;
	case VK_GONGWU:
		nKey = '.';
		break;
	case 52:
		nKey = '.';
		break;
	default:
		nKey = nKey + 47;
		break;
	}
	return nKey;
}
char NetNo[3];
char *GetNetNoConfig()
{
	strncpy(NetNo,GetLanConfigNetNo(),2);
	NetNo[2] = 0x00;
	return NetNo;
}
char PlazaNo[3];
static char *GetPlazaNoConfig()
{
	strncpy(PlazaNo,GetLanConfigPlazaNo(),2);
	PlazaNo[2] = 0x00;
	return PlazaNo;
}
int EditConfig = 0;
char Input[20];
void initConfig(void)
{
	EditConfig = 0;
	memset(Input,0x00,20);
}
char *ShowInfo20= "��ʾ��\n1�����ó���������Ϣ\n2�����ó���ͨѶ����\n3���������贮��\n����ȡ���������ء�";
void SetWorkStation_200_SetConfig()
{	
	UI_ShowOperatorInfo("���ó���","��ѡ��������");
	Set_WorkStation(200);
	UI_Show_Info(ShowInfo20);
}
void WorkStation_200_SetConfig(int nKey)
{
	switch (nKey)
	{
	case VK_1:
		SetWorkStation_201_SetLanInfo();
		break;
	case VK_2:
		SetWorkStation_202_SetCommunction();
		break;
	case VK_3:
		SetWorkStation_203_SetCommunction();
		break;
	case VK_CANCEL:
		Set_WorkStation_30_SelectWorkMod();
		break;
	default:
		//echoic("%d",nKey);
		ErrorPressKey();
		break;
	}
}

//=============================================================================================================================================
char *ShowInfo201 = "��ʾ��\n1��·����<%s>\n2������վ����<%s>\n3��������<%s>\n4������������<%c>\n5�������շ�վ<%s>\n6���������˳���<%s>\n����ȷ�ϡ�������\n����ȡ����������";
//=====================
static void SetWorkStation_205_SetPlaza(void);
void SetWorkStation_201_SetLanInfo()
{
	char tempinfo[200];
	memset(tempinfo,0x00,200);
	UI_ShowOperatorInfo("������Ϣ","��ѡ��������");
	SetWorkState(201);                                                                                       /*�˴��޸�ԭ��:�����ַ������ض�*/
	sprintf(tempinfo,ShowInfo201,GetNetNoConfig(),GetPlazaNoConfig(),GetLanConfigLaneNo(),GetLanConfigLaneType()==NULL? '0':GetLanConfigLaneType(),GetLanConfigPlazaDesc(),GetControlLane());
	UI_Show_Info(tempinfo);
	initConfig();
}


static void ShowNewInfo201(void)
{
	char tempinfo[200];
	memset(tempinfo,0x00,200);
	switch (EditConfig)
	{
		case 1:
			sprintf(tempinfo,ShowInfo201,Input,GetPlazaNoConfig(),GetLanConfigLaneNo(),GetLanConfigLaneType(),GetLanConfigPlazaDesc(),GetControlLane());
			break;
		case 2:
			sprintf(tempinfo,ShowInfo201,GetNetNoConfig(),Input,GetLanConfigLaneNo(),GetLanConfigLaneType(),GetLanConfigPlazaDesc(),GetControlLane());
			break;
		case 3:
			sprintf(tempinfo,ShowInfo201,GetNetNoConfig(),GetPlazaNoConfig(),Input,GetLanConfigLaneType(),GetLanConfigPlazaDesc(),GetControlLane());
			break;
		case 4:	                                                                            /*�˴��޸�:��=��Ϊ==*/
			sprintf(tempinfo,ShowInfo201,GetNetNoConfig(),GetPlazaNoConfig(),GetLanConfigLaneNo(),Input[0] == 0? ' ':Input[0],GetLanConfigPlazaDesc(),GetControlLane());
			break;
		case 6:
			sprintf(tempinfo,ShowInfo201,GetNetNoConfig(),GetPlazaNoConfig(),GetLanConfigLaneNo(),GetLanConfigLaneType(),GetLanConfigPlazaDesc(),Input);
			break;
	}
	
	UI_Show_Info(tempinfo);
}

void ShowSelectitem201(void)
{
	switch (EditConfig)
	{
	case 1:
		UI_ShowOperatorInfo("������Ϣ","·����");
		break;
	case 2:
		UI_ShowOperatorInfo("������Ϣ","����վ����");
		break;
	case 3:
		UI_ShowOperatorInfo("������Ϣ","������");
		break;
	case 4:
		UI_ShowOperatorInfo("������Ϣ","����������");
		break;          
	case 6:
		UI_ShowOperatorInfo("������Ϣ","�������˳���");
		break;
	}
}
void SaveLanInfo201(void)
{
	char *Item ="";
	char SysCommamd[200];
	memset(SysCommamd,0x00,200);

	switch (EditConfig)
	{
	case 1:
		Item = "NetNo";
		break;
	case 2:
		Item = "PlazaNo";
		break;
	case 3:
		Item = "LaneNo";
		break;
	case 4:
		Item = "LaneType";
		break;
	case 6:
		Item = "ControlLane";
		break;
	}
	if(0!=EditConfig)
	{
		sprintf(SysCommamd,"sed -i \"s/%s.\\{0,20\\}=.\\{0,20\\}<.\\{0,30\\}>/%s=<%s>/g;\" "LANECONFIGFILENAME_FILE,Item,Item,Input);

		echoic("%s",SysCommamd);
		system(SysCommamd);
		LoadLanConfig();
		SetWorkStation_201_SetLanInfo();
		UI_Show_Help_Info("�����ѱ���");
	}
}

void WorkStation_201SetLanInfo(int nKey)
{

	switch (nKey)
	{
	case VK_1:
	case VK_2:
	case VK_3:
	case VK_4:
	case VK_6:
		if (0==EditConfig)
		{
			EditConfig = ChangCodeInt(nKey);
			ShowSelectitem201();
		}
		else
		{
			sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
			ShowNewInfo201();
		}
		break;
	case VK_5:              /*�޸Ĵ˴���ԭ��:���޸Ĳ˵���12346ʱ���ڱ༭״̬���˼�5������״̬205*/
		if(EditConfig == 5)
		{
		    SetWorkStation_205_SetPlaza();
		}else{
			if (0==EditConfig)
			{
				EditConfig = ChangCodeInt(nKey);
				ShowSelectitem201();
			}
			else
			{
				sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
				ShowNewInfo201();
			}
		}
		break;
	case VK_7:
	case VK_8:
	case VK_9:
	case VK_0:
    case VK_LEFT:
	case VK_RIGHT:
		if (0!=EditConfig)
		{
			sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
			ShowNewInfo201();
		}
		break;
	case VK_DOWN:         /*��Ϊ����������ֻ��дInput�ĵ�һ���ֽڣ��������һ��case����һ�������дһ���ַ�*/
    case VK_UP:
		if (0!=EditConfig)
		{
			sprintf(Input ,"%c",ChangCodeChar(nKey));
			ShowNewInfo201();
		}
		break;
	case VK_RETURN:
		SaveLanInfo201();
		break;
	case VK_CANCEL:
		if(EditConfig == 4)      /*�˴��޸�ԭ��:�޸�������ֻ������״̬,Input�ַ�����ֻ��һ���ַ�*/
		{
		    SetWorkStation_201_SetLanInfo(); 
		}else if(0!=EditConfig)
		{
			if(0==strlen(Input))
			{
				SetWorkStation_201_SetLanInfo();
			}
			else
			{
				Input[strlen(Input)-1] = 0x00;
				ShowNewInfo201();
			}
		}
		else
		{
			SetWorkStation_200_SetConfig();
		}
		break;
	default:
		echoic("%d",nKey);
		ErrorPressKey();
		break;
	}
}
char *ShowInfo202Plaza = "��ʾ��\n1: ������\n2���κ�\n3��С�ݺ�\n4����³��\n5��ͷ�ͺ�\n��ѡ���շ�վ";
void WorkStation_205SetPlaza(int nKey)
{
	char *Plaza;
	char SysCommamd[200];
	memset(SysCommamd,0x00,200);
	switch (nKey)
	{
	case VK_1:
		Plaza = "������";
		break;
	case VK_2:
		Plaza = "�κ�";
		break;
	case VK_3:
		Plaza = "С�ݺ�";
		break;
	case VK_4:
		Plaza = "��³��";
		break;
	case VK_5:
		Plaza = "ͷ�ͺ�";
		break;
	case VK_CANCEL:
		Plaza = "������";
		break;
	default:
		echoic("%d",nKey);
		ErrorPressKey();
		break;
	}
	sprintf(SysCommamd,"sed -i \"s/%s.\\{0,20\\}=.\\{0,20\\}<.\\{0,30\\}>/%s=<%s>/g;\" "LANECONFIGFILENAME_FILE,"PlazaDesc","PlazaDesc",Plaza);
	echoic("%s",SysCommamd);
	system(SysCommamd);
	LoadLanConfig();
	SetWorkStation_201_SetLanInfo();
	UI_Show_Help_Info("�����ѱ���");
}
static void SetWorkStation_205_SetPlaza(void)
{
	char tempinfo[200];
	memset(tempinfo,0x00,200);
	UI_ShowOperatorInfo("������Ϣ","��ѡ���շ�վ");
	SetWorkState(205);
	UI_Show_Info(ShowInfo202Plaza);
	initConfig();
}
//=================================================================================================================================
char *ShowInfo202 = "��ʾ��\n1: ��Ϣ������IP<%s>\n2��FTP������IP<%s>\n3��Уʱ������<%s>\n4��TCO������IP<%s>\n5������IP��ַ<%s>\n6����������<%s>\n����ȷ�ϡ�����,����ȡ��������";
void SetWorkStation_202_SetCommunction()
{
	char tempinfo[400];
	memset(tempinfo,0x00,400);	
	UI_ShowOperatorInfo("ͨѶ����","��ѡ��������");
	SetWorkState(202);
	sprintf(tempinfo,ShowInfo202,GetMagServerIP(),GetFtpServerIP(),GetTimeServerIP(),GetTCOServerIP(),Getaddress(),Getgateway());
	UI_Show_Info(tempinfo);
	initConfig();
}
void ShowNewInfo202(void)
{
	char tempinfo[400];
	memset(tempinfo,0x00,400);
	switch (EditConfig)
	{
	case 1:
		sprintf(tempinfo,ShowInfo202,Input,GetFtpServerIP(),GetTimeServerIP(),GetTCOServerIP(),Getaddress(),Getgateway());
		break;
	case 2:
		sprintf(tempinfo,ShowInfo202,GetMagServerIP(),Input,GetTimeServerIP(),GetTCOServerIP(),Getaddress(),Getgateway());
		break;
	case 3:
		sprintf(tempinfo,ShowInfo202,GetMagServerIP(),GetFtpServerIP(),Input,GetTCOServerIP(),Getaddress(),Getgateway());
		break;
	case 4:
		sprintf(tempinfo,ShowInfo202,GetMagServerIP(),GetFtpServerIP(),GetTimeServerIP(),Input,Getaddress(),Getgateway());
		break;
	case 5:
		sprintf(tempinfo,ShowInfo202,GetMagServerIP(),GetFtpServerIP(),GetTimeServerIP(),GetTCOServerIP(),Input,Getgateway());
		break;
	case 6:
		sprintf(tempinfo,ShowInfo202,GetMagServerIP(),GetFtpServerIP(),GetTimeServerIP(),GetTCOServerIP(),Getaddress(),Input);
		break;
	}
	UI_Show_Info(tempinfo);
}
void ShowSelectitem202(void)
{
	switch (EditConfig)
	{
	case 1:
		UI_ShowOperatorInfo("ͨѶ����","��Ϣ������IP");
		break;
	case 2:
		UI_ShowOperatorInfo("ͨѶ����","FTP������IP");
		break;
	case 3:
		UI_ShowOperatorInfo("ͨѶ����","Уʱ������IP");
		break;
	case 4:
		UI_ShowOperatorInfo("ͨѶ����","TCO������IP");
		break;
	case 5:
		UI_ShowOperatorInfo("ͨѶ����","����IP��ַ");
		break;
	case 6:
		UI_ShowOperatorInfo("ͨѶ����","��������");
		break;
	}
}
#define ADD			"echo \"        address %s\" > /EMRCV3/CONFIG/ETH1%c"
#define NETMASK		"echo \"        netmask 255.255.255.0\" >> /EMRCV3/CONFIG/ETH1"
#define NETWOEK		"echo \"        network %s\" >> /EMRCV3/CONFIG/ETH1%c"
#define BORADCAST	"echo \"        broadcast 192.168.50.255\" >> /EMRCV3/CONFIG/ETH1"
#define GETEWAY		"echo \"        gateway %s\" >> /EMRCV3/CONFIG/ETH1%c"
#define DNS			"echo \"        dns-nameservers 61.128.114.133\" >> /EMRCV3/CONFIG/ETH1"


static void SetLocalIP(void )
{
	char SysCommamd[200];
	sprintf(SysCommamd,ADD,Getaddress(),0);
	system(SysCommamd);
	system(NETMASK);
	sprintf(SysCommamd,NETWOEK,Getgateway(),0);
	system(SysCommamd);
	system(BORADCAST);
	sprintf(SysCommamd,GETEWAY,Getgateway(),0);
	system(SysCommamd);
	system(DNS);
	system("cat /EMRCV3/CONFIG/ETH0 > /etc/network/interfaces");
	system("cat /EMRCV3/CONFIG/ETH1 >> /etc/network/interfaces");
	system("/etc/init.d/networking restart");
}


void SaveLanInfo202(void)
{
	char *Item="";
	char SysCommamd[200];
	memset(SysCommamd,0x00,200);
	switch (EditConfig)
	{
	case 1:
		Item = "MagServerIP";
		break;
	case 2:
		Item = "FtpServerIP";
		break;
	case 3:
		Item = "TimeServerIP";
		break;
	case 4:
		Item = "TCOServerIP";
		break;
	case 5:
		Item = "address";
		break;
	case 6:
		Item = "gateway";
		break;
	}
	if(0!=EditConfig)
	{
		sprintf(SysCommamd,"sed -i \"s/%s.\\{0,20\\}=.\\{0,20\\}<.\\{0,30\\}>/%s=<%s>/g;\" "CONFCOMMUNCTION_FILE,Item,Item,Input);
		system(SysCommamd);
		SetLocalIP();
		LoadCommunctionConfig();
		SetWorkStation_202_SetCommunction();
		UI_Show_Help_Info("�����ѱ���");
	}
}

void WorkStation_202_SetCommunction(int nKey)
{
	switch (nKey)
	{
	case VK_1:
	case VK_2:
	case VK_3:
	case VK_4:
	case VK_5:
	case VK_6:
		if (0==EditConfig)
		{
			EditConfig =ChangCodeInt(nKey);
			ShowSelectitem202();
		}
		else
		{
			sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
			ShowNewInfo202();
		}
		break;
	
	case VK_7:
	case VK_8:
	case VK_9:
	case VK_0:
	case VK_UP:
	case VK_DOWN:
	case VK_LEFT:
	case VK_RIGHT:
	case VK_GONGWU:
	case 52:
		if (0!=EditConfig)
		{
			sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
			ShowNewInfo202();
		}
		break;
	case VK_RETURN:
		SaveLanInfo202();
		break;
	case VK_CANCEL:
		if(0!=EditConfig)
		{
			if(0==strlen(Input))
			{
				SetWorkStation_202_SetCommunction();
			}
			else
			{
				Input[strlen(Input)-1] = 0x00;
				ShowNewInfo202();
			}
		}
		else
		{
			SetWorkStation_200_SetConfig();
		}
		break;
	default:
		echoic("%d",nKey);
		ErrorPressKey();
		break;
	}
}
//====================================================================================================================================
char *ShowInfo203 = "��ʾ��\n1: �����ʾ������<%s>\n2��Ʊ�ݴ�ӡ������<%s>\n3�����ش���<%s>\n4����д������<%s>\n����ȷ�ϡ�������\n����ȡ����������";
void SetWorkStation_203_SetCommunction()
{
	char tempinfo[200];
	memset(tempinfo,0x00,200);
	UI_ShowOperatorInfo("��������","��ѡ��������");
	SetWorkState(203);
	sprintf(tempinfo,ShowInfo203,sys_ini.led_tty,sys_ini.print_tty,"δ����","δ����");
	UI_Show_Info(tempinfo);
	initConfig();
}
void ShowNewInfo203(void)
{
	char tempinfo[200];
	memset(tempinfo,0x00,200);
	switch (EditConfig)
	{
	case 1:
			sprintf(tempinfo,ShowInfo203,Input,sys_ini.print_tty,"δ����","δ����");
		break;
	case 2:
			sprintf(tempinfo,ShowInfo203,sys_ini.led_tty,Input,"δ����","δ����");
		break;
	case 3:
			sprintf(tempinfo,ShowInfo203,sys_ini.led_tty,sys_ini.print_tty,"δ����","δ����");
		break;
	case 4:
			sprintf(tempinfo,ShowInfo203,sys_ini.led_tty,sys_ini.print_tty,"δ����","δ����");
		break;
	}
	UI_Show_Info(tempinfo);
}
void ShowSelectitem203(void)
{
	switch (EditConfig)
	{
	case 1:
		UI_ShowOperatorInfo("��������","�����ʾ������");
		break;
	case 2:
		UI_ShowOperatorInfo("��������","Ʊ�ݴ�ӡ������");
		break;
	case 3:
		UI_ShowOperatorInfo("��������","���ش���");
		break;
	case 4:
		UI_ShowOperatorInfo("��������","��д������");
		break;
	}
}
void SaveLanInfo203(void)
{
	char *Item="";
	char SysCommamd[200];
	memset(SysCommamd,0x00,200);
	switch (EditConfig)
	{
	case 1:
		Item = "led_tty";
		break;
	case 2:
		Item = "print_tty";
		break;
	case 3:
		Item = "";
		break;
	case 4:
		Item = "";
		break;
	}
	if(0!=EditConfig)
	{
		sprintf(SysCommamd,"cd /EMRC-S303/CONFIG;sed -i \"s/%s.\\{0,20\\}=.\\{0,20\\}<.\\{0,30\\}>/%s=<%s>/g;\" "LANEOLDCONFIG_FILE,Item,Item,Input);
		system(SysCommamd);
		read_sys_ini_file();
		SetWorkStation_203_SetCommunction();
		UI_Show_Help_Info("�����ѱ���");
	}
}
void WorkStation_203_SetDevConfig(int nKey)
{
	switch (nKey)
	{
	case VK_1:
	case VK_2:
		if (0==EditConfig)
		{
			EditConfig =ChangCodeInt(nKey);
			ShowSelectitem203();
		}
		else
		{
			sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
			ShowNewInfo203();
		}
		break;
	case VK_3:
	case VK_4:
		if (0!=EditConfig)
		{
			sprintf(Input+strlen(Input),"%c",ChangCodeChar(nKey));
			ShowNewInfo203();
		}
		break;
	case VK_RETURN:
		SaveLanInfo203();
		break;
	case VK_CANCEL:
		if(0!=EditConfig)
		{
			if(0==strlen(Input))
			{
				SetWorkStation_203_SetCommunction();
			}
			else
			{
				Input[strlen(Input)-1] = 0x00;
				ShowNewInfo203();
			}
		}
		else
		{
			SetWorkStation_200_SetConfig();
		}
		break;
	default:
		echoic("%d",nKey);
		ErrorPressKey();
		break;
	}
}
      