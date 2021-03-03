#include "stdafx.h"
#include "ScoreMgr.h"

ScoreMgr::ScoreMgr()
	:m_Score(0)
{
}

void ScoreMgr::Update()
{
	m_Score += dt * 100;
	if (m_Score / 500 == 0)
	{
		m_Score += 100;
	}

}
