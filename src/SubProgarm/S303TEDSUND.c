#include "LocalIncludeFile.h"
BOOL U_SBtn_Flag=0;
int main(int args, const char* arg[])
{
	
	if(args == 3)
	{
		int ComNo = atoi(arg[1]);
		int Sund = atoi(arg[2]);
		unsigned char SoundNUMBER[4] = {0x0A,0x46,0x15,0x00};
		unsigned char Hello[4] = {0x0A, 0x46, 0x0E,0x00};
		SoundNUMBER[2] +=Sund;
		if(serial_init(ComNo,B9600)<0)
		{	
			echo("���Դ��ڳ�ʼ��ʧ��,����շѳ����Ƿ�رգ�");	
			return;
		}
		serial_write(ComNo,SoundNUMBER,4);
		printf("�ɹ����á�%d���˿ڷ�����ʾ����Ϊ��%d��\n����3���Ӻ��������\n",ComNo,Sund);
		sleep(3);
		serial_write(ComNo,Hello,4);
		

	}
	else
	{
		printf(	"�������ݲ���ȷ,��һ������Ϊ���ںŵڶ�����Ϊ����������1��7 1��ʾ�������!\n",args);
	}
}