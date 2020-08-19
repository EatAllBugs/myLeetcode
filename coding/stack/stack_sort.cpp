#include <iostream>
using namespace std;
int main(){
}	

stack<int> sorting(stack<int> myStack){
	stack<int> result;
	//result存放返回值，即输出栈
	if(myStack.empty()){		
		return result;
		//边界条件
	}
	int tmp = myStack.top();
	//取栈的最顶端元素
	myStack.pop();
	//将该元素去除
	//当栈顶有元素并且栈顶元素大于tmp，再执行操作。
	while(!myStack.empty()|| (!result.empty()&&result.top()>tmp	){
		if(result.eampty()|| result.top()<=tmp){
			result.push(tmp);
			tmp = myStack.top();
			myStack.pop();	
		}else{
			myStack.push(result.top());	
			result.pop();	
		}
	}
	result.push(tmp);//tmp一直有元素	
	return result;//返回排序队列		
}