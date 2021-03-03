#pragma once
class Danger : public Object
{
private:

	Sprite* m_Danger;



public:

	Danger(int pt, Vec2 pos);
	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);



	float m_AttackTime;
	bool m_AttackCheck;


	int m_Pattern;

};

