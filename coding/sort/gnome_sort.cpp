#include <iostream>
using namespace std;
int main(){
}
//地精排序,Gnome Sort，这是该算法的作者命名的，O(n*n)时间复杂度，O(1)空间复杂度，属于稳定的排序算法。
//算法的思想是每趟循环找到第一个逆序的元素，把它和在它前面的已排序的元素逐个进行比较、交换，有点像插入排序	
void gnome_sort(int a[]){
	int len = a.length();	
	int i = 0;
	int temp;
	while ( i < len ){
		if (a[i] <= a[i+1]){
			i++;	
		}else{
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
			i--;	
		}
	}

}

