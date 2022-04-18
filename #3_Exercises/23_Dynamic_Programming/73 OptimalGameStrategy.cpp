#include <bits/stdc++.h>
using namespace std;


// 이거는 Top Down 방식으로만 풀 수 있겠네
// Top Down 방식으로 먼저 생각한 다음에, 그 다음에 Bottom Up 이 가능한지 생각하기

/* 
    A 와 B 가 서로 번갈아 가면서 동전을 하나씩 가져간다
    A 부터 가져가고 그 다음 B 가 가져가는데
    둘은 전략을 이미 세우고 있어서, 가장 이득이 되는 선택을 매번 계산해서 가져간다
    A 가 취할 수 있는 최대 이득을 계산하라
    
    주어진 동전 값 배열 v
    동전은 양 끝에 있는 것만 가져갈 수 있으므로
    동전의 범위 [s, e] 에서
    s 에 있는 동전을 가져가거나 e 에 있는 동전만 가져갈 수 있다

    동전 범위 [s, e] 에서 최종적으로 얻을 수 있는 최대 값을
    A 가 얻는 함수
 */
int game(vector<int>& v, int s, int e){

    // 범위 내에 동전이 하나만 있거나 2개만 있는 경우
    // 그 중 값이 큰 걸 가져와야 최대 값이 나온다
    if(s==e || s==e-1){
        return max(v[s],v[e]);
    }

    /* 
        A 가 s 에 있는 동전을 취하는 경우
        남아있는 범위인 [s+1, e] 에서 B 가 선택을 하게 되고
        이후에 다시 A 가 선택을 해서 => 최종적으로 어떤 값을 얻게 된다
        
        B 가 s+1 을 가져오는 경우
            [s+2, e] 로 범위 조정
        B 가 e 를 가져오는 경우
            [s+1, e-1] 로 범위 조정
            
        B 는 똑똑하기 때문에
        자신이 동전을 가져온 후, 동전 배열에서 최종적으로 A 가 얻을 수 있는 값을 계산할 수 있고
        A 가 값을 최소로 얻어야 하므로
        그 중에서 값이 작은 것이 나오는 경우를 선택할 것이다
     */
    int op1=v[s] + min(game(v,s+2,e),game(v,s+1,e-1));

    // A 가 e 에 있는 동전을 선택하는 경우
    // 마찬가지로 B 는 자신의 선택 이후, A 가 최소 값을 얻게 되는 경우를 선택한다
    int op2=v[e] + min(game(v,s+1,e-1),game(v,s,e-2));

    // A 가 할 수 있는 두 선택 중에서, 더 큰 값을 리턴하는 경우를 선택한다
    return max(op1,op2); 
}



int MaxValue(int n, vector<int> v){
    int res=game(v,0,n-1);
    return res;
}