#include "LocalIncludeFile.h"


#define _DEBUG_PRINTRT_

#define echoprint(fmt, args...)	  // printf("ECHO:::: [%s:%d]: " fmt "\n", __FILE__, __LINE__ , ## args)

/******************************************************************************************************
*打印机通讯状态
******************************************************************************************************/
int DevCStatePrinterState = BPLA_OK;
int DevCStatePrinterSendFlag = 1;
int GetDevCStatePrinterState()
{	
	return DevCStatePrinterState;
}
	char DevCStatePrinterState_char[4];
char *GetDevCStatePrinterState_Str()
{	
	memset(DevCStatePrinterState_char,'\0',4);	
	sprintf(DevCStatePrinterState_char,"%4d",GetDevCStatePrinterState());	
	return  DevCStatePrinterState_char;
}

void  SetDevCStatePrinterState (int InputDevCStatePrinterState)
{	
	if(BPLA_NOCHECK != InputDevCStatePrinterState)
	{	
		if( DevCStatePrinterState!=InputDevCStatePrinterState)
		{	
			DevCStatePrinterSendFlag=1;
			DevCStatePrinterState= InputDevCStatePrinterState;
			ShowDevCStatePrinterState();	

		}
	}
}

void ShowDevCStatePrinterState()
{	

	switch(DevCStatePrinterState)
	{	
		case BPLA_OK:
			//SendMsgEI( 票据打印机通信恢复");	
			UI_Show_Help_Info("票据打印机通信恢复");	
			break;
		case BPLA_COMERROR:
			SendMsgEI(MSGEI_PRINTER_ERROR,MSGEI_STATUS_ERROR_OCCURRED, "票据打印机通信故障");	
			UI_Show_Help_Info("票据打印机通信故障");	
			break;
		case BPLA_NOPAPER:

			//SendMsgEvent(EVENT_TYPE_ALARM,ID_DEV_DCP,ID_STATUS_DCP_BLANK,"票据打印机缺纸、通信正常");	
			UI_Show_Help_Info("票据打印机缺纸");	
			break;
	}
}
 
void RePrintBill(void)
{
	SendMsgEI(MSGEI_REPRINTBILL,MSGEI_STATUS_MSGINFO,"重打票据");////lzp  重打票据 MSGEI 事件处理
	if (!postPrinter(F))
	{
		SendMsgEI(MSGEI_PRINTER_ERROR ,MSGEI_STATUS_MSGINFO,"打印机故障");	//lzp// 打印机故障   MSGEI 事件处理
		UI_Show_Help_Info("打印机故障！");
	}
	
}
void createBillNumber()
{
    struct tm *rtc_time;
    time_t t = time(NULL);	
    rtc_time = localtime(&t);	
    SetbillCount(GetbillCount()+1);	
    SetbillCount( GetbillCount()%10000);	
    writeBillNumber();	
}
void writeBillNumber()
{
    char BillNumber[10];
    FILE *fp;
    memset(BillNumber,0x00,10);	
    sprintf(BillNumber,"%04d",GetbillCount());	
    if((fp=fopen(FILENAME_SAVE_BILLNUMBER,"wt+"))==NULL)
    {
        printf("Cannot open file strike any key exit!");	
    }
    fputs(BillNumber,fp);	
    fclose(fp);	
	echoprint("%s",BillNumber);
    SendTCOMsg(MSGTCO_CMD_BILLNUMBER,BillNumber);	//给服务器发送票据号码
}
void ReadBillNumber()
{
    char BillNumber[10];
    int fbillNumber;
    fbillNumber=open(FILENAME_SAVE_BILLNUMBER,O_RDONLY);	
    if(fbillNumber<0)
    {
    #ifdef SYS_LOG
        writelog(logfd,"system config file not find!\n");	
    #endif
      //createBillNumber();	
    }
	memset(BillNumber,0x00,10);
    lseek(fbillNumber,SEEK_SET,0);	
    if(read(fbillNumber,BillNumber,10)<0)
    {
        #ifdef SYS_LOG
        writelog(logfd,"system config file is emp!\n");	
        #endif
        close(fbillNumber);	
    }
  
    close(fbillNumber);	
	echoprint("%s",BillNumber);
    SetbillCount(atoi(BillNumber));	
}

BOOL _CanTestPrinter=TRUE;
BOOL GetCanTestPrinter(void )
{
	return _CanTestPrinter ;
}

BOOL postPrinter(BOOL newNillNumber)
{
	BOOL ret = T;
	testprinter();
	if (Getg_bPrint())
	{
		if (0!=strncmp("  0",g_currentPrint.Charge,3))
		{
			if (newNillNumber)
			{
				createBillNumber();
				strcpy(g_currentPrint.billNumber,GetbillNumber_str());
			}
			if (EnabledPrinter())// && (int)CSRI.charge >0)
			{
				//LogCAppLogDebug("打票据");
				_CanTestPrinter=FALSE;
				
				printBill(&g_currentPrint);//temp
				_CanTestPrinter=TRUE;
			}
		}
	}
	else
	{
		ret = F;
	}
	return ret;
}


void printBill(struct BILLPARAM *var_billparam)
{
    I_Dev_Printer_PrintBill(var_billparam);
}
void TestprintBill()
{
    I_DEV_Printer_PrintTestBill();
}
void   testprinter(void)
{   
	BOOL printState ;

	printState=Getg_bPrint();
	if (EnabledPrinter())
	{
		printState=I_Dev_Printer_TestStatus();
	}
	else
	{
		printState = T;
	}
	if (1==1 || printState!=Getg_bPrint())
	{
		Setg_bPrint(printState);
		
		if (Getg_bPrint())
		{
			G_CurrentSystemDevStatus.PrintStatus = 1;
		}
		else
		{
			G_CurrentSystemDevStatus.PrintStatus = 0;
		}
		SendLaneInfo_default();
	}
}

