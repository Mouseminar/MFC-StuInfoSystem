#include "pch.h"
#include "SQLInterface.h"

bool SQLInterface::Connect_MySQL()
{
	mysql_init(&mysqlCon);
	//mysqlCon 数据库结构 localhost 主机名 root 用户名 "" 密码为空 mytest 数据库 3306 端口
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "1234", "stuinfo", 3306, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
		return false;
	}
	else
	{
		AfxMessageBox(_T("成功连接数据库!"));
		// 设置字符集， 使程序支持中文。
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'");//解决从数据库中读取数据后汉字乱码显示的问题 
	}
	return true;
}

vector<StuInfo> SQLInterface::Get_All_Info()
{
	vector<StuInfo> Info;
	
	// C语言组合字符串
	snprintf(sql, SQL_MAX, "SELECT * FROM info1");
	// 查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// 判断查询结果
	if (ret) {
		AfxMessageBox(_T("查询失败!"));
		return Info;
	}
	// 获取结果集
	res = mysql_store_result(&mysqlCon);
	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		StuInfo stuinfo = StuInfo(row[0], row[1], atoi(row[2]), stod(row[3]), stod(row[4]), stod(row[5]));
		Info.push_back(stuinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return Info;
}

bool SQLInterface::Add_Info(StuInfo Info)
{
	// C语言字符串组合
	snprintf(sql, SQL_MAX, "INSERT INTO info1 VALUES('%s', '%s', %d, %lf, %lf, %lf);"
		, Info.m_name.c_str(), Info.m_sex.c_str(), Info.m_class_, Info.m_score1, Info.m_score2, Info.m_score3);
	// 查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// 判断查询结果
	if (ret) {
		AfxMessageBox(_T("添加失败!"));
		return false;
	}
	return true;
}

bool SQLInterface::Del_Info(StuInfo Info)
{
	// C语言字符串组合
	snprintf(sql, SQL_MAX, "DELETE FROM info1 WHERE name = '%s';", Info.m_name.c_str());
	// 查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// 判断查询结果
	if (ret) {
		AfxMessageBox(_T("删除失败!"));
		return false;
	}
	return true;
}

bool SQLInterface::Update_info(StuInfo old_Info, StuInfo new_Info)
{
	// C语言字符串组合
	snprintf(sql, SQL_MAX, "UPDATE info1 SET name = '%s', sex = '%s', class_ = %d, score1 = %lf, score2 = %lf, score3 = %lf WHERE name = '%s'"
		, new_Info.m_name.c_str(), new_Info.m_sex.c_str(), new_Info.m_class_, new_Info.m_score1, new_Info.m_score2, new_Info.m_score3, old_Info.m_name.c_str());
	// 查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// 判断查询结果
	if (ret) {
		AfxMessageBox(_T("修改失败!"));
		return false;
	}
	return true;
}

vector<StuInfo> SQLInterface::Seek_info(CString name)
{
	vector<StuInfo> result;

	// C语言字符串组合
	snprintf(sql, SQL_MAX, "SELECT * FROM info1 where name = '%s';", name);
	// 查询数据
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	// 判断查询结果
	if (ret) {
		AfxMessageBox(_T("查询失败!"));
		return result;
	}
	// 获取结果集
	res = mysql_store_result(&mysqlCon);
	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		StuInfo stuinfo = StuInfo(row[0], row[1], atoi(row[2]), stod(row[3]), stod(row[4]), stod(row[5]));
		result.push_back(stuinfo);
	}
	// 释放结果集
	mysql_free_result(res);
	return result;
}

void SQLInterface::Close_MySQL()
{
	// 关闭数据库
	mysql_close(&mysqlCon);
}
