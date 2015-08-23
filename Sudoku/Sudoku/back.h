#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;
#define n 9

namespace Back {
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

	void print_solution(int mat[9][9]) {
		// the function prints the matrix mat
		ofstream g("output.txt");
		int i, j;

		for(i = 0;i < n;i++) {
			for(j = 0;j < n;j++)
				cout << mat[i][j] << " ";
			cout << "\n";
			}
		cout << "\n";
		g.close();
		}

	int valid(int x, int y, int mat[9][9]) {
		// the function checks if the boars is valid
		// no duplicates on line, column or in little square
		// x: current line
		// y: current column
		// mat: matrix
		int found = 0;
		for(int i = 0;i < n;i++) // coloana
			if(mat[x][y] == mat[i][y])
				found++;
		for(int i = 0;i < n;i++) // linie
			if(mat[x][y] == mat[x][i])
				found++;
		// patrat
		int x_crt, y_crt;
		x_crt = (x / 3) * 3;
		y_crt = (y / 3) * 3;
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < 3;j++)
				if(mat[x_crt + i][y_crt + j] == mat[x][y])
					found++;
		if(found == 3)
			return 1;
		return 0;
		}

	void back(int i, int j, int mat[9][9]) {
		// the backtracking algorithm
		// i: current line
		// j: current column
		// mat: matrix
		if(mat[i][j] == 0) {
			for(int value = 1; value <= n; value++) {
				mat[i][j] = value;

				if(valid(i, j, mat)) {
					if(i == n - 1 && j == n - 1) {
						save_solution(mat);
						}
					else if(j == n - 1) {
						back(i + 1, 0, mat);
						}
					else {
						back(i, j + 1, mat);
						}
					}
				}
			mat[i][j] = 0;
			}
		else {
			if(i == n - 1 && j == n - 1) {
				save_solution(mat);
				}
			else if(j == n - 1) {
				back(i + 1, 0, mat);
				}
			else {
				back(i, j + 1, mat);
				}
			}
		}

	void readFile(int mat[9][9], string fileName) {
		// the function reads the input file and saves it in matrix mat
		// fileName: input file
		ifstream f(fileName);

		int i, j;
		char line[20], *p;

		i = 0;
		while(!f.eof() && i < n) {
			f.getline(line, 20);
			p = strtok(line, " ");
			for(j = 0;j < n && p;j++) {
				mat[i][j] = atoi(p);
				p = strtok(NULL, " ");
				}
			i++;
			}
		f.close();
		}
	}