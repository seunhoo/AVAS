#include "stdafx.h"
#include "Danger.h"
#include "Attack.h"


Danger::Danger(int pt,Vec2 pos)
{
	m_Pattern = pt;

	int Direction = rand() % 5 + 1;
	printf("%d \n", Direction);
	printf("%d \n", pt);
	printf("%d", m_Pattern);
	if (pt == 1)
	{
		m_Danger = Sprite::Create(L"Painting/Danger/HalfDanger.png");
		m_Danger->SetParent(this);

		if (Direction == 1)
			SetPosition(480, 1080 / 2);
		else
			SetPosition(1440, 1080 / 2);
	}
	else if (pt == 2)
	{
		m_Danger = Sprite::Create(L"Painting/Danger/UnderDanger.png");
		m_Danger->SetParent(this);
		if (Direction == 1)
			SetPosition(1920 / 2, 300);
		else if (Direction == 2)
			SetPosition(1920 / 2, 500);
		else if (Direction == 3)
			SetPosition(1920 / 2, 100);
		else if (Direction == 4)
			SetPosition(1920 / 2, 700);
		else if (Direction == 5)
			SetPosition(1920 / 2, 900);
	}
	else if (pt == 3)
	{			
		m_Danger = Sprite::Create(L"Painting/Danger/LazerDanger.png");
		m_Danger->SetParent(this);
		SetPosition(pos.x,1080/2);
	}
	

}

void Danger::Update(float deltatime, float time)
{
	m_AttackTime += dt;

	if (m_Pattern == 1)
	{
		if (m_AttackTime >= 1.2)
		{
			m_AttackCheck = true;
		}
		if (m_AttackCheck == true)
		{
			ObjMgr->AddObject(new Attack(Vec2(m_Position.x, m_Position.y + 1000), 1), "Attack");
			m_AttackTime = 0;
			m_AttackCheck = false;
			ObjMgr->RemoveObject(this);
		}
	}
	else if (m_Pattern == 2)
	{
		if (m_AttackTime >= 1.2)
		{
			m_AttackCheck = true;
		}
		if (m_AttackCheck == true)
		{
			ObjMgr->AddObject(new Attack(Vec2(m_Position.x, m_Position.y), 2), "Attack");
			m_AttackTime = 0;
			m_AttackCheck = false;
			ObjMgr->RemoveObject(this);
		}
	}
	else if (m_Pattern == 3)
	{
		m_AttackTime += dt;
		if (m_AttackTime >= 1)
		{
			m_AttackCheck = true;
		}
		if (m_AttackCheck == true)
		{
			ObjMgr->AddObject(new Attack(Vec2(m_Position.x, 0), 3), "Attack");
			m_AttackTime = 0;
			m_AttackCheck = false;
			ObjMgr->RemoveObject(this);
		}
	}
	



}

void Danger::Render()
{
	m_Danger->Render();
}

void Danger::OnCollision(Object* obj)
{
	
}
