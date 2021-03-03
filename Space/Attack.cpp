#include "stdafx.h"
#include "Attack.h"

Attack::Attack(Vec2 pos, int pt)
{
	m_Pattern = pt;

	if (pt == 1)
	{
		m_Attack = Sprite::Create(L"Painting/Attack/HalfCastle1.png");
		m_Attack->SetParent(this);
		SetPosition(pos.x, pos.y);
	}
	else if (pt == 2)
	{
		m_AniAttack = new Animation();
		m_AniAttack->AddContinueFrame(L"Painting/Attack/Lazer", 1, 6);
		m_AniAttack->Init(1 * dt, true);
		m_AniAttack->SetParent(this);
		SetPosition(pos.x, pos.y);
	}
	else if (pt == 3)
	{
		m_AniAttack = new Animation();
		m_AniAttack->AddContinueFrame(L"Painting/Attack/Bullet", 1, 8);
		m_AniAttack->Init(1 * dt, true);
		m_AniAttack->SetParent(this);

		m_SubAniAttack = new Animation();
		m_SubAniAttack->AddContinueFrame(L"Painting/Attack/Fire", 1, 4);
		m_SubAniAttack->Init(1 * dt, true);
		m_SubAniAttack->SetParent(this);
		SetPosition(pos.x, 1);
	}



}

void Attack::Update(float deltatime, float time)
{

	if (m_Pattern == 1)
	{
		if (m_Position.y >= 500 && m_Down == false)
		{
			m_Accel += dt * 73;
			m_Position.y -= m_Accel;
			if (m_Position.y < 600)
			{
				m_Accel = 0;
				m_Down = true;
			}
		}
		else if (m_Down == true)
		{
			m_Accel += dt * 60;
			m_Position.y += m_Accel;
		}
		if (m_Down == true && m_Position.y > 1500)
		{
			ObjMgr->RemoveObject(this);
		}
	}
	else if (m_Pattern == 2)
	{
		m_AniAttack->Update(deltatime, time);
		if (m_AniAttack->m_CurrentFrame >= 5)
		{
			ObjMgr->RemoveObject(this);
		}
	}
	else if (m_Pattern == 3)
	{
		m_AniAttack->Update(deltatime, time);
		m_SubAniAttack->Update(deltatime, time);
		m_Accel += dt * 50;
		m_Position.y += m_Accel;

		if (m_Position.y >= 1200)
		{
			ObjMgr->RemoveObject(this);
		}
	}



}

void Attack::Render()
{
	if (m_Pattern == 1)
	{
		m_Attack->Render();
	}
	if (m_Pattern == 2)
	{
		m_AniAttack->Render();
	}
	if (m_Pattern == 3)
	{
		m_AniAttack->Render();
		m_SubAniAttack->Render();
	}
}

void Attack::OnCollsion(Object obj)
{
}
