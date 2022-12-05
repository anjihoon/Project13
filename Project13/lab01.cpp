#include <iostream>

using namespace std;

template <typename T>
int sum(T arg) { //template �߿� arg���� �������� �޴� �Լ� ����
	return arg;
}
template<typename T, typename... types>
int sum(T arg, types... args) {
	return arg + sum(args...);
	// ���� ���� �� ���� ���� �� ���� ���ϴ� �Լ� ����
}
template <typename... args>
int average(args...nums) {
	return sum(nums...) / sizeof...(nums);
	//����� ���ڴ� sum�Լ��� ���� �и�� sizeof�Լ��� ����Ͽ� ��� ����
}
int main() {
	std::cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}