#include "stdafx.h"
#include "Player.h"
#include"Block.h"
#include"UI.h"
Player::Player()
	:m_PlayerState(State::NONE)
	,m_JumpCheck(false)
	,m_OnBlock(false)
	,m_DoubleJumpCheck(false)
	,m_Falling(false)
	,m_PlayerHp(5)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);

	SetPosition(1920 / 2, 950);

}

Player::~Player()
{
}

void Player::Gravity()
{
	static float vy = 0;
	vy += 9.8f * dt * 2;

	if (!m_OnBlock )
	{
		m_Position.y += vy;
	}
	else
		vy = 0.f;
}


void Player::Update(float deltaTime, float Time)
{
	UI::GetInst()->m_PlayerHp = m_PlayerHp;


	if (m_OnBlock == false)
	{
		if (m_PlayerState == State::NONE)
			ObjMgr->CollisionCheak(this, "MiddleBlock");

		ObjMgr->CollisionCheak(this, "GroundBlock");
	}
	if (m_DamagedCheck == false)
	{
		ObjMgr->CollisionCheak(this, "Attack");
	}
	Damaged();




	if (INPUT->GetKey('A') == KeyState::PRESS  || INPUT->GetKey(VK_LEFT) == KeyState::PRESS )
	{
		m_Position.x -= 9;

		if (m_Position.y < 960)
			m_OnBlock = false;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS || INPUT->GetKey(VK_RIGHT) == KeyState::PRESS)
	{
		m_Position.x += 9;

		if (m_Position.y < 960)
			m_OnBlock = false;
	}

	Jump();
	Gravity();
}

void Player::Jump()
{
	
	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN && m_JumpCheck == false && m_PlayerState != State::JUMP && m_DoubleJumpCheck < 2)
	{
		m_JumpTime = 0;
		m_Accel = 0;
		m_JumpCheck = true;
		
		++m_DoubleJumpCheck;

		m_PlayerState = State::JUMP;
	}
	if (m_PlayerState == State::JUMP)
	{
	
		m_OnBlock = false;
		m_Accel = ((-GR) / 2 * m_JumpTime * m_JumpTime) + (30 * m_JumpTime);
		m_JumpTime += dt * 35.f;
		m_Position.y = m_Position.y - m_Accel;

		if (m_Accel < 0.f)
		{
			m_PlayerState = State::NONE;
			m_JumpCheck = false;
			m_OnBlock = false;
		}

	}


}

void Player::Damaged()
{
	if (m_DamagedCheck == true)
	{
		m_DamagedTime += dt;

		m_Player->A -= 50;
		if(m_DamagedTime >= 1.5)
		{
			m_Player->A = 255;
			m_DamagedCheck = false;
			m_DamagedTime = 0;
		}
	}
}


void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
	if (obj->m_Tag == "MiddleBlock")
	{
		if (obj->m_Collision.top > m_Position.y)
		{
			m_Position.y = obj->m_Position.y - 55;
			m_OnBlock = true;
			m_JumpCheck = false;
			m_DoubleJumpCheck = 0;
		}

	}

	if (obj->m_Tag == "GroundBlock")
	{
		m_Position.y = obj->m_Position.y - 55;
		m_OnBlock = true;
		m_JumpCheck = false;
		m_DoubleJumpCheck = 1;		
	}
	if (obj->m_Tag == "Attack")
	{
		m_PlayerHp -= 1;
		m_DamagedCheck = true;
	}	
}
