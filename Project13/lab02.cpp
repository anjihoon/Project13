#include<iostream>
#include<algorithm>
#include<iterator>
#include<forward_list>

template <typename ForwardIterator>
void bubble_sort(ForwardIterator first, ForwardIterator last) {
    for (ForwardIterator sorted = first; first != last; last = sorted)
    { // ���� ������ �⺻ ������ ����� �̿��Ͽ� �����Ѵ�.
        //iter_swap�Լ��� �̿��Ͽ� �����Ѵ�.
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
/*class compGreater { // �������� ���Ŀ� ���
// functor�� ����(�� ���� �� ����� bool Ÿ������ ����, operator( ) ����)
};
class compLess { // �������� ���Ŀ� ���
// functor�� ����(�� ���� �� ����� bool Ÿ������ ����, operator( ) ����)
};
�� ������ �����ϴ� ����� ���ذ� ���� �ʴ´�.
boolŸ������ ���Ͽ� ��������, ���������� �ϴ� ����� if������ ���� ������
����� ������� �ʾ� �ᱹ �ٸ� ����� �̿��Ͽ���.
*/
int main() {
	std::forward_list<int> values{ 7,0,6,1,5,2,4,3 };
	std::cout << "�������� ����" << std::endl;
    //begin(),end()�� ����Ͽ� �����Ѵ�
    bubble_sort(std::begin(values), std::end(values));
    std::copy(std::begin(values), std::end(values),
        std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "�������� ����" << std::endl;
    values.reverse();
    // ���������� ���������� �ݴ��� reverse()�Լ��� ����Ͽ� ������ �ٲ۴�.
    //������ ��ºκ��� ���������� ����.
    std::copy(std::begin(values), std::end(values),
        std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 0;
}