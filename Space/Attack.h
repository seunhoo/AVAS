#pragma once
class Attack : public Object
{
private:

	Sprite* m_Attack;
	Animation* m_AniAttack;
	Animation* m_SubAniAttack;
public:

	Attack(Vec2 pos,int pt);

	void Update(float deltatime, float time);
	void Render();
	void OnCollsion(Object obj);

public: 

	float m_Accel;
	float m_JumpTime;

	bool m_Down;

	int m_Pattern;

};

