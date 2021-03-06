//定义收费键盘键值
#define S303KEYBORD

#ifdef S303KEYBORD
/*定义线圈消息*/
	#define MSG_BAR_DOWN		5004
	#define MSG_BAR_UP			5003
	#define MSG_PIC_DOWN		5002
	#define MSG_PIC_UP			5001
	#define MSG_TCORET			(MSG_USER+14)
	#define MSG_REMOTECONTROL	(MSG_USER+15)
	#define S_PASSLINEUP    1000 //通过线圈上升沿 用于代码内部使用，一般不用于事件发送
	#define VK_0				11	//'0'
	#define VK_1				2	//'1'
	#define VK_2				3	//'2'
	#define VK_3				4	//'3'
	#define VK_4				5	//'4'
	#define VK_5				6	//'5'
	#define VK_6				7	//'6'
	#define VK_7				8	//'7'
	#define VK_8				9	//'8'
	#define VK_9				10	//'9'

	#define VK_CANCEL			1	//19	//取消		'r'
	#define VK_YOUHUICARD		24	//'o'	优惠卡车
	#define VK_MOUNTHCARD		25	//	 月票卡

	#define VK_QIANKUAN		34  //25	//'p'	//48	//车型1		'b'
	#define VK_LVSETONGDAO		47	//'v'	//48	//车型1		'b'
	#define VK_RETURN			28	//确认
	#define VK_WEIZHANG			360	//'j'	//违章		'n'
	#define VK_JUNCHE			37	//'k'	//16	//军车		'q'
	#define VK_GONGWU			38	//'l'	//25	//公务		'p'

	#define VK_BEIYONG			19	//'R'	//48	//备用
	#define VK_LONGYONG			52	//'T'	//48	//备用
	#define VK_SHANGBAN			48	//'b'	//上班		'y'
	#define VK_XIABAN			46	//'c'    //下班		'z'
	#define VK_CLOSE_YPD		    45	//'x'	//暂停收费	'i'
	#define VK_OPEN_YPD			44	//'z'	//继续收费	'v'

	#define VK_OPEN				1600	//'q'    //开启		'u'
	#define VK_CLOSE			1800	//'e'    //封闭		'x'
	#define VK_MONI				35	//'h'	//模拟		'o'

	#define VK_CHEDUI_G			33	//'f'	//车队-紧急 'k'

	#define VK_CHEDUI_R			90	//车队-普通 'l'
	#define VK_URGENT			23	//'i' 紧急

	#define VK_LEFT				330	//'a'    //左光标	qQ
	#define VK_RIGHT			32	//'d'   //右光标	rR
	#define VK_UP				17	//'w'	//上光标	sS
	#define VK_DOWN				31	//'s'	//下光标	tT
	#define VK_LANGAN			-2	//30 是栏杆
	#define VK_BREAKAUTOMAN			36	//'j'	//违章		'n'
	#define VK_CHAHAO			21

int GetKeyMapValue(char *ItemName);
int LoadKeyBoardFile(void);
int  KeyTran(int keyvalue);
int  KeyNameTran(char *KeyName);
void InitKeyBoard_KeyMap(void);
#endif
 
