#pragma once

#include "Fireworks.h"

class Botan : public Fireworks
{
public:
	Botan(Vec2 position, Vec2 speed, vector<Color> colors, int headNum) : Fireworks(position, speed, colors)
	{
		m_HeadNum = headNum;
	}

	~Botan()
	{

	}

private:

	void Explosion() override
	{
		for (int i = 0; i < m_HeadNum; i++)	//head‚Ì’Ç‰Á
		{
			m_Heads.push_back(Head(m_Position, Point(5, 5), Vec2(Cos((m_HeadNum + 1) / (i + 1))*Pi * 2, Sin((m_HeadNum + 1) / (i + 1))*Pi * 2), 10, 0, /*m_Colors[(m_Colors.size() - 1)]*/RandomColor()));
		}
	}
};