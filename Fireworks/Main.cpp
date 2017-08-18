
# include <Siv3D.hpp>

#include "Botan.h"

void Main()
{
	vector<Color> c = vector<Color>();
	c.push_back(Palette::White); c.push_back(Palette::Yellow);
	Botan* botan = new Botan(Vec2(500, 500), Vec2(0, -10), c, 100);

	while (System::Update())
	{
		ClearPrint();
		botan->Update();
		botan->Draw();
	}
}
