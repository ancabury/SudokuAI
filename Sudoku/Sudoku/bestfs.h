#include <queue>
#include <set>
#include <stack>

using namespace std;
using namespace Back;

namespace BestFS {

	queue<pair<int, int>> waitQ;
	set<int> posib[9][9], aux[9][9];
	int sol[9][9];

	void createPosibilitySet(int mat[9][9]) {
		//the function creates the set with all valid values to be assigned for the position (i, j)
		//mat: the inital matrix
		for(int i = 0;i < 9;i++) {
			for(int j = 0;j < 9;j++) {
				if(mat[i][j] == 0) {
					for(int k = 1;k <= 9;k++) {
						mat[i][j] = k;
						if(valid(i, j, mat)) {
							posib[i][j].insert(k);
							aux[i][j].insert(k);
							}
						}
					mat[i][j] = 0;
					}
				else {
					posib[i][j].insert(mat[i][j]);
					aux[i][j].insert(mat[i][j]);
					}
				}
			}
		}

	void inserIntoQueue() {
		// the function adds to queue wait all position order by the size of the set associated
		// if size == 1 add the value in the solution, only valid value
		int size = 9;
		while(waitQ.size() < 81) {
			for(int i = 0;i < 9;i++) {
				for(int j = 0;j < 9;j++) {
					if(posib[i][j].size() == size) {
						if(size == 1)
							sol[i][j] = *(posib[i][j].begin());
						waitQ.push(make_pair(i, j));
						}
					}
				}
			size--;
			}
		}

	void erase_value(int line, int col, int value) {
		// the function removes the value from the sets which are on the same line, column or little square
		//erase line set
		for(int j = 0;j < 9;j++) {
			posib[line][j].erase(value);
			}
		//erase coloumn set
		for(int i = 0;i < 9;i++) {
			posib[i][col].erase(value);
			}
		//erase square
		int topleft_i = (line / 3) * 3;
		int topleft_j = (col / 3) * 3;
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++)
				posib[topleft_i + i][topleft_j + j].erase(value);
		}

	void undoErase(int line, int col, int value) {
		// the function inserts the value back in the sets which are on the same line, column or little square
		// it keeps the validity of the matrix
		int solValue;
		//insert line set
		for(int j = 0;j < 9;j++) {
			solValue = sol[line][j];
			sol[line][j] = value;
			if(valid(line, j, sol))
				posib[line][j].insert(value);
			sol[line][j] = solValue;
			}
		//insert coloumn set
		for(int i = 0;i < 9;i++) {
			solValue = sol[i][col];
			sol[i][col] = value;
			if(valid(i, col, sol))
				posib[i][col].insert(value);
			sol[i][col] = solValue;
			}
		//insert square
		int topleft_i = (line / 3) * 3;
		int topleft_j = (col / 3) * 3;
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++) {
				solValue = sol[topleft_i + i][topleft_j + j];
				sol[topleft_i + i][topleft_j + j] = value;
				if(valid(topleft_i + i, topleft_j + j, sol))
					posib[topleft_i + i][topleft_j + j].insert(value);
				sol[topleft_i + i][topleft_j + j] = solValue;
				}
		}

	void refreshQueue() {
		// the function reorders pairs in queue so that the ones with the min size are first to come out
		queue<pair<int, int>> aux[10];
		pair<int, int> crtPos;
		int i, j;
		while(waitQ.empty() == false) {
			crtPos = waitQ.front();
			waitQ.pop();
			i = crtPos.first;
			j = crtPos.second;
			aux[posib[i][j].size()].push(make_pair(i, j));
			}
		for(int i = 1;i <= 9;i++) {
			while(aux[i].empty() == false) {
				crtPos = aux[i].front();
				aux[i].pop();
				waitQ.push(crtPos);
				}
			}
		}

	bool checkValidity() {
		// the function looks if there is any emtpy pair in queue 
		// this means invalidity
		queue<pair<int, int>> aux;
		pair<int, int> crtP;
		aux = waitQ;
		while(aux.empty() == false) {
			crtP = aux.front();
			aux.pop();
			if(posib[crtP.first][crtP.second].size() == 0)
				return false;
			}
		return true;
		}

	bool bestfsRecursive() {
		// the function which determines a valid solution
		pair<int, int> crtPos;
		int value, i, j;
		bool zero = false;

		if(waitQ.empty() == false)
			if(!checkValidity()) {
				return false;
				}
			else {
				crtPos = waitQ.front();
				waitQ.pop();
				i = crtPos.first;
				j = crtPos.second;

				if(posib[i][j].size() == 1) {
					if(sol[i][j] == 0) {
						sol[i][j] = *(posib[i][j].begin());
						zero = true;
						}
					value = sol[i][j];
					erase_value(i, j, value);
					refreshQueue();
					if(!bestfsRecursive())
						return false;
					else
						return true;
					if(zero)
						sol[i][j] = 0;
					undoErase(i, j, value);
					}
				else {
					for(set<int>::iterator it = posib[i][j].begin();it != posib[i][j].end();) {
						value = *(++it);
						sol[i][j] = value;
						erase_value(i, j, value);
						refreshQueue();
						if(!bestfsRecursive())
							return false;
						else
							return true;
						//undo
						sol[i][j] = 0;
						undoErase(i, j, value);
						}
					}
				}
		else
			return false;
		}

	void bestfs(int mat[9][9]) {
		createPosibilitySet(mat);
		inserIntoQueue();
		bestfsRecursive();
		}
	}