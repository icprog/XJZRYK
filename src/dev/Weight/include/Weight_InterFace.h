#ifndef		_Weight_InterFace_H_
#define		_Weight_InterFace_H_


#define MAX_CAR_AXLE 11
typedef struct 
{
	int	AxleWeight ;//��λ 10KG
	int	AxleType ;
	int TiresType;
}Wds_AxleInfo;
typedef struct 
{
	int TotalWeight; //��λ 10KG
	int AxleNumber; 
	int Speed ;	
	int WeihtInfoType; //���� �Ƿ�������������Ϣ Ĭ�� 0 û���޸�
	Wds_AxleInfo AxleArry[MAX_CAR_AXLE]; //���һ����10���ĺϼ�
}Wds_CarWeightInfo;
Wds_CarWeightInfo * GetFirstCarWeightInfo(Wds_CarWeightInfo * cwi);
void RemoveFirstCarWeightInfo(void);
void ModifyAxlesNo(int inputAxesNo);
void ModfiyAxlesByWeight(int  InputWeight);
void AddAxleByIndex(int index,Wds_AxleInfo *Axle);
void RemoveAxleByIndex(int index);
void AddCarWeightInfo(Wds_CarWeightInfo *CarWeightInfo);

#endif

