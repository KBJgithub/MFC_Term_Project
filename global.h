#pragma once
//*************************************************************************
#include <vector>
//*************************************************************************

//*************************************************************************
typedef unsigned int u_int;
typedef unsigned char u_char;
typedef unsigned long u_long;
typedef unsigned short u_short;

typedef unsigned int u_32;
typedef unsigned char u_8;
typedef unsigned short u_16;

typedef int s_32;
typedef char s_8;
typedef short s_16;
//*************************************************************************

//*************************************************************************

typedef struct Temp_TimeSlot
{
	float tmp; //temp[x]�� �� ,����ð� + 3*x �ð��� �µ�. 
			   //ex) temp[0] = ����ð��� ���Ե� 3�ð�, temp[1] = ��ü 48�ð� �� 2��° �ð�.
	float tmx; //�ְ�µ�,  999.0 = data missing
	float tmn; //�����µ�,  999.0 = data missing
}temp_ts;

typedef struct Coordinates
{
	u_int gridx, gridy;
}coordinates;

typedef struct Town_Cord
{
	u_int do_, si, dong;
}town_cord;

typedef struct Weather_Info
{
	town_cord cord;  // �ּҿ��� ��, ��, �� �ڵ�(�츮�� ���ϴ� ��) 
						//ex) ��û���� = 1, õ�Ƚ� = 1, ��õ�� = 1
						//do_ = 1,     si = 1,    dong = 1
	coordinates grid;   //����,�浵 -> ���û ��ǥ x, y�� ��ȯ�� ���û x,y��.
	u_int day; //Date : 1 = ����, 2 = ����, 3 = ��	
	std::vector<temp_ts> temp;
	u_int sky;   //�ϴû����ڵ�, 1 = ����, 2 = ��������, 3 = ��������, 4 = �帲
	u_int pty;   //���������ڵ�, 0 = ����, 1 = ��, 2 = ��/��, 3 = ��/��, 4 = ��
	u_int pop;   //����Ȯ�� [%]
	float r6;    //6�ð� ���� ������
	float s6;    //6�ð� ���� ������
	float ws;   //wind speed [m/s], �ݿø��ؼ� ����.
	u_int wd;   //wind dir, �� {0~7} = {��,�ϵ�,��,����,��,����,��,�ϼ�}
	u_int reh;  //����[%]
}weather_info;

//*************************************************************************



//********************�������� ���� �κ�***********************************
//u_int fix; // ȭ�鿡 ������ �������� ���� flag ����.
//u_int user_do;
//u_int user_si;
//u_int user_dong; //����ڰ� �ָ��ϰ��ִ� �ϳ��� Ư�� �����ڵ�( �ð��뺰�� ��Ÿ�� ���� �ڵ�)
//u_int mode; // 1 = ������, 2 = Ư�� ������ �ð��뺰 ������, 3 = �Ѵ�  ps. �Ŀ� �߰��� ��ġ ��ġ�� ���� mode�� �߰��� �� ����.
//u_int update; //������Ʈ �ֱ�.
//u_int map;// mode 1, 3���� ���� ������Ȳ(ex. �ѹݵ� or ��Ư�� or �泲 or õ�Ƚ� )
//*************************************************************************
