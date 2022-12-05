#include<iostream>
#include<algorithm>
#include<iterator>
#include<forward_list>

template <typename ForwardIterator>
void bubble_sort(ForwardIterator first, ForwardIterator last) {
    for (ForwardIterator sorted = first; first != last; last = sorted)
    { // 버블 정렬의 기본 로직인 방식을 이용하여 정렬한다.
        //iter_swap함수를 이용하여 변경한다.
        sorted = first;
        for (ForwardIterator current = first, prev = first; ++current != last; ++prev)
        {
            if (*current<*prev)
            {
                std::iter_swap(current, prev);
                sorted = current;
            }
        }
    }
}
/*class compGreater { // 오름차순 정렬에 사용
// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
};
class compLess { // 내림차순 정렬에 사용
// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
};
이 로직을 구현하는 방법이 이해가 되지 않는다.
bool타입으로 비교하여 오름차순, 내림차순을 하는 방식이 if문으로 구현 했지만
결과가 도출되지 않아 결국 다른 방식을 이용하였다.
*/
int main() {
	std::forward_list<int> values{ 7,0,6,1,5,2,4,3 };
	std::cout << "오름차순 정렬" << std::endl;
    //begin(),end()를 사용하여 정렬한다
    bubble_sort(std::begin(values), std::end(values));
    std::copy(std::begin(values), std::end(values),
        std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "내림차순 정렬" << std::endl;
    values.reverse();
    // 내림차순은 오름차순의 반대인 reverse()함수를 사용하여 강제로 바꾼다.
    //나머지 출력부분은 오름차순과 같다.
    std::copy(std::begin(values), std::end(values),
        std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}