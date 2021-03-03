#include "stdafx.h"
#include "UI.h"

UI::UI()

{

}

void UI::Init()
{
	m_Hp = Sprite::Create(L"Painting/HpBar5.png");
	m_Hp->SetPosition(1800, 30);

}

void UI::Render()
{
	
	m_Hp->Render();
}

void UI::Update()
{
	if (m_PlayerHp > 5)
	{
		m_PlayerHp = 5;
	}
	if (m_PlayerHp == 5)
	{
		m_Hp = Sprite::Create(L"Painting/HpBar5.png");
		m_Hp->SetPosition(1800, 30);
	}
	else if (m_PlayerHp == 4)
	{
		m_Hp = Sprite::Create(L"Painting/HpBar4.png");
		m_Hp->SetPosition(1800, 30);
	}
	else if (m_PlayerHp == 3)
	{
		m_Hp = Sprite::Create(L"Painting/HpBar3.png");
		m_Hp->SetPosition(1800, 30);
	}
	else if (m_PlayerHp == 2)
	{
		m_Hp = Sprite::Create(L"Painting/HpBar2.png");
		m_Hp->SetPosition(1800, 30);
	}
	else if (m_PlayerHp == 1)
	{
		m_Hp = Sprite::Create(L"Painting/HpBar1.png");
		m_Hp->SetPosition(1800, 30);
	}

}
