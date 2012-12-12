#include "LocalIncludeFile.h"

BOOL WorkFlow_Peccancy(int nKey)
{
	BOOL ok=F;
	if (Getg_bWeiZhang())
	{
		WorkFlow_WeiZhang(nKey);
		ok=TRUE;
	}
	else if (nKey==VK_WEIZHANG)
	{
		Set_WorkStation_49_WeiZhang();
		SetRing(T);
		ok=TRUE;
	}
	return ok;
}
void WorkFlow_WeiZhang(int nKey)
{

		if (GetG_weiZhangState()==0)
		{
			WorkStation_49_WeiZhang(nKey);
		}
		else if (GetG_weiZhangState()==1)
		{
			WorkStation_59_WeiZhangHandl(nKey);
		}
		else if (2 == GetG_weiZhangState())
		{
			WorkStation_40_InPutWzCarType(nKey);
		}
		else if (3 == GetG_weiZhangState())
		{
			WorkStation_41_WzOK(nKey);
		}
}
void WorkStation_40_InPutWzCarType(nKey)
{
	switch (nKey)
	{
		case VK_1:
			wzCarType=1;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("һ�ͳ�");
			break;
		case VK_2:
			wzCarType=2;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("���ͳ�");
			break;
		case VK_3:
			wzCarType=3;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("���ͳ�");
			break;
		case VK_4:
			wzCarType=4;
			SetG_weiZhangState(3);
			Set_WorkStation_41_WzOK("���ͳ�");
			break;
		case VK_5:
			SetG_weiZhangState(3);
			wzCarType=5;
			Set_WorkStation_41_WzOK("���ͳ�");
			break;
		case VK_6:
			SetG_weiZhangState(3);
			wzCarType=6;
			Set_WorkStation_41_WzOK("������δ֪");
			break;
		case VK_CANCEL:
			SetG_weiZhangState(0);
			UI_Show_Info("��ʾ: ��ѡ����Ȧ����ԭ��\n1. ����\n2. ����\n3. �󱨾�");
			Setg_CurrentLaneState(7);
			break;
		default:
			ErrorPressKey();
			break;
	}
}

void WorkStation_41_WzOK(int nKey)
{
	switch (nKey)
	{
		case VK_RETURN:
			Setg_Violation(1);
			AddMsgTotal_Violation();
			AddExitESMsgTotal_Violation();
			switch (wzCarType)
			{
				case 1:
					SendMessageWzCar(wzCarType);
					break;
				case 2:
					SendMessageWzCar(wzCarType);
					break;
				case 3:
					SendMessageWzCar(wzCarType);
					break;
				case 4:
					SendMessageWzCar(wzCarType);
					break;
				case 5:
					SendMessageWzCar(wzCarType);
					break;
			}
			SendTcoWaingMsg("������");
			SetWorkSationEndWz();
			break;
		case VK_CANCEL:
			SetG_weiZhangState(2);
			Set_WorkStation_40_InPutWzCarType();
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_49_WeiZhang(int nKey)
{
	switch (nKey)
	{
		case VK_1:
			SetG_weiZhangState(2);
			Set_WorkStation_40_InPutWzCarType();
			break;
		case VK_2:
			SetG_weiZhangType(2);
			Set_WorkStation_59_WeiZhangHandl("����");
			break;
		case VK_3:
			SetG_weiZhangType(3);
			Set_WorkStation_59_WeiZhangHandl("�󱨾�");
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_59_WeiZhangHandl(int nKey)
{
	switch (nKey)
	{
		case VK_RETURN:
			SetWorkSationEndWz();
			if (GetG_weiZhangType()==2)
			{
				SendMsgInfo("Υ����Ϣ","","����");
				SetG_weiZhangType(0);
			}
			else if (GetG_weiZhangType()==3)
			{
				SendMsgInfo("Υ����Ϣ","","�󱨾�");
				SetG_weiZhangType(0);
			}
			break;
		case VK_CANCEL:
			SetG_weiZhangState(0);
			UI_Show_Info("��ʾ: ��ѡ����Ȧ����ԭ��\n1. ����\n2. ����\n3. �󱨾�");
			Setg_CurrentLaneState(7);
			break;
		default:
			ErrorPressKey();
			UI_Show_Help_Info("������Ч���밴��ʾ���в�����");
			break;
	}
}
