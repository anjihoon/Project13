#include <iostream>

using namespace std;

template <typename T>
int sum(T arg) { //template 중에 arg값을 리턴으로 받는 함수 구현
	return arg;
}
template<typename T, typename... types>
int sum(T arg, types... args) {
	return arg + sum(args...);
	// 리턴 받은 값 들의 더해 총 합을 구하는 함수 구현
}
template <typename... args>
int average(args...nums) {
	return sum(nums...) / sizeof...(nums);
	//평균의 분자는 sum함수의 총합 분모는 sizeof함수를 사용하여 평균 구현
}
int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}