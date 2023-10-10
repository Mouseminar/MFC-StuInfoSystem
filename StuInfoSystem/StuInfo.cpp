#include "pch.h"
#include "StuInfo.h"

StuInfo::StuInfo()
{
}

StuInfo::StuInfo(string name, string sex, int class_, double score1, double score2, double score3)
{
	m_name = name;
	m_sex = sex;
	m_class_ = class_;
	m_score1 = score1;
	m_score2 = score2;
	m_score3 = score3;
}
