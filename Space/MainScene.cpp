#include "stdafx.h"
#include "MainScene.h"
#include "Danger.h"
#include"Player.h"
#include"Block.h"
#include"UI.h"
#include"ScoreMgr.h"
MainScene::MainScene()
	: m_DangerSpawn(true)
	,m_DangerTime(0)
{

}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	//ScoreMgr::GetInst()->SetScore();
	UI::GetInst()->Init();
	m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Arial");
	m_Text->SetColor(255, 255, 255, 255);
		
	ObjMgr->AddObject(new Player(), "Player");
	ObjMgr->AddObject(new Block(Vec2(1920 / 2, 1060),1), "GroundBlock");
	ObjMgr->AddObject(new Block(Vec2(300, 600),2), "MiddleBlock");
	ObjMgr->AddObject(new Block(Vec2(1600, 600), 2), "MiddleBlock");
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	ScoreMgr::GetInst()->Update();
	UI::GetInst()->Update();
	m_DangerTime += dt;

	if (m_DangerTime >= 1 && m_DangerSpawn == true)
	{
		Random = rand() % 3 + 1;
		m_DangerSpawn = false;
		printf("%d \n", Random);
	}
	if (Random == 1)
	{
		ObjMgr->AddObject(new Danger(1,Vec2(0,0)), "HalfDanger");
		Random = 0;
		m_DangerSpawn = false;
	}
	else if (Random == 2)
	{
		ObjMgr->AddObject(new Danger(2,Vec2(0,0)), "HalfDanger");
		Random = 0;
		m_DangerSpawn = false;
	}
	else if (Random == 3)
	{
		int posx = rand() % 1920 + 1;
		i += 100;
		if (i % 5 == 0)
		{
			ObjMgr->AddObject(new Danger(3, Vec2(posx + i/10, 0)), "HalfDanger");
		}

		
	
		if (i >= 1000)
		{
			i = 0;
			Random = 0;
		}
		m_DangerSpawn = false;
	}
	//else if (Random == 4)
	//{
	//	ObjMgr->AddObject(new Danger(4), "HalfDanger");
	//	m_DangerSpawn = false;
	//}
	//else if (Random == 5)
	//{
	//	ObjMgr->AddObject(new Danger(5), "HalfDanger");
	//	m_DangerSpawn = false;
	//}


	if (m_DangerTime >= 1 && m_DangerSpawn == false)
	{
		m_DangerTime = 0;
		m_DangerSpawn = true;
	}


}

void MainScene::Render()
{
	UI::GetInst()->Render();
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + " " + std::to_string(INPUT->GetMousePos().y) + " \n" +
		std::to_string(dt) + " " +std::to_string(gt) , 0, 0);
	m_Text->print(std::to_string(ScoreMgr::GetInst()->GetScore()),1920/2,50);
	Renderer::GetInst()->GetSprite()->End();

	

}
