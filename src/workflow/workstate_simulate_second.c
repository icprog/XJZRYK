#include "LocalIncludeFile.h"

void WorkStation_46_SimulateTwoOk(int nKey)
{
	switch (nKey)
	{
	case VK_1: 
		SendMsgInfo("�쳣��Ϣ","","��Ȧ�쳣");	   
		SendMsgInfo("ģ����Ϣ","","����ģ��");	
		SetLanGan(F);
		SetExitTRMsgPassageLoopError('1');
		AddYCQK("����ģ��");
		AddExitESMsgCounter1();
		SetExitTRMsgDisputeType('1');
	case S_PASSLINEUP:			
		SetJiaoTong(F);		
		if (0!=GetG_IsTuoche())
		{
			AddYCQK("���ϳ�");
		}
		AfterOfTransDo(1,F);
		SetG_IsTuoche(0);		
		SendMsgInfo("������Ϣ","","��ͨ����");	   
		Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
		InitCarTypeKindCharge();
		SendLaneInfo_default();
		LedClare(F);
		SendLaneInfo("�ȴ�����");
		break;
	case VK_2:
		if ( 1==GetG_BillPrintFlag())
		{
			if (GetG_reprintbillnum()<atoi(sys_ini.reprintbillnum))
			{
				AddG_reprintbillnum ();
				RePrintBill();
				if (10==GetG_simulateWorkState())
				{
					Set_WorkStation_10_Up_Parapet_Pass();
				}
				AddExitESMsgCounter5();
				SendMsgInfo("ģ����Ϣ","","�ش�Ʊ��");
				AddYCQK("�ش�Ʊ��");
				SetExitTRMsgDisputeType('5');
			}
			else
			{
				UI_Show_Help_Info("�ش�Ʊ�ݴ�������!");
			}

		}
		else
		{
			UI_Show_Help_Info("��ѳ�û��Ʊ�ݣ�");
			setLed();
		}
		break;
	default:
		ErrorPressKey();
		break;
	}
}

