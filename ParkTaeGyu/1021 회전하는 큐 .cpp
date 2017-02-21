#include<iostream>
#include<deque>
#include<memory.h>
using namespace std;

int num[51];    //Input 
int cnt = 0;    // 2,3�� ���� ī��Ʈ
int funcSecondCnt= 0; // 2�� ���� ī��Ʈ
int funcThirdCnt = 0; // 3�� ���� ī��Ʈ

int main()
{
	int N, M;
	int nChk;     // ã������ ���ڰ� dec�� ���°�� ��ġ�ϴ��� �����ϴ� ����
	cin >> N >> M; 
	memset(num, 0, sizeof(num)); //�迭 �ʱ�ȭ #include<memory.h>
	deque<int> deq;   //�����̳ʷ� �� ���

	//dec �Է�
	for (int i = 1; i <= N; i++)
		deq.push_back(i);
	
	//Input �Է�(ã������ ���� �Է�)
	for (int i = 0; i < M; i++)
		cin >> num[i];


	//num[M] ��ŭ �ݺ�.
	for (int i = 0; i < M; i++)
	{
		//���� ã������ ���ڰ� ���� ù��°�� ��ġ�ϸ� 1�������̹Ƿ� ī��Ʈ ��������.
		if (num[i] == deq.front()) { deq.pop_front(); continue; }

		//ã������ ������ �������� ��ġ ����
		for (int j = 0; j < deq.size(); j++)
		{
			if (deq[j] == num[i])
			{
				nChk = j;
				break;
			}
		}
		
		//��ġ�� ���� 2,3�� ���� Ƚ�� ��� 
		funcSecondCnt = nChk;
		funcThirdCnt = deq.size()- nChk;

		//�� ���� ������ ������ ��� (ex) 2�������� 5�� . 3�������� 2������ ���ڸ� ã�� ���ִٸ� 2�� ����
		if (funcSecondCnt <= funcThirdCnt)
		{
			for (int j = 0; j < funcSecondCnt; j++) //2�������� ����� ����Ƚ����ŭ �ݺ�
			{
				deq.push_back(deq.front()); 
				deq.pop_front();
				cnt++;
			}
		}
		else
		{
			for (int j = 0; j < funcThirdCnt; j++) // 3�� ����
			{
				deq.push_front(deq.back());
				deq.pop_back();
				cnt++;
			}
		}
		
		--i;
	}

	cout << cnt << endl;

	return 0;
}