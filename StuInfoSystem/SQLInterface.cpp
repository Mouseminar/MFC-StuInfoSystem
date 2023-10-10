#include "pch.h"
#include "SQLInterface.h"

bool SQLInterface::Connect_MySQL()
{
	mysql_init(&mysqlCon);
	//mysqlCon ���ݿ�ṹ localhost ������ root �û��� "" ����Ϊ�� mytest ���ݿ� 3306 �˿�
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "1234", "stuinfo", 3306, NULL, 0))
	{
		AfxMessageBox(_T("�������ݿ�ʧ��!"));
		return false;
	}
	else
	{
		AfxMessageBox(_T("�ɹ��������ݿ�!"));
		// �����ַ����� ʹ����֧�����ġ�
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'");//��������ݿ��ж�ȡ���ݺ���������ʾ������ 
	}
	return true;
}

vector<StuInfo> SQLInterface::Get_All_Info()
{
	vector<StuInfo> Info;
	
	// C��������ַ���
	snprintf(sql, SQL_MAX, "SELECT * FROM info1");
	// ��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// �жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("��ѯʧ��!"));
		return Info;
	}
	// ��ȡ�����
	res = mysql_store_result(&mysqlCon);
	// ��ȡ��ѯ����һ������
	// ��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res)) {
		StuInfo stuinfo = StuInfo(row[0], row[1], atoi(row[2]), stod(row[3]), stod(row[4]), stod(row[5]));
		Info.push_back(stuinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return Info;
}

bool SQLInterface::Add_Info(StuInfo Info)
{
	// C�����ַ������
	snprintf(sql, SQL_MAX, "INSERT INTO info1 VALUES('%s', '%s', %d, %lf, %lf, %lf);"
		, Info.m_name.c_str(), Info.m_sex.c_str(), Info.m_class_, Info.m_score1, Info.m_score2, Info.m_score3);
	// ��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// �жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("���ʧ��!"));
		return false;
	}
	return true;
}

bool SQLInterface::Del_Info(StuInfo Info)
{
	// C�����ַ������
	snprintf(sql, SQL_MAX, "DELETE FROM info1 WHERE name = '%s';", Info.m_name.c_str());
	// ��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// �жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("ɾ��ʧ��!"));
		return false;
	}
	return true;
}

bool SQLInterface::Update_info(StuInfo old_Info, StuInfo new_Info)
{
	// C�����ַ������
	snprintf(sql, SQL_MAX, "UPDATE info1 SET name = '%s', sex = '%s', class_ = %d, score1 = %lf, score2 = %lf, score3 = %lf WHERE name = '%s'"
		, new_Info.m_name.c_str(), new_Info.m_sex.c_str(), new_Info.m_class_, new_Info.m_score1, new_Info.m_score2, new_Info.m_score3, old_Info.m_name.c_str());
	// ��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// �жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("�޸�ʧ��!"));
		return false;
	}
	return true;
}

vector<StuInfo> SQLInterface::Seek_info(CString name)
{
	vector<StuInfo> result;

	// C�����ַ������
	snprintf(sql, SQL_MAX, "SELECT * FROM info1 where name = '%s';", name);
	// ��ѯ����
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// �жϲ�ѯ���
	if (ret) {
		AfxMessageBox(_T("��ѯʧ��!"));
		return result;
	}
	// ��ȡ�����
	res = mysql_store_result(&mysqlCon);
	// ��ȡ��ѯ����һ������
	// ��row��ֵ���ж�row�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res)) {
		StuInfo stuinfo = StuInfo(row[0], row[1], atoi(row[2]), stod(row[3]), stod(row[4]), stod(row[5]));
		result.push_back(stuinfo);
	}
	// �ͷŽ����
	mysql_free_result(res);
	return result;
}

void SQLInterface::Close_MySQL()
{
	// �ر����ݿ�
	mysql_close(&mysqlCon);
}
