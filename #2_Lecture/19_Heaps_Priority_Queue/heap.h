#include<vector>
using namespace std;


//Min Heap => 부모가 자식보다 작다
template <typename T>
class Heap{
	
	//1차원 배열로 구성된다 => 하지만 그릴 때는 Tree 로 그린다
	vector<T> v{};

	//Max Heap 인지 Min Heap 인지 구별하는 멤버 변수
	//true => Min Heap
	//false => Max Heap
	bool heapType{ true };

	//두 값을 비교하는 멤버 함수
	//Heap Type 에 따라 다른 결과를 리턴한다
	bool comVal(const T& a, const T& b) {
		bool tmp = a < b;
		
		return (heapType ? tmp : !tmp);
	}


	//Heap 이 아닌 상태 => Heap 의 성질을 유지할 수 있도록
	//다시 Heap 을 만드는 함수, O(log N)
	void heapify(int i){ //i 번째 element => Heap 을 망친 범인

		//문제가 있는 element 의 자식 인덱스를 구한다
		int left = 2*i;
		int right = 2*i + 1;

		
		//Min Heap => 가장 작은 값이 올라가야 하므로 => 자식 중 작은 값을 찾는다
		//Max Heap => 가장 큰 값이 올라가야 하므로 => 자식 중 큰 값을 찾는다
		int targetIdx = i;
		//일단 왼쪽 자식 여부를 확인 => 후 값 비교
		//if(left < v.size() and v[left] < v[minIdx]){
		if (left < v.size() and comVal(v[left], v[targetIdx])) {
			targetIdx = left;
		}
		//역시 오른쪽 자식 여부를 먼저 확인 => 후, 앞에서 찾은 최소값과 비교
		//if(right < v.size() and v[right] < v[minIdx]){
		if (right < v.size() and comVal(v[right], v[targetIdx])) {
			targetIdx = right;
		}

		if(targetIdx != i){ //자식이 둘 다 없는 경우 or 문제가 사실 없는 경우 - 를 제외하고
			
			//가장 작은 자식과 문제 값을 바꾼 뒤
			swap(v[i],v[targetIdx]);

			//이제 바뀐 element 자리가 또 Heap 을 망치고 있으므로
			//다시 heapify 함수를 적용 => recursion
			heapify(targetIdx);
		}
	}



public:
	Heap(bool htype, int default_size = 10) : heapType{ htype } {

		//vector 사이즈를 미리 늘린다
		//growing 을 피하기 위해서 내부적으로 메모리만 할당한 것이지
		//사이즈가 늘어난 것은 아니다
		v.reserve(default_size+1);
		
		//0 index 는 쓰지 않는다
		v.push_back(T{});
	};

	void push(T data){ //Insert 동작, O(log N)

		//add data to end of the heap
		//항상 마지막 위치에 먼저 넣는다
		v.push_back(data);

		int idx = v.size() - 1; //마지막 위치를 가리키는 인덱스
		int parent = idx/2;		//부모 노드는 항상 절반 값으로 구할 수 있다

		//무조건 마지막 위치에 넣고 나서, 그 위치의 부모와 비교한다

		//idx == 1 => 더이상 부모가 없다 => 더이상 값을 swap 할 수 없다
		//부모가 자식보다 작아야 하므로, 자식이 더 작은 경우 swap 한다
		//while(idx>1 and v[idx] < v[parent]){
		while (idx > 1 and comVal(v[idx], v[parent])) {
			
			swap(v[idx],v[parent]);	//더 작은 값이 부모가 되도록
			
			//자식과 부모 인덱스를 새로 구함
			idx = parent;			
			parent = parent/2;
		}
	}


	//return min element <= Min Heap 이니까
	int top(){
		return v[1];
	}


	//Remove min element
	void pop(){

		//1. Swap first and last element
		//가장 꼭대기에 있던 값을 가장 마지막으로 보내서 => 제거해버린다
		int idx = v.size() - 1;
		swap(v[1],v[idx]); //가장 꼭대기와 끝 swap
		v.pop_back();	   //마지막 제거

		//기존 min element 는 제거했지만 swap 했기 때문에
		//Heap 의 성질율 유지하지 못하고 있다 => 다시 Heap 을 만든다
		//가장 꼭대기인 1번 인덱스가 문제이기 떄문에, 1부터 시작 => recursion
		heapify(1);
	}	

	bool empty(){
		return v.size()==1;
	}

};