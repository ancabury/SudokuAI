#include <queue>
#include <set>
#include <stack>

using namespace std;
using namespace BestFS;

namespace GBFS {
	queue<pair<int, int>> waitQ;
	set<int> posib[9][9];
	int sol[9][9];

	bool solutie() {
		//the function checks if we have found a solution
		for(int i = 0;i < 9;i++) {
			for(int j = 0;j < 9;j++) {
				if(sol[i][j] == 0)
					return false;
				else
					if(!valid(i, j, sol))
						return false;
				}
			}
		return true;
		}

	void gbfsRecursive() {
		//the recusive function which should determin a valid solution
		pair<int, int> crtPos;
		int value, i, j;

		if(waitQ.empty() == false)
			if(!checkValidity()) {
				return;
				}
			else {
				crtPos = waitQ.front();
				waitQ.pop();
				i = crtPos.first;
				j = crtPos.second;

				if(posib[i][j].size() == 1) {
					if(sol[i][j] == 0)
						sol[i][j] = *(posib[i][j].begin());
					value = sol[i][j];
					erase_value(i, j, value);
					refreshQueue();
					gbfsRecursive();
					}
				else {
					for(set<int>::iterator it = posib[i][j].begin();it != posib[i][j].end();) {
						value = *(++it);
						sol[i][j] = value;
						erase_value(i, j, value);
						refreshQueue();
						gbfsRecursive();
						}
					}
				}
		}

	void gbfs(int mat[9][9]) {
		createPosibilitySet(mat);
		inserIntoQueue();
		if(!solutie())
			for(int i = 0;i < 9;i++)
				for(int j = 0;j < 9;j++)
					sol[i][j] = 0;

		}
	}