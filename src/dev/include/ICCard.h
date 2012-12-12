

#ifndef __ICCard_H__
#define __ICCard_H__

typedef struct __GWCARDDATA
{
	unsigned char Version;    //�汾��(0X10)
	unsigned char CityNo;	 //�б��
	unsigned char Plaza; 	 //�շ�վ��(���ķ��Ŀ��˴�Ϊ0)
	unsigned char Usage; 	 //��;���
	// 	0X10ʡ���ķ��Ĺ���
	// 	0X11�����ķ��Ĺ���
	// 	0X12վ���Ĺ���
	// 	0X20ʡ���ķ�����Ʊ��
	// 	0X21�����ķ�����Ʊ��
	// 	0X22վ������Ʊ��
	// 	0X50ʡ���ķ����Żݿ�
	// 	0X51�����ķ����Żݿ�
	// 	0X52վ�����Żݿ�
	unsigned char CardSN[4];  //�����к�(����ʵ�����к�)
	unsigned char CardNo[4];	//����(8λBCD���ʾ)
	//���񿨺�
	//��Ʊ����
	unsigned char BTime[7];   //����ʱ��(14λBCD���ʾ)YYYYMMDDHHMMSS
	unsigned char ETime[7];	//����ʱ��(14λBCD���ʾ)
	unsigned char Valid; 	 //IC��״̬(ASCII��1-ʹ����/0-��Ч)
	unsigned char PlateLen;   //���ƺų���
	unsigned char Plate[10];	//���ƺ�
	unsigned char CType; 	 //����
	unsigned char Power; 	 //Ȩ��
	//0 ʡ��
	//1 ָ����
	//2 ָ���շ�վ
	unsigned char Area[10];	//�������
	unsigned char Percent;    //�Ż���(2λBCD���ʾ)
	//01Ϊ��ʾΪԭ�۵�1%��90Ϊԭ�۵�99%
	unsigned char FeeMode[2];	//�Ѷ����ģʽ(2λBCD���ʾ)
	//��С��λΪ�ǣ������й��ŻݵķѶ�ô������󣬶��������е���
	unsigned char Carry; 	 //��λ������ASCII���ʾ
	//1�������� 2ֱ���� 3ֱ����
	unsigned char Character[20]; //��������(2005-12-21�޸�)
	unsigned char Reserve[20];	//����(����������) (2005-12-21�޸�)
	unsigned char CRC[2];		//CRC(���ʽΪ0X1021)
}Card;
Card * ICCard_GetCard(void);
int ICCard_UnLoad(void);
int ICCard_Load(void);
int ICCard_init(int pcom,long pspeed,long pe,char * pn);
int ICCard_getCard(void);
int ICCard_GetIsInit(void);
void ICCard_GetBCD(char * bcd,unsigned char * s,int len);
char * ICCard_GetBDate(void);
char * ICCard_GetEDate(void);
int ICCard_ValidateCardEndDate(time_t Currenttime);
int ICCard_ValidateCardStartDate(time_t Currenttime);
int ICCard_ValidateArea(void);
#endif
