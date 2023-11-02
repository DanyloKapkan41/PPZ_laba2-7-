#include <iostream>
using namespace std;
void filling(int*& nums, int i, int n, bool mode)
{
	if (mode) {
		if (i < n) {
			nums[i] = rand() % 2001 - 1000;
			i++;
			filling(nums, i, n, mode);
		}
	}
	else {
		if (i < n) {
			do { cin >> nums[i]; } while (nums[i] < -1000 || nums[i]>1000);
			cout << " writed...\n";
			i++;
			filling(nums, i, n, mode);
		}
	}
}
void extract(int* nums, int i, int n)
{
	if (i < n) {
		cout << nums[i] << ' ';
		i++;
		extract(nums, i, n);
	}
}
bool checking(int*& numb, int n)
{
	bool answ = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i!=j && numb[i]==2*numb[j] )
			{
				answ = 1;
				//cout << endl << i << " " << j;
				return answ;
			}
		}
	}
	return answ;
}
int main()
{
	int n, modeint;
	bool mode;
	do {
		cout << "Enter array size(2 - 500): ";
		cin >> n;
	} while (n < 2 || n > 500);
	int* nums = new int[n];
	srand(time(NULL));
	do {
		cout << "Choose mode (1 - autoentering, 0 - enterig by yourself): ";
		cin >> modeint;
	} while (modeint < 0 || modeint > 1);
	mode = modeint;
	filling(nums, 0, n, mode);
	extract(nums, 0, n);
	if (checking(nums, n))
	{
		cout << "\nTrue.";
	}
	else cout << "\nFalse.";
}