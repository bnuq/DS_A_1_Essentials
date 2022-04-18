# DP ( Dynamic Programming )
	DP is all about Remembering what you have solved in the past
					= Memoization


## Top Down DP = Recursion + Memoization
	Start from top
	Start building the big solution by explaing how you build it from smaller solutions
	큰 문제에서를 작은 문제들로 쪼개면서 문제 해결
	해결한 문제는 따로 저장 => 나중에 필요할 때 사용


## Bottom UP DP = Iterative
	Start with small solutions and use it to build larger solutions
	문제를 해결하는 데 필요한 정보를 밑에서 부터 구해나간다
	큰 문제를 해결하는 데 필요한 작은 정보를 먼저 구하고 -> 그걸 바탕으로 큰 문제 해결하기

	배열로 주어지는 경우, 오른쪽부터 혹은 왼쪽부터
	인덱스를 이용해서 범위 표현
	구간 설정을 잘 해야 한다
		어디서부터 어디까지
		어디 이후로 => 끝까지

	2차원 배열을 이용해서, 임의의 구간에 해당하는 값을 저장할 수 있다

	누가 가장 작은가, 검색을 시작해야 하는 시작점이 어디인가 -> 잘 찾아야 한다


## Greedy
	매번 선택에서, 가장 이득이 되는 경우를 선택한다
	가장 값이 크거나, 가장 이득이 되는 경우를 매번 선택

	