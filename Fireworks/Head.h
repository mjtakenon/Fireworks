#pragma once

#include <Siv3D.hpp>
#include <vector>

#include "Tail.h"

using namespace std;

class Head
{
public:
	Head(Vec2 position, Point size, Vec2 speed, int explodeTime, int tailLength, Color color)
	{
		m_Position = position;
		m_Speed = speed;
		m_Size = size;
		m_Length = tailLength;
		m_Color = color;

		m_Acceleration = Vec2(0, 9.8)/60;

		m_Tail = new Tail(m_Position,m_Length);
	}

	~Head()
	{
	}

	void Update()
	{
		m_Position += m_Speed;
		m_Speed += m_Acceleration;

		m_Tail->Update(m_Position);
	}

	void Draw() const
	{
		Ellipse(m_Position, m_Size).draw(m_Color);
		m_Tail->Draw();
	}

private:

	Vec2	m_Position;		//座標
	Vec2	m_Speed;		//速度
	Vec2	m_Acceleration;	//加速度

	Point	m_Size;			//星の大きさ
	int		m_ExplodeTime;	//星が見えるようになるまでの時間
	Color	m_Color;		//星の色

	Tail*	m_Tail;			//尾
	int		m_Length;		//尾の長さ
};