#include "stdafx.h"
#include "Block.h"

Block::Block(Vec2 pos, int type)
{
	switch (type)
	{
	case 1:
		m_Block = Sprite::Create(L"Painting/UnderGround.png");
		m_Block->SetParent(this);
		break;
	case 2:
		m_Block = Sprite::Create(L"Painting/MiddleGround1.png");
		m_Block->SetParent(this);
		break;

	}


	SetPosition(pos.x,pos.y);


}

void Block::Update(float deltatime, float time)
{


}

void Block::Render()
{
	m_Block->Render();
}
