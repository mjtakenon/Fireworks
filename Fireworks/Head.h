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

	Vec2	m_Position;		//���W
	Vec2	m_Speed;		//���x
	Vec2	m_Acceleration;	//�����x

	Point	m_Size;			//���̑傫��
	int		m_ExplodeTime;	//����������悤�ɂȂ�܂ł̎���
	Color	m_Color;		//���̐F

	Tail*	m_Tail;			//��
	int		m_Length;		//���̒���
};