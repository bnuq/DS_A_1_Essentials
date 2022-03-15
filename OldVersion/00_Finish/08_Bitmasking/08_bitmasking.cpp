#include <iostream>
using namespace std;


void bitwise() { // Bit Manipulation
	cout << (5 & 7) << endl; // Binary AND
	cout << (5 | 7) << endl; // Binary OR
	cout << (5 ^ 7) << endl; // Binary XOR => 같으면 0, 다르면 1, Exclusive 해야 한다
	
	int x = 0; // 000000
	cout << (~x) << endl; // Binary NOT => 111111 => -1 출력, 2의 보수법

	cout << (5 << 2) << endl; // Binary Left Shift , 곱한 효과
	cout << (5 >> 2) << endl; // Binary Right Shift, 나눈 효과
}


/*
	어떤 숫자가 binary 로 표현될 때, last bit, 가장 낮은 비트를 조사
	=> 1 => Odd
	=> 0 => Even 
	따라서, last bit 만 알아내면 홀수, 짝수를 알아낼 수 있다
	
	1 == 0000001 => 따라서 1 과 Binary AND 시키면, 마지막 비트만 얻을 수 있다
	앞부분비트 => 0 과 AND => 무조건 0이 된다
	마지막비트 => 1 과 AND => 자신이 가지고 있던 비트가 나온다
*/
void checkOddOrEven(int x) {
	if (x & 1)	cout << "Odd";
	else		cout << "Even";
}


/*
	(1 << i) => 1 이 i 번 왼쪽으로 이동 => 뒤로 0 이 i 개 생긴다, 인덱스 0 부터 셌을 때 1 은 인덱스 i 에 위치
	나머지 비트에는 0 만 존재하는 마스크를 만들수 있다
*/
int getIthBit(int n, int i) { // i 번째 비트 값을 얻어냄
	int mask = (1 << i); // i 번째만 1 이 존재
	return (n & mask) > 0 ? 1 : 0; // i 번째 비트가 0 이라면 결과가 0 일것이고, 아니라면 양수일 것
}
void setIthBit(int& n, int i) { // i 번째 비트 값을 1 로 설정
	int mask = (1 << i);
	n = (n | mask); // OR 이용 => 무조건 i 번째는 1 이 되도록 한다
}
void clearIthBit(int& n, int i) { // i 번째 비트 값을 삭제, 0 으로 만든다
	int mask = ~(1 << i); // i 번째만 0 이고 나머지 비트는 1 인 마스크
	n = n & mask; // AND => 1 인 곳은 기존 값 유지, 0 인 곳은 0 으로 만들어 버림
}
void updateIthBit(int& n, int i, int v) { // i 번째 비트 값을 v 로 설정
	clearIthBit(n, i); // 일단 i 번째를 지워 ~ 0 으로 만들어 버리면, 설정하기 쉽다
	int mask = (v << i); // v 값이 i 번째에 위치한 마스크를 만듦
	n = n | mask; //sets the right value
}
void clearLastIBits(int& n, int i) { // i 개의 비트를 삭제 => 인덱스 0 ~ i-1 까지의 비트를 삭제
	// 뒤에서 i 개의 비트만 0 이고, 나머지는 1 인 마스크를 만든다
	int mask = (~(0) << i);
	//or int mask = (-1 << i);
	n = n & mask; // 1 인 부분만 살리고 0 인 부분은 없앤다
}
void clearBitsInRange(int& n, int i, int j) { // i 인덱스 ~ j 인덱스 범위의 비트들을 삭제한다
	// ~ j+1, i-1 ~ 0 구간이 1 이고, j ~ i 구간이 0 인 마스크를 만든다
	int a = (~0) << (j + 1); // 111...000 마스크, 0 이 j+1 개 존재, 가장 앞에 있는 0 의 인덱스가 j
	// 00..0100..00 구조에서 1을 빼 => 00..011..11 마스크를 만들 수 있다
	int b = (1 << i) - 1; // 뒤에 0 을 i 개 만들고 1 이 인덱스 i 에 존재 => 1을 빼니까 => i 번째까지 0, 그 뒤로는 1
	int mask = a | b; // OR => j ~ i 만 0 인 마스크가 만들어졌다
	n = n & mask; // AND => 0 인 부분은 삭제를 해버린다
}
void replaceBits(int& n, int i, int j, int m) { // n 의 i ~ j 범위 비트를 m 의 비트로 대체하기
	clearBitsInRange(n, i, j); // 기존 n 의 i~j 비트를 지워주고
	int mask = (m << i);	   // m 을 왼쪽으로 i 만큼 이동 => m 의 last bit 가 i 인덱스에 위치한다
	n = n | mask; // OR => 0 으로 비워놓은 부분에 m 이 온전히 들어가게 된다
}


/*
	n = 2 의 거듭제곱 이다 = binary 표현에서, 100..00 으로 구성된다
	=> (n & (n-1)) == 0 일 것이다
	아니라면, n 은 2 의 거듭제곱이 아니다 ==> 비트 연산을 이용해서 2의 거듭제곱인지를 알아낼 수 있다
*/


// binary bits 에 1 이 몇 개 있는 지 찾는 방법
int count_bits(int n) { // 기본적인 방법	
	int cnt = 0;
	while (n > 0) {
		int last_bit = (n & 1); // & 1 => 가장 마지막 자리를 가져온다
		cnt += last_bit;	  // last_bit == 0 or 1 => 그냥 더하면 카운트가 돼
		n = n >> 1; // right shift => 앞 자리 비트를 오른쪽으로 이동시켜, 마지막 자리 갱신
	}
	return cnt;
}
//Counting Sets Bits : Hack  (Faster method)
int count_bits_hack(int n) {
	int ans = 0;
	while (n > 0) {
		/*
			removes the last set bit from the current number
			숫자에서 1 을 빼면, 가장 낮은 자리에 있던 1 이 0 이 되고 그 이하가 1 로 가득찬다
			따라서 n & (n-1) 을 하면, n 에서 1 이 하나 제거되는 효과
		*/
		n = n & (n - 1);
		ans++;
	}
	return ans;
}


/*
	Fast Exponentitation
	a^n 계산 => a 를 n 번 순서대로 계산하면, O(n) 의 시간이 걸린다
	지수를 binary bits 로 생각 => 2 의 거듭제곱의 합으로 나타낼 수 있다
	밑을 계속 제곱하면서, 그거에 해당하는 지수를 구해? 그 단계에서 지수가 짝수면 곱하는 값이 없는 거다?
	지수에 대해서 right shift => 밑은 제곱이 되는 거고, 지수는 그 때 last bit = 0  이면 곱할 값이 없는거지
	a^7 = a^111 = a^4 * a^2 * a^1
*/
int fastExpo(int a, int n) {
	int ans = 1;
	while (n > 0) {
		int last_bit = (n & 1); // 지수의 1의 자리 수를 가져와
		if (last_bit) { // 1 인 경우 == 지수가 홀수
			ans = ans * a; // 현재 밑의 값을 먼저 곱해놔 => 이제 지수가 짝수
		}
		a = a * a; // 밑을 계속 제곱 => 지수 binary bit 에 맞춰서 진행
		n = n >> 1; // 지수는 다음 자리 수로 계속 넘어가 == 지수를 절반으로 나눈다
	}
	return ans;
}


// n 의 binary bits 표현을 실제 숫자로 바꿔서 리턴
int convertToBinary(int n) {
	int ans = 0;
	int p = 1;

	while (n > 0) {
		int last_bit = (n & 1); // binary bits 에서 1 의 자리 수를 가져와
		ans += p * last_bit; // 10 진법 자릿수를 곱해줘

		p = p * 10; // 다음 자릿수
		n = n >> 1; // 다음 자리 수
	}
	return ans;
}


int main() {
	cout << fastExpo(5, 8) << endl;
}