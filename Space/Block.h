#pragma once
class Block : public Object
{
	Sprite* m_Block;


public:


	Block(Vec2 pos, int type);

	void Update(float deltatime, float time);
	void Render();



};

