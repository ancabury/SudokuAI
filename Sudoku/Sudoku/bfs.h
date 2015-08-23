#include <queue>
#include <set>

using namespace Back;

namespace BFS {
#define n 9

	queue<pair<int, int>> waitQ;
	set<int> posib[9][9];
	int sol[9][9];

	void save_solution(int mat[9][9]) {
		//the function saves the solution in the matrix sol
		//mat: the final solution
		int i, j;

		for(i = 0;i < n;i++) {
			for(j = 0;j < n;j++)
				sol[i][j] = mat[i][j];
			}
		}

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
							}
						}
					mat[i][j] = 0;
					}
				else {
					posib[i][j].insert(mat[i][j]);
					}
				}
			}
		}

	void insertQueue() {
		//the function adds to queue wait all position in the matrix
		for(int i = 0;i < 9;i++) {
			for(int j = 0;j < 9;j++) {
				waitQ.push(make_pair(i, j));
				}
			}
		}

	void bfsRecursive(int mat[9][9]) {
		//the recursive algorithm that solves the sudoku
		//mat: the matrix on which we operate
		int line, col;
		pair<int, int> crtPos;
		crtPos = waitQ.front();
		waitQ.pop();
		line = crtPos.first;
		col = crtPos.second;

		if(mat[line][col] == 0) {
			for(set<int>::iterator it = posib[line][col].begin();it != posib[line][col].end();it++) {
				mat[line][col] = *it;

				if(valid(line, col, mat)) {
					if(waitQ.empty()) {
						save_solution(mat);
						}
					else {
						bfsRecursive(mat);
						}
					}
				}
			mat[line][col] = 0;
			waitQ.push(crtPos);
			}
		else {
			if(waitQ.empty()) {
				save_solution(mat);
				}
			else {
				bfsRecursive(mat);
				}
			}
		}

	void bfs(int mat[9][9]) {
		//mat: the initial matrix
		createPosibilitySet(mat);
		insertQueue();
		bfsRecursive(mat);
		}
	}