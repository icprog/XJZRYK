#include "LocalIncludeFile.h"
//	E δ����(Υ��ʱ)
//	DǷ��
//	1
//	2 SVC
//	3����
//	4��Ʊ
//	5���ÿ�
//	6����
//	7��ɫͨ��
//	8��׼��װ��
//	9��׼�޳�
//	T ����
char * GetMethodPayText(char Index)
{
	char *ret = "";
	switch (Index)
	{
	case  MP_NotPay		:
		ret = "δ����";
		break;
	case  MP_QIAN_KUAN	:
		ret = "Ƿ��";
		break;
	case  MP_XIAN_JIN	:
		ret = "�ֽ�";
		break;
	case  MP_SVC		:
		ret = "SVC";
		break;
	case  MP_OFFICE		:
		ret = "����";
		break;
	case  MP_MONTH		:
		ret = "��Ʊ";
		break;
	case  MP_CREDIT		:
		ret = "���ÿ�";
		break;
	case  MP_POLICE		:
		ret = "����";
		break;
	case  MP_LVSETD		:
		ret = "��ɫͨ��";
		break;
	case  MP_JI_ZHUANG_XIANG :
		ret = "��װ��";
		break;
	case  MP_GUAN_CHE		:
		ret = "�޳�";
		break;
	case  MP_TEAM			:
		ret = "����";
		break; 
	}
	return ret;

}

