#include "LocalIncludeFile.h"
int g_hCOM[5];


int set_Parity(int fd,int databits,int stopbits,int parity)
{ 
	struct termios options; 
	if  ( tcgetattr( fd,&options)  !=  0) { 
		perror("SetupSerial 1");     
		return(FALSE);  
	}
	options.c_cflag &= ~CSIZE; 
	switch (databits) /*��������λ��*/
	{   
	case 7:		
		options.c_cflag |= CS7; 
		break;
	case 8:     
		options.c_cflag |= CS8;
		break;   
	default:    
		fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
	}
	switch (parity) 
	{   
	case 'n':
	case 'N':    
		options.c_cflag &= ~PARENB;   /* Clear parity enable */
		options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
		break;  
	case 'o':   
	case 'O':     
		options.c_cflag |= (PARODD | PARENB); /* ����Ϊ��Ч��*/  
		options.c_iflag |= INPCK;             /* Disnable parity checking */ 
		break;  
	case 'e':  
	case 'E':   
		options.c_cflag |= PARENB;     /* Enable parity */    
		options.c_cflag &= ~PARODD;   /* ת��ΪżЧ��*/     
		options.c_iflag |= INPCK;       /* Disnable parity checking */
		break;
	case 'S': 
	case 's':  /*as no parity*/   
		options.c_cflag &= ~PARENB;
		options.c_cflag &= ~CSTOPB;break;  
	default:   
		fprintf(stderr,"Unsupported parity\n");    
		return (FALSE);  
	}  
	/* ����ֹͣλ*/  
	switch (stopbits)
	{   
	case 1:    
		options.c_cflag &= ~CSTOPB;  
		break;  
	case 2:    
		options.c_cflag |= CSTOPB;  
		break;
	default:    
		fprintf(stderr,"Unsupported stop bits\n");  
		return (FALSE); 
	} 
	/* Set input parity option */ 
	if (parity != 'n')   
		options.c_iflag |= INPCK; 
	tcflush(fd,TCIFLUSH);
	options.c_cc[VTIME] = 150; /* ���ó�ʱ15 seconds*/   
	options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
	if (tcsetattr(fd,TCSANOW,&options) != 0)   
	{ 
		perror("SetupSerial 3");   
		return (FALSE);  
	} 
	return (TRUE);  
}

void I_DEV_LED_Init(void)
{
    //˫�԰ӵ��Ϸ���Ϊ 9600 ���ڵķ���Ϊ 1200 
	int BTLV = B9600;
	if(0==strcmp("TWD",GetTFIDLL()))
	{
		BTLV=B1200;
	}
    if(serial_init(LED_COM,BTLV)<0)
    {	
        echo("���Դ��ڳ�ʼ��ʧ��12��");	
    }
	else
	{
		echo("���Դ��ڳ�ʼ���ɹ���");
	}
}
void setLed(void)
{
    int kbd_fd;
     unsigned char led;     
     kbd_fd = open("/dev/tty0",O_RDWR);	
     if(kbd_fd < 0)
     {   
         perror("/dev/tty0");	
         exit(errno);	
     }
     else
     {   
         ioctl(kbd_fd, KDGKBLED,&led);	
         led &= ~LED_NUM;
         ioctl (kbd_fd, KDSKBLED,led);	
         usleep(100);	
         led |= LED_NUM;
         ioctl (kbd_fd, KDSKBLED,led);	
     }
     close(kbd_fd);	
 
}

int serial_init(int nCOM, int nBaud)
{	
    struct termios newtio;
    char szCOM[20];
    sprintf(szCOM,"/dev/COM%d",nCOM);	
    g_hCOM[nCOM-1] = open(szCOM,O_RDWR | O_NOCTTY | O_NONBLOCK);
    if(g_hCOM[nCOM-1] < 0)
    {	
        return -1;
    }
	//return set_Parity(g_hCOM[nCOM-1],8,1,'N');

    bzero(&newtio, sizeof(newtio));/* ����ṹ���Է����µ����в��趨ֵ */
/*
BAUDRATE: �趨 bps ���ٶ�. ��Ҳ������ cfsetispeed �� cfsetospeed ���趨.
CRTSCTS : ������ϵ�Ӳ���������� (ֻ���ھ�������·�������¹���  �ο� Serial-HOWTO ���߽�)
CS8     : 8n1 (8 λԪ, ����ͬλԪ���,1 ����ֹλԪ)
CLOCAL  : ��������, �������ݻ����ƹ���
CREAD   : ���ܽ�����Ԫ
*/
    newtio.c_cflag = nBaud |  CS8 | CLOCAL | CREAD ;
/*
IGNPAR  : ���Ծ�ͬλԪ�����, �����λԪ��
ICRNL   : �� CR ��Ӧ�� NL (��������Ѷ���� CR ʱ������ֹ����)
            �ڲ�Ȼ��װ���趨�� raw ģʽ(û�����������봦��)
 */

    newtio.c_iflag = IGNPAR ;//| ICRNL;/*HH IGNPAR*/
/*
 Raw ģʽ���.
*/
    newtio.c_oflag = 0;

/*
 ICANON  : ���ܱ�׼����, ʹ���л�Ӧ����ͣ��, �����ͳ��ź��Խ��ó�ʽ
*/
    newtio.c_lflag = 0;//ICANON; /*HH 0*/




/*
 ��ʼ�����еĿ�������
 Ԥ��ֵ������ /usr/include/termios.h �ҵ�, ��ע����Ҳ��,
 ���������ⲻ��Ҫ������
*/
    newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
    newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
    newtio.c_cc[VERASE]   = 0;     /* del */
    newtio.c_cc[VKILL]    = 0;     /* @ */
    newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */
    newtio.c_cc[VTIME]    = 0;     /* ��ʹ�÷ָ���Ԫ��ļ�ʱ�� */
    newtio.c_cc[VMIN]     = 1;     /* �ڶ�ȡ�� 1 ����Ԫǰ��ֹͣ */
    newtio.c_cc[VSWTC]    = 0;     /* '\0' */
    newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
    newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
    newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
    newtio.c_cc[VEOL]     = 0;     /* '\0' */
    newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
    newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
    newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
    newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
    newtio.c_cc[VEOL2]    = 0;     /* '\0' */


/*
  ����������ݻ��߲��������в����趨
*/
    tcflush(g_hCOM[nCOM-1], TCIFLUSH);	
    tcsetattr(g_hCOM[nCOM-1],TCSANOW,&newtio);	

    return 0;
}

int serial_close(int nCOM)
{	
    close(g_hCOM[nCOM-1]);	
    return 0;
}

int serial_read(int nCOM,unsigned char *byReadBuf,int nReadLen)
{	
    int nLen;
    nLen = read(g_hCOM[nCOM-1], (void *)byReadBuf, nReadLen);	
    return nLen;
}
//AA 0D 84 00 00 00 20 20 20 20 20 31 BB 00 
//AA 0D 84 03 00 00 20 20 20 35 30 30 BB 00
int serial_write(int nCOM,unsigned char *byWriteBuf,int nWriteLen)
{	
    int nLen;//,i;
    nLen = write(g_hCOM[nCOM-1], (void *)byWriteBuf, nWriteLen);	
	//echoic("write Len = <%d>",nLen);
    return nLen;
}
void LedSound(int Index)
{	
    
}
void LedClare(BOOL IsSound)
{	
    
	if(0==strcmp("TWD",GetTFIDLL()))
	{
		if(IsSound && 1==atoi(sys_ini.LedSoundEnabled))
		{	
			serial_write(LED_COM,"<Y>",3);
		}
		else
		{	

			serial_write(LED_COM,"<D>",3);
		}	
	}
	else if(0==strcmp("KK",GetTFIDLL()))
	{
		TFI_KK_clean();
	}
	else if(0==strcmp("303",GetTFIDLL()))
	{
		TFI_303_clean(IsSound);
	}
	else if(0==strcmp("HN",GetTFIDLL()))
	{
		TFI_HN_clean();
	}
	else if(0==strcmp("SG",GetTFIDLL()))
	{
		TFI_SG_clean();
	}
	else if(0==strcmp("CJ",GetTFIDLL()))
	{
		TFI_CJ_clean();
	}
	else if(0==strcmp("MNS",GetTFIDLL()))
	{
		TFI_MNS_clean();
	}
}
void LedVolume(int VolumeValue)
{	
    unsigned char Command[4];
    Command[0] = 0x0A;
    Command[1] = 0x46;
    switch(VolumeValue)
    {	
    case 0:
        Command[2]=0x22;
        break;
    case 1:
        Command[2]=0x21;
        break;
    case 2:
        Command[2]=0x20;
        break;
    case 3:
        Command[2]=0x19;
        break;
    case 4:
        Command[2]=0x18;
        break;
    case 5:
        Command[2]=0x17;
        break;
    case 6:
        Command[2]=0x16;
        break;
    }

    Command[3] = 0x00;
    //serial_write(LED_COM,Command,4);	
    //sprintf(help,"��������Ϊ %d ",Currentvolume);	
}
void LedShowCharge(char CarType,int charge)
{   
	echo("%s",GetTFIDLL());
	if(0==strcmp("TWD",GetTFIDLL()))
	{
		echo("TWD %c  %d  %d",CarType,CarType,charge);
		if (' '!=CarType && '0'!=CarType)
		{
			ShowCarType(CarType);
		}
		usleep(10);
		if (0!=charge)
		{
			Showcharge(charge);
		}
	}
	else if(0==strcmp("KK",GetTFIDLL()))
	{
		TFI_KK_LedShow ( (int)CarType -0x30 ,  charge );
	}
	else if(0==strcmp("303",GetTFIDLL()))
	{
		echo("303 %c  %d  %d",CarType,CarType,charge);
		TFI_303_LedShow(CarType,charge);
	}
	else if(0==strcmp("HN",GetTFIDLL()))
	{
		echo("HN %c  %d  %d",CarType,CarType,charge);
		TFI_HN_LedShow ( (int)CarType -0x30 ,  charge );
	}
	else if(0==strcmp("SG",GetTFIDLL()))
	{
		echo("SG %c  %d  %d",CarType,CarType,charge);
		TFI_SG_LedShow ( (int)CarType -0x30 ,  charge );
	}
	else if(0==strcmp("CJ",GetTFIDLL()))
	{
		echo("CJ %c  %d  %d",CarType,CarType,charge);
		TFI_CJ_LedShow ( (int)CarType -0x30 ,  charge );
	}
	else if(0==strcmp("MNS",GetTFIDLL()))
	{
		echo("MNS %c  %d  %d",CarType,CarType,charge);
		TFI_MNS_LedShow ( CarType,charge);
	}
}
#define echo1(fmt, args...)	  //printf("ECHO:::: [%s:%d]: " fmt "\n", __FILE__, __LINE__ , ## args)

void ShowCarType(char ct)
{
	unsigned char strCMD[9];
	memset(strCMD,0x00,9);
	sprintf(strCMD,"<V****%c>",ct);
	echo1("ָ��:%s  ����:%c  �˿�COM%d",strCMD,ct,LED_COM);
	serial_write(LED_COM,strCMD ,sizeof(strCMD));
}
void Showcharge(int ct)
{
	unsigned char strCMD[9];
	char  tmpx1[10];
	char  tmpx2[10];
	memset(tmpx2,0x00,10);
	memset(tmpx1,0x00,10);
	memset(strCMD,0x00,9);
	sprintf(tmpx1,"%d",ct);
	strncpy(tmpx2,"*****",5-strlen(tmpx1));
	sprintf(strCMD,"<M%s%s>",tmpx2,tmpx1);
	//echoic("ָ��:%s  �Ѷ�:%d",strCMD,ct);
	serial_write(LED_COM,strCMD ,sizeof(strCMD));
}
 

void  LedClear()
{	
	if(0==strcmp("TWD",GetTFIDLL()))
	{
		serial_write(LED_COM,"<Y>",3);	
	}
	else if(0==strcmp("KK",GetTFIDLL()))
	{
		TFI_KK_clean();
	}
	else if(0==strcmp("303",GetTFIDLL()))
	{
		TFI_303_clean(F);
	}
	else if(0==strcmp("HN",GetTFIDLL()))
	{
		TFI_HN_clean();
	}
	else if(0==strcmp("CJ",GetTFIDLL()))
	{
		TFI_CJ_clean();
	}
    return;
}

