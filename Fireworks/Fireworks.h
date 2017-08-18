#pragma once

#include <Siv3D.hpp>
#include <vector>

#include "Head.h"

using namespace std;

class Fireworks
{
public:
	Fireworks(Vec2 position, Vec2 speed, vector<Color> colors)
	{
		m_PrevPosition = vector<Vec2>();

		m_Position = position;
		m_Speed = speed;
		m_Colors = colors;

		m_Acceleration = Vec2(0, 9.8) / 60;

		m_Heads = list<Head>();

		m_isExploded = false;
	}

	~Fireworks()
	{

	}

	void Update()
	{
		m_Position += m_Speed;
		m_Speed += m_Acceleration;

		if (m_Speed.y > 0 && !m_isExploded)
		{
			m_isExploded = true;
			Explosion();
		}

		if (m_isExploded)
		{
			for (auto itr = m_Heads.begin(); itr != m_Heads.end(); itr++)
			{
				itr->Update();
			}
		}

		m_PrevPosition.push_back(m_Position);
	}

	void Draw() const
	{
		if (m_isExploded)
		{
			for (auto itr = m_Heads.begin(); itr != m_Heads.end(); itr++)
			{
				itr->Draw();
			}
		}
		
		Circle(m_Position, 5).draw(Palette::White);
		Println(m_Speed);


	}

protected:

	virtual void Explosion() {}

	Vec2	m_Position;			//座標
	vector<Vec2>	m_PrevPosition;	//座標のログ

	Vec2	m_Speed;			//速度　0で爆発
	Vec2	m_Acceleration;		//加速度
	bool	m_isExploded;		//爆発したか

	list<Head>	m_Heads;		//火玉
	vector<Color>	m_Colors;	//火玉の色
	int		m_HeadNum;			//火玉の数

};

