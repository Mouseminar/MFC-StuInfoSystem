#pragma once

#include "StuInfo.h"

#define SQL_MAX 256		// sql����ַ��������ֵ

class SQLInterface
{
public:
	MYSQL_RES* res;	//result
	MYSQL_ROW row;
	MYSQL mysqlCon;	//Connect
	char sql[SQL_MAX];	// SQL���

	bool Connect_MySQL();	//�������ݿ�
	vector<StuInfo> Get_All_Info();	//��ȡȫ����Ϣ
	bool Add_Info(StuInfo Info);	//���ѧ����Ϣ
	bool Del_Info(StuInfo Info);	//ɾ��ѧ����Ϣ
	bool Update_info(StuInfo old_Info, StuInfo new_Info);	//�޸�ѧ����Ϣ
	vector<StuInfo> Seek_info(CString name);	//����ѧ����Ϣ
	void Close_MySQL();	//�ر����ݿ�
};

