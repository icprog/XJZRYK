#include "LocalIncludeFile.h"

void WorkStation_45_SimulateOnceOk_MoNITuoche(void)
{
	Addg_tuocheNum();
	SetG_IsTuoche(1);
	if (WorkStation_07_FUN_General_Second_OK_7(0))
	{
		AddExitESMsgCounter4();
		SendLaneInfo("�ϳ�ģ��");
		SendMsgInfo("ģ����Ϣ","","�����ϳ�");
		AddYCQK("�ϳ�");
		SetExitTRMsgDisputeType('4');
		TransDoTuoche();
		SendMsgInfo("������Ϣ","","��ͨ����");
		InitMsgExitTR();
		SendLaneInfo_default();
		Set_WorkStation_03_Main_Work3("�����շ�","ģ���ϳ�");
		InitCarTypeKindCharge(); 
	}
}
void WorkStation_45_SimulateOnceOk(int nKey)
{
	switch (nKey)
	{
		case VK_1:
			Setg_DisputeType(1);
			AddExitESMsgCounter2();
			SendLaneInfo("���ĳ���");
			SendMsgInfo("ģ����Ϣ","","���ĳ���");
			AddYCQK("���ĳ���");
			InitCarTypeKindCharge();
			SendLaneInfo_default();
			SetExitTRMsgDisputeType('2');
			AfterOfTransDo(0,F);
			Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
			break;
		case VK_2:
			Setg_DisputeType(1);
			AddExitESMsgCounter3();
			SendLaneInfo("���ĳ���");
			SendMsgInfo("ģ����Ϣ","","���ĳ���");
			AddYCQK("���ĳ���");
			InitCarTypeKindCharge();
			SendLaneInfo_default();
			SetExitTRMsgDisputeType('3');
			AfterOfTransDo(0,F);
			Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
			break;
		case VK_3:
			WorkStation_45_SimulateOnceOk_MoNITuoche();
			break;
		case VK_CANCEL:
			//�Ƿ����ȡ��ģ��״̬
			if (1==atoi(sys_ini.SimulateEnabledCancel))
			{
				Set_WorkStation_07_General_Second_OK(GetG_SaveBeforTipOne(),GetG_SaveBeforTipTwo());
			}
			else
			{
				ErrorPressKey();
			}
			break;
	default:
		ErrorPressKey();
		break;
	}
}
void WorkStation_53_SimulateOnceOkTuoche(int nKey)
{
	switch (nKey)
	{
		case VK_3:
			ErrorPressKey();			
		default:
			WorkStation_45_SimulateOnceOk(nKey);
			break;
	}
}

