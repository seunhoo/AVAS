#pragma once
class ScoreMgr : public Singleton<ScoreMgr>
{
private:




public:

	ScoreMgr();


	float m_Score;
	void Update();
	float GetScore() { return m_Score; }
	float SetScore() { m_Score = 0; }





};

