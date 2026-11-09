using namespace std;

void displayArr(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int calculateSum(int arr[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; ++i)
		sum += arr[i];
	return sum;
}

void sortArray(int arr[], int length)
{
	int low = arr[0];
	int high = arr[1];
	int temp;
	
	// Loop thru entire array to sort it in ascending order
	for (int i = 0; i < length - 1; ++i) {
		int temp;
		
		for (int j = i; j < length - 1; ++j) {
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void displayReverse(int arr[], int length)
{
	for (int i = length - 1; i >= 0; --i)
		cout << arr[i] << " ";
}

bool isEven(int num) {
	if (num % 2 == 0) return true;
	return false;
}