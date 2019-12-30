#include <iostream>
#include <vector>
// 정수의 개수
int N_Count;
// 타겟넘버
int Target;
// 정수집합
std::vector<int> Set;
// 집합의 원소들로 만들수 있는 조합의 정수의 합이 Target 과 같다면 SolveResult 를 더한다.
int SolveResult;

// Step
// 1. 정수의 집합을 만듬
// 2. 해당 집합으로 만들수 있는 모든 조합을 구함
// 3. 조합의 원소들의 합이 타겟과 같은 경우의수를 구함
// 4. 재귀로 자기자신을 더한 경우(자기자신을 조합에 포함시킨경우)
// 와 자기자신을 뺀 경우 ( 자기자신을 조합에 포함시키지않은경우) 를 호출하며 개수를 센다.
// 원소개수와 인덱스가 일치하는 경우 재귀를 종료한다. 
void Solve(const int Idx,int Sum)
{
	if (Idx >= N_Count)return;
	Sum += Set[Idx];
	if (Target == Sum)SolveResult++;

	/* 함수호출 시간 복잡도는 집합으로 만들수있는 조합의 경우의 수와 일치함.
	O(2 ^ N); 여기서 N은 당연히 집합의 원소의 수 */
	
	// 자기자신을 조합에 포함시킨 경우
	Solve(Idx + 1, Sum);
	// 자기자신을 조합에 포함시키지 않은  경우
	Solve(Idx + 1, Sum  - Set[Idx]);
};
int main() {
	
std::	cin	>> N_Count >> Target;

	for (int i = 0; i < N_Count; ++i)
	{
		int temp;
		std::cin >> temp;
		Set.emplace_back(temp);
	};
	Solve(0, 0);
	std::cout << SolveResult;
	return 0;
}
