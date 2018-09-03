//class MinValue {
//public:
//	int getMin(vector<int> arr, int n) {
//		// write code here
//		if (arr.size() == 0)
//			return -1;
//		if (arr.size() == 1)
//			return arr[0];
//		if (arr[0] < arr[n - 1])
//			return arr[0];
//
//		int left = 0, right = n - 1, mid;
//		while (left < right) {
//			if (left == right - 1) {
//				break;
//			}
//			if (arr[left] < arr[right]) {
//				return arr[left];
//			}
//			mid = (left + right) / 2;
//			if (arr[mid] < arr[left]) {
//				right = mid;
//			}
//			else if (arr[mid] > arr[right]) {
//				left = mid;
//			}
//		}
//		return arr[left] > arr[right] ? arr[right] : arr[left];
//	}
//};