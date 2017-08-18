#pragma once

#include <Siv3D.hpp>
#include <list>

using namespace std;

class Tail
{
public:
	Tail(Vec2 position, int tailLength)
	{
		m_Positions = list<Vec2>();
		m_Positions.push_back(position);

		m_Length = tailLength;
	}

	~Tail()
	{

	}

	void Update(Vec2 position)
	{
		if (m_Positions.size() > m_Length)
		{
			m_Positions.erase(m_Positions.begin());
		}

		m_Positions.push_back(position);
	}

	void Draw() const
	{
		for (auto itr = m_Positions.begin(); itr != m_Positions.end(); itr++)
		{
		}
	}

private:

	Point	m_Size;
	int		m_Length;
	list<Vec2>	m_Positions;
	Color	m_Color;
};