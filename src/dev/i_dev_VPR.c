#include "LocalIncludeFile.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dlfcn.h>
//#include  "i_dev_VPR_HK.h"
#include "i_dev_VPR_HW.h"
//#include "i_dev_VPR_UC.h"
BOOL  CPSB_isInit = F ;
int CPSB_UnLoad(void)
{
	if(!CPSB_isInit)
	{
		CPSB_isInit = T;
		/*	if (0 == strcmp("HK", GetVPRDLL()))
		{
		CPSB_isInit=VPR_HK_UnLoad();
		}
		else */
		//if (0 == strcmp("HW", GetVPRDLL()))
		{
			CPSB_isInit=VPR_HW_UnLoad();
		}
		/*	else if (0 == strcmp("UC", GetVPRDLL()))
		{
		CPSB_isInit=VPR_UC_UnLoad();
		}*/

	}
	return CPSB_isInit;
}
int CPSB_Load(void)
{
	int r=0;
	//if (0 == strcmp("HK", GetVPRDLL()))
	//{
	//	r =	VPR_HK_Load();
	//}
	//else 
	//if (0 == strcmp("HW", GetVPRDLL()))
	{
		r=VPR_HW_Load();
	}
	/*else 	if (0 == strcmp("UC", GetVPRDLL()))
	{
	r=VPR_UC_Load();
	}*/
	/*else 
	{
	echo_vpr("Unknow vpr name!!!");
	}*/
	return r;
}
int DVR_Open(void)
{
	int r=0;
	//if (0 == strcmp("HK", GetVPRDLL()))
	//{
	//	r= VPR_HK_Open();
	//}
	//else
	//if (0 == strcmp("HW", GetVPRDLL()))
	{
		r= VPR_HW_Open();
	}
	/*else if (0 == strcmp("UC", GetVPRDLL()))
	{

	}*/
	/*else 
	{
	echo_vpr("Unknow vpr name!!!");
	}*/

	return  r ;
}
void DVR_Close(void)
{
	/*if (0 == strcmp("HK", GetVPRDLL()))
	{
	VPR_HK_Close();
	}
	else */
	//	if (0 == strcmp("HW", GetVPRDLL()))
	{
		VPR_HW_Close();
	}
	/*	if (0 == strcmp("UC", GetVPRDLL()))
	{
	VPR_UC_Close();
	}*/
	/*	else 
	{
	echo_vpr("Unknow vpr name!!!");
	}*/
}
void ClearCPHM(void)
{
	//if (0 == strcmp("HK", GetVPRDLL()))
	//{
	//	VPR_HK_ClearCPHM();
	//}
	//else  
	//	if (0 == strcmp("HW", GetVPRDLL()))
	{
		VPR_HW_ClearCPHM();
	}
	/*else  	if (0 == strcmp("UC", GetVPRDLL()))
	{
	VPR_UC_ClearCPHM();
	}*/
	//else 
	//{
	//	echo_vpr("Unknow vpr name!!!");
	//}
}
char * GetCPHM(void )
{
	//if (0 == strcmp("HK", GetVPRDLL()))
	//{
	//	return VPR_HK_GetCPHM( );
	//}
	//else
	//	if (0 == strcmp("HW", GetVPRDLL()))
	{
		return VPR_HW_GetCPHM( );
	}
	/*else if (0 == strcmp("UC", GetVPRDLL()))
	{
	return VPR_UC_GetCPHM( );
	}*/
	/*else 
	{
	echo_vpr("Unknow vpr name!!!");
	}*/
	//return "δʶ��";

}

void i_dev_VPR_ReceivePlate(void )
{
	char CarNo[20];
	memset(CarNo,0x00,20);
	strncpy(CarNo,(char*)&GetCPHM()[3],5);
	echo_vpr("ȡ���ĳ��ƺ�����:::::%s   || CarNo: %s",GetCPHM(),CarNo);
	if (strncmp(CarNo,"�޳���",6)!=0)
	{
		echo_vpr("�г��ƺ�  %s",GetCPHM());
		if (CheckCarInfo(GetCPHM())  && (GetWorkState()==3  ||  GetWorkState()==4 || GetWorkState()==49  ))
		{
			char temp[200];
			memset(temp,0x00,sizeof(temp));
			Set_WorkStation_204_FreeCar();
			SetG_AbateNumber(CarNo);
			WorkStation_204_FreeCar(VK_GONGWU);
			sprintf(temp,"��ʾ��\n��˶���Ϣ��\n%s\n����ȷ�ϡ������ء�\n�������񡿼�ֱ�ӷ���\n����ȡ������ȡ����",GetCarInfo(GetG_AbateNumber()));
			UI_Show_Info(temp);
		}
	}
	else 
	{
		echo_vpr("��Ч���ƣ� ������");
	}
}

