
#include<iostream>
#include<vector>

using namespace std;


void printMap(int map[13][13], int N) {
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

char getDirection(int coreX, int coreY, int map[13][13], int N) {
	// 가능한 방향 구하기
	int flag = 0;
	int minLength = 14;
	char minDirection = NULL; // 벽까지 거리가 최소가 되는 direction

	//up
	int length = 0;
	for (int i = 0;i < coreX;i++) {
		if (map[i][coreY] != 0) {
			flag = 1;
			break;
		}
		length++;
	}
	if (flag == 0) { // 선 연결이 가능한 경우
		if (minLength > length) { // 가장 짧은 선 방향을 구하기 위한 최솟값 갱신
			minDirection = 'U';
			minLength = length;
		}

	}

	// down
	flag = 0;
	length = 0;
	for (int i = coreX+1;i < N;i++) {
		if (map[i][coreY] != 0) {
			flag = 1;
			break;
		}
		length++;
	}
	if (flag == 0) {
		if (minLength > length) { // 최솟값 갱신
			minDirection = 'D';
			minLength = length;
		}

	}

	//left 
	flag = 0;
	length = 0;
	for (int i = 0;i < coreY;i++) {
		if (map[coreX][i] != 0) {
			flag = 1;
			break;
		}
		length++;
	}
	if (flag == 0) {
		if (minLength > length) { // 최솟값 갱신
			minDirection = 'L';
			minLength = length;
		}

	}

	//right
	flag = 0;
	length = 0;
	for (int i = coreY+1;i < N;i++) {
		if (map[coreX][i] != 0) {
			flag = 1;
			break;
		}
		length++;
	}
	if (flag == 0) {
		if (minLength > length) { // 최솟값 갱신
			minDirection = 'R';
			minLength = length;
		}

	}

	return minDirection;

}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case){
		int N;
		int wireLength = 0;
		int map[13][13];
		vector<pair<int, int>> core;

		cin >> N;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				int val;
				cin >> val;
				map[i][j] = val;

				// 벽에 안 닿아있는 코어 따로 저장
				if (map[i][j] == 1 && i > 0 && j > 0) {
					if(i < N && j < N)
						core.push_back(pair<int, int>(i, j));

				}
			}
		}

		// 유선 연결이 필요한 코어들을 대상으로 선을 연결하고 길이를 계산하는과정
		for (int i = 0;i < core.size();i++) {

			int coreX = core[i].first;
			int coreY = core[i].second;
			char direction = getDirection(coreX, coreY, map, N);


			if (direction == 'U') {//up
				for (int i = 0;i < coreX;i++) {
					map[i][coreY] = 2;
					wireLength++;		
				}
			}

			else if (direction == 'D') {//down
				for (int i = coreX+1;i < N;i++) {
					map[i][coreY] = 2;
					wireLength++;
				}
			}

			else if (direction == 'L') {//left
				for (int i = 0;i < coreY;i++) {
					map[coreX][i] = 2;
					wireLength++;	
				}
			}

			else if (direction == 'R') {//right
				for (int i = coreY + 1;i < N; i++) {
					map[coreX][i] = 2;
					wireLength++;
				}
			}
			printMap(map, N);
		}
		cout << "#" << test_case << " " << wireLength << endl;
	}
	return 0;
}
