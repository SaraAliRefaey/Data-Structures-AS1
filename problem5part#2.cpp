
#include <iostream>
using namespace std;

class Stack
{
private:
    struct Node {
        int  item;
        Node* Next;
    };
    Node* top;
    int len;

public:

    Stack()
    {
        top = 0;
        len = 0;
    }

    ~Stack()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }


    bool IsEmpty()
    {
        return top == 0;
    }

    void Push(int element)
    {
        Node* newNode = new Node();
        newNode->item = element;

        newNode->Next = top;
            top = newNode;

        len++;

    }
    void Pop()
    {
        if (IsEmpty())
        {
            cout << "list is Empty cannot remove...";
        }

        else
        {
            Node* cur = top;
            top = top->Next;
            delete cur;
            len--;
        }

    }
    int getTop()
    {
        if (!IsEmpty())
        {
            return top->item;
        }
        return -1;
    }
    int Size()
    {
        return len;
    }

};
// Function to get The greater element
void solveNextGreater(int nums[] , int n , int res[])
{

    Stack s;
    for (int j = 0;j < n;j++)
    {
        res[j] = -1;

    }

    for (int i = 0;i < 2 * n;++i)
    {
        int currentNum = nums[i % n];
        while (!s.IsEmpty() && nums[s.getTop()] < currentNum)
        {
            res[s.getTop()] = currentNum;
            s.Pop();
        }
        if (i < n)
        {
            s.Push(i);
        }
    }

}

int main()
{
    int n;
    cout << "Enter the number of elements (size) : ";
    cin >> n;
    int *nums= new int[n];
    int* res = new int[n];

    cout << "please Enter Your Elements : ";
    for (int k = 0; k < n;++k)
    {
        cin >> nums[k];
    }

    solveNextGreater(nums,n,res);

    cout << "The output : [";

    for (int x=0; x<n ;++x)
    {
        cout << res[x ]<< " ";
    }
    cout << "]";

    delete[] nums;
    delete[] res;


    return 0;

}

