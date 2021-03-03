#pragma once

class MainScene : public Scene
{
	Sprite* m_BG;

	TextMgr* m_Text;
public:



	Sprite* m_HalfCastle;

	float m_DangerTime;
	bool m_DangerCheck;

	bool m_DangerSpawn;

	int Random;

	int i;

public:

	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

