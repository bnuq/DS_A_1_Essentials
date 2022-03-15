/*
* 실제 list STL 의 메서드를 사용해보자
*/
#include <iostream>
#include <list>
#include <algorithm>


void listBasic() {
	std::list<int> l{};
	l.push_front(9); // 9, == l.push_back(9)
	l.push_front(8); // 8-9

	l.push_back(10); // 8-9-10


	std::list<int>::iterator head{ l.begin() };
	std::list<int>::iterator tail{ l.end() };

	/*
	* insert => 해당 iterator 에 값을 넣고, 기존에 있던 것을 자신 뒤로 붙인다
	*/
	l.insert(l.begin(), 7); // 7-8-9-10
	l.insert(++l.begin(), 77); // 7-77-8-9-10
	l.insert(std::next(l.begin(), 2), 777); // 7-77-777-8-9-10
	l.insert(l.end(), 100); // 7-77-777-8-9-10-100
	l.insert(std::prev(l.end(), 1), 1000); // 7-77-777-8-9-10-1000-100


	for (auto node : l)
		std::cout << node << " , ";
	std::cout << std::endl;

	// Searching
	int key{ 9 };
	std::list<int>::iterator itr{ l.end() };
	for (auto i = l.begin(); i != l.end(); i++) {
		if (*i == key) {
			itr = i;
			break;
		}
	}
	if (itr != l.end()) std::cout << *itr << std::endl;

	// algorithm => find 사용
	auto itr2 = std::find(l.begin(), l.end(), key);
	if (itr2 != l.end()) std::cout << *itr2 << std::endl;

	auto itr3 = std::find_if(l.begin(), l.end(), [key](const auto& e) {
		return e == key;
		});
	if (itr3 != l.end()) std::cout << *itr3 << std::endl;
}

void listRemove() {
	std::list<int> l{ 9,8,7,6,5 };

	l.pop_front();
	l.pop_back();
	l.remove(7); // iterator 를 받는 게 아니고, 값을 받는구나
	l.remove_if([](const auto& e) {
		return e == 6;
		});

	for (auto x : l)
		std::cout << x << " ";
}

std::list<int>::iterator recursiveSearch(std::list<int>& l, std::list<int>::iterator itr, int key) {
	if (itr == l.end()) return itr;

	if (*itr == key) return itr;

	return recursiveSearch(l, ++itr, key);
}

int main() {
	std::list<int> l{ 1,2,3,4 }; // 이렇게 초기화 가능하다
	//auto itr = recursiveSearch(l, l.begin(), 9);
	//if (itr != l.end()) std::cout << *itr << std::endl;

	listRemove();

	std::reverse(l.begin(), l.end());
	std::reverse(l.rbegin(), l.rend());
	for (auto x : l)
		std::cout << x << std::endl;
}