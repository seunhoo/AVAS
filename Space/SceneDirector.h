#pragma once
enum class Stage
{
	STAGEONE,
	STAGETWO,
	STAGETHREE,
	STAGEFOUR,
	STAGEFIVE,
	STAGESIX,
	STAGESEVEN,
	STAGEEIGHT,
	STAGENINE,
	STAGETEN

};
class SceneDirector : public Singleton<SceneDirector>
{
	Scene* m_CurrentScene;

public:
	SceneDirector();
	~SceneDirector();

	void ChangeScene(Scene* newScene);

	void Update(float deltaTime, float time);
	void Render();

};

