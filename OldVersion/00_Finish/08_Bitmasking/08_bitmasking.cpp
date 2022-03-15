#include <iostream>
using namespace std;


void bitwise() { // Bit Manipulation
	cout << (5 & 7) << endl; // Binary AND
	cout << (5 | 7) << endl; // Binary OR
	cout << (5 ^ 7) << endl; // Binary XOR => ������ 0, �ٸ��� 1, Exclusive �ؾ� �Ѵ�
	
	int x = 0; // 000000
	cout << (~x) << endl; // Binary NOT => 111111 => -1 ���, 2�� ������

	cout << (5 << 2) << endl; // Binary Left Shift , ���� ȿ��
	cout << (5 >> 2) << endl; // Binary Right Shift, ���� ȿ��
}


/*
	� ���ڰ� binary �� ǥ���� ��, last bit, ���� ���� ��Ʈ�� ����
	=> 1 => Odd
	=> 0 => Even 
	����, last bit �� �˾Ƴ��� Ȧ��, ¦���� �˾Ƴ� �� �ִ�
	
	1 == 0000001 => ���� 1 �� Binary AND ��Ű��, ������ ��Ʈ�� ���� �� �ִ�
	�պκк�Ʈ => 0 �� AND => ������ 0�� �ȴ�
	��������Ʈ => 1 �� AND => �ڽ��� ������ �ִ� ��Ʈ�� ���´�
*/
void checkOddOrEven(int x) {
	if (x & 1)	cout << "Odd";
	else		cout << "Even";
}


/*
	(1 << i) => 1 �� i �� �������� �̵� => �ڷ� 0 �� i �� �����, �ε��� 0 ���� ���� �� 1 �� �ε��� i �� ��ġ
	������ ��Ʈ���� 0 �� �����ϴ� ����ũ�� ����� �ִ�
*/
int getIthBit(int n, int i) { // i ��° ��Ʈ ���� ��
	int mask = (1 << i); // i ��°�� 1 �� ����
	return (n & mask) > 0 ? 1 : 0; // i ��° ��Ʈ�� 0 �̶�� ����� 0 �ϰ��̰�, �ƴ϶�� ����� ��
}
void setIthBit(int& n, int i) { // i ��° ��Ʈ ���� 1 �� ����
	int mask = (1 << i);
	n = (n | mask); // OR �̿� => ������ i ��°�� 1 �� �ǵ��� �Ѵ�
}
void clearIthBit(int& n, int i) { // i ��° ��Ʈ ���� ����, 0 ���� �����
	int mask = ~(1 << i); // i ��°�� 0 �̰� ������ ��Ʈ�� 1 �� ����ũ
	n = n & mask; // AND => 1 �� ���� ���� �� ����, 0 �� ���� 0 ���� ����� ����
}
void updateIthBit(int& n, int i, int v) { // i ��° ��Ʈ ���� v �� ����
	clearIthBit(n, i); // �ϴ� i ��°�� ���� ~ 0 ���� ����� ������, �����ϱ� ����
	int mask = (v << i); // v ���� i ��°�� ��ġ�� ����ũ�� ����
	n = n | mask; //sets the right value
}
void clearLastIBits(int& n, int i) { // i ���� ��Ʈ�� ���� => �ε��� 0 ~ i-1 ������ ��Ʈ�� ����
	// �ڿ��� i ���� ��Ʈ�� 0 �̰�, �������� 1 �� ����ũ�� �����
	int mask = (~(0) << i);
	//or int mask = (-1 << i);
	n = n & mask; // 1 �� �κи� �츮�� 0 �� �κ��� ���ش�
}
void clearBitsInRange(int& n, int i, int j) { // i �ε��� ~ j �ε��� ������ ��Ʈ���� �����Ѵ�
	// ~ j+1, i-1 ~ 0 ������ 1 �̰�, j ~ i ������ 0 �� ����ũ�� �����
	int a = (~0) << (j + 1); // 111...000 ����ũ, 0 �� j+1 �� ����, ���� �տ� �ִ� 0 �� �ε����� j
	// 00..0100..00 �������� 1�� �� => 00..011..11 ����ũ�� ���� �� �ִ�
	int b = (1 << i) - 1; // �ڿ� 0 �� i �� ����� 1 �� �ε��� i �� ���� => 1�� ���ϱ� => i ��°���� 0, �� �ڷδ� 1
	int mask = a | b; // OR => j ~ i �� 0 �� ����ũ�� ���������
	n = n & mask; // AND => 0 �� �κ��� ������ �ع�����
}
void replaceBits(int& n, int i, int j, int m) { // n �� i ~ j ���� ��Ʈ�� m �� ��Ʈ�� ��ü�ϱ�
	clearBitsInRange(n, i, j); // ���� n �� i~j ��Ʈ�� �����ְ�
	int mask = (m << i);	   // m �� �������� i ��ŭ �̵� => m �� last bit �� i �ε����� ��ġ�Ѵ�
	n = n | mask; // OR => 0 ���� ������� �κп� m �� ������ ���� �ȴ�
}


/*
	n = 2 �� �ŵ����� �̴� = binary ǥ������, 100..00 ���� �����ȴ�
	=> (n & (n-1)) == 0 �� ���̴�
	�ƴ϶��, n �� 2 �� �ŵ������� �ƴϴ� ==> ��Ʈ ������ �̿��ؼ� 2�� �ŵ����������� �˾Ƴ� �� �ִ�
*/


// binary bits �� 1 �� �� �� �ִ� �� ã�� ���
int count_bits(int n) { // �⺻���� ���	
	int cnt = 0;
	while (n > 0) {
		int last_bit = (n & 1); // & 1 => ���� ������ �ڸ��� �����´�
		cnt += last_bit;	  // last_bit == 0 or 1 => �׳� ���ϸ� ī��Ʈ�� ��
		n = n >> 1; // right shift => �� �ڸ� ��Ʈ�� ���������� �̵�����, ������ �ڸ� ����
	}
	return cnt;
}
//Counting Sets Bits : Hack  (Faster method)
int count_bits_hack(int n) {
	int ans = 0;
	while (n > 0) {
		/*
			removes the last set bit from the current number
			���ڿ��� 1 �� ����, ���� ���� �ڸ��� �ִ� 1 �� 0 �� �ǰ� �� ���ϰ� 1 �� ��������
			���� n & (n-1) �� �ϸ�, n ���� 1 �� �ϳ� ���ŵǴ� ȿ��
		*/
		n = n & (n - 1);
		ans++;
	}
	return ans;
}


/*
	Fast Exponentitation
	a^n ��� => a �� n �� ������� ����ϸ�, O(n) �� �ð��� �ɸ���
	������ binary bits �� ���� => 2 �� �ŵ������� ������ ��Ÿ�� �� �ִ�
	���� ��� �����ϸ鼭, �װſ� �ش��ϴ� ������ ����? �� �ܰ迡�� ������ ¦���� ���ϴ� ���� ���� �Ŵ�?
	������ ���ؼ� right shift => ���� ������ �Ǵ� �Ű�, ������ �� �� last bit = 0  �̸� ���� ���� ���°���
	a^7 = a^111 = a^4 * a^2 * a^1
*/
int fastExpo(int a, int n) {
	int ans = 1;
	while (n > 0) {
		int last_bit = (n & 1); // ������ 1�� �ڸ� ���� ������
		if (last_bit) { // 1 �� ��� == ������ Ȧ��
			ans = ans * a; // ���� ���� ���� ���� ���س� => ���� ������ ¦��
		}
		a = a * a; // ���� ��� ���� => ���� binary bit �� ���缭 ����
		n = n >> 1; // ������ ���� �ڸ� ���� ��� �Ѿ == ������ �������� ������
	}
	return ans;
}


// n �� binary bits ǥ���� ���� ���ڷ� �ٲ㼭 ����
int convertToBinary(int n) {
	int ans = 0;
	int p = 1;

	while (n > 0) {
		int last_bit = (n & 1); // binary bits ���� 1 �� �ڸ� ���� ������
		ans += p * last_bit; // 10 ���� �ڸ����� ������

		p = p * 10; // ���� �ڸ���
		n = n >> 1; // ���� �ڸ� ��
	}
	return ans;
}


int main() {
	cout << fastExpo(5, 8) << endl;
}