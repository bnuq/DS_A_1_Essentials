#include<vector>
using namespace std;


//Min Heap => �θ� �ڽĺ��� �۴�
template <typename T>
class Heap{
	
	//1���� �迭�� �����ȴ� => ������ �׸� ���� Tree �� �׸���
	vector<T> v{};

	//Max Heap ���� Min Heap ���� �����ϴ� ��� ����
	//true => Min Heap
	//false => Max Heap
	bool heapType{ true };

	//�� ���� ���ϴ� ��� �Լ�
	//Heap Type �� ���� �ٸ� ����� �����Ѵ�
	bool comVal(const T& a, const T& b) {
		bool tmp = a < b;
		
		return (heapType ? tmp : !tmp);
	}


	//Heap �� �ƴ� ���� => Heap �� ������ ������ �� �ֵ���
	//�ٽ� Heap �� ����� �Լ�, O(log N)
	void heapify(int i){ //i ��° element => Heap �� ��ģ ����

		//������ �ִ� element �� �ڽ� �ε����� ���Ѵ�
		int left = 2*i;
		int right = 2*i + 1;

		
		//Min Heap => ���� ���� ���� �ö󰡾� �ϹǷ� => �ڽ� �� ���� ���� ã�´�
		//Max Heap => ���� ū ���� �ö󰡾� �ϹǷ� => �ڽ� �� ū ���� ã�´�
		int targetIdx = i;
		//�ϴ� ���� �ڽ� ���θ� Ȯ�� => �� �� ��
		//if(left < v.size() and v[left] < v[minIdx]){
		if (left < v.size() and comVal(v[left], v[targetIdx])) {
			targetIdx = left;
		}
		//���� ������ �ڽ� ���θ� ���� Ȯ�� => ��, �տ��� ã�� �ּҰ��� ��
		//if(right < v.size() and v[right] < v[minIdx]){
		if (right < v.size() and comVal(v[right], v[targetIdx])) {
			targetIdx = right;
		}

		if(targetIdx != i){ //�ڽ��� �� �� ���� ��� or ������ ��� ���� ��� - �� �����ϰ�
			
			//���� ���� �ڽİ� ���� ���� �ٲ� ��
			swap(v[i],v[targetIdx]);

			//���� �ٲ� element �ڸ��� �� Heap �� ��ġ�� �����Ƿ�
			//�ٽ� heapify �Լ��� ���� => recursion
			heapify(targetIdx);
		}
	}



public:
	Heap(bool htype, int default_size = 10) : heapType{ htype } {

		//vector ����� �̸� �ø���
		//growing �� ���ϱ� ���ؼ� ���������� �޸𸮸� �Ҵ��� ������
		//����� �þ ���� �ƴϴ�
		v.reserve(default_size+1);
		
		//0 index �� ���� �ʴ´�
		v.push_back(T{});
	};

	void push(T data){ //Insert ����, O(log N)

		//add data to end of the heap
		//�׻� ������ ��ġ�� ���� �ִ´�
		v.push_back(data);

		int idx = v.size() - 1; //������ ��ġ�� ����Ű�� �ε���
		int parent = idx/2;		//�θ� ���� �׻� ���� ������ ���� �� �ִ�

		//������ ������ ��ġ�� �ְ� ����, �� ��ġ�� �θ�� ���Ѵ�

		//idx == 1 => ���̻� �θ� ���� => ���̻� ���� swap �� �� ����
		//�θ� �ڽĺ��� �۾ƾ� �ϹǷ�, �ڽ��� �� ���� ��� swap �Ѵ�
		//while(idx>1 and v[idx] < v[parent]){
		while (idx > 1 and comVal(v[idx], v[parent])) {
			
			swap(v[idx],v[parent]);	//�� ���� ���� �θ� �ǵ���
			
			//�ڽİ� �θ� �ε����� ���� ����
			idx = parent;			
			parent = parent/2;
		}
	}


	//return min element <= Min Heap �̴ϱ�
	int top(){
		return v[1];
	}


	//Remove min element
	void pop(){

		//1. Swap first and last element
		//���� ����⿡ �ִ� ���� ���� ���������� ������ => �����ع�����
		int idx = v.size() - 1;
		swap(v[1],v[idx]); //���� ������ �� swap
		v.pop_back();	   //������ ����

		//���� min element �� ���������� swap �߱� ������
		//Heap �� ������ �������� ���ϰ� �ִ� => �ٽ� Heap �� �����
		//���� ������� 1�� �ε����� �����̱� ������, 1���� ���� => recursion
		heapify(1);
	}	

	bool empty(){
		return v.size()==1;
	}

};