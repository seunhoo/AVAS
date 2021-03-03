#pragma once

enum class State
{
	JUMP,
	NONE
};

class Player : public Object
{

	Sprite* m_Player;


	float m_Accel;

	float m_JumpTime;

	bool m_OnBlock;

	bool m_Falling;
	bool m_JumpCheck;

	int m_DoubleJumpCheck;

	bool m_DamagedCheck;
	float m_DamagedTime;

	int m_PlayerHp;
	int m_MaxPlayerHp;


	State m_PlayerState;



public:

	Player();
	~Player();


	void Gravity();
	void Jump();
	void Damaged();
	void Update(float deltaTime,float Time);
	void Render();
	void OnCollision(Object* obj);
};

