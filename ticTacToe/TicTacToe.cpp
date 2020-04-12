#include <iostream>
#include <vector>

using namespace std;

class PlayField
{
public:
	PlayField()
	{

	};
	enum  CellState
	{
		csEmpty,
		csCross,
		csNought
	};
	class CellPos
	{
	public:
		CellPos(CellState state = csEmpty)
		{
			this->state = state;
		};
		void SetState(CellState state)
		{
			this->state = state;
		}
		CellState GetState()
		{
			return this->state;
		}
	private:
		CellState state;
	};
	CellState operator[] (int id)
	{
		switch (this->field[id].GetState())
		{
		case 0:
			return csEmpty;
			break;

		case 1:
			return csCross;
			break;

		case 2:
			return csNought;
			break;
		}
	}
	/*PlayField operator + ()
	{
		PlayField newPf = *this;

		return newPf;
	}*/

	vector<CellPos> GetEmptyCells()
	{
		vector<CellPos> temp;
		for (auto i : this->field)
			if (i.GetState() != csEmpty)
				temp.push_back(i);

		return temp;
	}

private:
	vector<CellPos> field
	{
		CellPos(),
		CellPos(),
		CellPos(),
		CellPos(),
		CellPos(),
		CellPos(),
		CellPos(),
		CellPos(),
		CellPos(),
	};
	vector<int> emptyCells;
};


int main()
{
	PlayField field;



	return 0;
}