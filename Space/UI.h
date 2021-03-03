#pragma once
class UI : public Singleton<UI>
{
private:

	Sprite* m_Hp;
	

public:

	int m_PlayerHp;

public:

	UI();
	//
	void Init();
	void Render();
	void Update();

	


};

