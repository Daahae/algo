#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> Q;
	vector<int> waitWork; //대기작업 집단

	for (int i = 0;i < progresses.size();i++) {
		int restWork = 100 - progresses[i];
		int day = restWork / speeds[i];
		
		if (restWork% speeds[i] != 0)
			day++;
        Q.push(day);
	}
	// Q <- 1,7,3,9,4,5
    // 첫번 째 값 넣고시작
	waitWork.push_back(Q.front());
    Q.pop();

	while (!Q.empty()) {
        
        // waitWork[0] = 작업 단위를 묶는 limit 개발 날짜
		if (Q.front() <= waitWork[0]) {
			waitWork.push_back(Q.front());
		}
		else {
            
            // 대기순위에 있던 작업들 갯수 더함
			answer.push_back(waitWork.size());
			waitWork.clear();
			waitWork.push_back(Q.front());
        }
		Q.pop();
	}
	answer.push_back(waitWork.size());
	return answer;
}
