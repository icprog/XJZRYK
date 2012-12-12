#include "LocalIncludeFile.h"
#include "mac.h"
#include "imf.h"
#include "3des.h"

/*----------------------------------------------------------------------
�������ƣ�      void WorkStation_0_Wait_Begin_Work(int nKey)
���ã�          ���������ȴ��ϰ࣬�°����ϰࡣ
������          int nKey ���̼�ֵ
����ֵ��        ��
��̣�          WorkStation (1)
�������ڣ�      2005.10
������:         ĪԶ��
����޸�����:   2008.05
����޸���:     ����ΰ
----------------------------------------------------------------------*/

void WorkStation_03_Main_Work(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			SendLaneInfo("������");
			UI_SetCarType(nKey);
			Set_WorkStation_04_General_Validate_Car_Type_And_First_OK(); 
			break;
		case VK_CLOSE_YPD:
			if (Getg_bYuPeng())
			{
				UI_Show_Info("��ʾ��\n���Լ����������\n�򰴡��°ࡿ���°�\n�򰴡�����ơ���������ơ�");
				SetYuPeng(F);
			}
			else{
				//UI_Show_Info("YPD closed");
			}
			break;
		case VK_OPEN_YPD:
			if (!Getg_bYuPeng())
			{
				UI_Show_Info("��ʾ��\n�������֡������복�ͣ�\n�������ӡ��������ӡ�");
			}
			SetYuPeng(T);
			break;
		case VK_URGENT:
			Set_WorkStation_09_Handl_Urgent_Car_Team();
			break;
		case VK_CLOSE:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("��ȳ���ͨ����رճ���!");
			}
			else
			{
				Set_WorkStation_06_Closed_Road();
				SendMsgGR(MSGGR_CANOPY_OFF);
				SendLaneInfo_default();;
			}
			break;
		case VK_XIABAN:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("��ȳ���ͨ�����°�!");
			}
			else if (Getg_bYuPeng())
			{
				UI_Show_Help_Info("���ȹر�������ٰ����°ࡿ����");
			}
			else
			{
				SendLaneInfo("�����°�");
				Set_WorkStation_20_EndWorkOk();
			}
			break;
		case VK_MONI:
			if (1==atoi(sys_ini.SimulateEnabledFistTuoChe) && (1==GetG_IsTuoche()))
			{
				SetG_simulateWorkState(10);
				Set_WorkStation_45_SimulateOnceOk();
			}
			else
			{
				ErrorPressKey();
			}
			break;
		case VK_CHAHAO:
			Set_WorkStation_204_FreeCar();
			break;
		case S_PASSLINEUP:
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_03_Main_Work3(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			SendLaneInfo("������");
			UI_SetCarType(nKey);
			Set_WorkStation_04_General_Validate_Car_Type_And_First_OK();
		 
			break;
		case VK_CLOSE_YPD:
			if (Getg_bYuPeng())
			{
				UI_Show_Info("��ʾ��\n�������������\n�����°ࡿ���°࣬\n��������ơ���������ơ�");
			}
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			if (!Getg_bYuPeng())
			{
				UI_Show_Info("��ʾ��\n�������֡������복�ͣ�\n����������������������ӡ�");
			}
			SetYuPeng(T);
			break;
		case VK_CLOSE:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("��ȳ���ͨ����رճ���!");
			}
			else
			{
				Set_WorkStation_06_Closed_Road();
				SendMsgGR(MSGGR_CANOPY_OFF);
				SendLaneInfo_default();
			}
			break;
		case VK_URGENT:
			Set_WorkStation_09_Handl_Urgent_Car_Team();
			break;
		case VK_XIABAN:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("��ȳ���ͨ�����°�!");
			}
			else if (Getg_bYuPeng())
			{
				UI_Show_Help_Info("���ȹر�������ٰ����°ࡿ����");
			}
			else
			{
				Set_WorkStation_20_EndWorkOk();
			}
			break;
		case S_PASSLINEUP://ģ�������ѹ��Ȧ���α���
			if (1==YaxianquanNum)
			{
				SetRing(T);
				Set_WorkStation_49_WeiZhang();
			}
			else
			{
				SetJiaoTong(F);
			}
			break;
		default:
			ErrorPressKey();
			break;
	}
}
void WorkStation_03_Main_Work2(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			if (Getg_bYuPeng()||1==GetYuPengState())
			{
				SetYuPengState(0);
				SendLaneInfo("������");
				UI_SetCarType(nKey);
				Set_WorkStation_04_General_Validate_Car_Type_And_First_OK();
 
			}
			else
			{
				UI_Show_Help_Info("�����ȴ�������ٽ����շѡ�");
			}
			break;
		case VK_CLOSE_YPD:
			if (Getg_bYuPeng())
			{
				UI_Show_Info("��ʾ��\n�������������\n�����°ࡿ���°࣬\n��������ơ���������ơ�");
			}
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			if (!Getg_bYuPeng())
			{
				UI_Show_Info("��ʾ��\n�������֡������복�ͣ�\n�������ӡ��������ӡ�");
			}
			SetYuPengState(1);
			SetYuPeng(T);
			break;
		case VK_URGENT:
			Set_WorkStation_09_Handl_Urgent_Car_Team();
			break;
		case VK_CLOSE:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("��ȳ���ͨ����رճ���!");
			}
			else
			{
				Set_WorkStation_06_Closed_Road();
				SendMsgGR(MSGGR_CANOPY_OFF);
				SendLaneInfo_default();
			}
			break;
		case VK_XIABAN:
			if (Getg_bLanGan())
			{
				UI_Show_Help_Info("��ȳ���ͨ�����°�!");
			}
			else if (Getg_bYuPeng())
			{
				UI_Show_Help_Info("���ȹر�������ٰ����°ࡿ����");
			}
			else
			{
				Set_WorkStation_20_EndWorkOk();
			}
			break;
		case VK_MONI:
			if (1==atoi(sys_ini.SimulateEnabledFistTuoChe) && 1==GetG_IsTuoche())
			{
				SetG_simulateWorkState(10);
				Set_WorkStation_45_SimulateOnceOk();
			}
			else
			{
				ErrorPressKey();
			}
			break;
		case VK_CHAHAO:
			Set_WorkStation_204_FreeCar();
			break;
		case S_PASSLINEUP:
			break;
		default:
			ErrorPressKey();
			break;
	}
}
/*----------------------------------------------------------------------
�������ƣ�      void WorkStation_4_General_Validate_Car_Type_And_First_OK(int nKey)
���ã�          �����շѰ������ּ�����ת�����״̬��֤���͡�
������          int nKey ���̼�ֵ
����ֵ��        ��
��̣�          WorkStation (3��7��10)
�������ڣ�      2005.10
������:         ĪԶ��
����޸�����:   2008.07
����޸���:     ����ΰ
----------------------------------------------------------------------*/
void WorkStation_04_General_Validate_Car_Type_And_First_OK(int nKey)
{
	switch (nKey)
	{
		case VK_1:
		case VK_2:
		case VK_3:
		case VK_4:
		case VK_5:
			UI_SetCarType( nKey);
			break;
		case VK_BEIYONG:
		case VK_LONGYONG:
		case VK_GONGWU:
		case VK_JUNCHE:
		case VK_LVSETONGDAO:
		case VK_RETURN:
			HandOnceOK(nKey,4);
#ifdef PCMACHINE
			CaptureImg(IMG_FIRST);
#endif
			break;
		case VK_YOUHUICARD:
			Set_WorkStation_23_Abate("�Żݿ���");
			break;
		case VK_MOUNTHCARD:
			Set_WorkStation_23_Abate("��Ʊ����");
			break;
		case VK_CANCEL:
			if (Getg_tuocheNum()!=0)
			{
				Set_WorkStation_03_Main_Work3("�����շ�","�ϳ�ģ��");
			}
			else
			{
				Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
			}
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		default:
			{
				int  carKindIndex  ;
				carKindIndex = Validate_Car_Kind(nKey);
				if (carKindIndex!=0)
				{
					HandOnceOK( nKey,4);
				}
				else
				{
					ErrorPressKey();
				}
			}

			break;
	}
}

/*----------------------------------------------------------------------
�������ƣ�      void WorkStation_6_Closed_Road(int nKey)
���ã�          ��ʱ��ճ�������������������
������          int nKey ���̼�ֵ
����ֵ��        ��
��̣�          WorkStation (2)
�������ڣ�      2005.10
������:         ĪԶ��
����޸�����:   2005.10
����޸���:     ĪԶ��
----------------------------------------------------------------------*/
void WorkStation_06_Closed_Road(int nKey)
{
	if (nKey == VK_OPEN)
	{
		Set_WorkStation_02_Handl_Input_Password();
	}
	else
	{
		ErrorPressKey();
	}

}
/*----------------------------------------------------------------------
�������ƣ�      void WorkStation_7_General_Second_OK(int nKey)
���ã�          �����շѵ�һ��ȷ�Ϻ���ת״̬�����еڶ���ȷ�ϻ�ȡ���շѡ�
������          int nKey ���̼�ֵ
����ֵ��        ��
��̣�          WorkStation (3��10)
�������ڣ�      2005.10
������:         ĪԶ��
����޸�����:   2005.10 ,2006-12-15
����޸���:     ĪԶ��
----------------------------------------------------------------------*/
int WorkStation_07_FUN_General_Second_OK_7(int Flag )
{
	int ret = 1;	
	if (1==GetG_BillPrintFlag())
	{
		if (postPrinter(T))
		{
			CaptureImg(IMG_SECOND);
			SetG_simulateEnabled(T);
			SetG_reprintbillnum(0);
			if (Flag)
			{
				Set_WorkStation_10_Up_Parapet_Pass();
			}
			else
			{
				SetPassCar();
			}
		}
		else
		{
			setLed();
			SendMsgEI(MSGEI_PRINTER_ERROR ,MSGEI_STATUS_MSGINFO,"��ӡ������");	//lzp// ��ӡ������   MSGEI �¼�����
			UI_Show_Help_Info("��ӡ�����ϣ�");
			ret = 0;
		}
	}
	else
	{
		CaptureImg(IMG_SECOND);
		SetG_simulateEnabled(T);
		SetG_reprintbillnum(0);
		if (Flag)
		{
			Set_WorkStation_10_Up_Parapet_Pass();
		}
		else
		{
			SetPassCar();
		}
	}
	return ret;
}
/**
 * �ȴ�����ȷ�ϣ�ȷ��Ϊ�ֽ�֧��
 * 
 * @param nKey
 */
void WorkStation_07_General_Second_OK(int nKey)
{
	switch (nKey)
	{
		case   CSC_CARDENTER:
			{
				int ret;
				ret=UseCardToPay();
				switch (ret )
				{
					case PAYRET_OK://  0  //��������
						//˵��һ������
						break;
					case  PAYRET_READCARDERROR://  1//����ʧ��
						UI_Show_Help_Info("��Ǹ������ʧ�ܣ�������!");
						break;
					case  PAYRET_READCARDKEYOLD://  1//����ʧ��
						UI_Show_Help_Info("��Ǹ������Կ�ѹ���!");
						break;
					case  PAYRET_READCARDKEYNOTFOND://  1//����ʧ��
						UI_Show_Help_Info("��Ǹ��δ�ҵ�����Ϣ!");
						break;
					case  PAYRET_CARDTYPEINVALID:// 2//��������Ч��
						UI_Show_Help_Info("��Ǹ���˿�������Ч�Ŀ�֧����!");
						break;
					case PAYRET_CARTYPEERROR:
						UI_Show_Help_Info("��Ǹ�����Ͳ���!");
						break;
					case PAYRET_PRINTERERROR:
						UI_Show_Help_Info("��ӡ�����ϣ����޸���ӡ������ˢ��!");
						break;
					default:
						UI_Show_Help_Info("��Ǹ����Ч��");//δ����ķ���ֵ
						break;
				}
				echoic("����ˢ��%s",       GetCardNOByString());
			}
			break;
		case  CSC_CARDEXIT:
			echoic("���Ѿ���������  ������ %s",     GetCardNOByString());
			break;
		case VK_RETURN:
			if (0==GetG_IsTuoche())
			{				
				if (0==Getg_bLanGan())
				{
					//��ʱȥ����ɲ���ȷ�ϵ��жϣ����������ƽ�����ֲ���ɣ������ǰһ�������
					WorkStation_07_FUN_General_Second_OK_7(1);
				}
				else
				{
					UI_Show_Help_Info("������Ч���밴��ʾ���в�����");
				}
			}
			else
			{
				WorkStation_07_FUN_General_Second_OK_7(1);
			}
			CaptureImg('0');
			break;
		case VK_DOWN:
			LogCAppLogDebug("ǿ�����");
			SetLanGan(F);
			break;
		case VK_QIANKUAN:
			Set_WorkStation_42_HandArrearageNumber(7);
			break;
		case VK_CANCEL:
			if (1==atoi(sys_ini.OnceOkEnabledCancel))
			{
				Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
			}
			else
			{
				ErrorPressKey();
			}
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		case VK_MONI:			
			SendLaneInfo("����ģ��");
			if (0==GetG_IsTuoche())
			{					
				Set_WorkStation_45_SimulateOnceOk();
			}
			else
			{					
				Set_WorkStation_53_SimulateOnceOkTuoche();
			}			
			break;

		default:
			ErrorPressKey();
			break;
	}
}

/*----------------------------------------------------------------------
�������ƣ�      void WorkStation_10_Up_Parapet_Pass(int nKey)
���ã�          �����շѶ���ȷ��̧�˷���ʱ����״̬��
������          int nKey ���̼�ֵ
����ֵ��        ��
��̣�          WorkStation (3��21)
�������ڣ�      2005.10
������:         ĪԶ��
����޸�����:   2005.10
����޸���:     ĪԶ��
----------------------------------------------------------------------*/
void WorkStation_10_Up_Parapet_Pass(int nKey)
{
	switch (nKey)
	{
		case S_PASSLINEUP:
			if (0!=GetG_IsTuoche())
			{
				AddYCQK("���ϳ�");
				SetJiaoTong(F);
				SetG_IsTuoche(0);//Ӳ��             SetG_IsTuoche(GetG_IsTuoche()-1)//����
			}
			AfterOfTransDo(1,F);
			SetJiaoTong(F);
			SendMsgInfo("������Ϣ","","��ͨ����");	   //qq
			InitCarTypeKindCharge();
			SendLaneInfo_default();
			SendLaneInfo("�ȴ�����");
			LedClare(T);
			Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		case VK_MONI:			
			SetG_simulateWorkState(10);
			SendLaneInfo("����ģ��");
			Set_WorkStation_46_SimulateTwoOk();			
			break;
		default:
			ErrorPressKey();
			break;
	}
}







void WorkStation_28_CarNumber_Second_OK(int nKey)
{

	switch (nKey)
	{
		
		case VK_RETURN:
			SetG_simulateEnabled( T);
			SetG_reprintbillnum(0);
			Set_WorkStation_10_Up_Parapet_Pass();
			break;
		case VK_CANCEL:
			Set_WorkStation_03_Main_Work("�����շ�","�ȴ�����");
			break;
		case VK_CLOSE_YPD:
			SetYuPeng(F);
			break;
		case VK_OPEN_YPD:
			SetYuPeng(T);
			break;
		default:
			ErrorPressKey();
			break;
	}
}


/*-------------------------------------------------------------------------------------------------------------------
�������ƣ�     WorkStation_50_DataExporter(int nKey)
���ã�           ��usb�豸������������
������          int nKey ���̼�ֵ
����ֵ��        ��
��̣�          WorkStation (20)
�������ڣ�      2008.6
����޸�����:   2008.6
--------------------------------------------------------------------------------------------------------------------*/
int  itWorking=0;
void WorkStation_50_DataExporter(int nKey)
{
	switch (nKey)
	{
		case VK_CANCEL:
			if (0==itWorking)
			{
				Set_WorkStation_30_SelectWorkMod();
			}
			else
			{
				UI_Show_Help_Info("���ڵ������ݣ����Ժ�....");
			}
			break;
		case VK_RETURN:
			itWorking=1;
			DataExporter();
			itWorking=0;
			break;
		default:
			ErrorPressKey();
			break;
	}
}


